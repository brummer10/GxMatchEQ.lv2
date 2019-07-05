
#include <math.h>
#include <stdint.h>
#include <string.h>

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"
#include "lv2/lv2plug.in/ns/extensions/ui/ui.h"

#include <stdio.h>
#include <stdlib.h>

#include <cairo.h>
#include <cairo-xlib.h>

#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>

#include "./gx_matcheq.h"

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                define controller numbers
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

#define CONTROLS 27

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                define min/max if not defined already
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif
#ifndef max
#define max(x, y) ((x) < (y) ? (y) : (x))
#endif

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
        define some MACROS to read png data from binary stream 
        png's been converted to object files with
        ld -r -b binary name.png -o name.o
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

#ifdef __APPLE__
#include <mach-o/getsect.h>

#define EXTLD(NAME) \
  extern const unsigned char _section$__DATA__ ## NAME [];
#define LDVAR(NAME) _section$__DATA__ ## NAME
#define LDLEN(NAME) (getsectbyname("__DATA", "__" #NAME)->size)

#elif (defined __WIN32__)  /* mingw */

#define EXTLD(NAME) \
  extern const unsigned char binary_ ## NAME ## _start[]; \
  extern const unsigned char binary_ ## NAME ## _end[];
#define LDVAR(NAME) \
  binary_ ## NAME ## _start
