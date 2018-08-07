//BDT for signal extraction in 3l1tau category

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <sys/stat.h>
#include <cmath>
#include <typeinfo>

using namespace std;

//ROOT libraries
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TBranch.h>
#include <TBranchElement.h>
#include <TCanvas.h>
#include <vector>
#include <TLorentzVector.h>
#include <TH2F.h>

#include <Math/Functor.h> // ROOT::Math::Functo
#include <Math/Factory.h> // ROOT::Math::Factory
#include <Math/Minimizer.h> // ROOT::Math::Minimizer
#include <TFile.h> // TFile
#include <TF1.h> // TF1

#include <gsl/gsl_monte_vegas.h> // gsl_*

#include <Math/LorentzVector.h>
#include <Math/PtEtaPhiM4D.h>

typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> > LorentzVector;

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"


//variables for final BDT
float lep1_conePt;
float lep2_conePt;
float mindr_lep1_jet;
float max_lep_eta;
float mindr_tau_jet;
float ptmiss;
float tau_pt;
float dr_leps;
float mTauTauVis1;
float mTauTauVis2;
float mbb_loose;
float nJet;

TMVA::Reader* Book_3l1tau_MVAReader(std::string basePath, std::string weightFileName){

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("lep1_conePt", &lep1_conePt );
    reader->AddVariable("lep2_conePt", &lep2_conePt );
    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet );
    reader->AddVariable("max_lep_eta", &max_lep_eta );
    reader->AddVariable("mindr_tau_jet", &mindr_tau_jet );
    reader->AddVariable("ptmiss", &ptmiss );
    reader->AddVariable("tau_pt", &tau_pt );
    reader->AddVariable("dr_leps", &dr_leps );
    reader->AddVariable("mTauTauVis1", &mTauTauVis1 );
    reader->AddVariable("mTauTauVis2", &mTauTauVis2 );  
    reader->AddVariable("mbb_loose", &mbb_loose ); 
    reader->AddVariable("nJet", &nJet );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}

