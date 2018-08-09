//BDT for signal extraction in 2l2tau category
/*
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
*/

//variables for final BDT
float mTauTauVis_2l2tau;
float cosThetaS_hadTau_2l2tau;
float tau1_pt_2l2tau;
float tau2_pt_2l2tau;
float lep2_conePt_2l2tau;
float mindr_lep1_jet_2l2tau;
float mT_lep1_2l2tau;
float mindr_tau_jet_2l2tau;
float avg_dr_jet_2l2tau;
float avr_dr_lep_tau_2l2tau;
float dr_taus_2l2tau;
float is_OS_2l2tau; 
float nBJetLoose_2l2tau;

TMVA::Reader* Book_2l2tau_MVAReader(std::string basePath, std::string weightFileName){

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("mTauTauVis", &mTauTauVis_2l2tau );
    reader->AddVariable("cosThetaS_hadTau", &cosThetaS_hadTau_2l2tau );
    reader->AddVariable("tau1_pt", &tau1_pt_2l2tau );
    reader->AddVariable("tau2_pt", &tau2_pt_2l2tau );
    reader->AddVariable("lep2_conePt", &lep2_conePt_2l2tau );
    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet_2l2tau );
    reader->AddVariable("mT_lep1", &mT_lep1_2l2tau );
    reader->AddVariable("mindr_tau_jet", &mindr_tau_jet_2l2tau );
    reader->AddVariable("avg_dr_jet", &avg_dr_jet_2l2tau );
    reader->AddVariable("avr_dr_lep_tau", &avr_dr_lep_tau_2l2tau );  
    reader->AddVariable("dr_taus", &dr_taus_2l2tau ); 
    reader->AddVariable("is_OS", &is_OS_2l2tau );
    reader->AddVariable("nBJetLoose", &nBJetLoose_2l2tau );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}