#define LDLEN(NAME) \
  ((binary_ ## NAME ## _end) - (binary_ ## NAME ## _start))

#else /* gnu/linux ld */

#define EXTLD(NAME) \
  extern const unsigned char _binary_ ## NAME ## _start[]; \
  extern const unsigned char _binary_ ## NAME ## _end[];
#define LDVAR(NAME) \
  _binary_ ## NAME ## _start
#define LDLEN(NAME) \
  ((_binary_ ## NAME ## _end) - (_binary_ ## NAME ## _start))
#endif

// png's linked in as binarys
EXTLD(pedal_png)
EXTLD(slider_png)
EXTLD(meter_surface_png)
EXTLD(meter_overlay_png)

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                    define needed structs
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// struct definition to read binary data into cairo surface 
typedef struct  {
    const unsigned char * data;
    long int position;
} binary_stream;

// define controller type
typedef enum {
    KNOB,
    SWITCH,
    BSWITCH,
    ENUM,
    METER,
    SLIDER,
} ctype;

// define controller position in window
typedef struct {
    int x;
    int y;
    int width;
    int height;
} gx_alinment;

// define controller adjustment
typedef struct {
    float std_value;
    float value;
    float old_value;
    float old_max_value;
    float min_value;
    float max_value;
    float step;
} gx_adjustment;

// controller struct
typedef struct {
    gx_adjustment adj;
    gx_alinment al;
    bool is_active;
    const char* label;
    ctype type;
    PortIndex port;
} gx_controller;

// resize window
typedef struct {
    double x;
    double y;
    double x1;
    double y1;
    double x2;
    double y2;
    double c;
    double xc;
} gx_scale;

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                the main LV2 handle->XWindow
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// main window struct
typedef struct {
    Display *dpy;
    Window win;
    void *parentXwindow;
    Visual *visual;
    long event_mask;
    Atom DrawController;
    bool blocked;

    int width;
    int height;
    int init_width;
    int init_height;
    int pos_x;
    int pos_y;

    binary_stream png_stream;
    cairo_surface_t *surface;
    cairo_surface_t *pedal;
    cairo_surface_t *frame;
    cairo_surface_t *fswitch;
    cairo_surface_t *fslider;
    cairo_surface_t *meter_back;
    cairo_surface_t *meter_ahead;
    cairo_surface_t *meter_state;
    cairo_t *crf;
    cairo_t *cr;
    cairo_t *crm;
    cairo_t *crs;

    gx_controller controls[CONTROLS];
    double start_value;
    double v1_value;
    gx_scale rescale;
    gx_controller *sc;
    int set_sc;
    float c_states[11];
    float c_states2[11];
    float c_states_set[11];
    int first_match;
    bool analyse;

    void *controller;
    LV2UI_Write_Function write_function;
    LV2UI_Resize* resize;
} gx_matcheqUI;

// forward declaration to resize window and cairo surface
static void resize_event(gx_matcheqUI *ui);

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
        load png data from binary blob into cairo surface
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// read png data from binary blob
cairo_status_t png_stream_reader (void *_stream, unsigned char *data, unsigned int length) {
    binary_stream * stream = (binary_stream *) _stream;
    memcpy(data, &stream->data[stream->position],length);
    stream->position += length;
    return CAIRO_STATUS_SUCCESS;
}

cairo_surface_t *cairo_image_surface_create_from_stream (gx_matcheqUI* ui, const unsigned char* name) {
    ui->png_stream.data = name;
    ui->png_stream.position = 0;
    return cairo_image_surface_create_from_png_stream(&png_stream_reader, (void *)&ui->png_stream);
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                XWindow init the LV2 handle
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// init the xwindow and return the LV2UI handle
static LV2UI_Handle instantiate(const struct _LV2UI_Descriptor * descriptor,
            const char * plugin_uri, const char * bundle_path,
            LV2UI_Write_Function write_function,
            LV2UI_Controller controller, LV2UI_Widget * widget,
            const LV2_Feature * const * features) {

    gx_matcheqUI* ui = (gx_matcheqUI*)malloc(sizeof(gx_matcheqUI));

    if (!ui) {
        fprintf(stderr,"ERROR: failed to instantiate plugin with URI %s\n", plugin_uri);
        return NULL;
    }

    ui->parentXwindow = 0;
    LV2UI_Resize* resize = NULL;

    for (int i = 0; features[i]; ++i) {
        if (!strcmp(features[i]->URI, LV2_UI__parent)) {
            ui->parentXwindow = features[i]->data;
        } else if (!strcmp(features[i]->URI, LV2_UI__resize)) {
            resize = (LV2UI_Resize*)features[i]->data;
        }
    }

    if (ui->parentXwindow == NULL)  {
        fprintf(stderr, "ERROR: Failed to open parentXwindow for %s\n", plugin_uri);
        free(ui);
        return NULL;
    }

    ui->dpy = XOpenDisplay(0);

    if (ui->dpy == NULL)  {
        fprintf(stderr, "ERROR: Failed to open display for %s\n", plugin_uri);
        free(ui);
        return NULL;
    }
    //31.25, 62.5, 125., 250., 500., 1000., 2000., 4000., 8000., 16000.
    ui->controls[0] = (gx_controller) {{1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0}, {40, 280, 40, 40}, false,"POWER", BSWITCH, BYPASS};
    ui->controls[1] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {40, 30, 20, 216}, false,">", KNOB, G1};
    ui->controls[2] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {60, 30, 20, 216}, false,"63", KNOB, G2};
    ui->controls[3] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {80, 30, 20, 216}, false,"125", KNOB, G3};
    ui->controls[4] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {100, 30, 20, 216}, false,"250", KNOB, G4};
    ui->controls[5] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {120, 30, 20, 216}, false,"500", KNOB, G5};
    ui->controls[6] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {140, 30, 20, 216}, false,"1k", KNOB, G6};
    ui->controls[7] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {160, 30, 20, 216}, false,"2k", KNOB, G7};
    ui->controls[8] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {180, 30, 20, 216}, false,"4k", KNOB, G8};
    ui->controls[9] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {200, 30, 20, 216}, false,"8k", KNOB, G9};
    ui->controls[10] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {220, 30, 20, 216}, false,"16k", KNOB, G10};
    ui->controls[11] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -70.0, 10.0, 0.1}, {240, 30, 20, 216}, false,"<", KNOB, G11};

    ui->v1_value = 20.*log10(0.0);
    ui->controls[12] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {40, 30, 20, 216}, false,"V1", METER, V1};
    ui->controls[13] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {60, 30, 20, 216}, false,"V2", METER, V2};
    ui->controls[14] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {80, 30, 20, 216}, false,"V3", METER, V3};
    ui->controls[15] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {100, 30, 20, 216}, false,"V4", METER, V4};
    ui->controls[16] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {120, 30, 20, 216}, false,"V5", METER, V5};
    ui->controls[17] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {140, 30, 20, 216}, false,"V6", METER, V6};
    ui->controls[18] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {160, 30, 20, 216}, false,"V7", METER, V7};
    ui->controls[19] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {180, 30, 20, 216}, false,"V8", METER, V8};
    ui->controls[20] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {200, 30, 20, 216}, false,"V9", METER, V9};
    ui->controls[21] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {220, 30, 20, 216}, false,"V10", METER, V10};
    ui->controls[22] = (gx_controller) {{-70.0, -70.0, ui->v1_value, ui->v1_value, -70.0, 5.0, 0.00001}, {240, 30, 20, 216}, false,"V11", METER, V11};

    ui->controls[23] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0}, {240, 272, 40, 20}, false,"Match1", SWITCH, MATCH1};
    ui->controls[24] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0}, {240, 297, 40, 20}, false,"Match2", SWITCH, MATCH2};
    ui->controls[25] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, -40.0, 40.0, 0.1}, {190, 280, 40, 40}, false,"GAIN", SLIDER, GAIN};
    ui->controls[26] = (gx_controller) {{0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0}, {240, 322, 40, 20}, false,"CLEAR", SWITCH, CLEAR};

    ui->start_value = 0.0;
    ui->sc = NULL;
    ui->set_sc = 0;

    for (int i=0;i<11;i++) {
        ui->c_states[i] = 0.0;
        ui->c_states2[i] = 0.0;
        ui->c_states_set[i] = 0.0;
    }
    ui->analyse = False;
    ui->first_match = 1;


    ui->pedal = cairo_image_surface_create_from_stream(ui, LDVAR(pedal_png));
    ui->init_width = cairo_image_surface_get_width(ui->pedal);
    ui->height = ui->init_height = cairo_image_surface_get_height(ui->pedal);
    ui->width = ui->init_width -185 + (10 * CONTROLS);

    ui->win = XCreateWindow(ui->dpy, (Window)ui->parentXwindow, 0, 0,
                                ui->width, ui->height, 0,
                                CopyFromParent, InputOutput,
                                CopyFromParent, CopyFromParent, 0);

    ui->event_mask = StructureNotifyMask|ExposureMask|KeyPressMask 
                    |EnterWindowMask|LeaveWindowMask|ButtonReleaseMask
                    |ButtonPressMask|Button1MotionMask;

    XSizeHints* win_size_hints;
    win_size_hints = XAllocSizeHints();
    win_size_hints->flags = PSize | PMinSize;
    win_size_hints->min_width = ui->width/1.4;
    win_size_hints->min_height = ui->height/1.4;
    win_size_hints->base_width = ui->width;
    win_size_hints->base_height = ui->height;
    XSetWMNormalHints(ui->dpy, ui->win, win_size_hints);
    XFree(win_size_hints);

    XSelectInput(ui->dpy, ui->win, ui->event_mask);
    XMapWindow(ui->dpy, ui->win);
    XClearWindow(ui->dpy, ui->win);

    ui->visual = DefaultVisual(ui->dpy, DefaultScreen (ui->dpy));
    ui->surface = cairo_xlib_surface_create (ui->dpy, ui->win, ui->visual,
                                        ui->width, ui->height);
    ui->cr = cairo_create(ui->surface);

    ui->frame = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 42, 62);
    ui->crf = cairo_create (ui->frame);

    ui->fslider = cairo_image_surface_create_from_stream(ui, LDVAR(slider_png));

    ui->fswitch = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 40, 20);
    ui->crs = cairo_create (ui->fswitch);

    ui->meter_back = cairo_image_surface_create_from_stream(ui, LDVAR(meter_surface_png));
    ui->meter_ahead = cairo_image_surface_create_from_stream(ui, LDVAR(meter_overlay_png));
    ui->meter_state = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 20, 230);
    ui->crm = cairo_create (ui->meter_state);

    *widget = (void*)ui->win;

    ui->blocked = false;
    if (resize){
        ui->resize = resize;
        resize->ui_resize(resize->handle, ui->width, ui->height);
    }

    ui->rescale.x  = (double)ui->width/ui->init_width;
    ui->rescale.y  = (double)ui->height/ui->init_height;
    ui->rescale.x1 = (double)ui->init_width/ui->width;
    ui->rescale.y1 = (double)ui->init_height/ui->height;
    ui->rescale.xc = (double)ui->width/(ui->init_width-185 + (10 * CONTROLS));
    ui->rescale.c = (ui->rescale.xc < ui->rescale.y) ? ui->rescale.xc : ui->rescale.y;
    ui->rescale.x2 =  ui->rescale.xc / ui->rescale.c;
    ui->rescale.y2 = ui->rescale.y / ui->rescale.c;

    ui->DrawController = XInternAtom(ui->dpy, "ControllerMessage", False);

    ui->controller = controller;
    ui->write_function = write_function;
    //resize_event(ui);

    return (LV2UI_Handle)ui;
}

