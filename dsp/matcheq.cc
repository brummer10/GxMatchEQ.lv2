// generated from file './/matcheq.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace matcheq {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec0[2];
	double fConst0;
	double fConst1;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec4[2];
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec16[2];
	double fVec0[2];
	double fConst9;
	double fConst10;
	double fRec15[2];
	double fConst11;
	double fConst12;
	double fRec14[3];
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fRec13[3];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fRec12[3];
	double fConst32;
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fRec11[3];
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fRec10[3];
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fRec9[3];
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fRec8[3];
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fRec7[3];
	double fConst77;
	double fConst78;
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec6[3];
	double fConst86;
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
	double fConst94;
	double fRec5[3];
	double fRec1[2];
	int iRec2[2];
	double fRec3[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT	*fVbargraph0_;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	double fRec20[2];
	double fConst95;
	double fConst96;
	double fRec32[2];
	double fRec31[3];
	double fVec1[2];
	double fConst97;
	double fConst98;
	double fRec30[2];
	double fConst99;
	double fRec29[3];
	double fConst100;
	double fRec28[3];
	double fRec27[3];
	double fRec26[3];
	double fRec25[3];
	double fRec24[3];
	double fRec23[3];
	double fRec22[3];
	double fRec21[3];
	double fRec17[2];
	int iRec18[2];
	double fRec19[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT	*fVbargraph1_;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT	*fVslider4_;
	double fRec36[2];
	double fConst101;
	double fConst102;
	double fConst103;
	double fRec47[2];
	double fRec46[3];
	double fVec2[2];
	double fConst104;
	double fConst105;
	double fRec45[2];
	double fConst106;
	double fRec44[3];
	double fConst107;
	double fRec43[3];
	double fRec42[3];
	double fRec41[3];
	double fRec40[3];
	double fRec39[3];
	double fRec38[3];
	double fRec37[3];
	double fRec33[2];
	int iRec34[2];
	double fRec35[2];
	FAUSTFLOAT fVbargraph2;
	FAUSTFLOAT	*fVbargraph2_;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT	*fVslider5_;
	double fRec51[2];
	double fConst108;
	double fConst109;
	double fConst110;
	double fRec61[2];
	double fRec60[3];
	double fVec3[2];
	double fConst111;
	double fConst112;
	double fRec59[2];
	double fConst113;
	double fRec58[3];
	double fConst114;
	double fRec57[3];
	double fRec56[3];
	double fRec55[3];
	double fRec54[3];
	double fRec53[3];
	double fRec52[3];
	double fRec48[2];
	int iRec49[2];
	double fRec50[2];
	FAUSTFLOAT fVbargraph3;
	FAUSTFLOAT	*fVbargraph3_;
	FAUSTFLOAT fVslider6;
	FAUSTFLOAT	*fVslider6_;
	double fRec65[2];
	double fConst115;
	double fConst116;
	double fConst117;
	double fRec74[2];
	double fRec73[3];
	double fVec4[2];
	double fConst118;
	double fConst119;
	double fRec72[2];
	double fConst120;
	double fRec71[3];
	double fConst121;
	double fRec70[3];
	double fRec69[3];
	double fRec68[3];
	double fRec67[3];
	double fRec66[3];
	double fRec62[2];
	int iRec63[2];
	double fRec64[2];
	FAUSTFLOAT fVbargraph4;
	FAUSTFLOAT	*fVbargraph4_;
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT	*fVslider7_;
	double fRec78[2];
	double fConst122;
	double fConst123;
	double fConst124;
	double fRec86[2];
	double fRec85[3];
	double fVec5[2];
	double fConst125;
	double fConst126;
	double fRec84[2];
	double fConst127;
	double fRec83[3];
	double fConst128;
	double fRec82[3];
	double fRec81[3];
	double fRec80[3];
	double fRec79[3];
	double fRec75[2];
	int iRec76[2];
	double fRec77[2];
	FAUSTFLOAT fVbargraph5;
	FAUSTFLOAT	*fVbargraph5_;
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT	*fVslider8_;
	double fRec90[2];
	double fConst129;
	double fConst130;
	double fConst131;
	double fRec97[2];
	double fRec96[3];
	double fVec6[2];
	double fConst132;
	double fConst133;
	double fRec95[2];
	double fConst134;
	double fRec94[3];
	double fConst135;
	double fRec93[3];
	double fRec92[3];
	double fRec91[3];
	double fRec87[2];
	int iRec88[2];
	double fRec89[2];
	FAUSTFLOAT fVbargraph6;
	FAUSTFLOAT	*fVbargraph6_;
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT	*fVslider9_;
	double fRec101[2];
	double fConst136;
	double fConst137;
	double fConst138;
	double fRec107[2];
	double fRec106[3];
	double fVec7[2];
	double fConst139;
	double fConst140;
	double fRec105[2];
	double fConst141;
	double fRec104[3];
	double fConst142;
	double fRec103[3];
	double fRec102[3];
	double fRec98[2];
	int iRec99[2];
	double fRec100[2];
	FAUSTFLOAT fVbargraph7;
	FAUSTFLOAT	*fVbargraph7_;
	FAUSTFLOAT fVslider10;
	FAUSTFLOAT	*fVslider10_;
	double fRec111[2];
	double fConst143;
	double fConst144;
	double fConst145;
	double fRec116[2];
	double fRec115[3];
	double fVec8[2];
	double fConst146;
	double fConst147;
	double fRec114[2];
	double fConst148;
	double fRec113[3];
	double fConst149;
	double fRec112[3];
	double fRec108[2];
	int iRec109[2];
	double fRec110[2];
	FAUSTFLOAT fVbargraph8;
	FAUSTFLOAT	*fVbargraph8_;
	double fConst150;
	FAUSTFLOAT fVslider11;
	FAUSTFLOAT	*fVslider11_;
	double fRec120[2];
	double fConst151;
	double fConst152;
	double fRec124[2];
	double fRec123[3];
	double fVec9[2];
	double fConst153;
	double fConst154;
	double fRec122[2];
	double fConst155;
	double fRec121[3];
	double fConst156;
	double fRec117[2];
	int iRec118[2];
	double fRec119[2];
	FAUSTFLOAT fVbargraph9;
	FAUSTFLOAT	*fVbargraph9_;
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT	*fVslider12_;
	double fRec128[2];
	double fConst157;
	double fRec130[2];
	double fRec129[3];
	double fRec125[2];
	int iRec126[2];
	double fRec127[2];
	FAUSTFLOAT fVbargraph10;
	FAUSTFLOAT	*fVbargraph10_;
	double _power0;
	double _power1;
	double _power2;
	double _power3;
	double _power4;
	double _power5;
	double _power6;
	double _power7;
	double _power8;
	double _power9;
	double _power10;
    double db_zero;
	FAUSTFLOAT bypass;
	FAUSTFLOAT	*bypass_;
    double anti_denormal;

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "matcheq";
	name = N_("Graphic EQ");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec0[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec4[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec16[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fVec0[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec15[l4] = 0.0;
	for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) fRec14[l5] = 0.0;
	for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) fRec13[l6] = 0.0;
	for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) fRec12[l7] = 0.0;
	for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) fRec11[l8] = 0.0;
	for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) fRec10[l9] = 0.0;
	for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) fRec9[l10] = 0.0;
	for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) fRec8[l11] = 0.0;
	for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) fRec7[l12] = 0.0;
	for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) fRec6[l13] = 0.0;
	for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) fRec5[l14] = 0.0;
	for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) fRec1[l15] = 0.0;
	for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) iRec2[l16] = 0;
	for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) fRec3[l17] = 0.0;
	for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) fRec20[l18] = 0.0;
	for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) fRec32[l19] = 0.0;
	for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) fRec31[l20] = 0.0;
	for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) fVec1[l21] = 0.0;
	for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) fRec30[l22] = 0.0;
	for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) fRec29[l23] = 0.0;
	for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) fRec28[l24] = 0.0;
	for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) fRec27[l25] = 0.0;
	for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) fRec26[l26] = 0.0;
	for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) fRec25[l27] = 0.0;
	for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) fRec24[l28] = 0.0;
	for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) fRec23[l29] = 0.0;
	for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) fRec22[l30] = 0.0;
	for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) fRec21[l31] = 0.0;
	for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) fRec17[l32] = 0.0;
	for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) iRec18[l33] = 0;
	for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) fRec19[l34] = 0.0;
	for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) fRec36[l35] = 0.0;
	for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) fRec47[l36] = 0.0;
	for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) fRec46[l37] = 0.0;
	for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) fVec2[l38] = 0.0;
	for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) fRec45[l39] = 0.0;
	for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) fRec44[l40] = 0.0;
	for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) fRec43[l41] = 0.0;
	for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) fRec42[l42] = 0.0;
	for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) fRec41[l43] = 0.0;
	for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) fRec40[l44] = 0.0;
	for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) fRec39[l45] = 0.0;
	for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) fRec38[l46] = 0.0;
	for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) fRec37[l47] = 0.0;
	for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) fRec33[l48] = 0.0;
	for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) iRec34[l49] = 0;
	for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) fRec35[l50] = 0.0;
	for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) fRec51[l51] = 0.0;
	for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) fRec61[l52] = 0.0;
	for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) fRec60[l53] = 0.0;
	for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) fVec3[l54] = 0.0;
	for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) fRec59[l55] = 0.0;
	for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) fRec58[l56] = 0.0;
	for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) fRec57[l57] = 0.0;
	for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) fRec56[l58] = 0.0;
	for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) fRec55[l59] = 0.0;
	for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) fRec54[l60] = 0.0;
	for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) fRec53[l61] = 0.0;
	for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) fRec52[l62] = 0.0;
	for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) fRec48[l63] = 0.0;
	for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) iRec49[l64] = 0;
	for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) fRec50[l65] = 0.0;
	for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) fRec65[l66] = 0.0;
	for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) fRec74[l67] = 0.0;
	for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) fRec73[l68] = 0.0;
	for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) fVec4[l69] = 0.0;
	for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) fRec72[l70] = 0.0;
	for (int l71 = 0; (l71 < 3); l71 = (l71 + 1)) fRec71[l71] = 0.0;
	for (int l72 = 0; (l72 < 3); l72 = (l72 + 1)) fRec70[l72] = 0.0;
	for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) fRec69[l73] = 0.0;
	for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) fRec68[l74] = 0.0;
	for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) fRec67[l75] = 0.0;
	for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) fRec66[l76] = 0.0;
	for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) fRec62[l77] = 0.0;
	for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) iRec63[l78] = 0;
	for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) fRec64[l79] = 0.0;
	for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) fRec78[l80] = 0.0;
	for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) fRec86[l81] = 0.0;
	for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) fRec85[l82] = 0.0;
	for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) fVec5[l83] = 0.0;
	for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) fRec84[l84] = 0.0;
	for (int l85 = 0; (l85 < 3); l85 = (l85 + 1)) fRec83[l85] = 0.0;
	for (int l86 = 0; (l86 < 3); l86 = (l86 + 1)) fRec82[l86] = 0.0;
	for (int l87 = 0; (l87 < 3); l87 = (l87 + 1)) fRec81[l87] = 0.0;
	for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) fRec80[l88] = 0.0;
	for (int l89 = 0; (l89 < 3); l89 = (l89 + 1)) fRec79[l89] = 0.0;
	for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) fRec75[l90] = 0.0;
	for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) iRec76[l91] = 0;
	for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) fRec77[l92] = 0.0;
	for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) fRec90[l93] = 0.0;
	for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) fRec97[l94] = 0.0;
	for (int l95 = 0; (l95 < 3); l95 = (l95 + 1)) fRec96[l95] = 0.0;
	for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) fVec6[l96] = 0.0;
	for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) fRec95[l97] = 0.0;
	for (int l98 = 0; (l98 < 3); l98 = (l98 + 1)) fRec94[l98] = 0.0;
	for (int l99 = 0; (l99 < 3); l99 = (l99 + 1)) fRec93[l99] = 0.0;
	for (int l100 = 0; (l100 < 3); l100 = (l100 + 1)) fRec92[l100] = 0.0;
	for (int l101 = 0; (l101 < 3); l101 = (l101 + 1)) fRec91[l101] = 0.0;
	for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) fRec87[l102] = 0.0;
	for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) iRec88[l103] = 0;
	for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) fRec89[l104] = 0.0;
	for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) fRec101[l105] = 0.0;
	for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) fRec107[l106] = 0.0;
	for (int l107 = 0; (l107 < 3); l107 = (l107 + 1)) fRec106[l107] = 0.0;
	for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) fVec7[l108] = 0.0;
	for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) fRec105[l109] = 0.0;
	for (int l110 = 0; (l110 < 3); l110 = (l110 + 1)) fRec104[l110] = 0.0;
	for (int l111 = 0; (l111 < 3); l111 = (l111 + 1)) fRec103[l111] = 0.0;
	for (int l112 = 0; (l112 < 3); l112 = (l112 + 1)) fRec102[l112] = 0.0;
	for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) fRec98[l113] = 0.0;
	for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) iRec99[l114] = 0;
	for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) fRec100[l115] = 0.0;
	for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) fRec111[l116] = 0.0;
	for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) fRec116[l117] = 0.0;
	for (int l118 = 0; (l118 < 3); l118 = (l118 + 1)) fRec115[l118] = 0.0;
	for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) fVec8[l119] = 0.0;
	for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) fRec114[l120] = 0.0;
	for (int l121 = 0; (l121 < 3); l121 = (l121 + 1)) fRec113[l121] = 0.0;
	for (int l122 = 0; (l122 < 3); l122 = (l122 + 1)) fRec112[l122] = 0.0;
	for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) fRec108[l123] = 0.0;
	for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) iRec109[l124] = 0;
	for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) fRec110[l125] = 0.0;
	for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) fRec120[l126] = 0.0;
	for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) fRec124[l127] = 0.0;
	for (int l128 = 0; (l128 < 3); l128 = (l128 + 1)) fRec123[l128] = 0.0;
	for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) fVec9[l129] = 0.0;
	for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) fRec122[l130] = 0.0;
	for (int l131 = 0; (l131 < 3); l131 = (l131 + 1)) fRec121[l131] = 0.0;
	for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) fRec117[l132] = 0.0;
	for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) iRec118[l133] = 0;
	for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) fRec119[l134] = 0.0;
	for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) fRec128[l135] = 0.0;
	for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) fRec130[l136] = 0.0;
	for (int l137 = 0; (l137 < 3); l137 = (l137 + 1)) fRec129[l137] = 0.0;
	for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) fRec125[l138] = 0.0;
	for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) iRec126[l139] = 0;
	for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) fRec127[l140] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (1.0 / fConst0);
	fConst2 = std::tan((56894.242956511152 / fConst0));
	fConst3 = (1.0 / fConst2);
	fConst4 = (1.0 / (((fConst3 + 1.0000000000000004) / fConst2) + 1.0));
	fConst5 = mydsp_faustpower2_f(fConst2);
	fConst6 = (1.0 / fConst5);
	fConst7 = (fConst3 + 1.0);
	fConst8 = (0.0 - (1.0 / (fConst7 * fConst2)));
	fConst9 = (1.0 / fConst7);
	fConst10 = (1.0 - fConst3);
	fConst11 = (((fConst3 + -1.0000000000000004) / fConst2) + 1.0);
	fConst12 = (2.0 * (1.0 - fConst6));
	fConst13 = (0.0 - (2.0 / fConst5));
	fConst14 = std::tan((35763.890768466204 / fConst0));
	fConst15 = (1.0 / fConst14);
	fConst16 = (fConst15 + 1.0);
	fConst17 = (1.0 / ((fConst16 / fConst14) + 1.0));
	fConst18 = (1.0 - fConst15);
	fConst19 = (1.0 - (fConst18 / fConst14));
	fConst20 = mydsp_faustpower2_f(fConst14);
	fConst21 = (1.0 / fConst20);
	fConst22 = (2.0 * (1.0 - fConst21));
	fConst23 = std::tan((17771.989641357461 / fConst0));
	fConst24 = (1.0 / fConst23);
	fConst25 = (fConst24 + 1.0);
	fConst26 = (1.0 / ((fConst25 / fConst23) + 1.0));
	fConst27 = (1.0 - fConst24);
	fConst28 = (1.0 - (fConst27 / fConst23));
	fConst29 = mydsp_faustpower2_f(fConst23);
	fConst30 = (1.0 / fConst29);
	fConst31 = (2.0 * (1.0 - fConst30));
	fConst32 = std::tan((8884.4240243519343 / fConst0));
	fConst33 = (1.0 / fConst32);
	fConst34 = (fConst33 + 1.0);
	fConst35 = (1.0 / ((fConst34 / fConst32) + 1.0));
	fConst36 = (1.0 - fConst33);
	fConst37 = (1.0 - (fConst36 / fConst32));
	fConst38 = mydsp_faustpower2_f(fConst32);
	fConst39 = (1.0 / fConst38);
	fConst40 = (2.0 * (1.0 - fConst39));
	fConst41 = std::tan((4442.2120121759672 / fConst0));
	fConst42 = (1.0 / fConst41);
	fConst43 = (fConst42 + 1.0);
	fConst44 = (1.0 / ((fConst43 / fConst41) + 1.0));
	fConst45 = (1.0 - fConst42);
	fConst46 = (1.0 - (fConst45 / fConst41));
	fConst47 = mydsp_faustpower2_f(fConst41);
	fConst48 = (1.0 / fConst47);
	fConst49 = (2.0 * (1.0 - fConst48));
	fConst50 = std::tan((2221.1060060879836 / fConst0));
	fConst51 = (1.0 / fConst50);
	fConst52 = (fConst51 + 1.0);
	fConst53 = (1.0 / ((fConst52 / fConst50) + 1.0));
	fConst54 = (1.0 - fConst51);
	fConst55 = (1.0 - (fConst54 / fConst50));
	fConst56 = mydsp_faustpower2_f(fConst50);
	fConst57 = (1.0 / fConst56);
	fConst58 = (2.0 * (1.0 - fConst57));
	fConst59 = std::tan((1112.1237993707869 / fConst0));
	fConst60 = (1.0 / fConst59);
	fConst61 = (fConst60 + 1.0);
	fConst62 = (1.0 / ((fConst61 / fConst59) + 1.0));
	fConst63 = (1.0 - fConst60);
	fConst64 = (1.0 - (fConst63 / fConst59));
	fConst65 = mydsp_faustpower2_f(fConst59);
	fConst66 = (1.0 / fConst65);
	fConst67 = (2.0 * (1.0 - fConst66));
	fConst68 = std::tan((556.06189968539343 / fConst0));
	fConst69 = (1.0 / fConst68);
	fConst70 = (fConst69 + 1.0);
	fConst71 = (1.0 / ((fConst70 / fConst68) + 1.0));
	fConst72 = (1.0 - fConst69);
	fConst73 = (1.0 - (fConst72 / fConst68));
	fConst74 = mydsp_faustpower2_f(fConst68);
	fConst75 = (1.0 / fConst74);
	fConst76 = (2.0 * (1.0 - fConst75));
	fConst77 = std::tan((276.46015351590177 / fConst0));
	fConst78 = (1.0 / fConst77);
	fConst79 = (fConst78 + 1.0);
	fConst80 = (1.0 / ((fConst79 / fConst77) + 1.0));
	fConst81 = (1.0 - fConst78);
	fConst82 = (1.0 - (fConst81 / fConst77));
	fConst83 = mydsp_faustpower2_f(fConst77);
	fConst84 = (1.0 / fConst83);
	fConst85 = (2.0 * (1.0 - fConst84));
	fConst86 = std::tan((138.23007675795088 / fConst0));
	fConst87 = (1.0 / fConst86);
	fConst88 = (fConst87 + 1.0);
	fConst89 = (1.0 / ((fConst88 / fConst86) + 1.0));
	fConst90 = (1.0 - fConst87);
	fConst91 = (1.0 - (fConst90 / fConst86));
	fConst92 = mydsp_faustpower2_f(fConst86);
	fConst93 = (1.0 / fConst92);
	fConst94 = (2.0 * (1.0 - fConst93));
	fConst95 = (1.0 / (((fConst15 + 1.0000000000000004) / fConst14) + 1.0));
	fConst96 = (1.0 / (fConst14 * fConst16));
	fConst97 = (0.0 - fConst96);
	fConst98 = (fConst18 / fConst16);
	fConst99 = (((fConst15 + -1.0000000000000004) / fConst14) + 1.0);
	fConst100 = (0.0 - (2.0 / fConst20));
	fConst101 = (1.0 / (((fConst24 + 1.0000000000000004) / fConst23) + 1.0));
	fConst102 = (1.0 / (fConst23 * fConst25));
	fConst103 = (1.0 / fConst16);
	fConst104 = (0.0 - fConst102);
	fConst105 = (fConst27 / fConst25);
	fConst106 = (((fConst24 + -1.0000000000000004) / fConst23) + 1.0);
	fConst107 = (0.0 - (2.0 / fConst29));
	fConst108 = (1.0 / (((fConst33 + 1.0000000000000004) / fConst32) + 1.0));
	fConst109 = (1.0 / (fConst32 * fConst34));
	fConst110 = (1.0 / fConst25);
	fConst111 = (0.0 - fConst109);
	fConst112 = (fConst36 / fConst34);
	fConst113 = (((fConst33 + -1.0000000000000004) / fConst32) + 1.0);
	fConst114 = (0.0 - (2.0 / fConst38));
	fConst115 = (1.0 / (((fConst42 + 1.0000000000000004) / fConst41) + 1.0));
	fConst116 = (1.0 / (fConst41 * fConst43));
	fConst117 = (1.0 / fConst34);
	fConst118 = (0.0 - fConst116);
	fConst119 = (fConst45 / fConst43);
	fConst120 = (((fConst42 + -1.0000000000000004) / fConst41) + 1.0);
	fConst121 = (0.0 - (2.0 / fConst47));
	fConst122 = (1.0 / (((fConst51 + 1.0000000000000004) / fConst50) + 1.0));
	fConst123 = (1.0 / (fConst50 * fConst52));
	fConst124 = (1.0 / fConst43);
	fConst125 = (0.0 - fConst123);
	fConst126 = (fConst54 / fConst52);
	fConst127 = (((fConst51 + -1.0000000000000004) / fConst50) + 1.0);
	fConst128 = (0.0 - (2.0 / fConst56));
	fConst129 = (1.0 / (((fConst60 + 1.0000000000000004) / fConst59) + 1.0));
	fConst130 = (1.0 / (fConst59 * fConst61));
	fConst131 = (1.0 / fConst52);
	fConst132 = (0.0 - fConst130);
	fConst133 = (fConst63 / fConst61);
	fConst134 = (((fConst60 + -1.0000000000000004) / fConst59) + 1.0);
	fConst135 = (0.0 - (2.0 / fConst65));
	fConst136 = (1.0 / (((fConst69 + 1.0000000000000004) / fConst68) + 1.0));
	fConst137 = (1.0 / (fConst68 * fConst70));
	fConst138 = (1.0 / fConst61);
	fConst139 = (0.0 - fConst137);
	fConst140 = (fConst72 / fConst70);
	fConst141 = (((fConst69 + -1.0000000000000004) / fConst68) + 1.0);
	fConst142 = (0.0 - (2.0 / fConst74));
	fConst143 = (1.0 / (((fConst78 + 1.0000000000000004) / fConst77) + 1.0));
	fConst144 = (1.0 / (fConst77 * fConst79));
	fConst145 = (1.0 / fConst70);
	fConst146 = (0.0 - fConst144);
	fConst147 = (fConst81 / fConst79);
	fConst148 = (((fConst78 + -1.0000000000000004) / fConst77) + 1.0);
	fConst149 = (0.0 - (2.0 / fConst83));
	fConst150 = (1.0 / (((fConst87 + 1.0000000000000004) / fConst86) + 1.0));
	fConst151 = (1.0 / (fConst86 * fConst88));
	fConst152 = (1.0 / fConst79);
	fConst153 = (0.0 - fConst151);
	fConst154 = (fConst90 / fConst88);
	fConst155 = (((fConst87 + -1.0000000000000004) / fConst86) + 1.0);
	fConst156 = (0.0 - (2.0 / fConst92));
	fConst157 = (1.0 / fConst88);
	fVslider0 = FAUSTFLOAT(1.0);
	fVslider1 = FAUSTFLOAT(0.0);
	fVslider2 = FAUSTFLOAT(0.0);
	fVslider3 = FAUSTFLOAT(0.0);
	fVslider4 = FAUSTFLOAT(0.0);
	fVslider5 = FAUSTFLOAT(0.0);
	fVslider6 = FAUSTFLOAT(0.0);
	fVslider7 = FAUSTFLOAT(0.0);
	fVslider8 = FAUSTFLOAT(0.0);
	fVslider9 = FAUSTFLOAT(0.0);
	fVslider10 = FAUSTFLOAT(0.0);
	fVslider11 = FAUSTFLOAT(0.0);
	fVslider12 = FAUSTFLOAT(0.0);
	db_zero = 20.*log10(0.0000003); // -137db
    anti_denormal = pow(10,-20);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
