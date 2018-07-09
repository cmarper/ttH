#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TCanvas.h>
#include <iostream>
#include <TLorentzVector.h>
#include <TH2F.h>
#include "TMVA/Reader.h"

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

//#include "HTT_kinfit/HadTopKinFit.cc"
#include "HTT_kinfit/HadTopKinFit.h"

// VARIABLES FOR FINAL BDT
float _avg_dr_jet;
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

TMVA::Reader* Book_1l2tau_MVAReader(std::string basePath, std::string weightFileName)
{

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("avg_dr_jet", &_avg_dr_jet );
    reader->AddVariable("dr_taus", &_dr_taus );
    reader->AddVariable("ptmiss", &_ptmiss );   
    reader->AddVariable("lep_conePt", &_lep_conePt );
    reader->AddVariable("mT_lep", &_mT_lep );  
    reader->AddVariable("mTauTauVis", &_mTauTauVis );
    reader->AddVariable("mindr_lep_jet", &_mindr_lep_jet );
    reader->AddVariable("mindr_tau1_jet", &_mindr_tau1_jet );
    reader->AddVariable("mindr_tau2_jet", &_mindr_tau2_jet );
    reader->AddVariable("dr_lep_tau_ss", &_dr_lep_tau_ss );
    reader->AddVariable("dr_lep_tau_lead", &_dr_lep_tau_lead );
    reader->AddVariable("costS_tau", &_costS_tau );
    reader->AddVariable("nBJetLoose", &_nBJetLoose );
    reader->AddVariable("tau1_pt", &_tau1_pt );
    reader->AddVariable("tau2_pt", &_tau2_pt );
    reader->AddVariable("HTT", &_HTT );
    reader->AddVariable("HadTop_pt", &_HadTop_pt );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}

// VARIABLES FOR HTT
float _CSV_b;
float _qg_Wj2;
float _pT_bWj1Wj2;
float _m_Wj1Wj2;
float _nllKinFit;
float _pT_b_o_kinFit_pT_b;
float _pT_Wj2;

TMVA::Reader* Book_HTT_MVAReader(std::string basePath, std::string weightFileName)
{

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");
  
    reader->AddVariable("CSV_b", &_CSV_b);
    reader->AddVariable("qg_Wj2", &_qg_Wj2);
    reader->AddVariable("pT_bWj1Wj2", &_pT_bWj1Wj2);
    reader->AddVariable("m_Wj1Wj2", &_m_Wj1Wj2);
    reader->AddVariable("nllKinFit", &_nllKinFit);
    reader->AddVariable("pT_b_o_kinFit_pT_b", &_pT_b_o_kinFit_pT_b);
    reader->AddVariable("pT_Wj2", &_pT_Wj2);

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}



