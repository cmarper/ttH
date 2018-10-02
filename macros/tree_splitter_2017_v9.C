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
#include "triggerSF.cc"
#include "triggerFilter_v2.cc"
#include "metFilter.cc"

using namespace std;


void split_tree(TString filename_in, TString filename_out,
		int i_split1=0, int i_split2=0,
		bool isMC=true, bool isReHLT=true){

  produce_triggerlist();

  vector<TString> list;
  list.push_back(filename_in);


  TChain * tree = new TChain("HTauTauTree");
  int nFiles = list.size();

  for(int i=0;i<nFiles;i++)
    {
      tree->Add(list[i]);
    }

  TH1F* h=new TH1F("h_counter","h_counter",3,0,3);


  //Old branches used

  Long64_t _EventNumber;
   
  Long64_t _triggerbit; 
  int _metfilterbit;
 
  int _n_recolep_mvasel;
  int _n_recolep_fakeable;

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
  vector<bool>  *_recomu_isfakeable;

  vector<float> *_recoele_e;
  vector<float> *_recoele_px;
  vector<float> *_recoele_py;
  vector<float> *_recoele_pz;
  vector<bool>  *_recoele_isfakeable;

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
  vector<float> *_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT;
  vector<float> *_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT;
  vector<float> *_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT;


  tree->SetBranchAddress("EventNumber",&_EventNumber);

  tree->SetBranchAddress("triggerbit",&_triggerbit);
  tree->SetBranchAddress("metfilterbit",&_metfilterbit);

  tree->SetBranchAddress("n_recolep_mvasel",&_n_recolep_mvasel);
  tree->SetBranchAddress("n_recolep_fakeable",&_n_recolep_fakeable);

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
  tree->SetBranchAddress("recomu_isfakeable",&_recomu_isfakeable);

  tree->SetBranchAddress("recoele_e",&_recoele_e);
  tree->SetBranchAddress("recoele_px",&_recoele_px);
  tree->SetBranchAddress("recoele_py",&_recoele_py);
  tree->SetBranchAddress("recoele_pz",&_recoele_pz);
  tree->SetBranchAddress("recoele_isfakeable",&_recoele_isfakeable);

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
  tree->SetBranchAddress("recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT);
  tree->SetBranchAddress("recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT);
  tree->SetBranchAddress("recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT);
  
  Long64_t nentries = tree->GetEntries();

  TFile* f_new = TFile::Open(filename_out);
  
  if(f_new!=0){
    cout<<filename_out<<" already exists, please delete it before converting again"<<endl;
    return;
  }
  
  f_new = TFile::Open(filename_out,"RECREATE");

  TTree* tree_1l_2tau_SR=tree->GetTree()->CloneTree(0);
  tree_1l_2tau_SR->SetNameTitle("HTauTauTree_1l_2tau_SR","HTauTauTree_1l_2tau_SR");
  TTree* tree_1l_2tau_fake=tree->GetTree()->CloneTree(0);
  tree_1l_2tau_fake->SetNameTitle("HTauTauTree_1l_2tau_fake","HTauTauTree_1l_2tau_fake");

  TTree* tree_2lSS_SR=tree->GetTree()->CloneTree(0);
  tree_2lSS_SR->SetNameTitle("HTauTauTree_2lSS_SR","HTauTauTree_2lSS_SR");
  TTree* tree_2lSS_fake=tree->GetTree()->CloneTree(0);
  tree_2lSS_fake->SetNameTitle("HTauTauTree_2lSS_fake","HTauTauTree_2lSS_fake");
  TTree* tree_2lSS_flip=tree->GetTree()->CloneTree(0);
  tree_2lSS_flip->SetNameTitle("HTauTauTree_2lSS_flip","HTauTauTree_2lSS_flip");

  TTree* tree_2lSS_1tau_SR=tree->GetTree()->CloneTree(0);
  tree_2lSS_1tau_SR->SetNameTitle("HTauTauTree_2lSS_1tau_SR","HTauTauTree_2lSS_1tau_SR");
  TTree* tree_2lSS_1tau_fake=tree->GetTree()->CloneTree(0);
  tree_2lSS_1tau_fake->SetNameTitle("HTauTauTree_2lSS_1tau_fake","HTauTauTree_2lSS_1tau_fake");
  TTree* tree_2lSS_1tau_flip=tree->GetTree()->CloneTree(0);
  tree_2lSS_1tau_flip->SetNameTitle("HTauTauTree_2lSS_1tau_flip","HTauTauTree_2lSS_1tau_flip");

  TTree* tree_2l_2tau_SR=tree->GetTree()->CloneTree(0);
  tree_2l_2tau_SR->SetNameTitle("HTauTauTree_2l_2tau_SR","HTauTauTree_2l_2tau_SR");
  TTree* tree_2l_2tau_fake=tree->GetTree()->CloneTree(0);
  tree_2l_2tau_fake->SetNameTitle("HTauTauTree_2l_2tau_fake","HTauTauTree_2l_2tau_fake");

  TTree* tree_3l_SR=tree->GetTree()->CloneTree(0);
  tree_3l_SR->SetNameTitle("HTauTauTree_3l_SR","HTauTauTree_3l_SR");
  TTree* tree_3l_fake=tree->GetTree()->CloneTree(0);
  tree_3l_fake->SetNameTitle("HTauTauTree_3l_fake","HTauTauTree_3l_fake");

  TTree* tree_3l_1tau_SR=tree->GetTree()->CloneTree(0);
  tree_3l_1tau_SR->SetNameTitle("HTauTauTree_3l_SR","HTauTauTree_3l_SR");
  TTree* tree_3l_1tau_fake=tree->GetTree()->CloneTree(0);
  tree_3l_1tau_fake->SetNameTitle("HTauTauTree_3l_1tau_fake","HTauTauTree_3l_1tau_fake");
  
  TTree* tree_4l_SR=tree->GetTree()->CloneTree(0);
  tree_4l_SR->SetNameTitle("HTauTauTree_4l_SR","HTauTauTree_4l_SR");
  TTree* tree_4l_fake=tree->GetTree()->CloneTree(0);
  tree_4l_fake->SetNameTitle("HTauTauTree_4l_fake","HTauTauTree_4l_fake");

  TTree* tree_ttWctrl_SR=tree->GetTree()->CloneTree(0);
  tree_ttWctrl_SR->SetNameTitle("HTauTauTree_ttWctrl_SR","HTauTauTree_ttWctrl_SR");
  TTree* tree_ttWctrl_fake=tree->GetTree()->CloneTree(0);
  tree_ttWctrl_fake->SetNameTitle("HTauTauTree_ttWctrl_fake","HTauTauTree_ttWctrl_fake");
  TTree* tree_ttWctrl_flip=tree->GetTree()->CloneTree(0);
  tree_ttWctrl_flip->SetNameTitle("HTauTauTree_ttWctrl_flip","HTauTauTree_ttWctrl_flip");

  TTree* tree_ttZctrl_SR=tree->GetTree()->CloneTree(0);
  tree_ttZctrl_SR->SetNameTitle("HTauTauTree_ttZctrl_SR","HTauTauTree_ttZctrl_SR");
  TTree* tree_ttZctrl_fake=tree->GetTree()->CloneTree(0);
  tree_ttZctrl_fake->SetNameTitle("HTauTauTree_ttZZctrl_fake","HTauTauTree_ttZctrl_fake");


  vector<TTree*> tree_new;

  tree_new.push_back(tree_1l_2tau_SR);
  tree_new.push_back(tree_1l_2tau_fake);

  tree_new.push_back(tree_2lSS_SR);
  tree_new.push_back(tree_2lSS_fake);
  tree_new.push_back(tree_2lSS_flip);

  tree_new.push_back(tree_2lSS_1tau_SR);
  tree_new.push_back(tree_2lSS_1tau_fake);
  tree_new.push_back(tree_2lSS_1tau_flip);

  tree_new.push_back(tree_2l_2tau_SR);
  tree_new.push_back(tree_2l_2tau_fake);

  tree_new.push_back(tree_3l_SR);
  tree_new.push_back(tree_3l_fake);

  tree_new.push_back(tree_3l_1tau_SR);
  tree_new.push_back(tree_3l_1tau_fake);

  tree_new.push_back(tree_4l_SR);
  tree_new.push_back(tree_4l_fake);

  tree_new.push_back(tree_ttWctrl_SR);
  tree_new.push_back(tree_ttWctrl_fake);
  tree_new.push_back(tree_ttWctrl_flip);

  tree_new.push_back(tree_ttZctrl_SR);
  tree_new.push_back(tree_ttZctrl_fake);


  int n_1l_2tau_SR=0;
  int n_1l_2tau_fake=0;

  int n_2lSS_SR=0;
  int n_2lSS_fake=0;
  int n_2lSS_flip=0;

  int n_2lSS_1tau_SR=0;
  int n_2lSS_1tau_fake=0;
  int n_2lSS_1tau_flip=0;

  int n_2l_2tau_SR=0;
  int n_2l_2tau_fake=0;

  int n_3l_SR=0;
  int n_3l_fake=0;

  int n_3l_1tau_SR=0;
  int n_3l_1tau_fake=0;
  
  int n_4l_SR=0;
  int n_4l_fake=0;
  
  int n_ttWctrl_SR=0;
  int n_ttWctrl_fake=0;
  int n_ttWctrl_flip=0;
  
  int n_ttZctrl_SR=0;
  int n_ttZctrl_fake=0;


  //New branches

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
    21: 2l + 2tauh
    
    -1: mumu flip, btight
    -3: mumu flip, bloose
    -5: emu flip, mu+ btight
    -6: emu flip, mu-  btight
    -7: emu flip, mu+ bloose
    -8: emu flip, mu- bloose
    -9: ee flip, lead. e+
    -10: ee flip, lead. e-
    -11: 2lss flip + tauh

    31: mumu+, btight, fake
    32: mumu-, btight, fake
    33: mumu+, bloose, fake
    34: mumu-, bloose, fake
    35: emu+, btight, fake
    36: emu-, btight, fake
    37: emu+, bloose, fake
    38: emu-, bloose, fake
    39: ee+, fake
    40: ee-, fake
    41: 2lSS + tauh, fake
    42: 3l+, btight, fake
    43: 3l-, btight, fake
    44: 3l+, bloose, fake
    45: 3l-, bloose, fake
    46: 3l- + tauh, fake
    50: 1l + 2tauh, fake
    51: 2l + 2tauh, fake

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
  vector<int> _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017;
  vector<int> _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017;
  vector<int> _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017;
  vector<int> _recotauh_sel_againstMuonLoose3;
  vector<int> _recotauh_sel_againstMuonTight3;
  vector<int> _recotauh_sel_againstElectronVLooseMVA6;
  vector<int> _recotauh_sel_againstElectronLooseMVA6;
  vector<int> _recotauh_sel_againstElectronMediumMVA6;
  vector<int> _recotauh_sel_againstElectronTightMVA6;
  vector<int> _recotauh_sel_againstElectronVTightMVA6;
  vector<bool> _recotauh_sel_isGenMatched;
  vector<int> _recotauh_sel_genMatchInd;
  vector<float> _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT; 
  vector<float> _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT; //to be updated
  vector<float> _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT; //to be updated

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
    tree_new[i]->Branch("recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017",&_recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017);
    tree_new[i]->Branch("recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017",&_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017);
    tree_new[i]->Branch("recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017",&_recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017);
    tree_new[i]->Branch("recotauh_sel_againstMuonLoose3",&_recotauh_sel_againstMuonLoose3);
    tree_new[i]->Branch("recotauh_sel_againstMuonTight3",&_recotauh_sel_againstMuonTight3);
    tree_new[i]->Branch("recotauh_sel_againstElectronVLooseMVA6",&_recotauh_sel_againstElectronVLooseMVA6);
    tree_new[i]->Branch("recotauh_sel_againstElectronLooseMVA6",&_recotauh_sel_againstElectronLooseMVA6);
    tree_new[i]->Branch("recotauh_sel_againstElectronMediumMVA6",&_recotauh_sel_againstElectronMediumMVA6);
    tree_new[i]->Branch("recotauh_sel_againstElectronTightMVA6",&_recotauh_sel_againstElectronTightMVA6);
    tree_new[i]->Branch("recotauh_sel_againstElectronVTightMVA6",&_recotauh_sel_againstElectronVTightMVA6);
    tree_new[i]->Branch("recotauh_sel_isGenMatched",&_recotauh_sel_isGenMatched);
    tree_new[i]->Branch("recotauh_sel_genMatchInd",&_recotauh_sel_genMatchInd);
    tree_new[i]->Branch("recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT);
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


  for (int i=skip_entries;i<skip_entries+nentries;i++) {

    h->Fill(1);

    if(i%10000==0) 
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
    _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_againstMuonLoose3.clear();
    _recotauh_sel_againstMuonTight3.clear();
    _recotauh_sel_againstElectronVLooseMVA6.clear();
    _recotauh_sel_againstElectronLooseMVA6.clear();
    _recotauh_sel_againstElectronMediumMVA6.clear();
    _recotauh_sel_againstElectronTightMVA6.clear();
    _recotauh_sel_againstElectronVTightMVA6.clear();
    _recotauh_sel_isGenMatched.clear();
    _recotauh_sel_genMatchInd.clear();
    _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
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
    _recomu_isfakeable = 0;  

    _recoele_e = 0;
    _recoele_px = 0;
    _recoele_py = 0;
    _recoele_pz = 0;
    _recoele_isfakeable = 0;

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
    _recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT = 0;
    _recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT = 0;
    _recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT = 0;

    tree->GetEntry(i);

    // number of fakeable electrons and muons for trigger matching
    int n_fakeable_mu = (*_recomu_e).size();
    int n_fakeable_ele = (*_recoele_e).size();

    //Trigger matching
    bool pass_e   = pass_trigger_list_1e(_triggerbit);
    bool pass_m   = pass_trigger_list_1m(_triggerbit);
    bool pass_2e  = pass_trigger_list_2e(_triggerbit); 
    bool pass_2m  = pass_trigger_list_2m(_triggerbit);
    bool pass_em  = pass_trigger_list_em(_triggerbit);
    bool pass_et  = pass_trigger_list_et(_triggerbit);
    bool pass_mt  = pass_trigger_list_mt(_triggerbit);
    bool pass_3e  = pass_trigger_list_3e(_triggerbit);
    bool pass_m2e = pass_trigger_list_m2e(_triggerbit);
    bool pass_2me = pass_trigger_list_e2m(_triggerbit);
    bool pass_3m  = pass_trigger_list_3m(_triggerbit);

    //MET filters
    bool pass_met_filter = pass_met_filters(_metfilterbit, isMC);
    if (!pass_met_filter) continue;

 
    // ***************** //
    // **** 1l+2tau **** //
    // ***************** //
    
    if(_n_recolep_fakeable>=1 && _n_recolep_mvasel<=1 && _n_recotauh>=2){  
           
      vector<TLorentzVector> loose_leptons;
      for(unsigned int i_mu=0; i_mu<(*_recomu_e).size(); i_mu++){
          TLorentzVector mu((*_recomu_px)[i_mu], (*_recomu_py)[i_mu], (*_recomu_pz)[i_mu], (*_recomu_e)[i_mu]);
          loose_leptons.push_back(mu);
      }
      for(unsigned int i_ele=0; i_ele<(*_recoele_e).size(); i_ele++){
          TLorentzVector ele((*_recoele_px)[i_ele], (*_recoele_py)[i_ele], (*_recoele_pz)[i_ele], (*_recoele_e)[i_ele]);
          loose_leptons.push_back(ele);
      }

      bool inv_mass_lep_pairs=true;
      for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
        TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
        for(unsigned int i_lep2=i_lep+1; i_lep2<(*_recolep_charge).size();i_lep2++){
          TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
          float m_ll = (lep1 + lep2).M();
          if(m_ll<12) inv_mass_lep_pairs=false;
        }
      }

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
          _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
          _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	        _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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

          _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
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
	      _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
	      _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
	      _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
	      _recotauh_sel_againstMuonLoose3.clear();
	      _recotauh_sel_againstMuonTight3.clear();
	      _recotauh_sel_againstElectronVLooseMVA6.clear();
	      _recotauh_sel_againstElectronLooseMVA6.clear();
	      _recotauh_sel_againstElectronMediumMVA6.clear();
	      _recotauh_sel_againstElectronTightMVA6.clear();
	      _recotauh_sel_againstElectronVTightMVA6.clear();
	      _recotauh_sel_isGenMatched.clear();
	      _recotauh_sel_genMatchInd.clear();
	      _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
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
	        _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	        _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
	        _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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
          
          _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	        _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	        _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    	
	      }	
      }

      bool passTriggerMatch = ( (pass_e && n_fakeable_ele>0 ) || (pass_et && n_fakeable_ele>0 ) || 
                                (pass_m && n_fakeable_mu>0 )  || (pass_mt && n_fakeable_mu>0 ) );

      _isGenMatched = true;
      if(isMC)
        _isGenMatched = _recolep_sel_isGenMatched[0] && _recotauh_sel_isGenMatched[0] && _recotauh_sel_isGenMatched[1];

      bool sig_1l2tau_base = passTriggerMatch &&
        (_n_recolep_fakeable>=1) &&
        ( (_recolep_sel_conept[0]>25 && abs(_recolep_sel_pdg[0])==13) || (_recolep_sel_conept[0]>30 && abs(_recolep_sel_pdg[0])==11) ) &&
        ((abs(_recolep_sel_eta[0]))<2.1) &&
        (_n_recolep_mvasel<=1) &&
        (_n_recotauh>=2) &&
        ( (_recotauh_sel_pt[0]>30) && (_recotauh_sel_pt[1]>20) ) &&
        (_n_recoPFJet>=3 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2) ) &&
        (inv_mass_lep_pairs);

      bool sig_1l2tau_SR = 
        sig_1l2tau_base &&
        (_recolep_sel_ismvasel[0]) &&
        (*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[0] && (*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[1] &&
        ((_recotauh_sel_charge[0]*_recotauh_sel_charge[1])<0) &&
        _isGenMatched;

      if (sig_1l2tau_SR) n_1l_2tau_SR = n_1l_2tau_SR + 1;

      bool sig_1l2tau_fake = 
        sig_1l2tau_base &&
        (!(_recolep_sel_ismvasel[0]) || !( (*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[0] && (*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[1] )) &&        
        ((_recotauh_sel_charge[0]*_recotauh_sel_charge[1])<0);

      if (sig_1l2tau_fake) n_1l_2tau_fake = n_1l_2tau_fake + 1;

      passTriggerMatch = false;
      
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

      bool passHLT1l = pass_m || pass_e;
      bool passHLT1l1tau = pass_et || pass_mt;

      _triggerSF_weight = triggerSF_ttH_1l(_recolep_sel_pt[0],_recolep_sel_eta[0],_recolep_sel_pdg[0],
					  _recotauh_sel_pt[0],_recotauh_sel_eta[0],_recotauh_sel_phi[0],
					  _recotauh_sel_pt[1],_recotauh_sel_eta[1],_recotauh_sel_phi[1],
					  passHLT1l, passHLT1l1tau );
      
      close_triggerSF_ttH_1l();
     
      if(_recolep_sel_ismvasel[0])
	      _leptonSF_ttH_weight = leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],3); //No tight-charge criteria for 1l2tau	      
      else
	      _leptonSF_ttH_weight = _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],3,0);

      if(isMC)
	      _tauSF_weight = (1-0.11*_recotauh_sel_isGenMatched[0])*(1-0.11*_recotauh_sel_isGenMatched[1]);
      
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

      if(!_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[0]){
	
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

      if(!_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[1]){

	      float weight_tau = _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT[1]/(1-_recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT[1]);

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

      if(sig_1l2tau_SR){
	      _category = 20;
	      tree_1l_2tau_SR->Fill();
      }

      else if(sig_1l2tau_fake){
        _category = 50;
	      tree_1l_2tau_fake->Fill();
      }

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
    _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_againstMuonLoose3.clear();
    _recotauh_sel_againstMuonTight3.clear();
    _recotauh_sel_againstElectronVLooseMVA6.clear();
    _recotauh_sel_againstElectronLooseMVA6.clear();
    _recotauh_sel_againstElectronMediumMVA6.clear();
    _recotauh_sel_againstElectronTightMVA6.clear();
    _recotauh_sel_againstElectronVTightMVA6.clear();
    _recotauh_sel_isGenMatched.clear();
    _recotauh_sel_genMatchInd.clear();
    _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();

    _n_fake_lep = 0;
    _n_fake_tau = 0;




    // *******************************
    // ****** 2lSS + 2lSS+1tau *******
    // *******************************

    if(_n_recolep_fakeable>=2 && _n_recolep_mvasel<=2){

      vector<TLorentzVector> loose_leptons;      
      for(unsigned int i_mu=0; i_mu<(*_recomu_e).size(); i_mu++){
        TLorentzVector mu((*_recomu_px)[i_mu], (*_recomu_py)[i_mu], (*_recomu_pz)[i_mu], (*_recomu_e)[i_mu]);
        loose_leptons.push_back(mu);
      }
      for(unsigned int i_ele=0; i_ele<(*_recoele_e).size(); i_ele++){
        TLorentzVector ele((*_recoele_px)[i_ele], (*_recoele_py)[i_ele], (*_recoele_pz)[i_ele], (*_recoele_e)[i_ele]);
        loose_leptons.push_back(ele);
      }

      bool inv_mass_lep_pairs=true;
      bool inv_mass_Zee=true;
      for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
        TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
        for(unsigned int i_lep2=i_lep+1; i_lep2<(*_recolep_charge).size();i_lep2++){
          TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
          float m_ll = (lep1 + lep2).M();
          if(m_ll<12) inv_mass_lep_pairs=false;
          if(abs((*_recolep_pdg)[i_lep])==11 && abs((*_recolep_pdg)[i_lep2])==11 && fabs(m_ll-91.2)<10) inv_mass_Zee=false;
        }
      }
	
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
	    }

      int n_tau_medium = 0;  
      bool tau = false;
      bool tau_fake = false;

      if (_n_recotauh>0){

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
            _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);

            if((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]>0.5) n_tau_medium = n_tau_medium + 1;

            _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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

            _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);

          }
        } 

        tau = _recotauh_sel_e.size()>=1;

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
          _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_againstMuonLoose3.clear();
          _recotauh_sel_againstMuonTight3.clear();
          _recotauh_sel_againstElectronVLooseMVA6.clear();
          _recotauh_sel_againstElectronLooseMVA6.clear();
          _recotauh_sel_againstElectronMediumMVA6.clear();
          _recotauh_sel_againstElectronTightMVA6.clear();
          _recotauh_sel_againstElectronVTightMVA6.clear();
          _recotauh_sel_isGenMatched.clear();
          _recotauh_sel_genMatchInd.clear();
          _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
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
            _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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
          
            _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
         
          } 

        }

        tau_fake = _recotauh_sel_e.size()>0;

      } 

      bool passTriggerMatch = (pass_e && n_fakeable_ele>0) || (pass_2e && n_fakeable_ele>1) ||
          (pass_m && n_fakeable_mu>0) || (pass_2m && n_fakeable_mu>1) ||
          (pass_em && n_fakeable_ele>0 && n_fakeable_mu>0);

      _isGenMatched = true;
      if(isMC)
        _isGenMatched = ((_recolep_sel_isGenMatched[0]) && (_recolep_sel_isGenMatched[1]));

      bool metLD = true;
      if(abs(_recolep_sel_pdg[0])==11 && abs(_recolep_sel_pdg[1])==11) metLD = (_ETmissLD>0.2); 

      //2lSS

      bool sig_2lSS_base = passTriggerMatch &&
        (_n_recolep_fakeable>=2) &&
        ((_recolep_sel_conept[0]>25) && (_recolep_sel_conept[1]>15)) &&
        (inv_mass_lep_pairs) &&
        (_n_recolep_mvasel<=2) &&
        (_recolep_sel_tightcharge[0] && _recolep_sel_tightcharge[1]) &&
        (!tau) && 
        (inv_mass_Zee) && 
        (metLD) &&
        (_n_recoPFJet>=4 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2) );

      bool sig_2lSS_SR = 
        sig_2lSS_base &&
        (_recolep_sel_charge[0]*_recolep_sel_charge[1]>0) && 
        (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) &&
        _isGenMatched;

      if (sig_2lSS_SR) n_2lSS_SR = n_2lSS_SR + 1;

      bool sig_2lSS_fake = 
        sig_2lSS_base &&
        (_recolep_sel_charge[0]*_recolep_sel_charge[1]>0) && 
        !(_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]);

      if (sig_2lSS_fake) n_2lSS_fake = n_2lSS_fake + 1;

      bool sig_2lSS_flip = 
        sig_2lSS_base &&
        (abs(_recolep_sel_pdg[0])==11 || abs(_recolep_sel_pdg[1])==11) &&
        (_recolep_sel_charge[0]*_recolep_sel_charge[1]<0) && 
        (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) &&
        _isGenMatched;

      if (sig_2lSS_flip) n_2lSS_flip = n_2lSS_flip + 1;


      //ttW CR

      bool sig_ttWctrl_SR = passTriggerMatch &&
        (_n_recolep_fakeable>=2) &&
        ((_recolep_sel_conept[0]>25) && (_recolep_sel_conept[1]>15)) &&
        (inv_mass_lep_pairs) &&
        (_n_recolep_mvasel<=2) &&
        (_recolep_sel_tightcharge[0] && _recolep_sel_tightcharge[1]) &&
        (!tau) && 
        (inv_mass_Zee) && 
        (metLD) &&
        (_n_recoPFJet==3 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2) ) &&
        (_recolep_sel_charge[0]*_recolep_sel_charge[1]>0) && 
        (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) &&
        _isGenMatched;

      if (sig_ttWctrl_SR) n_ttWctrl_SR = n_ttWctrl_SR + 1;

      bool sig_ttWctrl_fake = passTriggerMatch &&
        (_n_recolep_fakeable>=2) &&
        ((_recolep_sel_conept[0]>25) && (_recolep_sel_conept[1]>15)) &&
        (inv_mass_lep_pairs) &&
        (_n_recolep_mvasel<=2) &&
        (_recolep_sel_tightcharge[0] && _recolep_sel_tightcharge[1]) &&
        (!tau) && 
        (inv_mass_Zee) && 
        (metLD) &&
        (_n_recoPFJet==3 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2) ) &&
        (_recolep_sel_charge[0]*_recolep_sel_charge[1]>0) && 
        !(_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) &&
        _isGenMatched;

      if (sig_ttWctrl_fake) n_ttWctrl_fake = n_ttWctrl_fake + 1;

      bool sig_ttWctrl_flip = passTriggerMatch &&
        (_n_recolep_fakeable>=2) &&
        ((_recolep_sel_conept[0]>25) && (_recolep_sel_conept[1]>15)) &&
        (inv_mass_lep_pairs) &&
        (_n_recolep_mvasel<=2) &&
        (_recolep_sel_tightcharge[0] && _recolep_sel_tightcharge[1]) &&
        (!tau) && 
        (inv_mass_Zee) && 
        (metLD) &&
        (_n_recoPFJet==3 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2) ) &&
        (_recolep_sel_charge[0]*_recolep_sel_charge[1]<0) && 
        (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) &&
        _isGenMatched &&
        (abs(_recolep_sel_pdg[0])==11 || abs(_recolep_sel_pdg[1])==11);

      if (sig_ttWctrl_flip) n_ttWctrl_flip = n_ttWctrl_flip + 1;

      //2lSS+1tau

      bool sig_2lSS1tau_base = false;
      bool sig_2lSS1tau_SR = false;
      bool sig_2lSS1tau_fake = false;
      bool sig_2lSS1tau_flip = false;

      if (_n_recotauh>0){

        sig_2lSS1tau_base = passTriggerMatch &&
          (_n_recolep_fakeable>=2) &&
          ((_recolep_sel_conept[0]>25) && ((_recolep_sel_conept[1]>10 && abs(_recolep_sel_pdg[1])==13) || (_recolep_sel_conept[1]>15 && abs(_recolep_sel_pdg[1])==11))) &&
          (inv_mass_lep_pairs) &&
          (_n_recolep_mvasel<=2) &&
          (_recolep_sel_tightcharge[0] && _recolep_sel_tightcharge[1]) &&
          (_n_recotauh>0) &&
          (n_tau_medium<=1) &&
          (inv_mass_Zee) && 
          (metLD) &&
          (_n_recoPFJet>=3 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2) ) &&
          (_recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0]);

        sig_2lSS1tau_SR = 
          sig_2lSS1tau_base &&
          (_recolep_sel_charge[0]*_recolep_sel_charge[1]>0) && 
          (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) &&
          (_recolep_sel_charge[0]*_recotauh_sel_charge[0]<0) &&
          _isGenMatched;

        if (sig_2lSS1tau_SR) n_2lSS_1tau_SR = n_2lSS_1tau_SR + 1;

        sig_2lSS1tau_fake = 
          sig_2lSS1tau_base &&
          (_recolep_sel_charge[0]*_recolep_sel_charge[1]>0) && 
          !(_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) &&
          (_recolep_sel_charge[0]*_recotauh_sel_charge[0]<0);

        if (sig_2lSS1tau_fake) n_2lSS_1tau_fake = n_2lSS_1tau_fake + 1;

        bool pt_lep_2l1tau = ((_recolep_sel_conept[0]>25 && abs(_recolep_sel_pdg[0])==13) || (_recolep_sel_conept[0]>25 && abs(_recolep_sel_pdg[0])==11)) && ((_recolep_sel_conept[1]>10 && abs(_recolep_sel_pdg[1])==13) || (_recolep_sel_conept[1]>15 && abs(_recolep_sel_pdg[1])==11));
        bool lep_quality = _recolep_sel_tightcharge[0] && _recolep_sel_tightcharge[1];
        bool taus_overlap = (n_tau_medium <= 1);
        bool jetmult_sig = _n_recoPFJet>=3 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2);
        bool elecharge = (abs((_recolep_sel_pdg)[0])==11 && (_recolep_sel_charge)[0]*(_recotauh_sel_charge)[0]>0) || (abs((_recolep_sel_pdg)[1])==11 && (_recolep_sel_charge)[1]*(_recotauh_sel_charge)[0]>0);  
        bool tight_mvasel = _recolep_sel_ismvasel[0]==1 && _recolep_sel_ismvasel[1]==1;
        bool SS_lep = _recolep_sel_charge[0]*_recolep_sel_charge[1]>0;
        bool SS_taulep = _recolep_sel_charge[0]*_recotauh_sel_charge[0]>0 || _recolep_sel_charge[1]*_recotauh_sel_charge[0]>0 ;
        bool ele = (abs(_recolep_sel_pdg[0])==11 || abs(_recolep_sel_pdg[1])==11);

        sig_2lSS1tau_flip = passTriggerMatch &&
          (*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[0]>0.5 && 
          pt_lep_2l1tau && 
          inv_mass_Zee && 
          inv_mass_lep_pairs && 
          lep_quality && 
          taus_overlap && 
          metLD && 
          jetmult_sig && 
          tight_mvasel && 
          !SS_lep && 
          SS_taulep && 
          ele && 
          elecharge && 
          _isGenMatched; 

        if (sig_2lSS1tau_flip) n_2lSS_1tau_flip = n_2lSS_1tau_flip + 1;

      }

      passTriggerMatch = false;

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

      _triggerSF_weight = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2);
      _triggerSF_weight_up = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2,+1);
      _triggerSF_weight_down = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2,-1);


      if(_recolep_sel_ismvasel[0])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2,0);

      if(_recolep_sel_ismvasel[1])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2,0);
  

      if(isMC && tau_fake)
        _tauSF_weight = (1-0.11*_recotauh_sel_isGenMatched[0]);

	
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

	      if(!_recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0]){
	        
          float weight_tau = _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT[0]/(1-_recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT[0]);

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

	    //MuMu
	    else if(abs(_recolep_sel_pdg[0])==13 && abs(_recolep_sel_pdg[1])==13){
	    
	      if(_n_recoPFJet_btag_medium>=2){
	       
	        if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	          if(sig_2lSS_SR)
	   	        _category = 1;
	          else if (sig_2lSS_fake)
	   	        _category = 31;
	        }
	       
	        else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	          if(sig_2lSS_SR)
	   	        _category = 2;
	          else if (sig_2lSS_fake)
	   	        _category = 32;
	        }
	       
	        else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0){
            if(sig_2lSS_flip)
	            _category = -1;
          }
	       
	      }
	     
	      else{
	       
	        if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	          if(sig_2lSS_SR)
	   	        _category = 3;
	          else if (sig_2lSS_fake)
	   	        _category = 33;
	        }
	       
	        else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	          if(sig_2lSS_SR)
	   	        _category = 4;
	          else if (sig_2lSS_fake)
	   	        _category = 34;
	        }
	       
	        else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0){
            if(sig_2lSS_flip)
              _category = -3;
          }    
	      }
	    }
	   
	    //EMu
	    else if((abs(_recolep_sel_pdg[0])==13 && abs(_recolep_sel_pdg[1])==11) || (abs(_recolep_sel_pdg[0])==11 && abs(_recolep_sel_pdg[1])==13)){
	    
	      if(_n_recoPFJet_btag_medium>=2){
	       
	        if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	          if(sig_2lSS_SR)
	   	        _category = 5;
	          else if (sig_2lSS_fake)
		          _category = 35;
	        }
	    
	        else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	          if(sig_2lSS_SR)
		          _category = 6;
	          else if (sig_2lSS_fake)
		          _category = 36;
	        }
	    
	        else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0){
            if (sig_2lSS_flip){
              if(_recolep_sel_pdg[0]==-13 || _recolep_sel_pdg[1]==-13)
                _category = -5;
              else if(_recolep_sel_pdg[0]==13 || _recolep_sel_pdg[1]==13)
                _category = -6;
            }  
	        }
	      }
	  
	      else{
	    
	        if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	          if(sig_2lSS_SR)
		          _category = 7;
	          else if (sig_2lSS_fake)
		          _category = 37;
	        }
	    
	        else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	          if(sig_2lSS_SR)
		          _category = 8;
	          else if (sig_2lSS_fake)
		          _category = 38;
	        }
	    
	        else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0){
            if(sig_2lSS_flip){
	            if(_recolep_sel_pdg[0]==-13 || _recolep_sel_pdg[1]==-13)
		            _category = -7;
	            else if(_recolep_sel_pdg[0]==13 || _recolep_sel_pdg[1]==13)
		            _category = -8;
            }
	        }
	      }
	    }
	
	    //EE
	    else if(abs(_recolep_sel_pdg[0])==11 && abs(_recolep_sel_pdg[1])==11){
	 
	      if(_recolep_sel_charge[0]+_recolep_sel_charge[1]>0){
	        if(sig_2lSS_SR)
	          _category = 9;
	        else if (sig_2lSS_fake)
	          _category = 39;
	      }
	  
	      else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]<0){
	        if(sig_2lSS_SR)
	          _category = 10;
	        else if (sig_2lSS_fake)
	          _category = 40;
	      }
	  
	      else if(_recolep_sel_charge[0]+_recolep_sel_charge[1]==0){
          if(sig_2lSS_flip){ 
	          if(_recolep_sel_charge[0]>0)
	            _category = -9;
	          else
	           _category = -10;
          }
	      }
	    }
	

      if(sig_2lSS_SR){
        tree_2lSS_SR->Fill();
      }

      else if(sig_2lSS_fake){
        tree_2lSS_fake->Fill();
      }

      else if(sig_2lSS_flip){
        tree_2lSS_flip->Fill();
      }

	    if(sig_2lSS1tau_SR){
        _category = 11;
        tree_2lSS_1tau_SR->Fill();
      }

      else if(sig_2lSS1tau_fake){
        _category = 41;
        tree_2lSS_1tau_fake->Fill();
      }

      else if(sig_2lSS1tau_flip){
        _category = -11;
        tree_2lSS_1tau_flip->Fill();
      }

      else if(sig_ttWctrl_SR){
        tree_ttWctrl_SR->Fill();
      }

      else if(sig_ttWctrl_fake){
        tree_ttWctrl_fake->Fill();
      }

      else if(sig_ttWctrl_flip){
        tree_ttWctrl_flip->Fill();
      }

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
    _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_againstMuonLoose3.clear();
    _recotauh_sel_againstMuonTight3.clear();
    _recotauh_sel_againstElectronVLooseMVA6.clear();
    _recotauh_sel_againstElectronLooseMVA6.clear();
    _recotauh_sel_againstElectronMediumMVA6.clear();
    _recotauh_sel_againstElectronTightMVA6.clear();
    _recotauh_sel_againstElectronVTightMVA6.clear();
    _recotauh_sel_isGenMatched.clear();
    _recotauh_sel_genMatchInd.clear();
    _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
      
    _n_fake_lep = 0;
    _n_fake_tau = 0;




    // ****************** 
    // **** 2l+2taus ****
    // ****************** 

    if(_n_recolep_fakeable>=2 && _n_recotauh>=2){     
     
      vector<TLorentzVector> loose_leptons;
      for(unsigned int i_mu=0; i_mu<(*_recomu_e).size(); i_mu++){
	      TLorentzVector mu((*_recomu_px)[i_mu], (*_recomu_py)[i_mu], (*_recomu_pz)[i_mu], (*_recomu_e)[i_mu]);
	      loose_leptons.push_back(mu);
      }
      for(unsigned int i_ele=0; i_ele<(*_recoele_e).size(); i_ele++){
	      TLorentzVector ele((*_recoele_px)[i_ele], (*_recoele_py)[i_ele], (*_recoele_pz)[i_ele], (*_recoele_e)[i_ele]);
	      loose_leptons.push_back(ele);
      }

      bool inv_mass_lep_pairs=true;
      bool inv_mass_Z=true;
      bool SFOS_pair=false;
      for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
        TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
        for(unsigned int i_lep2=i_lep+1; i_lep2<(*_recolep_charge).size();i_lep2++){
          TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
          float m_ll = (lep1 + lep2).M();
          if(m_ll<12) inv_mass_lep_pairs=false;
          if((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep2]){
            SFOS_pair=true;
            if(fabs(m_ll-91.2)<10) inv_mass_Z=false;
          }
        }
      }
         
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
          _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
          _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
          _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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
     
          _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]); 
          _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
          _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);

        }
      }   

      bool tau = _recotauh_sel_e.size()>=2; //at least two taus pass medium

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
  	    _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
  	    _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
  	    _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
  	    _recotauh_sel_againstMuonLoose3.clear();
  	    _recotauh_sel_againstMuonTight3.clear();
  	    _recotauh_sel_againstElectronVLooseMVA6.clear();
  	    _recotauh_sel_againstElectronLooseMVA6.clear();
  	    _recotauh_sel_againstElectronMediumMVA6.clear();
  	    _recotauh_sel_againstElectronTightMVA6.clear();
  	    _recotauh_sel_againstElectronVTightMVA6.clear();
  	    _recotauh_sel_isGenMatched.clear();
  	    _recotauh_sel_genMatchInd.clear();
        _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
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
          _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
          _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
          _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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
  
          _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]); 
          _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
          _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
        
        } 
      }

      bool tau_fake = _recotauh_sel_e.size()>0;

      bool passTriggerMatch = ((pass_e || pass_et) && n_fakeable_ele>0) ||
           ((pass_m || pass_mt) && n_fakeable_mu>0) ||
           (pass_2e && n_fakeable_ele>1) || (pass_2m && n_fakeable_mu>1) ||
           (pass_em && n_fakeable_ele>0 && n_fakeable_mu>0);

      bool metLD = true;
      if (_n_recoPFJet<=3){
        if(SFOS_pair) metLD = _ETmissLD>0.3;
        else if (!SFOS_pair) metLD = _ETmissLD>0.2;
      }

      _isGenMatched = true;
      if(isMC)
        _isGenMatched = _recolep_sel_isGenMatched[0] && _recolep_sel_isGenMatched[1] && _recotauh_sel_isGenMatched[0] && _recotauh_sel_isGenMatched[1];


      bool sig_2l2tau_base = passTriggerMatch &&
        (_n_recolep_fakeable>=2) &&
        ((_recolep_sel_conept[0]>25) && ((_recolep_sel_conept[1]>10 && abs(_recolep_sel_pdg[1])==13) || (_recolep_sel_conept[1]>15 && abs(_recolep_sel_pdg[1])==11))) &&
        (inv_mass_lep_pairs) &&
        (inv_mass_Z) && 
        (_n_recotauh>=2) &&
        (metLD) &&
        (_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recotauh_sel_charge[0]+_recotauh_sel_charge[1])==0 &&
        _n_recoPFJet>=2 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2);

      bool sig_2l2tau_SR = 
        sig_2l2tau_base &&
        (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) &&
        (_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[0] && _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[1]) &&
        _isGenMatched;

      if (sig_2l2tau_SR) n_2l_2tau_SR = n_2l_2tau_SR + 1;

      bool sig_2l2tau_fake = 
        sig_2l2tau_base &&
        (!(_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1]) || !(_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[0] && _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[1]));
    
      if (sig_2l2tau_fake) n_2l_2tau_fake = n_2l_2tau_fake + 1;

      passTriggerMatch = false;

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

      _triggerSF_weight = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2);
      _triggerSF_weight_up = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2,+1);
      _triggerSF_weight_down = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2,-1);


      if(_recolep_sel_ismvasel[0])
          _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);
      else
          _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2,0);

      if(_recolep_sel_ismvasel[1])
          _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);
      else
          _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2,0);


      if(isMC)
          _tauSF_weight = (1-0.11*_recotauh_sel_isGenMatched[0])*(1-0.11*_recotauh_sel_isGenMatched[1]);


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

        if(!_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[0]){

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

        if(!_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[1]){

          float weight_tau = _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT[1]/(1-_recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT[1]);
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

     
      if(sig_2l2tau_SR){
        _category = 21;
        tree_2l_2tau_SR->Fill();
      }

      else if(sig_2l2tau_fake){
        _category = 51;
        tree_2l_2tau_fake->Fill();
      }

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
    _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_againstMuonLoose3.clear();
    _recotauh_sel_againstMuonTight3.clear();
    _recotauh_sel_againstElectronVLooseMVA6.clear();
    _recotauh_sel_againstElectronLooseMVA6.clear();
    _recotauh_sel_againstElectronMediumMVA6.clear();
    _recotauh_sel_againstElectronTightMVA6.clear();
    _recotauh_sel_againstElectronVTightMVA6.clear();
    _recotauh_sel_isGenMatched.clear();
    _recotauh_sel_genMatchInd.clear();
    _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
 
    _n_fake_lep = 0;
    _n_fake_tau = 0;
     



    // ************************
    // **** 3l and 3l+1tau ****
    // ************************ 

    if(_n_recolep_fakeable>=3 && _n_recolep_mvasel<=3){

      vector<TLorentzVector> loose_leptons;
      for(unsigned int i_mu=0; i_mu<(*_recomu_e).size(); i_mu++){
        TLorentzVector mu((*_recomu_px)[i_mu], (*_recomu_py)[i_mu], (*_recomu_pz)[i_mu], (*_recomu_e)[i_mu]);
        loose_leptons.push_back(mu);
      }
      for(unsigned int i_ele=0; i_ele<(*_recoele_e).size(); i_ele++){
        TLorentzVector ele((*_recoele_px)[i_ele], (*_recoele_py)[i_ele], (*_recoele_pz)[i_ele], (*_recoele_e)[i_ele]);
        loose_leptons.push_back(ele);
      }

      bool inv_mass_lep_pairs=true;
      bool inv_mass_Z=true;
      bool SFOS_pair=false;
      for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
        TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
        for(unsigned int i_lep2=i_lep+1; i_lep2<(*_recolep_charge).size();i_lep2++){
          TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
          float m_ll = (lep1 + lep2).M();
          if(m_ll<12) inv_mass_lep_pairs=false;
          if((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep2]){
            SFOS_pair=true;
            if(fabs(m_ll-91.2)<10) inv_mass_Z=false;
          }
        }
      }

      bool inv_mass_4l=true;
      bool SFOS_doublepair=false;
      float m_4l = 0;      
      if (loose_leptons.size()>=4){
        for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
          TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
          for(unsigned int i_lep2=i_lep+1; i_lep2<loose_leptons.size(); i_lep2++){
            TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
            for(unsigned int i_lep3=i_lep+2; i_lep3<loose_leptons.size(); i_lep3++){
              TLorentzVector lep3((*_recolep_px)[i_lep3],(*_recolep_py)[i_lep3],(*_recolep_pz)[i_lep3],(*_recolep_e)[i_lep3]);
              for(unsigned int i_lep4=i_lep+3; i_lep4<loose_leptons.size(); i_lep4++){
                TLorentzVector lep4((*_recolep_px)[i_lep4],(*_recolep_py)[i_lep4],(*_recolep_pz)[i_lep4],(*_recolep_e)[i_lep4]);
                if( (i_lep != i_lep2) && (i_lep != i_lep3) && (i_lep != i_lep4) && (i_lep2 != i_lep3) && (i_lep2 != i_lep4) && (i_lep3 != i_lep4)){ 
                  if( ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep2] && (*_recolep_pdg)[i_lep3]==-(*_recolep_pdg)[i_lep4])
                    || ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep3] && (*_recolep_pdg)[i_lep2]==-(*_recolep_pdg)[i_lep4]) 
                    || ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep4] && (*_recolep_pdg)[i_lep2]==-(*_recolep_pdg)[i_lep3])) {
                    m_4l = (lep1 + lep2 + lep3 + lep4).M();
                    SFOS_doublepair=true;
                    if(m_4l<140) {
                      inv_mass_4l=false;
                      break;                  
                    }
                  }
                }  
              }
            }
          }
        }
      }

  
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
          _recolep_sel_tightcharge.push_back((*_recolep_tightcharge)[i_lep]);

          if(isMC){
            _recolep_sel_isGenMatched.push_back((*_recolep_isGenMatched)[i_lep]);
            _recolep_sel_genMatchInd.push_back((*_recolep_genMatchInd)[i_lep]);
          }

        }
      }

      bool tau = false;
      bool tau_fake = false;

      if (_n_recotauh>0){

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
            _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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

            _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);

          }
        } 

        tau = _recotauh_sel_e.size()>=1;

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
          _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_againstMuonLoose3.clear();
          _recotauh_sel_againstMuonTight3.clear();
          _recotauh_sel_againstElectronVLooseMVA6.clear();
          _recotauh_sel_againstElectronLooseMVA6.clear();
          _recotauh_sel_againstElectronMediumMVA6.clear();
          _recotauh_sel_againstElectronTightMVA6.clear();
          _recotauh_sel_againstElectronVTightMVA6.clear();
          _recotauh_sel_isGenMatched.clear();
          _recotauh_sel_genMatchInd.clear();
          _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
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
            _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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
          
            _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
         
          } 

        }

        tau_fake = _recotauh_sel_e.size()>0;

      } 

      bool metLD = true;
      if (_n_recoPFJet<=3){
        if(SFOS_pair) metLD = _ETmissLD>0.3;
        else if (!SFOS_pair) metLD = _ETmissLD>0.2;
      }

      bool passTriggerMatch = (pass_e && n_fakeable_ele>0) || (pass_2e && n_fakeable_ele>1) ||
                              (pass_m && n_fakeable_mu>0) || (pass_2m && n_fakeable_mu>1) ||
                              (pass_em && n_fakeable_ele>0 && n_fakeable_mu>0) ||
                              (pass_3e && n_fakeable_ele>2) || (pass_3m && n_fakeable_mu>2) ||
                              (pass_m2e && n_fakeable_ele>1 && n_fakeable_mu>0) ||
                              (pass_2me && n_fakeable_ele>0 && n_fakeable_mu>1);

      _isGenMatched = true;
      if(isMC)
        _isGenMatched = ((_recolep_sel_isGenMatched[0]) && (_recolep_sel_isGenMatched[1]) && (_recolep_sel_isGenMatched[2]) );


      // 3l
      bool sig_3l_base = passTriggerMatch &&
        (_n_recolep_fakeable>=3) &&
        (_recolep_sel_conept[0]>25 && _recolep_sel_conept[1]>15 && _recolep_sel_conept[2]>10) &&
        inv_mass_lep_pairs &&
        inv_mass_Z &&
        (!tau) &&
        metLD &&
        abs(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2])==1 &&
        (_n_recoPFJet>=2 && (_n_recoPFJet_btag_loose>=2 || _n_recoPFJet_btag_medium>=1)) &&
        inv_mass_4l && 
        (_n_recolep_mvasel<=3);

      bool sig_3l_SR = 
        sig_3l_base &&
        (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1] && _recolep_sel_ismvasel[2]) &&
        _isGenMatched;

      if (sig_3l_SR) n_3l_SR = n_3l_SR + 1;

      bool sig_3l_fake = 
        sig_3l_base &&
        !(_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1] && _recolep_sel_ismvasel[2]);

      if (sig_3l_fake) n_3l_fake = n_3l_fake + 1;

      bool sig_3l1tau_base = false;
      bool sig_3l1tau_SR = false;
      bool sig_3l1tau_fake = false;

      if (_n_recotauh>0){

        bool sig_3l1tau_base = passTriggerMatch &&
          (_n_recolep_fakeable>=3) &&
          (_recolep_sel_conept[0]>25 && _recolep_sel_conept[1]>10 && _recolep_sel_conept[2]>10) &&
          inv_mass_lep_pairs &&
          inv_mass_Z &&
          metLD &&
          abs(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2]+_recotauh_sel_charge[0])==0 &&
          (_n_recoPFJet>=2 && (_n_recoPFJet_btag_loose>=2 || _n_recoPFJet_btag_medium>=1)) &&
          (*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[0]>0.5; //added last minute;

        bool sig_3l1tau_SR = 
          sig_3l1tau_base &&
          (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1] && _recolep_sel_ismvasel[2]) &&
          _isGenMatched;

        if (sig_3l1tau_SR) n_3l_1tau_SR = n_3l_1tau_SR + 1;

        bool sig_3l1tau_fake = 
          sig_3l1tau_base &&
          !(_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1] && _recolep_sel_ismvasel[2]);

        if (sig_3l1tau_fake) n_3l_1tau_fake = n_3l_1tau_fake + 1;

      }

      passTriggerMatch = false;

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

      _triggerSF_weight = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2);
      _triggerSF_weight_up = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2,+1);
      _triggerSF_weight_down = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2,-1);


      if(_recolep_sel_ismvasel[0])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2,0);

      if(_recolep_sel_ismvasel[1])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2,0);

      if(_recolep_sel_ismvasel[2])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],2,0);


      if(isMC && tau_fake)
        _tauSF_weight = (1-0.11*_recotauh_sel_isGenMatched[0]);

  
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
        _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[2]/(1-_recolep_sel_fakerate_QCD_MC[2]);
        _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[2]/(1-_recolep_sel_fakerate_ttbar_MC[2]);

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

        if(!_recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0]){
          
          float weight_tau = _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT[0]/(1-_recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT[0]);
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
        

      if (sig_3l1tau_SR){
        _category = 16;
        tree_3l_1tau_SR->Fill();
      }

      if (sig_3l1tau_fake){
        _category = 46;
        tree_3l_1tau_fake->Fill();
      }
      
      
      if(_n_recoPFJet_btag_medium>=2){
      
        if(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2]>0){
          if(sig_3l_SR)
            _category = 12;
          else if(sig_3l_fake)
            _category = 42;
        }
      
        else{
          if(sig_3l_SR)
            _category = 13;
          else if(sig_3l_fake)
            _category = 43;
        }
      
      }
  
      else{
      
        if(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2]>0){
          if(sig_3l_SR)
            _category = 14;
          else if(sig_3l_fake)
            _category = 44;
        }
      
        else{
          if(sig_3l_SR)
            _category = 15;
          else
            _category = 45;
        }
      
      } 

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
    _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_againstMuonLoose3.clear();
    _recotauh_sel_againstMuonTight3.clear();
    _recotauh_sel_againstElectronVLooseMVA6.clear();
    _recotauh_sel_againstElectronLooseMVA6.clear();
    _recotauh_sel_againstElectronMediumMVA6.clear();
    _recotauh_sel_againstElectronTightMVA6.clear();
    _recotauh_sel_againstElectronVTightMVA6.clear();
    _recotauh_sel_isGenMatched.clear();
    _recotauh_sel_genMatchInd.clear();
    _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
      
    _n_fake_lep = 0;
    _n_fake_tau = 0;




    // ************************
    // ******** ttZ CR ********
    // ************************ 


    if(_n_recolep_fakeable>=3){

      vector<TLorentzVector> loose_leptons;    
      for(unsigned int i_mu=0; i_mu<(*_recomu_e).size(); i_mu++){
        TLorentzVector mu((*_recomu_px)[i_mu], (*_recomu_py)[i_mu], (*_recomu_pz)[i_mu], (*_recomu_e)[i_mu]);
        loose_leptons.push_back(mu);
      }
      for(unsigned int i_ele=0; i_ele<(*_recoele_e).size(); i_ele++){
        TLorentzVector ele((*_recoele_px)[i_ele], (*_recoele_py)[i_ele], (*_recoele_pz)[i_ele], (*_recoele_e)[i_ele]);
        loose_leptons.push_back(ele);
      }

      bool inv_mass_lep_pairs=true;      
      bool SFOS_pair=false;
      bool inv_mass_Z=true;
      for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
        TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
        for(unsigned int i_lep2=i_lep+1; i_lep2<(*_recolep_charge).size();i_lep2++){
          TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
          float m_ll = (lep1 + lep2).M();
          if(m_ll<12) inv_mass_lep_pairs=false;
          if((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep2]){
            SFOS_pair=true;
            if(fabs(m_ll-91.2)<10) inv_mass_Z=false;
          }
        }
      }

      bool inv_mass_4l=true;
      bool SFOS_doublepair=false;
      float m_4l = 0;      
      if (loose_leptons.size()>=4){
        for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
          TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
          for(unsigned int i_lep2=i_lep+1; i_lep2<loose_leptons.size(); i_lep2++){
            TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
            for(unsigned int i_lep3=i_lep+2; i_lep3<loose_leptons.size(); i_lep3++){
              TLorentzVector lep3((*_recolep_px)[i_lep3],(*_recolep_py)[i_lep3],(*_recolep_pz)[i_lep3],(*_recolep_e)[i_lep3]);
              for(unsigned int i_lep4=i_lep+3; i_lep4<loose_leptons.size(); i_lep4++){
                TLorentzVector lep4((*_recolep_px)[i_lep4],(*_recolep_py)[i_lep4],(*_recolep_pz)[i_lep4],(*_recolep_e)[i_lep4]);
                if( (i_lep != i_lep2) && (i_lep != i_lep3) && (i_lep != i_lep4) && (i_lep2 != i_lep3) && (i_lep2 != i_lep4) && (i_lep3 != i_lep4)){ 
                  if( ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep2] && (*_recolep_pdg)[i_lep3]==-(*_recolep_pdg)[i_lep4])
                    || ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep3] && (*_recolep_pdg)[i_lep2]==-(*_recolep_pdg)[i_lep4]) 
                    || ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep4] && (*_recolep_pdg)[i_lep2]==-(*_recolep_pdg)[i_lep3])) {
                    m_4l = (lep1 + lep2 + lep3 + lep4).M();
                    SFOS_doublepair=true;
                    if(m_4l<140) {
                      inv_mass_4l=false;
                      break;                  
                    }
                  }
                }  
              }
            }
          }
        }
      }
  
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
          _recolep_sel_tightcharge.push_back((*_recolep_tightcharge)[i_lep]);

          if(isMC){
            _recolep_sel_isGenMatched.push_back((*_recolep_isGenMatched)[i_lep]);
            _recolep_sel_genMatchInd.push_back((*_recolep_genMatchInd)[i_lep]);
          }

        }
      }

      bool tau = false;
      bool tau_fake = false;

      if (_n_recotauh>0){

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
            _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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

            _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);

          }
        } 

        tau = _recotauh_sel_e.size()>=1;

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
          _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
          _recotauh_sel_againstMuonLoose3.clear();
          _recotauh_sel_againstMuonTight3.clear();
          _recotauh_sel_againstElectronVLooseMVA6.clear();
          _recotauh_sel_againstElectronLooseMVA6.clear();
          _recotauh_sel_againstElectronMediumMVA6.clear();
          _recotauh_sel_againstElectronTightMVA6.clear();
          _recotauh_sel_againstElectronVTightMVA6.clear();
          _recotauh_sel_isGenMatched.clear();
          _recotauh_sel_genMatchInd.clear();
          _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
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
            _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
            _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.push_back((*_recotauh_byTightIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]);
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
          
            _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
            _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
         
          } 

        }

        tau_fake = _recotauh_sel_e.size()>0;

      } 

      bool metLD = true;
      if (_n_recoPFJet<=3){
        if(SFOS_pair) metLD = _ETmissLD>0.3;
        else if (!SFOS_pair) metLD = _ETmissLD>0.2;
      }

      bool passTriggerMatch = (pass_e && n_fakeable_ele>0) || (pass_2e && n_fakeable_ele>1) ||
                              (pass_m && n_fakeable_mu>0) || (pass_2m && n_fakeable_mu>1) ||
                              (pass_em && n_fakeable_ele>0 && n_fakeable_mu>0) ||
                              (pass_3e && n_fakeable_ele>2) || (pass_3m && n_fakeable_mu>2) ||
                              (pass_m2e && n_fakeable_ele>1 && n_fakeable_mu>0) ||
                              (pass_2me && n_fakeable_ele>0 && n_fakeable_mu>1);

      _isGenMatched = true;
      if(isMC)
        _isGenMatched = ((_recolep_sel_isGenMatched[0]) && (_recolep_sel_isGenMatched[1]) && (_recolep_sel_isGenMatched[2]) );

      //ttZ CR
      bool sig_ttZctrl_SR = passTriggerMatch &&
        (_n_recolep_fakeable>=3) &&
        (_recolep_sel_conept[0]>25 && _recolep_sel_conept[1]>15 && _recolep_sel_conept[2]>10) &&
        inv_mass_lep_pairs &&
        !inv_mass_Z &&
        metLD &&
        abs(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2])==1 &&
        (_n_recoPFJet>=2 && (_n_recoPFJet_btag_loose>=2 || _n_recoPFJet_btag_medium>=1)) &&
        (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1] && _recolep_sel_ismvasel[2]) &&
        _isGenMatched;

      if (sig_ttZctrl_SR) n_ttZctrl_SR = n_ttZctrl_SR + 1;

      bool sig_ttZctrl_fake = passTriggerMatch &&
        (_n_recolep_fakeable>=3) &&
        (_recolep_sel_conept[0]>25 && _recolep_sel_conept[1]>15 && _recolep_sel_conept[2]>10) &&
        inv_mass_lep_pairs &&
        !inv_mass_Z &&
        metLD &&
        abs(_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2])==1 &&
        (_n_recoPFJet>=2 && (_n_recoPFJet_btag_loose>=2 || _n_recoPFJet_btag_medium>=1)) &&
        !(_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1] && _recolep_sel_ismvasel[2]) &&
        _isGenMatched;

      if (sig_ttZctrl_fake) n_ttZctrl_fake = n_ttZctrl_fake + 1;

      passTriggerMatch = false;

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


      _triggerSF_weight = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2);
      _triggerSF_weight_up = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2,+1);
      _triggerSF_weight_down = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],2,-1);


      if(_recolep_sel_ismvasel[0])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2,0);

      if(_recolep_sel_ismvasel[1])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2,0);

      if(_recolep_sel_ismvasel[2])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],2,0);


      if(isMC && tau_fake)
        _tauSF_weight = (1-0.11*_recotauh_sel_isGenMatched[0]);

  
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
        _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[2]/(1-_recolep_sel_fakerate_QCD_MC[2]);
        _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[2]/(1-_recolep_sel_fakerate_ttbar_MC[2]);

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

        if(!_recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0]){
          
          float weight_tau = _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT[0]/(1-_recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT[0]);
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

      if(sig_ttZctrl_SR){
        tree_ttZctrl_SR->Fill(); 
      }

      if(sig_ttZctrl_fake){
        tree_ttZctrl_fake->Fill();
      }

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
    _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_byTightIsolationMVArun2v2DBdR03oldDMwLT2017.clear();
    _recotauh_sel_againstMuonLoose3.clear();
    _recotauh_sel_againstMuonTight3.clear();
    _recotauh_sel_againstElectronVLooseMVA6.clear();
    _recotauh_sel_againstElectronLooseMVA6.clear();
    _recotauh_sel_againstElectronMediumMVA6.clear();
    _recotauh_sel_againstElectronTightMVA6.clear();
    _recotauh_sel_againstElectronVTightMVA6.clear();
    _recotauh_sel_isGenMatched.clear();
    _recotauh_sel_genMatchInd.clear();
    _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.clear();
    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.clear();
      
    _n_fake_lep = 0;
    _n_fake_tau = 0;

    



    // *******************
    // ******* 4l ********
    // *******************    
    
    if(_n_recolep_fakeable>=4){  
                 
      vector<TLorentzVector> loose_leptons;
      for(unsigned int i_mu=0; i_mu<(*_recomu_e).size(); i_mu++){
        TLorentzVector mu((*_recomu_px)[i_mu], (*_recomu_py)[i_mu], (*_recomu_pz)[i_mu], (*_recomu_e)[i_mu]);
        loose_leptons.push_back(mu);
      }
      for(unsigned int i_ele=0; i_ele<(*_recoele_e).size(); i_ele++){
        TLorentzVector ele((*_recoele_px)[i_ele], (*_recoele_py)[i_ele], (*_recoele_pz)[i_ele], (*_recoele_e)[i_ele]);
        loose_leptons.push_back(ele);
      }

      bool inv_mass_lep_pairs=true;
      bool inv_mass_Z=true;
      bool SFOS_pair=false;
      for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
        TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
        for(unsigned int i_lep2=i_lep+1; i_lep2<(*_recolep_charge).size();i_lep2++){
          TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
          float m_ll = (lep1 + lep2).M();
          if(m_ll<12) inv_mass_lep_pairs=false;
          if((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep2]){
            SFOS_pair=true;
            if(fabs(m_ll-91.2)<10) inv_mass_Z=false;
          }
        }
      }

      bool inv_mass_4l=true;
      bool SFOS_doublepair=false;
      float m_4l = 0;      
      if (loose_leptons.size()>=4){
        for(unsigned int i_lep=0; i_lep<loose_leptons.size(); i_lep++){
          TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
          for(unsigned int i_lep2=i_lep+1; i_lep2<loose_leptons.size(); i_lep2++){
            TLorentzVector lep2((*_recolep_px)[i_lep2],(*_recolep_py)[i_lep2],(*_recolep_pz)[i_lep2],(*_recolep_e)[i_lep2]);
            for(unsigned int i_lep3=i_lep+2; i_lep3<loose_leptons.size(); i_lep3++){
              TLorentzVector lep3((*_recolep_px)[i_lep3],(*_recolep_py)[i_lep3],(*_recolep_pz)[i_lep3],(*_recolep_e)[i_lep3]);
              for(unsigned int i_lep4=i_lep+3; i_lep4<loose_leptons.size(); i_lep4++){
                TLorentzVector lep4((*_recolep_px)[i_lep4],(*_recolep_py)[i_lep4],(*_recolep_pz)[i_lep4],(*_recolep_e)[i_lep4]);
                if( (i_lep != i_lep2) && (i_lep != i_lep3) && (i_lep != i_lep4) && (i_lep2 != i_lep3) && (i_lep2 != i_lep4) && (i_lep3 != i_lep4)){ 
                  if( ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep2] && (*_recolep_pdg)[i_lep3]==-(*_recolep_pdg)[i_lep4])
                    || ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep3] && (*_recolep_pdg)[i_lep2]==-(*_recolep_pdg)[i_lep4]) 
                    || ((*_recolep_pdg)[i_lep]==-(*_recolep_pdg)[i_lep4] && (*_recolep_pdg)[i_lep2]==-(*_recolep_pdg)[i_lep3])) {
                    m_4l = (lep1 + lep2 + lep3 + lep4).M();
                    SFOS_doublepair=true;
                    if(m_4l<140) {
                      inv_mass_4l=false;
                      break;                  
                    }
                  }
                }  
              }
            }
          }
        }
      }

  
      for(unsigned int i_lep=0;i_lep<(*_recolep_charge).size();i_lep++){
    
        TLorentzVector lep1((*_recolep_px)[i_lep],(*_recolep_py)[i_lep],(*_recolep_pz)[i_lep],(*_recolep_e)[i_lep]);
    
        if(i_lep<4){
      
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
    
      }

      bool metLD = true;
      if (_n_recoPFJet<=3){
        if(SFOS_pair) metLD = _ETmissLD>0.3;
        else if (!SFOS_pair) metLD = _ETmissLD>0.2;
      }

      bool passTriggerMatch = (pass_e && n_fakeable_ele>0) || (pass_2e && n_fakeable_ele>1) ||
                              (pass_m && n_fakeable_mu>0) || (pass_2m && n_fakeable_mu>1) ||
                              (pass_em && n_fakeable_ele>0 && n_fakeable_mu>0) ||
                              (pass_3e && n_fakeable_ele>2) || (pass_3m && n_fakeable_mu>2) ||
                              (pass_m2e && n_fakeable_ele>1 && n_fakeable_mu>0) ||
                              (pass_2me && n_fakeable_ele>0 && n_fakeable_mu>1);

      _isGenMatched = true;
      if(isMC)
        _isGenMatched = ((_recolep_sel_isGenMatched[0]) && (_recolep_sel_isGenMatched[1]) && (_recolep_sel_isGenMatched[2]) && (_recolep_sel_isGenMatched[3]));


      // 4l
      bool sig_4l_base = passTriggerMatch &&
        (_n_recolep_fakeable>=4) &&
        (_recolep_sel_conept[0]>25 && _recolep_sel_conept[1]>15 && _recolep_sel_conept[2]>15  && _recolep_sel_conept[3]>10) &&
        inv_mass_lep_pairs &&
        inv_mass_Z &&
        metLD &&
        (_recolep_sel_charge[0]+_recolep_sel_charge[1]+_recolep_sel_charge[2]+_recolep_sel_charge[3])==0 &&
        (_n_recoPFJet>=2 && (_n_recoPFJet_btag_loose>=2 || _n_recoPFJet_btag_medium>=1)) &&
        inv_mass_4l;

      bool sig_4l_SR = 
        sig_4l_base &&
        (_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1] && _recolep_sel_ismvasel[2] && _recolep_sel_ismvasel[3]) &&
        _isGenMatched;

      if (sig_4l_SR) n_4l_SR = n_4l_SR + 1;

      bool sig_4l_fake = 
        sig_4l_base &&
        !(_recolep_sel_ismvasel[0] && _recolep_sel_ismvasel[1] && _recolep_sel_ismvasel[2] && _recolep_sel_ismvasel[3]);

      if (sig_4l_fake) n_4l_fake = n_4l_fake + 1;

      passTriggerMatch = false;

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


      _triggerSF_weight = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],3);
      _triggerSF_weight_up = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],3,+1);
      _triggerSF_weight_down = triggerSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_pdg[1],_recolep_sel_pt[1],3,-1);


      if(_recolep_sel_ismvasel[0])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[0],_recolep_sel_pt[0],_recolep_sel_eta[0],2,0);


      if(_recolep_sel_ismvasel[1])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[1],_recolep_sel_pt[1],_recolep_sel_eta[1],2,0);


      if(_recolep_sel_ismvasel[2])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[2],_recolep_sel_pt[2],_recolep_sel_eta[2],2,0);


      if(_recolep_sel_ismvasel[3])
        _leptonSF_ttH_weight *= leptonSF_ttH(_recolep_sel_pdg[3],_recolep_sel_pt[3],_recolep_sel_eta[3],2);
      else
        _leptonSF_ttH_weight *= _get_recoToLoose_leptonSF_ttH(_recolep_sel_pdg[3],_recolep_sel_pt[3],_recolep_sel_eta[3],2,0);


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
        _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[2]/(1-_recolep_sel_fakerate_QCD_MC[3]);
        _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[2]/(1-_recolep_sel_fakerate_ttbar_MC[3]);

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

      if(!_recolep_sel_ismvasel[3]){
        _event_weight_ttH *= _recolep_sel_fakerate[3]/(1-_recolep_sel_fakerate[3]);
        _event_weight_ttH_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[3]/(1-_recolep_sel_fakerate_QCD_MC[3]);
        _event_weight_ttH_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[3]/(1-_recolep_sel_fakerate_ttbar_MC[3]);

        if(abs(_recolep_sel_pdg[3])==11){
          _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[3]/(1-_recolep_sel_fakerate_QCD_MC[3]);
          _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[3]/(1-_recolep_sel_fakerate_ttbar_MC[3]);
          _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate[3]/(1-_recolep_sel_fakerate[3]);
          _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate[3]/(1-_recolep_sel_fakerate[3]);
        }

        else if(abs(_recolep_sel_pdg[3])==13){
          _event_weight_ttH_ele_FR_QCD_MC *= _recolep_sel_fakerate[3]/(1-_recolep_sel_fakerate[3]);
          _event_weight_ttH_ele_FR_TT_MC *= _recolep_sel_fakerate[3]/(1-_recolep_sel_fakerate[3]);
          _event_weight_ttH_mu_FR_QCD_MC *= _recolep_sel_fakerate_QCD_MC[3]/(1-_recolep_sel_fakerate_QCD_MC[3]);
          _event_weight_ttH_mu_FR_TT_MC *= _recolep_sel_fakerate_ttbar_MC[3]/(1-_recolep_sel_fakerate_ttbar_MC[3]);
        }

        n_fake++;
        _n_fake_lep++;
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

      if (sig_4l_SR){
        _category = 22;
        tree_4l_SR->Fill();
      }

      if (sig_4l_fake){
        _category = 52;
        tree_4l_fake->Fill();
      }


    }


  } 

  cout<<" "<<endl;
  cout<<"***"<<endl;
  cout<<" "<<endl;
  
  cout<<"2lss SR: "<<n_2lSS_SR<<endl;
  cout<<"2lss fake: "<<n_2lSS_fake<<endl;
  cout<<"2lss flip: "<<n_2lSS_flip<<endl;

  cout<<" "<<endl;

  cout<<"3l SR: "<<n_3l_SR<<endl;
  cout<<"3l fake: "<<n_3l_fake<<endl;

  cout<<" "<<endl;

  cout<<"4l SR: "<<n_4l_SR<<endl;
  cout<<"4l fake: "<< n_4l_fake<<endl;
  
  cout<<" "<<endl;
  cout<<"***"<<endl;
  cout<<" "<<endl;

  cout<<"1l+2tau SR: "<<n_1l_2tau_SR<<endl;
  cout<<"1l+2tau fake: "<<n_1l_2tau_fake<<endl;

  cout<<" "<<endl; 

  cout<<"2lss+1tau SR: "<<n_2lSS_1tau_SR<<endl;
  cout<<"2lss+1tau fake: "<<n_2lSS_1tau_fake<<endl;
  cout<<"2lss+1tau flip: "<<n_2lSS_1tau_flip<<endl;

  cout<<" "<<endl;

  cout<<"2l+2tau SR: "<<n_2l_2tau_SR<<endl;
  cout<<"2l+2tau fake: "<<n_2l_2tau_fake<<endl;

  cout<<" "<<endl;

  cout<<"3l+1tau SR: "<<n_3l_1tau_SR<<endl;
  cout<<"3l+1tau fake: "<< n_3l_1tau_fake<<endl;

  cout<<" "<<endl;
  cout<<"***"<<endl;
  cout<<" "<<endl;

  cout<<"ttW CR SR: "<<n_ttWctrl_SR<<endl;
  cout<<"ttW CR fake: "<<n_ttWctrl_fake<<endl;
  cout<<"ttW CR flip: "<< n_ttWctrl_flip<<endl;

  cout<<" "<<endl;

  cout<<"ttZ CR SR: "<<n_ttZctrl_SR<<endl;
  cout<<"ttZ CR fake: "<<n_ttZctrl_fake<<endl;

  cout<<" "<<endl;
  

  f_new->cd();
  
  h->Write();

  for(unsigned int i=0; i<tree_new.size();i++)
    tree_new[i]->Write();

  f_new->Close();
  return;

}
