#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TH1F.h>
#include <TF1.h>


void add_MEM_variables_to_split_tree(TString filein_MEM, TString filein_BDT, TString treein_BDT, TString fileout){

	cout<<"MEM file: "<<filein_MEM<<endl;
	cout<<"BDT file: "<<filein_BDT<<", tree: "<<treein_BDT<<endl;
	cout<<"Output file: "<<fileout<<endl;

    //tree to get the new variables
    TFile *f_MEM = TFile::Open(filein_MEM, "READ");
    if(!f_MEM) cout<<"No MEM file!"<<endl;
    TTree *t_MEM = (TTree*)f_MEM->Get("T");
    if(!t_MEM) cout<<"No MEM tree!"<<endl;

    // tree to clone
    TFile *f_BDT = TFile::Open(filein_BDT, "READ");
    if(!f_BDT) cout<<"No BDT file!"<<endl;
    TTree *t_BDT = (TTree*)f_BDT->Get(treein_BDT);
    if(!t_BDT) cout<<"No BDT tree!"<<endl;

    // tree out
    TFile *f_out = TFile::Open(fileout,"RECREATE"); 
    TTree *t_out = t_BDT->GetTree()->CloneTree();
    t_out->SetNameTitle("T","T");

    //Variables from t_MEM to copy to t_out
    int   _integration_type;
    float _Integral_ttH;
    float _Integral_ttZ;
    float _Integral_ttZ_Zll;
    float _Integral_ttbar_DL_fakelep_tlep;
    float _Integral_ttbar_DL_fakelep_ttau;

    t_MEM->SetBranchAddress("integration_type",&_integration_type);
    t_MEM->SetBranchAddress("Integral_ttH",&_Integral_ttH);
    t_MEM->SetBranchAddress("Integral_ttZ",&_Integral_ttZ);
    t_MEM->SetBranchAddress("Integral_ttZ_Zll",&_Integral_ttZ_Zll);
    t_MEM->SetBranchAddress("Integral_ttbar_DL_fakelep_tlep",&_Integral_ttbar_DL_fakelep_tlep);
    t_MEM->SetBranchAddress("Integral_ttbar_DL_fakelep_ttau",&_Integral_ttbar_DL_fakelep_ttau);

    //New branches in t_out
    int   _integration_type_2;
    float _Integral_ttH_2;
    float _Integral_ttZ_2;
    float _Integral_ttZ_Zll_2;
    float _Integral_ttbar_DL_fakelep_tlep_2;
    float _Integral_ttbar_DL_fakelep_ttau_2;

    TBranch *b_integration_type_2 = t_out->Branch("integration_type", &_integration_type_2, "integration_type_2/I");
    TBranch *b_Integral_ttH_2 = t_out->Branch("Integral_ttH", &_Integral_ttH_2, "Integral_ttH_2/F");
    TBranch *b_Integral_ttZ_2 = t_out->Branch("Integral_ttZ", &_Integral_ttZ_2, "Integral_ttZ_2/F");
    TBranch *b_Integral_ttZ_Zll_2 = t_out->Branch("Integral_ttZ_Zll", &_Integral_ttZ_Zll_2, "Integral_ttZ_Zll_2/F");
    TBranch *b_Integral_ttbar_DL_fakelep_tlep_2 = t_out->Branch("Integral_ttbar_DL_fakelep_tlep", &_Integral_ttbar_DL_fakelep_tlep_2, "Integral_ttbar_DL_fakelep_tlep_2/F");
    TBranch *b_Integral_ttbar_DL_fakelep_ttau_2 = t_out->Branch("Integral_ttbar_DL_fakelep_ttau", &_Integral_ttbar_DL_fakelep_ttau_2, "Integral_ttbar_DL_fakelep_ttau_2/F");

    Long64_t nentries = t_MEM->GetEntries();
    cout<<"nentries="<<nentries<<endl;

    if (t_MEM->GetEntries() != t_BDT->GetEntries() )
    	cout<<"Entries don't match!"<<endl;

    for(int i=0;i<nentries;i++){

        if(i%10000==0) 
        	cout<<"i="<<i<<endl;

        _integration_type = 0;
   		_Integral_ttH = 0;
   		_Integral_ttZ = 0;
   		_Integral_ttZ_Zll = 0;
   		_Integral_ttbar_DL_fakelep_tlep = 0;
   		_Integral_ttbar_DL_fakelep_ttau = 0;

   		_integration_type_2 = 0;
   		_Integral_ttH_2 = 0;
   		_Integral_ttZ_2 = 0;
   		_Integral_ttZ_Zll_2 = 0;
   		_Integral_ttbar_DL_fakelep_tlep_2 = 0;
   		_Integral_ttbar_DL_fakelep_ttau_2 = 0;

        t_MEM->GetEntry(i);

        _integration_type_2 = _integration_type;
        _Integral_ttH_2 = _Integral_ttH;
        _Integral_ttZ_2 = _Integral_ttZ;
        _Integral_ttZ_Zll_2 = _Integral_ttZ_Zll;
        _Integral_ttbar_DL_fakelep_tlep_2 = _Integral_ttbar_DL_fakelep_tlep;
        _Integral_ttbar_DL_fakelep_ttau_2 = _Integral_ttbar_DL_fakelep_ttau;

        //fill only the relevant branches
        b_integration_type_2->Fill();
        b_Integral_ttH_2->Fill();
   		b_Integral_ttZ_2->Fill();
   		b_Integral_ttZ_Zll_2->Fill();
   		b_Integral_ttbar_DL_fakelep_tlep_2->Fill();
   		b_Integral_ttbar_DL_fakelep_ttau_2->Fill();

    }

   f_out->Write();
   f_out->Close();

}

