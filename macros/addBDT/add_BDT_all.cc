
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
#include <TF1.h> // TF1

#include <gsl/gsl_monte_vegas.h> // gsl_*

#include <Math/LorentzVector.h>
#include <Math/PtEtaPhiM4D.h>

typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> > LorentzVector;

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"

#include "HTT_kinfit/HadTopKinFit.cc"
//#include "HTT_kinfit/HadTopKinFit.h"


bool pT_comparison_pairs(pair<int,float> pair1, pair<int,float> pair2){

  return pair1.second>pair2.second;

}

bool DeepCSV_comparison_pairs(pair<int,float> pair1, pair<int,float> pair2){

  return pair1.second>pair2.second;

}


float avg_dr_jet_1l2tau;
float dr_taus_1l2tau;
float ptmiss_1l2tau;
float lep_conePt_1l2tau;
float mT_lep_1l2tau;
float mTauTauVis_1l2tau;
float mindr_lep_jet_1l2tau;
float mindr_tau1_jet_1l2tau;
float mindr_tau2_jet_1l2tau;
float dr_lep_tau_lead_1l2tau;
float dr_lep_tau_sublead_1l2tau;
float nBJetLoose_1l2tau;
float tau1_pt_1l2tau;
float tau2_pt_1l2tau;
float dr_lep_tau_ss_1l2tau;
float costS_tau_1l2tau;
float HTT_1l2tau;
float HadTop_pt_1l2tau;

TMVA::Reader* Book_1l2tau_MVAReader(std::string basePath, std::string weightFileName){

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");
    
    reader->AddVariable("avg_dr_jet", &avg_dr_jet_1l2tau );
    reader->AddVariable("dr_taus", &dr_taus_1l2tau );
    reader->AddVariable("ptmiss", &ptmiss_1l2tau );
    reader->AddVariable("lep_conePt", &lep_conePt_1l2tau );
    reader->AddVariable("mT_lep", &mT_lep_1l2tau );
    reader->AddVariable("mTauTauVis", &mTauTauVis_1l2tau );
    reader->AddVariable("mindr_lep_jet", &mindr_lep_jet_1l2tau );
    reader->AddVariable("mindr_tau1_jet", &mindr_tau1_jet_1l2tau );
    reader->AddVariable("mindr_tau2_jet", &mindr_tau2_jet_1l2tau );
    reader->AddVariable("dr_lep_tau_ss", &dr_lep_tau_ss_1l2tau );
    reader->AddVariable("dr_lep_tau_lead", &dr_lep_tau_lead_1l2tau );
    reader->AddVariable("costS_tau", &costS_tau_1l2tau );
    reader->AddVariable("nBJetLoose", &nBJetLoose_1l2tau );
    reader->AddVariable("tau1_pt", &tau1_pt_1l2tau );
    reader->AddVariable("tau2_pt", &tau2_pt_1l2tau );
    reader->AddVariable("HTT", &HTT_1l2tau );
    reader->AddVariable("HadTop_pt", &HadTop_pt_1l2tau );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}

float CSV_b_1l2tau;
float qg_Wj2_1l2tau;
float pT_bWj1Wj2_1l2tau;
float m_Wj1Wj2_1l2tau;
float nllKinFit_1l2tau;
float pT_b_o_kinFit_pT_b_1l2tau;
float pT_Wj2_1l2tau;

TMVA::Reader* Book_HTT_1l2tau_MVAReader(std::string basePath, std::string weightFileName){

   TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

   reader->AddVariable("CSV_b", &CSV_b_1l2tau);
   reader->AddVariable("qg_Wj2", &qg_Wj2_1l2tau);
   reader->AddVariable("pT_bWj1Wj2", &pT_bWj1Wj2_1l2tau);
   reader->AddVariable("m_Wj1Wj2", &m_Wj1Wj2_1l2tau);
   reader->AddVariable("nllKinFit", &nllKinFit_1l2tau);
   reader->AddVariable("pT_b_o_kinFit_pT_b", &pT_b_o_kinFit_pT_b_1l2tau);
   reader->AddVariable("pT_Wj2", &pT_Wj2_1l2tau);

   reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

   return reader;

}


float avg_dr_jet_2lss1tau;
float dr_lep1_tau_2lss1tau;
float dr_lep2_tau_2lss1tau;
float dr_leps_2lss1tau;
float lep2_conePt_2lss1tau;
float mT_lep1_2lss1tau;
float mT_lep2_2lss1tau;
float mTauTauVis2_2lss1tau;
float max_lep_eta_2lss1tau;
float mbb_2lss1tau;
float mindr_lep1_jet_2lss1tau;
float mindr_lep2_jet_2lss1tau;
float mindr_tau_jet_2lss1tau;
float nJet_2lss1tau;
float ptmiss_2lss1tau;
float tau_pt_2lss1tau;
float HTT_2lss1tau;
float HadTop_pt_2lss1tau;

TMVA::Reader* Book_2lss1tau_MVAReader(std::string basePath, std::string weightFileName){

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");
    
    reader->AddVariable("avg_dr_jet", &avg_dr_jet_2lss1tau );
    reader->AddVariable("dr_lep1_tau", &dr_lep1_tau_2lss1tau );
    reader->AddVariable("dr_lep2_tau", &dr_lep2_tau_2lss1tau );
    reader->AddVariable("dr_leps", &dr_leps_2lss1tau );
    reader->AddVariable("lep2_conePt", &lep2_conePt_2lss1tau );
    reader->AddVariable("mT_lep1", &mT_lep1_2lss1tau );
    reader->AddVariable("mT_lep2", &mT_lep2_2lss1tau );
    reader->AddVariable("mTauTauVis2", &mTauTauVis2_2lss1tau );
    reader->AddVariable("max_lep_eta", &max_lep_eta_2lss1tau );
    reader->AddVariable("mbb", &mbb_2lss1tau );
    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet_2lss1tau );
    reader->AddVariable("mindr_lep2_jet", &mindr_lep2_jet_2lss1tau );
    reader->AddVariable("mindr_tau_jet", &mindr_tau_jet_2lss1tau );
    reader->AddVariable("nJet", &nJet_2lss1tau );
    reader->AddVariable("ptmiss", &ptmiss_2lss1tau );
    reader->AddVariable("tau_pt", &tau_pt_2lss1tau );
    reader->AddVariable("HTT", &HTT_2lss1tau );
    reader->AddVariable("HadTop_pt", &HadTop_pt_2lss1tau );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}

float CSV_b_2lss1tau;
float qg_Wj2_2lss1tau;
float pT_bWj1Wj2_2lss1tau;
float m_Wj1Wj2_2lss1tau;
float nllKinFit_2lss1tau;
float pT_b_o_kinFit_pT_b_2lss1tau;
float pT_Wj2_2lss1tau;

TMVA::Reader* Book_HTT_2lss1tau_MVAReader(std::string basePath, std::string weightFileName){

   TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

   reader->AddVariable("CSV_b", &CSV_b_2lss1tau );
   reader->AddVariable("qg_Wj2", &qg_Wj2_2lss1tau );
   reader->AddVariable("pT_bWj1Wj2", &pT_bWj1Wj2_2lss1tau );
   reader->AddVariable("m_Wj1Wj2", &m_Wj1Wj2_2lss1tau );
   reader->AddVariable("nllKinFit", &nllKinFit_2lss1tau );
   reader->AddVariable("pT_b_o_kinFit_pT_b", &pT_b_o_kinFit_pT_b_2lss1tau );
   reader->AddVariable("pT_Wj2", &pT_Wj2_2lss1tau );

   reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

   return reader;

}


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


float lep1_conePt_3l1tau;
float lep2_conePt_3l1tau;
float mindr_lep1_jet_3l1tau;
float max_lep_eta_3l1tau;
float mindr_tau_jet_3l1tau;
float ptmiss_3l1tau;
float tau_pt_3l1tau;
float dr_leps_3l1tau;
float mTauTauVis1_3l1tau;
float mTauTauVis2_3l1tau;
float mbb_loose_3l1tau;
float nJet_3l1tau;