// cleanup after usage
static void cleanup(LV2UI_Handle handle) {
    gx_matcheqUI* ui = (gx_matcheqUI*)handle;
    cairo_destroy(ui->cr);
    cairo_destroy(ui->crf);
    cairo_destroy(ui->crm);
    cairo_destroy(ui->crs);
    cairo_surface_destroy(ui->pedal);
    cairo_surface_destroy(ui->fslider);
    cairo_surface_destroy(ui->fswitch);
    cairo_surface_destroy(ui->surface);
    cairo_surface_destroy(ui->frame);
    cairo_surface_destroy(ui->meter_back);
    cairo_surface_destroy(ui->meter_ahead);
    cairo_surface_destroy(ui->meter_state);
    XDestroyWindow(ui->dpy, ui->win);
    XCloseDisplay(ui->dpy);
    free(ui);
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                XWindow drawing expose handling
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// draw knobs and simple switches
static void knob_expose(gx_matcheqUI *ui,gx_controller* knob) {
    cairo_set_operator(ui->crf,CAIRO_OPERATOR_CLEAR);
    cairo_paint(ui->crf);
    cairo_set_operator(ui->crf,CAIRO_OPERATOR_OVER);
    const double scale_zero = 20 * (M_PI/180); // defines "dead zone" for knobs
    int arc_offset = 0;
    int knob_x = 0;
    int knob_y = 0;
    int w = cairo_image_surface_get_width(ui->frame);
    int h = cairo_image_surface_get_height(ui->frame)-20;
    int grow = (w > h) ? h:w;
    knob_x = grow-1;
    knob_y = grow-1;
    /** get values for the knob **/

    int knobx = (w - knob_x) * 0.5;
    int knobx1 = w* 0.5;

    int knoby = (h - knob_y) * 0.5;
    int knoby1 = h * 0.5;

    double knobstate = (knob->adj.value - knob->adj.min_value) / (knob->adj.max_value - knob->adj.min_value);
    double angle = scale_zero + knobstate * 2 * (M_PI - scale_zero);

    double pointer_off =knob_x/6;
    double radius = min(knob_x-pointer_off, knob_y-pointer_off) / 2;
    double lengh_x = (knobx+radius+pointer_off/2) - radius * sin(angle);
    double lengh_y = (knoby+radius+pointer_off/2) + radius * cos(angle);
    double radius_x = (knobx+radius+pointer_off/2) - radius/ 1.18 * sin(angle);
    double radius_y = (knoby+radius+pointer_off/2) + radius/ 1.18 * cos(angle);

    cairo_arc(ui->crf,knobx1+arc_offset, knoby1+arc_offset, knob_x/2.1, 0, 2 * M_PI );

    cairo_set_source_rgb (ui->crf, 0.0, 0.1, 0.1);
    cairo_fill (ui->crf);
    cairo_new_path (ui->crf);

    cairo_arc(ui->crf,knobx1+arc_offset, knoby1+arc_offset, knob_x/3.1, 0, 2 * M_PI );
    cairo_set_source_rgb (ui->crf, 0.6, 0.6, 0.6);
    cairo_set_line_width(ui->crf, 1.0);
    cairo_stroke(ui->crf);
    cairo_new_path (ui->crf);

    /** create a rotating pointer on the kob**/
    cairo_set_line_cap(ui->crf, CAIRO_LINE_CAP_ROUND); 
    cairo_set_line_join(ui->crf, CAIRO_LINE_JOIN_BEVEL);
    cairo_move_to(ui->crf, radius_x, radius_y);
    cairo_line_to(ui->crf,lengh_x,lengh_y);
    cairo_set_line_width(ui->crf,2);
    cairo_set_source_rgb (ui->crf,0.6,0.6,0.6);
    cairo_stroke(ui->crf);
    cairo_new_path (ui->crf);

    cairo_text_extents_t extents;
    /** show value on the kob**/
    if (knob->is_active == true) {
        char s[64];
        const char* format[] = {"%.1f", "%.2f", "%.3f"};
        if (fabs(knob->adj.value)>9.99) {
            snprintf(s, 63,"%d",  (int) knob->adj.value);
        } else if (fabs(knob->adj.value)>0.99) {
            snprintf(s, 63, format[1-1], knob->adj.value);
        } else {
            snprintf(s, 63, format[1-1], knob->adj.value);
        }
        cairo_set_source_rgb (ui->crf, 0.6, 0.6, 0.6);
        cairo_set_font_size (ui->crf, 9.0);
        cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
                                   CAIRO_FONT_WEIGHT_BOLD);
        cairo_text_extents(ui->crf, s, &extents);
        cairo_move_to (ui->crf, knobx1-extents.width/2, knoby1+extents.height/2);
        cairo_show_text(ui->crf, s);
        cairo_new_path (ui->crf);
    }

    /** show label below the knob**/
    if (knob->is_active) {
        cairo_set_source_rgb (ui->crf, 0.8, 0.8, 0.8);
    } else {
        cairo_set_source_rgb (ui->crf, 0.6, 0.6, 0.6);
    }
    cairo_set_font_size (ui->crf, 9.0);
    cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
                               CAIRO_FONT_WEIGHT_BOLD);
    cairo_text_extents(ui->crf,knob->label , &extents);

    cairo_move_to (ui->crf, knobx1-extents.width/2, grow+6+extents.height);
    cairo_show_text(ui->crf, knob->label);
    cairo_new_path (ui->crf);
}

// draw knobs and simple switches
static void switch_expose(gx_matcheqUI *ui,gx_controller* knob) {
    cairo_set_operator(ui->crs,CAIRO_OPERATOR_CLEAR);
    cairo_paint(ui->crs);
    cairo_set_operator(ui->crs,CAIRO_OPERATOR_OVER);

    double knobstate = (knob->adj.value - knob->adj.min_value) / (knob->adj.max_value - knob->adj.min_value);
    cairo_set_source_rgb (ui->crs, 0.8 * knobstate, 0.1, 0.1);
    if(knob->port == MATCH2 && ui->first_match)
    cairo_set_source_rgb (ui->crs, 0.3 , 0.3, 0.3);
    cairo_rectangle(ui->crs,0, 0, 40,20);
    cairo_fill_preserve(ui->crs);
    if ((int)knobstate) { 
        cairo_set_source_rgb (ui->crs, 0., 0.1, 0.1);
        cairo_set_line_width(ui->crs, 2.0);
    } else {
        cairo_set_source_rgb (ui->crs, 0.6, 0.6, 0.6);
        cairo_set_line_width(ui->crs, 1.0);
    }
    cairo_stroke(ui->crs);
    cairo_new_path (ui->crs);
    /** show label on the switch**/
    if (knob->is_active && !ui->first_match) {
        cairo_set_source_rgb (ui->crs, 0.8, 0.8, 0.8);
    } else if( ui->first_match) {
        cairo_set_source_rgb (ui->crs, 0.4, 0.4, 0.4);
    } else {
        cairo_set_source_rgb (ui->crs, 0.6, 0.6, 0.6);
    }
    cairo_set_font_size (ui->crs, 9.0);
    cairo_select_font_face (ui->crs, "Sans", CAIRO_FONT_SLANT_NORMAL,
                               CAIRO_FONT_WEIGHT_BOLD);

    cairo_move_to (ui->crs, 2, 14);
    cairo_show_text(ui->crs, knob->label);
    cairo_new_path (ui->crs);
}

