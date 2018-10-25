#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TCanvas.h>
#include <iostream>
#include <TF1.h>
#include <TH2F.h>

using namespace std;


void add_event_weight_elemu(TString filein, TString fileout, vector<TString> treename, bool isMC){


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
    
    vector<int> *_recolep_sel_pdg;    
    vector<float> *_recolep_sel_conept;
    vector<float> *_recolep_sel_pt;
    vector<float> *_recolep_sel_eta;
    vector<bool> *_recolep_sel_ismvasel;
    vector<int> *_recolep_sel_charge; 
    vector<float> *_recolep_sel_fakerate;   

    vector<int> *_recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017;
    vector<int> *_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017;
    vector<float> *_recotauh_sel_pt;
    vector<float> *_recotauh_sel_eta;
    vector<bool> *_recotauh_sel_isGenMatched;
    vector<int> *_recotauh_sel_charge; 
    vector<float> *_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT;
    vector<float> *_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT;

    tree->SetBranchAddress("category",&_category);
    
    tree->SetBranchAddress("recolep_sel_pdg",&_recolep_sel_pdg);
    tree->SetBranchAddress("recolep_sel_conept",&_recolep_sel_conept);
    tree->SetBranchAddress("recolep_sel_pt",&_recolep_sel_pt);
    tree->SetBranchAddress("recolep_sel_eta",&_recolep_sel_eta);
    tree->SetBranchAddress("recolep_sel_ismvasel",&_recolep_sel_ismvasel);
    tree->SetBranchAddress("recolep_sel_charge",&_recolep_sel_charge);
    tree->SetBranchAddress("recolep_sel_fakerate",&_recolep_sel_fakerate);

    tree->SetBranchAddress("recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017",&_recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017);
    tree->SetBranchAddress("recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017",&_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017);
    tree->SetBranchAddress("recotauh_sel_pt",&_recotauh_sel_pt);
    tree->SetBranchAddress("recotauh_sel_eta",&_recotauh_sel_eta);
    tree->SetBranchAddress("recotauh_sel_isGenMatched",&_recotauh_sel_isGenMatched);
    tree->SetBranchAddress("recotauh_sel_charge",&_recotauh_sel_charge);
    tree->SetBranchAddress("recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT);
    tree->SetBranchAddress("recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT",&_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT);

    TTree* tree_new=tree->GetTree()->CloneTree(0);
    
    //New branches
    float _event_weight_ttH_ele_up;
    float _event_weight_ttH_ele_down;
    float _event_weight_ttH_ele_pt1;
    float _event_weight_ttH_ele_pt2;
    /*float _event_weight_ttH_ele_b1;
    float _event_weight_ttH_ele_b2;
    float _event_weight_ttH_ele_ec1;
    float _event_weight_ttH_ele_ec2;*/
    float _event_weight_ttH_ele_be1;
    float _event_weight_ttH_ele_be2;

    float _event_weight_ttH_mu_up;
    float _event_weight_ttH_mu_down;
    float _event_weight_ttH_mu_pt1;
    float _event_weight_ttH_mu_pt2;
    /*float _event_weight_ttH_mu_b1;
    float _event_weight_ttH_mu_b2;
    float _event_weight_ttH_mu_ec1;
    float _event_weight_ttH_mu_ec2;*/
    float _event_weight_ttH_mu_be1;
    float _event_weight_ttH_mu_be2;

    tree_new->Branch("event_weight_ttH_ele_up",&_event_weight_ttH_ele_up,"event_weight_ttH_ele_up/F");
    tree_new->Branch("event_weight_ttH_ele_down",&_event_weight_ttH_ele_down,"event_weight_ttH_ele_down/F");
    tree_new->Branch("event_weight_ttH_ele_pt1",&_event_weight_ttH_ele_pt1,"event_weight_ttH_ele_pt1/F");
    tree_new->Branch("event_weight_ttH_ele_pt2",&_event_weight_ttH_ele_pt2,"event_weight_ttH_ele_pt2/F");
    /*tree_new->Branch("event_weight_ttH_ele_b1",&_event_weight_ttH_ele_b1,"event_weight_ttH_ele_b1/F");
    tree_new->Branch("event_weight_ttH_ele_b2",&_event_weight_ttH_ele_b2,"event_weight_ttH_ele_b2/F");
    tree_new->Branch("event_weight_ttH_ele_ec1",&_event_weight_ttH_ele_ec1,"event_weight_ttH_ele_ec1/F");
    tree_new->Branch("event_weight_ttH_ele_ec2",&_event_weight_ttH_ele_ec2,"event_weight_ttH_ele_ec2/F");*/
    tree_new->Branch("event_weight_ttH_ele_be1",&_event_weight_ttH_ele_be1,"event_weight_ttH_ele_be1/F");
    tree_new->Branch("event_weight_ttH_ele_be2",&_event_weight_ttH_ele_be2,"event_weight_ttH_ele_be2/F");

    tree_new->Branch("event_weight_ttH_mu_up",&_event_weight_ttH_mu_up,"event_weight_ttH_mu_up/F");
    tree_new->Branch("event_weight_ttH_mu_down",&_event_weight_ttH_mu_down,"event_weight_ttH_mu_down/F");
    tree_new->Branch("event_weight_ttH_mu_pt1",&_event_weight_ttH_mu_pt1,"event_weight_ttH_mu_pt1/F");
    tree_new->Branch("event_weight_ttH_mu_pt2",&_event_weight_ttH_mu_pt2,"event_weight_ttH_mu_pt2/F");
    /*tree_new->Branch("event_weight_ttH_mu_b1",&_event_weight_ttH_mu_b1,"event_weight_ttH_mu_b1/F");
    tree_new->Branch("event_weight_ttH_mu_b2",&_event_weight_ttH_mu_b2,"event_weight_ttH_mu_b2/F");
    tree_new->Branch("event_weight_ttH_mu_ec1",&_event_weight_ttH_mu_ec1,"event_weight_ttH_mu_ec1/F");
    tree_new->Branch("event_weight_ttH_mu_ec2",&_event_weight_ttH_mu_ec2,"event_weight_ttH_mu_ec2/F");*/
    tree_new->Branch("event_weight_ttH_mu_be1",&_event_weight_ttH_mu_be1,"event_weight_ttH_mu_be1/F");
    tree_new->Branch("event_weight_ttH_mu_be2",&_event_weight_ttH_mu_be2,"event_weight_ttH_mu_be2/F");

    TFile* f_fakerate = TFile::Open("fake_rate_weights/FR_lep_ttH_mva090_2017_CERN_2018May29.root");

    TH2F* h_fakerate_mu = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb");
    h_fakerate_mu->SetDirectory(0);
    TH2F* h_fakerate_el = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC");
    h_fakerate_el->SetDirectory(0);
    
    TH2F* h_fakerate_mu_data_up = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_up");
    h_fakerate_mu_data_up->SetDirectory(0);
    TH2F* h_fakerate_el_data_up = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_up");
    h_fakerate_el_data_up->SetDirectory(0);

    TH2F* h_fakerate_mu_data_down = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_down");
    h_fakerate_mu_data_down->SetDirectory(0);
    TH2F* h_fakerate_el_data_down = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_down");
    h_fakerate_el_data_down->SetDirectory(0);

    TH2F* h_fakerate_mu_data_pt1 = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_pt1");
    h_fakerate_mu_data_pt1->SetDirectory(0);
    TH2F* h_fakerate_el_data_pt1 = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_pt1");
    h_fakerate_el_data_pt1->SetDirectory(0);

    TH2F* h_fakerate_mu_data_pt2 = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_pt2");
    h_fakerate_mu_data_pt2->SetDirectory(0);
    TH2F* h_fakerate_el_data_pt2 = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_pt2");
    h_fakerate_el_data_pt2->SetDirectory(0);

    /*TH2F* h_fakerate_mu_data_b1 = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_b1");
    h_fakerate_mu_data_b1->SetDirectory(0);
    TH2F* h_fakerate_el_data_b1 = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_b1");
    h_fakerate_el_data_b1->SetDirectory(0);

    TH2F* h_fakerate_mu_data_b2 = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_b2");
    h_fakerate_mu_data_b2->SetDirectory(0);
    TH2F* h_fakerate_el_data_b2 = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_b2");
    h_fakerate_el_data_b2->SetDirectory(0);

    TH2F* h_fakerate_mu_data_ec1 = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_ec1");
    h_fakerate_mu_data_ec1->SetDirectory(0);
    TH2F* h_fakerate_el_data_ec1 = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_ec1");
    h_fakerate_el_data_ec1->SetDirectory(0);

    TH2F* h_fakerate_mu_data_ec2 = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_ec2");
    h_fakerate_mu_data_ec2->SetDirectory(0);
    TH2F* h_fakerate_el_data_ec2 = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_ec2");
    h_fakerate_el_data_ec2->SetDirectory(0);*/

    TH2F* h_fakerate_mu_data_be1 = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_be1");
    h_fakerate_mu_data_be1->SetDirectory(0);
    TH2F* h_fakerate_el_data_be1 = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_be1");
    h_fakerate_el_data_be1->SetDirectory(0);

    TH2F* h_fakerate_mu_data_be2 = (TH2F*)f_fakerate->Get("FR_mva090_mu_data_comb_be2");
    h_fakerate_mu_data_be2->SetDirectory(0);
    TH2F* h_fakerate_el_data_be2 = (TH2F*)f_fakerate->Get("FR_mva090_el_data_comb_NC_be2");
    h_fakerate_el_data_be2->SetDirectory(0);

    f_fakerate->Close();

    vector<float> _recolep_sel_fakerate_up;
    vector<float> _recolep_sel_fakerate_down;
    vector<float> _recolep_sel_fakerate_pt1;
    vector<float> _recolep_sel_fakerate_pt2;
    /*vector<float> _recolep_sel_fakerate_b1;
    vector<float> _recolep_sel_fakerate_b2;
    vector<float> _recolep_sel_fakerate_ec1;
    vector<float> _recolep_sel_fakerate_ec2;*/
    vector<float> _recolep_sel_fakerate_be1;
    vector<float> _recolep_sel_fakerate_be2;


    for(int i=0;i<nentries;i++){
      
      if(i%10000==0)
	      cout<<"i="<<i<<endl;

      _category = 0;

      _recolep_sel_pdg = 0;
      _recolep_sel_ismvasel = 0;
      _recolep_sel_conept = 0;
      _recolep_sel_pt = 0;
      _recolep_sel_eta = 0;
      _recolep_sel_charge = 0;
      _recolep_sel_fakerate = 0;

      _recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017 = 0;
      _recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017 = 0;
      _recotauh_sel_pt = 0;
      _recotauh_sel_eta = 0;
      _recotauh_sel_isGenMatched = 0;
      _recotauh_sel_charge = 0;
      _recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT = 0;
      _recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT = 0;

      _recolep_sel_fakerate_up.clear();
      _recolep_sel_fakerate_down.clear();
      _recolep_sel_fakerate_pt1.clear();
      _recolep_sel_fakerate_pt2.clear();
      /*_recolep_sel_fakerate_b1.clear();
      _recolep_sel_fakerate_b2.clear();
      _recolep_sel_fakerate_ec1.clear();
      _recolep_sel_fakerate_ec2.clear();*/
      _recolep_sel_fakerate_be1.clear();
      _recolep_sel_fakerate_be2.clear();

      _event_weight_ttH_ele_up = 0;
      _event_weight_ttH_ele_down = 0;
      _event_weight_ttH_ele_pt1 = 0;
      _event_weight_ttH_ele_pt2 = 0;
      /*_event_weight_ttH_ele_b1 = 0;
      _event_weight_ttH_ele_b2 = 0;
      _event_weight_ttH_ele_ec1 = 0;
      _event_weight_ttH_ele_ec2 = 0;*/
      _event_weight_ttH_ele_be1 = 0;
      _event_weight_ttH_ele_be2 = 0;

      _event_weight_ttH_mu_up = 0;
      _event_weight_ttH_mu_down = 0;
      _event_weight_ttH_mu_pt1 = 0;
      _event_weight_ttH_mu_pt2 = 0;
      /*_event_weight_ttH_mu_b1 = 0;
      _event_weight_ttH_mu_b2 = 0;
      _event_weight_ttH_mu_ec1 = 0;
      _event_weight_ttH_mu_ec2 = 0;*/
      _event_weight_ttH_mu_be1 = 0;
      _event_weight_ttH_mu_be2 = 0;

      tree->GetEntry(i);

      for(unsigned int i_lep=0;i_lep<(*_recolep_sel_pdg).size();i_lep++){

	      float FR = 0;
	      float conept = (*_recolep_sel_conept)[i_lep];

	      if(abs((*_recolep_sel_pdg)[i_lep])==11){

          int bin_FR = h_fakerate_el_data_up->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_up->GetBinContent(bin_FR);
          _recolep_sel_fakerate_up.push_back(FR);

          bin_FR = h_fakerate_el_data_down->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_down->GetBinContent(bin_FR);
          _recolep_sel_fakerate_down.push_back(FR);

          bin_FR = h_fakerate_el_data_pt1->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_pt1->GetBinContent(bin_FR);
          _recolep_sel_fakerate_pt1.push_back(FR);

          bin_FR = h_fakerate_el_data_pt2->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_pt2->GetBinContent(bin_FR);
          _recolep_sel_fakerate_pt2.push_back(FR);

          /*bin_FR = h_fakerate_el_data_b1->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_b1->GetBinContent(bin_FR);
          _recolep_sel_fakerate_b1.push_back(FR);

          bin_FR = h_fakerate_el_data_b2->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_b2->GetBinContent(bin_FR);
          _recolep_sel_fakerate_b2.push_back(FR);

          bin_FR = h_fakerate_el_data_ec1->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_ec1->GetBinContent(bin_FR);
          _recolep_sel_fakerate_ec1.push_back(FR);

          bin_FR = h_fakerate_el_data_ec2->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_ec2->GetBinContent(bin_FR);
          _recolep_sel_fakerate_ec2.push_back(FR);*/

          bin_FR = h_fakerate_el_data_be1->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_be1->GetBinContent(bin_FR);
          _recolep_sel_fakerate_be1.push_back(FR);

          bin_FR = h_fakerate_el_data_be2->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_el_data_be2->GetBinContent(bin_FR);
          _recolep_sel_fakerate_be2.push_back(FR);

	      }

	      else if(abs((*_recolep_sel_pdg)[i_lep])==13){

          int bin_FR = h_fakerate_mu_data_up->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_up->GetBinContent(bin_FR);
          _recolep_sel_fakerate_up.push_back(FR);

          bin_FR = h_fakerate_mu_data_down->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_down->GetBinContent(bin_FR);
          _recolep_sel_fakerate_down.push_back(FR);

          bin_FR = h_fakerate_mu_data_pt1->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_pt1->GetBinContent(bin_FR);
          _recolep_sel_fakerate_pt1.push_back(FR);

          bin_FR = h_fakerate_mu_data_pt2->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_pt2->GetBinContent(bin_FR);
          _recolep_sel_fakerate_pt2.push_back(FR);

          /*bin_FR = h_fakerate_mu_data_b1->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_b1->GetBinContent(bin_FR);
          _recolep_sel_fakerate_b1.push_back(FR);

          bin_FR = h_fakerate_mu_data_b2->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_b2->GetBinContent(bin_FR);
          _recolep_sel_fakerate_b2.push_back(FR);

          bin_FR = h_fakerate_mu_data_ec1->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_ec1->GetBinContent(bin_FR);
          _recolep_sel_fakerate_ec1.push_back(FR);

          bin_FR = h_fakerate_mu_data_ec2->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_ec2->GetBinContent(bin_FR);
          _recolep_sel_fakerate_ec2.push_back(FR);*/

          bin_FR = h_fakerate_mu_data_be1->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_be1->GetBinContent(bin_FR);
          _recolep_sel_fakerate_be1.push_back(FR);

          bin_FR = h_fakerate_mu_data_be2->FindBin(min(conept,float(99.)), abs((*_recolep_sel_eta)[i_lep]));
          FR = h_fakerate_mu_data_be2->GetBinContent(bin_FR);
          _recolep_sel_fakerate_be2.push_back(FR);

	      }

      }

      _event_weight_ttH_ele_up = 1;
      _event_weight_ttH_ele_down = 1;
      _event_weight_ttH_ele_pt1 = 1;
      _event_weight_ttH_ele_pt2 = 1;
      /*_event_weight_ttH_ele_b1 = 1;
      _event_weight_ttH_ele_b2 = 1;
      _event_weight_ttH_ele_ec1 = 1;
      _event_weight_ttH_ele_ec2 = 1;*/
      _event_weight_ttH_ele_be1 = 1;
      _event_weight_ttH_ele_be2 = 1;

      _event_weight_ttH_mu_up = 1;
      _event_weight_ttH_mu_down = 1;
      _event_weight_ttH_mu_pt1 = 1;
      _event_weight_ttH_mu_pt2 = 1;
      /*_event_weight_ttH_mu_b1 = 1;
      _event_weight_ttH_mu_b2 = 1;
      _event_weight_ttH_mu_ec1 = 1;
      _event_weight_ttH_mu_ec2 = 1;*/
      _event_weight_ttH_mu_be1 = 1;
      _event_weight_ttH_mu_be2 = 1;

      
      if(_category==20 || _category==50 || _category==21 || _category==51){ //1l2tau and 2l2tau

        //cout<<"entering cats"<<endl;
	
	      int n_fake = 0;

        for(unsigned int i_lep=0;i_lep<(*_recolep_sel_fakerate).size();i_lep++){

          if(!(*_recolep_sel_ismvasel)[i_lep]){
    
            float lep_weight = (*_recolep_sel_fakerate)[i_lep]/(1-(*_recolep_sel_fakerate)[i_lep]);
    
            if(abs((*_recolep_sel_pdg)[i_lep])==11){

              _event_weight_ttH_ele_up *= _recolep_sel_fakerate_up[i_lep]/(1-_recolep_sel_fakerate_up[i_lep]);
              _event_weight_ttH_ele_down *= _recolep_sel_fakerate_down[i_lep]/(1-_recolep_sel_fakerate_down[i_lep]);
              _event_weight_ttH_ele_pt1 *= _recolep_sel_fakerate_pt1[i_lep]/(1-_recolep_sel_fakerate_pt1[i_lep]);
              _event_weight_ttH_ele_pt2 *= _recolep_sel_fakerate_pt2[i_lep]/(1-_recolep_sel_fakerate_pt2[i_lep]);
              /*_event_weight_ttH_ele_b1 *= _recolep_sel_fakerate_b1[i_lep]/(1-_recolep_sel_fakerate_b1[i_lep]);
              _event_weight_ttH_ele_b2 *= _recolep_sel_fakerate_b2[i_lep]/(1-_recolep_sel_fakerate_b2[i_lep]);
              _event_weight_ttH_ele_ec1 *= _recolep_sel_fakerate_ec1[i_lep]/(1-_recolep_sel_fakerate_ec1[i_lep]);
              _event_weight_ttH_ele_ec2 *= _recolep_sel_fakerate_ec2[i_lep]/(1-_recolep_sel_fakerate_ec2[i_lep]);*/
              _event_weight_ttH_ele_be1 *= _recolep_sel_fakerate_be1[i_lep]/(1-_recolep_sel_fakerate_be1[i_lep]);
              _event_weight_ttH_ele_be2 *= _recolep_sel_fakerate_be2[i_lep]/(1-_recolep_sel_fakerate_be2[i_lep]);

              _event_weight_ttH_mu_up *= lep_weight;
              _event_weight_ttH_mu_down *= lep_weight;
              _event_weight_ttH_mu_pt1 *= lep_weight;
              _event_weight_ttH_mu_pt2 *= lep_weight;
              /*_event_weight_ttH_mu_b1 *= lep_weight;
              _event_weight_ttH_mu_b2 *= lep_weight;
              _event_weight_ttH_mu_ec1 *= lep_weight;
              _event_weight_ttH_mu_ec2 *= lep_weight;*/
              _event_weight_ttH_mu_be1 *= lep_weight;
              _event_weight_ttH_mu_be2 *= lep_weight;

            }
      
            else if(abs((*_recolep_sel_pdg)[i_lep])==13){

              _event_weight_ttH_ele_up *= lep_weight;
              _event_weight_ttH_ele_down *= lep_weight;
              _event_weight_ttH_ele_pt1 *= lep_weight;
              _event_weight_ttH_ele_pt2 *= lep_weight;
              /*_event_weight_ttH_ele_b1 *= lep_weight;
              _event_weight_ttH_ele_b2 *= lep_weight;
              _event_weight_ttH_ele_ec1 *= lep_weight;
              _event_weight_ttH_ele_ec2 *= lep_weight;*/
              _event_weight_ttH_ele_be1 *= lep_weight;
              _event_weight_ttH_ele_be2 *= lep_weight;
 
              _event_weight_ttH_mu_up *= _recolep_sel_fakerate_up[i_lep]/(1-_recolep_sel_fakerate_up[i_lep]);
              _event_weight_ttH_mu_down *= _recolep_sel_fakerate_down[i_lep]/(1-_recolep_sel_fakerate_down[i_lep]);
              _event_weight_ttH_mu_pt1 *= _recolep_sel_fakerate_pt1[i_lep]/(1-_recolep_sel_fakerate_pt1[i_lep]);
              _event_weight_ttH_mu_pt2 *= _recolep_sel_fakerate_pt2[i_lep]/(1-_recolep_sel_fakerate_pt2[i_lep]);
              /*_event_weight_ttH_mu_b1 *= _recolep_sel_fakerate_b1[i_lep]/(1-_recolep_sel_fakerate_b1[i_lep]);
              _event_weight_ttH_mu_b2 *= _recolep_sel_fakerate_b2[i_lep]/(1-_recolep_sel_fakerate_b2[i_lep]);
              _event_weight_ttH_mu_ec1 *= _recolep_sel_fakerate_ec1[i_lep]/(1-_recolep_sel_fakerate_ec1[i_lep]);
              _event_weight_ttH_mu_ec2 *= _recolep_sel_fakerate_ec2[i_lep]/(1-_recolep_sel_fakerate_ec2[i_lep]);*/
              _event_weight_ttH_mu_be1 *= _recolep_sel_fakerate_be1[i_lep]/(1-_recolep_sel_fakerate_be1[i_lep]);
              _event_weight_ttH_mu_be2 *= _recolep_sel_fakerate_be2[i_lep]/(1-_recolep_sel_fakerate_be2[i_lep]);

            }
      
            n_fake++;
    
          }
    
        }


	      for(int i_tau=0; i_tau<2; i_tau++){

	        if(!(*_recotauh_sel_byMediumIsolationMVArun2v2DBdR03oldDMwLT2017)[i_tau]){
	          
            float weight_tau = (*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]/(1-(*_recotauh_fakerate_byMediumIsolationMVArun2v1DBdR03oldDMwLT)[i_tau]);

	          _event_weight_ttH_ele_up *= weight_tau;
	          _event_weight_ttH_ele_down *= weight_tau;
	          _event_weight_ttH_ele_pt1 *= weight_tau;
	          _event_weight_ttH_ele_pt2 *= weight_tau;
	          /*_event_weight_ttH_ele_b1 *= weight_tau;
	          _event_weight_ttH_ele_b2 *= weight_tau;
	          _event_weight_ttH_ele_ec1 *= weight_tau;
	          _event_weight_ttH_ele_ec2 *= weight_tau;*/
            _event_weight_ttH_ele_be1 *= weight_tau;
            _event_weight_ttH_ele_be2 *= weight_tau;

	          _event_weight_ttH_mu_up *= weight_tau;
	          _event_weight_ttH_mu_down *= weight_tau;
	          _event_weight_ttH_mu_pt1 *= weight_tau;
	          _event_weight_ttH_mu_pt2 *= weight_tau;
	          /*_event_weight_ttH_mu_b1 *= weight_tau;
	          _event_weight_ttH_mu_b2 *= weight_tau;
	          _event_weight_ttH_mu_ec1 *= weight_tau;
	          _event_weight_ttH_mu_ec2 *= weight_tau;*/
            _event_weight_ttH_mu_be1 *= weight_tau;
            _event_weight_ttH_mu_be2 *= weight_tau;
	    
	          n_fake++;

	        }

	      }

	      if(n_fake>0 && n_fake%2==0){

	        _event_weight_ttH_ele_up *= -1;
	        _event_weight_ttH_ele_down *= -1;
	        _event_weight_ttH_ele_pt1 *= -1;
	        _event_weight_ttH_ele_pt2 *= -1;
	        /*_event_weight_ttH_ele_b1 *= -1;
	        _event_weight_ttH_ele_b2 *= -1;
	        _event_weight_ttH_ele_ec1 *= -1;
	        _event_weight_ttH_ele_ec2 *= -1;*/
          _event_weight_ttH_ele_be1 *= -1;
          _event_weight_ttH_ele_be2 *= -1;

	        _event_weight_ttH_mu_up *= -1;
	        _event_weight_ttH_mu_down *= -1;
	        _event_weight_ttH_mu_pt1 *= -1;
	        _event_weight_ttH_mu_pt2 *= -1;
	        /*_event_weight_ttH_mu_b1 *= -1;
	        _event_weight_ttH_mu_b2 *= -1;
	        _event_weight_ttH_mu_ec1 *= -1;
	        _event_weight_ttH_mu_ec2 *= -1;*/
          _event_weight_ttH_mu_be1 *= -1;
          _event_weight_ttH_mu_be2 *= -1;
	  
	      }
	
      }

      
      else if(_category==11 || _category==41 || _category==16 || _category==46){ //2lss1tau, 3l1tau

        int n_fake = 0;

	      for(unsigned int i_lep=0;i_lep<(*_recolep_sel_fakerate).size();i_lep++){

	        if(!(*_recolep_sel_ismvasel)[i_lep]){
	  
	          float lep_weight = (*_recolep_sel_fakerate)[i_lep]/(1-(*_recolep_sel_fakerate)[i_lep]);
	  
	          if(abs((*_recolep_sel_pdg)[i_lep])==11){

              _event_weight_ttH_ele_up *= _recolep_sel_fakerate_up[i_lep]/(1-_recolep_sel_fakerate_up[i_lep]);
              _event_weight_ttH_ele_down *= _recolep_sel_fakerate_down[i_lep]/(1-_recolep_sel_fakerate_down[i_lep]);
              _event_weight_ttH_ele_pt1 *= _recolep_sel_fakerate_pt1[i_lep]/(1-_recolep_sel_fakerate_pt1[i_lep]);
              _event_weight_ttH_ele_pt2 *= _recolep_sel_fakerate_pt2[i_lep]/(1-_recolep_sel_fakerate_pt2[i_lep]);
              /*_event_weight_ttH_ele_b1 *= _recolep_sel_fakerate_b1[i_lep]/(1-_recolep_sel_fakerate_b1[i_lep]);
              _event_weight_ttH_ele_b2 *= _recolep_sel_fakerate_b2[i_lep]/(1-_recolep_sel_fakerate_b2[i_lep]);
              _event_weight_ttH_ele_ec1 *= _recolep_sel_fakerate_ec1[i_lep]/(1-_recolep_sel_fakerate_ec1[i_lep]);
              _event_weight_ttH_ele_ec2 *= _recolep_sel_fakerate_ec2[i_lep]/(1-_recolep_sel_fakerate_ec2[i_lep]);*/
              _event_weight_ttH_ele_be1 *= _recolep_sel_fakerate_be1[i_lep]/(1-_recolep_sel_fakerate_be1[i_lep]);
              _event_weight_ttH_ele_be2 *= _recolep_sel_fakerate_be2[i_lep]/(1-_recolep_sel_fakerate_be2[i_lep]);

              _event_weight_ttH_mu_up *= lep_weight;
              _event_weight_ttH_mu_down *= lep_weight;
              _event_weight_ttH_mu_pt1 *= lep_weight;
              _event_weight_ttH_mu_pt2 *= lep_weight;
              /*_event_weight_ttH_mu_b1 *= lep_weight;
              _event_weight_ttH_mu_b2 *= lep_weight;
              _event_weight_ttH_mu_ec1 *= lep_weight;
              _event_weight_ttH_mu_ec2 *= lep_weight;*/
              _event_weight_ttH_mu_be1 *= lep_weight;
              _event_weight_ttH_mu_be2 *= lep_weight;

	          }
	    
	          else if(abs((*_recolep_sel_pdg)[i_lep])==13){

              _event_weight_ttH_ele_up *= lep_weight;
              _event_weight_ttH_ele_down *= lep_weight;
              _event_weight_ttH_ele_pt1 *= lep_weight;
              _event_weight_ttH_ele_pt2 *= lep_weight;
              /*_event_weight_ttH_ele_b1 *= lep_weight;
              _event_weight_ttH_ele_b2 *= lep_weight;
              _event_weight_ttH_ele_ec1 *= lep_weight;
              _event_weight_ttH_ele_ec2 *= lep_weight;*/
              _event_weight_ttH_ele_be1 *= lep_weight;
              _event_weight_ttH_ele_be2 *= lep_weight;
 
              _event_weight_ttH_mu_up *= _recolep_sel_fakerate_up[i_lep]/(1-_recolep_sel_fakerate_up[i_lep]);
              _event_weight_ttH_mu_down *= _recolep_sel_fakerate_down[i_lep]/(1-_recolep_sel_fakerate_down[i_lep]);
              _event_weight_ttH_mu_pt1 *= _recolep_sel_fakerate_pt1[i_lep]/(1-_recolep_sel_fakerate_pt1[i_lep]);
              _event_weight_ttH_mu_pt2 *= _recolep_sel_fakerate_pt2[i_lep]/(1-_recolep_sel_fakerate_pt2[i_lep]);
              /*_event_weight_ttH_mu_b1 *= _recolep_sel_fakerate_b1[i_lep]/(1-_recolep_sel_fakerate_b1[i_lep]);
              _event_weight_ttH_mu_b2 *= _recolep_sel_fakerate_b2[i_lep]/(1-_recolep_sel_fakerate_b2[i_lep]);
              _event_weight_ttH_mu_ec1 *= _recolep_sel_fakerate_ec1[i_lep]/(1-_recolep_sel_fakerate_ec1[i_lep]);
              _event_weight_ttH_mu_ec2 *= _recolep_sel_fakerate_ec2[i_lep]/(1-_recolep_sel_fakerate_ec2[i_lep]);*/
              _event_weight_ttH_mu_be1 *= _recolep_sel_fakerate_be1[i_lep]/(1-_recolep_sel_fakerate_be1[i_lep]);
              _event_weight_ttH_mu_be2 *= _recolep_sel_fakerate_be2[i_lep]/(1-_recolep_sel_fakerate_be2[i_lep]);

	          }
	    
	          n_fake++;
	  
          }
	  
	      }

	      if(!(*_recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017)[0]){
	  
          float weight_tau = (*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[0]/(1.0-(*_recotauh_fakerate_byLooseIsolationMVArun2v1DBdR03oldDMwLT)[0]);
	 
          _event_weight_ttH_ele_up *= weight_tau;
          _event_weight_ttH_ele_down *= weight_tau;
          _event_weight_ttH_ele_pt1 *= weight_tau;
          _event_weight_ttH_ele_pt2 *= weight_tau;
          /*_event_weight_ttH_ele_b1 *= weight_tau;
          _event_weight_ttH_ele_b2 *= weight_tau;
          _event_weight_ttH_ele_ec1 *= weight_tau;
          _event_weight_ttH_ele_ec2 *= weight_tau;*/
          _event_weight_ttH_ele_be1 *= weight_tau;
          _event_weight_ttH_ele_be2 *= weight_tau;

          _event_weight_ttH_mu_up *= weight_tau;
          _event_weight_ttH_mu_down *= weight_tau;
          _event_weight_ttH_mu_pt1 *= weight_tau;
          _event_weight_ttH_mu_pt2 *= weight_tau;
          /*_event_weight_ttH_mu_b1 *= weight_tau;
          _event_weight_ttH_mu_b2 *= weight_tau;
          _event_weight_ttH_mu_ec1 *= weight_tau;
          _event_weight_ttH_mu_ec2 *= weight_tau;*/
          _event_weight_ttH_mu_be1 *= weight_tau;
          _event_weight_ttH_mu_be2 *= weight_tau;
	  
	        n_fake++;

	      }
	

	      if(n_fake>0 && n_fake%2==0){

          _event_weight_ttH_ele_up *= -1;
          _event_weight_ttH_ele_down *= -1;
          _event_weight_ttH_ele_pt1 *= -1;
          _event_weight_ttH_ele_pt2 *= -1;
          /*_event_weight_ttH_ele_b1 *= -1;
          _event_weight_ttH_ele_b2 *= -1;
          _event_weight_ttH_ele_ec1 *= -1;
          _event_weight_ttH_ele_ec2 *= -1;*/
          _event_weight_ttH_ele_be1 *= -1;
          _event_weight_ttH_ele_be2 *= -1;

          _event_weight_ttH_mu_up *= -1;
          _event_weight_ttH_mu_down *= -1;
          _event_weight_ttH_mu_pt1 *= -1;
          _event_weight_ttH_mu_pt2 *= -1;
          /*_event_weight_ttH_mu_b1 *= -1;
          _event_weight_ttH_mu_b2 *= -1;
          _event_weight_ttH_mu_ec1 *= -1;
          _event_weight_ttH_mu_ec2 *= -1;*/
          _event_weight_ttH_mu_be1 *= -1;
          _event_weight_ttH_mu_be2 *= -1;
	  
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

  /*filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THW_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THQ_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_lowmass_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttW_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttG_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WZ_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_ZZ_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WpWp_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ZZZ_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WZZ_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWZ_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWW_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ttWW_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_TTTT_split_BDT_tauSF.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_tZq_split_BDT_tauSF.root");*/

  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap.root");
  filein.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap.root");

  /*fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THW_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THQ_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_lowmass_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttW_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttG_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WZ_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_ZZ_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WpWp_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ZZZ_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WZZ_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWZ_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWW_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ttWW_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_TTTT_split_BDT_tauSF_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_tZq_split_BDT_tauSF_fakelep.root");*/

  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap_fakelep.root");
  fileout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap_fakelep.root");
  
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

  for (unsigned int i_file = 0; i_file<filein.size(); i_file++){
    add_event_weight_elemu(filein[i_file],fileout[i_file],tree,true);  
  }   

}