int main(int argc, char** argv){
  
  string input;
  for (int i = 1; i < argc; ++i) {
    if(std::string(argv[i]) == "--input") {
      if (i + 1 < argc) {
	input = argv[i+1];
	break;
      } else {
	std::cerr << "--input option requires one argument." << std::endl;
	return 1;
      }      
    }  
  }
  if(input==""){
    std::cerr << "--input argument required" << std::endl;
    return 1;
  }

  string output;
  for (int i = 1; i < argc; ++i) {
    if(std::string(argv[i]) == "--output") {
      if (i + 1 < argc) {
	output = argv[i+1];
	break;
      } else {
	std::cerr << "--output option requires one argument." << std::endl;
	return 1;
      }      
    }  
  }
  if(output==""){
    std::cerr << "--output argument required" << std::endl;
    return 1;
  }

  TFile* f_new = TFile::Open(output.c_str());
  /*if(f_new!=0){
    cout<<output<<" already exists, please delete it before converting again"<<endl;
    return 0;
  }*/
  f_new = TFile::Open(output.c_str(),"RECREATE");
 
  std::vector<string> treename;
  /*treename.push_back("HTauTauTree_2lSS");
  treename.push_back("HTauTauTree_2lOS_CR");
  treename.push_back("HTauTauTree_2lSS_lepMVA_CR");
  treename.push_back("HTauTauTree_2lSS_jetmult_CR");
  treename.push_back("HTauTauTree_2lSS_ttbarOF_CR");
  treename.push_back("HTauTauTree_2lSS_2jet_CR");
  */treename.push_back("HTauTauTree_3l");
  /*treename.push_back("HTauTauTree_3l_lepMVA_CR");
  treename.push_back("HTauTauTree_3l_WZ_CR");
  treename.push_back("HTauTauTree_3l_ttZ_CR");
  treename.push_back("HTauTauTree_3l_ttZ_lepMVA_CR");
  treename.push_back("HTauTauTree_1l_2tau");
  treename.push_back("HTauTauTree_1l_2tau_fake_CR");
  treename.push_back("HTauTauTree_1l_2tau_2jet_CR");
  treename.push_back("HTauTauTree_2l_2tau");
  treename.push_back("HTauTauTree_2l_2tau_fake_CR");
  */
  TMVA::Reader* MVA_3l1tau_reader = Book_3l1tau_MVAReader("../MVA/BDT_3l1tau","3l_1tau_XGB_plainKin_evtLevelSUM_TTH_M_12Var.xml");
  if(!MVA_3l1tau_reader) std::cout << "No 3l1tau xml file"<<std::endl;

  for(unsigned int i_tree=0;i_tree<treename.size();i_tree++){

    TChain *tree = new TChain(treename[i_tree].c_str());
    tree->Add(input.c_str());

    Long64_t nentries = tree->GetEntries();
    std::cout<<"nentries="<<tree->GetEntries()<<std::endl;

    //old variables used
    int _category;
    std::vector<float>* _recotauh_sel_px;
    std::vector<float>* _recotauh_sel_py;
    std::vector<float>* _recotauh_sel_pz;
    std::vector<float>* _recotauh_sel_e;
    std::vector<float>* _recotauh_sel_pt;
    std::vector<int>* _recotauh_sel_charge;

    std::vector<float>* _recolep_sel_pt;
    std::vector<float>* _recolep_sel_conept;
    std::vector<float>* _recolep_sel_eta;
    std::vector<float>* _recolep_sel_phi;
    std::vector<float>* _recolep_sel_px;
    std::vector<float>* _recolep_sel_py;
    std::vector<float>* _recolep_sel_pz;
    std::vector<float>* _recolep_sel_e;
    std::vector<int>* _recolep_sel_charge;

    int _n_recoPFJet;
    int _n_recoPFJet_btag_loose;
    std::vector<float>* _recoPFJet_pt;
    std::vector<float>* _recoPFJet_px;
    std::vector<float>* _recoPFJet_py;
    std::vector<float>* _recoPFJet_pz;
    std::vector<float>* _recoPFJet_e;
    std::vector<float>* _recoPFJet_btag_px;
    std::vector<float>* _recoPFJet_btag_py;
    std::vector<float>* _recoPFJet_btag_pz;
    std::vector<float>* _recoPFJet_btag_e;

    float _mindR_lep1_recoPFjet;
    float _avg_dr_jet;
    float _HTmiss;
    float _met;
    float _metphi;

    tree->SetBranchAddress("recotauh_sel_px",&_recotauh_sel_px);
    tree->SetBranchAddress("recotauh_sel_py",&_recotauh_sel_py);
    tree->SetBranchAddress("recotauh_sel_pz",&_recotauh_sel_pz);
    tree->SetBranchAddress("recotauh_sel_e",&_recotauh_sel_e);
    tree->SetBranchAddress("recotauh_sel_pt",&_recotauh_sel_pt);
    tree->SetBranchAddress("recotauh_sel_charge",&_recotauh_sel_charge);

    tree->SetBranchAddress("recolep_sel_px",&_recolep_sel_px);
    tree->SetBranchAddress("recolep_sel_py",&_recolep_sel_py);
    tree->SetBranchAddress("recolep_sel_pz",&_recolep_sel_pz);
    tree->SetBranchAddress("recolep_sel_e",&_recolep_sel_e);
    tree->SetBranchAddress("recolep_sel_pt",&_recolep_sel_pt);
    tree->SetBranchAddress("recolep_sel_conept",&_recolep_sel_conept);
    tree->SetBranchAddress("recolep_sel_phi",&_recolep_sel_phi);
    tree->SetBranchAddress("recolep_sel_eta",&_recolep_sel_eta);
    tree->SetBranchAddress("recolep_sel_charge",&_recolep_sel_charge);

    tree->SetBranchAddress("n_recoPFJet",&_n_recoPFJet);
    tree->SetBranchAddress("n_recoPFJet_btag_loose",&_n_recoPFJet_btag_loose);
    tree->SetBranchAddress("recoPFJet_pt",&_recoPFJet_pt);
    tree->SetBranchAddress("recoPFJet_px",&_recoPFJet_px);
    tree->SetBranchAddress("recoPFJet_py",&_recoPFJet_py);
    tree->SetBranchAddress("recoPFJet_pz",&_recoPFJet_pz);
    tree->SetBranchAddress("recoPFJet_e",&_recoPFJet_e);
    tree->SetBranchAddress("recoPFJet_btag_px",&_recoPFJet_btag_px);
    tree->SetBranchAddress("recoPFJet_btag_py",&_recoPFJet_btag_py);
    tree->SetBranchAddress("recoPFJet_btag_pz",&_recoPFJet_btag_pz);
    tree->SetBranchAddress("recoPFJet_btag_e",&_recoPFJet_btag_e);

    tree->SetBranchAddress("mindR_lep1_recoPFjet",&_mindR_lep1_recoPFjet);
    tree->SetBranchAddress("avg_dr_jet",&_avg_dr_jet);
    tree->SetBranchAddress("HTmiss",&_HTmiss);
    tree->SetBranchAddress("met",&_met);
    tree->SetBranchAddress("metphi",&_metphi);

    tree->SetBranchAddress("category",&_category);

    TTree* tree_new=(TTree*)tree->GetTree()->CloneTree(0);

    //new variables for final BDT
    float _mTauTauVis1;
    float _mTauTauVis2;
    float _max_lep_eta;
    float _ptmiss;
    float _tau_pt;
    float _dr_leps;
    float _mindr_lep1_jet;
    float _mindr_tau_jet;
    float _mbb_loose;
    float _lep1_conePt;
    float _lep2_conePt;
    float _nJet;

    tree_new->Branch("mTauTauVis1",&_mTauTauVis1,"mTauTauVis1/F");
    tree_new->Branch("mTauTauVis2",&_mTauTauVis2,"mTauTauVis2/F");
    tree_new->Branch("max_lep_eta",&_max_lep_eta,"max_lep_eta/F");
    tree_new->Branch("ptmiss",&_ptmiss,"ptmiss/F");
    tree_new->Branch("tau_pt",&_tau_pt,"tau_pt/F");
    tree_new->Branch("dr_leps",&_dr_leps,"dr_leps/F");
    tree_new->Branch("mindr_lep1_jet",&_mindr_lep1_jet,"mindr_lep1_jet/F");
    tree_new->Branch("mindr_tau_jet",&_mindr_tau_jet,"mindr_tau_jet/F");
    tree_new->Branch("mbb_loose",&_mbb_loose,"mbb_loose/F");
    tree_new->Branch("lep1_conePt",&_lep1_conePt,"lep1_conePt/F");
    tree_new->Branch("lep2_conePt",&_lep2_conePt,"lep2_conePt/F");
    tree_new->Branch("nJet",&_nJet,"nJet/F");

    float _MVA_3l1tau_output;
    float _MVA_3l1tau;

    tree_new->Branch("MVA_3l1tau_output",&_MVA_3l1tau_output,"MVA_3l1tau_output/F");
    tree_new->Branch("MVA_3l1tau",&_MVA_3l1tau,"MVA_3l1tau/F");

    //nentries=100;
    for(int i=0;i<nentries;i++){
      if(i%100==0)
         std::cout<<"i="<<i<<std::endl;

      //new variables
      _mTauTauVis1 = 0;
      _mTauTauVis2 = 0;
      _max_lep_eta = 0;
      _ptmiss = 0;
      _tau_pt = 0;
      _dr_leps = 0;
      _mindr_lep1_jet = 0;
      _mindr_tau_jet = 0;
      _mbb_loose = 0;
      _lep1_conePt =0;
      _lep2_conePt = 0;
      _nJet = 0;

      //old variables used
      _recotauh_sel_px = 0;
      _recotauh_sel_py = 0;
      _recotauh_sel_pz = 0;
      _recotauh_sel_e = 0;
      _recotauh_sel_pt = 0;
      _recotauh_sel_charge = 0;

      _recolep_sel_px = 0;
      _recolep_sel_py = 0;
      _recolep_sel_pz = 0;
      _recolep_sel_e = 0;
      _recolep_sel_pt = 0;
      _recolep_sel_conept = 0;
      _recolep_sel_phi = 0;
      _recolep_sel_eta = 0;
      _recolep_sel_charge = 0;

      _n_recoPFJet = 0;
      _n_recoPFJet_btag_loose = 0;
      _recoPFJet_pt = 0;
      _recoPFJet_px = 0;
      _recoPFJet_py = 0;
      _recoPFJet_pz = 0;
      _recoPFJet_e = 0;
      _recoPFJet_btag_px = 0;
      _recoPFJet_btag_py = 0;
      _recoPFJet_btag_pz = 0;
      _recoPFJet_btag_e = 0;
      _mindR_lep1_recoPFjet = 0;

      _HTmiss = 0;
      _met = 0;

      _MVA_3l1tau_output = 0;
      _MVA_3l1tau = 0;

      tree->GetEntry(i);

      if(_category==16 || _category==46){
        
      TLorentzVector tau1((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
      TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
      TLorentzVector lep2((*_recolep_sel_px)[1],(*_recolep_sel_py)[1],(*_recolep_sel_pz)[1],(*_recolep_sel_e)[1]);
      TLorentzVector lep3((*_recolep_sel_px)[2],(*_recolep_sel_py)[2],(*_recolep_sel_pz)[2],(*_recolep_sel_e)[2]);
      
      if (_recoPFJet_btag_px->size()==0) continue;
      TLorentzVector bjet1((*_recoPFJet_btag_px)[0],(*_recoPFJet_btag_py)[0],(*_recoPFJet_btag_pz)[0],(*_recoPFJet_btag_e)[0]);
      TLorentzVector bjet2((*_recoPFJet_btag_px)[1],(*_recoPFJet_btag_py)[1],(*_recoPFJet_btag_pz)[1],(*_recoPFJet_btag_e)[1]);
      
      //for BDT
      float _charge_lep1 = (*_recolep_sel_charge)[0];
      float _charge_lep2 = (*_recolep_sel_charge)[1];
      float _charge_tau = (*_recotauh_sel_charge)[0];
      bool OS1 = (_charge_lep1*_charge_tau < 0);
      bool OS2 = (_charge_lep2*_charge_tau < 0);

      _mTauTauVis1 = (OS1) ? (tau1+lep1).M() : -1.;
      mTauTauVis1 = _mTauTauVis1;
      _mTauTauVis1 = (OS2) ? (tau1+lep2).M() : -1.;
      mTauTauVis1 = _mTauTauVis1;

      float _maxEta = -999.;
      for(unsigned int i_lep=0;i_lep<(*_recolep_sel_pt).size();i_lep++){
        float _eta_lep = (*_recolep_sel_eta)[i_lep];
        if(_eta_lep>_maxEta){
            _maxEta = _eta_lep;
        }
      }

      _max_lep_eta = _maxEta;
      max_lep_eta = _max_lep_eta;

      _ptmiss = _met;
      ptmiss = _ptmiss;

      _tau_pt = tau1.Pt();
      tau_pt = _tau_pt;

      _dr_leps = lep1.DeltaR(lep2);
      dr_leps = _dr_leps;

      float _mindR1 = 999.;
      float _mindR2 = 999.;
      for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size()-1;i_jet++){
        TLorentzVector jet1((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
        TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
        TLorentzVector lep2((*_recolep_sel_px)[1],(*_recolep_sel_py)[1],(*_recolep_sel_pz)[1],(*_recolep_sel_e)[1]);
        float _dR1 = jet1.DeltaR(lep1);
        float _dR2 = jet1.DeltaR(lep2);

        if(_dR1<_mindR1){
            _mindR1 = _dR1;
        }
        if(_dR2<_mindR2){
            _mindR2 = _dR2;
        }
      }

      _mindr_lep1_jet = _mindR1;
      mindr_lep1_jet = _mindr_lep1_jet;

      //_mindr_tau_jet FIXME

      _mbb_loose = (_n_recoPFJet_btag_loose>1) ? (bjet1+bjet2).M() : -1; 
      mbb_loose = _mbb_loose;

      _lep1_conePt = (*_recolep_sel_conept)[0];
      lep1_conePt = _lep1_conePt;

      _lep2_conePt = (*_recolep_sel_conept)[1];
      lep2_conePt = _lep2_conePt;

      _nJet = _n_recoPFJet;
      nJet = _nJet;

      _MVA_3l1tau_output = MVA_3l1tau_reader->EvaluateMVA("BDTG method");
      _MVA_3l1tau = 1. / (1. + sqrt((1. - _MVA_3l1tau_output) / (1. + _MVA_3l1tau_output)));
 
     }

     tree_new->Fill();
  
    }
 
  f_new->cd();
  tree_new->Write();

  }
  
  f_new->Close();
  return 0;
}
