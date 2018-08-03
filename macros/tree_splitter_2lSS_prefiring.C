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
#include "triggerFilter.cc"
#include "metFilter.cc"

using namespace std;


void split_tree_2lSS(TString filename_in, TString filename_out,
		int i_split1=0, int i_split2=0,
		bool isMC=true, bool isReHLT=true){


  vector<TString> list;
  list.push_back(filename_in);

  TChain * tree = new TChain("HTauTauTree");
  int nFiles = list.size();

  for(int i=0;i<nFiles;i++)
    {
      tree->Add(list[i]);
    }

  //Old branches used
   
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

  //TFile* f_new = TFile::Open(dir_out+file);
  TFile* f_new = TFile::Open(filename_out);
  
  if(f_new!=0){
    cout<<filename_out<<" already exists, please delete it before converting again"<<endl;
    return;
  }
  
  f_new = TFile::Open(filename_out,"RECREATE");

  TTree* tree_2lSS=tree->GetTree()->CloneTree(0);
  tree_2lSS->SetNameTitle("HTauTauTree_2lSS","HTauTauTree_2lSS");

  vector<TTree*> tree_new;

  tree_new.push_back(tree_2lSS);

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
    51: 2l + 2tauh, lepMVA + tau CR
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
  //event weights to estimate the systematic uncertainty associated with the closure of the fake rate method
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
    int n_fakeable_mu = 0;
    int n_fakeable_ele = 0;
    for(unsigned int i_mu=0; i_mu<(*_recomu_e).size(); i_mu++){
        if ((*_recomu_isfakeable)[i_mu]) n_fakeable_mu = n_fakeable_mu + 1;
    }
    for(unsigned int i_ele=0; i_ele<(*_recoele_e).size(); i_ele++){
        if ((*_recoele_isfakeable)[i_ele]) n_fakeable_ele = n_fakeable_ele + 1;
    }

    //Trigger matching
    bool pass_e = pass_SingleEle_trigger(_triggerbit);
    bool pass_m = pass_SingleMu_trigger(_triggerbit);
    bool pass_2e = pass_DoubleEle_trigger(_triggerbit); 
    bool pass_2m = pass_DoubleMu_trigger(_triggerbit);
    bool pass_em = pass_MuEle_trigger(_triggerbit);
    bool pass_etau = pass_EleTau_trigger(_triggerbit);
    bool pass_mtau = pass_MuTau_trigger(_triggerbit);
    bool pass_3e = pass_TripleEle_trigger(_triggerbit);
    bool pass_m2e = pass_MuDiEle_trigger(_triggerbit);
    bool pass_2me = pass_DiMuEle_trigger(_triggerbit);
    bool pass_3m = pass_TripleMu_trigger(_triggerbit);

    //MET filters
    bool pass_met_filter = pass_met_filters(_metfilterbit, isMC);
    if (!pass_met_filter) continue;

    // ****************************
    // *********** 2lSS ***********
    // **************************** 

    if(_n_recolep_fakeable>=2 && _n_recotauh>0){
       
       if(_n_recolep_mvasel<=2){

       bool inv_mass_lep_pairs=true;
       bool inv_mass_Zee=true;
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
	
        int n_tau_Med = 0;	
	
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
            if((*_recotauh_byMediumIsolationMVArun2017v2DBoldDMdR0p3wLT2017)[i_tau]>0.5) n_tau_Med = n_tau_Med + 1;
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

	bool tau = _recotauh_sel_e.size()>0;//there is at least 1 tau that passes loose iso

	//int n_tau_Med = 0;
 
        //all taus (vloose,ie fakeable) 
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

	    //if (_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017[i_tau]>0.5) n_tau_Med = n_tau_Med + 1;
	    
            if(isMC){
	      _recotauh_sel_isGenMatched.push_back((*_recotauh_isGenMatched)[i_tau]);
	      _recotauh_sel_genMatchInd.push_back((*_recotauh_genMatchInd)[i_tau]);
	    }

            _recotauh_sel_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    _recotauh_sel_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    _recotauh_sel_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT.push_back((*_recotauh_fakerate_byTightIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);
	    
	    
	  }	

	}

    bool pt_lep_2l = (_recolep_sel_conept[0]>25 && _recolep_sel_conept[1]>15);
    bool lep_quality = _recolep_sel_tightcharge[0] && _recolep_sel_tightcharge[1];
    bool metLD = true;
    if(abs(_recolep_sel_pdg[0])==11 && abs(_recolep_sel_pdg[1])==11) metLD = (_ETmissLD>0.2); 
    bool jetmult_sig = _n_recoPFJet>=4 && (_n_recoPFJet_btag_medium>=1 || _n_recoPFJet_btag_loose>=2);
    bool tight_mvasel = _recolep_sel_ismvasel[0]==1 && _recolep_sel_ismvasel[1]==1;
    bool SS_lep = _recolep_sel_charge[0]*_recolep_sel_charge[1]>0;
    bool passTriggerMatch = (pass_e && n_fakeable_ele>0) || (pass_2e && n_fakeable_ele>1) ||
      (pass_m && n_fakeable_mu>0) || (pass_2m && n_fakeable_mu>1) ||
      (pass_em && n_fakeable_ele>0 && n_fakeable_mu>0);
    bool isGenMatched = _recolep_sel_isGenMatched[0] && _recolep_sel_isGenMatched[1];

    bool sig_2lSS = pt_lep_2l && inv_mass_lep_pairs && !tau && inv_mass_Zee && metLD && jetmult_sig && tight_mvasel && SS_lep && passTriggerMatch && isGenMatched;

    if(sig_2lSS) tree_2lSS->Fill();
	
    }
   }    
  }
 
  f_new->cd();
  
  for(unsigned int i=0; i<tree_new.size();i++)
    tree_new[i]->Write();

  f_new->Close();
  return;

}