#define fVbargraph0 (*fVbargraph0_)
#define fVslider3 (*fVslider3_)
#define fVbargraph1 (*fVbargraph1_)
#define fVslider4 (*fVslider4_)
#define fVbargraph2 (*fVbargraph2_)
#define fVslider5 (*fVslider5_)
#define fVbargraph3 (*fVbargraph3_)
#define fVslider6 (*fVslider6_)
#define fVbargraph4 (*fVbargraph4_)
#define fVslider7 (*fVslider7_)
#define fVbargraph5 (*fVbargraph5_)
#define fVslider8 (*fVslider8_)
#define fVbargraph6 (*fVbargraph6_)
#define fVslider9 (*fVslider9_)
#define fVbargraph7 (*fVbargraph7_)
#define fVslider10 (*fVslider10_)
#define fVbargraph8 (*fVbargraph8_)
#define fVslider11 (*fVslider11_)
#define fVbargraph9 (*fVbargraph9_)
#define fVslider12 (*fVslider12_)
#define fVbargraph10 (*fVbargraph10_)
#define bypass (*bypass_)
	double fSlow0 = (0.0010000000000000009 * double(fVslider0));
	double fSlow1 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider1))));
	double fSlow2 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider2))));
	double fSlow3 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider3))));
	double fSlow4 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider4))));
	double fSlow5 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider5))));
	double fSlow6 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider6))));
	double fSlow7 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider7))));
	double fSlow8 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider8))));
	double fSlow9 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider9))));
	double fSlow10 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider10))));
	double fSlow11 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider11))));
	double fSlow12 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider12))));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec0[0] = (fSlow0 + (0.999 * fRec0[1]));
		double fTemp0 = double(input0[i]);
		int iTemp1 = (iRec2[1] < 4096);
		fRec4[0] = (fSlow1 + (0.999 * fRec4[1]));
		fRec16[0] = (fSlow2 + (0.999 * fRec16[1]));
		double fTemp2 = (fRec16[0] * fTemp0);
		fVec0[0] = fTemp2;
		fRec15[0] = ((fConst8 * fVec0[1]) - (fConst9 * ((fConst10 * fRec15[1]) - (fConst3 * fTemp2))));
		fRec14[0] = (fRec15[0] - (fConst4 * ((fConst11 * fRec14[2]) + (fConst12 * fRec14[1]))));
		double fTemp3 = (fConst22 * fRec13[1]);
		fRec13[0] = ((fConst4 * (((fConst6 * fRec14[0]) + (fConst13 * fRec14[1])) + (fConst6 * fRec14[2]))) - (fConst17 * ((fConst19 * fRec13[2]) + fTemp3)));
		double fTemp4 = (fConst31 * fRec12[1]);
		fRec12[0] = ((fRec13[2] + (fConst17 * (fTemp3 + (fConst19 * fRec13[0])))) - (fConst26 * ((fConst28 * fRec12[2]) + fTemp4)));
		double fTemp5 = (fConst40 * fRec11[1]);
		fRec11[0] = ((fRec12[2] + (fConst26 * (fTemp4 + (fConst28 * fRec12[0])))) - (fConst35 * ((fConst37 * fRec11[2]) + fTemp5)));
		double fTemp6 = (fConst49 * fRec10[1]);
		fRec10[0] = ((fRec11[2] + (fConst35 * (fTemp5 + (fConst37 * fRec11[0])))) - (fConst44 * ((fConst46 * fRec10[2]) + fTemp6)));
		double fTemp7 = (fConst58 * fRec9[1]);
		fRec9[0] = ((fRec10[2] + (fConst44 * (fTemp6 + (fConst46 * fRec10[0])))) - (fConst53 * ((fConst55 * fRec9[2]) + fTemp7)));
		double fTemp8 = (fConst67 * fRec8[1]);
		fRec8[0] = ((fRec9[2] + (fConst53 * (fTemp7 + (fConst55 * fRec9[0])))) - (fConst62 * ((fConst64 * fRec8[2]) + fTemp8)));
		double fTemp9 = (fConst76 * fRec7[1]);
		fRec7[0] = ((fRec8[2] + (fConst62 * (fTemp8 + (fConst64 * fRec8[0])))) - (fConst71 * ((fConst73 * fRec7[2]) + fTemp9)));
		double fTemp10 = (fConst85 * fRec6[1]);
		fRec6[0] = ((fRec7[2] + (fConst71 * (fTemp9 + (fConst73 * fRec7[0])))) - (fConst80 * ((fConst82 * fRec6[2]) + fTemp10)));
		double fTemp11 = (fConst94 * fRec5[1]);
		fRec5[0] = ((fRec6[2] + (fConst80 * (fTemp10 + (fConst82 * fRec6[0])))) - (fConst89 * ((fConst91 * fRec5[2]) + fTemp11)));
		double fTemp12 = (fRec4[0] * (fRec5[2] + (fConst89 * (fTemp11 + (fConst91 * fRec5[0])))));
		double fTemp13 = std::max<double>(fConst1, std::fabs(fTemp12));
		fRec1[0] = (iTemp1?std::max<double>(fRec1[1], fTemp13):fTemp13);
		iRec2[0] = (iTemp1?(iRec2[1] + 1):1);
		fRec3[0] = (iTemp1?fRec3[1]:fRec1[1]);
		_power0 = FAUSTFLOAT(fRec3[0]);
		int iTemp14 = (iRec18[1] < 4096);
		fRec20[0] = (fSlow3 + (0.999 * fRec20[1]));
		fRec32[0] = (0.0 - (fConst9 * ((fConst10 * fRec32[1]) - (fTemp2 + fVec0[1]))));
		fRec31[0] = (fRec32[0] - (fConst4 * ((fConst11 * fRec31[2]) + (fConst12 * fRec31[1]))));
		double fTemp15 = (fRec31[2] + (fRec31[0] + (2.0 * fRec31[1])));
		fVec1[0] = fTemp15;
		fRec30[0] = ((fConst4 * ((fConst96 * fTemp15) + (fConst97 * fVec1[1]))) - (fConst98 * fRec30[1]));
		fRec29[0] = (fRec30[0] - (fConst95 * ((fConst99 * fRec29[2]) + (fConst22 * fRec29[1]))));
		double fTemp16 = (fConst31 * fRec28[1]);
		fRec28[0] = ((fConst95 * (((fConst21 * fRec29[0]) + (fConst100 * fRec29[1])) + (fConst21 * fRec29[2]))) - (fConst26 * ((fConst28 * fRec28[2]) + fTemp16)));
		double fTemp17 = (fConst40 * fRec27[1]);
		fRec27[0] = ((fRec28[2] + (fConst26 * (fTemp16 + (fConst28 * fRec28[0])))) - (fConst35 * ((fConst37 * fRec27[2]) + fTemp17)));
		double fTemp18 = (fConst49 * fRec26[1]);
		fRec26[0] = ((fRec27[2] + (fConst35 * (fTemp17 + (fConst37 * fRec27[0])))) - (fConst44 * ((fConst46 * fRec26[2]) + fTemp18)));
		double fTemp19 = (fConst58 * fRec25[1]);
		fRec25[0] = ((fRec26[2] + (fConst44 * (fTemp18 + (fConst46 * fRec26[0])))) - (fConst53 * ((fConst55 * fRec25[2]) + fTemp19)));
		double fTemp20 = (fConst67 * fRec24[1]);
		fRec24[0] = ((fRec25[2] + (fConst53 * (fTemp19 + (fConst55 * fRec25[0])))) - (fConst62 * ((fConst64 * fRec24[2]) + fTemp20)));
		double fTemp21 = (fConst76 * fRec23[1]);
		fRec23[0] = ((fRec24[2] + (fConst62 * (fTemp20 + (fConst64 * fRec24[0])))) - (fConst71 * ((fConst73 * fRec23[2]) + fTemp21)));
		double fTemp22 = (fConst85 * fRec22[1]);
		fRec22[0] = ((fRec23[2] + (fConst71 * (fTemp21 + (fConst73 * fRec23[0])))) - (fConst80 * ((fConst82 * fRec22[2]) + fTemp22)));
		double fTemp23 = (fConst94 * fRec21[1]);
		fRec21[0] = ((fRec22[2] + (fConst80 * (fTemp22 + (fConst82 * fRec22[0])))) - (fConst89 * ((fConst91 * fRec21[2]) + fTemp23)));
		double fTemp24 = (fRec20[0] * (fRec21[2] + (fConst89 * (fTemp23 + (fConst91 * fRec21[0])))));
		double fTemp25 = std::max<double>(fConst1, std::fabs(fTemp24));
		fRec17[0] = (iTemp14?std::max<double>(fRec17[1], fTemp25):fTemp25);
		iRec18[0] = (iTemp14?(iRec18[1] + 1):1);
		fRec19[0] = (iTemp14?fRec19[1]:fRec17[1]);
		_power1 = FAUSTFLOAT(fRec19[0]);
		int iTemp26 = (iRec34[1] < 4096);
		fRec36[0] = (fSlow4 + (0.999 * fRec36[1]));
		fRec47[0] = (0.0 - (fConst103 * ((fConst18 * fRec47[1]) - (fConst4 * (fTemp15 + fVec1[1])))));
		fRec46[0] = (fRec47[0] - (fConst95 * ((fConst99 * fRec46[2]) + (fConst22 * fRec46[1]))));
		double fTemp27 = (fRec46[2] + (fRec46[0] + (2.0 * fRec46[1])));
		fVec2[0] = fTemp27;
		fRec45[0] = ((fConst95 * ((fConst102 * fTemp27) + (fConst104 * fVec2[1]))) - (fConst105 * fRec45[1]));
		fRec44[0] = (fRec45[0] - (fConst101 * ((fConst106 * fRec44[2]) + (fConst31 * fRec44[1]))));
		double fTemp28 = (fConst40 * fRec43[1]);
		fRec43[0] = ((fConst101 * (((fConst30 * fRec44[0]) + (fConst107 * fRec44[1])) + (fConst30 * fRec44[2]))) - (fConst35 * ((fConst37 * fRec43[2]) + fTemp28)));
		double fTemp29 = (fConst49 * fRec42[1]);
		fRec42[0] = ((fRec43[2] + (fConst35 * (fTemp28 + (fConst37 * fRec43[0])))) - (fConst44 * ((fConst46 * fRec42[2]) + fTemp29)));
		double fTemp30 = (fConst58 * fRec41[1]);
		fRec41[0] = ((fRec42[2] + (fConst44 * (fTemp29 + (fConst46 * fRec42[0])))) - (fConst53 * ((fConst55 * fRec41[2]) + fTemp30)));
		double fTemp31 = (fConst67 * fRec40[1]);
		fRec40[0] = ((fRec41[2] + (fConst53 * (fTemp30 + (fConst55 * fRec41[0])))) - (fConst62 * ((fConst64 * fRec40[2]) + fTemp31)));
		double fTemp32 = (fConst76 * fRec39[1]);
		fRec39[0] = ((fRec40[2] + (fConst62 * (fTemp31 + (fConst64 * fRec40[0])))) - (fConst71 * ((fConst73 * fRec39[2]) + fTemp32)));
		double fTemp33 = (fConst85 * fRec38[1]);
		fRec38[0] = ((fRec39[2] + (fConst71 * (fTemp32 + (fConst73 * fRec39[0])))) - (fConst80 * ((fConst82 * fRec38[2]) + fTemp33)));
		double fTemp34 = (fConst94 * fRec37[1]);
		fRec37[0] = ((fRec38[2] + (fConst80 * (fTemp33 + (fConst82 * fRec38[0])))) - (fConst89 * ((fConst91 * fRec37[2]) + fTemp34)));
		double fTemp35 = (fRec36[0] * (fRec37[2] + (fConst89 * (fTemp34 + (fConst91 * fRec37[0])))));
		double fTemp36 = std::max<double>(fConst1, std::fabs(fTemp35));
		fRec33[0] = (iTemp26?std::max<double>(fRec33[1], fTemp36):fTemp36);
		iRec34[0] = (iTemp26?(iRec34[1] + 1):1);
		fRec35[0] = (iTemp26?fRec35[1]:fRec33[1]);
		_power2 = FAUSTFLOAT(fRec35[0]);
		int iTemp37 = (iRec49[1] < 4096);
		fRec51[0] = (fSlow5 + (0.999 * fRec51[1]));
		fRec61[0] = (0.0 - (fConst110 * ((fConst27 * fRec61[1]) - (fConst95 * (fTemp27 + fVec2[1])))));
		fRec60[0] = (fRec61[0] - (fConst101 * ((fConst106 * fRec60[2]) + (fConst31 * fRec60[1]))));
		double fTemp38 = (fRec60[2] + (fRec60[0] + (2.0 * fRec60[1])));
		fVec3[0] = fTemp38;
		fRec59[0] = ((fConst101 * ((fConst109 * fTemp38) + (fConst111 * fVec3[1]))) - (fConst112 * fRec59[1]));
		fRec58[0] = (fRec59[0] - (fConst108 * ((fConst113 * fRec58[2]) + (fConst40 * fRec58[1]))));
		double fTemp39 = (fConst49 * fRec57[1]);
		fRec57[0] = ((fConst108 * (((fConst39 * fRec58[0]) + (fConst114 * fRec58[1])) + (fConst39 * fRec58[2]))) - (fConst44 * ((fConst46 * fRec57[2]) + fTemp39)));
		double fTemp40 = (fConst58 * fRec56[1]);
		fRec56[0] = ((fRec57[2] + (fConst44 * (fTemp39 + (fConst46 * fRec57[0])))) - (fConst53 * ((fConst55 * fRec56[2]) + fTemp40)));
		double fTemp41 = (fConst67 * fRec55[1]);
		fRec55[0] = ((fRec56[2] + (fConst53 * (fTemp40 + (fConst55 * fRec56[0])))) - (fConst62 * ((fConst64 * fRec55[2]) + fTemp41)));
		double fTemp42 = (fConst76 * fRec54[1]);
		fRec54[0] = ((fRec55[2] + (fConst62 * (fTemp41 + (fConst64 * fRec55[0])))) - (fConst71 * ((fConst73 * fRec54[2]) + fTemp42)));
		double fTemp43 = (fConst85 * fRec53[1]);
		fRec53[0] = ((fRec54[2] + (fConst71 * (fTemp42 + (fConst73 * fRec54[0])))) - (fConst80 * ((fConst82 * fRec53[2]) + fTemp43)));
		double fTemp44 = (fConst94 * fRec52[1]);
		fRec52[0] = ((fRec53[2] + (fConst80 * (fTemp43 + (fConst82 * fRec53[0])))) - (fConst89 * ((fConst91 * fRec52[2]) + fTemp44)));
		double fTemp45 = (fRec51[0] * (fRec52[2] + (fConst89 * (fTemp44 + (fConst91 * fRec52[0])))));
		double fTemp46 = std::max<double>(fConst1, std::fabs(fTemp45));
		fRec48[0] = (iTemp37?std::max<double>(fRec48[1], fTemp46):fTemp46);
		iRec49[0] = (iTemp37?(iRec49[1] + 1):1);
		fRec50[0] = (iTemp37?fRec50[1]:fRec48[1]);
		_power3 = FAUSTFLOAT(fRec50[0]);
		int iTemp47 = (iRec63[1] < 4096);
		fRec65[0] = (fSlow6 + (0.999 * fRec65[1]));
		fRec74[0] = (0.0 - (fConst117 * ((fConst36 * fRec74[1]) - (fConst101 * (fTemp38 + fVec3[1])))));
		fRec73[0] = (fRec74[0] - (fConst108 * ((fConst113 * fRec73[2]) + (fConst40 * fRec73[1]))));
		double fTemp48 = (fRec73[2] + (fRec73[0] + (2.0 * fRec73[1])));
		fVec4[0] = fTemp48;
		fRec72[0] = ((fConst108 * ((fConst116 * fTemp48) + (fConst118 * fVec4[1]))) - (fConst119 * fRec72[1]));
		fRec71[0] = (fRec72[0] - (fConst115 * ((fConst120 * fRec71[2]) + (fConst49 * fRec71[1]))));
		double fTemp49 = (fConst58 * fRec70[1]);
		fRec70[0] = ((fConst115 * (((fConst48 * fRec71[0]) + (fConst121 * fRec71[1])) + (fConst48 * fRec71[2]))) - (fConst53 * ((fConst55 * fRec70[2]) + fTemp49)));
		double fTemp50 = (fConst67 * fRec69[1]);
		fRec69[0] = ((fRec70[2] + (fConst53 * (fTemp49 + (fConst55 * fRec70[0])))) - (fConst62 * ((fConst64 * fRec69[2]) + fTemp50)));
		double fTemp51 = (fConst76 * fRec68[1]);
		fRec68[0] = ((fRec69[2] + (fConst62 * (fTemp50 + (fConst64 * fRec69[0])))) - (fConst71 * ((fConst73 * fRec68[2]) + fTemp51)));
		double fTemp52 = (fConst85 * fRec67[1]);
		fRec67[0] = ((fRec68[2] + (fConst71 * (fTemp51 + (fConst73 * fRec68[0])))) - (fConst80 * ((fConst82 * fRec67[2]) + fTemp52)));
		double fTemp53 = (fConst94 * fRec66[1]);
		fRec66[0] = ((fRec67[2] + (fConst80 * (fTemp52 + (fConst82 * fRec67[0])))) - (fConst89 * ((fConst91 * fRec66[2]) + fTemp53)));
		double fTemp54 = (fRec65[0] * (fRec66[2] + (fConst89 * (fTemp53 + (fConst91 * fRec66[0])))));
		double fTemp55 = std::max<double>(fConst1, std::fabs(fTemp54));
		fRec62[0] = (iTemp47?std::max<double>(fRec62[1], fTemp55):fTemp55);
		iRec63[0] = (iTemp47?(iRec63[1] + 1):1);
		fRec64[0] = (iTemp47?fRec64[1]:fRec62[1]);
		_power4 = FAUSTFLOAT(fRec64[0]);
		int iTemp56 = (iRec76[1] < 4096);
		fRec78[0] = (fSlow7 + (0.999 * fRec78[1]));
		fRec86[0] = (0.0 - (fConst124 * ((fConst45 * fRec86[1]) - (fConst108 * (fTemp48 + fVec4[1])))));
		fRec85[0] = (fRec86[0] - (fConst115 * ((fConst120 * fRec85[2]) + (fConst49 * fRec85[1]))));
		double fTemp57 = (fRec85[2] + (fRec85[0] + (2.0 * fRec85[1])));
		fVec5[0] = fTemp57;
		fRec84[0] = ((fConst115 * ((fConst123 * fTemp57) + (fConst125 * fVec5[1]))) - (fConst126 * fRec84[1]));
		fRec83[0] = (fRec84[0] - (fConst122 * ((fConst127 * fRec83[2]) + (fConst58 * fRec83[1]))));
		double fTemp58 = (fConst67 * fRec82[1]);
		fRec82[0] = ((fConst122 * (((fConst57 * fRec83[0]) + (fConst128 * fRec83[1])) + (fConst57 * fRec83[2]))) - (fConst62 * ((fConst64 * fRec82[2]) + fTemp58)));
		double fTemp59 = (fConst76 * fRec81[1]);
		fRec81[0] = ((fRec82[2] + (fConst62 * (fTemp58 + (fConst64 * fRec82[0])))) - (fConst71 * ((fConst73 * fRec81[2]) + fTemp59)));
		double fTemp60 = (fConst85 * fRec80[1]);
		fRec80[0] = ((fRec81[2] + (fConst71 * (fTemp59 + (fConst73 * fRec81[0])))) - (fConst80 * ((fConst82 * fRec80[2]) + fTemp60)));
		double fTemp61 = (fConst94 * fRec79[1]);
		fRec79[0] = ((fRec80[2] + (fConst80 * (fTemp60 + (fConst82 * fRec80[0])))) - (fConst89 * ((fConst91 * fRec79[2]) + fTemp61)));
		double fTemp62 = (fRec78[0] * (fRec79[2] + (fConst89 * (fTemp61 + (fConst91 * fRec79[0])))));
		double fTemp63 = std::max<double>(fConst1, std::fabs(fTemp62));
		fRec75[0] = (iTemp56?std::max<double>(fRec75[1], fTemp63):fTemp63);
		iRec76[0] = (iTemp56?(iRec76[1] + 1):1);
		fRec77[0] = (iTemp56?fRec77[1]:fRec75[1]);
		_power5 = FAUSTFLOAT(fRec77[0]);
		int iTemp64 = (iRec88[1] < 4096);
		fRec90[0] = (fSlow8 + (0.999 * fRec90[1]));
		fRec97[0] = (0.0 - (fConst131 * ((fConst54 * fRec97[1]) - (fConst115 * (fTemp57 + fVec5[1])))));
		fRec96[0] = (fRec97[0] - (fConst122 * ((fConst127 * fRec96[2]) + (fConst58 * fRec96[1]))));
		double fTemp65 = (fRec96[2] + (fRec96[0] + (2.0 * fRec96[1])));
		fVec6[0] = fTemp65;
		fRec95[0] = ((fConst122 * ((fConst130 * fTemp65) + (fConst132 * fVec6[1]))) - (fConst133 * fRec95[1]));
		fRec94[0] = (fRec95[0] - (fConst129 * ((fConst134 * fRec94[2]) + (fConst67 * fRec94[1]))));
		double fTemp66 = (fConst76 * fRec93[1]);
		fRec93[0] = ((fConst129 * (((fConst66 * fRec94[0]) + (fConst135 * fRec94[1])) + (fConst66 * fRec94[2]))) - (fConst71 * ((fConst73 * fRec93[2]) + fTemp66)));
		double fTemp67 = (fConst85 * fRec92[1]);
		fRec92[0] = ((fRec93[2] + (fConst71 * (fTemp66 + (fConst73 * fRec93[0])))) - (fConst80 * ((fConst82 * fRec92[2]) + fTemp67)));
		double fTemp68 = (fConst94 * fRec91[1]);
		fRec91[0] = ((fRec92[2] + (fConst80 * (fTemp67 + (fConst82 * fRec92[0])))) - (fConst89 * ((fConst91 * fRec91[2]) + fTemp68)));
		double fTemp69 = (fRec90[0] * (fRec91[2] + (fConst89 * (fTemp68 + (fConst91 * fRec91[0])))));
		double fTemp70 = std::max<double>(fConst1, std::fabs(fTemp69));
		fRec87[0] = (iTemp64?std::max<double>(fRec87[1], fTemp70):fTemp70);
		iRec88[0] = (iTemp64?(iRec88[1] + 1):1);
		fRec89[0] = (iTemp64?fRec89[1]:fRec87[1]);
		_power6 = FAUSTFLOAT(fRec89[0]);
		int iTemp71 = (iRec99[1] < 4096);
		fRec101[0] = (fSlow9 + (0.999 * fRec101[1]));
		fRec107[0] = (0.0 - (fConst138 * ((fConst63 * fRec107[1]) - (fConst122 * (fTemp65 + fVec6[1])))));
		fRec106[0] = (fRec107[0] - (fConst129 * ((fConst134 * fRec106[2]) + (fConst67 * fRec106[1]))));
		double fTemp72 = (fRec106[2] + (fRec106[0] + (2.0 * fRec106[1])));
		fVec7[0] = fTemp72;
		fRec105[0] = ((fConst129 * ((fConst137 * fTemp72) + (fConst139 * fVec7[1]))) - (fConst140 * fRec105[1]));
		fRec104[0] = (fRec105[0] - (fConst136 * ((fConst141 * fRec104[2]) + (fConst76 * fRec104[1]))));
		double fTemp73 = (fConst85 * fRec103[1]);
		fRec103[0] = ((fConst136 * (((fConst75 * fRec104[0]) + (fConst142 * fRec104[1])) + (fConst75 * fRec104[2]))) - (fConst80 * ((fConst82 * fRec103[2]) + fTemp73)));
		double fTemp74 = (fConst94 * fRec102[1]);
		fRec102[0] = ((fRec103[2] + (fConst80 * (fTemp73 + (fConst82 * fRec103[0])))) - (fConst89 * ((fConst91 * fRec102[2]) + fTemp74)));
		double fTemp75 = (fRec101[0] * (fRec102[2] + (fConst89 * (fTemp74 + (fConst91 * fRec102[0])))));
		double fTemp76 = std::max<double>(fConst1, std::fabs(fTemp75));
		fRec98[0] = (iTemp71?std::max<double>(fRec98[1], fTemp76):fTemp76);
		iRec99[0] = (iTemp71?(iRec99[1] + 1):1);
		fRec100[0] = (iTemp71?fRec100[1]:fRec98[1]);
		_power7 = FAUSTFLOAT(fRec100[0]);
		int iTemp77 = (iRec109[1] < 4096);
		fRec111[0] = (fSlow10 + (0.999 * fRec111[1]));
		fRec116[0] = (0.0 - (fConst145 * ((fConst72 * fRec116[1]) - (fConst129 * (fTemp72 + fVec7[1])))));
		fRec115[0] = (fRec116[0] - (fConst136 * ((fConst141 * fRec115[2]) + (fConst76 * fRec115[1]))));
		double fTemp78 = (fRec115[2] + (fRec115[0] + (2.0 * fRec115[1])));
		fVec8[0] = fTemp78;
		fRec114[0] = ((fConst136 * ((fConst144 * fTemp78) + (fConst146 * fVec8[1]))) - (fConst147 * fRec114[1]));
		fRec113[0] = (fRec114[0] - (fConst143 * ((fConst148 * fRec113[2]) + (fConst85 * fRec113[1]))));
		double fTemp79 = (fConst94 * fRec112[1]);
		fRec112[0] = ((fConst143 * (((fConst84 * fRec113[0]) + (fConst149 * fRec113[1])) + (fConst84 * fRec113[2]))) - (fConst89 * ((fConst91 * fRec112[2]) + fTemp79)));
		double fTemp80 = (fRec111[0] * (fRec112[2] + (fConst89 * (fTemp79 + (fConst91 * fRec112[0])))));
		double fTemp81 = std::max<double>(fConst1, std::fabs(fTemp80));
		fRec108[0] = (iTemp77?std::max<double>(fRec108[1], fTemp81):fTemp81);
		iRec109[0] = (iTemp77?(iRec109[1] + 1):1);
		fRec110[0] = (iTemp77?fRec110[1]:fRec108[1]);
		_power8 = FAUSTFLOAT(fRec110[0]);
		int iTemp82 = (iRec118[1] < 4096);
		fRec120[0] = (fSlow11 + (0.999 * fRec120[1]));
		fRec124[0] = (0.0 - (fConst152 * ((fConst81 * fRec124[1]) - (fConst136 * (fTemp78 + fVec8[1])))));
		fRec123[0] = (fRec124[0] - (fConst143 * ((fConst148 * fRec123[2]) + (fConst85 * fRec123[1]))));
		double fTemp83 = (fRec123[2] + (fRec123[0] + (2.0 * fRec123[1])));
		fVec9[0] = fTemp83;
		fRec122[0] = ((fConst143 * ((fConst151 * fTemp83) + (fConst153 * fVec9[1]))) - (fConst154 * fRec122[1]));
		fRec121[0] = (fRec122[0] - (fConst150 * ((fConst155 * fRec121[2]) + (fConst94 * fRec121[1]))));
		double fTemp84 = (fConst150 * (fRec120[0] * (((fConst93 * fRec121[0]) + (fConst156 * fRec121[1])) + (fConst93 * fRec121[2]))));
		double fTemp85 = std::max<double>(fConst1, std::fabs(fTemp84));
		fRec117[0] = (iTemp82?std::max<double>(fRec117[1], fTemp85):fTemp85);
		iRec118[0] = (iTemp82?(iRec118[1] + 1):1);
		fRec119[0] = (iTemp82?fRec119[1]:fRec117[1]);
		_power9 = FAUSTFLOAT(fRec119[0]);
		int iTemp86 = (iRec126[1] < 4096);
		fRec128[0] = (fSlow12 + (0.999 * fRec128[1]));
		fRec130[0] = (0.0 - (fConst157 * ((fConst90 * fRec130[1]) - (fConst143 * (fTemp83 + fVec9[1])))));
		fRec129[0] = (fRec130[0] - (fConst150 * ((fConst155 * fRec129[2]) + (fConst94 * fRec129[1]))));
		double fTemp87 = (fConst150 * (fRec128[0] * (fRec129[2] + (fRec129[0] + (2.0 * fRec129[1])))));
		double fTemp88 = std::max<double>(fConst1, std::fabs(fTemp87));
		fRec125[0] = (iTemp86?std::max<double>(fRec125[1], fTemp88):fTemp88);
		iRec126[0] = (iTemp86?(iRec126[1] + 1):1);
		fRec127[0] = (iTemp86?fRec127[1]:fRec125[1]);
		_power10 = FAUSTFLOAT(fRec127[0]);
		output0[i] = FAUSTFLOAT((((1.0 - fRec0[0]) * fTemp0) + (fRec0[0] * ((((((((((fTemp12 + fTemp24) + fTemp35) + fTemp45) + fTemp54) + fTemp62) + fTemp69) + fTemp75) + fTemp80) + fTemp84) + fTemp87))));
		fRec0[1] = fRec0[0];
		fRec4[1] = fRec4[0];
		fRec16[1] = fRec16[0];
		fVec0[1] = fVec0[0];
		fRec15[1] = fRec15[0];
		fRec14[2] = fRec14[1];
		fRec14[1] = fRec14[0];
		fRec13[2] = fRec13[1];
		fRec13[1] = fRec13[0];
		fRec12[2] = fRec12[1];
		fRec12[1] = fRec12[0];
		fRec11[2] = fRec11[1];
		fRec11[1] = fRec11[0];
		fRec10[2] = fRec10[1];
		fRec10[1] = fRec10[0];
		fRec9[2] = fRec9[1];
		fRec9[1] = fRec9[0];
		fRec8[2] = fRec8[1];
		fRec8[1] = fRec8[0];
		fRec7[2] = fRec7[1];
		fRec7[1] = fRec7[0];
		fRec6[2] = fRec6[1];
		fRec6[1] = fRec6[0];
		fRec5[2] = fRec5[1];
		fRec5[1] = fRec5[0];
		fRec1[1] = fRec1[0];
		iRec2[1] = iRec2[0];
		fRec3[1] = fRec3[0];
		fRec20[1] = fRec20[0];
		fRec32[1] = fRec32[0];
		fRec31[2] = fRec31[1];
		fRec31[1] = fRec31[0];
		fVec1[1] = fVec1[0];
		fRec30[1] = fRec30[0];
		fRec29[2] = fRec29[1];
		fRec29[1] = fRec29[0];
		fRec28[2] = fRec28[1];
		fRec28[1] = fRec28[0];
		fRec27[2] = fRec27[1];
		fRec27[1] = fRec27[0];
		fRec26[2] = fRec26[1];
		fRec26[1] = fRec26[0];
		fRec25[2] = fRec25[1];
		fRec25[1] = fRec25[0];
		fRec24[2] = fRec24[1];
		fRec24[1] = fRec24[0];
		fRec23[2] = fRec23[1];
		fRec23[1] = fRec23[0];
		fRec22[2] = fRec22[1];
		fRec22[1] = fRec22[0];
		fRec21[2] = fRec21[1];
		fRec21[1] = fRec21[0];
		fRec17[1] = fRec17[0];
		iRec18[1] = iRec18[0];
		fRec19[1] = fRec19[0];
		fRec36[1] = fRec36[0];
		fRec47[1] = fRec47[0];
		fRec46[2] = fRec46[1];
		fRec46[1] = fRec46[0];
		fVec2[1] = fVec2[0];
		fRec45[1] = fRec45[0];
		fRec44[2] = fRec44[1];
		fRec44[1] = fRec44[0];
		fRec43[2] = fRec43[1];
		fRec43[1] = fRec43[0];
		fRec42[2] = fRec42[1];
		fRec42[1] = fRec42[0];
		fRec41[2] = fRec41[1];
		fRec41[1] = fRec41[0];
		fRec40[2] = fRec40[1];
		fRec40[1] = fRec40[0];
		fRec39[2] = fRec39[1];
		fRec39[1] = fRec39[0];
		fRec38[2] = fRec38[1];
		fRec38[1] = fRec38[0];
		fRec37[2] = fRec37[1];
		fRec37[1] = fRec37[0];
		fRec33[1] = fRec33[0];
		iRec34[1] = iRec34[0];
		fRec35[1] = fRec35[0];
		fRec51[1] = fRec51[0];
		fRec61[1] = fRec61[0];
		fRec60[2] = fRec60[1];
		fRec60[1] = fRec60[0];
		fVec3[1] = fVec3[0];
		fRec59[1] = fRec59[0];
		fRec58[2] = fRec58[1];
		fRec58[1] = fRec58[0];
		fRec57[2] = fRec57[1];
		fRec57[1] = fRec57[0];
		fRec56[2] = fRec56[1];
		fRec56[1] = fRec56[0];
		fRec55[2] = fRec55[1];
		fRec55[1] = fRec55[0];
		fRec54[2] = fRec54[1];
		fRec54[1] = fRec54[0];
		fRec53[2] = fRec53[1];
		fRec53[1] = fRec53[0];
		fRec52[2] = fRec52[1];
		fRec52[1] = fRec52[0];
		fRec48[1] = fRec48[0];
		iRec49[1] = iRec49[0];
		fRec50[1] = fRec50[0];
		fRec65[1] = fRec65[0];
		fRec74[1] = fRec74[0];
		fRec73[2] = fRec73[1];
		fRec73[1] = fRec73[0];
		fVec4[1] = fVec4[0];
		fRec72[1] = fRec72[0];
		fRec71[2] = fRec71[1];
		fRec71[1] = fRec71[0];
		fRec70[2] = fRec70[1];
		fRec70[1] = fRec70[0];
		fRec69[2] = fRec69[1];
		fRec69[1] = fRec69[0];
		fRec68[2] = fRec68[1];
		fRec68[1] = fRec68[0];
		fRec67[2] = fRec67[1];
		fRec67[1] = fRec67[0];
		fRec66[2] = fRec66[1];
		fRec66[1] = fRec66[0];
		fRec62[1] = fRec62[0];
		iRec63[1] = iRec63[0];
		fRec64[1] = fRec64[0];
		fRec78[1] = fRec78[0];
		fRec86[1] = fRec86[0];
		fRec85[2] = fRec85[1];
		fRec85[1] = fRec85[0];
		fVec5[1] = fVec5[0];
		fRec84[1] = fRec84[0];
		fRec83[2] = fRec83[1];
		fRec83[1] = fRec83[0];
		fRec82[2] = fRec82[1];
		fRec82[1] = fRec82[0];
		fRec81[2] = fRec81[1];
		fRec81[1] = fRec81[0];
		fRec80[2] = fRec80[1];
		fRec80[1] = fRec80[0];
		fRec79[2] = fRec79[1];
		fRec79[1] = fRec79[0];
		fRec75[1] = fRec75[0];
		iRec76[1] = iRec76[0];
		fRec77[1] = fRec77[0];
		fRec90[1] = fRec90[0];
		fRec97[1] = fRec97[0];
		fRec96[2] = fRec96[1];
		fRec96[1] = fRec96[0];
		fVec6[1] = fVec6[0];
		fRec95[1] = fRec95[0];
		fRec94[2] = fRec94[1];
		fRec94[1] = fRec94[0];
		fRec93[2] = fRec93[1];
		fRec93[1] = fRec93[0];
		fRec92[2] = fRec92[1];
		fRec92[1] = fRec92[0];
		fRec91[2] = fRec91[1];
		fRec91[1] = fRec91[0];
		fRec87[1] = fRec87[0];
		iRec88[1] = iRec88[0];
		fRec89[1] = fRec89[0];
		fRec101[1] = fRec101[0];
		fRec107[1] = fRec107[0];
		fRec106[2] = fRec106[1];
		fRec106[1] = fRec106[0];
		fVec7[1] = fVec7[0];
		fRec105[1] = fRec105[0];
		fRec104[2] = fRec104[1];
		fRec104[1] = fRec104[0];
		fRec103[2] = fRec103[1];
		fRec103[1] = fRec103[0];
		fRec102[2] = fRec102[1];
		fRec102[1] = fRec102[0];
		fRec98[1] = fRec98[0];
		iRec99[1] = iRec99[0];
		fRec100[1] = fRec100[0];
		fRec111[1] = fRec111[0];
		fRec116[1] = fRec116[0];
		fRec115[2] = fRec115[1];
		fRec115[1] = fRec115[0];
		fVec8[1] = fVec8[0];
		fRec114[1] = fRec114[0];
		fRec113[2] = fRec113[1];
		fRec113[1] = fRec113[0];
		fRec112[2] = fRec112[1];
		fRec112[1] = fRec112[0];
		fRec108[1] = fRec108[0];
		iRec109[1] = iRec109[0];
		fRec110[1] = fRec110[0];
		fRec120[1] = fRec120[0];
		fRec124[1] = fRec124[0];
		fRec123[2] = fRec123[1];
		fRec123[1] = fRec123[0];
		fVec9[1] = fVec9[0];
		fRec122[1] = fRec122[0];
		fRec121[2] = fRec121[1];
		fRec121[1] = fRec121[0];
		fRec117[1] = fRec117[0];
		iRec118[1] = iRec118[0];
		fRec119[1] = fRec119[0];
		fRec128[1] = fRec128[0];
		fRec130[1] = fRec130[0];
		fRec129[2] = fRec129[1];
		fRec129[1] = fRec129[0];
		fRec125[1] = fRec125[0];
		iRec126[1] = iRec126[0];
		fRec127[1] = fRec127[0];
	}
	fVbargraph0 = (bypass? FAUSTFLOAT(20.*log10(_power0+anti_denormal)) : db_zero);
	fVbargraph1 = (bypass? FAUSTFLOAT(20.*log10(_power1+anti_denormal)) : db_zero);
	fVbargraph2 = (bypass? FAUSTFLOAT(20.*log10(_power2+anti_denormal)) : db_zero);
	fVbargraph3 = (bypass? FAUSTFLOAT(20.*log10(_power3+anti_denormal)) : db_zero);
	fVbargraph4 = (bypass? FAUSTFLOAT(20.*log10(_power4+anti_denormal)) : db_zero);
	fVbargraph5 = (bypass? FAUSTFLOAT(20.*log10(_power5+anti_denormal)) : db_zero);
	fVbargraph6 = (bypass? FAUSTFLOAT(20.*log10(_power6+anti_denormal)) : db_zero);
	fVbargraph7 = (bypass? FAUSTFLOAT(20.*log10(_power7+anti_denormal)) : db_zero);
	fVbargraph8 = (bypass? FAUSTFLOAT(20.*log10(_power8+anti_denormal)) : db_zero);
	fVbargraph9 = (bypass? FAUSTFLOAT(20.*log10(_power9+anti_denormal)) : db_zero);
	fVbargraph10 = (bypass? FAUSTFLOAT(20.*log10(_power10+anti_denormal)) : db_zero);