// draw the power switch (bypass)
static void bypass_expose(gx_matcheqUI *ui, gx_controller* switch_) {
    cairo_set_operator(ui->crf,CAIRO_OPERATOR_CLEAR);
    cairo_paint(ui->crf);
    cairo_set_operator(ui->crf,CAIRO_OPERATOR_OVER);
    int arc_offset = 0;
    int switch_x = 0;
    int w = cairo_image_surface_get_width(ui->frame);
    int h = cairo_image_surface_get_height(ui->frame)-20;
    int grow = (w > h) ? h:w;
    switch_x = grow-1;
    /** get values for the switch **/

    int switchx1 = w* 0.5;

    int switchy1 = h * 0.5;

    double switchstate = (switch_->adj.value - switch_->adj.min_value) / (switch_->adj.max_value - switch_->adj.min_value);

    cairo_arc(ui->crf,switchx1+arc_offset, switchy1+arc_offset, switch_x/2.1, 0, 2 * M_PI );

    cairo_set_source_rgb (ui->crf, 0.0, 0.1, 0.1);
    cairo_fill (ui->crf);
    cairo_new_path (ui->crf);

    cairo_arc(ui->crf,switchx1+arc_offset, switchy1+arc_offset, switch_x/3.1, 0, 2 * M_PI );
    cairo_set_source_rgb (ui->crf, 0.6*switchstate, 0.1, 0.1);
    cairo_fill_preserve (ui->crf);
    cairo_set_source_rgb (ui->crf, 0.6, 0.6, 0.6);
    cairo_set_line_width(ui->crf, 1.0);
    cairo_stroke(ui->crf);
    cairo_new_path (ui->crf);

    /** show label below the switch**/
    cairo_text_extents_t extents;

    if (switch_->is_active) {
        cairo_set_source_rgb (ui->crf, 0.8, 0.8, 0.8);
    } else {
        cairo_set_source_rgb (ui->crf, 0.6, 0.6, 0.6);
    }
    cairo_set_font_size (ui->crf, 9.0);
    cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
                               CAIRO_FONT_WEIGHT_BOLD);
    cairo_text_extents(ui->crf,switch_->label , &extents);

    cairo_move_to (ui->crf, 20.0-extents.width/2, 47.0+extents.height);
    cairo_show_text(ui->crf, switch_->label);
    cairo_new_path (ui->crf);
}

inline double log_meter (double db) {
    float def = 0.0f; /* Meter deflection %age */

    if (db < -70.0f) {
        def = 0.0f;
    } else if (db < -60.0f) {
        def = (db + 70.0f) * 0.25f;
    } else if (db < -50.0f) {
        def = (db + 60.0f) * 0.5f + 2.5f;
    } else if (db < -40.0f) {
        def = (db + 50.0f) * 0.75f + 7.5f;
    } else if (db < -30.0f) {
        def = (db + 40.0f) * 1.5f + 15.0f;
    } else if (db < -20.0f) {
        def = (db + 30.0f) * 2.0f + 30.0f;
    } else if (db < 6.0f) {
        def = (db + 20.0f) * 2.5f + 50.0f;
    } else {
        def = 115.0f;
    }

    /* 115 is the deflection %age that would be
       when db=6.0. this is an arbitrary
       endpoint for our scaling.
    */

    return def/115.0f;
}

static void meter_scale(cairo_t* cr, bool ds) {
    double x0      = 0;
    double y0      = 0;
    double rect_width  = 20;
    double rect_height = 216;

    int  db_points[] = { -50, -40, -30, -20, -15, -10, -6, -3, 0, 3 };
    char  buf[32];

    cairo_set_font_size (cr, 8.0);
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
                               CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);

    for (unsigned int i = 0; i < sizeof (db_points)/sizeof (db_points[0]); ++i)
    {
        float fraction = log_meter((double)db_points[i]);
        // cairo_set_source_rgb (cr,0.32 + 0.22*i,0.5 + (0.5- 0.2*i/2), 0.1);
        if (!ds) {
        cairo_move_to (cr, 12,y0+rect_height - (rect_height * fraction));
        cairo_line_to (cr, x0+rect_width-1 ,y0+rect_height -  (rect_height * fraction));
        }
        if (ds) {
        if (i<6)
        {
            snprintf (buf, sizeof (buf), "%d", db_points[i]);
            cairo_move_to (cr, x0+rect_width*0.2,y0+rect_height - (rect_height * fraction));
        }
        else if (i<8)
        {
            snprintf (buf, sizeof (buf), "%d", db_points[i]);
            cairo_move_to (cr, x0+rect_width*0.33,y0+rect_height - (rect_height * fraction));
        }
        else
        {
            snprintf (buf, sizeof (buf), " %d", db_points[i]);
            cairo_move_to (cr, x0+rect_width*0.34,y0+rect_height - (rect_height * fraction));
        }
        cairo_show_text (cr, buf);
        }
    }

    cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);
    cairo_set_line_width(cr, 2.0);
    cairo_stroke(cr);
}

