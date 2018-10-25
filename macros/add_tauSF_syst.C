#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TCanvas.h>
#include <iostream>
#include <TF1.h>
#include <TGraphAsymmErrors.h>

using namespace std;

float fakerate_from_TGraph(TGraphAsymmErrors* graph, float pt){

  int n = graph->GetN();

  double x, y;
  graph->GetPoint(0,x,y);
  if(pt<x)
    return y;

  graph->GetPoint(n-1,x,y);
  if(pt>x)
    return y;
  

  for(int i=0; i<n;i++){

    graph->GetPoint(i,x,y);
    double err_low_x = graph->GetErrorXlow(i);
    double err_high_x = graph->GetErrorXhigh(i);

    if( (x-err_low_x) < pt && pt < (x+err_high_x) )
      return y;

  }

  return -1.;

}

void add_tauSF(TString filein, TString fileout, vector<TString> treename, bool isMC){


  TFile* f_new = TFile::Open(fileout);
  if(f_new!=0){
    cout<<fileout<<" already exists, please delete it before converting again"<<endl;
    return;
  }
  
  f_new = TFile::Open(fileout,"RECREATE");
  
  for(unsigned int i_tree=0;i_tree<treename.size();i_tree++){

    TChain * tree = new TChain(treename[i_tree]);
    tree->Add(filein);
    
    Long64_t nentries = tree->GetEntries();
    cout<<"nentries="<<tree->GetEntries()<<endl;
           
    int _category;
    vector<float> *_recotauh_sel_pt;
    vector<float> *_recotauh_sel_eta;
    vector<bool> *_recotauh_sel_isGenMatched;
    
    tree->SetBranchAddress("category",&_category);
    tree->SetBranchAddress("recotauh_sel_pt",&_recotauh_sel_pt);
    tree->SetBranchAddress("recotauh_sel_eta",&_recotauh_sel_eta);
    tree->SetBranchAddress("recotauh_sel_isGenMatched",&_recotauh_sel_isGenMatched);

    TTree* tree_new=tree->GetTree()->CloneTree(0);
    
    //New branches
    float _tauSF_weight_tauNormUp;
    float _tauSF_weight_tauNormDown;
    float _tauSF_weight_tauShapeUp;
    float _tauSF_weight_tauShapeDown;

    tree_new->Branch("tauSF_weight_tauNormUp",&_tauSF_weight_tauNormUp,"tauSF_weight_tauNormUp/F");
    tree_new->Branch("tauSF_weight_tauNormDown",&_tauSF_weight_tauNormDown,"tauSF_weight_tauNormDown/F");
    tree_new->Branch("tauSF_weight_tauShapeUp",&_tauSF_weight_tauShapeUp,"tauSF_weight_tauShapeUp/F");
    tree_new->Branch("tauSF_weight_tauShapeDown",&_tauSF_weight_tauShapeDown,"tauSF_weight_tauShapeDown/F");   

    vector<TString> FR_tau_syst;
    FR_tau_syst.push_back("_par1Up");
    FR_tau_syst.push_back("_par1Down");
    FR_tau_syst.push_back("_par2Up");
    FR_tau_syst.push_back("_par2Down");

    TFile* f_fakerate_tau = TFile::Open("fake_rate_weights/FR_tau_2017_v2.root");

    vector<TF1*> f_dataMC_fakerate_tau_loose_barrel;
    vector<TF1*> f_dataMC_fakerate_tau_loose_endcap;

    vector<TF1*> f_dataMC_fakerate_tau_medium_barrel;
    vector<TF1*> f_dataMC_fakerate_tau_medium_endcap;


    for(unsigned int i=0;i<FR_tau_syst.size();i++){

      f_dataMC_fakerate_tau_loose_barrel.push_back( (TF1*)f_fakerate_tau->Get("jetToTauFakeRate/dR03mvaLoose/absEtaLt1_5/fitFunction_data_div_mc_hadTaus_pt" + FR_tau_syst[i]) );
      f_dataMC_fakerate_tau_loose_endcap.push_back( (TF1*)f_fakerate_tau->Get("jetToTauFakeRate/dR03mvaLoose/absEta1_5to9_9/fitFunction_data_div_mc_hadTaus_pt" + FR_tau_syst[i]) );
      
      f_dataMC_fakerate_tau_medium_barrel.push_back( (TF1*)f_fakerate_tau->Get("jetToTauFakeRate/dR03mvaMedium/absEtaLt1_5/fitFunction_data_div_mc_hadTaus_pt" + FR_tau_syst[i]) );
      f_dataMC_fakerate_tau_medium_endcap.push_back( (TF1*)f_fakerate_tau->Get("jetToTauFakeRate/dR03mvaMedium/absEta1_5to9_9/fitFunction_data_div_mc_hadTaus_pt" + FR_tau_syst[i]) );

    }

    f_fakerate_tau->Close();

    vector<float> _recotauh_sel_jetToTau_FR_byLoose_SF_tauNormUp;
    vector<float> _recotauh_sel_jetToTau_FR_byLoose_SF_tauNormDown;
    vector<float> _recotauh_sel_jetToTau_FR_byLoose_SF_tauShapeUp;
    vector<float> _recotauh_sel_jetToTau_FR_byLoose_SF_tauShapeDown;

    vector<float> _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormUp;
    vector<float> _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormDown;
    vector<float> _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeUp;
    vector<float> _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeDown;

    for(int i=0;i<nentries;i++){
      
      if(i%10000==0)
	    cout<<"i="<<i<<endl;

      _category = 0;
      _recotauh_sel_pt = 0;
      _recotauh_sel_eta = 0;
      _recotauh_sel_isGenMatched = 0;

      _recotauh_sel_jetToTau_FR_byLoose_SF_tauNormUp.clear();
      _recotauh_sel_jetToTau_FR_byLoose_SF_tauNormDown.clear();
      _recotauh_sel_jetToTau_FR_byLoose_SF_tauShapeUp.clear();
      _recotauh_sel_jetToTau_FR_byLoose_SF_tauShapeDown.clear();

      _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormUp.clear();
      _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormDown.clear();
      _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeUp.clear();
      _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeDown.clear();

      _tauSF_weight_tauNormUp = 0;
      _tauSF_weight_tauNormDown = 0;
      _tauSF_weight_tauShapeUp = 0;
      _tauSF_weight_tauShapeDown = 0;
      
      tree->GetEntry(i);

      for(unsigned int i_tau=0;i_tau<(*_recotauh_sel_pt).size();i_tau++){

        float jetToTau_FR_byLoose_SF_tauNormUp = 0;
        float jetToTau_FR_byLoose_SF_tauNormDown = 0;
        float jetToTau_FR_byLoose_SF_tauShapeUp = 0;
        float jetToTau_FR_byLoose_SF_tauShapeDown = 0;

	      float jetToTau_FR_byMedium_SF_tauNormUp = 0;
	      float jetToTau_FR_byMedium_SF_tauNormDown = 0;
	      float jetToTau_FR_byMedium_SF_tauShapeUp = 0;
	      float jetToTau_FR_byMedium_SF_tauShapeDown = 0;

	      float tau_pt = (*_recotauh_sel_pt)[i_tau];

	      if(fabs((*_recotauh_sel_eta)[i_tau])<1.479){

          jetToTau_FR_byLoose_SF_tauNormUp = f_dataMC_fakerate_tau_loose_barrel[0]->Eval(tau_pt);
          jetToTau_FR_byLoose_SF_tauNormDown = f_dataMC_fakerate_tau_loose_barrel[1]->Eval(tau_pt);
          jetToTau_FR_byLoose_SF_tauShapeUp = f_dataMC_fakerate_tau_loose_barrel[2]->Eval(tau_pt);
          jetToTau_FR_byLoose_SF_tauShapeDown = f_dataMC_fakerate_tau_loose_barrel[3]->Eval(tau_pt);

	        jetToTau_FR_byMedium_SF_tauNormUp = f_dataMC_fakerate_tau_medium_barrel[0]->Eval(tau_pt);
	        jetToTau_FR_byMedium_SF_tauNormDown = f_dataMC_fakerate_tau_medium_barrel[1]->Eval(tau_pt);
	        jetToTau_FR_byMedium_SF_tauShapeUp = f_dataMC_fakerate_tau_medium_barrel[2]->Eval(tau_pt);
	        jetToTau_FR_byMedium_SF_tauShapeDown = f_dataMC_fakerate_tau_medium_barrel[3]->Eval(tau_pt);	  	    

	      }

	      else{

          jetToTau_FR_byLoose_SF_tauNormUp = f_dataMC_fakerate_tau_loose_endcap[0]->Eval(tau_pt);
          jetToTau_FR_byLoose_SF_tauNormDown = f_dataMC_fakerate_tau_loose_endcap[1]->Eval(tau_pt);
          jetToTau_FR_byLoose_SF_tauShapeUp = f_dataMC_fakerate_tau_loose_endcap[2]->Eval(tau_pt);
          jetToTau_FR_byLoose_SF_tauShapeDown = f_dataMC_fakerate_tau_loose_endcap[3]->Eval(tau_pt);

          jetToTau_FR_byMedium_SF_tauNormUp = f_dataMC_fakerate_tau_medium_endcap[0]->Eval(tau_pt);
          jetToTau_FR_byMedium_SF_tauNormDown = f_dataMC_fakerate_tau_medium_endcap[1]->Eval(tau_pt);
          jetToTau_FR_byMedium_SF_tauShapeUp = f_dataMC_fakerate_tau_medium_endcap[2]->Eval(tau_pt);
          jetToTau_FR_byMedium_SF_tauShapeDown = f_dataMC_fakerate_tau_medium_endcap[3]->Eval(tau_pt);   	    	    

	      }

        _recotauh_sel_jetToTau_FR_byLoose_SF_tauNormUp.push_back(jetToTau_FR_byLoose_SF_tauNormUp);
        _recotauh_sel_jetToTau_FR_byLoose_SF_tauNormDown.push_back(jetToTau_FR_byLoose_SF_tauNormDown);
        _recotauh_sel_jetToTau_FR_byLoose_SF_tauShapeUp.push_back(jetToTau_FR_byLoose_SF_tauShapeUp);
        _recotauh_sel_jetToTau_FR_byLoose_SF_tauShapeDown.push_back(jetToTau_FR_byLoose_SF_tauShapeDown);  

	      _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormUp.push_back(jetToTau_FR_byMedium_SF_tauNormUp);
	      _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormDown.push_back(jetToTau_FR_byMedium_SF_tauNormDown);
	      _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeUp.push_back(jetToTau_FR_byMedium_SF_tauShapeUp);
	      _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeDown.push_back(jetToTau_FR_byMedium_SF_tauShapeDown);      

      }

      _tauSF_weight_tauNormUp = 1;
      _tauSF_weight_tauNormDown = 1;
      _tauSF_weight_tauShapeUp = 1;
      _tauSF_weight_tauShapeDown = 1;

     
      if(_category==20 || _category==50 || _category==21 || _category==51){	

	      if(isMC){

            _tauSF_weight_tauNormUp *= _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormUp[0];
            _tauSF_weight_tauNormDown *= _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormDown[0];
            _tauSF_weight_tauShapeUp *= _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeUp[0];
            _tauSF_weight_tauShapeDown *= _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeDown[0];

            _tauSF_weight_tauNormUp *= _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormUp[1];
            _tauSF_weight_tauNormDown *= _recotauh_sel_jetToTau_FR_byMedium_SF_tauNormDown[1];
            _tauSF_weight_tauShapeUp *= _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeUp[1];
            _tauSF_weight_tauShapeDown *= _recotauh_sel_jetToTau_FR_byMedium_SF_tauShapeDown[1];

	      }

      }
      
      else if(_category==11 || _category==41 || _category==16 || _category==46){

	      if(isMC){
  
	          _tauSF_weight_tauNormUp *= _recotauh_sel_jetToTau_FR_byLoose_SF_tauNormUp[0];
	          _tauSF_weight_tauNormDown *= _recotauh_sel_jetToTau_FR_byLoose_SF_tauNormDown[0];
	          _tauSF_weight_tauShapeUp *= _recotauh_sel_jetToTau_FR_byLoose_SF_tauShapeUp[0];
	          _tauSF_weight_tauShapeDown *= _recotauh_sel_jetToTau_FR_byLoose_SF_tauShapeDown[0];

        }
	
      }	
      
      tree_new->Fill();

    }

   
    f_new->cd();
    
    tree_new->Write();


  }

  f_new->Close();


  return;

}






