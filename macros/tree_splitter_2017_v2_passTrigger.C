#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile.h>


#include <iostream>
#include <TLegend.h>
#include <TBranch.h>
#include <TClonesArray.h>
#include <TChain.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <TVector3.h>

#include "leptonSF.cc"

using namespace std;

/*
vector<TString> triggerlist;
vector<TString> triggerlist_1e;
vector<TString> triggerlist_1mu;
vector<TString> triggerlist_2e;
vector<TString> triggerlist_2m;
vector<TString> triggerlist_em;
vector<TString> triggerlist_etau;
vector<TString> triggerlist_mtau;

triggerlist.clear();
triggerlist_1e.clear();
triggerlist_1mu.clear();
triggerlist_2e.clear();
triggerlist_2m.clear();
triggerlist_em.clear();
triggerlist_etau.clear();
triggerlist_mtau.clear();

triggerlist_1e.push_back("HLT_Ele32_WPTight_Gsf_v");
triggerlist_1e.push_back("HLT_Ele35_WPTight_Gsf_v");

triggerlist_1mu.push_back("HLT_IsoMu24_v");
triggerlist_1mu.push_back("HLT_IsoMu27_v");

triggerlist_2e.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
triggerlist_2e.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");

triggerlist_2m.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
triggerlist_2m.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");

triggerlist_em.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v");
triggerlist_em.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
triggerlist_em.push_back("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");

triggerlist_etau.push_back("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v");

triggerlist_mtau.push_back("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v");
*/

/*void print_triggers(){

  cout<<endl;
  cout<<"Triggers 1e"<<endl;
  for(unsigned int j=0;j<triggerlist_1e.size();j++)	
    cout<<triggerlist_1e[j]<<endl;

  cout<<"Triggers 1m"<<endl;
  for(unsigned int j=0;j<triggerlist_1mu.size();j++)	
    cout<<triggerlist_1mu[j]<<endl;

  cout<<"Triggers 2e"<<endl;
  for(unsigned int j=0;j<triggerlist_2e.size();j++)	
    cout<<triggerlist_2e[j]<<endl;

  cout<<"Triggers 2m"<<endl;
  for(unsigned int j=0;j<triggerlist_2m.size();j++)	
    cout<<triggerlist_2m[j]<<endl;

  cout<<"Triggers em"<<endl;
  for(unsigned int j=0;j<triggerlist_em.size();j++)	
    cout<<triggerlist_em[j]<<endl;

  cout<<"Triggers etau"<<endl;
  for(unsigned int j=0;j<triggerlist_etau.size();j++)	
    cout<<triggerlist_etau[j]<<endl;

  cout<<"Triggers mtau"<<endl;
  for(unsigned int j=0;j<triggerlist_mtau.size();j++)  
    cout<<triggerlist_mtau[j]<<endl;

}

void produce_triggerlist(TString sample, TH1F* hCounter){

  triggerlist.clear();
  triggerlist_1e.clear();
  triggerlist_1mu.clear();
  triggerlist_2e.clear();
  triggerlist_2m.clear();
  triggerlist_em.clear();
  triggerlist_etau.clear();
  triggerlist_mtau.clear();


  for(int itr=1;itr<=hCounter->GetNbinsX();itr++){
    TString binlabel = hCounter->GetXaxis()->GetBinLabel(itr);
    if(binlabel.BeginsWith("HLT"))triggerlist.push_back(hCounter->GetXaxis()->GetBinLabel(itr));
  }


  triggerlist_1e.push_back("HLT_Ele32_WPTight_Gsf_v");
  triggerlist_1e.push_back("HLT_Ele35_WPTight_Gsf_v");

  triggerlist_1mu.push_back("HLT_IsoMu24_v");
  triggerlist_1mu.push_back("HLT_IsoMu27_v");

  triggerlist_2e.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  triggerlist_2e.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");

  triggerlist_2m.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
  triggerlist_2m.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");

  triggerlist_em.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  triggerlist_em.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
  triggerlist_em.push_back("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");

  triggerlist_etau.push_back("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v");

  triggerlist_mtau.push_back("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v");

  print_triggers();
  return;

}

*/

/*
1 Nevt_Gen
2 Nevt_PassTrigger
3 Npairs
4 HLT_IsoMu27_v
5 HLT_IsoMu24_v
6 HLT_Ele32_WPTight_Gsf_v
7 HLT_Ele35_WPTight_Gsf_v
8 HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v
9 HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1_v
10 HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1_v
11 HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_v
12 HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1_v
13 HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1_v
14 HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_eta2p1_SingleL1_v
15 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_eta2p1_SingleL1_v
16 HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_eta2p1_SingleL1_v
17 HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_eta2p1_TightID_SingleL1_v
18 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_eta2p1_TightID_SingleL1_v
19 HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_eta2p1_TightID_SingleL1_v
20 HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v
21 HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1_v
22 HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1_v
23 HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1_v
24 HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1_v
25 HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1_v
26 HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg_v
27 HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v
28 HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v
29 HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg_v
30 HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg_v
31 HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v
32 HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v
33 HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg_v
34 HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v
35 HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v
36 HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v
37 HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v
38 HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v
39 HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v
40 HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v
41 HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v
42 HLT_TripleMu_12_10_5_v
43 HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v
44 HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_v
45 HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_v
46 HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr_v
47 HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg_v
48 HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg_v
49 HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg_v
50 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90_v
51 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100_v
52 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110_v
53 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130_v
*/

bool pass_1e_trigger(Long64_t tbit){
  bool tbitmask;
  if( (tbit>>1)&6 ) tbitmask = true;
  else tbitmask = false;
  return tbitmask;
}

bool pass_1m_trigger(Long64_t tbit){
  bool tbitmask;
  if( (tbit>>1)&4 ) tbitmask = true;
  else tbitmask = false;
  return tbitmask;
}

bool pass_2e_trigger(Long64_t tbit){
  bool tbitmask;
  if( (tbit>>1)&39 ) tbitmask = true;
  else tbitmask = false;
  return tbitmask;
}



