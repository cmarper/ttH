#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TH1F.h>
#include <iostream>

using namespace std;

vector<TString> triggerlist;

vector<TString> triggerlist_1e;
vector<TString> triggerlist_1m;
vector<TString> triggerlist_em;
vector<TString> triggerlist_et;
vector<TString> triggerlist_mt;
vector<TString> triggerlist_2e;
vector<TString> triggerlist_2m;
vector<TString> triggerlist_e2m;
vector<TString> triggerlist_m2e;
vector<TString> triggerlist_3e;
vector<TString> triggerlist_3m;




void produce_triggerlist(){

  TString filename="/data_CMS/cms/mperez/ttH_2017/sync_ntuples/syncNtuple_LLRHTauTau.root";

  TFile* f = TFile::Open(filename);
  TH1F* hCounter = (TH1F*)f->Get("HTauTauTree/Counters");

  for(int itr=1;itr<=hCounter->GetNbinsX();itr++){
    TString binlabel = hCounter->GetXaxis()->GetBinLabel(itr);
    if(binlabel.BeginsWith("HLT"))triggerlist.push_back(hCounter->GetXaxis()->GetBinLabel(itr));
    //cout<<itr<<" "<<hCounter->GetXaxis()->GetBinLabel(itr)<<endl;
  }
}

void produce_triggerlist_singletriggers(){

  triggerlist_1e.push_back("HLT_Ele32_WPTight_Gsf_v");
  triggerlist_1e.push_back("HLT_Ele35_WPTight_Gsf_v");

  triggerlist_1m.push_back("HLT_IsoMu27_v");
  triggerlist_1m.push_back("HLT_IsoMu24_v");

  triggerlist_em.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  triggerlist_em.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
  triggerlist_em.push_back("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");

  triggerlist_et.push_back("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v");

  triggerlist_mt.push_back("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v");

  triggerlist_2e.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  triggerlist_2e.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");

  triggerlist_2m.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
  triggerlist_2m.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");

  triggerlist_e2m.push_back("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_v");

  triggerlist_m2e.push_back("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v");

  triggerlist_3e.push_back("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v");

  triggerlist_2m.push_back("HLT_TripleMu_12_10_5_v");


}


int FindTriggerNumber(TString triggername){
  
  for(unsigned int it=0;it<triggerlist.size();it++){ 	
  	if(triggerlist.at(it).CompareTo(triggername.Data())==0)return it;
  	else {
  	    TString newName=triggername.Data();
  	    newName.Prepend("HLT_");
  	    newName.Append("_v1");
  	    if(triggerlist.at(it).CompareTo(newName.Data())==0)return it;
  	}
  }
  return -1;

}

bool IsTriggerFired(Long64_t triggerbit, int triggernumber){ 
  if(triggernumber>=0) return triggerbit & (long(1) << triggernumber);
  return false;
}


bool IsTriggerFired(Long64_t triggerbit, TString triggername){
  return IsTriggerFired(triggerbit,FindTriggerNumber(triggername));
}


bool pass_trigger_list(Long64_t triggerbit){
  produce_triggerlist();
  for(unsigned int i=0;i<triggerlist.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist[i])){
      cout<< "all: "<<triggerlist[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_1e(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_1e.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_1e[i])){
      cout<< triggerlist_1e[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_1m(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_1m.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_1m[i])){
      cout<< triggerlist_1m[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_2e(Long64_t triggerbit){
  //cout<<"entering"<<endl;
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_2e.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_2e[i])){
      cout<< triggerlist_2e[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_2m(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_2m.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_2m[i])){
      cout<< triggerlist_2m[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_em(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_em.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_em[i])){
      cout<< triggerlist_em[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_et(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_et.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_et[i])){
      cout<< triggerlist_em[i] << endl;
      return true;
    }
  }
}


bool pass_trigger_list_mt(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_mt.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_mt[i])){
      cout<< triggerlist_em[i] << endl;
      return true;
    }
  }
}


bool pass_trigger_list_3e(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_3e.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_3e[i])){
      cout<< triggerlist_3e[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_3m(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_3m.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_3m[i])){
      cout<< triggerlist_3m[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_e2m(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_e2m.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_e2m[i])){
      cout<< triggerlist_e2m[i] << endl;
      return true;
    }
  }
}

bool pass_trigger_list_m2e(Long64_t triggerbit){
  //produce_triggerlist_singletriggers();
  for(unsigned int i=0;i<triggerlist_m2e.size();i++){  
    if(IsTriggerFired(triggerbit,triggerlist_m2e[i])){
      cout<< triggerlist_m2e[i] << endl;
      return true;
    }
  }
}


/*void test(unsigned long tbit){
	produce_triggerlist();
	bool pass_triggers = pass_trigger_list(tbit);
	//cout<<"all "<<pass_triggers<<endl;
	bool pass_triggers_1e = pass_trigger_list_1e(tbit);
	//cout<<"1e "<<pass_triggers_1e<<endl;
	bool pass_triggers_1m = pass_trigger_list_1m(tbit);
	//cout<<"1m "<<pass_triggers_1m<<endl;
	bool pass_triggers_em = pass_trigger_list_em(tbit);
	//cout<<"em "<<pass_triggers_em<<endl;
	bool pass_triggers_2e = pass_trigger_list_2e(tbit);
	//cout<<"2e "<<pass_triggers_2e<<endl;
	bool pass_triggers_2m = pass_trigger_list_2m(tbit);
	//cout<<"2m "<<pass_triggers_2m<<endl;
	bool pass_triggers_3e = pass_trigger_list_3e(tbit);
	//cout<<"3e "<<pass_triggers_3e<<endl;
	bool pass_triggers_3m = pass_trigger_list_3m(tbit);
	//cout<<"3m "<<pass_triggers_3m<<endl;
	bool pass_triggers_m2e = pass_trigger_list_m2e(tbit);
	//cout<<"m2e "<<pass_triggers_m2e<<endl;
	bool pass_triggers_e2m = pass_trigger_list_e2m(tbit);
	//cout<<"e2m "<<pass_triggers_e2m<<endl;

	//cout<<mytest<<endl;
}*/