// draw the slider (V)
static void slider_expose(gx_matcheqUI *ui, int i, gx_controller* meter_) {

    cairo_set_source_surface (ui->crm, ui->fslider, 3, 212 -(216 * log_meter(ui->controls[i-11].adj.value)));
    cairo_rectangle(ui->crm,3, 212 -( 216 * log_meter(ui->controls[i-11].adj.value)), 12, 7);
    cairo_fill(ui->crm);
    cairo_new_path (ui->crm);

    cairo_text_extents_t extents;
    // show value on the slider
    if (ui->controls[i-11].is_active == true) {
        char s[64];
        const char* format[] = {"%.1f", "%.2f", "%.3f"};
        if (fabs(ui->controls[i-11].adj.value)>9.99) {
            snprintf(s, 63,"%d",  (int) ui->controls[i-11].adj.value);
        } else {
            snprintf(s, 63, format[1-1], ui->controls[i-11].adj.value);
        }
        cairo_set_source_rgb (ui->crm, 0.6, 0.6, 0.6);
        cairo_set_font_size (ui->crm, 8.0);
        cairo_select_font_face (ui->crm, "Sans", CAIRO_FONT_SLANT_NORMAL,
                                   CAIRO_FONT_WEIGHT_BOLD);
        cairo_text_extents(ui->crm, "0.00", &extents);
        cairo_move_to (ui->crm, 10-extents.width/2, 220 -( 216 * log_meter(ui->controls[i-11].adj.value))+extents.height/2);
        cairo_show_text(ui->crm, s);
        cairo_new_path (ui->crm);
    }    /** show label below the slider**/
    if (ui->controls[i-11].is_active) {
        cairo_set_source_rgb (ui->crm, 0.8, 0.8, 0.8);
    } else {
        cairo_set_source_rgb (ui->crm, 0.6, 0.6, 0.6);
    }
    cairo_set_font_size (ui->crm, 8.0);
    cairo_select_font_face (ui->crm, "Sans", CAIRO_FONT_SLANT_NORMAL,
                               CAIRO_FONT_WEIGHT_BOLD);
    cairo_text_extents(ui->crm,ui->controls[i-11].label , &extents);

    cairo_move_to (ui->crm, 10-extents.width/2, 225);
    cairo_show_text(ui->crm, ui->controls[i-11].label);
    cairo_new_path (ui->crm);
}

// draw the meter (V)
static void meter_expose(gx_matcheqUI *ui,  int i, gx_controller* meter_) {
    cairo_set_operator(ui->crm,CAIRO_OPERATOR_CLEAR);
    cairo_paint(ui->crm);
    cairo_set_operator(ui->crm,CAIRO_OPERATOR_OVER);
    cairo_set_source_rgb (ui->crm, 0.1, 0.1, 0.1);
    cairo_paint(ui->crm);
    meter_scale(ui->crm, false);

    cairo_set_source_surface (ui->crm, ui->meter_back, 3, 0);
    cairo_rectangle(ui->crm,3, 0, 12, 216);
    cairo_fill(ui->crm);
    cairo_set_source_surface (ui->crm, ui->meter_ahead, 3, 0);
    cairo_rectangle(ui->crm,3, 216, 12, -(216 * log_meter(ui->controls[i].adj.value)));
    cairo_fill(ui->crm);
    cairo_rectangle(ui->crm,3, 216-(216 * log_meter(ui->controls[i].adj.old_max_value)), 12, 3);
    cairo_fill(ui->crm);
    cairo_new_path (ui->crm);
    slider_expose(ui, i, meter_);
}

// select draw methode by controller type
static void draw_controller(gx_matcheqUI *ui, int i, gx_controller* controller) {
    if (controller->type == KNOB) meter_expose(ui,i+11, controller);
    else if (controller->type == SWITCH) switch_expose(ui, controller);
    else if (controller->type == ENUM) knob_expose(ui, controller);
    else if (controller->type == METER) meter_expose(ui, i, controller);
    else if (controller->type == SLIDER) knob_expose(ui, controller);
    else if (controller->type == BSWITCH) bypass_expose(ui, controller);
}

// general XWindow expose callback, 
static void _expose(gx_matcheqUI *ui) {
    const char* plug_name1 = "MATCH" ;
    const char* plug_name2 = "EQ " ;
    cairo_push_group (ui->cr);

    cairo_scale (ui->cr, ui->rescale.x, ui->rescale.y);

    cairo_set_source_surface (ui->cr, ui->pedal, 0, 0);
    cairo_paint (ui->cr);

    cairo_text_extents_t extents;
    cairo_set_source_rgb (ui->cr, 0.0, 0.1, 0.1);
    cairo_set_font_size (ui->cr, 16.0);
    cairo_select_font_face (ui->cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
                               CAIRO_FONT_WEIGHT_BOLD);
    cairo_text_extents(ui->cr, plug_name1, &extents);
    cairo_move_to (ui->cr, ((double)(ui->width/2.4)/ui->rescale.x-(extents.width)/2.0),
      (double)(ui->height-30.0)/ui->rescale.y-extents.height);
    cairo_show_text(ui->cr, plug_name1);
    cairo_text_extents(ui->cr, plug_name2, &extents);
    cairo_move_to (ui->cr, ((double)(ui->width/2.4)/ui->rescale.x-(extents.width)/2.0),
      (double)(ui->height-10.0)/ui->rescale.y-extents.height);
    cairo_show_text(ui->cr, plug_name2);

    cairo_scale (ui->cr, ui->rescale.x1, ui->rescale.y1);
    cairo_scale (ui->cr, ui->rescale.c, ui->rescale.c);

    for (int i=0;i<CONTROLS;i++) {
        draw_controller(ui,i, &ui->controls[i]);
        if (ui->controls[i].type == METER || ui->controls[i].type == KNOB ) {
            cairo_set_source_surface (ui->cr, ui->meter_state, 
              (double)ui->controls[i].al.x * ui->rescale.x2,
              (double)ui->controls[i].al.y * ui->rescale.y2);
        } else if (ui->controls[i].type == SWITCH ) {
            cairo_set_source_surface (ui->cr, ui->fswitch, 
              (double)ui->controls[i].al.x * ui->rescale.x2,
              (double)ui->controls[i].al.y * ui->rescale.y2);
        } else {
            cairo_set_source_surface (ui->cr, ui->frame, 
              (double)ui->controls[i].al.x * ui->rescale.x2,
              (double)ui->controls[i].al.y * ui->rescale.y2);
        } 
        cairo_paint (ui->cr);
    }
    
    cairo_set_operator(ui->crm,CAIRO_OPERATOR_CLEAR);
    cairo_paint(ui->crm);
    cairo_set_operator(ui->crm,CAIRO_OPERATOR_OVER);
    cairo_set_source_rgb (ui->crm, 0.1, 0.1, 0.1);
    cairo_paint(ui->crm);
    meter_scale(ui->crm, true);
    cairo_set_source_surface (ui->cr, ui->meter_state, 
      (double)(ui->controls[11].al.x+20) * ui->rescale.x2,
      (double)(ui->controls[11].al.y) * ui->rescale.y2);
    cairo_paint (ui->cr);
    

    cairo_pop_group_to_source (ui->cr);
    cairo_paint (ui->cr);
}

