#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TCanvas.h>
#include <iostream>
#include "PUweight.cc"


using namespace std;



void create_PUtree(TString filein, TString fileout, TString treename, TString samplename){
  
  TFile* f_new = TFile::Open(fileout);
  if(f_new!=0){
    cout<<fileout<<" already exists, please delete it before converting again"<<endl;
    return;
  }
  f_new = TFile::Open(fileout,"RECREATE");

  TChain * tree = new TChain(treename);
  //for(unsigned int i=0;i<filein.size();i++)
  //  tree->Add(filein[i]);
  tree->Add(filein);
  Long64_t nentries = tree->GetEntries();
  cout<<"nentries="<<tree->GetEntries()<<endl;

  TTree* tree_new=new TTree(treename,treename);
  
  //New branches
  unsigned long long _EventNumber = -1;
  int _RunNumber = -1, _lumi = -1;

  float _npu;
  float _MC_weight;
  float _PU_weight_ICHEP18;

  tree_new->Branch("EventNumber",&_EventNumber,"EventNumber/l");
  tree_new->Branch("RunNumber",&_RunNumber,"RunNumber/I");
  tree_new->Branch("lumi",&_lumi,"lumi/I");
  tree_new->Branch("npu",&_npu,"npu/F");
  tree_new->Branch("MC_weight",&_MC_weight,"MC_weight/F");
  tree_new->Branch("PU_weight_ICHEP18",&_PU_weight_ICHEP18,"PU_weight_ICHEP18/F");

  tree->SetBranchAddress("EventNumber",&_EventNumber);
  tree->SetBranchAddress("RunNumber",&_RunNumber);
  tree->SetBranchAddress("lumi",&_lumi);
  tree->SetBranchAddress("npu",&_npu);
  tree->SetBranchAddress("MC_weight",&_MC_weight);

  for(int i=0;i<nentries;i++){ //nentries
  
      if(i%10000==0)
	cout<<"i="<<i<<endl;

      _npu = 0;
      _MC_weight = 0;
      _PU_weight_ICHEP18 = 0;
      
      tree->GetEntry(i);

      _PU_weight_ICHEP18 = getPUweight(_npu,true,samplename);
  
      tree_new->Fill();
  }

  f_new->cd();
    
  tree_new->Write();

  f_new->Close();

  return;

}






void add_PUweight(TString filein, TString fileout, vector<TString> treename, TString samplename){


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
    
    float _npu;
    tree->SetBranchAddress("npu",&_npu);

    
    TTree* tree_new=tree->GetTree()->CloneTree(0);
    
    //New branches
    float _PU_weight_ICHEP18;
    tree_new->Branch("PU_weight_ICHEP18",&_PU_weight_ICHEP18,"PU_weight_ICHEP18/F");


    for(int i=0;i<nentries;i++){
      
      if(i%10000==0)
	cout<<"i="<<i<<endl;

      _PU_weight_ICHEP18 = 0;

      _npu = 0;

      tree->GetEntry(i);

      _PU_weight_ICHEP18 = getPUweight(_npu,true,samplename);

      tree_new->Fill();

    }
    
    
    f_new->cd();
    
    tree_new->Write();


  }

  f_new->Close();


  return;

}
      




void test(){

  for (int j = 0; j<5; j++){
     
     TString filein=Form("/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_ttH_Hnonbb_%i_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root",j);
     TString fileout=Form("/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_ttH_Hnonbb_%i_PU.root",j);
     cout << fileout << endl;
     TString treename = "HTauTauTree";
     TString samplename = "ttHJetToNonbb";
     create_PUtree(filein,fileout,treename,samplename);
 
  }

}





