#include <map>

const std::map<int, string> TriggerBitMap_ = {
	{ 1 , "Nevt_Gen"},
	{ 2 , "Nevt_PassTrigger"},
	{ 3 , "Npairs"},
	{ 4 , "HLT_IsoMu27_v"},
	{ 5 , "HLT_IsoMu24_v"},
	{ 6 , "HLT_Ele32_WPTight_Gsf_v"},
	{ 7 , "HLT_Ele35_WPTight_Gsf_v"},
	{ 8 , "HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v"},
	{ 9 , "HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1_v"},
	{ 10 , "HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1_v"},
	{ 11 , "HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_v"},
	{ 12 , "HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1_v"},
	{ 13 , "HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1_v"},
	{ 14 , "HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_eta2p1_SingleL1_v"},
	{ 15 , "HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_eta2p1_SingleL1_v"},
	{ 16 , "HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_eta2p1_SingleL1_v"},
	{ 17 , "HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_eta2p1_TightID_SingleL1_v"},
	{ 18 , "HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_eta2p1_TightID_SingleL1_v"},
	{ 19 , "HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_eta2p1_TightID_SingleL1_v"},
	{ 20 , "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v"},
	{ 21 , "HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1_v"},
	{ 22 , "HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1_v"},
	{ 23 , "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1_v"},
	{ 24 , "HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1_v"},
	{ 25 , "HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1_v"},
	{ 26 , "HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg_v"},
	{ 27 , "HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v"},
	{ 28 , "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v"},
	{ 29 , "HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg_v"},
	{ 30 , "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg_v"},
	{ 31 , "HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v"},
	{ 32 , "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v"},
	{ 33 , "HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg_v"},
	{ 34 , "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v"},
	{ 35 , "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"},
	{ 36 , "HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"},
	{ 37 , "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v"},
	{ 38 , "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"},
	{ 39 , "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"},
	{ 40 , "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"},
	{ 41 , "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v"},
	{ 42 , "HLT_TripleMu_12_10_5_v"},
	{ 43 , "HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v"},
	{ 44 , "HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_v"},
	{ 45 , "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_v"},
	{ 46 , "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr_v"},
	{ 47 , "HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg_v"},
	{ 48 , "HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg_v"},
	{ 49 , "HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg_v"},
	{ 50 , "HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90_v"},
	{ 51 , "HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100_v"},
	{ 52 , "HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110_v"},
	{ 53 , "HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130_v"},	
};


bool pass_SingleEle_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( ((tbit>>1)&6) || ((tbit>>1)&7)) tbitmask = true;
  return tbitmask;
}

bool pass_SingleMu_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( ((tbit>>1)&4) || ((tbit>>1)&5)) tbitmask = true;
  return tbitmask;
}

bool pass_DoubleEle_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( ((tbit>>1)&39) || ((tbit>>1)&40)) tbitmask = true;
  return tbitmask;
}

bool pass_DoubleMu_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( ((tbit>>1)&37) || ((tbit>>1)&38)) tbitmask = true;
  return tbitmask;
}

bool pass_MuEle_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( ((tbit>>1)&34) || ((tbit>>1)&35) || ((tbit>>1)&36) ) tbitmask = true;
  return tbitmask;
}

bool pass_EleTau_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( (tbit>>1)&20) tbitmask = true;
  return tbitmask;
}

bool pass_MuTau_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( (tbit>>1)&8) tbitmask = true;
  return tbitmask;
}

bool pass_MuDiEle_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( (tbit>>1)&43) tbitmask = true;
  return tbitmask;
}

bool pass_DiMuEle_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( (tbit>>1)&44) tbitmask = true;
  return tbitmask;
}

bool pass_TripleEle_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( (tbit>>1)&41) tbitmask = true;
  return tbitmask;
}

bool pass_TripleMu_trigger(Long64_t tbit){
  bool tbitmask = false;
  if( (tbit>>1)&42) tbitmask = true;
  return tbitmask;
}

bool pass_1l2tau_trigger(Long64_t tbit){
	bool tbitmask = false;
	if ( pass_SingleEle_trigger(tbit) || pass_SingleMu_trigger(tbit) || pass_EleTau_trigger(tbit) || pass_MuTau_trigger(tbit) ) tbitmask = true;
	return tbitmask;
}

bool pass_2lSS1tau_trigger(Long64_t tbit){
	bool tbitmask = false;
	if ( pass_SingleEle_trigger(tbit) || pass_SingleMu_trigger(tbit) || pass_DoubleEle_trigger(tbit) || pass_MuEle_trigger(tbit) || pass_DoubleMu_trigger(tbit) ) tbitmask = true;
	return tbitmask;
}

bool pass_3l1tau_trigger(Long64_t tbit){
	bool tbitmask = false;
	if ( pass_SingleEle_trigger(tbit) || pass_SingleMu_trigger(tbit) || pass_DoubleEle_trigger(tbit) 
		|| pass_MuEle_trigger(tbit) || pass_DoubleMu_trigger(tbit) || pass_TripleEle_trigger(tbit) 
		|| pass_TripleMu_trigger(tbit) || pass_MuDiEle_trigger(tbit) || pass_DiMuEle_trigger(tbit) ) tbitmask = true;
	return tbitmask;
}