TMVA::Reader* Book_3l1tau_MVAReader(std::string basePath, std::string weightFileName){

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("lep1_conePt", &lep1_conePt_3l1tau );
    reader->AddVariable("lep2_conePt", &lep2_conePt_3l1tau );
    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet_3l1tau );
    reader->AddVariable("max_lep_eta", &max_lep_eta_3l1tau );
    reader->AddVariable("mindr_tau_jet", &mindr_tau_jet_3l1tau );
    reader->AddVariable("ptmiss", &ptmiss_3l1tau );
    reader->AddVariable("tau_pt", &tau_pt_3l1tau );
    reader->AddVariable("dr_leps", &dr_leps_3l1tau );
    reader->AddVariable("mTauTauVis1", &mTauTauVis1_3l1tau );
    reader->AddVariable("mTauTauVis2", &mTauTauVis2_3l1tau );  
    reader->AddVariable("mbb_loose", &mbb_loose_3l1tau ); 
    reader->AddVariable("nJet", &nJet_3l1tau );

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
  
  TMVA::Reader* MVA_HTT_1l2tau_reader = Book_HTT_1l2tau_MVAReader("../MVA/HadTopTagger","HadTopTagger_resolved_XGB_CSV_sort_withKinFit.xml");
  if(!MVA_HTT_1l2tau_reader) std::cout << "No HTT xml file"<<std::endl;

  TMVA::Reader* MVA_HTT_2lss1tau_reader = Book_HTT_2lss1tau_MVAReader("../MVA/HadTopTagger","HadTopTagger_resolved_XGB_CSV_sort_withKinFit.xml");
  if(!MVA_HTT_2lss1tau_reader) std::cout << "No HTT xml file"<<std::endl;
 
  TMVA::Reader* MVA_1l2tau_reader = Book_1l2tau_MVAReader("../MVA/BDT_1l2tau","1l_2tau_XGB_HTT_evtLevelSUM_TTH_VT_17Var.xml");
  if(!MVA_1l2tau_reader) std::cout << "No 1l2tau xml file"<<std::endl;

  TMVA::Reader* MVA_2lss1tau_reader = Book_2lss1tau_MVAReader("../MVA/BDT_2lss1tau","2lss_1tau_XGB_HTT_evtLevelSUM_TTH_M_18Var.xml");
  if(!MVA_2lss1tau_reader) std::cout << "No 2lss1tau xml file"<<std::endl;

  TMVA::Reader* MVA_2l2tau_reader = Book_2l2tau_MVAReader("../MVA/BDT_2l2tau","2l_2tau_XGB_plainKin_evtLevelSUM_TTH_VT_13Var.xml");
  if(!MVA_2l2tau_reader) std::cout << "No 2l12au xml file"<<std::endl;

  TMVA::Reader* MVA_3l1tau_reader = Book_3l1tau_MVAReader("../MVA/BDT_3l1tau","3l_1tau_XGB_plainKin_evtLevelSUM_TTH_M_12Var.xml");
  if(!MVA_3l1tau_reader) std::cout << "No 3l1tau xml file"<<std::endl;

  const std::string tf_fileName = "./HTT_kinfit/TF_jets.root"; 
  HadTopKinFit* _kinFit = new HadTopKinFit(1, tf_fileName);

  TFile* f_new = TFile::Open(output.c_str());
  if(f_new!=0){
    cout<<output<<" already exists, please delete it before converting again"<<endl;
    return 0;
  }
  f_new = TFile::Open(output.c_str(),"RECREATE");


  std::vector<string> treename;

  treename.push_back("HTauTauTree_1l_2tau_SR");
  treename.push_back("HTauTauTree_1l_2tau_fake");
 
 /*treename.push_back("HTauTauTree_2lSS_SR");
  treename.push_back("HTauTauTree_2lSS_fake");
  treename.push_back("HTauTauTree_2lSS_flip");*/

  treename.push_back("HTauTauTree_2lSS_1tau_SR");
  treename.push_back("HTauTauTree_2lSS_1tau_fake");
  treename.push_back("HTauTauTree_2lSS_1tau_flip");

  treename.push_back("HTauTauTree_2l_2tau_SR");
  treename.push_back("HTauTauTree_2l_2tau_fake");

  /*treename.push_back("HTauTauTree_3l_SR");
  treename.push_back("HTauTauTree_3l_fake");*/

  treename.push_back("HTauTauTree_3l_1tau_SR");
  treename.push_back("HTauTauTree_3l_1tau_fake");

  /*treename.push_back("HTauTauTree_4l_SR");

  treename.push_back("HTauTauTree_4l_fake");

  treename.push_back("HTauTauTree_ttWctrl_SR");
  treename.push_back("HTauTauTree_ttWctrl_fake");
  treename.push_back("HTauTauTree_ttWctrl_flip");

  treename.push_back("HTauTauTree_ttZctrl_SR");
  treename.push_back("HTauTauTree_ttZZctrl_fake");*/

  for(unsigned int i_tree=0;i_tree<treename.size();i_tree++){ //CMP for(unsigned int i_tree=0;i_tree<treename.size();i_tree++){

    TChain *tree = new TChain(treename[i_tree].c_str());
    tree->Add(input.c_str());

    cout<<"Tree: "<<treename[i_tree]<<endl;

    Long64_t nentries = tree->GetEntries();
    std::cout<<"nentries="<<tree->GetEntries()<<std::endl;

    //old variables used
    int _category;

    std::vector<float>* _recotauh_px;
    std::vector<float>* _recotauh_py;
    std::vector<float>* _recotauh_pz;
    std::vector<float>* _recotauh_e;

    std::vector<float>* _recotauh_sel_px;
    std::vector<float>* _recotauh_sel_py;
    std::vector<float>* _recotauh_sel_pz;
    std::vector<float>* _recotauh_sel_e;
    std::vector<float>* _recotauh_sel_pt;
    std::vector<int>*   _recotauh_sel_charge;
    std::vector<float>* _recotauh_sel_eta;
    std::vector<float>* _recotauh_sel_phi;

    std::vector<float>* _recolep_sel_pt;
    std::vector<float>* _recolep_sel_conept;
    std::vector<float>* _recolep_sel_px;
    std::vector<float>* _recolep_sel_py;
    std::vector<float>* _recolep_sel_pz;
    std::vector<float>* _recolep_sel_e;
    std::vector<int>*   _recolep_sel_charge;
    std::vector<float>* _recolep_sel_eta;
    std::vector<float>* _recolep_sel_phi;

    int _n_recoPFJet;
    int _n_recoPFJet_btag_loose;
    int _n_recoPFJet_btag_medium;

    std::vector<float>* _recoPFJet_DeepCSVscore;
    std::vector<float>* _recoPFJet_px;
    std::vector<float>* _recoPFJet_py;
    std::vector<float>* _recoPFJet_pz;
    std::vector<float>* _recoPFJet_pt;
    std::vector<float>* _recoPFJet_eta;
    std::vector<float>* _recoPFJet_phi;
    std::vector<float>* _recoPFJet_e;
    std::vector<float>* _recoPFJet_QGdiscr;

    /*std::vector<float>* _recoPFJet_btag_DeepCSVscore;
    std::vector<float>* _recoPFJet_btag_px;
    std::vector<float>* _recoPFJet_btag_py;
    std::vector<float>* _recoPFJet_btag_pz;
    std::vector<float>* _recoPFJet_btag_pt;
    std::vector<float>* _recoPFJet_btag_eta;
    std::vector<float>* _recoPFJet_btag_phi;
    std::vector<float>* _recoPFJet_btag_e;
    std::vector<float>* _recoPFJet_btag_QGdiscr;*/

    /*std::vector<float>* _recoPFJet_untag_DeepCSVscore;
    std::vector<float>* _recoPFJet_untag_px;
    std::vector<float>* _recoPFJet_untag_py;
    std::vector<float>* _recoPFJet_untag_pz;
    std::vector<float>* _recoPFJet_untag_pt;
    std::vector<float>* _recoPFJet_untag_eta;
    std::vector<float>* _recoPFJet_untag_phi;
    std::vector<float>* _recoPFJet_untag_e;
    std::vector<float>* _recoPFJet_untag_QGdiscr;*/

    //float _recoPFJet_untag_best_mW; //invariant mass of the pair

    float _mindR_lep1_recoPFjet;
    float _avg_dr_jet;
    float _HTmiss;
    float _met;
    float _metphi;

    float _PFMET;
    float _PFMET_phi;

    tree->SetBranchAddress("recotauh_px",&_recotauh_px);
    tree->SetBranchAddress("recotauh_py",&_recotauh_py);
    tree->SetBranchAddress("recotauh_pz",&_recotauh_pz);
    tree->SetBranchAddress("recotauh_e",&_recotauh_e);

    tree->SetBranchAddress("recotauh_sel_px",&_recotauh_sel_px);
    tree->SetBranchAddress("recotauh_sel_py",&_recotauh_sel_py);
    tree->SetBranchAddress("recotauh_sel_pz",&_recotauh_sel_pz);
    tree->SetBranchAddress("recotauh_sel_e",&_recotauh_sel_e);
    tree->SetBranchAddress("recotauh_sel_pt",&_recotauh_sel_pt);
    tree->SetBranchAddress("recotauh_sel_charge",&_recotauh_sel_charge);
    tree->SetBranchAddress("recotauh_sel_eta",&_recotauh_sel_eta);
    tree->SetBranchAddress("recotauh_sel_phi",&_recotauh_sel_phi);

    tree->SetBranchAddress("recolep_sel_px",&_recolep_sel_px);
    tree->SetBranchAddress("recolep_sel_py",&_recolep_sel_py);
    tree->SetBranchAddress("recolep_sel_pz",&_recolep_sel_pz);
    tree->SetBranchAddress("recolep_sel_e",&_recolep_sel_e);
    tree->SetBranchAddress("recolep_sel_pt",&_recolep_sel_pt);
    tree->SetBranchAddress("recolep_sel_conept",&_recolep_sel_conept);
    tree->SetBranchAddress("recolep_sel_charge",&_recolep_sel_charge);    
    tree->SetBranchAddress("recolep_sel_eta",&_recolep_sel_eta);
    tree->SetBranchAddress("recolep_sel_phi",&_recolep_sel_phi);

    tree->SetBranchAddress("n_recoPFJet",&_n_recoPFJet);
    tree->SetBranchAddress("n_recoPFJet_btag_loose",&_n_recoPFJet_btag_loose);
    tree->SetBranchAddress("n_recoPFJet_btag_medium",&_n_recoPFJet_btag_medium);

    tree->SetBranchAddress("recoPFJet_DeepCSVscore",&_recoPFJet_DeepCSVscore);
    tree->SetBranchAddress("recoPFJet_px",&_recoPFJet_px);
    tree->SetBranchAddress("recoPFJet_py",&_recoPFJet_py);
    tree->SetBranchAddress("recoPFJet_pz",&_recoPFJet_pz);
    tree->SetBranchAddress("recoPFJet_e",&_recoPFJet_e);
    tree->SetBranchAddress("recoPFJet_pt",&_recoPFJet_pt);
    tree->SetBranchAddress("recoPFJet_eta",&_recoPFJet_eta);
    tree->SetBranchAddress("recoPFJet_phi",&_recoPFJet_phi);
    tree->SetBranchAddress("recoPFJet_QGdiscr",&_recoPFJet_QGdiscr);

    /*tree->SetBranchAddress("recoPFJet_btag_DeepCSVscore",&_recoPFJet_btag_DeepCSVscore);
    tree->SetBranchAddress("recoPFJet_btag_px",&_recoPFJet_btag_px);
    tree->SetBranchAddress("recoPFJet_btag_py",&_recoPFJet_btag_py);
    tree->SetBranchAddress("recoPFJet_btag_pz",&_recoPFJet_btag_pz);
    tree->SetBranchAddress("recoPFJet_btag_e",&_recoPFJet_btag_e);
    tree->SetBranchAddress("recoPFJet_btag_pt",&_recoPFJet_btag_pt);
    tree->SetBranchAddress("recoPFJet_btag_eta",&_recoPFJet_btag_eta);
    tree->SetBranchAddress("recoPFJet_btag_phi",&_recoPFJet_btag_phi);
    tree->SetBranchAddress("recoPFJet_btag_QGdiscr",&_recoPFJet_btag_QGdiscr);

    tree->SetBranchAddress("recoPFJet_untag_DeepCSVscore",&_recoPFJet_untag_DeepCSVscore);
    tree->SetBranchAddress("recoPFJet_untag_px",&_recoPFJet_untag_px);
    tree->SetBranchAddress("recoPFJet_untag_py",&_recoPFJet_untag_py);
    tree->SetBranchAddress("recoPFJet_untag_pz",&_recoPFJet_untag_pz);
    tree->SetBranchAddress("recoPFJet_untag_e",&_recoPFJet_untag_e);
    tree->SetBranchAddress("recoPFJet_untag_pt",&_recoPFJet_untag_pt);
    tree->SetBranchAddress("recoPFJet_untag_eta",&_recoPFJet_untag_eta);
    tree->SetBranchAddress("recoPFJet_untag_phi",&_recoPFJet_untag_phi);
    tree->SetBranchAddress("recoPFJet_untag_QGdiscr",&_recoPFJet_untag_QGdiscr);*/

    tree->SetBranchAddress("mindR_lep1_recoPFjet",&_mindR_lep1_recoPFjet);
    tree->SetBranchAddress("avg_dr_jet",&_avg_dr_jet);
    tree->SetBranchAddress("HTmiss",&_HTmiss);
    tree->SetBranchAddress("met",&_met);
    tree->SetBranchAddress("metphi",&_metphi);

    tree->SetBranchAddress("PFMET",&_PFMET);
    tree->SetBranchAddress("PFMET_phi",&_PFMET_phi);

    tree->SetBranchAddress("category",&_category);

    TTree* tree_new=(TTree*)tree->GetTree()->CloneTree(0);

    float _dr_taus_1l2tau;
    float _ptmiss_1l2tau;
    float _lep_conePt_1l2tau;
    float _mT_lep_1l2tau;
    float _mTauTauVis_1l2tau;
    float _mindr_lep_jet_1l2tau;
    float _mindr_tau1_jet_1l2tau;
    float _mindr_tau2_jet_1l2tau;
    float _dr_lep_tau_lead_1l2tau;
    float _dr_lep_tau_sublead_1l2tau;
    float _nBJetLoose_1l2tau;
    float _tau1_pt_1l2tau;
    float _tau2_pt_1l2tau;
    float _dr_lep_tau_ss_1l2tau;
    float _costS_tau_1l2tau;
    float _HTT_output_1l2tau;
    float _HTT_1l2tau;
    float _HadTop_pt_1l2tau;

    float _dr_lep1_tau_2lss1tau;
    float _dr_lep2_tau_2lss1tau;
    float _dr_leps_2lss1tau;
    float _lep2_conePt_2lss1tau;
    float _mT_lep1_2lss1tau;
    float _mT_lep2_2lss1tau;
    float _mTauTauVis2_2lss1tau;
    float _max_lep_eta_2lss1tau;
    float _mbb_2lss1tau;
    float _mindr_lep1_jet_2lss1tau;
    float _mindr_lep2_jet_2lss1tau;
    float _mindr_tau_jet_2lss1tau;
    float _nJet_2lss1tau;
    float _ptmiss_2lss1tau;
    float _tau_pt_2lss1tau;
    float _HTT_output_2lss1tau;
    float _HTT_2lss1tau;
    float _HadTop_pt_2lss1tau;

    float _mTauTauVis_2l2tau;
    float _cosThetaS_hadTau_2l2tau;
    float _tau1_pt_2l2tau;
    float _tau2_pt_2l2tau;
    float _lep2_conePt_2l2tau;
    float _mindr_lep1_jet_2l2tau;
    float _mT_lep1_2l2tau;
    float _mindr_tau_jet_2l2tau;
    float _avr_dr_lep_tau_2l2tau;
    float _dr_taus_2l2tau;
    float _is_OS_2l2tau; 
    float _nBJetLoose_2l2tau;

    float _mTauTauVis1_3l1tau;
    float _mTauTauVis2_3l1tau;
    float _max_lep_eta_3l1tau;
    float _ptmiss_3l1tau;
    float _tau_pt_3l1tau;
    float _dr_leps_3l1tau;
    float _mindr_lep1_jet_3l1tau;
    float _mindr_tau_jet_3l1tau;
    float _mbb_loose_3l1tau;
    float _lep1_conePt_3l1tau;
    float _lep2_conePt_3l1tau;
    float _nJet_3l1tau;

    float _MVA_1l2tau_output;
    float _MVA_1l2tau;
    float _MVA_2lss1tau_output;
    float _MVA_2lss1tau;
    float _MVA_2l2tau_output;
    float _MVA_2l2tau;
    float _MVA_3l1tau_output;
    float _MVA_3l1tau;

    tree_new->Branch("MVA_1l2tau_output",&_MVA_1l2tau_output,"MVA_1l2tau_output/F");
    tree_new->Branch("MVA_1l2tau",&_MVA_1l2tau,"MVA_1l2tau/F");
    tree_new->Branch("MVA_2lss1tau_output",&_MVA_2lss1tau_output,"MVA_2lss1tau_output/F");
    tree_new->Branch("MVA_2lss1tau",&_MVA_2lss1tau,"MVA_2lss1tau/F");
    tree_new->Branch("MVA_2l2tau_output",&_MVA_2l2tau_output,"MVA_2l2tau_output/F");
    tree_new->Branch("MVA_2l2tau",&_MVA_2l2tau,"MVA_2l2tau/F");
    tree_new->Branch("MVA_3l1tau_output",&_MVA_3l1tau_output,"MVA_3l1tau_output/F");
    tree_new->Branch("MVA_3l1tau",&_MVA_3l1tau,"MVA_3l1tau/F");

    //nentries=1;
    for(int i=0;i<nentries;i++){
      if(i%1000==0)
         std::cout<<"i="<<i<<std::endl;

      _dr_taus_1l2tau = 0;
      _ptmiss_1l2tau = 0;
      _lep_conePt_1l2tau = 0;
      _mT_lep_1l2tau = 0;
      _mTauTauVis_1l2tau = 0;
      _mindr_lep_jet_1l2tau = 0;
      _mindr_tau1_jet_1l2tau = 0;
      _mindr_tau2_jet_1l2tau = 0;
      _dr_lep_tau_lead_1l2tau = 0;
      _dr_lep_tau_sublead_1l2tau = 0;
      _nBJetLoose_1l2tau = 0;
      _tau1_pt_1l2tau = 0;
      _tau2_pt_1l2tau = 0;
      _dr_lep_tau_ss_1l2tau = 0;
      _costS_tau_1l2tau = 0;
      _HTT_output_1l2tau = -1;
      _HTT_1l2tau = -1;
      _HadTop_pt_1l2tau = 0;

      _dr_lep1_tau_2lss1tau = 0;
      _dr_lep2_tau_2lss1tau = 0;
      _dr_leps_2lss1tau = 0;
      _lep2_conePt_2lss1tau = 0;
      _mT_lep1_2lss1tau = 0;
      _mT_lep2_2lss1tau = 0;
      _mTauTauVis2_2lss1tau = 0;
      _max_lep_eta_2lss1tau = 0;
      _mbb_2lss1tau = 0;
      _mindr_lep1_jet_2lss1tau = 0;
      _mindr_lep2_jet_2lss1tau = 0;
      _mindr_tau_jet_2lss1tau = 0;
      _nJet_2lss1tau = 0;
      _ptmiss_2lss1tau = 0;
      _tau_pt_2lss1tau = 0;
      _HTT_output_2lss1tau = -1;
      _HTT_2lss1tau = -1;
      _HadTop_pt_2lss1tau = 0;

      _mTauTauVis_2l2tau = 0;
      _cosThetaS_hadTau_2l2tau = 0;
      _tau1_pt_2l2tau = 0;
      _tau2_pt_2l2tau = 0;
      _lep2_conePt_2l2tau = 0;
      _mindr_lep1_jet_2l2tau = 0;
      _mT_lep1_2l2tau = 0;
      _mindr_tau_jet_2l2tau = 0;
      _avr_dr_lep_tau_2l2tau = 0;
      _dr_taus_2l2tau = 0;
      _is_OS_2l2tau = 0; 
      _nBJetLoose_2l2tau = 0;

      _mTauTauVis1_3l1tau = 0;
      _mTauTauVis2_3l1tau = 0;
      _max_lep_eta_3l1tau = 0;
      _ptmiss_3l1tau = 0;
      _tau_pt_3l1tau = 0;
      _dr_leps_3l1tau = 0;
      _mindr_lep1_jet_3l1tau = 0;
      _mindr_tau_jet_3l1tau = 0;
      _mbb_loose_3l1tau = 0;
      _lep1_conePt_3l1tau = 0;
      _lep2_conePt_3l1tau = 0;
      _nJet_3l1tau = 0;

      _MVA_1l2tau_output = -1;
      _MVA_1l2tau = -1;
      _MVA_2lss1tau_output = -1;
      _MVA_2lss1tau = -1;
      _MVA_2l2tau_output = -1;
      _MVA_2l2tau = -1;
      _MVA_3l1tau_output = -1;
      _MVA_3l1tau = -1;

      //old variables used
      _recotauh_px = 0;
      _recotauh_py = 0;
      _recotauh_pz = 0;
      _recotauh_e = 0;

      _recotauh_sel_px = 0;
      _recotauh_sel_py = 0;
      _recotauh_sel_pz = 0;
      _recotauh_sel_e = 0;
      _recotauh_sel_pt = 0;
      _recotauh_sel_charge = 0;
      _recotauh_sel_eta = 0;
      _recotauh_sel_phi = 0;

      _recolep_sel_px = 0;
      _recolep_sel_py = 0;
      _recolep_sel_pz = 0;
      _recolep_sel_e = 0;
      _recolep_sel_pt = 0;
      _recolep_sel_conept = 0;   
      _recolep_sel_charge = 0;
      _recolep_sel_eta = 0;
      _recolep_sel_phi = 0;

      _n_recoPFJet = 0;
      _n_recoPFJet_btag_loose = 0;
      _n_recoPFJet_btag_medium = 0;

      _recoPFJet_DeepCSVscore = 0;
      _recoPFJet_px = 0;
      _recoPFJet_py = 0;
      _recoPFJet_pz = 0;
      _recoPFJet_e = 0;
      _recoPFJet_pt = 0;
      _recoPFJet_eta = 0;
      _recoPFJet_phi = 0;
      _recoPFJet_QGdiscr = 0;

      /*_recoPFJet_btag_DeepCSVscore = 0;
      _recoPFJet_btag_px = 0;
      _recoPFJet_btag_py = 0;
      _recoPFJet_btag_pz = 0;
      _recoPFJet_btag_e = 0;
      _recoPFJet_btag_pt = 0;
      _recoPFJet_btag_eta = 0;
      _recoPFJet_btag_phi = 0;
      _recoPFJet_btag_QGdiscr = 0;*/

      _mindR_lep1_recoPFjet = 0;

      _HTmiss = 0;
      _met = 0;

      _PFMET = 0;
      _PFMET_phi = 0;

      tree->GetEntry(i);

      // *********************
      // ****** 1l2tau *******
      // *********************

      if(_category==20 || _category==50){
        
        TLorentzVector tau1((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
        TLorentzVector tau2((*_recotauh_sel_px)[1],(*_recotauh_sel_py)[1],(*_recotauh_sel_pz)[1],(*_recotauh_sel_e)[1]);
        TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);

        _dr_taus_1l2tau = tau1.DeltaR(tau2);
        _ptmiss_1l2tau = _PFMET;
        _lep_conePt_1l2tau = (*_recolep_sel_conept)[0];
        _mT_lep_1l2tau = sqrt(2*((*_recolep_sel_conept)[0])*_PFMET*(1-cos(((*_recolep_sel_phi)[0])-_PFMET_phi)));
        _mTauTauVis_1l2tau = (tau1+tau2).M();

        float _mindR = 999.;
        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){
          TLorentzVector jet((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
          TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
          float _dR = jet.DeltaR(lep1); 
          if(_dR < _mindR){
              _mindR = _dR;
          }
        }
        _mindr_lep_jet_1l2tau = _mindR;

        float _mindR1 = 999.;
        float _mindR2 = 999.;
        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){
          TLorentzVector jet((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
          TLorentzVector tau1((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
          TLorentzVector tau2((*_recotauh_sel_px)[1],(*_recotauh_sel_py)[1],(*_recotauh_sel_pz)[1],(*_recotauh_sel_e)[1]);
          float _dR1 = jet.DeltaR(tau1); 
          float _dR2 = jet.DeltaR(tau2); 
          if(_dR1<_mindR1){
               _mindR1 = _dR1;
          }
          if(_dR2<_mindR2){
               _mindR2 = _dR2;
          }
        }
        _mindr_tau1_jet_1l2tau = _mindR1;
        _mindr_tau2_jet_1l2tau = _mindR2;

        _dr_lep_tau_lead_1l2tau = tau1.DeltaR(lep1);
        //_dr_lep_tau_sublead_1l2tau = tau2.DeltaR(lep1);

        _nBJetLoose_1l2tau = _n_recoPFJet_btag_loose;

        _tau1_pt_1l2tau = tau1.Pt();
        _tau2_pt_1l2tau = tau2.Pt();

        _dr_lep_tau_ss_1l2tau = ( ((*_recolep_sel_charge)[0])==((*_recotauh_sel_charge)[0]) ) ? _dr_lep_tau_lead_1l2tau : _dr_lep_tau_sublead_1l2tau;
        _costS_tau_1l2tau = abs(tau1.CosTheta());

        //HTT variables
        for(unsigned int i_bjet=0; i_bjet<(*_recoPFJet_e).size(); i_bjet++){
          TLorentzVector bjet ( (*_recoPFJet_px)[i_bjet], (*_recoPFJet_py)[i_bjet], (*_recoPFJet_pz)[i_bjet], (*_recoPFJet_e)[i_bjet] );
          LorentzVector bjet_lv ( (*_recoPFJet_pt)[i_bjet], (*_recoPFJet_eta)[i_bjet], (*_recoPFJet_phi)[i_bjet],bjet.M() );
                 
          for(unsigned int i_wjet1=0; i_wjet1<(*_recoPFJet_e).size(); i_wjet1++){ 
            TLorentzVector wjet1 ( (*_recoPFJet_px)[i_wjet1], (*_recoPFJet_py)[i_wjet1], (*_recoPFJet_pz)[i_wjet1], (*_recoPFJet_e)[i_wjet1] );
            LorentzVector wjet1_lv ( (*_recoPFJet_pt)[i_wjet1], (*_recoPFJet_eta)[i_wjet1], (*_recoPFJet_phi)[i_wjet1],bjet.M() );

            if (wjet1 == bjet) continue;
            
            for(unsigned int i_wjet2=i_wjet1+1; i_wjet2<(*_recoPFJet_e).size(); i_wjet2++){ //_recoPFJet_untag_Wtag_px.size()
              TLorentzVector wjet2 ( (*_recoPFJet_px)[i_wjet2], (*_recoPFJet_py)[i_wjet2], (*_recoPFJet_pz)[i_wjet2], (*_recoPFJet_e)[i_wjet2] );
              LorentzVector wjet2_lv ( (*_recoPFJet_pt)[i_wjet2], (*_recoPFJet_eta)[i_wjet2], (*_recoPFJet_phi)[i_wjet2],bjet.M() );

              if (wjet2 == bjet) continue;
              if (wjet2 == wjet1) continue;

              //cout<<"b " << _recoPFJet_btag_DeepCSVscore[i_bjet] << ",wjet1 "<<_recoPFJet_untag_Wtag_DeepCSVscore[i_wjet1]<<",wjet2 "<<_recoPFJet_untag_Wtag_DeepCSVscore[i_wjet2]<<endl;
              /*cout<<"-- Testing ---"<<endl;
              cout<<"b jet: pt "<< bjet.Pt() << ", eta "<< (*_recoPFJet_eta)[i_bjet] << ", CSV "<<(*_recoPFJet_DeepCSVscore)[i_bjet]<<endl;
              cout<<"w jet1: pt "<< wjet1.Pt() << ", eta "<< (*_recoPFJet_eta)[i_wjet1] << ", CSV "<<(*_recoPFJet_DeepCSVscore)[i_wjet1]<<endl;
              cout<<"w jet2: pt "<< wjet2.Pt() << ", eta "<< (*_recoPFJet_eta)[i_wjet2] << ", CSV "<<(*_recoPFJet_DeepCSVscore)[i_wjet2]<<endl;*/

              CSV_b_1l2tau = 0;
              qg_Wj2_1l2tau = 0;
              pT_bWj1Wj2_1l2tau = 0;
              m_Wj1Wj2_1l2tau = 0;
              pT_Wj2_1l2tau = 0;
              nllKinFit_1l2tau = 0;
              pT_b_o_kinFit_pT_b_1l2tau = 0;

              // variables for HTT
              CSV_b_1l2tau = (*_recoPFJet_DeepCSVscore)[i_bjet];
              qg_Wj2_1l2tau = (*_recoPFJet_QGdiscr)[i_wjet2];
              pT_Wj2_1l2tau = wjet2.Pt();
              _kinFit->fit(bjet_lv,wjet1_lv,wjet2_lv);
              nllKinFit_1l2tau = _kinFit->nll();
              pT_bWj1Wj2_1l2tau = (bjet+wjet1+wjet2).Pt();
              m_Wj1Wj2_1l2tau = (wjet1+wjet2).M();
              pT_b_o_kinFit_pT_b_1l2tau = (bjet.Pt()) / (_kinFit->fittedBJet().Pt());

              /*cout<<"CSV_b "<<CSV_b_1l2tau<<endl;
              cout<<"qg_Wj2 "<<qg_Wj2_1l2tau<<endl;
              cout<<"pT_bWj1Wj2 "<<pT_bWj1Wj2_1l2tau<<endl;
              cout<<"pT_Wj2 "<<pT_Wj2_1l2tau<<endl;
              cout<<"m_Wj1Wj2 "<<m_Wj1Wj2_1l2tau<<endl;
              cout<<"nllKinFit "<<nllKinFit_1l2tau<<endl;
              cout<<"pT b "<<(bjet.Pt())<<endl;
              cout<<"kin fit pt b "<<(_kinFit->fittedBJet().Pt())<<endl;
              cout<<"pT_b_o_kinFit_pT_b "<<pT_b_o_kinFit_pT_b_1l2tau <<endl;*/

              float _my_HadTop_pt_1l2tau = (bjet+wjet1+wjet2).Pt();
              float _my_HTT_output_1l2tau = MVA_HTT_1l2tau_reader->EvaluateMVA("BDTG method");
              
              float _my_HTT_1l2tau = 1. / (1. + sqrt((1. - _my_HTT_output_1l2tau) / (1. + _my_HTT_output_1l2tau))); 

              /*cout<<"htt for this jet triplet: "<<_my_HTT_1l2tau<<endl;
              cout<<"had top pt for this jet triplet: "<<_my_HadTop_pt_1l2tau<<endl;*/
              
              if (_my_HTT_output_1l2tau > _HTT_output_1l2tau){
                _HTT_output_1l2tau = _my_HTT_output_1l2tau;
                _HadTop_pt_1l2tau = _my_HadTop_pt_1l2tau;
              }
              
            }      
          }
        }

        _HTT_1l2tau = 1. / (1. + sqrt((1. - _HTT_output_1l2tau) / (1. + _HTT_output_1l2tau))); 

        avg_dr_jet_1l2tau = _avg_dr_jet;
        dr_taus_1l2tau = _dr_taus_1l2tau;
        ptmiss_1l2tau = _ptmiss_1l2tau;
        lep_conePt_1l2tau = _lep_conePt_1l2tau;
        mT_lep_1l2tau = _mT_lep_1l2tau;
        mTauTauVis_1l2tau = _mTauTauVis_1l2tau;
        mindr_lep_jet_1l2tau = _mindr_lep_jet_1l2tau;
        mindr_tau1_jet_1l2tau = _mindr_tau1_jet_1l2tau;
        mindr_tau2_jet_1l2tau = _mindr_tau2_jet_1l2tau;
        dr_lep_tau_lead_1l2tau = _dr_lep_tau_lead_1l2tau;
        //dr_lep_tau_sublead_1l2tau = _dr_lep_tau_sublead_1l2tau;
        nBJetLoose_1l2tau = _nBJetLoose_1l2tau;
        tau1_pt_1l2tau = _tau1_pt_1l2tau;
        tau2_pt_1l2tau = _tau2_pt_1l2tau;
        dr_lep_tau_ss_1l2tau = _dr_lep_tau_ss_1l2tau;
        costS_tau_1l2tau = _costS_tau_1l2tau;

        HTT_1l2tau = _HTT_1l2tau;
        HadTop_pt_1l2tau = _HadTop_pt_1l2tau;   

        //synced in all variables but slightly different BDT output (??)
        /*cout<<"---"<<endl;
        cout<<"avg_dr_jet "<<avg_dr_jet_1l2tau<<",dr_taus "<<dr_taus_1l2tau<<",ptmiss "<<ptmiss_1l2tau<<",lep_conePt "<<lep_conePt_1l2tau<<",mT_lep "<<mT_lep_1l2tau<<endl;
        cout<<"mTauTauVis "<<mTauTauVis_1l2tau<<",mindr_lep_jet "<<mindr_lep_jet_1l2tau<<",mindr_tau1_jet "<<mindr_tau1_jet_1l2tau<<",mindr_tau2_jet "<<mindr_tau2_jet_1l2tau<<endl;
        cout<<"dr_lep_tau_lead "<<dr_lep_tau_lead_1l2tau<<",dr_lep_tau_sublead "<<dr_lep_tau_sublead_1l2tau<<",nBJetLoose "<<nBJetLoose_1l2tau<<endl;
        cout<<"tau1_pt "<<tau1_pt_1l2tau<<",tau2_pt "<<tau2_pt_1l2tau<<",dr_lep_tau_ss "<<dr_lep_tau_ss_1l2tau<<",costS_tau "<<costS_tau_1l2tau<<endl;
        cout<<"HTT "<<HTT_1l2tau<<", HadTop_pt "<<HadTop_pt_1l2tau<<endl; */

        _MVA_1l2tau_output = MVA_1l2tau_reader->EvaluateMVA("BDTG method");
        _MVA_1l2tau = 1. / (1. + sqrt((1. - _MVA_1l2tau_output) / (1. + _MVA_1l2tau_output)));

        //cout<<"_MVA_1l2tau "<< _MVA_1l2tau<<endl;
 
     }



      // *********************
      // ***** 2lss1tau ******
      // *********************

     if(_category==11 || _category==41 || _category==-11){
        
        TLorentzVector tau1((*_recotauh_px)[0],(*_recotauh_py)[0],(*_recotauh_pz)[0],(*_recotauh_e)[0]);
        TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
        TLorentzVector lep2((*_recolep_sel_px)[1],(*_recolep_sel_py)[1],(*_recolep_sel_pz)[1],(*_recolep_sel_e)[1]);

        _dr_lep1_tau_2lss1tau = tau1.DeltaR(lep1);
        _dr_lep2_tau_2lss1tau = tau1.DeltaR(lep2);
        _dr_leps_2lss1tau = lep1.DeltaR(lep2);
        _lep2_conePt_2lss1tau = (*_recolep_sel_conept)[1];
        _mT_lep1_2lss1tau = sqrt(2*((*_recolep_sel_conept)[0])*_PFMET*(1-cos(((*_recolep_sel_phi)[0])-_PFMET_phi)));
        _mT_lep2_2lss1tau = sqrt(2*((*_recolep_sel_conept)[1])*_PFMET*(1-cos(((*_recolep_sel_phi)[1])-_PFMET_phi)));
        _mTauTauVis2_2lss1tau = (tau1+lep2).M();

        float _maxEta = -999.;
        for(unsigned int i_lep=0;i_lep<(*_recolep_sel_pt).size();i_lep++){
          float _eta_lep = abs((*_recolep_sel_eta)[i_lep]);
          if(_eta_lep > _maxEta){
              _maxEta = _eta_lep;
          }
        }
        _max_lep_eta_2lss1tau = _maxEta;

        float _mindR1 = 999.;
        float _mindR2 = 999.;

        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){

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

        _mindr_lep1_jet_2lss1tau = _mindR1;
        _mindr_lep2_jet_2lss1tau = _mindR2;

        float _mindR = 999.;
        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){

          TLorentzVector jet((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
          TLorentzVector tau((*_recotauh_px)[0],(*_recotauh_py)[0],(*_recotauh_pz)[0],(*_recotauh_e)[0]);

          float _dR = jet.DeltaR(tau);
          if(_dR<_mindR){
              _mindR = _dR;
          }

        }

        _mindr_tau_jet_2lss1tau = _mindR;
        _nJet_2lss1tau = _n_recoPFJet;
        _ptmiss_2lss1tau = _PFMET;
        _tau_pt_2lss1tau = tau1.Pt();
        
        vector< pair<int,TLorentzVector> > reco_jets;
        vector< pair<int,float> > i_jet_DeepCSV_pairs;

        vector<float> _recoPFJet_btag_e;
        vector<float> _recoPFJet_btag_px;
        vector<float> _recoPFJet_btag_py;
        vector<float> _recoPFJet_btag_pz;

        vector<float> _recoPFJet_untag_e;
        vector<float> _recoPFJet_untag_px;
        vector<float> _recoPFJet_untag_py;
        vector<float> _recoPFJet_untag_pz;

        for(unsigned int i_jet=0; i_jet<_recoPFJet_px->size(); i_jet++){
          TLorentzVector recoPFJet ( (*_recoPFJet_px)[i_jet] , (*_recoPFJet_py)[i_jet] , (*_recoPFJet_pz)[i_jet] , (*_recoPFJet_e)[i_jet] );
          pair<int,TLorentzVector> jet_pair = make_pair(i_jet, recoPFJet);
          float DeepCSVscore = (*_recoPFJet_DeepCSVscore)[i_jet];
          pair<int,float> DeepCSV_pair = make_pair(i_jet,DeepCSVscore);
          reco_jets.push_back(jet_pair);
          i_jet_DeepCSV_pairs.push_back(DeepCSV_pair);
        }

        sort(i_jet_DeepCSV_pairs.begin(), i_jet_DeepCSV_pairs.end(), DeepCSV_comparison_pairs);

        for(unsigned int i_PFJet=0; i_PFJet<i_jet_DeepCSV_pairs.size(); i_PFJet++){

          int i_jet = i_jet_DeepCSV_pairs[i_PFJet].first;
          float DeepCSVscore= i_jet_DeepCSV_pairs[i_PFJet].second;

          if(_n_recoPFJet>=4){

            if (i_PFJet<2){
              _recoPFJet_btag_e.push_back( (*_recoPFJet_e)[i_jet] );
              _recoPFJet_btag_px.push_back( (*_recoPFJet_px)[i_jet] );
              _recoPFJet_btag_py.push_back( (*_recoPFJet_py)[i_jet] );
              _recoPFJet_btag_pz.push_back( (*_recoPFJet_pz)[i_jet] );
            }
            else{
              _recoPFJet_untag_e.push_back( (*_recoPFJet_e)[i_jet] );
              _recoPFJet_untag_px.push_back( (*_recoPFJet_px)[i_jet] );
              _recoPFJet_untag_py.push_back( (*_recoPFJet_py)[i_jet] );
              _recoPFJet_untag_pz.push_back( (*_recoPFJet_pz)[i_jet] );
            }
          }
          else{
            if (i_PFJet<1){
              _recoPFJet_btag_e.push_back( (*_recoPFJet_e)[i_jet] );
              _recoPFJet_btag_px.push_back( (*_recoPFJet_px)[i_jet] );
              _recoPFJet_btag_py.push_back( (*_recoPFJet_py)[i_jet] );
              _recoPFJet_btag_pz.push_back( (*_recoPFJet_pz)[i_jet] );
            }
            else{
              _recoPFJet_untag_e.push_back( (*_recoPFJet_e)[i_jet] );
              _recoPFJet_untag_px.push_back( (*_recoPFJet_px)[i_jet] );
              _recoPFJet_untag_py.push_back( (*_recoPFJet_py)[i_jet] );
              _recoPFJet_untag_pz.push_back( (*_recoPFJet_pz)[i_jet] );
            }

          }

        }

        if (_recoPFJet_btag_px.size()>1){          
          TLorentzVector bjet1 ( _recoPFJet_btag_px[0], _recoPFJet_btag_py[0], _recoPFJet_btag_pz[0], _recoPFJet_btag_e[0] );
          TLorentzVector bjet2 ( _recoPFJet_btag_px[1], _recoPFJet_btag_py[1], _recoPFJet_btag_pz[1], _recoPFJet_btag_e[1] );
          _mbb_2lss1tau = (_n_recoPFJet_btag_medium>1) ? (bjet1+bjet2).M() : -1;

        }
        else{
          TLorentzVector bjet1 ( _recoPFJet_btag_px[0], _recoPFJet_btag_py[0], _recoPFJet_btag_pz[0], _recoPFJet_btag_e[0] );
          TLorentzVector bjet2 ( _recoPFJet_untag_px[0], _recoPFJet_untag_py[0], _recoPFJet_untag_pz[0], _recoPFJet_untag_e[0] );
          _mbb_2lss1tau = (_n_recoPFJet_btag_medium>1) ? (bjet1+bjet2).M() : -1;
        }


        //HTT variables
        for(unsigned int i_bjet=0; i_bjet<(*_recoPFJet_e).size(); i_bjet++){
          TLorentzVector bjet ( (*_recoPFJet_px)[i_bjet], (*_recoPFJet_py)[i_bjet], (*_recoPFJet_pz)[i_bjet], (*_recoPFJet_e)[i_bjet] );
          LorentzVector bjet_lv ( (*_recoPFJet_pt)[i_bjet], (*_recoPFJet_eta)[i_bjet], (*_recoPFJet_phi)[i_bjet],bjet.M() );
                 
          for(unsigned int i_wjet1=0; i_wjet1<(*_recoPFJet_e).size(); i_wjet1++){ 
            TLorentzVector wjet1 ( (*_recoPFJet_px)[i_wjet1], (*_recoPFJet_py)[i_wjet1], (*_recoPFJet_pz)[i_wjet1], (*_recoPFJet_e)[i_wjet1] );
            LorentzVector wjet1_lv ( (*_recoPFJet_pt)[i_wjet1], (*_recoPFJet_eta)[i_wjet1], (*_recoPFJet_phi)[i_wjet1],bjet.M() );

            if (wjet1 == bjet) continue;
            
            for(unsigned int i_wjet2=i_wjet1+1; i_wjet2<(*_recoPFJet_e).size(); i_wjet2++){ //_recoPFJet_untag_Wtag_px.size()
              TLorentzVector wjet2 ( (*_recoPFJet_px)[i_wjet2], (*_recoPFJet_py)[i_wjet2], (*_recoPFJet_pz)[i_wjet2], (*_recoPFJet_e)[i_wjet2] );
              LorentzVector wjet2_lv ( (*_recoPFJet_pt)[i_wjet2], (*_recoPFJet_eta)[i_wjet2], (*_recoPFJet_phi)[i_wjet2],bjet.M() );

              if (wjet2 == bjet) continue;
              if (wjet2 == wjet1) continue;

              /*cout<<"-- Testing ---"<<endl;
              cout<<"b jet: pt "<< bjet.Pt() << ", eta "<< (*_recoPFJet_eta)[i_bjet] << ", CSV "<<(*_recoPFJet_DeepCSVscore)[i_bjet]<<endl;
              cout<<"w jet1: pt "<< wjet1.Pt() << ", eta "<< (*_recoPFJet_eta)[i_wjet1] << ", CSV "<<(*_recoPFJet_DeepCSVscore)[i_wjet1]<<endl;
              cout<<"w jet2: pt "<< wjet2.Pt() << ", eta "<< (*_recoPFJet_eta)[i_wjet2] << ", CSV "<<(*_recoPFJet_DeepCSVscore)[i_wjet2]<<endl;*/

              CSV_b_2lss1tau = 0;
              qg_Wj2_2lss1tau = 0;
              pT_bWj1Wj2_2lss1tau = 0;
              m_Wj1Wj2_2lss1tau = 0;
              pT_Wj2_2lss1tau = 0;
              nllKinFit_2lss1tau = 0;
              pT_b_o_kinFit_pT_b_2lss1tau = 0;

              // variables for HTT
              CSV_b_2lss1tau = (*_recoPFJet_DeepCSVscore)[i_bjet];
              qg_Wj2_2lss1tau = (*_recoPFJet_QGdiscr)[i_wjet2];
              pT_Wj2_2lss1tau = wjet2.Pt();
              _kinFit->fit(bjet_lv,wjet1_lv,wjet2_lv);
              nllKinFit_2lss1tau = _kinFit->nll();
              pT_bWj1Wj2_2lss1tau = (bjet+wjet1+wjet2).Pt();
              m_Wj1Wj2_2lss1tau = (wjet1+wjet2).M();
              pT_b_o_kinFit_pT_b_2lss1tau = (bjet.Pt()) / (_kinFit->fittedBJet().Pt());

              /*cout<<"CSV_b "<<CSV_b_2lss1tau<<endl;
              cout<<"qg_Wj2 "<<qg_Wj2_2lss1tau<<endl;
              cout<<"pT_bWj1Wj2 "<<pT_bWj1Wj2_2lss1tau<<endl;
              cout<<"pT_Wj2 "<<pT_Wj2_2lss1tau<<endl;
              cout<<"m_Wj1Wj2 "<<m_Wj1Wj2_2lss1tau<<endl;
              cout<<"nllKinFit "<<nllKinFit_2lss1tau<<endl;
              cout<<"pT b "<<(bjet.Pt())<<endl;
              cout<<"kin fit pt b "<<(_kinFit->fittedBJet().Pt())<<endl;
              cout<<"pT_b_o_kinFit_pT_b "<<pT_b_o_kinFit_pT_b_2lss1tau <<endl;*/

              float _my_HadTop_pt_2lss1tau = (bjet+wjet1+wjet2).Pt();
              float _my_HTT_output_2lss1tau = MVA_HTT_2lss1tau_reader->EvaluateMVA("BDTG method");
              
              float _my_HTT_2lss1tau = 1. / (1. + sqrt((1. - _my_HTT_output_2lss1tau) / (1. + _my_HTT_output_2lss1tau))); 

              /*cout<<"htt for this jet triplet: "<<_my_HTT_2lss1tau<<endl;
              cout<<"had top pt for this jet triplet: "<<_my_HadTop_pt_2lss1tau<<endl;*/
              
              if (_my_HTT_output_2lss1tau > _HTT_output_2lss1tau){
                _HTT_output_2lss1tau = _my_HTT_output_2lss1tau;
                _HadTop_pt_2lss1tau = _my_HadTop_pt_2lss1tau;
              }

            }      
          }
        }

        _HTT_2lss1tau = 1. / (1. + sqrt((1. - _HTT_output_2lss1tau) / (1. + _HTT_output_2lss1tau))); 
      
        avg_dr_jet_2lss1tau = _avg_dr_jet; 
        dr_lep1_tau_2lss1tau = _dr_lep1_tau_2lss1tau; 
        dr_lep2_tau_2lss1tau = _dr_lep2_tau_2lss1tau; 
        dr_leps_2lss1tau = _dr_leps_2lss1tau;
        lep2_conePt_2lss1tau = _lep2_conePt_2lss1tau; 
        mT_lep1_2lss1tau = _mT_lep1_2lss1tau; 
        mT_lep2_2lss1tau = _mT_lep2_2lss1tau; 
        mTauTauVis2_2lss1tau = _mTauTauVis2_2lss1tau; 
        max_lep_eta_2lss1tau = _max_lep_eta_2lss1tau; 
        mbb_2lss1tau = _mbb_2lss1tau; 
        mindr_lep1_jet_2lss1tau = _mindr_lep1_jet_2lss1tau; 
        mindr_lep2_jet_2lss1tau = _mindr_lep2_jet_2lss1tau; 
        mindr_tau_jet_2lss1tau = _mindr_tau_jet_2lss1tau; 
        nJet_2lss1tau = _nJet_2lss1tau; 
        ptmiss_2lss1tau = _ptmiss_2lss1tau; 
        tau_pt_2lss1tau = _tau_pt_2lss1tau; 

        HTT_2lss1tau = _HTT_2lss1tau;
        HadTop_pt_2lss1tau = _HadTop_pt_2lss1tau;     

        //all synced! 
        /*cout<<"avg_dr_jet "<<avg_dr_jet_2lss1tau<<",dr_lep1_tau "<<dr_lep1_tau_2lss1tau<<",dr_lep2_tau "<<dr_lep2_tau_2lss1tau<<",dr_leps "<<dr_leps_2lss1tau<<endl;
        cout<<"lep2_conePt "<<lep2_conePt_2lss1tau<<",mT_lep1 "<<mT_lep1_2lss1tau<<",mT_lep2 "<<mT_lep2_2lss1tau<<",mTauTauVis2 "<<mTauTauVis2_2lss1tau<<endl;
        cout<<"max_lep_eta "<<max_lep_eta_2lss1tau<<",mbb "<<mbb_2lss1tau<<",mindr_lep1_jet "<<mindr_lep1_jet_2lss1tau<<",mindr_lep2_jet "<<mindr_lep2_jet_2lss1tau<<endl;
        cout<<"mindr_tau_jet "<<mindr_tau_jet_2lss1tau<<",nJet "<<nJet_2lss1tau<<",ptmiss "<<ptmiss_2lss1tau<<"tau_pt "<<tau_pt_2lss1tau<<endl;
        cout<<"HTT "<<HTT_2lss1tau<<",HadTop_pt "<<HadTop_pt_2lss1tau<<endl;*/


        _MVA_2lss1tau_output = MVA_2lss1tau_reader->EvaluateMVA("BDTG method");
        _MVA_2lss1tau = 1. / (1. + sqrt((1. - _MVA_2lss1tau_output) / (1. + _MVA_2lss1tau_output)));
        /*cout<<"HTT_2lss1tau "<<_HTT_2lss1tau<<endl;
        cout<<"MVA 2lss1tau "<<_MVA_2lss1tau<<endl;*/

     }


      // *********************
      // ****** 2l2tau *******
      // *********************
     
     if(_category==21 || _category==51){
        
        TLorentzVector tau1((*_recotauh_px)[0],(*_recotauh_py)[0],(*_recotauh_pz)[0],(*_recotauh_e)[0]);
        TLorentzVector tau2((*_recotauh_px)[1],(*_recotauh_py)[1],(*_recotauh_pz)[1],(*_recotauh_e)[1]);
        TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
        TLorentzVector lep2((*_recolep_sel_px)[1],(*_recolep_sel_py)[1],(*_recolep_sel_pz)[1],(*_recolep_sel_e)[1]);
        
        _mTauTauVis_2l2tau = (tau1+tau2).M();
        _cosThetaS_hadTau_2l2tau = abs(tau1.CosTheta());
        _tau1_pt_2l2tau = tau1.Pt();
        _tau2_pt_2l2tau = tau2.Pt();
        _lep2_conePt_2l2tau = (*_recolep_sel_conept)[1];
        _mindr_lep1_jet_2l2tau = _mindR_lep1_recoPFjet;
        _mT_lep1_2l2tau = sqrt(2*((*_recolep_sel_conept)[0])*_PFMET*(1-cos(((*_recolep_sel_phi)[0])-_PFMET_phi)));

        float _mindR = 999.;
        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){
          TLorentzVector jet((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
          for(unsigned int i_tau=0;i_tau<(*_recotauh_sel_pt).size();i_tau++){
            TLorentzVector tau((*_recotauh_sel_px)[i_tau],(*_recotauh_sel_py)[i_tau],(*_recotauh_sel_pz)[i_tau],(*_recotauh_sel_e)[i_tau]);
            float _dR = jet.DeltaR(tau);
            if(_dR<_mindR){
              _mindR = _dR;
            }
          }
        }

        _mindr_tau_jet_2l2tau = _mindR;

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
        _avr_dr_lep_tau_2l2tau = _dR_lep_tau / _n_lep_tau_pairs;

        _dr_taus_2l2tau = tau1.DeltaR(tau2);
        _is_OS_2l2tau = ( (*_recotauh_sel_charge)[0]*(*_recotauh_sel_charge)[1] < 0 );
        _nBJetLoose_2l2tau = _n_recoPFJet_btag_loose;

        mTauTauVis_2l2tau = _mTauTauVis_2l2tau;
        cosThetaS_hadTau_2l2tau = _cosThetaS_hadTau_2l2tau;
        tau1_pt_2l2tau = _tau1_pt_2l2tau;
        tau2_pt_2l2tau = _tau2_pt_2l2tau;
        lep2_conePt_2l2tau = _lep2_conePt_2l2tau;
        mindr_lep1_jet_2l2tau = _mindr_lep1_jet_2l2tau;
        mT_lep1_2l2tau = _mT_lep1_2l2tau;
        mindr_tau_jet_2l2tau = _mindr_tau_jet_2l2tau;
        avg_dr_jet_2l2tau = _avg_dr_jet;
        avr_dr_lep_tau_2l2tau = _avr_dr_lep_tau_2l2tau;
        dr_taus_2l2tau = _dr_taus_2l2tau;
        is_OS_2l2tau = _is_OS_2l2tau;
        nBJetLoose_2l2tau = _nBJetLoose_2l2tau;


        //--> not synced with Tallinn in nBJetLoose; not synced with Cornell in mT_lep1

        /*cout<<"---"<<endl;
        cout<<"mTauTauVis "<<mTauTauVis_2l2tau<<",cosThetaS_hadTau "<<cosThetaS_hadTau_2l2tau <<",is_OS "<<is_OS_2l2tau<<",mindr_tau_jet "<<mindr_tau_jet_2l2tau<<",mT_lep1 "<<mT_lep1_2l2tau<<endl;
        cout<<"mindr_lep1_jet "<<mindr_lep1_jet_2l2tau<<",tau1_pt "<<tau1_pt_2l2tau<<",tau2_pt "<<tau2_pt_2l2tau<<",dr_taus "<<dr_taus_2l2tau<<",avg_dr_jet "<<avg_dr_jet_2l2tau<<endl;
        cout<<"lep2_conePt "<<lep2_conePt_2l2tau<<",avr_dr_lep_tau "<<avr_dr_lep_tau_2l2tau<<",nBJetLoose "<<nBJetLoose_2l2tau<<endl;*/

        _MVA_2l2tau_output = MVA_2l2tau_reader->EvaluateMVA("BDTG method");
        _MVA_2l2tau = 1. / (1. + sqrt((1. - _MVA_2l2tau_output) / (1. + _MVA_2l2tau_output)));
       
        //cout<<"MVA_2l2tau = "<<_MVA_2l2tau<<endl;
 
     }




      // *********************
      // ****** 3l1tau *******
      // *********************
     
     if(_category==16 || _category==46){
        
        TLorentzVector tau1((*_recotauh_px)[0],(*_recotauh_py)[0],(*_recotauh_pz)[0],(*_recotauh_e)[0]);
        TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
        TLorentzVector lep2((*_recolep_sel_px)[1],(*_recolep_sel_py)[1],(*_recolep_sel_pz)[1],(*_recolep_sel_e)[1]);
        TLorentzVector lep3((*_recolep_sel_px)[2],(*_recolep_sel_py)[2],(*_recolep_sel_pz)[2],(*_recolep_sel_e)[2]);
       
        vector< pair<int,TLorentzVector> > reco_jets;
        vector< pair<int,float> > i_jet_DeepCSV_pairs;

        vector<float> _recoPFJet_btag_e;
        vector<float> _recoPFJet_btag_px;
        vector<float> _recoPFJet_btag_py;
        vector<float> _recoPFJet_btag_pz;

        vector<float> _recoPFJet_untag_e;
        vector<float> _recoPFJet_untag_px;
        vector<float> _recoPFJet_untag_py;
        vector<float> _recoPFJet_untag_pz;

        for(unsigned int i_jet=0; i_jet<_recoPFJet_px->size(); i_jet++){
          TLorentzVector recoPFJet ( (*_recoPFJet_px)[i_jet] , (*_recoPFJet_py)[i_jet] , (*_recoPFJet_pz)[i_jet] , (*_recoPFJet_e)[i_jet] );
          pair<int,TLorentzVector> jet_pair = make_pair(i_jet, recoPFJet);
          float DeepCSVscore = (*_recoPFJet_DeepCSVscore)[i_jet];
          pair<int,float> DeepCSV_pair = make_pair(i_jet,DeepCSVscore);
          reco_jets.push_back(jet_pair);
          i_jet_DeepCSV_pairs.push_back(DeepCSV_pair);
        }

        sort(i_jet_DeepCSV_pairs.begin(), i_jet_DeepCSV_pairs.end(), DeepCSV_comparison_pairs);

        for(unsigned int i_PFJet=0; i_PFJet<i_jet_DeepCSV_pairs.size(); i_PFJet++){

          int i_jet = i_jet_DeepCSV_pairs[i_PFJet].first;
          float DeepCSVscore= i_jet_DeepCSV_pairs[i_PFJet].second;

          if(_n_recoPFJet>=4){

            if (i_PFJet<2){
              _recoPFJet_btag_e.push_back( (*_recoPFJet_e)[i_jet] );
              _recoPFJet_btag_px.push_back( (*_recoPFJet_px)[i_jet] );
              _recoPFJet_btag_py.push_back( (*_recoPFJet_py)[i_jet] );
              _recoPFJet_btag_pz.push_back( (*_recoPFJet_pz)[i_jet] );
            }
            else{
              _recoPFJet_untag_e.push_back( (*_recoPFJet_e)[i_jet] );
              _recoPFJet_untag_px.push_back( (*_recoPFJet_px)[i_jet] );
              _recoPFJet_untag_py.push_back( (*_recoPFJet_py)[i_jet] );
              _recoPFJet_untag_pz.push_back( (*_recoPFJet_pz)[i_jet] );
            }
          }
          else{
            if (i_PFJet<1){
              _recoPFJet_btag_e.push_back( (*_recoPFJet_e)[i_jet] );
              _recoPFJet_btag_px.push_back( (*_recoPFJet_px)[i_jet] );
              _recoPFJet_btag_py.push_back( (*_recoPFJet_py)[i_jet] );
              _recoPFJet_btag_pz.push_back( (*_recoPFJet_pz)[i_jet] );
            }
            else{
              _recoPFJet_untag_e.push_back( (*_recoPFJet_e)[i_jet] );
              _recoPFJet_untag_px.push_back( (*_recoPFJet_px)[i_jet] );
              _recoPFJet_untag_py.push_back( (*_recoPFJet_py)[i_jet] );
              _recoPFJet_untag_pz.push_back( (*_recoPFJet_pz)[i_jet] );
            }

          }

        }

        if (_recoPFJet_btag_px.size()>1){          
          TLorentzVector bjet1 ( _recoPFJet_btag_px[0], _recoPFJet_btag_py[0], _recoPFJet_btag_pz[0], _recoPFJet_btag_e[0] );
          TLorentzVector bjet2 ( _recoPFJet_btag_px[1], _recoPFJet_btag_py[1], _recoPFJet_btag_pz[1], _recoPFJet_btag_e[1] );
          _mbb_loose_3l1tau = (_n_recoPFJet_btag_loose>1) ? (bjet1+bjet2).M() : -1;

        }
        else{
          TLorentzVector bjet1 ( _recoPFJet_btag_px[0], _recoPFJet_btag_py[0], _recoPFJet_btag_pz[0], _recoPFJet_btag_e[0] );
          TLorentzVector bjet2 ( _recoPFJet_untag_px[0], _recoPFJet_untag_py[0], _recoPFJet_untag_pz[0], _recoPFJet_untag_e[0] );
          _mbb_loose_3l1tau = (_n_recoPFJet_btag_loose>1) ? (bjet1+bjet2).M() : -1;
        }
              
        bool OS1 = ((*_recolep_sel_charge)[0]*(*_recotauh_sel_charge)[0] < 0);
        _mTauTauVis1_3l1tau = (OS1) ? (tau1+lep1).M() : -1.;  
        bool OS2 = ((*_recolep_sel_charge)[1]*(*_recotauh_sel_charge)[0] < 0);   
        _mTauTauVis2_3l1tau = (OS2) ? (tau1+lep2).M() : -1.;      

        float _maxEta = -999.;
        for(unsigned int i_lep=0;i_lep<(*_recolep_sel_pt).size();i_lep++){
          float _eta_lep = abs((*_recolep_sel_eta)[i_lep]);
          if(_eta_lep > _maxEta){
              _maxEta = _eta_lep;
          }
        }
        _max_lep_eta_3l1tau = _maxEta;

        _max_lep_eta_3l1tau = _maxEta;
        _ptmiss_3l1tau = _PFMET;
        _tau_pt_3l1tau = tau1.Pt();
        _dr_leps_3l1tau = lep1.DeltaR(lep2);

        float _mindR_lepjet = 999.;
        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){
          TLorentzVector jet((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
          TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
          float _dR_lepjet = jet.DeltaR(lep1);
          if(_dR_lepjet < _mindR_lepjet){
              _mindR_lepjet = _dR_lepjet;
          }
        }

        _mindr_lep1_jet_3l1tau = _mindR_lepjet;

        float _mindR = 999.;
        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){
          TLorentzVector jet((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
          for(unsigned int i_tau=0;i_tau<(*_recotauh_sel_pt).size();i_tau++){
            TLorentzVector tau((*_recotauh_sel_px)[i_tau],(*_recotauh_sel_py)[i_tau],(*_recotauh_sel_pz)[i_tau],(*_recotauh_sel_e)[i_tau]);
            float _dR = jet.DeltaR(tau);
            if(_dR<_mindR){
              _mindR = _dR;
            }
          }
        }

        _mindr_tau_jet_3l1tau = _mindR;


        _lep1_conePt_3l1tau = (*_recolep_sel_conept)[0];
        _lep2_conePt_3l1tau = (*_recolep_sel_conept)[1];
        _nJet_3l1tau = _n_recoPFJet;

        mTauTauVis1_3l1tau = _mTauTauVis1_3l1tau;
        mTauTauVis2_3l1tau = _mTauTauVis2_3l1tau;
        max_lep_eta_3l1tau = _max_lep_eta_3l1tau;
        ptmiss_3l1tau = _ptmiss_3l1tau;
        tau_pt_3l1tau = _tau_pt_3l1tau;
        dr_leps_3l1tau = _dr_leps_3l1tau;
        mindr_lep1_jet_3l1tau = _mindr_lep1_jet_3l1tau;
        mindr_tau_jet_3l1tau = _mindr_tau_jet_3l1tau; 
        mbb_loose_3l1tau = _mbb_loose_3l1tau;
        lep1_conePt_3l1tau = _lep1_conePt_3l1tau;
        lep2_conePt_3l1tau = _lep2_conePt_3l1tau;
        nJet_3l1tau = _nJet_3l1tau;

        //not synced in nJet

        /*cout<<"---"<<endl;
        cout<<"mTauTauVis1 "<<mTauTauVis1_3l1tau<<",mTauTauVis2 "<<mTauTauVis2_3l1tau<<",max_lep_eta "<<max_lep_eta_3l1tau<<",ptmiss "<<ptmiss_3l1tau<<endl;
        cout<<"tau_pt "<<tau_pt_3l1tau<<",dr_leps "<<dr_leps_3l1tau<<",mindr_lep1_jet "<<mindr_lep1_jet_3l1tau<<",mindr_tau_jet "<<mindr_tau_jet_3l1tau<<endl;
        cout<<"mbb_loose "<<mbb_loose_3l1tau<<",lep1_conePt "<<lep1_conePt_3l1tau<<",lep2_conePt "<<lep2_conePt_3l1tau<<",nJet "<<nJet_3l1tau<<endl;*/

        _MVA_3l1tau_output = MVA_3l1tau_reader->EvaluateMVA("BDTG method");
        _MVA_3l1tau = 1. / (1. + sqrt((1. - _MVA_3l1tau_output) / (1. + _MVA_3l1tau_output)));

        //cout<<"_MVA_3l1tau "<<_MVA_3l1tau<<endl;
 
     }

     tree_new->Fill();
  
    }
 
    f_new->cd();
    tree_new->Write();

  }
  
  f_new->Close();
  return 0;
}