// redraw a single controller
static void controller_expose(gx_matcheqUI *ui, int i, gx_controller * control) {
    cairo_push_group (ui->cr);
    cairo_scale (ui->cr, ui->rescale.x, ui->rescale.y);

    cairo_set_source_surface (ui->cr, ui->pedal, 0, 0);

    cairo_scale (ui->cr, ui->rescale.x1, ui->rescale.y1);
    cairo_scale (ui->cr, ui->rescale.c, ui->rescale.c);
    if(control->type == BSWITCH || ui->controls[i].type == SLIDER) {
        cairo_rectangle (ui->cr,(double)control->al.x * ui->rescale.x2,
          (double)control->al.y * ui->rescale.y2,
          (double)control->al.width, (double)control->al.height+ 20.0);
    } else {
        cairo_rectangle (ui->cr,(double)control->al.x * ui->rescale.x2,
          (double)control->al.y * ui->rescale.y2,
          (double)control->al.width, (double)control->al.height);
    }
    cairo_fill(ui->cr);
    cairo_stroke(ui->cr);

    draw_controller(ui, i, control);
    if (ui->controls[i].type == METER || ui->controls[i].type == KNOB ) {
        cairo_set_source_surface (ui->cr, ui->meter_state, 
          (double)control->al.x * ui->rescale.x2,
          (double)control->al.y * ui->rescale.y2);
    } else if (ui->controls[i].type == SWITCH ) {
        cairo_set_source_surface (ui->cr, ui->fswitch, 
          (double)ui->controls[i].al.x * ui->rescale.x2,
          (double)ui->controls[i].al.y * ui->rescale.y2);
    } else {
        cairo_set_source_surface (ui->cr, ui->frame, 
          (double)control->al.x * ui->rescale.x2,
          (double)control->al.y * ui->rescale.y2);
    }
    cairo_paint (ui->cr);

    cairo_pop_group_to_source (ui->cr);
    cairo_paint (ui->cr);
}