void test(){

  vector<TString> filein;
  vector<TString> fileout;

  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THW_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THQ_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_lowmass_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttW_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttG_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WZ_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_ZZ_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WpWp_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ZZZ_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WZZ_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWZ_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWW_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ttWW_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_TTTT_split_BDT.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_tZq_split_BDT.root");

  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THW_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THQ_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_lowmass_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttW_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttG_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WZ_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_ZZ_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WpWp_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ZZZ_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WZZ_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWZ_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWW_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ttWW_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_TTTT_split_BDT_tauSF.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_tZq_split_BDT_tauSF.root");

  vector<TString> tree;
  tree.push_back("HTauTauTree_1l_2tau_SR");
  tree.push_back("HTauTauTree_1l_2tau_fake");
  /*tree.push_back("HTauTauTree_2lSS_SR");
  tree.push_back("HTauTauTree_2lSS_fake");
  tree.push_back("HTauTauTree_2lSS_flip");*/
  tree.push_back("HTauTauTree_2lSS_1tau_SR");
  tree.push_back("HTauTauTree_2lSS_1tau_fake");
  tree.push_back("HTauTauTree_2lSS_1tau_flip");
  tree.push_back("HTauTauTree_2l_2tau_SR");
  tree.push_back("HTauTauTree_2l_2tau_fake");
  /*tree.push_back("HTauTauTree_3l_SR");
  tree.push_back("HTauTauTree_3l_fake");*/
  tree.push_back("HTauTauTree_3l_1tau_SR");
  tree.push_back("HTauTauTree_3l_1tau_fake");
  /*tree.push_back("HTauTauTree_4l_SR");
  tree.push_back("HTauTauTree_4l_fake");
  tree.push_back("HTauTauTree_ttWctrl_SR");
  tree.push_back("HTauTauTree_ttWctrl_fake");
  tree.push_back("HTauTauTree_ttWctrl_flip");
  tree.push_back("HTauTauTree_ttZctrl_SR");
  tree.push_back("HTauTauTree_ttZctrl_fake");*/

  for (int i_file = 0; i_file<filein.size(); i_file++){
    add_tauSF(filein[i_file],fileout[i_file],tree,true);  
  }   

}