void test(){

	vector<TString> finMEM;
	vector<TString> finBDT;
	vector<TString> fout;

	TString tinBDT = "HTauTauTree_2lSS_1tau_SR";
	//TString tinBDT = "HTauTauTree_2lSS_1tau_fake";
	//TString tinBDT = "HTauTauTree_2lSS_1tau_flip";

	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/TT/HTauTauTree_TT_Semileptonic_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/TT/HTauTauTree_TT_Leptons_split_MEM.root");

	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/TT/HTauTauTree_TTSemileptonic_split_BDT.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/TT/HTauTauTree_TTLeptons_split_BDT.root");

    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/TT/HTauTauTree_TTSemileptonic_split_BDT_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/TT/HTauTauTree_TTLeptons_split_BDT_MEM.root");


	/*finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_MEM.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_MEM.root");*/

    /*finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_MEM_fakeCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_MEM_fakeCR.root");*/

    /*finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_MEM_flipCR.root");
    finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_MEM_flipCR.root");*/

    /*finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap_fakelep.root");
    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap_fakelep.root");*/

    /*fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root");*/
    
    /*fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root");*/

    /*fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");
    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root");*/

	/*finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/ttH/HTauTauTree_THW_v2_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/ttH/HTauTauTree_THQ_v2_split_MEM.root");

	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/ttV/HTauTauTree_ttW_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/ttV/HTauTauTree_ttZ_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/ttV/HTauTauTree_ttZ_lowmass_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/ttV/HTauTauTree_ttG_split_MEM.root");

	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/EWK/HTauTauTree_WZ_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/EWK/HTauTauTree_ZZ_split_MEM.root");

	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Rares/HTauTauTree_WWW_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Rares/HTauTauTree_WWZ_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Rares/HTauTauTree_WZZ_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Rares/HTauTauTree_ZZZ_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Rares/HTauTauTree_WpWp_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Rares/HTauTauTree_ttWW_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Rares/HTauTauTree_TTTT_split_MEM.root");
	finMEM.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/nominal/Rares/HTauTauTree_tZq_split_MEM.root");


    finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THW_v2_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_THQ_v2_split_BDT_tauSF_fakelep.root");

	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttW_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_lowmass_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttG_split_BDT_tauSF_fakelep.root");

	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WZ_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_ZZ_split_BDT_tauSF_fakelep.root");

	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWW_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWZ_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WZZ_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ZZZ_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WpWp_split_BDT_tauSF_fakelep_PU.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ttWW_split_BDT_tauSF_fakelep_PU.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_TTTT_split_BDT_tauSF_fakelep.root");
	finBDT.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_tZq_split_BDT_tauSF_fakelep.root");


    fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttH/HTauTauTree_THW_v2_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttH/HTauTauTree_THQ_v2_split_BDT_tauSF_fakelep_MEM.root");

	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttV/HTauTauTree_ttW_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttV/HTauTauTree_ttZ_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttV/HTauTauTree_ttZ_lowmass_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttV/HTauTauTree_ttG_split_BDT_tauSF_fakelep_MEM.root");

	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/EWK/HTauTauTree_WZ_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/EWK/HTauTauTree_ZZ_split_BDT_tauSF_fakelep_MEM.root");

	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_WWW_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_WWZ_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_WZZ_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_ZZZ_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_WpWp_split_BDT_tauSF_fakelep_PU_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_ttWW_split_BDT_tauSF_fakelep_PU_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_TTTT_split_BDT_tauSF_fakelep_MEM.root");
	fout.push_back("/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_tZq_split_BDT_tauSF_fakelep_MEM.root");*/


    for (int i_file = 0; i_file<finMEM.size(); i_file++){
       add_MEM_variables_to_split_tree(finMEM[i_file], finBDT[i_file], tinBDT, fout[i_file]);  
    } 
    

}