inline float power2db(gx_matcheqUI *ui, int port_index, float power) {
    const float falloff = 27 * 60 * 0.0005;
    const float fallsoft = 6 * 60 * 0.0005;

   // fprintf(stderr,"  %f  ",power);
    if (power <=  20.*log10(0.00021)) {
        power = 20.*log10(0.0);
        if(!ui->analyse) ui->controls[port_index].adj.old_max_value = min(0.0,ui->controls[port_index].adj.old_max_value - fallsoft); 
    }
    //power = 20.*log10(power);
    // retrieve old meter value and consider falloff
    if (power < ui->controls[port_index].adj.old_value) {
        power = max(power, ui->controls[port_index].adj.old_value - falloff);
        if(!ui->analyse) ui->controls[port_index].adj.old_max_value = min(0.0,ui->controls[port_index].adj.old_max_value - fallsoft); 
    }
    if (power > ui->controls[port_index].adj.old_max_value) {
        ui->controls[port_index].adj.old_max_value = power ;
    }
   
    
    ui->controls[port_index].adj.old_value = power;
    return  power;
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                XWindow event handling
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// resize the xwindow and the cairo xlib surface
static void resize_event(gx_matcheqUI *ui) {
    XWindowAttributes attrs;
    XGetWindowAttributes(ui->dpy, (Window)ui->parentXwindow, &attrs);
    ui->width = attrs.width;
    ui->height = attrs.height;
    XResizeWindow (ui->dpy,ui->win ,ui->width, ui->height);
    cairo_xlib_surface_set_size( ui->surface, ui->width, ui->height);
    ui->rescale.x  = (double)ui->width/ui->init_width;
    ui->rescale.y  = (double)ui->height/ui->init_height;
    ui->rescale.x1 = (double)ui->init_width/ui->width;
    ui->rescale.y1 = (double)ui->init_height/ui->height;
    ui->rescale.xc = (double)ui->width/(ui->init_width-185 + (10 * CONTROLS));
    ui->rescale.c = (ui->rescale.xc < ui->rescale.y) ? ui->rescale.xc : ui->rescale.y;
    ui->rescale.x2 =  ui->rescale.xc / ui->rescale.c;
    ui->rescale.y2 = ui->rescale.y / ui->rescale.c;
}

// send event when active controller changed
static void send_controller_event(gx_matcheqUI *ui, int controller) {
    XClientMessageEvent xevent;
    xevent.type = ClientMessage;
    xevent.message_type = ui->DrawController;
    xevent.display = ui->dpy;
    xevent.window = ui->win;
    xevent.format = 16;
    xevent.data.l[0] = controller;
    XSendEvent(ui->dpy, ui->win, 0, 0, (XEvent *)&xevent);
}

/*------------- check and set state of controllers ---------------*/
static void check_value_changed(gx_matcheqUI *ui, int i, float* value);

static void check_switch_state(gx_matcheqUI *ui, int i, float* value) {
    float v = 0.0;
    if(i == 23) {
        if ((int)(*value) == 0) {
            for (int a=0;a<11;a++) {
                ui->c_states[a] = ui->controls[a+12].adj.old_max_value;
           }
            ui->analyse = False;
        } else {
            float zero = 0.0;
            for (int a=0;a<11;a++) {
                check_value_changed(ui, a+1, &zero);
            }
            check_value_changed(ui, 25, &zero);
            ui->analyse = True;
            if (ui->first_match) {
                ui->first_match = 0;
                send_controller_event(ui, 24);
            }
        }
    }
    if(i == 24) {
        if (ui->first_match) {
            float zero = 0.0;
            check_value_changed(ui, 24, &zero);
            return;
        }
        if ((int)(*value) == 0) {
            for (int a=0;a<11;a++) {
                ui->c_states2[a] = ui->controls[a+12].adj.old_max_value;
                ui->c_states_set[a] = ui->c_states[a] - ui->c_states2[a];
                v = max(v,ui->c_states_set[a]);
            }
            if(v>10.0) v = -(10.0-v);
            else v = 0.0;
            for (int a=0;a<11;a++) {
                ui->c_states_set[a] -= v;
                check_value_changed(ui, a+1, &ui->c_states_set[a]);
            }
            ui->analyse = False;
            if(isnormal(v)) { 
                v = min(40.0,max(-40.0,v));
                check_value_changed(ui, 25, &v);
            }
        } else {
            ui->analyse = True;
        }
    }
    if(i == 26) {
        if ((int)(*value) == 1) {
            float zero = 0.0;
            check_value_changed(ui, 25, &zero);
            for (int a=0;a<11;a++) {
                check_value_changed(ui, a+1, &zero);
            }
            for (int i=0;i<11;i++) {
               // ui->c_states[i] = 0.0; // keep first source
                ui->c_states2[i] = 0.0;
                ui->c_states_set[i] = 0.0;
            }
            check_value_changed(ui, 26, &zero);
        }
    }
    
}

// check if controller value changed, if so, redraw
static void check_value_changed(gx_matcheqUI *ui, int i, float* value) {
    if(fabs(*(value) - ui->controls[i].adj.value)>=0.00001) {
        ui->controls[i].adj.value = *(value);
        if (ui->controls[i].type == SWITCH) {
            check_switch_state(ui, i, value);
        }
        if (ui->controls[i].type != METER) {
            ui->write_function(ui->controller,ui->controls[i].port,sizeof(float),0,value);
        }
        send_controller_event(ui, i);
    }
}

// check if controller activation state changed, if so, redraw
static void check_is_active(gx_matcheqUI *ui, int i, bool set) {
    if (ui->controls[i].is_active != set) {
        ui->controls[i].is_active = set;
        send_controller_event(ui, i);
    }
}

// check if controller is under mouse pointer
static bool aligned(int x, int y, gx_controller *control, gx_matcheqUI *ui) {
    double ax = (control->al.x * ui->rescale.x2)* ui->rescale.c;
    double ay = (control->al.y  * ui->rescale.y2)* ui->rescale.c;
    double aw = ax + (control->al.width * ui->rescale.c);
    double ah = ay + (control->al.height * ui->rescale.c);
    return ((x >= ax ) && (x <= aw)
      && (y >= ay ) && (y <= ah)) ? true : false;
}

// get controller number under mouse pointer and make it active, or return false
static bool get_active_ctl_num(gx_matcheqUI *ui, int *num) {
    bool ret = false;
    for (int i=0;i<CONTROLS;i++) {
        if (ui->controls[i].type == METER) continue;
        if (aligned(ui->pos_x, ui->pos_y, &ui->controls[i], ui)) {
            *(num) = i;
            check_is_active(ui, i, true);
            ret = true;
        } else {
            check_is_active(ui, i, false);
        }
    }
    return ret;
}

// get current active controller number, or return false
static bool get_active_controller_num(gx_matcheqUI *ui, int *num) {
    for (int i=0;i<CONTROLS;i++) {
        if (ui->controls[i].type == METER) continue;
        if (ui->controls[i].is_active) {
            *(num) = i;
            return true;
        }
    }
    return false;
}

/*------------- mouse event handlings ---------------*/

// mouse wheel scroll event
static void scroll_event(gx_matcheqUI *ui, int direction) {
    float value;
    int num;
    if (get_active_ctl_num(ui, &num)) {
        value = min(ui->controls[num].adj.max_value,max(ui->controls[num].adj.min_value, 
          ui->controls[num].adj.value + (ui->controls[num].adj.step * direction)));
        check_value_changed(ui, num, &value);
    }
}

// control is a enum, so switch value
static void enum_event(gx_matcheqUI *ui, int i) {
    float value;
    if (ui->controls[i].adj.value != ui->controls[i].adj.max_value) {
        value = min(ui->controls[i].adj.max_value,max(ui->controls[i].adj.min_value, 
          ui->controls[i].adj.value + ui->controls[i].adj.step));
    } else {
        value = ui->controls[i].adj.min_value;
    }
    check_value_changed(ui, i, &value);
}

// control is a switch, so switch value
static void switch_event(gx_matcheqUI *ui, int i) {
    float value = ui->controls[i].adj.value ? 0.0 : 1.0;
    check_value_changed(ui, i, &value);
}

// left mouse button is pressed, generate a switch event, or set controller active
static void button1_event(gx_matcheqUI *ui, double* start_value) {
    int num;
    if (get_active_ctl_num(ui, &num)) {
        if (ui->controls[num].type == BSWITCH ||ui->controls[num].type == SWITCH) {
            switch_event(ui, num);
        } else if (ui->controls[num].type == ENUM) {
            enum_event(ui, num);
        } else {
            *(start_value) = ui->controls[num].adj.value;
        }
    }
}

// mouse move while left button is pressed
static void motion_event(gx_matcheqUI *ui, double start_value, int m_y) {
    const double scaling = 1;
    float value = 0.0;
    int num;
    if (get_active_controller_num(ui, &num)) {
        if (ui->controls[num].type != BSWITCH && ui->controls[num].type != SWITCH && ui->controls[num].type != ENUM) {
            double knobstate = (start_value - ui->controls[num].adj.min_value) /
                               (ui->controls[num].adj.max_value - ui->controls[num].adj.min_value);
            double nsteps = ui->controls[num].adj.step / (ui->controls[num].adj.max_value-ui->controls[num].adj.min_value);
            double nvalue = min(1.0,max(0.0,knobstate + ((double)(ui->pos_y - m_y)*scaling *nsteps)));
            value = nvalue * (ui->controls[num].adj.max_value-ui->controls[num].adj.min_value) + ui->controls[num].adj.min_value;
            check_value_changed(ui, num, &value);
        }
    }
}

/*------------- keyboard event handlings ---------------*/

// set min std or max value, depending on which key is pressed
static void set_key_value(gx_matcheqUI *ui, int set_value) {
    float value = 0.0;
    int num;
    if (get_active_controller_num(ui, &num)) {
        if (set_value == 1) value = ui->controls[num].adj.min_value;
        else if (set_value == 2) value = ui->controls[num].adj.std_value;
        else if (set_value == 3) value = ui->controls[num].adj.max_value;
        check_value_changed(ui, num, &value);
    }
}

// scroll up/down on key's up/right down/left
static void key_event(gx_matcheqUI *ui, int direction) {
    float value;
    int num;
    if (get_active_controller_num(ui, &num)) {
        value = min(ui->controls[num].adj.max_value,max(ui->controls[num].adj.min_value, 
          ui->controls[num].adj.value + (ui->controls[num].adj.step * direction)));
        check_value_changed(ui, num, &value);
    }
}

// set previous controller active on shift+tab key's
static void set_previous_controller_active(gx_matcheqUI *ui) {
    int num;
    if (get_active_controller_num(ui, &num)) {
        ui->controls[num].is_active = false;
        send_controller_event(ui, num);
        if(num>0) {
            if (ui->controls[num-1].is_active != true) {
                ui->controls[num-1].is_active = true;
                send_controller_event(ui, num-1);
            }
            return;
        } else {
            if (ui->controls[CONTROLS-1].is_active != true) {
                ui->controls[CONTROLS-1].is_active = true;
                send_controller_event(ui, CONTROLS-1);
            }
            return;
        }
    }

    check_is_active(ui, CONTROLS-1, true);
}

// set next controller active on tab key
static void set_next_controller_active(gx_matcheqUI *ui) {
    int num;
    if (get_active_controller_num(ui, &num)) {
        ui->controls[num].is_active = false;
        send_controller_event(ui, num);
        if(num<CONTROLS-1) {
            if (ui->controls[num+1].is_active != true) {
                ui->controls[num+1].is_active = true;
                send_controller_event(ui, num+1);
            }
            return;
        } else {
            if (ui->controls[0].is_active != true) {
                ui->controls[0].is_active = true;
                send_controller_event(ui, 0);
            }
            return;
        }
    }
    check_is_active(ui, 0, true);
}

// get/set active controller on enter and leave notify
static void get_last_active_controller(gx_matcheqUI *ui, bool set) {
    int num;
    if (get_active_controller_num(ui, &num)) {
        ui->sc = &ui->controls[num];
        ui->set_sc = num;
        ui->controls[num].is_active = set;
        send_controller_event(ui, num);
        return;
    } else if (!set) {
        ui->sc =  NULL;
    }
    if (ui->sc != NULL) {
        ui->sc->is_active = true;
        send_controller_event(ui, ui->set_sc);
    }
}

// map supported key's to integers or return zerro
static int key_mapping(Display *dpy, XKeyEvent *xkey) {
    if (xkey->keycode == XKeysymToKeycode(dpy,XK_Tab))
        return (xkey->state == ShiftMask) ? 1 : 2;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_Up))
        return 3;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_Right))
        return 3;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_Down))
        return 4;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_Left))
        return 4;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_Home))
        return 5;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_Insert))
        return 6;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_End))
        return 7;
    // keypad
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_Subtract))
        return 1;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_Add))
        return 2;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_Up))
        return 3;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_Right))
        return 3;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_Down))
        return 4;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_Left))
        return 4;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_Home))
        return 5;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_Insert))
        return 6;
    else if (xkey->keycode == XKeysymToKeycode(dpy,XK_KP_End))
        return 7;
    else return 0;
}