void split_tree(TString filename_in, TString filename_out,
		int i_split1=0, int i_split2=0,
		bool isMC=true, bool isReHLT=true){

  vector<TString> triggerlist;
  vector<TString> triggerlist_1e;
  vector<TString> triggerlist_1mu;
  vector<TString> triggerlist_2e;
  vector<TString> triggerlist_2m;
  vector<TString> triggerlist_em;
  vector<TString> triggerlist_etau;
  vector<TString> triggerlist_mtau;

  triggerlist.clear();
  triggerlist_1e.clear();
  triggerlist_1mu.clear();
  triggerlist_2e.clear();
  triggerlist_2m.clear();
  triggerlist_em.clear();
  triggerlist_etau.clear();
  triggerlist_mtau.clear();

  triggerlist_1e.push_back("HLT_Ele32_WPTight_Gsf_v");
  triggerlist_1e.push_back("HLT_Ele35_WPTight_Gsf_v");
  triggerlist_1mu.push_back("HLT_IsoMu24_v");
  triggerlist_1mu.push_back("HLT_IsoMu27_v");
  triggerlist_2e.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  triggerlist_2e.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
  triggerlist_2m.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
  triggerlist_2m.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");
  triggerlist_em.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  triggerlist_em.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
  triggerlist_em.push_back("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");
  triggerlist_etau.push_back("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v");
  triggerlist_mtau.push_back("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v");

  vector<TString> list;
  list.push_back(filename_in);

  //produce_triggerlist(filename_in);

  TChain * tree = new TChain("HTauTauTree");
  int nFiles = list.size();

  for(int i=0;i<nFiles;i++)
    {
      tree->Add(list[i]);
    }

  TH1F* h=new TH1F("h_counter","h_counter",3,0,3);


  //Old branches used
  Long64_t _triggerbit; 
  int _metfilterbit;
 
  int _n_recolep_mvasel;
  int _n_recolep_fakeable;
  int _n_recolep_presel;

  vector<int> *_recolep_charge;
  vector<int> *_recolep_pdg;
  vector<float> *_recolep_e;
  vector<float> *_recolep_px;
  vector<float> *_recolep_py;
  vector<float> *_recolep_pz;
  vector<float> *_recolep_pt;
  vector<float> *_recolep_conept;
  vector<float> *_recolep_eta;
  vector<float> *_recolep_phi;
  vector<float> *_recolep_fakerate;
  vector<float> *_recolep_fakerate_QCD_MC;
  vector<float> *_recolep_fakerate_ttbar_MC;
  vector<float> *_recolep_QFrate; 
  vector<bool> *_recolep_ismvasel;
  vector<bool> *_recolep_tightcharge;
  vector<bool> *_recolep_isGenMatched;
  vector<int> *_recolep_genMatchInd;

  vector<float> *_recomu_e;
  vector<float> *_recomu_px;
  vector<float> *_recomu_py;
  vector<float> *_recomu_pz;

  vector<float> *_recoele_e;
  vector<float> *_recoele_px;
  vector<float> *_recoele_py;
  vector<float> *_recoele_pz;

  float _ETmissLD;
  int _n_recoPFJet;
  int _n_recoPFJet_btag_medium;
  int _n_recoPFJet_btag_loose;

  int _n_recotauh;
  vector<int> *_recotauh_charge;
  vector<int> *_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017;
  vector<int> *_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017;
  vector<int> *_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017;
  vector<int> *_recotauh_againstMuonLoose3;
  vector<int> *_recotauh_againstMuonTight3;
  vector<int> *_recotauh_againstElectronVLooseMVA6;
  vector<int> *_recotauh_againstElectronLooseMVA6;
  vector<int> *_recotauh_againstElectronMediumMVA6;
  vector<int> *_recotauh_againstElectronTightMVA6;
  vector<int> *_recotauh_againstElectronVTightMVA6;
  vector<int> *_recotauh_decayMode;
  vector<float> *_recotauh_e;
  vector<float> *_recotauh_px;
  vector<float> *_recotauh_py;
  vector<float> *_recotauh_pz;
  vector<bool> *_recotauh_isGenMatched;
  vector<int> *_recotauh_genMatchInd;
  vector<float> *_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT;
  vector<float> *_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT;

  tree->SetBranchAddress("triggerbit",&_triggerbit);
  tree->SetBranchAddress("metfilterbit",&_metfilterbit);

  tree->SetBranchAddress("n_recolep_mvasel",&_n_recolep_mvasel);
  tree->SetBranchAddress("n_recolep_fakeable",&_n_recolep_fakeable);
  tree->SetBranchAddress("n_recolep_presel",&_n_recolep_presel);

  tree->SetBranchAddress("recolep_charge",&_recolep_charge);
  tree->SetBranchAddress("recolep_pdg",&_recolep_pdg);
  tree->SetBranchAddress("recolep_e",&_recolep_e);
  tree->SetBranchAddress("recolep_px",&_recolep_px);
  tree->SetBranchAddress("recolep_py",&_recolep_py);
  tree->SetBranchAddress("recolep_pz",&_recolep_pz);
  tree->SetBranchAddress("recolep_pt",&_recolep_pt);
  tree->SetBranchAddress("recolep_conept",&_recolep_conept);
  tree->SetBranchAddress("recolep_eta",&_recolep_eta);
  tree->SetBranchAddress("recolep_phi",&_recolep_phi);
  tree->SetBranchAddress("recolep_fakerate",&_recolep_fakerate);
  tree->SetBranchAddress("recolep_fakerate_QCD_MC",&_recolep_fakerate_QCD_MC);
  tree->SetBranchAddress("recolep_fakerate_ttbar_MC",&_recolep_fakerate_ttbar_MC);
  tree->SetBranchAddress("recolep_QFrate",&_recolep_QFrate);
  tree->SetBranchAddress("recolep_ismvasel",&_recolep_ismvasel);
  tree->SetBranchAddress("recolep_tightcharge",&_recolep_tightcharge);
  tree->SetBranchAddress("recolep_isGenMatched",&_recolep_isGenMatched);
  tree->SetBranchAddress("recolep_genMatchInd",&_recolep_genMatchInd);

  tree->SetBranchAddress("recomu_e",&_recomu_e);
  tree->SetBranchAddress("recomu_px",&_recomu_px);
  tree->SetBranchAddress("recomu_py",&_recomu_py);
  tree->SetBranchAddress("recomu_pz",&_recomu_pz);

  tree->SetBranchAddress("recoele_e",&_recoele_e);
  tree->SetBranchAddress("recoele_px",&_recoele_px);
  tree->SetBranchAddress("recoele_py",&_recoele_py);
  tree->SetBranchAddress("recoele_pz",&_recoele_pz);

  tree->SetBranchAddress("ETmissLD",&_ETmissLD);
  tree->SetBranchAddress("n_recoPFJet",&_n_recoPFJet);
  tree->SetBranchAddress("n_recoPFJet_btag_medium",&_n_recoPFJet_btag_medium);
  tree->SetBranchAddress("n_recoPFJet_btag_loose",&_n_recoPFJet_btag_loose);

  tree->SetBranchAddress("n_recotauh",&_n_recotauh);
  tree->SetBranchAddress("recotauh_charge",&_recotauh_charge);
  tree->SetBranchAddress("recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017",&_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017);
  tree->SetBranchAddress("recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017",&_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017);
  tree->SetBranchAddress("recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017",&_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017);
  tree->SetBranchAddress("recotauh_againstMuonLoose3",&_recotauh_againstMuonLoose3);
  tree->SetBranchAddress("recotauh_againstMuonTight3",&_recotauh_againstMuonTight3);
  tree->SetBranchAddress("recotauh_againstElectronVLooseMVA6",&_recotauh_againstElectronVLooseMVA6);
  tree->SetBranchAddress("recotauh_againstElectronLooseMVA6",&_recotauh_againstElectronLooseMVA6);
  tree->SetBranchAddress("recotauh_againstElectronMediumMVA6",&_recotauh_againstElectronMediumMVA6);
  tree->SetBranchAddress("recotauh_againstElectronTightMVA6",&_recotauh_againstElectronTightMVA6);
  tree->SetBranchAddress("recotauh_againstElectronVTightMVA6",&_recotauh_againstElectronVTightMVA6);
  tree->SetBranchAddress("recotauh_decayMode",&_recotauh_decayMode);
  tree->SetBranchAddress("recotauh_e",&_recotauh_e);
  tree->SetBranchAddress("recotauh_px",&_recotauh_px);
  tree->SetBranchAddress("recotauh_py",&_recotauh_py);
  tree->SetBranchAddress("recotauh_pz",&_recotauh_pz);
  tree->SetBranchAddress("recotauh_isGenMatched",&_recotauh_isGenMatched);
  tree->SetBranchAddress("recotauh_genMatchInd",&_recotauh_genMatchInd);
  tree->SetBranchAddress("recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT);
  tree->SetBranchAddress("recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT);
  
  Long64_t nentries = tree->GetEntries();

  //TFile* f_new = TFile::Open(dir_out+file);
  TFile* f_new = TFile::Open(filename_out);
  if(f_new!=0){
    cout<<filename_out<<" already exists, please delete it before converting again"<<endl;
    return;
  }
  
  f_new = TFile::Open(filename_out,"RECREATE");

  TTree* tree_2l=tree->GetTree()->CloneTree(0);
  tree_2l->SetNameTitle("HTauTauTree_2l","HTauTauTree_2l");
  TTree* tree_2lSS=tree->GetTree()->CloneTree(0);
  tree_2lSS->SetNameTitle("HTauTauTree_2lSS","HTauTauTree_2lSS");
  TTree* tree_2lOS_CR=tree->GetTree()->CloneTree(0);
  tree_2lOS_CR->SetNameTitle("HTauTauTree_2lOS_CR","HTauTauTree_2lOS_CR");
  TTree* tree_2lSS_lepMVA_CR=tree->GetTree()->CloneTree(0);
  tree_2lSS_lepMVA_CR->SetNameTitle("HTauTauTree_2lSS_lepMVA_CR","HTauTauTree_2lSS_lepMVA_CR");
  TTree* tree_2lSS_jetmult_CR=tree->GetTree()->CloneTree(0);
  tree_2lSS_jetmult_CR->SetNameTitle("HTauTauTree_2lSS_jetmult_CR","HTauTauTree_2lSS_jetmult_CR");
  TTree* tree_2lSS_ttbarOF_CR=tree->GetTree()->CloneTree(0);
  tree_2lSS_ttbarOF_CR->SetNameTitle("HTauTauTree_2lSS_ttbarOF_CR","HTauTauTree_2lSS_ttbarOF_CR");
  TTree* tree_2lSS_2jet_CR=tree->GetTree()->CloneTree(0);
  tree_2lSS_2jet_CR->SetNameTitle("HTauTauTree_2lSS_2jet_CR","HTauTauTree_2lSS_2jet_CR");

  TTree* tree_3l=tree->GetTree()->CloneTree(0);
  tree_3l->SetNameTitle("HTauTauTree_3l","HTauTauTree_3l");
  TTree* tree_3l_lepMVA_CR=tree->GetTree()->CloneTree(0);
  tree_3l_lepMVA_CR->SetNameTitle("HTauTauTree_3l_lepMVA_CR","HTauTauTree_3l_lepMVA_CR");
  TTree* tree_3l_WZ_CR=tree->GetTree()->CloneTree(0);
  tree_3l_WZ_CR->SetNameTitle("HTauTauTree_3l_WZ_CR","HTauTauTree_3l_WZ_CR");
  TTree* tree_3l_ttZ_CR=tree->GetTree()->CloneTree(0);
  tree_3l_ttZ_CR->SetNameTitle("HTauTauTree_3l_ttZ_CR","HTauTauTree_3l_ttZ_CR");
  TTree* tree_3l_ttZ_lepMVA_CR=tree->GetTree()->CloneTree(0);
  tree_3l_ttZ_lepMVA_CR->SetNameTitle("HTauTauTree_3l_ttZ_lepMVA_CR","HTauTauTree_3l_ttZ_lepMVA_CR");

  TTree* tree_1l_2tau=tree->GetTree()->CloneTree(0);
  tree_1l_2tau->SetNameTitle("HTauTauTree_1l_2tau","HTauTauTree_1l_2tau");
  TTree* tree_1l_2tau_fake_CR=tree->GetTree()->CloneTree(0);
  tree_1l_2tau_fake_CR->SetNameTitle("HTauTauTree_1l_2tau_fake_CR","HTauTauTree_1l_2tau_fake_CR");
  TTree* tree_1l_2tau_2jet_CR=tree->GetTree()->CloneTree(0);
  tree_1l_2tau_2jet_CR->SetNameTitle("HTauTauTree_1l_2tau_2jet_CR","HTauTauTree_1l_2tau_2jet_CR");

  vector<TTree*> tree_new;
  tree_new.push_back(tree_2lSS);
  tree_new.push_back(tree_2lOS_CR);
  tree_new.push_back(tree_2lSS_lepMVA_CR);
  tree_new.push_back(tree_2lSS_jetmult_CR);
  tree_new.push_back(tree_2lSS_ttbarOF_CR);
  tree_new.push_back(tree_2lSS_2jet_CR);

 
  tree_new.push_back(tree_3l);
  tree_new.push_back(tree_3l_lepMVA_CR);
  tree_new.push_back(tree_3l_WZ_CR);
  tree_new.push_back(tree_3l_ttZ_CR);
  tree_new.push_back(tree_3l_ttZ_lepMVA_CR);

  tree_new.push_back(tree_1l_2tau);
  tree_new.push_back(tree_1l_2tau_fake_CR);
  tree_new.push_back(tree_1l_2tau_2jet_CR);



  //New branches

  bool _isTrig_1e;
  bool _isTrig_1m;
  bool _isTrig_2e;
  bool _isTrig_2m;
  bool _isTrig_em;
  bool _isTrig_etau;
  bool _isTrig_mtau;

  int _category;

  /*
    1: mumu+, btight
    2: mumu-, btight
    3: mumu+, bloose
    4: mumu-, bloose
    5: emu+, btight
    6: emu-, btight
    7: emu+, bloose
    8: emu-, bloose
    9: ee+
    10: ee-
    11: 2lSS + tauh
    12: 3l+, btight
    13: 3l-, btight
    14: 3l+, bloose
    15: 3l-, bloose
    16: 3l + tauh
    20: 1l + 2tauh
    

    -1: mumu OS, btight
    -3: mumu OS, bloose
    -5: emu OS, mu+ btight
    -6: emu OS, mu-  btight
    -7: emu OS, mu+ bloose
    -8: emu OS, mu- bloose
    -9: ee OS, lead. e+
    -10: ee OS, lead. e-
    -11: 2lOS + tauh

    31: mumu+, btight, lepMVA CR
    32: mumu-, btight, lepMVA CR
    33: mumu+, bloose, lepMVA CR
    34: mumu-, bloose, lepMVA CR
    35: emu+, btight, lepMVA CR
    36: emu-, btight, lepMVA CR
    37: emu+, bloose, lepMVA CR
    38: emu-, bloose, lepMVA CR
    39: ee+, lepMVA CR
    40: ee-, lepMVA CR
    41: 2lSS + tauh, lepMVA + tau CR
    42: 3l+, btight, lepMVA CR
    43: 3l-, btight, lepMVA CR
    44: 3l+, bloose, lepMVA CR
    45: 3l-, bloose, lepMVA CR
    46: 3l- + tauh, lepMVA + tau CR
    50: 1l + 2tauh, lepMVA + tau CR

   */

  vector<int> _recolep_sel_charge;
  vector<int> _recolep_sel_pdg;
  vector<float> _recolep_sel_e;
  vector<float> _recolep_sel_px;
  vector<float> _recolep_sel_py;
  vector<float> _recolep_sel_pz;
  vector<float> _recolep_sel_pt;
  vector<float> _recolep_sel_conept;
  vector<float> _recolep_sel_eta;
  vector<float> _recolep_sel_phi;
  vector<float> _recolep_sel_fakerate;
  vector<float> _recolep_sel_fakerate_QCD_MC;
  vector<float> _recolep_sel_fakerate_ttbar_MC;
  vector<float> _recolep_sel_QFrate; 
  vector<bool>  _recolep_sel_ismvasel;
  vector<bool>  _recolep_sel_tightcharge;
  vector<bool>  _recolep_sel_isGenMatched;
  vector<int>  _recolep_sel_genMatchInd;

  vector<int> _recotauh_sel_charge;
  vector<int> _recotauh_sel_decayMode;
  vector<float> _recotauh_sel_e;
  vector<float> _recotauh_sel_px;
  vector<float> _recotauh_sel_py;
  vector<float> _recotauh_sel_pz;
  vector<float> _recotauh_sel_pt;
  vector<float> _recotauh_sel_eta;
  vector<float> _recotauh_sel_phi;
  vector<int> _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT;
  vector<int> _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT;
  vector<int> _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT;
  vector<int> _recotauh_sel_againstMuonLoose3;
  vector<int> _recotauh_sel_againstMuonTight3;
  vector<int> _recotauh_sel_againstElectronVLooseMVA6;
  vector<int> _recotauh_sel_againstElectronLooseMVA6;
  vector<int> _recotauh_sel_againstElectronMediumMVA6;
  vector<int> _recotauh_sel_againstElectronTightMVA6;
  vector<int> _recotauh_sel_againstElectronVTightMVA6;
  vector<bool> _recotauh_sel_isGenMatched;
  vector<int> _recotauh_sel_genMatchInd;
  vector<float> _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT;
  vector<float> _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT;

  int _n_fake_lep;
  int _n_fake_tau;

  float _event_weight_ttH;
  float _event_weight_ttH_FR_QCD_MC;
  float _event_weight_ttH_FR_TT_MC;
  float _event_weight_ttH_ele_FR_QCD_MC;
  float _event_weight_ttH_ele_FR_TT_MC;
  float _event_weight_ttH_mu_FR_QCD_MC;
  float _event_weight_ttH_mu_FR_TT_MC;


  float _triggerSF_weight;
  float _triggerSF_weight_up;
  float _triggerSF_weight_down;

  float _leptonSF_ttH_weight;
  float _tauSF_weight;

  bool _isGenMatched;


  for(unsigned int i=0; i<tree_new.size();i++){
    
    tree_new[i]->Branch("_isTrig_1e",&_isTrig_1e,"_isTrig_1e/O");
    tree_new[i]->Branch("_isTrig_1m",&_isTrig_1m,"_isTrig_1m/O");
    tree_new[i]->Branch("_isTrig_2e",&_isTrig_2e,"_isTrig_2e/O");
    tree_new[i]->Branch("_isTrig_2m",&_isTrig_2m,"_isTrig_2m/O");
    tree_new[i]->Branch("_isTrig_em",&_isTrig_em,"_isTrig_em/O");
    tree_new[i]->Branch("_isTrig_etau",&_isTrig_etau,"_isTrig_etau/O");
    tree_new[i]->Branch("_isTrig_mtau",&_isTrig_mtau,"_isTrig_mtau/O"); 
    
    tree_new[i]->Branch("category",&_category,"category/I");
    
    tree_new[i]->Branch("recolep_sel_charge",&_recolep_sel_charge);
    tree_new[i]->Branch("recolep_sel_pdg",&_recolep_sel_pdg);
    tree_new[i]->Branch("recolep_sel_e",&_recolep_sel_e);
    tree_new[i]->Branch("recolep_sel_px",&_recolep_sel_px);
    tree_new[i]->Branch("recolep_sel_py",&_recolep_sel_py);
    tree_new[i]->Branch("recolep_sel_pz",&_recolep_sel_pz);
    tree_new[i]->Branch("recolep_sel_pt",&_recolep_sel_pt);
    tree_new[i]->Branch("recolep_sel_conept",&_recolep_sel_conept);
    tree_new[i]->Branch("recolep_sel_eta",&_recolep_sel_eta);
    tree_new[i]->Branch("recolep_sel_phi",&_recolep_sel_phi);
    tree_new[i]->Branch("recolep_sel_fakerate",&_recolep_sel_fakerate);
    tree_new[i]->Branch("recolep_sel_fakerate_QCD_MC",&_recolep_sel_fakerate_QCD_MC);
    tree_new[i]->Branch("recolep_sel_fakerate_ttbar_MC",&_recolep_sel_fakerate_ttbar_MC);
    tree_new[i]->Branch("recolep_sel_QFrate",&_recolep_sel_QFrate);
    tree_new[i]->Branch("recolep_sel_ismvasel",&_recolep_sel_ismvasel);
    tree_new[i]->Branch("recolep_sel_tightcharge",&_recolep_sel_tightcharge);
    tree_new[i]->Branch("recolep_sel_isGenMatched",&_recolep_sel_isGenMatched);
    tree_new[i]->Branch("recolep_sel_genMatchInd",&_recolep_sel_genMatchInd);

    tree_new[i]->Branch("recotauh_sel_charge",&_recotauh_sel_charge);
    tree_new[i]->Branch("recotauh_sel_decayMode",&_recotauh_sel_decayMode);
    tree_new[i]->Branch("recotauh_sel_e",&_recotauh_sel_e);
    tree_new[i]->Branch("recotauh_sel_px",&_recotauh_sel_px);
    tree_new[i]->Branch("recotauh_sel_py",&_recotauh_sel_py);
    tree_new[i]->Branch("recotauh_sel_pz",&_recotauh_sel_pz);
    tree_new[i]->Branch("recotauh_sel_pt",&_recotauh_sel_pt);
    tree_new[i]->Branch("recotauh_sel_eta",&_recotauh_sel_eta);
    tree_new[i]->Branch("recotauh_sel_phi",&_recotauh_sel_phi);
    tree_new[i]->Branch("recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT);
    tree_new[i]->Branch("recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT);
    tree_new[i]->Branch("recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT);
    tree_new[i]->Branch("recotauh_sel_againstMuonLoose3",&_recotauh_sel_againstMuonLoose3);
    tree_new[i]->Branch("recotauh_sel_againstMuonTight3",&_recotauh_sel_againstMuonTight3);
    tree_new[i]->Branch("recotauh_sel_againstElectronVLooseMVA6",&_recotauh_sel_againstElectronVLooseMVA6);
    tree_new[i]->Branch("recotauh_sel_againstElectronLooseMVA6",&_recotauh_sel_againstElectronLooseMVA6);
    tree_new[i]->Branch("recotauh_sel_againstElectronMediumMVA6",&_recotauh_sel_againstElectronMediumMVA6);
    tree_new[i]->Branch("recotauh_sel_againstElectronTightMVA6",&_recotauh_sel_againstElectronTightMVA6);
    tree_new[i]->Branch("recotauh_sel_againstElectronVTightMVA6",&_recotauh_sel_againstElectronVTightMVA6);
    tree_new[i]->Branch("recotauh_sel_isGenMatched",&_recotauh_sel_isGenMatched);
    tree_new[i]->Branch("recotauh_sel_genMatchInd",&_recotauh_sel_genMatchInd);

    tree_new[i]->Branch("recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT);
    tree_new[i]->Branch("recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT);

    tree_new[i]->Branch("n_fake_lep",&_n_fake_lep,"n_fake_lep/I");
    tree_new[i]->Branch("n_fake_tau",&_n_fake_tau,"n_fake_tau/I");

    tree_new[i]->Branch("event_weight_ttH",&_event_weight_ttH,"event_weight_ttH/F");
    tree_new[i]->Branch("event_weight_ttH_FR_QCD_MC",&_event_weight_ttH_FR_QCD_MC,"event_weight_ttH_FR_QCD_MC/F");
    tree_new[i]->Branch("event_weight_ttH_FR_TT_MC",&_event_weight_ttH_FR_TT_MC,"event_weight_ttH_FR_TT_MC/F");
    tree_new[i]->Branch("event_weight_ttH_ele_FR_QCD_MC",&_event_weight_ttH_ele_FR_QCD_MC,"event_weight_ttH_ele_FR_QCD_MC/F");
    tree_new[i]->Branch("event_weight_ttH_ele_FR_TT_MC",&_event_weight_ttH_ele_FR_TT_MC,"event_weight_ttH_ele_FR_TT_MC/F");
    tree_new[i]->Branch("event_weight_ttH_mu_FR_QCD_MC",&_event_weight_ttH_mu_FR_QCD_MC,"event_weight_ttH_mu_FR_QCD_MC/F");
    tree_new[i]->Branch("event_weight_ttH_mu_FR_TT_MC",&_event_weight_ttH_mu_FR_TT_MC,"event_weight_ttH_mu_FR_TT_MC/F");

    tree_new[i]->Branch("triggerSF_weight",&_triggerSF_weight,"triggerSF_weight/F");
    tree_new[i]->Branch("triggerSF_weight_up",&_triggerSF_weight_up,"triggerSF_weight_up/F");
    tree_new[i]->Branch("triggerSF_weight_down",&_triggerSF_weight_down,"triggerSF_weight_down/F");
    tree_new[i]->Branch("leptonSF_ttH_weight",&_leptonSF_ttH_weight,"leptonSF_ttH_weight/F");
    tree_new[i]->Branch("tauSF_weight",&_tauSF_weight,"tauSF_weight/F");

    tree_new[i]->Branch("isGenMatched",&_isGenMatched,"isGenMatched/O");

  }



  cout<<"nentries="<<nentries<<endl;

  int skip_entries=0;
  if(i_split1>0){
    skip_entries = nentries/i_split1 * i_split2;
    nentries = nentries/i_split1 * (i_split2+1);
  }


  //skip_entries=44583;
  nentries = 100;

  for (int i=skip_entries;i<skip_entries+nentries;i++) {

    h->Fill(1);
    
    cout<<"event " << i << ", triggerbit" << _triggerbit << endl;
    bool passSingleMu = pass_single_m_trigger(_triggerbit);
    bool passSingleEle = pass_single_e_trigger(_triggerbit);
    cout << "pass_single_m_trigger " << passSingleMu << endl;
    cout << "pass_single_e_trigger " << passSingleEle << endl;

    if(i%1000==0) 
      cout<<"i="<<i<<endl;

    _category = -1;

    _recolep_sel_charge.clear();
    _recolep_sel_pdg.clear();
    _recolep_sel_e.clear();
    _recolep_sel_px.clear();
    _recolep_sel_py.clear();
    _recolep_sel_pz.clear();
    _recolep_sel_pt.clear();
    _recolep_sel_conept.clear();
    _recolep_sel_eta.clear();
    _recolep_sel_phi.clear();
    _recolep_sel_fakerate.clear();
    _recolep_sel_fakerate_QCD_MC.clear();
    _recolep_sel_fakerate_ttbar_MC.clear();
    _recolep_sel_QFrate.clear(); 
    _recolep_sel_ismvasel.clear();
    _recolep_sel_tightcharge.clear();
    _recolep_sel_isGenMatched.clear();
    _recolep_sel_genMatchInd.clear();

    _recotauh_sel_charge.clear();
    _recotauh_sel_decayMode.clear();
    _recotauh_sel_e.clear();
    _recotauh_sel_px.clear();
    _recotauh_sel_py.clear();
    _recotauh_sel_pz.clear();
    _recotauh_sel_pt.clear();
    _recotauh_sel_eta.clear();
    _recotauh_sel_phi.clear();
    _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_againstMuonLoose3.clear();
    _recotauh_sel_againstMuonTight3.clear();
    _recotauh_sel_againstElectronVLooseMVA6.clear();
    _recotauh_sel_againstElectronLooseMVA6.clear();
    _recotauh_sel_againstElectronMediumMVA6.clear();
    _recotauh_sel_againstElectronTightMVA6.clear();
    _recotauh_sel_againstElectronVTightMVA6.clear();
    _recotauh_sel_isGenMatched.clear();
    _recotauh_sel_genMatchInd.clear();
    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();

    _n_fake_lep = 0;
    _n_fake_tau = 0;

    _event_weight_ttH = 0;
    _event_weight_ttH_FR_QCD_MC = 0;
    _event_weight_ttH_FR_TT_MC = 0;
    _event_weight_ttH_ele_FR_QCD_MC = 0;
    _event_weight_ttH_ele_FR_TT_MC = 0;
    _event_weight_ttH_mu_FR_QCD_MC = 0;
    _event_weight_ttH_mu_FR_TT_MC = 0;

    _triggerSF_weight = 0;
    _triggerSF_weight_up = 0;
    _triggerSF_weight_down = 0;
    _leptonSF_ttH_weight = 0;
    _tauSF_weight = 0;
    _isGenMatched = 0;

    _n_recolep_mvasel = 0;
    _n_recolep_fakeable = 0;
    _n_recolep_presel = 0;

    _recolep_charge = 0;
    _recolep_pdg = 0;
    _recolep_e = 0;
    _recolep_px = 0;
    _recolep_py = 0;
    _recolep_pz = 0;
    _recolep_pt = 0;
    _recolep_conept = 0;
    _recolep_eta = 0;
    _recolep_phi = 0;
    _recolep_fakerate = 0;
    _recolep_fakerate_QCD_MC = 0;
    _recolep_fakerate_ttbar_MC = 0;
    _recolep_QFrate = 0; 
    _recolep_ismvasel = 0;
    _recolep_tightcharge = 0;
    _recolep_isGenMatched = 0;
    _recolep_genMatchInd = 0;
  
    _recomu_e = 0;
    _recomu_px = 0;
    _recomu_py = 0;
    _recomu_pz = 0;
  
    _recoele_e = 0;
    _recoele_px = 0;
    _recoele_py = 0;
    _recoele_pz = 0;

    _ETmissLD = 0;
    _n_recoPFJet = 0;
    _n_recoPFJet_btag_medium = 0;
    _n_recoPFJet_btag_loose = 0;

    _n_recotauh = 0;
    _recotauh_charge = 0;
    _recotauh_decayMode = 0;
    _recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017 = 0;
    _recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017 = 0;
    _recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017 = 0;
    _recotauh_againstMuonLoose3 = 0;
    _recotauh_againstMuonTight3 = 0;
    _recotauh_againstElectronVLooseMVA6 = 0;
    _recotauh_againstElectronLooseMVA6 = 0;
    _recotauh_againstElectronMediumMVA6 = 0;
    _recotauh_againstElectronTightMVA6 = 0;
    _recotauh_againstElectronVTightMVA6 = 0;
    _recotauh_e = 0;
    _recotauh_px = 0;
    _recotauh_py = 0;
    _recotauh_pz = 0;
    _recotauh_isGenMatched = 0;
    _recotauh_genMatchInd = 0;
    _recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT = 0;
    _recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT = 0;

    tree->GetEntry(i);

    // 1l+2tau
    if(_n_recolep_fakeable>=1 && _n_recolep_mvasel<=1 && _n_recotauh>=2){     
      
      TLorentzVector lep1((*_recolep_px)[0],(*_recolep_py)[0],(*_recolep_pz)[0],(*_recolep_e)[0]);
	  	    
      _recolep_sel_charge.push_back((*_recolep_charge)[0]);
      _recolep_sel_pdg.push_back((*_recolep_pdg)[0]);
      _recolep_sel_e.push_back(lep1.E());
      _recolep_sel_px.push_back(lep1.Px());
      _recolep_sel_py.push_back(lep1.Py());
      _recolep_sel_pz.push_back(lep1.Pz());
      _recolep_sel_pt.push_back(lep1.Pt());
      _recolep_sel_conept.push_back((*_recolep_conept)[0]);
      _recolep_sel_eta.push_back(lep1.Eta());
      _recolep_sel_phi.push_back(lep1.Phi());
      _recolep_sel_fakerate.push_back((*_recolep_fakerate)[0]);
      _recolep_sel_fakerate_QCD_MC.push_back((*_recolep_fakerate_QCD_MC)[0]);
      _recolep_sel_fakerate_ttbar_MC.push_back((*_recolep_fakerate_ttbar_MC)[0]);
      _recolep_sel_QFrate.push_back((*_recolep_QFrate)[0]);
      _recolep_sel_ismvasel.push_back((*_recolep_ismvasel)[0]);
      _recolep_sel_tightcharge.push_back((*_recolep_tightcharge)[0]);
      if(isMC){
	_recolep_sel_isGenMatched.push_back((*_recolep_isGenMatched)[0]);
	_recolep_sel_genMatchInd.push_back((*_recolep_genMatchInd)[0]);
      }


      for(unsigned int i_tau=0; i_tau<(*_recotauh_charge).size(); i_tau++){
	  
	if((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]>0.5){
	    
	    _recotauh_sel_charge.push_back((*_recotauh_charge)[i_tau]);
	    _recotauh_sel_decayMode.push_back((*_recotauh_decayMode)[i_tau]);
	    
	    TLorentzVector tau_tlv((*_recotauh_px)[i_tau],(*_recotauh_py)[i_tau],(*_recotauh_pz)[i_tau],(*_recotauh_e)[i_tau]);
	    
	    _recotauh_sel_e.push_back(tau_tlv.E());
	    _recotauh_sel_px.push_back(tau_tlv.Px());
	    _recotauh_sel_py.push_back(tau_tlv.Py());
	    _recotauh_sel_pz.push_back(tau_tlv.Pz());
	    _recotauh_sel_pt.push_back(tau_tlv.Pt());
	    _recotauh_sel_eta.push_back(tau_tlv.Eta());
	    _recotauh_sel_phi.push_back(tau_tlv.Phi());
            _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_againstMuonLoose3.push_back((*_recotauh_againstMuonLoose3)[i_tau]);
	    _recotauh_sel_againstMuonTight3.push_back((*_recotauh_againstMuonTight3)[i_tau]);
	    _recotauh_sel_againstElectronVLooseMVA6.push_back((*_recotauh_againstElectronVLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronLooseMVA6.push_back((*_recotauh_againstElectronLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronMediumMVA6.push_back((*_recotauh_againstElectronMediumMVA6)[i_tau]);
	    _recotauh_sel_againstElectronTightMVA6.push_back((*_recotauh_againstElectronTightMVA6)[i_tau]);
	    _recotauh_sel_againstElectronVTightMVA6.push_back((*_recotauh_againstElectronVTightMVA6)[i_tau]);
	    if(isMC){
	      _recotauh_sel_isGenMatched.push_back((*_recotauh_isGenMatched)[i_tau]);	    
	      _recotauh_sel_genMatchInd.push_back((*_recotauh_genMatchInd)[i_tau]);	    
	    }
	    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);

	}

      }	  

      bool tau = _recotauh_sel_e.size()>=2;

      
      if(!tau){

	_recotauh_sel_charge.clear();
	_recotauh_sel_decayMode.clear();
	_recotauh_sel_e.clear();
	_recotauh_sel_px.clear();
	_recotauh_sel_py.clear();
	_recotauh_sel_pz.clear();
	_recotauh_sel_pt.clear();
	_recotauh_sel_eta.clear();
	_recotauh_sel_phi.clear();
        _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
	_recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
	_recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
	_recotauh_sel_againstMuonLoose3.clear();
	_recotauh_sel_againstMuonTight3.clear();
	_recotauh_sel_againstElectronVLooseMVA6.clear();
	_recotauh_sel_againstElectronLooseMVA6.clear();
	_recotauh_sel_againstElectronMediumMVA6.clear();
	_recotauh_sel_againstElectronTightMVA6.clear();
	_recotauh_sel_againstElectronVTightMVA6.clear();
	_recotauh_sel_isGenMatched.clear();
	_recotauh_sel_genMatchInd.clear();
	_recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
	_recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
	
	for(unsigned int i_tau=0; i_tau<2; i_tau++){
	  	    
	  _recotauh_sel_charge.push_back((*_recotauh_charge)[i_tau]);
	  _recotauh_sel_decayMode.push_back((*_recotauh_decayMode)[i_tau]);
	  
	  TLorentzVector tau_tlv((*_recotauh_px)[i_tau],(*_recotauh_py)[i_tau],(*_recotauh_pz)[i_tau],(*_recotauh_e)[i_tau]);
	  
	  _recotauh_sel_e.push_back(tau_tlv.E());
	  _recotauh_sel_px.push_back(tau_tlv.Px());
	  _recotauh_sel_py.push_back(tau_tlv.Py());
	  _recotauh_sel_pz.push_back(tau_tlv.Pz());
	  _recotauh_sel_pt.push_back(tau_tlv.Pt());
	  _recotauh_sel_eta.push_back(tau_tlv.Eta());
	  _recotauh_sel_phi.push_back(tau_tlv.Phi());
          _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	  _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	  _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	  _recotauh_sel_againstMuonLoose3.push_back((*_recotauh_againstMuonLoose3)[i_tau]);
	  _recotauh_sel_againstMuonTight3.push_back((*_recotauh_againstMuonTight3)[i_tau]);
	  _recotauh_sel_againstElectronVLooseMVA6.push_back((*_recotauh_againstElectronVLooseMVA6)[i_tau]);
	  _recotauh_sel_againstElectronLooseMVA6.push_back((*_recotauh_againstElectronLooseMVA6)[i_tau]);
	  _recotauh_sel_againstElectronMediumMVA6.push_back((*_recotauh_againstElectronMediumMVA6)[i_tau]);
	  _recotauh_sel_againstElectronTightMVA6.push_back((*_recotauh_againstElectronTightMVA6)[i_tau]);
	  _recotauh_sel_againstElectronVTightMVA6.push_back((*_recotauh_againstElectronVTightMVA6)[i_tau]);
	  if(isMC){
	    _recotauh_sel_isGenMatched.push_back((*_recotauh_isGenMatched)[i_tau]);
	    _recotauh_sel_genMatchInd.push_back((*_recotauh_genMatchInd)[i_tau]);
	  }
	  _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	  _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    	
	}	

      }


      bool tight_mvasel = _recolep_sel_ismvasel[0];   
      bool pt_lep = ((_recolep_sel_pt[0]>25 && abs(_recolep_sel_pdg[0])==13) || (_recolep_sel_pt[0]>30 && abs(_recolep_sel_pdg[0])==11));
      bool eta_lep = abs(_recolep_sel_eta[0])<2.1; //to match the lepton-tau cross triggers
      bool pt_taus = (_recotauh_sel_pt[0]>30 && _recotauh_sel_pt[1]>20);
      bool taus = _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0] && _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT[1];
      int  taus2 = _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0] + _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT[1];
      bool jetmult_sig = _n_recoPFJet>=3 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2);
      if(isMC)
	_isGenMatched = _recolep_sel_isGenMatched[0] && _recotauh_sel_isGenMatched[0] && _recotauh_sel_isGenMatched[1];
      bool tau_charge = _recotauh_sel_charge[0]*_recotauh_sel_charge[1]<0;
      bool jetmult_2jet_CR = _n_recoPFJet>=2 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2);

      bool sig_1l2tau;
      if(isMC){ sig_1l2tau = tight_mvasel && pt_lep && pt_taus && eta_lep && taus && jetmult_sig && tau_charge && _isGenMatched;}
      else{ sig_1l2tau = tight_mvasel && pt_lep && pt_taus && eta_lep && taus && jetmult_sig && tau_charge;}
      //bool sig_1l2tau = tight_mvasel && pt_lep && taus && jetmult_sig && tau_charge;
      bool fake_CR = (!tight_mvasel || taus2<2) && pt_lep && pt_taus && eta_lep && jetmult_sig && tau_charge;
      bool CR_2jet_tight_lep = tight_mvasel && taus && pt_lep && jetmult_2jet_CR && tau_charge; //FIXME
      bool CR_2jet_fake_lep = !(tight_mvasel && taus) && pt_lep && jetmult_2jet_CR && tau_charge; //FIXME

      /*cout<<"tight_mvasel="<<tight_mvasel<<endl;
      cout<<"taus="<<taus<<endl;
      cout<<"jetmult_sig="<<jetmult_sig<<endl;
      cout<<"tau_charge="<<tau_charge<<endl;
      cout<<"pt_lep="<<pt_lep<<endl;
      cout<<"fake_CR="<<fake_CR<<endl;*/

      _event_weight_ttH = 1;
      _event_weight_ttH_FR_QCD_MC = 1;
      _event_weight_ttH_FR_TT_MC = 1;
      _event_weight_ttH_ele_FR_QCD_MC = 1;
      _event_weight_ttH_ele_FR_TT_MC = 1;
      _event_weight_ttH_mu_FR_QCD_MC = 1;
      _event_weight_ttH_mu_FR_TT_MC = 1;
      _triggerSF_weight = 1;
      _triggerSF_weight_up = 1;
      _triggerSF_weight_down = 1;
      _leptonSF_ttH_weight = 1;
      _tauSF_weight = 1;

      _triggerSF_weight = triggerSF_ttH_1l(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0]);
      _triggerSF_weight_up = triggerSF_ttH_1l(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0], +1.);
      _triggerSF_weight_down = triggerSF_ttH_1l(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0], -1.);

      if(tight_mvasel)
	_leptonSF_ttH_weight = leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],3); //No tight-charge criteria for 1l2tau	      
      else
	_leptonSF_ttH_weight = _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],3);

      if(isMC)
	_tauSF_weight = (1-0.1*_recotauh_sel_isGenMatched[0])*(1-0.1*_recotauh_sel_isGenMatched[1]);
      
      int n_fake = 0;

      if(!_recolep_sel_ismvasel[0]){
	_event_weight_ttH *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	_event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	_event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);

	if(abs(_recolep_sel_pdg[0])==11){
	  _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	  _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);
	  _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	  _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	}
	
	else if(abs(_recolep_sel_pdg[0])==13){
	  _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	  _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	  _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	  _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);
	}


	n_fake++;
	_n_fake_lep++;
      }

      if(!_recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT[0]){
	float weight_tau = _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT[0]/(1-_recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT[0]);
	_event_weight_ttH *= weight_tau;
	_event_weight_ttH_FR_QCD_MC *= weight_tau;
	_event_weight_ttH_FR_TT_MC *= weight_tau;
	_event_weight_ttH_ele_FR_QCD_MC *= weight_tau;
	_event_weight_ttH_ele_FR_TT_MC *= weight_tau;
	_event_weight_ttH_mu_FR_TT_MC *= weight_tau;
	_event_weight_ttH_mu_FR_TT_MC *= weight_tau;
	
	n_fake++;
	_n_fake_tau++;
      }

      if(!_recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT[1]){
	float weight_tau = _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT[1]/(1-_recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT[1]);
	_event_weight_ttH *= weight_tau;
	_event_weight_ttH_FR_QCD_MC *= weight_tau;
	_event_weight_ttH_FR_TT_MC *= weight_tau;
	_event_weight_ttH_ele_FR_QCD_MC *= weight_tau;
	_event_weight_ttH_ele_FR_TT_MC *= weight_tau;
	_event_weight_ttH_mu_FR_TT_MC *= weight_tau;
	_event_weight_ttH_mu_FR_TT_MC *= weight_tau;
	
	n_fake++;
	_n_fake_tau++;
      }

      if(n_fake>0 && n_fake%2==0){
	_event_weight_ttH *=-1;
	_event_weight_ttH_FR_QCD_MC *=-1;
	_event_weight_ttH_FR_TT_MC *=-1;
	_event_weight_ttH_ele_FR_QCD_MC *= -1;
	_event_weight_ttH_ele_FR_TT_MC *= -1;
	_event_weight_ttH_mu_FR_TT_MC *= -1;
	_event_weight_ttH_mu_FR_TT_MC *= -1;
      }

      if(sig_1l2tau){

	_category = 20;
	tree_1l_2tau->Fill();

      }

      else if(fake_CR){

	_category = 50;
	tree_1l_2tau_fake_CR->Fill();

      }

      else if(CR_2jet_tight_lep){

	_category = 20;
	tree_1l_2tau_2jet_CR->Fill();

      }

      else if(CR_2jet_fake_lep){

	_category = 50;
	tree_1l_2tau_2jet_CR->Fill();

      }

    //CMP }

    }


    _recolep_sel_charge.clear();
    _recolep_sel_pdg.clear();
    _recolep_sel_e.clear();
    _recolep_sel_px.clear();
    _recolep_sel_py.clear();
    _recolep_sel_pz.clear();
    _recolep_sel_pt.clear();
    _recolep_sel_conept.clear();
    _recolep_sel_eta.clear();
    _recolep_sel_phi.clear();
    _recolep_sel_fakerate.clear();
    _recolep_sel_fakerate_QCD_MC.clear();
    _recolep_sel_fakerate_ttbar_MC.clear();
    _recolep_sel_QFrate.clear(); 
    _recolep_sel_ismvasel.clear();
    _recolep_sel_tightcharge.clear();
    _recolep_sel_isGenMatched.clear();      
    _recolep_sel_genMatchInd.clear();      


    _recotauh_sel_charge.clear();
    _recotauh_sel_decayMode.clear();    
    _recotauh_sel_e.clear();
    _recotauh_sel_px.clear();
    _recotauh_sel_py.clear();
    _recotauh_sel_pz.clear();
    _recotauh_sel_pt.clear();
    _recotauh_sel_eta.clear();
    _recotauh_sel_phi.clear();
    _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_againstMuonLoose3.clear();
    _recotauh_sel_againstMuonTight3.clear();
    _recotauh_sel_againstElectronVLooseMVA6.clear();
    _recotauh_sel_againstElectronLooseMVA6.clear();
    _recotauh_sel_againstElectronMediumMVA6.clear();
    _recotauh_sel_againstElectronTightMVA6.clear();
    _recotauh_sel_againstElectronVTightMVA6.clear();
    _recotauh_sel_isGenMatched.clear();
    _recotauh_sel_genMatchInd.clear();
    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();

    _n_fake_lep = 0;
    _n_fake_tau = 0;


    if(_n_recolep_presel>=2){

      bool inv_mass_lep_pairs=true;
      
      vector<TLorentzVector> loose_leptons;
      
      for(unsigned int i_mu=0; i_mu<(*_recomu_e).size(); i_mu++){
	TLorentzVector mu((*_recomu_px)[i_mu], (*_recomu_py)[i_mu], (*_recomu_pz)[i_mu], (*_recomu_e)[i_mu]);
	loose_leptons.push_back(mu);
      }
      
      for(unsigned int i_ele=0; i_ele<(*_recoele_e).size(); i_ele++){
	TLorentzVector ele((*_recoele_px)[i_ele], (*_recoele_py)[i_ele], (*_recoele_pz)[i_ele], (*_recoele_e)[i_ele]);
	loose_leptons.push_back(ele);
      }
      
      for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
	TLorentzVector lep1 = loose_leptons[i_lep];
	for(unsigned int i_lep2=i_lep+1; i_lep2<loose_leptons.size(); i_lep2++){
	  TLorentzVector lep2 = loose_leptons[i_lep2];
	  if((lep1+lep2).M()<12){
	    //lep1.Print();
	    //lep2.Print();
	    inv_mass_lep_pairs=false;
	  }
	}
      }
      

      //cout<<"inv_mass_lep_pairs="<<inv_mass_lep_pairs<<endl;
      if(!inv_mass_lep_pairs) continue;
      
      
      if(_n_recolep_mvasel<=2){
	
	bool inv_mass_Zee=true;
	
	for(unsigned int i_lep=0;i_lep<(*_recolep_charge).size();i_lep++){
	  
	  TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
	  
	  if(i_lep<2){
	    
	    _recolep_sel_charge.push_back((*_recolep_charge)[i_lep]);
	    _recolep_sel_pdg.push_back((*_recolep_pdg)[i_lep]);
	    _recolep_sel_e.push_back(lep1.E());
	    _recolep_sel_px.push_back(lep1.Px());
	    _recolep_sel_py.push_back(lep1.Py());
	    _recolep_sel_pz.push_back(lep1.Pz());
	    _recolep_sel_pt.push_back(lep1.Pt());
	    _recolep_sel_conept.push_back((*_recolep_conept)[i_lep]);
	    _recolep_sel_eta.push_back(lep1.Eta());
	    _recolep_sel_phi.push_back(lep1.Phi());
	    _recolep_sel_fakerate.push_back((*_recolep_fakerate)[i_lep]);
	    _recolep_sel_fakerate_QCD_MC.push_back((*_recolep_fakerate_QCD_MC)[i_lep]);
	    _recolep_sel_fakerate_ttbar_MC.push_back((*_recolep_fakerate_ttbar_MC)[i_lep]);
	    _recolep_sel_QFrate.push_back((*_recolep_QFrate)[i_lep]);
	    _recolep_sel_ismvasel.push_back((*_recolep_ismvasel)[i_lep]);
	    _recolep_sel_tightcharge.push_back((*_recolep_tightcharge)[i_lep]);
	    if(isMC){
	      _recolep_sel_isGenMatched.push_back((*_recolep_isGenMatched)[i_lep]);
	      _recolep_sel_genMatchInd.push_back((*_recolep_genMatchInd)[i_lep]);
	    }

	  }
	  
	  for(unsigned int i_lep2=i_lep+1; i_lep2<(*_recolep_charge).size();i_lep2++){
	    TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
	    float m_ll = (lep1 + lep2).M();
	    if(abs((*_recolep_pdg)[i_lep])==11 && abs((*_recolep_pdg)[i_lep2])==11 && fabs(m_ll-91.2)<10) inv_mass_Zee=false;
	    
	  }
	  
	}		
	
	
	for(unsigned int i_tau=0; i_tau<(*_recotauh_charge).size(); i_tau++){
	  
	  if((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]>0.5){
	    
	    _recotauh_sel_charge.push_back((*_recotauh_charge)[i_tau]);
	    _recotauh_sel_decayMode.push_back((*_recotauh_decayMode)[i_tau]);
	    
	    TLorentzVector tau_tlv((*_recotauh_px)[i_tau],(*_recotauh_py)[i_tau],(*_recotauh_pz)[i_tau],(*_recotauh_e)[i_tau]);
	    
	    _recotauh_sel_e.push_back(tau_tlv.E());
	    _recotauh_sel_px.push_back(tau_tlv.Px());
	    _recotauh_sel_py.push_back(tau_tlv.Py());
	    _recotauh_sel_pz.push_back(tau_tlv.Pz());
	    _recotauh_sel_pt.push_back(tau_tlv.Pt());
	    _recotauh_sel_eta.push_back(tau_tlv.Eta());
	    _recotauh_sel_phi.push_back(tau_tlv.Phi());
            _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_againstMuonLoose3.push_back((*_recotauh_againstMuonLoose3)[i_tau]);
	    _recotauh_sel_againstMuonTight3.push_back((*_recotauh_againstMuonTight3)[i_tau]);
	    _recotauh_sel_againstElectronVLooseMVA6.push_back((*_recotauh_againstElectronVLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronLooseMVA6.push_back((*_recotauh_againstElectronLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronMediumMVA6.push_back((*_recotauh_againstElectronMediumMVA6)[i_tau]);
	    _recotauh_sel_againstElectronTightMVA6.push_back((*_recotauh_againstElectronTightMVA6)[i_tau]);
	    _recotauh_sel_againstElectronVTightMVA6.push_back((*_recotauh_againstElectronVTightMVA6)[i_tau]);
	    if(isMC){
	      _recotauh_sel_isGenMatched.push_back((*_recotauh_isGenMatched)[i_tau]);	  	  
	      _recotauh_sel_genMatchInd.push_back((*_recotauh_genMatchInd)[i_tau]);	  	  
	    }
	    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);

	  }

	}	  

	bool tau = _recotauh_sel_e.size()>0;

  
	if(!tau){

	  _recotauh_sel_charge.clear();
	  _recotauh_sel_decayMode.clear();
	  _recotauh_sel_e.clear();
	  _recotauh_sel_px.clear();
	  _recotauh_sel_py.clear();
	  _recotauh_sel_pz.clear();
	  _recotauh_sel_pt.clear();
	  _recotauh_sel_eta.clear();
	  _recotauh_sel_phi.clear();
          _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  _recotauh_sel_againstMuonLoose3.clear();
	  _recotauh_sel_againstMuonTight3.clear();
	  _recotauh_sel_againstElectronVLooseMVA6.clear();
	  _recotauh_sel_againstElectronLooseMVA6.clear();
	  _recotauh_sel_againstElectronMediumMVA6.clear();
	  _recotauh_sel_againstElectronTightMVA6.clear();
	  _recotauh_sel_againstElectronVTightMVA6.clear();
	  _recotauh_sel_isGenMatched.clear();
	  _recotauh_sel_genMatchInd.clear();
	  _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  
	  for(unsigned int i_tau=0; i_tau<(*_recotauh_charge).size(); i_tau++){
	  	    
	    _recotauh_sel_charge.push_back((*_recotauh_charge)[i_tau]);
	    _recotauh_sel_decayMode.push_back((*_recotauh_decayMode)[i_tau]);
	    
	    TLorentzVector tau_tlv((*_recotauh_px)[i_tau],(*_recotauh_py)[i_tau],(*_recotauh_pz)[i_tau],(*_recotauh_e)[i_tau]);
	    
	    _recotauh_sel_e.push_back(tau_tlv.E());
	    _recotauh_sel_px.push_back(tau_tlv.Px());
	    _recotauh_sel_py.push_back(tau_tlv.Py());
	    _recotauh_sel_pz.push_back(tau_tlv.Pz());
	    _recotauh_sel_pt.push_back(tau_tlv.Pt());
	    _recotauh_sel_eta.push_back(tau_tlv.Eta());
	    _recotauh_sel_phi.push_back(tau_tlv.Phi());
            _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_againstMuonLoose3.push_back((*_recotauh_againstMuonLoose3)[i_tau]);
	    _recotauh_sel_againstMuonTight3.push_back((*_recotauh_againstMuonTight3)[i_tau]);
	    _recotauh_sel_againstElectronVLooseMVA6.push_back((*_recotauh_againstElectronVLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronLooseMVA6.push_back((*_recotauh_againstElectronLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronMediumMVA6.push_back((*_recotauh_againstElectronMediumMVA6)[i_tau]);
	    _recotauh_sel_againstElectronTightMVA6.push_back((*_recotauh_againstElectronTightMVA6)[i_tau]);
	    _recotauh_sel_againstElectronVTightMVA6.push_back((*_recotauh_againstElectronVTightMVA6)[i_tau]);
	    if(isMC){
	      _recotauh_sel_isGenMatched.push_back((*_recotauh_isGenMatched)[i_tau]);
	      _recotauh_sel_genMatchInd.push_back((*_recotauh_genMatchInd)[i_tau]);
	    }
	    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    
	    
	  }	

	}

	bool tau_fake = _recotauh_sel_e.size()>0;
	

	bool tight_mvasel = _recolep_sel_ismvasel[0]==1 && _recolep_sel_ismvasel[1]==1;
  int tight_mvasel2 = _recolep_sel_ismvasel[0] + _recolep_sel_ismvasel[1];
	bool lep_quality = _recolep_sel_tightcharge[0] && _recolep_sel_tightcharge[1];
	//bool pt_lep = ((_recolep_sel_conept[0]>25 && abs(_recolep_sel_pdg[0])==13) || (_recolep_sel_conept[0]>25 && abs(_recolep_sel_pdg[0])==11)) && ((_recolep_sel_conept[1]>10 && abs(_recolep_sel_pdg[1])==13) || (_recolep_sel_conept[1]>15 && abs(_recolep_sel_pdg[1])==11));
	bool pt_lep = ((_recolep_sel_pt[0]>25 && abs(_recolep_sel_pdg[0])==13) || (_recolep_sel_pt[0]>25 && abs(_recolep_sel_pdg[0])==11)) && ((_recolep_sel_pt[1]>10 && abs(_recolep_sel_pdg[1])==13) || (_recolep_sel_pt[1]>15 && abs(_recolep_sel_pdg[1])==11));
	bool taus2 = _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0] + _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT[1];
  bool OS_leptau = (_recolep_sel_charge[0]*_recotauh_sel_charge[0]<0) && (_recolep_sel_charge[1]*_recotauh_sel_charge[0]<0);
  bool SS_lep = _recolep_sel_charge[0]*_recolep_sel_charge[1]>0;
	bool SF_lep = abs(_recolep_sel_pdg[0])==abs(_recolep_sel_pdg[1]);
	bool metLD = (abs(_recolep_sel_pdg[0])==13 || abs(_recolep_sel_pdg[1])==13 || _ETmissLD>0.2);
	bool jetmult_sig = _n_recoPFJet>=3 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2);
	bool jetmult_CR_jets = _n_recoPFJet==2 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2);
	bool jetmult_ttbar_OF = _n_recoPFJet>=2 && _n_recoPFJet_btag_medium>=1;
	if(isMC && tau_fake)
	  _isGenMatched = _recolep_sel_isGenMatched[0] && _recolep_sel_isGenMatched[1] && _recotauh_sel_isGenMatched[0];
	
	bool sig_2lSS;
        if(isMC){ sig_2lSS = tight_mvasel && lep_quality && pt_lep && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_sig && _isGenMatched;}
	else { sig_2lSS = tight_mvasel && lep_quality && pt_lep && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_sig; }
        bool sig_2lSS_1tau;
        if(isMC){ sig_2lSS_1tau = tight_mvasel && lep_quality && pt_lep && taus2 ==1 && OS_leptau && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_sig && _isGenMatched;}
        else { sig_2lSS_1tau = tight_mvasel && lep_quality && pt_lep && taus2 ==1 && OS_leptau && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_sig; }
        //bool sig_2lSS_1tau = tight_mvasel && lep_quality && pt_lep && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_sig && tau;
	bool lepMVA_CR = !tight_mvasel && lep_quality && pt_lep && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_sig;
	bool tau_fake_CR = tau_fake && !tau && tight_mvasel2==1 && lep_quality && pt_lep && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_sig;
	bool sig_2lOS_CR = tight_mvasel && lep_quality && pt_lep && !SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_sig;
	bool jetmult_CR = tight_mvasel && lep_quality && pt_lep && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_CR_jets;
	bool ttbarOF_CR = tight_mvasel && lep_quality && pt_lep && !SS_lep && !SF_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_ttbar_OF;
	
	bool CR_2jets_tau = tau_fake && lep_quality && pt_lep && SS_lep && inv_mass_lep_pairs && inv_mass_Zee && metLD && jetmult_CR_jets;

	/*cout<<"tight_mvasel="<<tight_mvasel<<endl;
	cout<<"lep_quality="<<lep_quality<<endl;
	cout<<"pt_lep="<<pt_lep<<endl;
	cout<<"SS_lep="<<SS_lep<<endl;
	cout<<"inv_mass_lep_pairs="<<inv_mass_lep_pairs<<endl;
	cout<<"inv_mass_Zee="<<inv_mass_Zee<<endl;
	cout<<"metLD="<<metLD<<endl;
	cout<<"jetmult_sig="<<jetmult_sig<<endl;*/
	
	_event_weight_ttH = 1;
	_event_weight_ttH_FR_QCD_MC = 1;
	_event_weight_ttH_FR_TT_MC = 1;
	_event_weight_ttH_ele_FR_QCD_MC = 1;
	_event_weight_ttH_ele_FR_TT_MC = 1;
	_event_weight_ttH_mu_FR_QCD_MC = 1;
	_event_weight_ttH_mu_FR_TT_MC = 1;
	_triggerSF_weight = 1;
	_triggerSF_weight_up = 1;
	_triggerSF_weight_down = 1;
	_leptonSF_ttH_weight = 1;
	_tauSF_weight = 1;

	
	if(_recolep_sel_charge[0]*_recolep_sel_charge[1]<0)
	  _event_weight_ttH = _recolep_sel_QFrate[0]+_recolep_sel_QFrate[1];
	

	int n_fake = 0;

	if(!_recolep_sel_ismvasel[0]){
	    _event_weight_ttH *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	    _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	    _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);

	    if(abs(_recolep_sel_pdg[0])==11){
	      _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	      _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);
	      _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	      _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	    }
	    
	    else if(abs(_recolep_sel_pdg[0])==13){
	      _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	      _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	      _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	      _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);
	    }
	    
	    
	    n_fake++;
	    _n_fake_lep++;
	}


	if(!_recolep_sel_ismvasel[1]){
	    _event_weight_ttH *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	    _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[1]/(1-_recolep_sel_fakerate_QCD_MC[1]);
	    _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[1]/(1-_recolep_sel_fakerate_ttbar_MC[1]);

	    if(abs(_recolep_sel_pdg[1])==11){
	      _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[1]/(1-_recolep_sel_fakerate_QCD_MC[1]);
	      _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[1]/(1-_recolep_sel_fakerate_ttbar_MC[1]);
	      _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	      _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	    }
	    
	    else if(abs(_recolep_sel_pdg[1])==13){
	      _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	      _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	      _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[1]/(1-_recolep_sel_fakerate_QCD_MC[1]);
	      _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[1]/(1-_recolep_sel_fakerate_ttbar_MC[1]);
	    }

	    n_fake++;
	    _n_fake_lep++;
	}	
	
	
	if(tau_fake){
	  if(!_recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0]){
	    float weight_tau = _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0]/(1-_recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0]);
	    _event_weight_ttH *= weight_tau;
	    _event_weight_ttH_FR_QCD_MC *= weight_tau;
	    _event_weight_ttH_FR_TT_MC *= weight_tau;
	    _event_weight_ttH_ele_FR_QCD_MC *= weight_tau;
	    _event_weight_ttH_ele_FR_TT_MC *= weight_tau;
	    _event_weight_ttH_mu_FR_TT_MC *= weight_tau;
	    _event_weight_ttH_mu_FR_TT_MC *= weight_tau;

	    n_fake++;
	    _n_fake_tau++;
	  }
	}
      
	if(n_fake>0 && n_fake%2==0){
	  _event_weight_ttH *=-1;
	  _event_weight_ttH_FR_QCD_MC *=-1;
	  _event_weight_ttH_FR_TT_MC *=-1;
	  _event_weight_ttH_ele_FR_QCD_MC *= -1;
	  _event_weight_ttH_ele_FR_TT_MC *= -1;
	  _event_weight_ttH_mu_FR_TT_MC *= -1;
	  _event_weight_ttH_mu_FR_TT_MC *= -1;
	}

	
	if(!isReHLT)
	  _triggerSF_weight = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],
					    _recolep_sel_pdg[1],_recolep_sel_pt[1],
					    2);
	else{
	  if(abs(_recolep_sel_pdg[0])==11 && abs(_recolep_sel_pdg[1])==11){
	    _triggerSF_weight = 1.02;
	    _triggerSF_weight_up = 1.04;
	    _triggerSF_weight_down = 1.0;
	  }
	  else if(abs(_recolep_sel_pdg[0])==11 || abs(_recolep_sel_pdg[1])==11){
	    _triggerSF_weight = 1.02;
	    _triggerSF_weight_up = 1.03;
	    _triggerSF_weight_down = 1.01;
	  }
	  else{
	    _triggerSF_weight = 1.01;
	    _triggerSF_weight_up = 1.02;
	    _triggerSF_weight_down = 1.0;
	  }
	}


	/*if(tight_mvasel)
	  _leptonSF_ttH_weight = leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2)
	  * leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);*/

	if(_recolep_sel_ismvasel[0])
	  _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);
	else
	  _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);

	if(_recolep_sel_ismvasel[1])
	  _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);
	else
	  _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);
	

	if(isMC && tau_fake)
	  _tauSF_weight = (1-0.1*_recotauh_sel_isGenMatched[0]);

	
	//2lSS + tauh
	if(tau_fake){
	   
	  if(_recolep_sel_charge[0]*_recolep_sel_charge[1]>0){
	    if(tight_mvasel && tau)
	      _category = 11;
	    else
	      _category = 41;	    
	  }
	  
	  else if(_recolep_sel_charge[0]*_recolep_sel_charge[1]<0 && tight_mvasel && tau)
	    _category = -11;
	  
	}
	
	//MuMu
	else if(abs(_recolep_sel_pdg[0])==13 && abs(_recolep_sel_pdg[1])==13){
	 
	  if(_n_recoPFJet_btag_medium>=2){
	    
	    if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	      if(tight_mvasel)
		_category = 1;
	      else
		_category = 31;
	    }
	    
	    else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	      if(tight_mvasel)
		_category = 2;
	      else
		_category = 32;
	    }
	    
	    else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0 && tight_mvasel)
	      _category = -1;
	    
	  }
	  
	  else{
	    
	    if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	      if(tight_mvasel)
		_category = 3;
	      else
		_category = 33;
	    }
	    
	    else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	      if(tight_mvasel)
		_category = 4;
	      else
		_category = 34;
	    }
	    
	    else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0 && tight_mvasel)
	      _category = -3;
	    
	  }
	}
	
	//EMu
	else if((abs(_recolep_sel_pdg[0])==13 && abs(_recolep_sel_pdg[1])==11) || (abs(_recolep_sel_pdg[0])==11 && abs(_recolep_sel_pdg[1])==13)){
	 
	  if(_n_recoPFJet_btag_medium>=2){
	    
	    if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	      if(tight_mvasel)
		_category = 5;
	      else
		_category = 35;
	    }
	    
	    else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	      if(tight_mvasel)
		_category = 6;
	      else
		_category = 36;
	    }
	    
	    else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0 && tight_mvasel){
	      if(_recolep_sel_pdg[0]==-13 || _recolep_sel_pdg[1]==-13)
		_category = -5;
	      else if(_recolep_sel_pdg[0]==13 || _recolep_sel_pdg[1]==13)
		_category = -6;
	    }
	  }
	  
	  else{
	    
	    if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	      if(tight_mvasel)
		_category = 7;
	      else
		_category = 37;
	    }
	    
	    else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	      if(tight_mvasel)
		_category = 8;
	      else
		_category = 38;
	    }
	    
	    else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0 && tight_mvasel){
	      if(_recolep_sel_pdg[0]==-13 || _recolep_sel_pdg[1]==-13)
		_category = -7;
	      else if(_recolep_sel_pdg[0]==13 || _recolep_sel_pdg[1]==13)
		_category = -8;
	    }
	    
	  }
	}
	
	//EE
	else if(abs(_recolep_sel_pdg[0])==11 && abs(_recolep_sel_pdg[1])==11){
	 
	  if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	    if(tight_mvasel)
	      _category = 9;
	    else
	      _category = 39;
	  }
	  
	  else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	    if(tight_mvasel)
	      _category = 10;
	    else
	      _category = 40;
	  }
	  
	  else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0 && tight_mvasel){
	    if(_recolep_sel_charge[0]>0)
	      _category = -9;
	    else
	      _category = -10;
	  }
	  
	}
	
	
	
	if(sig_2lSS_1tau)
	  tree_2lSS->Fill();
	else if(lepMVA_CR || tau_fake_CR)
	  tree_2lSS_lepMVA_CR->Fill();
	else if(sig_2lOS_CR)
	  tree_2lOS_CR->Fill();
	else if(jetmult_CR)
	  tree_2lSS_jetmult_CR->Fill(); 
	else if(ttbarOF_CR)
	  tree_2lSS_ttbarOF_CR->Fill();      
	
	if(CR_2jets_tau)
	  tree_2lSS_2jet_CR->Fill();
	
      }
         

      
      _recolep_sel_charge.clear();
      _recolep_sel_pdg.clear();
      _recolep_sel_e.clear();
      _recolep_sel_px.clear();
      _recolep_sel_py.clear();
      _recolep_sel_pz.clear();
      _recolep_sel_pt.clear();
      _recolep_sel_conept.clear();
      _recolep_sel_eta.clear();
      _recolep_sel_phi.clear();
      _recolep_sel_fakerate.clear();
      _recolep_sel_fakerate_QCD_MC.clear();
      _recolep_sel_fakerate_ttbar_MC.clear();
      _recolep_sel_QFrate.clear(); 
      _recolep_sel_ismvasel.clear();
      _recolep_sel_tightcharge.clear();
      _recolep_sel_isGenMatched.clear();
      _recolep_sel_genMatchInd.clear();

      _recotauh_sel_charge.clear();
      _recotauh_sel_decayMode.clear();    
      _recotauh_sel_e.clear();
      _recotauh_sel_px.clear();
      _recotauh_sel_py.clear();
      _recotauh_sel_pz.clear();
      _recotauh_sel_pt.clear();
      _recotauh_sel_eta.clear();
      _recotauh_sel_phi.clear();
      _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
      _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
      _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
      _recotauh_sel_againstMuonLoose3.clear();
      _recotauh_sel_againstMuonTight3.clear();
      _recotauh_sel_againstElectronVLooseMVA6.clear();
      _recotauh_sel_againstElectronLooseMVA6.clear();
      _recotauh_sel_againstElectronMediumMVA6.clear();
      _recotauh_sel_againstElectronTightMVA6.clear();
      _recotauh_sel_againstElectronVTightMVA6.clear();
      _recotauh_sel_isGenMatched.clear();
      _recotauh_sel_genMatchInd.clear();
      _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
      _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
      
      _n_fake_lep = 0;
      _n_fake_tau = 0;
     
     

      if(_n_recolep_fakeable>=3){  
                 
	bool inv_mass_Z=true;
	bool SFOS_pair=false;
	
	for(unsigned int i_lep=0;i_lep<(*_recolep_charge).size();i_lep++){
	  
	  TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
	  
	  if(i_lep<3){
	    
	    _recolep_sel_charge.push_back((*_recolep_charge)[i_lep]);
	    _recolep_sel_pdg.push_back((*_recolep_pdg)[i_lep]);
	    _recolep_sel_e.push_back(lep1.E());
	    _recolep_sel_px.push_back(lep1.Px());
	    _recolep_sel_py.push_back(lep1.Py());
	    _recolep_sel_pz.push_back(lep1.Pz());
	    _recolep_sel_pt.push_back(lep1.Pt());
	    _recolep_sel_conept.push_back((*_recolep_conept)[i_lep]);
	    _recolep_sel_eta.push_back(lep1.Eta());
	    _recolep_sel_phi.push_back(lep1.Phi());
	    _recolep_sel_fakerate.push_back((*_recolep_fakerate)[i_lep]);
	    _recolep_sel_fakerate_QCD_MC.push_back((*_recolep_fakerate_QCD_MC)[i_lep]);
	    _recolep_sel_fakerate_ttbar_MC.push_back((*_recolep_fakerate_ttbar_MC)[i_lep]);
	    _recolep_sel_QFrate.push_back((*_recolep_QFrate)[i_lep]);
	    _recolep_sel_ismvasel.push_back((*_recolep_ismvasel)[i_lep]);
	    if(isMC){	      
	      _recolep_sel_isGenMatched.push_back((*_recolep_isGenMatched)[i_lep]);	    
	      _recolep_sel_genMatchInd.push_back((*_recolep_genMatchInd)[i_lep]);	    
	    }
	    
	  }
	  
	  for(unsigned int i_lep2=i_lep+1; i_lep2<(*_recolep_charge).size();i_lep2++){
	    TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
	    float m_ll = (lep1 + lep2).M();
	    if((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep2]){
	      SFOS_pair=true;
	      if(fabs(m_ll-91.2)<10) inv_mass_Z=false;
	    }
	  }
	  
	}
	

	for(unsigned int i_tau=0; i_tau<(*_recotauh_charge).size(); i_tau++){
	  
	  if((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]>0.5){
	    
	    _recotauh_sel_charge.push_back((*_recotauh_charge)[i_tau]);
	    _recotauh_sel_decayMode.push_back((*_recotauh_decayMode)[i_tau]);
	    
	    TLorentzVector tau_tlv((*_recotauh_px)[i_tau],(*_recotauh_py)[i_tau],(*_recotauh_pz)[i_tau],(*_recotauh_e)[i_tau]);
	    
	    _recotauh_sel_e.push_back(tau_tlv.E());
	    _recotauh_sel_px.push_back(tau_tlv.Px());
	    _recotauh_sel_py.push_back(tau_tlv.Py());
	    _recotauh_sel_pz.push_back(tau_tlv.Pz());
	    _recotauh_sel_pt.push_back(tau_tlv.Pt());
	    _recotauh_sel_eta.push_back(tau_tlv.Eta());
	    _recotauh_sel_phi.push_back(tau_tlv.Phi());
            _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_againstMuonLoose3.push_back((*_recotauh_againstMuonLoose3)[i_tau]);
	    _recotauh_sel_againstMuonTight3.push_back((*_recotauh_againstMuonTight3)[i_tau]);
	    _recotauh_sel_againstElectronVLooseMVA6.push_back((*_recotauh_againstElectronVLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronLooseMVA6.push_back((*_recotauh_againstElectronLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronMediumMVA6.push_back((*_recotauh_againstElectronMediumMVA6)[i_tau]);
	    _recotauh_sel_againstElectronTightMVA6.push_back((*_recotauh_againstElectronTightMVA6)[i_tau]);
	    _recotauh_sel_againstElectronVTightMVA6.push_back((*_recotauh_againstElectronVTightMVA6)[i_tau]);
	    if(isMC){	      
	      _recotauh_sel_isGenMatched.push_back((*_recotauh_isGenMatched)[i_tau]);	  	  
	      _recotauh_sel_genMatchInd.push_back((*_recotauh_genMatchInd)[i_tau]);	  	  
	    }
	    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);

	  }

	}	  

	bool tau = _recotauh_sel_e.size()>0;

  
	if(!tau){

	  _recotauh_sel_charge.clear();
	  _recotauh_sel_decayMode.clear();
	  _recotauh_sel_e.clear();
	  _recotauh_sel_px.clear();
	  _recotauh_sel_py.clear();
	  _recotauh_sel_pz.clear();
	  _recotauh_sel_pt.clear();
	  _recotauh_sel_eta.clear();
	  _recotauh_sel_phi.clear();
          _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  _recotauh_sel_againstMuonLoose3.clear();
	  _recotauh_sel_againstMuonTight3.clear();
	  _recotauh_sel_againstElectronVLooseMVA6.clear();
	  _recotauh_sel_againstElectronLooseMVA6.clear();
	  _recotauh_sel_againstElectronMediumMVA6.clear();
	  _recotauh_sel_againstElectronTightMVA6.clear();
	  _recotauh_sel_againstElectronVTightMVA6.clear();
	  _recotauh_sel_isGenMatched.clear();
	  _recotauh_sel_genMatchInd.clear();
	  _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
	  _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();

	  for(unsigned int i_tau=0; i_tau<(*_recotauh_charge).size(); i_tau++){
	  	    
	    _recotauh_sel_charge.push_back((*_recotauh_charge)[i_tau]);
	    _recotauh_sel_decayMode.push_back((*_recotauh_decayMode)[i_tau]);
	    
	    TLorentzVector tau_tlv((*_recotauh_px)[i_tau],(*_recotauh_py)[i_tau],(*_recotauh_pz)[i_tau],(*_recotauh_e)[i_tau]);
	    
	    _recotauh_sel_e.push_back(tau_tlv.E());
	    _recotauh_sel_px.push_back(tau_tlv.Px());
	    _recotauh_sel_py.push_back(tau_tlv.Py());
	    _recotauh_sel_pz.push_back(tau_tlv.Pz());
	    _recotauh_sel_pt.push_back(tau_tlv.Pt());
	    _recotauh_sel_eta.push_back(tau_tlv.Eta());
	    _recotauh_sel_phi.push_back(tau_tlv.Phi());
            _recotauh_sel_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	    _recotauh_sel_againstMuonLoose3.push_back((*_recotauh_againstMuonLoose3)[i_tau]);
	    _recotauh_sel_againstMuonTight3.push_back((*_recotauh_againstMuonTight3)[i_tau]);
	    _recotauh_sel_againstElectronVLooseMVA6.push_back((*_recotauh_againstElectronVLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronLooseMVA6.push_back((*_recotauh_againstElectronLooseMVA6)[i_tau]);
	    _recotauh_sel_againstElectronMediumMVA6.push_back((*_recotauh_againstElectronMediumMVA6)[i_tau]);
	    _recotauh_sel_againstElectronTightMVA6.push_back((*_recotauh_againstElectronTightMVA6)[i_tau]);
	    _recotauh_sel_againstElectronVTightMVA6.push_back((*_recotauh_againstElectronVTightMVA6)[i_tau]);
	    if(isMC){
	      _recotauh_sel_isGenMatched.push_back((*_recotauh_isGenMatched)[i_tau]);
	      _recotauh_sel_genMatchInd.push_back((*_recotauh_genMatchInd)[i_tau]);
	    }
	    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);	    
      
	    
	  }	

	}

	bool tau_fake = _recotauh_sel_e.size()>0;
	
	bool tight_mvasel = _recolep_sel_ismvasel[0]==1 && _recolep_sel_ismvasel[1]==1 && _recolep_sel_ismvasel[2]==1;
  int tight_mvasel2 = _recolep_sel_ismvasel[0] + _recolep_sel_ismvasel[1] + _recolep_sel_ismvasel[2];
	//bool pt_lep = _recolep_sel_conept[0]>20 && _recolep_sel_conept[1]>10 && _recolep_sel_conept[2]>10;
	bool pt_lep = _recolep_sel_pt[0]>20 && _recolep_sel_pt[1]>10 && _recolep_sel_pt[2]>10;
	bool metLD = _ETmissLD>0.2 || _n_recoPFJet>=4;
	if(SFOS_pair)
	  metLD = _ETmissLD>0.3 || _n_recoPFJet>=4;
	bool three_charge = abs(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2])==1;
	bool jetmult_sig = _n_recoPFJet>=2 && (_n_recoPFJet_btag_loose>=2 || _n_recoPFJet_btag_medium>=1);
	bool jetmult_WZ = _n_recoPFJet>=2 && _n_recoPFJet_btag_medium==0;
	bool jetmult_ttZ = _n_recoPFJet>=2 && _n_recoPFJet_btag_medium>=1 && _n_recoPFJet_btag_loose>=2;
	if(isMC && tau_fake)
	  _isGenMatched = _recolep_sel_isGenMatched[0] && _recolep_sel_isGenMatched[1] && _recolep_sel_isGenMatched[2] && _recotauh_sel_isGenMatched[0];
	

	bool sig_3l = tight_mvasel && pt_lep && inv_mass_lep_pairs && inv_mass_Z && metLD && three_charge && jetmult_sig; //&& isGenMatched;
	bool sig_3l_1tau;
  if(isMC){sig_3l_1tau = tight_mvasel && pt_lep && inv_mass_lep_pairs && inv_mass_Z && metLD && three_charge && jetmult_sig && tau && _isGenMatched;} //&& isGenMatched;
	else{ sig_3l_1tau = tight_mvasel && pt_lep && inv_mass_lep_pairs && inv_mass_Z && metLD && three_charge && jetmult_sig && tau;}
  bool lepMVA_CR = !tight_mvasel && pt_lep && inv_mass_lep_pairs && inv_mass_Z && metLD && three_charge && jetmult_sig;
	bool tau_fake_CR = !tau && tau_fake && tight_mvasel2<3 && pt_lep && inv_mass_lep_pairs && inv_mass_Z && metLD && three_charge && jetmult_sig;
	bool WZ_CR = tight_mvasel && pt_lep && inv_mass_lep_pairs && !inv_mass_Z && metLD && three_charge && jetmult_WZ;
	bool ttZ_CR = tight_mvasel && pt_lep && inv_mass_lep_pairs && !inv_mass_Z && metLD && three_charge && jetmult_ttZ;
	bool ttZ_lepMVA_CR = !tight_mvasel && pt_lep && inv_mass_lep_pairs && !inv_mass_Z && metLD && three_charge && jetmult_ttZ;
	
	_event_weight_ttH = 1;
	_event_weight_ttH_FR_QCD_MC = 1;
	_event_weight_ttH_FR_TT_MC = 1;
	_event_weight_ttH_ele_FR_QCD_MC = 1;
	_event_weight_ttH_ele_FR_TT_MC = 1;
	_event_weight_ttH_mu_FR_QCD_MC = 1;
	_event_weight_ttH_mu_FR_TT_MC = 1;
	_triggerSF_weight = 1;
	_triggerSF_weight_up = 1;
	_triggerSF_weight_down = 1;
	_leptonSF_ttH_weight = 1;
	_tauSF_weight = 1;

	int n_fake = 0;

	if(!_recolep_sel_ismvasel[0]){
	  _event_weight_ttH *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	  _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	  _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);

	  if(abs(_recolep_sel_pdg[0])==11){
	    _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	    _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);
	    _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	    _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	  }
	  
	  else if(abs(_recolep_sel_pdg[0])==13){
	    _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	    _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate[0]/(1-_recolep_sel_fakerate[0]);
	    _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[0]/(1-_recolep_sel_fakerate_QCD_MC[0]);
	    _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[0]/(1-_recolep_sel_fakerate_ttbar_MC[0]);
	  }

	  n_fake++;
	  _n_fake_lep++;
	}


	if(!_recolep_sel_ismvasel[1]){
	  _event_weight_ttH *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	  _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[1]/(1-_recolep_sel_fakerate_QCD_MC[1]);
	  _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[1]/(1-_recolep_sel_fakerate_ttbar_MC[1]);

	  if(abs(_recolep_sel_pdg[1])==11){
	    _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[1]/(1-_recolep_sel_fakerate_QCD_MC[1]);
	    _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[1]/(1-_recolep_sel_fakerate_ttbar_MC[1]);
	    _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	    _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	  }
	  
	  else if(abs(_recolep_sel_pdg[1])==13){
	    _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	    _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate[1]/(1-_recolep_sel_fakerate[1]);
	    _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[1]/(1-_recolep_sel_fakerate_QCD_MC[1]);
	    _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[1]/(1-_recolep_sel_fakerate_ttbar_MC[1]);
	  }

	  n_fake++;
	  _n_fake_lep++;
	}

	if(!_recolep_sel_ismvasel[2]){
	  _event_weight_ttH *= _recolep_sel_fakerate[2]/(1-_recolep_sel_fakerate[2]);
	  _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[2]/(1-_recolep_sel_fakerate_QCD_MC[1]);
	  _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[2]/(1-_recolep_sel_fakerate_ttbar_MC[1]);

	  if(abs(_recolep_sel_pdg[2])==11){
	    _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[2]/(1-_recolep_sel_fakerate_QCD_MC[2]);
	    _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[2]/(1-_recolep_sel_fakerate_ttbar_MC[2]);
	    _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate[2]/(1-_recolep_sel_fakerate[2]);
	    _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate[2]/(1-_recolep_sel_fakerate[2]);
	  }

	  else if(abs(_recolep_sel_pdg[2])==13){
	    _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate[2]/(1-_recolep_sel_fakerate[2]);
	    _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate[2]/(1-_recolep_sel_fakerate[2]);
	    _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[2]/(1-_recolep_sel_fakerate_QCD_MC[2]);
	    _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[2]/(1-_recolep_sel_fakerate_ttbar_MC[2]);
	  }

	  n_fake++;
	  _n_fake_lep++;
	}	
	
	if(tau_fake){	
	  if(!_recotauh_sel_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0]){
	    float weight_tau = _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0]/(1-_recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT[0]);
	    _event_weight_ttH *= weight_tau;
	    _event_weight_ttH_FR_QCD_MC *= weight_tau;
	    _event_weight_ttH_FR_TT_MC *= weight_tau;
	    _event_weight_ttH_ele_FR_QCD_MC *= weight_tau;
	    _event_weight_ttH_ele_FR_TT_MC *= weight_tau;
	    _event_weight_ttH_mu_FR_TT_MC *= weight_tau;
	    _event_weight_ttH_mu_FR_TT_MC *= weight_tau;
	    n_fake++;
	    _n_fake_tau++;
	  }
	}	  

	if(n_fake>0 && n_fake%2==0){
	  _event_weight_ttH *=-1;
	  _event_weight_ttH_FR_QCD_MC *=-1;
	  _event_weight_ttH_FR_TT_MC *=-1;
	  _event_weight_ttH_ele_FR_QCD_MC *= -1;
	  _event_weight_ttH_ele_FR_TT_MC *= -1;
	  _event_weight_ttH_mu_FR_TT_MC *= -1;
	  _event_weight_ttH_mu_FR_TT_MC *= -1;
	}

	if(!isReHLT)
	  _triggerSF_weight = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],
					    _recolep_sel_pdg[1],_recolep_sel_pt[1],
					    3);
	
	else{
	  _triggerSF_weight = 1.;
	  _triggerSF_weight_up = 1.06;
	  _triggerSF_weight_down = 0.94;
	}

	/*if(tight_mvasel)
	  _leptonSF_ttH_weight = leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],3)
	    * leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],3)
	    * leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],3);*/

	if(_recolep_sel_ismvasel[0])
	  _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);
	else
	  _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);


	if(_recolep_sel_ismvasel[1])
	  _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);
	else
	  _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);


	if(_recolep_sel_ismvasel[2])
	  _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],2);
	else
	  _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],2);

		
	if(isMC && tau_fake)
	  _tauSF_weight = (1-0.1*_recotauh_sel_isGenMatched[0]);
      
      

	//if(tau){
	if(tau_fake){
	  
	  if(tight_mvasel && tau)
	    _category = 16;
	  else
	    _category = 46;	    
	  
	}
      
      
	else{
	  
	  if(_n_recoPFJet_btag_medium>=2){
	    
	    if(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2]>0){
	      if(tight_mvasel)
		_category = 12;
	      else
		_category = 42;
	    }
	    
	    else{
	      if(tight_mvasel)
		_category = 13;
	      else
		_category = 43;
	    }
	    
	  }
	
	  else{
	    
	    if(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2]>0){
	      if(tight_mvasel)
		_category = 14;
	      else
		_category = 44;
	    }
	    
	    else{
	      if(tight_mvasel)
		_category = 15;
	      else
		_category = 45;
	    }
	    
	  }
	  
	}
	
      
	
	if(sig_3l_1tau)
	  tree_3l->Fill();
	else if(lepMVA_CR || tau_fake_CR){
	  tree_3l_lepMVA_CR->Fill();
	}
	else if(WZ_CR)
	  tree_3l_WZ_CR->Fill(); 
	else if(ttZ_CR)
	  tree_3l_ttZ_CR->Fill(); 
	else if(ttZ_lepMVA_CR)
	  tree_3l_ttZ_lepMVA_CR->Fill(); 
	
      }

    

    }

  }


  f_new->cd();
  
  h->Write();

  for(unsigned int i=0; i<tree_new.size();i++)
    tree_new[i]->Write();



  f_new->Close();
  return;

}