void test2(){

  vector<TString> treename;
  treename.push_back("HTauTauTree_1l_2tau_fake_CR");
  treename.push_back("HTauTauTree_1l_2tau");
  treename.push_back("HTauTauTree_2lSS");
  treename.push_back("HTauTauTree_2lOS_CR");
  treename.push_back("HTauTauTree_2lSS_lepMVA_CR");
  treename.push_back("HTauTauTree_3l");
  treename.push_back("HTauTauTree_3l_lepMVA_CR");
  treename.push_back("HTauTauTree_2l_2tau");
  treename.push_back("HTauTauTree_2l_2tau_fake_CR"); 
 
/*  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_withPU.root";
  TString samplename = "ttHJetToNonbb"; 
  add_PUweight(filein,fileout,treename,samplename);*/

/*  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWW_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWW_split_withPU.root";
  TString samplename = "WWW";
  add_PUweight(filein,fileout,treename,samplename);*/

/*  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWZ_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWZ_split_withPU.root";
  TString samplename = "WWZ";
  add_PUweight(filein,fileout,treename,samplename);*/

/*  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WZZ_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WZZ_split_withPU.root";
  TString samplename = "WZZ";
  add_PUweight(filein,fileout,treename,samplename);*/
 
/*  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ZZZ_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ZZZ_split_withPU.root";
  TString samplename = "ZZZ";
  add_PUweight(filein,fileout,treename,samplename);*/

/*  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttW_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttW_split_withPU.root";
  TString samplename = "TTW";
  add_PUweight(filein,fileout,treename,samplename);*/

/*  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_split_withPU.root";
  TString samplename = "TTZ";
  add_PUweight(filein,fileout,treename,samplename);*/

/*  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WZ_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WZ_split_withPU.root";
  TString samplename = "WZ";
  add_PUweight(filein,fileout,treename,samplename);*/

  TString filein = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/TT/HTauTauTree_TTLeptons_split.root";
  TString fileout = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/TT/HTauTauTree_TTLeptons_split_withPU.root";
  TString samplename = "TTToDiLep";
  add_PUweight(filein,fileout,treename,samplename);

  /*TString filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/TTbar/ttbar_DL_ext_split_2lSS_lepMVA_CR_MEM_160110.root";
  TString fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/TTbar/ttbar_DL_ext_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);*/

  /*TString filein = "/data_CMS/cms/strebler/ttH_prod_80X_11_2016/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_bTagSF_CSVshape.root";
  TString fileout = "/data_CMS/cms/strebler/ttH_prod_80X_11_2016/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_bTagSF_CSVshape_PU.root";
  add_PUweight(filein,fileout,treename);*/

  /*TString filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/JECup/Rares/HTauTauTree_tZq_split_JECup.root";
  TString fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/JECup/Rares/HTauTauTree_tZq_split_JECup_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/JECdown/Rares/HTauTauTree_tZq_split_JECdown.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/JECdown/Rares/HTauTauTree_tZq_split_JECdown_PU.root";
  add_PUweight(filein,fileout,treename);*/

  /*filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/TESup/Rares/HTauTauTree_tZq_split_TESup.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/TESup/Rares/HTauTauTree_tZq_split_TESup_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/TESdown/Rares/HTauTauTree_tZq_split_TESdown.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/TESdown/Rares/HTauTauTree_tZq_split_TESdown_PU.root";
  add_PUweight(filein,fileout,treename);*/

  /*TString filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/nominal/TTbar/HTauTauTree_ttbar_SLfromT_split.root";
  TString fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/nominal/TTbar/HTauTauTree_ttbar_SLfromT_split_PU.root";
  add_PUweight(filein,fileout,treename);


  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/nominal/TTbar/HTauTauTree_ttbar_SLfromTbar_split.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_splitted/nominal/TTbar/HTauTauTree_ttbar_SLfromTbar_split_PU.root";
  add_PUweight(filein,fileout,treename);*/

//  vector<TString> treename;
//  treename.push_back("T");  

  /*vector<TString> syst;
  syst.push_back("JECup");
  syst.push_back("JECdown");
  syst.push_back("TESup");
  syst.push_back("TESdown");

  for(unsigned int i=0;i<4;i++){
    TString filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/"+syst[i]+"/Rares/tZq_split_*16*.root";
    TString fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/"+syst[i]+"/Rares/tZq_split_"+syst[i]+"_2lSS_MEM_PU.root";
    add_PUweight(filein,fileout,treename);
  }*/

  /*TString filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/ttV/ttG_split_2lSS_lepMVA_CR_MEM_1*.root";
  TString fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/ttV/ttG_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/ttV/ttW_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/ttV/ttW_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/ttV/ttZ_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/ttV/ttZ_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/EWK/WZ_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/EWK/WZ_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);
  
  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/WWW_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/WWW_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/WWZ_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/WWZ_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/WZZ_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/WZZ_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/ZZZ_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/ZZZ_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);

 filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/WpWp_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/WpWp_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);

  filein = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/tZq_split_2lSS_lepMVA_CR_MEM_1*.root";
  fileout = "/data_CMS/cms/strebler/ttH_prod_80X_12_2016/ntuples_MEM/nominal/Rares/tZq_split_2lSS_lepMVA_CR_MEM_PU.root";
  add_PUweight(filein,fileout,treename);
  */
}
