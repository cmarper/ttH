//BDT for signal extraction in 1l2tau category
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

#include "HTT_kinfit/HadTopKinFit.cc"
//#include "HTT_kinfit/HadTopKinFit.h"
*/

//variables for final BDT
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

//variables for HTT
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


//int add_BDT_1l2tau(int argc, char** argv){
int add_BDT_1l2tau(string input, string output, vector<string> treename){  
  
 cout<<"Computing 1l2tau BDT..."<<endl;

 /* string input;
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
  
  TMVA::Reader* MVA_1l2tau_reader = Book_1l2tau_MVAReader("../MVA/BDT_1l2tau","1l_2tau_XGB_HTT_evtLevelSUM_TTH_VT_17Var.xml");
  if(!MVA_1l2tau_reader) std::cout << "No 1l2tau xml file"<<std::endl;

  TMVA::Reader* MVA_HTT_reader = Book_HTT_1l2tau_MVAReader("../MVA/HadTopTagger","HadTopTagger_resolved_XGB_CSV_sort_withKinFit.xml");
  if(!MVA_HTT_reader) std::cout << "No HTT xml file"<<std::endl;

  const std::string tf_fileName = "./HTT_kinfit/TF_jets.root"; 
  HadTopKinFit* _kinFit = new HadTopKinFit(1, tf_fileName);

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
    std::vector<float>* _recoPFJet_btag_DeepCSVscore;
    std::vector<float>* _recoPFJet_btag_px;
    std::vector<float>* _recoPFJet_btag_py;
    std::vector<float>* _recoPFJet_btag_pz;
    std::vector<float>* _recoPFJet_btag_pt;
    std::vector<float>* _recoPFJet_btag_eta;
    std::vector<float>* _recoPFJet_btag_phi;
    std::vector<float>* _recoPFJet_btag_e;
    std::vector<float>* _recoPFJet_untag_e;
    std::vector<float>* _recoPFJet_untag_px;
    std::vector<float>* _recoPFJet_untag_py;
    std::vector<float>* _recoPFJet_untag_pz;
    std::vector<float>* _recoPFJet_QGdiscr;
    std::vector<float>* _recoPFJet_untag_Wtag_px;
    std::vector<float>* _recoPFJet_untag_Wtag_py;
    std::vector<float>* _recoPFJet_untag_Wtag_pz;
    std::vector<float>* _recoPFJet_untag_Wtag_pt;
    std::vector<float>* _recoPFJet_untag_Wtag_eta;
    std::vector<float>* _recoPFJet_untag_Wtag_phi;
    std::vector<float>* _recoPFJet_untag_Wtag_e;
    float _recoPFJet_untag_best_mW; //invariant mass of the pair

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
    tree->SetBranchAddress("recolep_sel_charge",&_recolep_sel_charge);

    tree->SetBranchAddress("n_recoPFJet",&_n_recoPFJet);
    tree->SetBranchAddress("n_recoPFJet_btag_loose",&_n_recoPFJet_btag_loose);
    tree->SetBranchAddress("recoPFJet_pt",&_recoPFJet_pt);
    tree->SetBranchAddress("recoPFJet_px",&_recoPFJet_px);
    tree->SetBranchAddress("recoPFJet_py",&_recoPFJet_py);
    tree->SetBranchAddress("recoPFJet_pz",&_recoPFJet_pz);
    tree->SetBranchAddress("recoPFJet_e",&_recoPFJet_e);
    tree->SetBranchAddress("recoPFJet_btag_DeepCSVscore",&_recoPFJet_btag_DeepCSVscore);
    tree->SetBranchAddress("recoPFJet_btag_px",&_recoPFJet_btag_px);
    tree->SetBranchAddress("recoPFJet_btag_py",&_recoPFJet_btag_py);
    tree->SetBranchAddress("recoPFJet_btag_pz",&_recoPFJet_btag_pz);
    tree->SetBranchAddress("recoPFJet_btag_e",&_recoPFJet_btag_e);
    tree->SetBranchAddress("recoPFJet_btag_pt",&_recoPFJet_btag_pt);
    tree->SetBranchAddress("recoPFJet_btag_eta",&_recoPFJet_btag_eta);
    tree->SetBranchAddress("recoPFJet_btag_phi",&_recoPFJet_btag_phi);
    tree->SetBranchAddress("recoPFJet_untag_e",&_recoPFJet_untag_e);
    tree->SetBranchAddress("recoPFJet_untag_px",&_recoPFJet_untag_px);
    tree->SetBranchAddress("recoPFJet_untag_py",&_recoPFJet_untag_py);
    tree->SetBranchAddress("recoPFJet_untag_pz",&_recoPFJet_untag_pz);
    tree->SetBranchAddress("recoPFJet_QGdiscr",&_recoPFJet_QGdiscr);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_px",&_recoPFJet_untag_Wtag_px);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_py",&_recoPFJet_untag_Wtag_py);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_pz",&_recoPFJet_untag_Wtag_pz);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_e",&_recoPFJet_untag_Wtag_e);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_pt",&_recoPFJet_untag_Wtag_pt);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_eta",&_recoPFJet_untag_Wtag_eta);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_phi",&_recoPFJet_untag_Wtag_phi);

    tree->SetBranchAddress("mindR_lep1_recoPFjet",&_mindR_lep1_recoPFjet);
    tree->SetBranchAddress("avg_dr_jet",&_avg_dr_jet);
    tree->SetBranchAddress("HTmiss",&_HTmiss);
    tree->SetBranchAddress("met",&_met);
    tree->SetBranchAddress("metphi",&_metphi);

    tree->SetBranchAddress("category",&_category);

    TTree* tree_new=(TTree*)tree->GetTree()->CloneTree(0);

    //new variables for final BDT
    float _dr_taus;
    float _ptmiss;
    float _lep_conePt;
    float _mT_lep;
    float _mTauTauVis;
    float _mindr_lep_jet;
    float _mindr_tau1_jet;
    float _mindr_tau2_jet;
    float _dr_lep_tau_lead;
    float _dr_lep_tau_sublead;
    float _nBJetLoose;
    float _tau1_pt;
    float _tau2_pt;
    float _dr_lep_tau_ss;
    float _costS_tau;
    float _HTT;
    float _HadTop_pt;

    /*tree_new->Branch("avg_dr_jet",&_avg_dr_jet,"avg_dr_jet/F");
    tree_new->Branch("dr_taus",&_dr_taus,"dr_taus/F");
    tree_new->Branch("ptmiss",&_ptmiss,"ptmiss/F");
    tree_new->Branch("lep_conePt",&_lep_conePt,"lep_conePt/F");
    tree_new->Branch("mT_lep",&_mT_lep,"mT_lep/F");
    tree_new->Branch("mTauTauVis",&_mTauTauVis,"mTauTauVis/F");
    tree_new->Branch("mindr_lep_jet",&_mindr_lep_jet,"mindr_lep_jet/F");
    tree_new->Branch("mindr_tau1_jet",&_mindr_tau1_jet,"mindr_tau1_jet/F");
    tree_new->Branch("mindr_tau2_jet",&_mindr_tau1_jet,"mindr_tau2_jet/F");
    tree_new->Branch("dr_lep_tau_lead",&_dr_lep_tau_lead,"dr_lep_tau_lead/F");
    tree_new->Branch("nBJetLoose",&_nBJetLoose,"nBJetLoose/F");
    tree_new->Branch("tau1_pt",&_tau1_pt,"tau1_pt/F");
    tree_new->Branch("tau2_pt",&_tau2_pt,"tau2_pt/F");
    tree_new->Branch("dr_lep_tau_ss",&_dr_lep_tau_ss,"dr_lep_tau_ss/F");
    tree_new->Branch("costS_tau",&_costS_tau,"costS_tau/F");
    tree_new->Branch("HTT",&_HTT,"HTT/F");
    tree_new->Branch("HadTop_pt",&_HadTop_pt,"HadTop_pt/F");
    */

    //new variables for HTT
    std::vector<float> _recoPFJet_untag_Wtag_QGdiscr;
    float _CSV_b;
    float _qg_Wj2;
    float _pT_bWj1Wj2;
    float _m_Wj1Wj2;
    float _pT_Wj2;
    float _nllKinFit;
    float _pT_b_o_kinFit_pT_b;

    /*tree_new->Branch("recoPFJet_untag_Wtag_QGdiscr",&_recoPFJet_untag_Wtag_QGdiscr,"recoPFJet_untag_Wtag_QGdiscr/F");
    tree_new->Branch("CSV_b",&_CSV_b,"CSV_b/F");
    tree_new->Branch("qg_Wj2",&_qg_Wj2,"qg_Wj2/F");
    tree_new->Branch("pT_bWj1Wj2",&_pT_bWj1Wj2,"pT_bWj1Wj2/F");
    tree_new->Branch("m_Wj1Wj2",&_m_Wj1Wj2,"m_Wj1Wj2/F");
    tree_new->Branch("nllKinFit",&_nllKinFit,"snllKinFit/F");
    tree_new->Branch("pT_b_o_kinFit_pT_b",&_pT_b_o_kinFit_pT_b,"pT_b_o_kinFit_pT_b/F");
    tree_new->Branch("pT_Wj2",&_pT_Wj2,"pT_Wj2/F");
    */
    float _MVA_1l2tau_output;
    float _MVA_1l2tau;

    tree_new->Branch("MVA_1l2tau_output",&_MVA_1l2tau_output,"MVA_1l2tau_output/F");
    tree_new->Branch("MVA_1l2tau",&_MVA_1l2tau,"MVA_1l2tau/F");

    //nentries=100;
    for(int i=0;i<nentries;i++){
      if(i%1000==0)
         std::cout<<"i="<<i<<std::endl;

      //new variables
      _dr_taus = 0;
      _ptmiss = 0;
      _lep_conePt = 0;
      _mT_lep = 0;
      _mTauTauVis = 0;
      _mindr_lep_jet = 0;
      _mindr_tau1_jet = 0;
      _mindr_tau2_jet = 0;
      _dr_lep_tau_lead = 0;
      _nBJetLoose = 0;
      _tau1_pt = 0;
      _tau2_pt = 0;
      _dr_lep_tau_ss = 0;
      _costS_tau = 0;
      _HTT = -1;
      _HadTop_pt = 0;

      _recoPFJet_untag_Wtag_QGdiscr.clear();
      _CSV_b = 0;
      _qg_Wj2 = 0;
      _pT_bWj1Wj2 = 0;
      _m_Wj1Wj2 = 0;
      _pT_Wj2 = 0;
      _nllKinFit = 0;
      _pT_b_o_kinFit_pT_b = 0;

      int _n_pair_Wtag_recoPFJet_untag = 0;

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
      _recolep_sel_charge = 0;

      _n_recoPFJet = 0;
      _n_recoPFJet_btag_loose = 0;
      _recoPFJet_pt = 0;
      _recoPFJet_px = 0;
      _recoPFJet_py = 0;
      _recoPFJet_pz = 0;
      _recoPFJet_e = 0;
      _recoPFJet_btag_DeepCSVscore = 0;
      _recoPFJet_btag_px = 0;
      _recoPFJet_btag_py = 0;
      _recoPFJet_btag_pz = 0;
      _recoPFJet_btag_e = 0;
      _recoPFJet_btag_pt = 0;
      _recoPFJet_btag_eta = 0;
      _recoPFJet_btag_phi = 0;
      _recoPFJet_untag_e = 0;
      _recoPFJet_untag_px = 0;
      _recoPFJet_untag_py = 0;
      _recoPFJet_untag_pz = 0;
      _recoPFJet_QGdiscr = 0;
      _recoPFJet_untag_Wtag_px = 0;
      _recoPFJet_untag_Wtag_py = 0;
      _recoPFJet_untag_Wtag_pz = 0;
      _recoPFJet_untag_Wtag_e = 0;
      _recoPFJet_untag_Wtag_pt = 0;
      _recoPFJet_untag_Wtag_eta = 0;
      _recoPFJet_untag_Wtag_phi = 0;

      _mindR_lep1_recoPFjet = 0;

      _HTmiss = 0;
      _met = 0;

      _MVA_1l2tau_output = -1;
      _MVA_1l2tau = -1;

      tree->GetEntry(i);

      if(_category==20 || _category==50){
        
      TLorentzVector tau1((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
      TLorentzVector tau2((*_recotauh_sel_px)[1],(*_recotauh_sel_py)[1],(*_recotauh_sel_pz)[1],(*_recotauh_sel_e)[1]);
      TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
      
      TLorentzVector bjet1;
      TLorentzVector bjet2;
      float mass_bjet1;
      float mass_bjet2;
      LorentzVector bjet1_lv;
      LorentzVector bjet2_lv;

      if (_recoPFJet_btag_px->size()>0){
        bjet1.SetPxPyPzE((*_recoPFJet_btag_px)[0],(*_recoPFJet_btag_py)[0],(*_recoPFJet_btag_pz)[0],(*_recoPFJet_btag_e)[0]);
        bjet2.SetPxPyPzE((*_recoPFJet_btag_px)[1],(*_recoPFJet_btag_py)[1],(*_recoPFJet_btag_pz)[1],(*_recoPFJet_btag_e)[1]);
        mass_bjet1 = bjet1.M();
        mass_bjet2 = bjet2.M();
        bjet1_lv.SetCoordinates((*_recoPFJet_btag_pt)[0],(*_recoPFJet_btag_eta)[0],(*_recoPFJet_btag_phi)[0],mass_bjet1);
        bjet2_lv.SetCoordinates((*_recoPFJet_btag_pt)[1],(*_recoPFJet_btag_eta)[1],(*_recoPFJet_btag_phi)[1],mass_bjet2);
      }     
 
      //for BDT
      _dr_taus = tau1.DeltaR(tau2);
      _ptmiss = _met;
      _lep_conePt = (*_recolep_sel_conept)[0];
      _mT_lep = sqrt(2*((*_recolep_sel_conept)[0])*_met*(1-cos(((*_recolep_sel_phi)[0])-_metphi)));
      _mTauTauVis = (tau1+tau2).M();

      float _mindR = 999.;
      for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){
        TLorentzVector jet((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);
        TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
        float _dR = jet.DeltaR(lep1); 
        if(_dR < _mindR){
            _mindR = _dR;
        }
      }

      _mindr_lep_jet = _mindR;

      //jet+tau
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

      _mindr_tau1_jet = _mindR1;
      _mindr_tau2_jet = _mindR2;
      _dr_lep_tau_lead = tau1.DeltaR(lep1);
      _dr_lep_tau_sublead = tau2.DeltaR(lep1);
      _nBJetLoose = _n_recoPFJet_btag_loose;
      _tau1_pt = tau1.Pt();
      _tau2_pt = tau2.Pt();
      _dr_lep_tau_ss = ( ((*_recolep_sel_charge)[0])==((*_recotauh_sel_charge)[0]) ) ? _dr_lep_tau_lead : _dr_lep_tau_sublead;
      _costS_tau = abs(tau1.CosTheta());
 
      //for HTT
      _CSV_b = (*_recoPFJet_btag_DeepCSVscore)[0];

      double mW=80.4;
      if((*_recoPFJet_untag_e).size()>1){
          vector<int> index_Wtag;
          index_Wtag.push_back(0);
          index_Wtag.push_back(0);
          for(unsigned int i_jet1=0; i_jet1<(*_recoPFJet_untag_e).size()-1; i_jet1++){
              TLorentzVector jet1 ( (*_recoPFJet_untag_px)[i_jet1], (*_recoPFJet_untag_py)[i_jet1], (*_recoPFJet_untag_pz)[i_jet1], (*_recoPFJet_untag_e)[i_jet1] );
              for(unsigned int i_jet2=i_jet1+1; i_jet2<(*_recoPFJet_untag_e).size(); i_jet2++){
                  TLorentzVector jet2 ( (*_recoPFJet_untag_px)[i_jet2], (*_recoPFJet_untag_py)[i_jet2], (*_recoPFJet_untag_pz)[i_jet2], (*_recoPFJet_untag_e)[i_jet2] );
                  double mjj = (jet1+jet2).M();
                  if(mjj>60 && mjj<100)
                      _n_pair_Wtag_recoPFJet_untag++;

                      if( _recoPFJet_untag_best_mW<0 || (abs( mjj - mW ) < abs( _recoPFJet_untag_best_mW - mW )) ){
                          _recoPFJet_untag_best_mW = mjj;
                          if(jet1.Pt()>jet2.Pt()){
                               _qg_Wj2= (*_recoPFJet_QGdiscr)[1];
                          }
                          else{
                              _qg_Wj2= (*_recoPFJet_QGdiscr)[0];
                          }
                     }
              }
          }
      } 


      TLorentzVector wjet1;
      TLorentzVector wjet2;
      float mass_wjet1;
      float mass_wjet2;
      LorentzVector wjet1_lv;
      LorentzVector wjet2_lv;

      if (_recoPFJet_untag_Wtag_px->size()>0){
        wjet1.SetPxPyPzE((*_recoPFJet_untag_Wtag_px)[0],(*_recoPFJet_untag_Wtag_py)[0],(*_recoPFJet_untag_Wtag_pz)[0],(*_recoPFJet_untag_Wtag_e)[0]);
        wjet1.SetPxPyPzE((*_recoPFJet_untag_Wtag_px)[1],(*_recoPFJet_untag_Wtag_py)[1],(*_recoPFJet_untag_Wtag_pz)[1],(*_recoPFJet_untag_Wtag_e)[1]);
        mass_wjet1 = wjet1.M();
        mass_wjet2 = wjet2.M();
        wjet1_lv.SetCoordinates((*_recoPFJet_untag_Wtag_pt)[0],(*_recoPFJet_untag_Wtag_eta)[0],(*_recoPFJet_untag_Wtag_phi)[0],mass_wjet1);
        wjet2_lv.SetCoordinates((*_recoPFJet_untag_Wtag_pt)[1],(*_recoPFJet_untag_Wtag_eta)[1],(*_recoPFJet_untag_Wtag_phi)[1],mass_wjet2);
      }   
 
      _pT_bWj1Wj2 = (bjet1+wjet1+wjet2).Pt();
      _pT_Wj2 = wjet2.Pt();
      _m_Wj1Wj2 = (wjet1+wjet2).M();
      _kinFit->fit(bjet1_lv,wjet1_lv,wjet2_lv);
      _nllKinFit = _kinFit->nll();
      _pT_b_o_kinFit_pT_b = (bjet1.Pt()) / (_kinFit->fittedBJet().Pt());

      //for BDT
      avg_dr_jet_1l2tau = _avg_dr_jet;
      dr_taus_1l2tau = _dr_taus;
      ptmiss_1l2tau = _ptmiss;
      lep_conePt_1l2tau = _lep_conePt;
      mT_lep_1l2tau = _mT_lep;
      mTauTauVis_1l2tau = _mTauTauVis;
      mindr_lep_jet_1l2tau = _mindr_lep_jet;
      mindr_tau1_jet_1l2tau = _mindr_tau1_jet;
      mindr_tau2_jet_1l2tau = _mindr_tau2_jet;
      dr_lep_tau_lead_1l2tau = _dr_lep_tau_lead;
      dr_lep_tau_sublead_1l2tau = _dr_lep_tau_sublead;
      nBJetLoose_1l2tau = _nBJetLoose;
      tau1_pt_1l2tau = _tau1_pt;
      tau2_pt_1l2tau = _tau2_pt;
      dr_lep_tau_ss_1l2tau = _dr_lep_tau_ss;
      costS_tau_1l2tau = _costS_tau;

      //for HTT
      CSV_b_1l2tau = _CSV_b; 
      qg_Wj2_1l2tau = _qg_Wj2;
      pT_bWj1Wj2_1l2tau = _pT_bWj1Wj2;
      pT_Wj2_1l2tau = _pT_Wj2;
      m_Wj1Wj2_1l2tau = _m_Wj1Wj2;
      nllKinFit_1l2tau = _nllKinFit;
      pT_b_o_kinFit_pT_b_1l2tau = _pT_b_o_kinFit_pT_b;

      float _HTT_output = MVA_HTT_reader->EvaluateMVA("BDTG method");
      _HTT = 1. / (1. + sqrt((1. - _HTT_output) / (1. + _HTT_output)));
      _HadTop_pt = (bjet1+wjet1+wjet2).Pt();

      HTT_1l2tau = _HTT;
      HadTop_pt_1l2tau = _HadTop_pt;

      //cout<<avg_dr_jet<<" "<<dr_taus<<" "<<ptmiss<<" "<<lep_conePt<<" "<<mT_lep<<" "<<mTauTauVis<<" "<<mindr_lep_jet<<" "<<mindr_tau1_jet<<" "<<mindr_tau2_jet<<" "<<dr_lep_tau_lead<<" "<<dr_lep_tau_sublead<<" "<<nBJetLoose<<" "<<tau1_pt<<" "<<tau2_pt<<" "<<dr_lep_tau_ss<<" "<<costS_tau<<" "<<HTT<<" "<<HadTop_pt<<endl;

      _MVA_1l2tau_output = MVA_1l2tau_reader->EvaluateMVA("BDTG method");
      _MVA_1l2tau = 1. / (1. + sqrt((1. - _MVA_1l2tau_output) / (1. + _MVA_1l2tau_output)));
      //cout<<"MVA 1l2tau "<<_MVA_1l2tau<<endl;
 
     }

     tree_new->Fill();
  
    }
 
  f_new->cd();
  tree_new->Write();

  }
  
  f_new->Close();
  return 0;
}