#undef bypass
#undef fVslider0
#undef fVslider1
#undef fVslider2
#undef fVbargraph0
#undef fVslider3
#undef fVbargraph1
#undef fVslider4
#undef fVbargraph2
#undef fVslider5
#undef fVbargraph3
#undef fVslider6
#undef fVbargraph4
#undef fVslider7
#undef fVbargraph5
#undef fVslider8
#undef fVbargraph6
#undef fVslider9
#undef fVbargraph7
#undef fVslider10
#undef fVbargraph8
#undef fVslider11
#undef fVbargraph9
#undef fVslider12
#undef fVbargraph10
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case BYPASS: 
		bypass_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case MORPH: 
		fVslider0_ = (float*)data; // , 1.0, 0.0, 1.0, 0.10000000000000001 
		break;
	case G10: 
		fVslider3_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G11: 
		fVslider1_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G1: 
		fVslider12_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G2: 
		fVslider11_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G3: 
		fVslider10_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G4: 
		fVslider9_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G5: 
		fVslider8_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G6: 
		fVslider7_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G7: 
		fVslider6_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G8: 
		fVslider5_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case G9: 
		fVslider4_ = (float*)data; // , 0.0, -30.0, 5.2000000000000002, 0.10000000000000001 
		break;
	case GAIN: 
		fVslider2_ = (float*)data; // , 0.0, -40.0, 40.0, 0.10000000000000001 
		break;
	case V10: 
		fVbargraph1_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V11: 
		fVbargraph0_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V1: 
		fVbargraph10_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V2: 
		fVbargraph9_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V3: 
		fVbargraph8_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V4: 
		fVbargraph7_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V5: 
		fVbargraph6_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V6: 
		fVbargraph5_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V7: 
		fVbargraph4_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V8: 
		fVbargraph3_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	case V9: 
		fVbargraph2_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   MORPH, 
   G10, 
   G11, 
   G1, 
   G2, 
   G3, 
   G4, 
   G5, 
   G6, 
   G7, 
   G8, 
   G9, 
   GAIN, 
   V10, 
   V11, 
   V1, 
   V2, 
   V3, 
   V4, 
   V5, 
   V6, 
   V7, 
   V8, 
   V9, 
} PortIndex;
*/

} // end namespace matcheq