/*------------- the event loop ---------------*/

// general xevent handler
static void event_handler(gx_matcheqUI *ui) {
    XEvent xev;

    while (XPending(ui->dpy) > 0) {
        XNextEvent(ui->dpy, &xev);

        switch(xev.type) {
            case ConfigureNotify:
                // configure event, we only check for resize events here
                resize_event(ui);
            break;
            case Expose:
                // only fetch the last expose event
                if (xev.xexpose.count == 0) 
                    _expose(ui);
            break;

            case ButtonPress:
                ui->pos_x = xev.xbutton.x;
                ui->pos_y = xev.xbutton.y;

                switch(xev.xbutton.button) {
                    case Button1:
                        if (xev.xbutton.type == ButtonPress) {
                            ui->blocked = true;
                        }
                        // left mouse button click
                        button1_event(ui, &ui->start_value);
                    break;
                    case Button2:
                        // click on the mouse wheel
                        //fprintf(stderr,"Button2 \n");
                    break;
                    case Button3:
                        // right mouse button click
                        //fprintf(stderr,"Button3 \n");
                    break;
                    case  Button4:
                        // mouse wheel scroll up
                        scroll_event(ui, 1);
                    break;
                    case Button5:
                        // mouse wheel scroll down
                        scroll_event(ui, -1);
                    break;
                    default:
                    break;
                }
            break;
            case ButtonRelease:
                if (xev.xbutton.type == ButtonRelease) {
                    ui->blocked = false;
                }
            break;

            case KeyPress:
                switch (key_mapping(ui->dpy, &xev.xkey)) {
                    case 1: set_previous_controller_active(ui);
                    break;
                    case 2: set_next_controller_active(ui);
                    break;
                    case 3: key_event(ui, 1);
                    break;
                    case 4: key_event(ui, -1);
                    break;
                    case 5: set_key_value(ui, 1);
                    break;
                    case 6: set_key_value(ui, 2);
                    break;
                    case 7: set_key_value(ui, 3);
                    break;
                    default:
                    break;
                }
            break;

            case EnterNotify:
                if (!ui->blocked) get_last_active_controller(ui, true);
            break;
            case LeaveNotify:
                if (!ui->blocked) get_last_active_controller(ui, false);
            break;
            case MotionNotify:
                // mouse move while button1 is pressed
                if(xev.xmotion.state & Button1Mask) {
                    motion_event(ui, ui->start_value, xev.xmotion.y);
                }
            break;
            case ClientMessage:
                if (xev.xclient.message_type == ui->DrawController) {
                    int i = (int)xev.xclient.data.l[0];
                    controller_expose(ui, i, &ui->controls[i]);
                }
            break;

            default:
            break;
        }
    }
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                        LV2 interface
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// port value change message from host
static void port_event(LV2UI_Handle handle, uint32_t port_index,
                        uint32_t buffer_size, uint32_t format,
                        const void * buffer) {
    gx_matcheqUI* ui = (gx_matcheqUI*)handle;
    float value = *(float*)buffer;
    for (int i=0;i<CONTROLS;i++) {
        if (port_index == ui->controls[i].port) {
            if (ui->controls[i].type == METER) {
                value = power2db(ui, i,  *(float*)buffer);
            }
            check_value_changed(ui, i, &value);
        }
    }
}

// LV2 idle interface to host
static int ui_idle(LV2UI_Handle handle) {
    gx_matcheqUI* ui = (gx_matcheqUI*)handle;
    event_handler(ui);
    return 0;
}

// LV2 resize interface to host
static int ui_resize(LV2UI_Feature_Handle handle, int w, int h) {
    gx_matcheqUI* ui = (gx_matcheqUI*)handle;
    if (ui) resize_event(ui);
    return 0;
}

// connect idle and resize functions to host
static const void* extension_data(const char* uri) {
    static const LV2UI_Idle_Interface idle = { ui_idle };
    static const LV2UI_Resize resize = { 0 ,ui_resize };
    if (!strcmp(uri, LV2_UI__idleInterface)) {
        return &idle;
    }
    if (!strcmp(uri, LV2_UI__resize)) {
        return &resize;
    }
    return NULL;
}

static const LV2UI_Descriptor descriptor = {
    GXPLUGIN_UI_URI,
    instantiate,
    cleanup,
    port_event,
    extension_data
};


LV2_SYMBOL_EXPORT
const LV2UI_Descriptor* lv2ui_descriptor(uint32_t index) {
    switch (index) {
        case 0:
            return &descriptor;
        default:
        return NULL;
    }
}