//int add_BDT_2l2tau(int argc, char** argv){
int add_BDT_2l2tau(string input, string output, vector<string> treename){  

  cout<<"Computing 2l2tau BDT..."<<endl;
 
/*  string input;
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
*/
  TFile* f_new = TFile::Open(output.c_str());
  /*if(f_new!=0){
    cout<<output<<" already exists, please delete it before converting again"<<endl;
    return 0;
  }*/
  f_new = TFile::Open(output.c_str(),"RECREATE");
 
  /*std::vector<string> treename;
  treename.push_back("HTauTauTree_2lSS");
  treename.push_back("HTauTauTree_2lOS_CR");
  treename.push_back("HTauTauTree_2lSS_lepMVA_CR");
  treename.push_back("HTauTauTree_2lSS_jetmult_CR");
  treename.push_back("HTauTauTree_2lSS_ttbarOF_CR");
  treename.push_back("HTauTauTree_2lSS_2jet_CR");
  treename.push_back("HTauTauTree_3l");
  treename.push_back("HTauTauTree_3l_lepMVA_CR");
  treename.push_back("HTauTauTree_3l_WZ_CR");
  treename.push_back("HTauTauTree_3l_ttZ_CR");
  treename.push_back("HTauTauTree_3l_ttZ_lepMVA_CR");
  treename.push_back("HTauTauTree_1l_2tau");
  treename.push_back("HTauTauTree_1l_2tau_fake_CR");
  treename.push_back("HTauTauTree_1l_2tau_2jet_CR");
  treename.push_back("HTauTauTree_2l_2tau");
  treename.push_back("HTauTauTree_2l_2tau_fake_CR");*/
  
  TMVA::Reader* MVA_2l2tau_reader = Book_2l2tau_MVAReader("../MVA/BDT_2l2tau","2l_2tau_XGB_plainKin_evtLevelSUM_TTH_VT_13Var.xml");
  if(!MVA_2l2tau_reader) std::cout << "No 2l12au xml file"<<std::endl;

  for(unsigned int i_tree=0;i_tree<treename.size();i_tree++){

    TChain *tree = new TChain(treename[i_tree].c_str());
    tree->Add(input.c_str());

    cout<<"Tree: "<<treename[i_tree]<<endl;

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
    float _mTauTauVis;
    float _cosThetaS_hadTau;
    float _tau1_pt;
    float _tau2_pt;
    float _lep2_conePt;
    float _mindr_lep1_jet;
    float _mT_lep1;
    float _mindr_tau_jet;
    float _avr_dr_lep_tau;
    float _dr_taus;
    float _is_OS; 
    float _nBJetLoose;

    /*tree_new->Branch("mTauTauVis",&_mTauTauVis,"mTauTauVis/F");
    tree_new->Branch("cosThetaS_hadTau",&_cosThetaS_hadTau,"cosThetaS_hadTau/F");
    tree_new->Branch("tau1_pt",&_tau1_pt,"tau1_pt/F");
    tree_new->Branch("tau2_pt",&_tau2_pt,"tau2_pt/F");
    tree_new->Branch("lep2_conePt",&_lep2_conePt,"lep2_conePt/F");
    tree_new->Branch("mindr_lep1_jet",&_mindr_lep1_jet,"mindr_lep1_jet/F");
    tree_new->Branch("mT_lep1",&_mT_lep1,"mT_lep1/F");
    tree_new->Branch("mindr_tau_jet",&_mindr_tau_jet,"mindr_tau_jet/F");
    tree_new->Branch("avg_dr_jet",&_avg_dr_jet,"avg_dr_jet/F");
    tree_new->Branch("avr_dr_lep_tau",&_avr_dr_lep_tau,"avr_dr_lep_tau/F");
    tree_new->Branch("dr_taus",&_dr_taus,"dr_taus/F");
    tree_new->Branch("is_OS",&_is_OS,"is_OS/F");
    tree_new->Branch("nBJetLoose",&_nBJetLoose,"nBJetLoose/F");
    */
    float _MVA_2l2tau_output;
    float _MVA_2l2tau;

    tree_new->Branch("MVA_2l2tau_output",&_MVA_2l2tau_output,"MVA_2l2tau_output/F");
    tree_new->Branch("MVA_2l2tau",&_MVA_2l2tau,"MVA_2l2tau/F");

    //nentries=100;
    for(int i=0;i<nentries;i++){
      if(i%1000==0)
         std::cout<<"i="<<i<<std::endl;

      //new variables
      _mTauTauVis = 0;
      _cosThetaS_hadTau = 0;
      _tau1_pt = 0;
      _tau2_pt = 0;
      _lep2_conePt = 0;
      _mindr_lep1_jet = 0;
      _mT_lep1 = 0;
      _mindr_tau_jet = 0;
      _avg_dr_jet = 0;
      _avr_dr_lep_tau = 0;
      _dr_taus = 0;
      _is_OS = 0; 
      _nBJetLoose = 0;

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

      _MVA_2l2tau_output = -1;
      _MVA_2l2tau = -1;

      tree->GetEntry(i);

      if(_category==21 || _category==51){
        
      TLorentzVector tau1((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
      TLorentzVector tau2((*_recotauh_sel_px)[1],(*_recotauh_sel_py)[1],(*_recotauh_sel_pz)[1],(*_recotauh_sel_e)[1]);
      TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
      TLorentzVector lep2((*_recolep_sel_px)[1],(*_recolep_sel_py)[1],(*_recolep_sel_pz)[1],(*_recolep_sel_e)[1]);
      
      _mTauTauVis = (tau1+tau2).M();
      _cosThetaS_hadTau = abs(tau1.CosTheta());
      _tau1_pt = tau1.Pt();
      _tau2_pt = tau2.Pt();
      _lep2_conePt = (*_recolep_sel_conept)[1];
      _mindr_lep1_jet = _mindR_lep1_recoPFjet;
      _mT_lep1 = sqrt(2*((*_recolep_sel_conept)[0])*_met*(1-cos(((*_recolep_sel_phi)[0])-_metphi)));

      float _mindR = 999.;
      for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){
        TLorentzVector jet((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
        for(unsigned int i_tau=0;i_tau<(*_recotauh_sel_pt).size();i_tau++){
          TLorentzVector tau((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
          float _dR = jet.DeltaR(tau);
          if(_dR<_mindR){
            _mindR = _dR;
          }
        }
      }

      _mindr_tau_jet = _mindR;

      float _n_lep_tau_pairs = 0;
      float _dR_lep_tau = 0;
      for(unsigned int i_lep=0;i_lep<(*_recolep_sel_pt).size();i_lep++){
        TLorentzVector lep((*_recolep_sel_px)[i_lep],(*_recolep_sel_py)[i_lep],(*_recolep_sel_pz)[i_lep],(*_recolep_sel_e)[i_lep]);
        for(unsigned int i_tau=0;i_tau<(*_recotauh_sel_pt).size();i_tau++){
          TLorentzVector tau((*_recotauh_sel_px)[i_tau],(*_recotauh_sel_py)[i_tau],(*_recotauh_sel_pz)[i_tau],(*_recotauh_sel_e)[i_tau]);
          _dR_lep_tau += lep.DeltaR(tau);
          _n_lep_tau_pairs++;
        }
      }
      int one = (*_recolep_sel_pt).size();
      int two = (*_recotauh_sel_pt).size();
      _avr_dr_lep_tau = _dR_lep_tau / _n_lep_tau_pairs;
      _dr_taus = tau1.DeltaR(tau2);
      _is_OS = ( (*_recotauh_sel_charge)[0]*(*_recotauh_sel_charge)[1] < 0 );
      _nBJetLoose = _n_recoPFJet_btag_loose;


      //cout<<_mTauTauVis<<" "<<_cosThetaS_hadTau<<" "<<_tau1_pt<<" "<<_tau2_pt<<" "<<_lep2_conePt<<" "<<_mindr_lep1_jet<<" "<<_mT_lep1<<" "<<_mindr_tau_jet<<" "<<_avg_dr_jet<<" "<<_avr_dr_lep_tau<<" "<<_dr_taus<<" "<<_is_OS<<" "<<_nBJetLoose<<endl;

      mTauTauVis_2l2tau = _mTauTauVis;
      cosThetaS_hadTau_2l2tau = _cosThetaS_hadTau;
      tau1_pt_2l2tau = _tau1_pt;
      tau2_pt_2l2tau = _tau2_pt;
      lep2_conePt_2l2tau = _lep2_conePt;
      mindr_lep1_jet_2l2tau = _mindr_lep1_jet;
      mT_lep1_2l2tau = _mT_lep1;
      mindr_tau_jet_2l2tau = _mindr_tau_jet;
      avg_dr_jet_2l2tau = _avg_dr_jet;
      avr_dr_lep_tau_2l2tau = _avr_dr_lep_tau;
      dr_taus_2l2tau = _dr_taus;
      is_OS_2l2tau = _is_OS;
      nBJetLoose_2l2tau = _nBJetLoose;

      _MVA_2l2tau_output = MVA_2l2tau_reader->EvaluateMVA("BDTG method");
      _MVA_2l2tau = 1. / (1. + sqrt((1. - _MVA_2l2tau_output) / (1. + _MVA_2l2tau_output)));
      //cout<<"MVA_2l2tau = "<<_MVA_2l2tau<<endl;
 
     }

     tree_new->Fill();
  
    }
 
  f_new->cd();
  tree_new->Write();

  }
  
  f_new->Close();
  return 0;
}
