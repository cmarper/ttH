#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TCanvas.h>
#include <iostream>
#include "PUweight.cc"


using namespace std;



void create_prefiring_tree(TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_prefiring.root", 
			   TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_prefiring_withProbEvent.root")
			   {
  
  TFile* f_new = TFile::Open(fileout);
  /*if(f_new!=0){
    cout<<fileout<<" already exists, please delete it before converting again"<<endl;
    return;
  }*/
  f_new = TFile::Open(fileout,"RECREATE");

  TChain * tree = new TChain("HTauTauTree_2lSS");
  tree->Add(filein);

  Long64_t nentries = tree->GetEntries();
  cout<<"nentries="<<tree->GetEntries()<<endl;

  //old variables used
  unsigned long long _EventNumber = -1;
  int _RunNumber = -1;
  int _lumi = -1;
  int n_recoPFJet;
  vector<float>* _jets_pt;
  vector<float>* _jets_eta;
  vector<float>* _jets_prefire_prob;
  vector<float>* _recoPFJet_pt;
  vector<float>* _recoPFJet_eta;
  vector<float>* _recoPFJet_prefire_prob;

  tree->SetBranchAddress("EventNumber",&_EventNumber);
  tree->SetBranchAddress("RunNumber",&_RunNumber);
  tree->SetBranchAddress("lumi",&_lumi);
  tree->SetBranchAddress("jets_pt",&_jets_pt);
  tree->SetBranchAddress("jets_eta",&_jets_eta);
  tree->SetBranchAddress("jets_prefire_prob",&_jets_prefire_prob);
  tree->SetBranchAddress("recoPFJet_pt",&_recoPFJet_pt);
  tree->SetBranchAddress("recoPFJet_eta",&_recoPFJet_eta);
  tree->SetBranchAddress("recoPFJet_prefire_prob",&_recoPFJet_prefire_prob);

  TTree* tree_new=tree->GetTree()->CloneTree(0);
  
  //New branches
  float _event_prefire_prob = 0;

  tree_new->Branch("event_prefire_prob",&_event_prefire_prob,"event_prefire_prob/F");
 
//  nentries=10;
  for(int i=0;i<nentries;i++){ //nentries
  
      if(i%1000==0)
	       cout<<"i="<<i<<endl;
   
      n_recoPFJet = 0;
      _jets_pt = 0;
      _jets_eta = 0;
      _jets_prefire_prob = 0;
      _recoPFJet_pt = 0;
      _recoPFJet_eta = 0;
      _recoPFJet_prefire_prob = 0;

      _event_prefire_prob = 0;
      float oneminusp = 1;
      float prod_oneminusp = 1;
      tree->GetEntry(i);

      //cout<<"number of PFJets " << (*_recoPFJet_pt).size() << endl;
      for(unsigned int i_jet=0;i_jet<(*_recoPFJet_pt).size();i_jet++){
        //cout << "jet_prefire_prob "<<(*_jets_prefire_prob)[i_jet]<<endl;
        oneminusp = 1.0 - (*_jets_prefire_prob)[i_jet];
        //cout<<"oneminusp "<<oneminusp<<endl;
        prod_oneminusp *= oneminusp;
        //cout<<"prod_oneminusp "<<prod_oneminusp<<endl;
      }
      //cout<<"----"<<endl;
      _event_prefire_prob = 1.0 - prod_oneminusp;
      //cout<<"event prefire prob "<<_event_prefire_prob<<endl;
      //cout<<"----"<<endl;  

      tree_new->Fill();
  }

  f_new->cd();
    
  tree_new->Write();

  f_new->Close();

  return;

}


