const std::map<std::string, std::string> SFHelper::PUSampleNameMap_ = {
	{"DYJets_M10to50","DYJetsToLL_M-10to50"},
	{"DYJets_M50","DYJetsToLL_M-50"},
	{"DYJets_M50_ext","DYJetsToLL_M-50_ext1"},
	{"ggHZZ4l","GluGluHToZZTo4L"},
	{"ST_sLep","ST_s-channel_4f_leptonDecays"},
	{"ST_sLep_psw","ST_s-channel_4f_leptonDecays"}, // FIXME
	{"ST_tTbar","ST_t-channel_antitop_4f_inclusiveDecays"},
	{"ST_tT","ST_t-channel_top_4f_inclusiveDecays"},
	{"ST_tWTbar","ST_tW_antitop_5f_inclusiveDecays"},
	{"ST_tWT","ST_tW_top_5f_inclusiveDecays"},
	{"ST_tWll","ST_tWll"},
	{"tHq","THQ"},
	{"tHW","THW"},
	{"TTGJets","TTGJets"},
	{"ttHJetTobb","ttHJetTobb_M125_amcatnlo"},
	{"ttHJetToNonbb","ttHJetToNonbb_M125_amcatnlo"},
	{"ttHToNonbb","ttHToNonbb_M125_powheg"},
	{"TTToDiLep","TTTo2L2Nu"},
	{"TTToDiLep_psw","TTTo2L2Nu_PSweights"},
	{"TTToHad","TTToHadronic"},
	{"TTToHad_psw","TTToHadronic_PSweights"},
	{"TTToSemiLep","TTToSemiLeptonic"},
	{"TTToSemiLep_psw","TTToSemiLeptonic_PSweights"},
	{"TTTT","TTTT"},
	{"TTW","TTWJetsToLNu"},
	{"TTW_psw","TTWJetsToLNu_PSweights"},
	{"TTWW","TTWW"},
	{"TTZ_M1to10","TTZToLL_M-1to10"},
	{"TTZ","TTZToLL_M10"},
	{"tZq","tZq_ll_4f"},
	{"VHToNonbb","VHToNonbb_M125"},
	{"WJets","WJetsToLNu"},
	{"WpWpJJ","WpWpJJ_EWK_QCD"},
	{"WW","WWTo2L2Nu"},
	{"WWds","WWTo2L2Nu_DoubleScattering"}, // FIXME
	{"WWTo2L2Nuds","WWTo2L2Nu_DoubleScattering"},
	{"WWW","WWW_4F"},
	{"WWZ","WWZ_4F"},
	{"WZ","WZTo3LNu"}, // FIXME
	{"WZTo3LNu","WZTo3LNu"},
	{"WZZ","WZZ"},
	{"ZZ","ZZTo4L"},
	{"ZZ_ext","ZZTo4L_ext1"},
	{"ZZZ","ZZZ"}
}; 


void set_up_PUWeights(const std::string& samplename)
{
    std::string fname_pu_data = std::string("PUreweight/PileupData_ReRecoJSON_Full2017.root";
    std::string fname_pu_mc = std::string("PUreweight/pileup_2017.root";

	if (not PUSampleNameMap_.count(samplename)) {
		std::cerr << "sample name : " << samplename << " not exsit in the PU name map"
				  << std::endl;
		assert(0);
	}
	
	LumiWeights_ = edm::LumiReWeighting(fname_pu_mc, fname_pu_data,
										PUSampleNameMap_.at(samplename), "pileup");
}

float get_PUweight(int nPU)
{
	/*
 * 	assert(not _isdata);
 * 		
 * 			int xbin = h_puweight->FindBin(nPU);
 * 				return h_puweight->GetBinContent(xbin);
 * 					*/
	return LumiWeights_.weight(nPU);
}