void add_1l2tau_BDT(TString filein, TString fileout, std::vector<TString> treename){


  TFile* f_new = TFile::Open(fileout);
  if(f_new!=0){
    std::cout<<fileout<<" already exists, please delete it before converting again"<<std::endl;
    return;
  }
  
  f_new = TFile::Open(fileout,"RECREATE");

  TMVA::Reader* MVA_1l2tau_reader = Book_1l2tau_MVAReader("MVA/BDT_1l2tau","1l_2tau_XGB_HTT_evtLevelSUM_TTH_VT_17Var.xml");
  TMVA::Reader* MVA_HTT_reader = Book_HTT_MVAReader("MVA/HadTopTagger","HadTopTagger_resolved_XGB_CSV_sort_withKinFit.xml");

  const std::string tf_fileName = "/home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros/HadTopTagger/HTT_kinfit/TF_jets.root";
  HadTopKinFit* _kinFit = new HadTopKinFit(1, tf_fileName);

  for(unsigned int i_tree=0;i_tree<treename.size();i_tree++){

    TChain * tree = new TChain(treename[i_tree]);
    tree->Add(filein);
    
    Long64_t nentries = tree->GetEntries();
    std::cout<<"nentries="<<tree->GetEntries()<<std::endl;
    
    // OLD VARIABLES USED HERE
    int _category;
    std::vector<float>* _recotauh_sel_px;
    std::vector<float>* _recotauh_sel_py;
    std::vector<float>* _recotauh_sel_pz;
    std::vector<float>* _recotauh_sel_e;
    std::vector<float>* _recotauh_sel_pt;
    std::vector<float>* _recotauh_sel_charge;
 
    std::vector<float>* _recolep_sel_pt;
    std::vector<float>* _recolep_sel_conept;
    std::vector<float>* _recolep_sel_phi;
    std::vector<float>* _recolep_sel_px;
    std::vector<float>* _recolep_sel_py;
    std::vector<float>* _recolep_sel_pz;
    std::vector<float>* _recolep_sel_e;
    std::vector<float>* _recolep_sel_charge; 
  
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
    std::vector<float>* _recoPFJet_btag_e;
    std::vector<float>* _recoPFJet_untag_Wtag_QGdiscr;
    std::vector<float>* _recoPFJet_untag_Wtag_px;
    std::vector<float>* _recoPFJet_untag_Wtag_py;
    std::vector<float>* _recoPFJet_untag_Wtag_pz;
    std::vector<float>* _recoPFJet_untag_Wtag_e;
     
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
    tree->SetBranchAddress("recoPFJet_untag_Wtag_QGdiscr",&_recoPFJet_untag_Wtag_QGdiscr);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_px",&_recoPFJet_untag_Wtag_px);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_py",&_recoPFJet_untag_Wtag_py);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_pz",&_recoPFJet_untag_Wtag_pz);
    tree->SetBranchAddress("recoPFJet_untag_Wtag_e",&_recoPFJet_untag_Wtag_e);
   
    tree->SetBranchAddress("mindR_lep1_recoPFjet",&_mindR_lep1_recoPFjet); 
    tree->SetBranchAddress("avg_dr_jet",&_avg_dr_jet);
    tree->SetBranchAddress("HTmiss",&_HTmiss);
    tree->SetBranchAddress("met",&_met);
    tree->SetBranchAddress("metphi",&_metphi);
    
    tree->SetBranchAddress("category",&_category);

    TTree* tree_new=tree->GetTree()->CloneTree(0);

    // NEW VARIABLES FOR FINAL BDT
    float _dr_taus;
    float _ptmiss;
    float _lep_conePt;
    float _mT_lep;
    float _mTauTauVis;
    float _mindr_lep_jet;
    float _mindr_tau1_jet;
    float _mindr_tau2_jet;
    float _dr_lep_tau_lead;
    float _nBJetLoose;
    float _tau1_pt;
    float _tau2_pt;
    float _dr_lep_tau_ss;
    float _costS_tau;
    float _HTT;
    float _HadTop_pt;

    tree_new->Branch("avg_dr_jet",&_avg_dr_jet,"avg_dr_jet/F");
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

    // NEW VARIABLES FOR HTT
    float CSV_b;
    float qg_Wj2;
    float pT_bWj1Wj2;
    float m_Wj1Wj2;
    float pT_Wj2;
    float nllKinFit;
    float pT_b_o_kinFit_pT_b;

    tree_new->Branch("CSV_b",&_CSV_b,"CSV_b/F");
    tree_new->Branch("qg_Wj2",&_qg_Wj2,"qg_Wj2/F");
    tree_new->Branch("pT_bWj1Wj2",&_pT_bWj1Wj2,"pT_bWj1Wj2/F");
    tree_new->Branch("m_Wj1Wj2",&_m_Wj1Wj2,"m_Wj1Wj2/F");
    tree_new->Branch("nllKinFit",&_nllKinFit,"snllKinFit/F");
    tree_new->Branch("pT_b_o_kinFit_pT_b",&_pT_b_o_kinFit_pT_b,"pT_b_o_kinFit_pT_b/F");
    tree_new->Branch("pT_Wj2",&_pT_Wj2,"pT_Wj2/F");

    float _MVA_1l2tau_output;
    float _MVA_1l2tau;

    tree_new->Branch("MVA_1l2tau_output",&_MVA_1l2tau_output,"MVA_1l2tau_output/F");
    tree_new->Branch("MVA_1l2tau",&_MVA_1l2tau,"MVA_1l2tau/F"); 

    for(int i=0;i<nentries;i++){
      
      if(i%100==0)
	 std::cout<<"i="<<i<<std::endl;

      // new variables
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
      _HTT = 0;
      _HadTop_pt = 0;   
 
      _CSV_b = 0;
      _qg_Wj2 = 0;
      _pT_bWj1Wj2 = 0;
      _m_Wj1Wj2 = 0;
      _pT_Wj2 = 0;
      _nllKinFit = 0;
      _pT_b_o_kinFit_pT_b = 0;

      // old variables used 
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

      _recoPFJet_pt = 0;
      _n_recoPFJet = 0;
      _n_recoPFJet_btag_loose = 0;
      _recoPFJet_px = 0;
      _recoPFJet_py = 0;
      _recoPFJet_pz = 0;
      _recoPFJet_e = 0;
      _recoPFJet_btag_DeepCSVscore = 0;
      _recoPFJet_btag_px = 0;
      _recoPFJet_btag_py = 0;
      _recoPFJet_btag_pz = 0;
      _recoPFJet_btag_e = 0;
      _recoPFJet_untag_Wtag_QGdiscr = 0;
      _recoPFJet_untag_Wtag_px = 0;
      _recoPFJet_untag_Wtag_py = 0;
      _recoPFJet_untag_Wtag_pz = 0;
      _recoPFJet_untag_Wtag_e = 0;
      
      _mindR_lep1_recoPFjet = 0;

      _HTmiss = 0;
      _met = 0;
     
      _MVA_1l2tau_output = 0;
      _MVA_1l2tau = 0;

      tree->GetEntry(i);

      if(_category==20 || _category==50){

	TLorentzVector tau1((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
	TLorentzVector tau2((*_recotauh_sel_px)[1],(*_recotauh_sel_py)[1],(*_recotauh_sel_pz)[1],(*_recotauh_sel_e)[1]);
        TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);	
        
        LorentzVector bjet1((*_recoPFJet_btag_px)[0],(*_recoPFJet_btag_py)[0],(*_recoPFJet_btag_pz)[0],(*_recoPFJet_btag_e)[0]);
        LorentzVector wjet1((*_recoPFJet_untag_Wtag_px)[0],(*_recoPFJet_untag_Wtag_py)[0],(*_recoPFJet_untag_Wtag_pz)[0],(*_recoPFJet_untag_Wtag_e)[0]);
        LorentzVector wjet2((*_recoPFJet_untag_Wtag_px)[1],(*_recoPFJet_untag_Wtag_py)[1],(*_recoPFJet_untag_Wtag_pz)[1],(*_recoPFJet_untag_Wtag_e)[1]);

        //jet+jet 
        /*_deltaRmax_jet = -1;      
        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size()-1;i_jet++){
        TLorentzVector jet1((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);

          for(unsigned int i_jet2=i_jet+1;i_jet2<(*_recoPFJet_pt).size();i_jet2++){
          TLorentzVector jet2((*_recoPFJet_px)[i_jet2], (*_recoPFJet_py)[i_jet2], (*_recoPFJet_pz)[i_jet2], (*_recoPFJet_e)[i_jet2]);
      
            float dR = jet1.DeltaR(jet2);
            if(_deltaRmax_jet<0 || dR>_deltaRmax_jet){
              _deltaRmax_jet = dR;
            }
          }
        }*/

        //jet+tau
        float _mindR1 = -999.;
        float _mindR2 = -999.;
        for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size()-1;i_jet++){
        TLorentzVector jet1((*_recoPFJet_px)[i_jet], (*_recoPFJet_py)[i_jet], (*_recoPFJet_pz)[i_jet], (*_recoPFJet_e)[i_jet]);

          for(unsigned int i_tau=0;i_tau<(*_recotauh_sel_pt).size();i_tau++){
          TLorentzVector tau1((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
          TLorentzVector tau2((*_recotauh_sel_px)[1],(*_recotauh_sel_py)[1],(*_recotauh_sel_pz)[1],(*_recotauh_sel_e)[1]);
          float _dR1 = jet1.DeltaR(tau1);
          float _dR2 = jet1.DeltaR(tau2);
            
          if(_dR1<_mindR1){
              _mindR1 = _dR1;
          }
          if(_dR2<_mindR2){
              _mindR2 = _dR2;
          }
          }
        }

        //for BDT
	_dr_taus = tau1.DeltaR(tau2);
        _ptmiss = _met;
        _lep_conePt = (*_recolep_sel_conept)[0];
        _mT_lep = sqrt(2*((*_recolep_sel_conept)[0])*_met*(1-cos(((*_recolep_sel_phi)[0])-_metphi)));
 	_mTauTauVis = (tau1+tau2).M();
        _mindr_lep_jet = _mindR_lep1_recoPFjet;
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
        _qg_Wj2 = (*_recoPFJet_untag_Wtag_QGdiscr)[1];
        _pT_bWj1Wj2 = (bjet1+wjet1+wjet2).Pt();
        _pT_Wj2 = wjet2.Pt();
        _m_Wj1Wj2 = (wjet1+wjet2).M();
        _kinFit->fit(bjet1,wjet1,wjet2);
        _nllKinFit = _kinFit->nll();
        _pT_b_o_kinFit_pT_b = (bjet1.Pt()) / (_kinFit->fittedBJet().Pt());

        _HTT = MVA_HTT_reader->EvaluateMVA("BDTG method");
        _HadTop_pt = (bjet1+wjet1+wjet2).Pt();

	_MVA_1l2tau_output = MVA_1l2tau_reader->EvaluateMVA("BDTG method");
        _MVA_1l2tau = 1. / (1. + sqrt((1. - _MVA_1l2tau_output) / (1. + _MVA_1l2tau_output)));

      }

      
       tree_new->Fill();

    }
    
    
    f_new->cd();
    
    tree_new->Write();


  }

  f_new->Close();


  return;

}



/*
float njet;
float mindr_lep1_jet;
float mindr_lep2_jet;
float mindr_lep3_jet;
float avg_dr_jet;
float max_lep_eta;
//float ptmiss;
float mT_lep1;
float mT_lep3;
//float htmiss;
float dr_leps;
float tau_pt;
float abs_tau_eta;
float dr_lep1_tau;
float dr_lep2_tau;
float dr_lep3_tau;
float lep1_pt;
float lep2_pt;
float lep3_pt;
float mTauTauVis1;
float mTauTauVis2;
float mindr_tau_jet;
*/

/*
TMVA::Reader* Book_2lSS1tau_TT_noMEM_MVAReader(std::string basePath, std::string weightFileName)
{

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("nJet", &njet );
    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet );
    reader->AddVariable("avg_dr_jet", &avg_dr_jet );
    reader->AddVariable("TMath::Max(TMath::Abs(lep1_eta),TMath::Abs(lep2_eta))", &max_lep_eta );
    reader->AddVariable("lep2_conePt", &lep2_pt );
    reader->AddVariable("dr_leps", &dr_leps );
    reader->AddVariable("tau_pt", &tau_pt );
    reader->AddVariable("dr_lep1_tau", &dr_lep1_tau );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}



TMVA::Reader* Book_2lSS1tau_TTV_noMEM_MVAReader(std::string basePath, std::string weightFileName)
{

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet );
    reader->AddVariable("mindr_lep2_jet", &mindr_lep2_jet );
    reader->AddVariable("avg_dr_jet", &avg_dr_jet );
    reader->AddVariable("TMath::Max(TMath::Abs(lep1_eta),TMath::Abs(lep2_eta))", &max_lep_eta );
    reader->AddVariable("lep1_conePt", &lep1_pt );
    reader->AddVariable("lep2_conePt", &lep2_pt );
    reader->AddVariable("mT_lep1", &mT_lep1 );
    reader->AddVariable("dr_leps", &dr_leps );
    reader->AddVariable("mTauTauVis1", &mTauTauVis1 );
    reader->AddVariable("mTauTauVis2", &mTauTauVis2 );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}



float memOutput_LR;



TMVA::Reader* Book_2lSS1tau_TT_MEM_LR_MVAReader(std::string basePath, std::string weightFileName)
{

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("nJet", &njet );
    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet );
    //reader->AddVariable("mindr_lep2_jet", &mindr_lep2_jet );
    reader->AddVariable("avg_dr_jet", &avg_dr_jet );
    reader->AddVariable("TMath::Max(TMath::Abs(lep1_eta),TMath::Abs(lep2_eta))", &max_lep_eta );
    //reader->AddVariable("max_lep_eta", &max_lep_eta );
    reader->AddVariable("lep2_conePt", &lep2_pt );    
    //reader->AddVariable("ptmiss", &ptmiss );
    //reader->AddVariable("mT_lep1", &mT_lep1 );
    //reader->AddVariable("htmiss", &htmiss );
    reader->AddVariable("dr_leps", &dr_leps );
    reader->AddVariable("tau_pt", &tau_pt );
    reader->AddVariable("dr_lep1_tau", &dr_lep1_tau );
    reader->AddVariable("memOutput_LR", &memOutput_LR );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}




TMVA::Reader* Book_2lSS1tau_TTV_MEM_LR_MVAReader(std::string basePath, std::string weightFileName)
{

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet );
    reader->AddVariable("mindr_lep2_jet", &mindr_lep2_jet );
    reader->AddVariable("avg_dr_jet", &avg_dr_jet );
    //reader->AddVariable("lep1_pt", &lep1_pt );
    //reader->AddVariable("lep2_pt", &lep2_pt );
    reader->AddVariable("TMath::Max(TMath::Abs(lep1_eta),TMath::Abs(lep2_eta))", &max_lep_eta );
    //reader->AddVariable("max_lep_eta", &max_lep_eta );
    reader->AddVariable("lep1_conePt", &lep1_pt );
    reader->AddVariable("lep2_conePt", &lep2_pt );
    reader->AddVariable("mT_lep1", &mT_lep1 );
    reader->AddVariable("dr_leps", &dr_leps );
    reader->AddVariable("mTauTauVis1", &mTauTauVis1 );
    reader->AddVariable("mTauTauVis2", &mTauTauVis2 );
    reader->AddVariable("memOutput_LR", &memOutput_LR );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}






TMVA::Reader* Book_3l1tau_TTV_MVAReader(std::string basePath, std::string weightFileName)
{

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("nJet", &njet );
    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet );
    reader->AddVariable("lep1_conePt", &lep1_pt );
    reader->AddVariable("lep2_conePt", &lep2_pt );
    reader->AddVariable("lep3_conePt", &lep3_pt );
    reader->AddVariable("mindr_tau_jet", &mindr_tau_jet );
    reader->AddVariable("mT_lep3", &mT_lep3 );
    reader->AddVariable("tau_pt", &tau_pt );
    reader->AddVariable("dr_lep1_tau", &dr_lep1_tau );
    reader->AddVariable("dr_lep2_tau", &dr_lep2_tau );
    reader->AddVariable("dr_lep3_tau", &dr_lep3_tau );
    reader->AddVariable("mTauTauVis2", &mTauTauVis2 );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}






TMVA::Reader* Book_3l1tau_TT_MVAReader(std::string basePath, std::string weightFileName)
{

    TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

    reader->AddVariable("nJet", &njet );
    reader->AddVariable("mindr_lep1_jet", &mindr_lep1_jet );
    reader->AddVariable("mindr_lep2_jet", &mindr_lep2_jet );
    reader->AddVariable("mindr_lep3_jet", &mindr_lep3_jet );
    reader->AddVariable("avg_dr_jet", &avg_dr_jet );
    reader->AddVariable("mindr_tau_jet", &mindr_tau_jet );
    reader->AddVariable("tau_pt", &tau_pt );
    reader->AddVariable("TMath::Abs(tau_eta)", &abs_tau_eta );
    reader->AddVariable("dr_lep1_tau", &dr_lep1_tau );
    reader->AddVariable("dr_lep2_tau", &dr_lep2_tau );
    reader->AddVariable("dr_lep3_tau", &dr_lep3_tau );
    reader->AddVariable("mTauTauVis2", &mTauTauVis2 );

    reader->BookMVA("BDTG method", basePath+"/"+weightFileName);

    return reader;
}
*/



/*
void add_2lSS1tau_MEM_BDT(TString filein, TString fileout, std::vector<TString> treename){


  TFile* f_new = TFile::Open(fileout);
  if(f_new!=0){
    std::cout<<fileout<<" already exists, please delete it before converting again"<<std::endl;
    return;
  }
  
  f_new = TFile::Open(fileout,"RECREATE");
  
  for(unsigned int i_tree=0;i_tree<treename.size();i_tree++){

    TChain * tree = new TChain(treename[i_tree]);
    tree->Add(filein);
    
    Long64_t nentries = tree->GetEntries();
    std::cout<<"nentries="<<tree->GetEntries()<<std::endl;

    int _category;
    int _n_recoPFJet;
    std::vector<float>* _recoPFJet_px;
    std::vector<float>* _recoPFJet_py;
    std::vector<float>* _recoPFJet_pz;
    std::vector<float>* _recoPFJet_e;
    std::vector<float>* _recolep_sel_px;
    std::vector<float>* _recolep_sel_py;
    std::vector<float>* _recolep_sel_pz;
    std::vector<float>* _recolep_sel_e;
    std::vector<float>* _recolep_sel_conept;
    std::vector<float>* _recotauh_sel_px;
    std::vector<float>* _recotauh_sel_py;
    std::vector<float>* _recotauh_sel_pz;
    std::vector<float>* _recotauh_sel_e;
    float _avg_dr_jet;
    float _PFMET;
    float _PFMET_phi;
    float _HTmiss;    

    float _Integral_ttH;
    float _Integral_ttZ;
    float _Integral_ttZ_Zll;
    float _Integral_ttbar_DL_fakelep_tlep;
    float _Integral_ttbar_DL_fakelep_ttau;
    int _integration_type;

    tree->SetBranchAddress("n_recoPFJet",&_n_recoPFJet);
    tree->SetBranchAddress("recoPFJet_px",&_recoPFJet_px);
    tree->SetBranchAddress("recoPFJet_py",&_recoPFJet_py);
    tree->SetBranchAddress("recoPFJet_pz",&_recoPFJet_pz);
    tree->SetBranchAddress("recoPFJet_e",&_recoPFJet_e);
    tree->SetBranchAddress("recolep_sel_px",&_recolep_sel_px);
    tree->SetBranchAddress("recolep_sel_py",&_recolep_sel_py);
    tree->SetBranchAddress("recolep_sel_pz",&_recolep_sel_pz);
    tree->SetBranchAddress("recolep_sel_e",&_recolep_sel_e);
    tree->SetBranchAddress("recolep_sel_conept",&_recolep_sel_conept);
    tree->SetBranchAddress("recotauh_sel_px",&_recotauh_sel_px);
    tree->SetBranchAddress("recotauh_sel_py",&_recotauh_sel_py);
    tree->SetBranchAddress("recotauh_sel_pz",&_recotauh_sel_pz);
    tree->SetBranchAddress("recotauh_sel_e",&_recotauh_sel_e);
    tree->SetBranchAddress("avg_dr_jet",&_avg_dr_jet);
    tree->SetBranchAddress("PFMET",&_PFMET);
    tree->SetBranchAddress("PFMET_phi",&_PFMET_phi);
    tree->SetBranchAddress("HTmiss",&_HTmiss);
    tree->SetBranchAddress("category",&_category);

    tree->SetBranchAddress("Integral_ttH",&_Integral_ttH);
    tree->SetBranchAddress("Integral_ttZ",&_Integral_ttZ);
    tree->SetBranchAddress("Integral_ttZ_Zll",&_Integral_ttZ_Zll);
    tree->SetBranchAddress("Integral_ttbar_DL_fakelep_tlep",&_Integral_ttbar_DL_fakelep_tlep);
    tree->SetBranchAddress("Integral_ttbar_DL_fakelep_ttau",&_Integral_ttbar_DL_fakelep_ttau);
    tree->SetBranchAddress("integration_type",&_integration_type);

    TTree* tree_new=tree->GetTree()->CloneTree(0);

    float _mindR_lep1_jet;
    float _mindR_lep2_jet;
    float _mT_lep1;
    float _dR_leps;
    float _mTauTauVis1;
    float _mTauTauVis2;
    float _dR_lep1_tau;  

    float _MVA_2lSS1tau_noMEM_ttbar;
    float _MVA_2lSS1tau_MEM_LR_ttbar;
 
    float _MVA_2lSS1tau_noMEM_ttV;
    float _MVA_2lSS1tau_MEM_LR_ttV;

    int _MVA_2lSS1tau_noMEM_2Dbin;
    int _MVA_2lSS1tau_MEM_LR_2Dbin;

    tree_new->Branch("mindR_lep1_jet",&_mindR_lep1_jet,"mindR_lep1_jet/F");
    tree_new->Branch("mindR_lep2_jet",&_mindR_lep2_jet,"mindR_lep2_jet/F");
    tree_new->Branch("mT_lep1",&_mT_lep1,"mT_lep1/F");
    tree_new->Branch("dR_leps",&_dR_leps,"dR_leps/F");
    tree_new->Branch("mTauTauVis1",&_mTauTauVis1,"mTauTauVis1/F");
    tree_new->Branch("mTauTauVis2",&_mTauTauVis2,"mTauTauVis2/F");
    tree_new->Branch("dR_lep1_tau",&_dR_lep1_tau,"dR_lep1_tau/F");  

    tree_new->Branch("MVA_2lSS1tau_noMEM_ttbar",&_MVA_2lSS1tau_noMEM_ttbar,"MVA_2lSS1tau_noMEM_ttbar/F");
    tree_new->Branch("MVA_2lSS1tau_MEM_LR_ttbar",&_MVA_2lSS1tau_MEM_LR_ttbar,"MVA_2lSS1tau_MEM_LR_ttbar/F");

    tree_new->Branch("MVA_2lSS1tau_noMEM_ttV",&_MVA_2lSS1tau_noMEM_ttV,"MVA_2lSS1tau_noMEM_ttV/F");
    tree_new->Branch("MVA_2lSS1tau_MEM_LR_ttV",&_MVA_2lSS1tau_MEM_LR_ttV,"MVA_2lSS1tau_MEM_LR_ttV/F");
    
    tree_new->Branch("MVA_2lSS1tau_noMEM_2Dbin",&_MVA_2lSS1tau_noMEM_2Dbin,"MVA_2lSS1tau_noMEM_2Dbin/I");
    tree_new->Branch("MVA_2lSS1tau_MEM_LR_2Dbin",&_MVA_2lSS1tau_MEM_LR_2Dbin,"MVA_2lSS1tau_MEM_LR_2Dbin/I");


    TMVA::Reader* MVA_2lSS1tau_TT_noMEM_reader = Book_2lSS1tau_TT_noMEM_MVAReader("2lSS1tau_MVA_weights","/mvaTTHvsTTbar2lss1tau_BDTG.weights.xml");
    TMVA::Reader* MVA_2lSS1tau_TT_MEM_LR_reader = Book_2lSS1tau_TT_MEM_LR_MVAReader("2lSS1tau_MVA_weights","/2lss_1tau_ttbar_BDTGwMEM.weights.xml");

    TMVA::Reader* MVA_2lSS1tau_TTV_noMEM_reader = Book_2lSS1tau_TTV_noMEM_MVAReader("2lSS1tau_MVA_weights","/mvaTTHvsTTV2lss1tau_BDTG.weights.xml");
    TMVA::Reader* MVA_2lSS1tau_TTV_MEM_LR_reader = Book_2lSS1tau_TTV_MEM_LR_MVAReader("2lSS1tau_MVA_weights","/2lss_1tau_ttV_BDTGwMEM.weights.xml");


    TFile* f_MVA_2Dbin = TFile::Open("2lSS1tau_MVA_weights/binning_2l.root");
    TH2F* h_MVA_2Dbin = (TH2F*)f_MVA_2Dbin->Get("hTargetBinning");
    h_MVA_2Dbin->SetDirectory(0);
    f_MVA_2Dbin->Close();    

    TFile* f_MVA_MEM_LR_2Dbin = TFile::Open("2lSS1tau_MVA_weights/2lss_1tau_BDTwMEM_mapping_likelihood.root");
    TH2F* h_MVA_MEM_LR_2Dbin = (TH2F*)f_MVA_MEM_LR_2Dbin->Get("hTargetBinning");
    h_MVA_MEM_LR_2Dbin->SetDirectory(0);
    f_MVA_MEM_LR_2Dbin->Close();    



    for(int i=0;i<nentries;i++){
      
      if(i%10000==0)
	std::cout<<"i="<<i<<std::endl;

      _mindR_lep1_jet = 0;
      _mindR_lep2_jet = 0;
      _mT_lep1 = 0;
      _dR_leps = 0;
      _mTauTauVis1 = 0;
      _mTauTauVis2 = 0;
      _dR_lep1_tau = 0; 
     
      _MVA_2lSS1tau_noMEM_ttbar = 0;
      _MVA_2lSS1tau_MEM_LR_ttbar = 0;    
      
      _MVA_2lSS1tau_noMEM_ttV = 0;
      _MVA_2lSS1tau_MEM_LR_ttV = 0;

      _MVA_2lSS1tau_noMEM_2Dbin = 0;
      _MVA_2lSS1tau_MEM_LR_2Dbin = 0;

      _category = 0;
      _n_recoPFJet = 0;
      _recoPFJet_px = 0;
      _recoPFJet_py = 0;
      _recoPFJet_pz = 0;
      _recoPFJet_e = 0;
      _recolep_sel_px = 0;
      _recolep_sel_py = 0;
      _recolep_sel_pz = 0;
      _recolep_sel_e = 0;
      _recolep_sel_conept = 0;
      _recotauh_sel_px = 0;
      _recotauh_sel_py = 0;
      _recotauh_sel_pz = 0;
      _recotauh_sel_e = 0;
      _avg_dr_jet = 0;
      _PFMET = 0;
      _PFMET_phi = 0;
      _HTmiss = 0;    

      _Integral_ttH = 0;
      _Integral_ttZ = 0;
      _Integral_ttZ_Zll = 0;
      _Integral_ttbar_DL_fakelep_tlep = 0;
      _Integral_ttbar_DL_fakelep_ttau = 0;
      _integration_type = 0;      
 

      tree->GetEntry(i);

      if(_category==11 || _category==41 || _category==-11){

	TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
	TLorentzVector lep2((*_recolep_sel_px)[1],(*_recolep_sel_py)[1],(*_recolep_sel_pz)[1],(*_recolep_sel_e)[1]);

	_mindR_lep1_jet = -10;
	_mindR_lep2_jet = -10;

	for(unsigned int i_jet=0;i_jet<_n_recoPFJet;i_jet++){

	  TLorentzVector jet((*_recoPFJet_px)[i_jet],(*_recoPFJet_py)[i_jet],(*_recoPFJet_pz)[i_jet],(*_recoPFJet_e)[i_jet]);
	  if(jet.DeltaR(lep1)<_mindR_lep1_jet || _mindR_lep1_jet<0)
	    _mindR_lep1_jet = jet.DeltaR(lep1);
	  if(jet.DeltaR(lep2)<_mindR_lep2_jet || _mindR_lep2_jet<0)
	    _mindR_lep2_jet = jet.DeltaR(lep2);

	}

      

      _mT_lep1=sqrt( 2*(*_recolep_sel_conept)[0]*_PFMET*(1-cos(lep1.Phi()-_PFMET_phi)) );
      _dR_leps = lep1.DeltaR(lep2);      
      
      TLorentzVector tauh((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
      _mTauTauVis1 = (tauh+lep1).M();
      _mTauTauVis2 = (tauh+lep2).M();
      _dR_lep1_tau = tauh.DeltaR(lep1);

      njet = _n_recoPFJet;
      mindr_lep1_jet = _mindR_lep1_jet;
      mindr_lep2_jet = _mindR_lep2_jet;
      avg_dr_jet = _avg_dr_jet;
      max_lep_eta = max(abs(lep1.Eta()), abs(lep2.Eta()));
      mT_lep1 = _mT_lep1;
      dr_leps = _dR_leps;
      tau_pt = tauh.Pt();
      lep1_pt = (*_recolep_sel_conept)[0];
      lep2_pt = (*_recolep_sel_conept)[1];
      mTauTauVis1 = _mTauTauVis1;
      mTauTauVis2 = _mTauTauVis2;
      dr_lep1_tau = _dR_lep1_tau;
      
      //memOutput_type = _integration_type;
      if(_integration_type==0){
	float k_ttZ = 5e-2;
	float k_ttZ_Zll = 1e-1;
	float k_ttbar = 1e-17;
	memOutput_LR = _Integral_ttH>0 ? _Integral_ttH / (_Integral_ttH + k_ttZ*_Integral_ttZ + k_ttZ_Zll*_Integral_ttZ_Zll + k_ttbar*(_Integral_ttbar_DL_fakelep_tlep + _Integral_ttbar_DL_fakelep_ttau) ) : 0;
      }
      else{
	float k_ttZ = 5e-2;
	float k_ttZ_Zll = 1;
	float k_ttbar = 1e-14;
	memOutput_LR = _Integral_ttH>0 ? _Integral_ttH / (_Integral_ttH + k_ttZ*_Integral_ttZ + k_ttZ_Zll*_Integral_ttZ_Zll + k_ttbar*(_Integral_ttbar_DL_fakelep_tlep + _Integral_ttbar_DL_fakelep_ttau) ) : 0;
      }
      
      log_memOutput_ttH = _Integral_ttH>0 ? log(_Integral_ttH): -100;
      log_memOutput_ttZ = _Integral_ttZ>0 ? log(_Integral_ttZ): -100;
      log_memOutput_ttZ_Zll = _Integral_ttZ_Zll ? log(_Integral_ttZ_Zll) : -100;
      log_memOutput_tt = (_Integral_ttbar_DL_fakelep_tlep + _Integral_ttbar_DL_fakelep_ttau) ? log(_Integral_ttbar_DL_fakelep_tlep + _Integral_ttbar_DL_fakelep_ttau) : -100;
      
 

      _MVA_2lSS1tau_noMEM_ttbar = MVA_2lSS1tau_TT_noMEM_reader->EvaluateMVA("BDTG method");
      _MVA_2lSS1tau_MEM_LR_ttbar = MVA_2lSS1tau_TT_MEM_LR_reader->EvaluateMVA("BDTG method");
      _MVA_2lSS1tau_MEM_weights_ttbar = MVA_2lSS1tau_TT_MEM_weights_reader->EvaluateMVA("BDTG method");
      _MVA_2lSS1tau_MEM_weights_only_ttbar = MVA_2lSS1tau_TT_MEM_weights_only_reader->EvaluateMVA("BDTG method");


      _MVA_2lSS1tau_noMEM_ttV = MVA_2lSS1tau_TTV_noMEM_reader->EvaluateMVA("BDTG method");
      _MVA_2lSS1tau_MEM_LR_ttV = MVA_2lSS1tau_TTV_MEM_LR_reader->EvaluateMVA("BDTG method");
      _MVA_2lSS1tau_MEM_weights_ttV = MVA_2lSS1tau_TTV_MEM_weights_reader->EvaluateMVA("BDTG method");
      _MVA_2lSS1tau_MEM_weights_only_ttV = MVA_2lSS1tau_TTV_MEM_weights_only_reader->EvaluateMVA("BDTG method");
      }


      int i_bin = h_MVA_2Dbin->FindBin(_MVA_2lSS1tau_noMEM_ttbar,_MVA_2lSS1tau_noMEM_ttV);
      _MVA_2lSS1tau_noMEM_2Dbin = int(h_MVA_2Dbin->GetBinContent(i_bin));

      int i_bin2 = h_MVA_MEM_LR_2Dbin->FindBin(_MVA_2lSS1tau_MEM_LR_ttbar,_MVA_2lSS1tau_MEM_LR_ttV);
      _MVA_2lSS1tau_MEM_LR_2Dbin = int(h_MVA_MEM_LR_2Dbin->GetBinContent(i_bin2));

      tree_new->Fill();

    }
    
    
    f_new->cd();
    
    tree_new->Write();


  }

  f_new->Close();


  return;

}

*/






/*
void add_3l1tau_BDT(TString filein, TString fileout, std::vector<TString> treename){


  TFile* f_new = TFile::Open(fileout);
  if(f_new!=0){
    std::cout<<fileout<<" already exists, please delete it before converting again"<<std::endl;
    return;
  }
  
  f_new = TFile::Open(fileout,"RECREATE");
  
  for(unsigned int i_tree=0;i_tree<treename.size();i_tree++){

    TChain * tree = new TChain(treename[i_tree]);
    tree->Add(filein);
    
    Long64_t nentries = tree->GetEntries();
    std::cout<<"nentries="<<tree->GetEntries()<<std::endl;

    int _category;
    int _n_recoPFJet;
    std::vector<float>* _recoPFJet_px;
    std::vector<float>* _recoPFJet_py;
    std::vector<float>* _recoPFJet_pz;
    std::vector<float>* _recoPFJet_e;
    std::vector<float>* _recolep_sel_px;
    std::vector<float>* _recolep_sel_py;
    std::vector<float>* _recolep_sel_pz;
    std::vector<float>* _recolep_sel_e;
    std::vector<float>* _recolep_sel_conept;
    std::vector<float>* _recotauh_sel_px;
    std::vector<float>* _recotauh_sel_py;
    std::vector<float>* _recotauh_sel_pz;
    std::vector<float>* _recotauh_sel_e;
    float _avg_dr_jet;
    float _PFMET;
    float _PFMET_phi;
    float _HTmiss;    

    tree->SetBranchAddress("n_recoPFJet",&_n_recoPFJet);
    tree->SetBranchAddress("recoPFJet_px",&_recoPFJet_px);
    tree->SetBranchAddress("recoPFJet_py",&_recoPFJet_py);
    tree->SetBranchAddress("recoPFJet_pz",&_recoPFJet_pz);
    tree->SetBranchAddress("recoPFJet_e",&_recoPFJet_e);
    tree->SetBranchAddress("recolep_sel_px",&_recolep_sel_px);
    tree->SetBranchAddress("recolep_sel_py",&_recolep_sel_py);
    tree->SetBranchAddress("recolep_sel_pz",&_recolep_sel_pz);
    tree->SetBranchAddress("recolep_sel_e",&_recolep_sel_e);
    tree->SetBranchAddress("recolep_sel_conept",&_recolep_sel_conept);
    tree->SetBranchAddress("recotauh_sel_px",&_recotauh_sel_px);
    tree->SetBranchAddress("recotauh_sel_py",&_recotauh_sel_py);
    tree->SetBranchAddress("recotauh_sel_pz",&_recotauh_sel_pz);
    tree->SetBranchAddress("recotauh_sel_e",&_recotauh_sel_e);
    tree->SetBranchAddress("avg_dr_jet",&_avg_dr_jet);
    tree->SetBranchAddress("PFMET",&_PFMET);
    tree->SetBranchAddress("PFMET_phi",&_PFMET_phi);
    tree->SetBranchAddress("HTmiss",&_HTmiss);
    tree->SetBranchAddress("category",&_category);


    TTree* tree_new=tree->GetTree()->CloneTree(0);

    float _mindR_lep1_jet;
    float _mindR_lep2_jet;
    float _mindR_lep3_jet;
    float _mindR_tau_jet;
    float _mT_lep3;
    float _mTauTauVis2;
    float _dR_lep1_tau;
    float _dR_lep2_tau;
    float _dR_lep3_tau;

    float _MVA_3l1tau_ttbar;
    float _MVA_3l1tau_ttV;
    int _MVA_3l1tau_2Dbin;


    tree_new->Branch("mindR_lep1_jet",&_mindR_lep1_jet,"mindR_lep1_jet/F");
    tree_new->Branch("mindR_lep2_jet",&_mindR_lep2_jet,"mindR_lep2_jet/F");
    tree_new->Branch("mindR_lep3_jet",&_mindR_lep3_jet,"mindR_lep3_jet/F");
    tree_new->Branch("mindR_tau_jet",&_mindR_tau_jet,"mindR_tau_jet/F");
    tree_new->Branch("mT_lep3",&_mT_lep3,"mT_lep3/F");
    tree_new->Branch("mTauTauVis2",&_mTauTauVis2,"mTauTauVis2/F");
    tree_new->Branch("dR_lep1_tau",&_dR_lep1_tau,"dR_lep1_tau/F");
    tree_new->Branch("dR_lep2_tau",&_dR_lep2_tau,"dR_lep2_tau/F");
    tree_new->Branch("dR_lep3_tau",&_dR_lep3_tau,"dR_lep3_tau/F");

    tree_new->Branch("MVA_3l1tau_ttbar",&_MVA_3l1tau_ttbar,"MVA_3l1tau_ttbar/F");
    tree_new->Branch("MVA_3l1tau_ttV",&_MVA_3l1tau_ttV,"MVA_3l1tau_ttV/F");
    tree_new->Branch("MVA_3l1tau_2Dbin",&_MVA_3l1tau_2Dbin,"MVA_3l1tau_2Dbin/I");

    TMVA::Reader* MVA_3l1tau_TT_reader = Book_3l1tau_TT_MVAReader("3l1tau_MVA_weights","/3l_1tau_ttbar_BDTG.weights.xml");
    TMVA::Reader* MVA_3l1tau_TTV_reader = Book_3l1tau_TTV_MVAReader("3l1tau_MVA_weights","/3l_1tau_ttV_BDTG.weights.xml");


    TFile* f_MVA_2Dbin = TFile::Open("3l1tau_MVA_weights/3l_1tau_BDT_mapping.root");
    TH2F* h_MVA_2Dbin = (TH2F*)f_MVA_2Dbin->Get("hTargetBinning");
    h_MVA_2Dbin->SetDirectory(0);
    f_MVA_2Dbin->Close();    


    for(int i=0;i<nentries;i++){
      
      if(i%10000==0)
	std::cout<<"i="<<i<<std::endl;

      _mindR_lep1_jet = 0;
      _mindR_lep2_jet = 0;
      _mindR_lep3_jet = 0;
      _mindR_tau_jet = 0;
      _mT_lep3 = 0;
      _mTauTauVis2 = 0;
      _dR_lep1_tau = 0;
      _dR_lep2_tau = 0;
      _dR_lep3_tau = 0;     

      _MVA_3l1tau_ttbar = 0;
      _MVA_3l1tau_ttV = 0;
      _MVA_3l1tau_2Dbin = 0;

      _category = 0;
      _n_recoPFJet = 0;
      _recoPFJet_px = 0;
      _recoPFJet_py = 0;
      _recoPFJet_pz = 0;
      _recoPFJet_e = 0;
      _recolep_sel_px = 0;
      _recolep_sel_py = 0;
      _recolep_sel_pz = 0;
      _recolep_sel_e = 0;
      _recolep_sel_conept = 0;
      _recotauh_sel_px = 0;
      _recotauh_sel_py = 0;
      _recotauh_sel_pz = 0;
      _recotauh_sel_e = 0;
      _avg_dr_jet = 0;
      _PFMET = 0;
      _PFMET_phi = 0;
      _HTmiss = 0;    

 
      tree->GetEntry(i);

      if(_category==16 || _category==46){

	TLorentzVector lep1((*_recolep_sel_px)[0],(*_recolep_sel_py)[0],(*_recolep_sel_pz)[0],(*_recolep_sel_e)[0]);
	TLorentzVector lep2((*_recolep_sel_px)[1],(*_recolep_sel_py)[1],(*_recolep_sel_pz)[1],(*_recolep_sel_e)[1]);
	TLorentzVector lep3((*_recolep_sel_px)[2],(*_recolep_sel_py)[2],(*_recolep_sel_pz)[2],(*_recolep_sel_e)[2]);

	_mT_lep3=sqrt( 2*(*_recolep_sel_conept)[2]*_PFMET*(1-cos(lep3.Phi()-_PFMET_phi)) );
	
	TLorentzVector tauh((*_recotauh_sel_px)[0],(*_recotauh_sel_py)[0],(*_recotauh_sel_pz)[0],(*_recotauh_sel_e)[0]);
	_mTauTauVis2 = (tauh+lep2).M();
	_dR_lep1_tau = tauh.DeltaR(lep1);
	_dR_lep2_tau = tauh.DeltaR(lep2);
	_dR_lep3_tau = tauh.DeltaR(lep3);
	
	_mindR_lep1_jet = -10;
	_mindR_lep2_jet = -10;
	_mindR_lep3_jet = -10;
	_mindR_tau_jet = -10;


	for(unsigned int i_jet=0;i_jet<_n_recoPFJet;i_jet++){

	  TLorentzVector jet((*_recoPFJet_px)[i_jet],(*_recoPFJet_py)[i_jet],(*_recoPFJet_pz)[i_jet],(*_recoPFJet_e)[i_jet]);
	  if(jet.DeltaR(lep1)<_mindR_lep1_jet || _mindR_lep1_jet<0)
	    _mindR_lep1_jet = jet.DeltaR(lep1);
	  if(jet.DeltaR(lep2)<_mindR_lep2_jet || _mindR_lep2_jet<0)
	    _mindR_lep2_jet = jet.DeltaR(lep2);
	  if(jet.DeltaR(lep3)<_mindR_lep3_jet || _mindR_lep3_jet<0)
	    _mindR_lep3_jet = jet.DeltaR(lep3);
	  if(jet.DeltaR(tauh)<_mindR_tau_jet || _mindR_tau_jet<0)
	    _mindR_tau_jet = jet.DeltaR(tauh);	  

	}      


	njet = _n_recoPFJet;
	mindr_lep1_jet = _mindR_lep1_jet;
	mindr_lep2_jet = _mindR_lep2_jet;
	mindr_lep3_jet = _mindR_lep3_jet;
	mindr_tau_jet = _mindR_tau_jet;
	avg_dr_jet = _avg_dr_jet;
	mT_lep3 = _mT_lep3;
	tau_pt = tauh.Pt();
	abs_tau_eta = abs(tauh.Eta());   
	dr_lep1_tau = _dR_lep1_tau;
	dr_lep2_tau = _dR_lep2_tau;
	dr_lep3_tau = _dR_lep3_tau;       
	lep1_pt = (*_recolep_sel_conept)[0];
	lep2_pt = (*_recolep_sel_conept)[1];
	lep3_pt = (*_recolep_sel_conept)[2];
	mTauTauVis2 = _mTauTauVis2;
            
	_MVA_3l1tau_ttbar = MVA_3l1tau_TT_reader->EvaluateMVA("BDTG method");
	_MVA_3l1tau_ttV = MVA_3l1tau_TTV_reader->EvaluateMVA("BDTG method");

      }

      int i_bin = h_MVA_2Dbin->FindBin(_MVA_3l1tau_ttbar,_MVA_3l1tau_ttV);
      _MVA_3l1tau_2Dbin = int(h_MVA_2Dbin->GetBinContent(i_bin));

      tree_new->Fill();

    }
    
    
    f_new->cd();
    
    tree_new->Write();


  }

  f_new->Close();


  return;

}
*/





void test_BDT(){

  TString filein="/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split.root";
  TString fileout="/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_BDT.root";  

  std::vector<TString> tree;
  tree.push_back("HTauTauTree_2lSS");
  tree.push_back("HTauTauTree_2lOS_CR");
  tree.push_back("HTauTauTree_2lSS_lepMVA_CR");
  tree.push_back("HTauTauTree_2lSS_jetmult_CR");
  tree.push_back("HTauTauTree_2lSS_ttbarOF_CR");
  tree.push_back("HTauTauTree_2lSS_2jet_CR");
  tree.push_back("HTauTauTree_3l");
  tree.push_back("HTauTauTree_3l_lepMVA_CR");
  tree.push_back("HTauTauTree_3l_WZ_CR");
  tree.push_back("HTauTauTree_3l_ttZ_CR");
  tree.push_back("HTauTauTree_3l_ttZ_lepMVA_CR");
  tree.push_back("HTauTauTree_1l_2tau");
  tree.push_back("HTauTauTree_1l_2tau_fake_CR");
  tree.push_back("HTauTauTree_1l_2tau_2jet_CR");
  tree.push_back("HTauTauTree_2l_2tau");
  tree.push_back("HTauTauTree_2l_2tau_fake_CR");

  add_1l2tau_BDT(filein,fileout,tree);

}

