#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TH1F.h>
#include <TF1.h>

#include "Helpers.C"

float luminosity = 41298; //41.298 fb-1

float XS_ttH = 0.2118;
float XS_tHq = 0.07096; 
float XS_tHW = 0.01561;
float XS_ttW = 0.2043;
float XS_ttZ = 0.2529;
float XS_ttZ_lowmass = 0.0493;
float XS_ttG = 3.697;
float XS_WpWp = 0.03711;
float XS_WZ = 4.42965;
float XS_ZZ = 1.256;
float XS_ZZZ = 0.01398;
float XS_WZZ = 0.05565;
float XS_WWZ = 0.1651;
float XS_WWW = 0.2086;
float XS_ttWW = 0.007834; 
float XS_tZq = 0.0758;
float XS_TTTT = 0.008213; 
float XS_ttbar_DL = 88.29;
float XS_ttbar_SL = 365.34;


vector<float> XS;

TString antiEle_WP = "1";
//TString antiEle_WP = "recotauh_againstElectronVLooseMVA6[0]";
//TString antiEle_WP = "recotauh_againstElectronLooseMVA6[0]";
//TString antiEle_WP = "recotauh_againstElectronMediumMVA6[0]";
//TString antiEle_WP = "recotauh_againstElectronTightMVA6[0]";
//TString antiEle_WP = "recotauh_againstElectronVTightMVA6[0]";


//MC

TString filename_ttH = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_BDT_tauSF_fakelep_MEM.root";
TString filename_tHq = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttH/HTauTauTree_THQ_v2_split_BDT_tauSF_fakelep_MEM.root";
TString filename_tHW = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttH/HTauTauTree_THW_v2_split_BDT_tauSF_fakelep_MEM.root";

TString filename_ttW = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttV/HTauTauTree_ttW_split_BDT_tauSF_fakelep_MEM.root";
TString filename_ttZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttV/HTauTauTree_ttZ_split_BDT_tauSF_fakelep_MEM.root";
TString filename_ttZ_lowmass = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttV/HTauTauTree_ttZ_lowmass_split_BDT_tauSF_fakelep_MEM.root";
TString filename_ttG = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/ttV/HTauTauTree_ttG_split_BDT_tauSF_fakelep_MEM.root";

TString filename_WZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/EWK/HTauTauTree_WZ_split_BDT_tauSF_fakelep_MEM.root";
TString filename_ZZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/EWK/HTauTauTree_ZZ_split_BDT_tauSF_fakelep_MEM.root";

TString filename_WWW = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_WWW_split_BDT_tauSF_fakelep_MEM.root";
TString filename_WWZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_WWZ_split_BDT_tauSF_fakelep_MEM.root";
TString filename_WZZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_WZZ_split_BDT_tauSF_fakelep_MEM.root";
TString filename_ZZZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_ZZZ_split_BDT_tauSF_fakelep_MEM.root";
TString filename_tZq = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_tZq_split_BDT_tauSF_fakelep_MEM.root";
TString filename_WpWp = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_WpWp_split_BDT_tauSF_fakelep_PU_MEM.root";
TString filename_TTTT = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_TTTT_split_BDT_tauSF_fakelep_MEM.root";
TString filename_ttWW = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Rares/HTauTauTree_ttWW_split_BDT_tauSF_fakelep_PU_MEM.root";

TString filename_ttbar_DL = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/TT/HTauTauTree_TTLeptons_split_BDT_MEM.root";
TString filename_ttbar_SL = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/TT/HTauTauTree_TTSemileptonic_split_BDT_MEM.root";



// NORMALIZATION FILES
TString filename_norm_ttH = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_PU_ttH_Hnonbb.root";
TString filename_norm_tHq = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_PU_THQ_v2.root";
TString filename_norm_tHW = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_PU_THW_v2.root";

TString filename_norm_ttW = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_PU_ttW.root";
TString filename_norm_ttZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_PU_ttZ.root";
TString filename_norm_ttZ_lowmass = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_PU_ttZ_lowmass.root";
TString filename_norm_ttG = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_PU_ttG.root";

TString filename_norm_WZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/EWK/ntuple_PU_WZ.root";
TString filename_norm_ZZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/EWK/ntuple_PU_ZZ.root";

TString filename_norm_WWW = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_WWW.root";
TString filename_norm_WWZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_WWZ.root";
TString filename_norm_WZZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_WZZ.root";
TString filename_norm_ZZZ = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_ZZZ.root";
TString filename_norm_tZq = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_tZq.root";
TString filename_norm_WpWp = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_WpWp.root";
TString filename_norm_TTTT = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_TTTT.root";
TString filename_norm_ttWW = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_ttWW.root";

TString filename_norm_ttbar_DL = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/TT/ntuple_PU_TTLeptons.root";
TString filename_norm_ttbar_SL = "/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/TT/ntuple_PU_TTSemileptonic.root";

vector<TString> filename_MC;
vector<TString> filename_norm_MC;


//Data

TString filename_SingleMu_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_SingleEle_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleMu_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleEG_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_MuonEG_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM.root";

TString filename_SingleMu_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root"; 
TString filename_SingleEle_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleMu_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleEG_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root"; 
TString filename_MuonEG_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM.root";

TString filename_SingleMu_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_SingleEle_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleMu_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleEG_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_MuonEG_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM.root";

TString filename_SingleMu_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_SingleEle_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleMu_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleEG_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root"; 
TString filename_MuonEG_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM.root";

TString filename_SingleMu_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_SingleEle_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleMu_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_DoubleEG_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root";
TString filename_MuonEG_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM.root";


TString filename_fakeCR_SingleMu_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_SingleEle_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleMu_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleEG_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_MuonEG_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";

TString filename_fakeCR_SingleMu_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root"; 
TString filename_fakeCR_SingleEle_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleMu_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleEG_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root"; 
TString filename_fakeCR_MuonEG_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";

TString filename_fakeCR_SingleMu_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_SingleEle_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleMu_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleEG_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_MuonEG_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";

TString filename_fakeCR_SingleMu_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_SingleEle_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleMu_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleEG_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root"; 
TString filename_fakeCR_MuonEG_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";

TString filename_fakeCR_SingleMu_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_SingleEle_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleMu_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_DoubleEG_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";
TString filename_fakeCR_MuonEG_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_fakeCR.root";


TString filename_flipCR_SingleMu_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_SingleEle_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleMu_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleEG_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_MuonEG_2017B = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017B_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";

TString filename_flipCR_SingleMu_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root"; 
TString filename_flipCR_SingleEle_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleMu_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleEG_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root"; 
TString filename_flipCR_MuonEG_2017C = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017C_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";

TString filename_flipCR_SingleMu_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_SingleEle_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleMu_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleEG_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_MuonEG_2017D = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017D_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";

TString filename_flipCR_SingleMu_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_SingleEle_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleMu_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleEG_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root"; 
TString filename_flipCR_MuonEG_2017E = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017E_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";

TString filename_flipCR_SingleMu_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_SingleEle_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_SingleEle_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleMu_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleMu_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_DoubleEG_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_DoubleEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";
TString filename_flipCR_MuonEG_2017F = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted_MEM/nominal/Data/HTauTauTree_MuonEG_2017F_split_BDT_noDatasetOverlap_fakelep_MEM_flipCR.root";


vector<TString> filename_data;
vector<TString> filename_fakeCR_data;
vector<TString> filename_flipCR_data;

vector<TString> MC_sample_name;
vector<TString> MC_sample_cut;


vector<TString> filename_MC_thu_unc;
vector<TString> MC_sample_name_thu_unc;
vector<TString> MC_sample_cut_thu_unc;



// MC JEC + TES

/*TString filename_ttH_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/ttH/HTauTauTree_ttH_Hnonbb_split_JECup_BDT.root";
TString filename_ttH_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/ttH/HTauTauTree_ttH_Hnonbb_split_JECdown_BDT.root";
TString filename_ttH_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/ttH/HTauTauTree_ttH_Hnonbb_split_TESup_BDT.root";
TString filename_ttH_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/ttH/HTauTauTree_ttH_Hnonbb_split_TESdown_BDT.root";

TString filename_tHq_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/ttH/HTauTauTree_THQ_v2_split_JECup_BDT.root";
TString filename_tHq_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/ttH/HTauTauTree_THQ_v2_split_JECdown_BDT.root";
TString filename_tHq_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/ttH/HTauTauTree_THQ_v2_split_TESup_BDT.root";
TString filename_tHq_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/ttH/HTauTauTree_THQ_v2_split_TESdown_BDT.root";

TString filename_tHW_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/ttH/HTauTauTree_THW_v2_split_JECup_BDT.root";
TString filename_tHW_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/ttH/HTauTauTree_THW_v2_split_JECdown_BDT.root";
TString filename_tHW_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/ttH/HTauTauTree_THW_v2_split_TESup_BDT.root";
TString filename_tHW_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/ttH/HTauTauTree_THW_v2_split_TESdown_BDT.root";

TString filename_ttZ_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/ttV/HTauTauTree_ttZ_split_JECup_BDT.root";
TString filename_ttZ_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/ttV/HTauTauTree_ttZ_split_JECdown_BDT.root";
TString filename_ttZ_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/ttV/HTauTauTree_ttZ_split_TESup_BDT.root";
TString filename_ttZ_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/ttV/HTauTauTree_ttZ_split_TESdown_BDT.root";

TString filename_ttW_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/ttV/HTauTauTree_ttW_split_JECup_BDT.root";
TString filename_ttW_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/ttV/HTauTauTree_ttW_split_JECdown_BDT.root";
TString filename_ttW_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/ttV/HTauTauTree_ttW_split_TESup_BDT.root";
TString filename_ttW_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/ttV/HTauTauTree_ttW_split_TESdown_BDT.root";

TString filename_ttG_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/ttV/HTauTauTree_ttW_split_JECup_BDT.root";
TString filename_ttG_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/ttV/HTauTauTree_ttW_split_JECdown_BDT.root";
TString filename_ttG_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/ttV/HTauTauTree_ttW_split_TESup_BDT.root";
TString filename_ttG_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/ttV/HTauTauTree_ttW_split_TESdown_BDT.root";

TString filename_WZ_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/EWK/HTauTauTree_WZ_split_JECup_BDT.root";
TString filename_WZ_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/EWK/HTauTauTree_WZ_split_JECdown_BDT.root";
TString filename_WZ_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/EWK/HTauTauTree_WZ_split_TESup_BDT.root";
TString filename_WZ_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/EWK/HTauTauTree_WZ_split_TESdown_BDT.root";

TString filename_ZZ_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/EWK/HTauTauTree_ZZ_split_JECup_BDT.root";
TString filename_ZZ_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/EWK/HTauTauTree_ZZ_split_JECdown_BDT.root";
TString filename_ZZ_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/EWK/HTauTauTree_ZZ_split_TESup_BDT.root";
TString filename_ZZ_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/EWK/HTauTauTree_ZZ_split_TESdown_BDT.root";

TString filename_WWW_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/Rares/HTauTauTree_WWW_split_JECup_BDT.root";
TString filename_WWW_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/Rares/HTauTauTree_WWW_split_JECdown_BDT.root";
TString filename_WWW_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/Rares/HTauTauTree_WWW_split_TESup_BDT.root";
TString filename_WWW_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/Rares/HTauTauTree_WWW_split_TESdown_BDT.root";

TString filename_WWZ_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/Rares/HTauTauTree_WWZ_split_JECup_BDT.root";
TString filename_WWZ_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/Rares/HTauTauTree_WWZ_split_JECdown_BDT.root";
TString filename_WWZ_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/Rares/HTauTauTree_WWZ_split_TESup_BDT.root";
TString filename_WWZ_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/Rares/HTauTauTree_WWZ_split_TESdown_BDT.root";

TString filename_WZZ_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/Rares/HTauTauTree_WZZ_split_JECup_BDT.root";
TString filename_WZZ_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/Rares/HTauTauTree_WZZ_split_JECdown_BDT.root";
TString filename_WZZ_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/Rares/HTauTauTree_WZZ_split_TESup_BDT.root";
TString filename_WZZ_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/Rares/HTauTauTree_WZZ_split_TESdown_BDT.root";

TString filename_ZZZ_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/Rares/HTauTauTree_ZZZ_split_JECup_BDT.root";
TString filename_ZZZ_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/Rares/HTauTauTree_ZZZ_split_JECdown_BDT.root";
TString filename_ZZZ_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/Rares/HTauTauTree_ZZZ_split_TESup_BDT.root";
TString filename_ZZZ_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/Rares/HTauTauTree_ZZZ_split_TESdown_BDT.root";

TString filename_tZq_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/Rares/HTauTauTree_tZq_split_JECup_BDT.root";
TString filename_tZq_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/Rares/HTauTauTree_tZq_split_JECdown_BDT.root";
TString filename_tZq_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/Rares/HTauTauTree_tZq_split_TESup_BDT.root";
TString filename_tZq_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/Rares/HTauTauTree_tZq_split_TESdown_BDT.root";

TString filename_WpWp_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/Rares/HTauTauTree_WpWp_split_JECup_BDT_PU.root";
TString filename_WpWp_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/Rares/HTauTauTree_WpWp_split_JECdown_BDT_PU.root";
TString filename_WpWp_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/Rares/HTauTauTree_WpWp_split_TESup_BDT_PU.root";
TString filename_WpWp_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/Rares/HTauTauTree_WpWp_split_TESdown_BDT_PU.root";

TString filename_TTTT_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/Rares/HTauTauTree_TTTT_split_JECup_BDT.root";
TString filename_TTTT_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/Rares/HTauTauTree_TTTT_split_JECdown_BDT.root";
TString filename_TTTT_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/Rares/HTauTauTree_TTTT_split_TESup_BDT.root";
TString filename_TTTT_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/Rares/HTauTauTree_TTTT_split_TESdown_BDT.root";

TString filename_ttWW_JECup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECup/Rares/HTauTauTree_ttWW_split_JECup_BDT_PU.root";
TString filename_ttWW_JECdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/JECdown/Rares/HTauTauTree_ttWW_split_JECdown_BDT_PU.root";
TString filename_ttWW_TESup = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESup/Rares/HTauTauTree_ttWW_split_TESup_BDT_PU.root";
TString filename_ttWW_TESdown = "/data_CMS/cms/mperez/ttH_2017/ntuples_MEM/TESdown/Rares/HTauTauTree_ttWW_split_TESdown_BDT_PU.root";


vector<TString> filename_MC_JECup;
vector<TString> filename_MC_JECdown;
vector<TString> filename_MC_TESup;
vector<TString> filename_MC_TESdown;*/

// Systematics
vector<TString> bTag_syst_names;
vector<TString> jetToTau_FR_syst_names;
vector<TString> fake_syst_names;

void initialize(){

  XS.clear();
  filename_MC.clear();
  filename_norm_MC.clear();
  MC_sample_name.clear();
  MC_sample_cut.clear();
  filename_data.clear();
  filename_fakeCR_data.clear();
  filename_flipCR_data.clear();

  /*filename_MC_JECup.clear();
  filename_MC_JECdown.clear();
  filename_MC_TESup.clear();
  filename_MC_TESdown.clear();*/

  /*filename_MC_thu_unc.clear();
  MC_sample_name_thu_unc.clear();
  MC_sample_cut_thu_unc.clear();
  bTag_syst_names.clear();
  jetToTau_FR_syst_names.clear();
  fake_syst_names.clear();*/

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_gentau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_faketau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_htt");
  MC_sample_cut.push_back("genH_decayMode[1]<=5 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_htt_gentau");
  MC_sample_cut.push_back("genH_decayMode[1]<=5 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_htt_faketau");
  MC_sample_cut.push_back("genH_decayMode[1]<=5 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_hww");
  MC_sample_cut.push_back("genH_decayMode[1]>5 && n_genW==4 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_hww_gentau");
  MC_sample_cut.push_back("genH_decayMode[1]>5 && n_genW==4 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_hww_faketau");
  MC_sample_cut.push_back("genH_decayMode[1]>5 && n_genW==4 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_hzz");
  MC_sample_cut.push_back("genH_decayMode[1]>5 && n_genZ==2 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_hzz_gentau");
  MC_sample_cut.push_back("genH_decayMode[1]>5 && n_genZ==2 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_ttH);
  filename_MC.push_back(filename_ttH);
  filename_norm_MC.push_back(filename_norm_ttH);
  MC_sample_name.push_back("ttH_hzz_faketau");
  MC_sample_cut.push_back("genH_decayMode[1]>5 && n_genZ==2 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttH_JECup);
  //filename_MC_JECdown.push_back(filename_ttH_JECdown);
  //filename_MC_TESup.push_back(filename_ttH_TESup);
  //filename_MC_TESdown.push_back(filename_ttH_TESdown);

  XS.push_back(XS_tHq);
  filename_MC.push_back(filename_tHq);
  filename_norm_MC.push_back(filename_norm_tHq);
  MC_sample_name.push_back("tHq");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tHq_JECup);
  //filename_MC_JECdown.push_back(filename_tHq_JECdown);
  //filename_MC_TESup.push_back(filename_tHq_TESup);
  //filename_MC_TESdown.push_back(filename_tHq_TESdown);

  XS.push_back(XS_tHq);
  filename_MC.push_back(filename_tHq);
  filename_norm_MC.push_back(filename_norm_tHq);
  MC_sample_name.push_back("tHq_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tHq_JECup);
  //filename_MC_JECdown.push_back(filename_tHq_JECdown);
  //filename_MC_TESup.push_back(filename_tHq_TESup);
  //filename_MC_TESdown.push_back(filename_tHq_TESdown);

  XS.push_back(XS_tHq);
  filename_MC.push_back(filename_tHq);
  filename_norm_MC.push_back(filename_norm_tHq);
  MC_sample_name.push_back("tHq_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tHq_JECup);
  //filename_MC_JECdown.push_back(filename_tHq_JECdown);
  //filename_MC_TESup.push_back(filename_tHq_TESup);
  //filename_MC_TESdown.push_back(filename_tHq_TESdown);

  XS.push_back(XS_tHW);
  filename_MC.push_back(filename_tHW);
  filename_norm_MC.push_back(filename_norm_tHW);
  MC_sample_name.push_back("tHW");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tHW_JECup);
  //filename_MC_JECdown.push_back(filename_tHW_JECdown);
  //filename_MC_TESup.push_back(filename_tHW_TESup);
  //filename_MC_TESdown.push_back(filename_tHW_TESdown);

  XS.push_back(XS_tHW);
  filename_MC.push_back(filename_tHW);
  filename_norm_MC.push_back(filename_norm_tHW);
  MC_sample_name.push_back("tHW_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tHW_JECup);
  //filename_MC_JECdown.push_back(filename_tHW_JECdown);
  //filename_MC_TESup.push_back(filename_tHW_TESup);
  //filename_MC_TESdown.push_back(filename_tHW_TESdown);

  XS.push_back(XS_tHW);
  filename_MC.push_back(filename_tHW);
  filename_norm_MC.push_back(filename_norm_tHW);
  MC_sample_name.push_back("tHW_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tHW_JECup);
  //filename_MC_JECdown.push_back(filename_tHW_JECdown);
  //filename_MC_TESup.push_back(filename_tHW_TESup);
  //filename_MC_TESdown.push_back(filename_tHW_TESdown);

  XS.push_back(XS_ttW);
  filename_MC.push_back(filename_ttW);
  filename_norm_MC.push_back(filename_norm_ttW);
  MC_sample_name.push_back("ttW");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttW_JECup);
  //filename_MC_JECdown.push_back(filename_ttW_JECdown);
  //filename_MC_TESup.push_back(filename_ttW_TESup);
  //filename_MC_TESdown.push_back(filename_ttW_TESdown);

  XS.push_back(XS_ttW);
  filename_MC.push_back(filename_ttW);
  filename_norm_MC.push_back(filename_norm_ttW);
  MC_sample_name.push_back("ttW_gentau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttW_JECup);
  //filename_MC_JECdown.push_back(filename_ttW_JECdown);
  //filename_MC_TESup.push_back(filename_ttW_TESup);
  //filename_MC_TESdown.push_back(filename_ttW_TESdown);

  XS.push_back(XS_ttW);
  filename_MC.push_back(filename_ttW);
  filename_norm_MC.push_back(filename_norm_ttW);
  MC_sample_name.push_back("ttW_faketau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttW_JECup);
  //filename_MC_JECdown.push_back(filename_ttW_JECdown);
  //filename_MC_TESup.push_back(filename_ttW_TESup);
  //filename_MC_TESdown.push_back(filename_ttW_TESdown);

  XS.push_back(XS_ttZ);
  filename_MC.push_back(filename_ttZ);
  filename_norm_MC.push_back(filename_norm_ttZ);
  MC_sample_name.push_back("ttZ");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttZ_JECup);
  //filename_MC_JECdown.push_back(filename_ttZ_JECdown);
  //filename_MC_TESup.push_back(filename_ttZ_TESup);
  //filename_MC_TESdown.push_back(filename_ttZ_TESdown);

  XS.push_back(XS_ttZ);
  filename_MC.push_back(filename_ttZ);
  filename_norm_MC.push_back(filename_norm_ttZ);
  MC_sample_name.push_back("ttZ_gentau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttZ_JECup);
  //filename_MC_JECdown.push_back(filename_ttZ_JECdown);
  //filename_MC_TESup.push_back(filename_ttZ_TESup);
  //filename_MC_TESdown.push_back(filename_ttZ_TESdown);

  XS.push_back(XS_ttZ);
  filename_MC.push_back(filename_ttZ);
  filename_norm_MC.push_back(filename_norm_ttZ);
  MC_sample_name.push_back("ttZ_faketau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttZ_JECup);
  //filename_MC_JECdown.push_back(filename_ttZ_JECdown);
  //filename_MC_TESup.push_back(filename_ttZ_TESup);
  //filename_MC_TESdown.push_back(filename_ttZ_TESdown);

  XS.push_back(XS_ttG);
  filename_MC.push_back(filename_ttG);
  filename_norm_MC.push_back(filename_norm_ttG);
  MC_sample_name.push_back("Convs");
  MC_sample_cut.push_back("1");
  //filename_MC_JECup.push_back(filename_ttG_JECup);
  //filename_MC_JECdown.push_back(filename_ttG_JECdown);
  //filename_MC_TESup.push_back(filename_ttG_TESup);
  //filename_MC_TESdown.push_back(filename_ttG_TESdown);
  
  XS.push_back(XS_ttG);
  filename_MC.push_back(filename_ttG);
  filename_norm_MC.push_back(filename_norm_ttG);
  MC_sample_name.push_back("Convs_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttG_JECup);
  //filename_MC_JECdown.push_back(filename_ttG_JECdown);
  //filename_MC_TESup.push_back(filename_ttG_TESup);
  //filename_MC_TESdown.push_back(filename_ttG_TESdown);

  XS.push_back(XS_ttG);
  filename_MC.push_back(filename_ttG);
  filename_norm_MC.push_back(filename_norm_ttG);
  MC_sample_name.push_back("Convs_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ttG_JECup);
  //filename_MC_JECdown.push_back(filename_ttG_JECdown);
  //filename_MC_TESup.push_back(filename_ttG_TESup);
  //filename_MC_TESdown.push_back(filename_ttG_TESdown);

  XS.push_back(XS_WZ);
  filename_MC.push_back(filename_WZ);
  filename_norm_MC.push_back(filename_norm_WZ);
  MC_sample_name.push_back("WZ");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WZ_JECup);
  //filename_MC_JECdown.push_back(filename_WZ_JECdown);
  //filename_MC_TESup.push_back(filename_WZ_TESup);
  //filename_MC_TESdown.push_back(filename_WZ_TESdown);

  XS.push_back(XS_WZ);
  filename_MC.push_back(filename_WZ);
  filename_norm_MC.push_back(filename_norm_WZ);
  MC_sample_name.push_back("WZ_gentau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_WZ_JECup);
  //filename_MC_JECdown.push_back(filename_WZ_JECdown);
  //filename_MC_TESup.push_back(filename_WZ_TESup);
  //filename_MC_TESdown.push_back(filename_WZ_TESdown);

  XS.push_back(XS_WZ);
  filename_MC.push_back(filename_WZ);
  filename_norm_MC.push_back(filename_norm_WZ);
  MC_sample_name.push_back("WZ_faketau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_WZ_JECup);
  //filename_MC_JECdown.push_back(filename_WZ_JECdown);
  //filename_MC_TESup.push_back(filename_WZ_TESup);
  //filename_MC_TESdown.push_back(filename_WZ_TESdown);

  XS.push_back(XS_ZZ);
  filename_MC.push_back(filename_ZZ);
  filename_norm_MC.push_back(filename_norm_ZZ);
  MC_sample_name.push_back("ZZ");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ZZ_JECup);
  //filename_MC_JECdown.push_back(filename_ZZ_JECdown);
  //filename_MC_TESup.push_back(filename_ZZ_TESup);
  //filename_MC_TESdown.push_back(filename_ZZ_TESdown);

  XS.push_back(XS_ZZ);
  filename_MC.push_back(filename_ZZ);
  filename_norm_MC.push_back(filename_norm_ZZ);
  MC_sample_name.push_back("ZZ_gentau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ZZ_JECup);
  //filename_MC_JECdown.push_back(filename_ZZ_JECdown);
  //filename_MC_TESup.push_back(filename_ZZ_TESup);
  //filename_MC_TESdown.push_back(filename_ZZ_TESdown);

  XS.push_back(XS_ZZ);
  filename_MC.push_back(filename_ZZ);
  filename_norm_MC.push_back(filename_norm_ZZ);
  MC_sample_name.push_back("ZZ_faketau");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");
  //filename_MC_JECup.push_back(filename_ZZ_JECup);
  //filename_MC_JECdown.push_back(filename_ZZ_JECdown);
  //filename_MC_TESup.push_back(filename_ZZ_TESup);
  //filename_MC_TESdown.push_back(filename_ZZ_TESdown);

  XS.push_back(XS_WWW);
  filename_MC.push_back(filename_WWW);
  filename_norm_MC.push_back(filename_norm_WWW);
  MC_sample_name.push_back("WWW");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WWW_JECup);
  //filename_MC_JECdown.push_back(filename_WWW_JECdown);
  //filename_MC_TESup.push_back(filename_WWW_TESup);
  //filename_MC_TESdown.push_back(filename_WWW_TESdown);

  XS.push_back(XS_WWW);
  filename_MC.push_back(filename_WWW);
  filename_norm_MC.push_back(filename_norm_WWW);
  MC_sample_name.push_back("WWW_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WWW_JECup);
  //filename_MC_JECdown.push_back(filename_WWW_JECdown);
  //filename_MC_TESup.push_back(filename_WWW_TESup);
  //filename_MC_TESdown.push_back(filename_WWW_TESdown);

  XS.push_back(XS_WWW);
  filename_MC.push_back(filename_WWW);
  filename_norm_MC.push_back(filename_norm_WWW);
  MC_sample_name.push_back("WWW_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WWW_JECup);
  //filename_MC_JECdown.push_back(filename_WWW_JECdown);
  //filename_MC_TESup.push_back(filename_WWW_TESup);
  //filename_MC_TESdown.push_back(filename_WWW_TESdown);


  XS.push_back(XS_WWZ);
  filename_MC.push_back(filename_WWZ);
  filename_norm_MC.push_back(filename_norm_WWZ);
  MC_sample_name.push_back("WWZ");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WWZ_JECup);
  //filename_MC_JECdown.push_back(filename_WWZ_JECdown);
  //filename_MC_TESup.push_back(filename_WWZ_TESup);
  //filename_MC_TESdown.push_back(filename_WWZ_TESdown);

  XS.push_back(XS_WWZ);
  filename_MC.push_back(filename_WWZ);
  filename_norm_MC.push_back(filename_norm_WWZ);
  MC_sample_name.push_back("WWZ_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WWZ_JECup);
  //filename_MC_JECdown.push_back(filename_WWZ_JECdown);
  //filename_MC_TESup.push_back(filename_WWZ_TESup);
  //filename_MC_TESdown.push_back(filename_WWZ_TESdown);

  XS.push_back(XS_WWZ);
  filename_MC.push_back(filename_WWZ);
  filename_norm_MC.push_back(filename_norm_WWZ);
  MC_sample_name.push_back("WWZ_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WWZ_JECup);
  //filename_MC_JECdown.push_back(filename_WWZ_JECdown);
  //filename_MC_TESup.push_back(filename_WWZ_TESup);
  //filename_MC_TESdown.push_back(filename_WWZ_TESdown);
  
  
  XS.push_back(XS_WZZ);
  filename_MC.push_back(filename_WZZ);
  filename_norm_MC.push_back(filename_norm_WZZ);
  MC_sample_name.push_back("WZZ");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WZZ_JECup);
  //filename_MC_JECdown.push_back(filename_WZZ_JECdown);
  //filename_MC_TESup.push_back(filename_WZZ_TESup);
  //filename_MC_TESdown.push_back(filename_WZZ_TESdown);

  XS.push_back(XS_WZZ);
  filename_MC.push_back(filename_WZZ);
  filename_norm_MC.push_back(filename_norm_WZZ);
  MC_sample_name.push_back("WZZ_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WZZ_JECup);
  //filename_MC_JECdown.push_back(filename_WZZ_JECdown);
  //filename_MC_TESup.push_back(filename_WZZ_TESup);
  //filename_MC_TESdown.push_back(filename_WZZ_TESdown);

  XS.push_back(XS_WZZ);
  filename_MC.push_back(filename_WZZ);
  filename_norm_MC.push_back(filename_norm_WZZ);
  MC_sample_name.push_back("WZZ_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WZZ_JECup);
  //filename_MC_JECdown.push_back(filename_WZZ_JECdown);
  //filename_MC_TESup.push_back(filename_WZZ_TESup);
  //filename_MC_TESdown.push_back(filename_WZZ_TESdown);


  XS.push_back(XS_ZZZ);
  filename_MC.push_back(filename_ZZZ);
  filename_norm_MC.push_back(filename_norm_ZZZ);
  MC_sample_name.push_back("ZZZ");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ZZZ_JECup);
  //filename_MC_JECdown.push_back(filename_ZZZ_JECdown);
  //filename_MC_TESup.push_back(filename_ZZZ_TESup);
  //filename_MC_TESdown.push_back(filename_ZZZ_TESdown);

  XS.push_back(XS_ZZZ);
  filename_MC.push_back(filename_ZZZ);
  filename_norm_MC.push_back(filename_norm_ZZZ);
  MC_sample_name.push_back("ZZZ_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ZZZ_JECup);
  //filename_MC_JECdown.push_back(filename_ZZZ_JECdown);
  //filename_MC_TESup.push_back(filename_ZZZ_TESup);
  //filename_MC_TESdown.push_back(filename_ZZZ_TESdown);

  XS.push_back(XS_ZZZ);
  filename_MC.push_back(filename_ZZZ);
  filename_norm_MC.push_back(filename_norm_ZZZ);
  MC_sample_name.push_back("ZZZ_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ZZZ_JECup);
  //filename_MC_JECdown.push_back(filename_ZZZ_JECdown);
  //filename_MC_TESup.push_back(filename_ZZZ_TESup);
  //filename_MC_TESdown.push_back(filename_ZZZ_TESdown);

  XS.push_back(XS_WpWp);
  filename_MC.push_back(filename_WpWp);
  filename_norm_MC.push_back(filename_norm_WpWp);
  MC_sample_name.push_back("WWss");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WpWp_JECup);
  //filename_MC_JECdown.push_back(filename_WpWp_JECdown);
  //filename_MC_TESup.push_back(filename_WpWp_TESup);
  //filename_MC_TESdown.push_back(filename_WpWp_TESdown);

  XS.push_back(XS_WpWp);
  filename_MC.push_back(filename_WpWp);
  filename_norm_MC.push_back(filename_norm_WpWp);
  MC_sample_name.push_back("WWss_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WpWp_JECup);
  //filename_MC_JECdown.push_back(filename_WpWp_JECdown);
  //filename_MC_TESup.push_back(filename_WpWp_TESup);
  //filename_MC_TESdown.push_back(filename_WpWp_TESdown);

  XS.push_back(XS_WpWp);
  filename_MC.push_back(filename_WpWp);
  filename_norm_MC.push_back(filename_norm_WpWp);
  MC_sample_name.push_back("WWss_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_WpWp_JECup);
  //filename_MC_JECdown.push_back(filename_WpWp_JECdown);
  //filename_MC_TESup.push_back(filename_WpWp_TESup);
  //filename_MC_TESdown.push_back(filename_WpWp_TESdown);

  XS.push_back(XS_tZq);
  filename_MC.push_back(filename_tZq);
  filename_norm_MC.push_back(filename_norm_tZq);
  MC_sample_name.push_back("tZq");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tZq_JECup);
  //filename_MC_JECdown.push_back(filename_tZq_JECdown);
  //filename_MC_TESup.push_back(filename_tZq_TESup);
  //filename_MC_TESdown.push_back(filename_tZq_TESdown);

  XS.push_back(XS_tZq);
  filename_MC.push_back(filename_tZq);
  filename_norm_MC.push_back(filename_norm_tZq);
  MC_sample_name.push_back("tZq_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tZq_JECup);
  //filename_MC_JECdown.push_back(filename_tZq_JECdown);
  //filename_MC_TESup.push_back(filename_tZq_TESup);
  //filename_MC_TESdown.push_back(filename_tZq_TESdown);

  XS.push_back(XS_tZq);
  filename_MC.push_back(filename_tZq);
  filename_norm_MC.push_back(filename_norm_tZq);
  MC_sample_name.push_back("tZq_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_tZq_JECup);
  //filename_MC_JECdown.push_back(filename_tZq_JECdown);
  //filename_MC_TESup.push_back(filename_tZq_TESup);
  //filename_MC_TESdown.push_back(filename_tZq_TESdown);

  XS.push_back(XS_TTTT);
  filename_MC.push_back(filename_TTTT);
  filename_norm_MC.push_back(filename_norm_TTTT);
  MC_sample_name.push_back("TTTT");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_TTTT_JECup);
  //filename_MC_JECdown.push_back(filename_TTTT_JECdown);
  //filename_MC_TESup.push_back(filename_TTTT_TESup);
  //filename_MC_TESdown.push_back(filename_TTTT_TESdown);

  XS.push_back(XS_TTTT);
  filename_MC.push_back(filename_TTTT);
  filename_norm_MC.push_back(filename_norm_TTTT);
  MC_sample_name.push_back("TTTT_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_TTTT_JECup);
  //filename_MC_JECdown.push_back(filename_TTTT_JECdown);
  //filename_MC_TESup.push_back(filename_TTTT_TESup);
  //filename_MC_TESdown.push_back(filename_TTTT_TESdown);

  XS.push_back(XS_TTTT);
  filename_MC.push_back(filename_TTTT);
  filename_norm_MC.push_back(filename_norm_TTTT);
  MC_sample_name.push_back("TTTT_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_TTTT_JECup);
  //filename_MC_JECdown.push_back(filename_TTTT_JECdown);
  //filename_MC_TESup.push_back(filename_TTTT_TESup);
  //filename_MC_TESdown.push_back(filename_TTTT_TESdown);

  XS.push_back(XS_ttWW);
  filename_MC.push_back(filename_ttWW);
  filename_norm_MC.push_back(filename_norm_ttWW);
  MC_sample_name.push_back("ttWW");
  MC_sample_cut.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttWW_JECup);
  //filename_MC_JECdown.push_back(filename_ttWW_JECdown);
  //filename_MC_TESup.push_back(filename_ttWW_TESup);
  //filename_MC_TESdown.push_back(filename_ttWW_TESdown);

  XS.push_back(XS_ttWW);
  filename_MC.push_back(filename_ttWW);
  filename_norm_MC.push_back(filename_norm_ttWW);
  MC_sample_name.push_back("ttWW_gentau");
  MC_sample_cut.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttWW_JECup);
  //filename_MC_JECdown.push_back(filename_ttWW_JECdown);
  //filename_MC_TESup.push_back(filename_ttWW_TESup);
  //filename_MC_TESdown.push_back(filename_ttWW_TESdown);

  XS.push_back(XS_ttWW);
  filename_MC.push_back(filename_ttWW);
  filename_norm_MC.push_back(filename_norm_ttWW);
  MC_sample_name.push_back("ttWW_faketau");
  MC_sample_cut.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  //filename_MC_JECup.push_back(filename_ttWW_JECup);
  //filename_MC_JECdown.push_back(filename_ttWW_JECdown);
  //filename_MC_TESup.push_back(filename_ttWW_TESup);
  //filename_MC_TESdown.push_back(filename_ttWW_TESdown);
 
  /*XS.push_back(XS_ttbar_DL);
  filename_MC.push_back(filename_ttbar_DL);
  filename_norm_MC.push_back(filename_norm_ttbar_DL);
  MC_sample_name.push_back("ttbar_DL");
  MC_sample_cut.push_back("1");

  XS.push_back(XS_ttbar_SL);
  filename_MC.push_back(filename_ttbar_SL);
  filename_norm_MC.push_back(filename_norm_ttbar_SL);
  MC_sample_name.push_back("ttbar_SL");
  MC_sample_cut.push_back("1"); */

  
  filename_data.push_back(filename_DoubleEG_2017B);
  filename_data.push_back(filename_MuonEG_2017B);
  filename_data.push_back(filename_DoubleMu_2017B);
  filename_data.push_back(filename_SingleMu_2017B);
  filename_data.push_back(filename_SingleEle_2017B);

  filename_data.push_back(filename_DoubleEG_2017C);
  filename_data.push_back(filename_MuonEG_2017C);
  filename_data.push_back(filename_DoubleMu_2017C);
  filename_data.push_back(filename_SingleMu_2017C);
  filename_data.push_back(filename_SingleEle_2017C);

  filename_data.push_back(filename_DoubleEG_2017D);
  filename_data.push_back(filename_MuonEG_2017D);
  filename_data.push_back(filename_DoubleMu_2017D);
  filename_data.push_back(filename_SingleMu_2017D);
  filename_data.push_back(filename_SingleEle_2017D);

  filename_data.push_back(filename_DoubleEG_2017E);
  filename_data.push_back(filename_MuonEG_2017E);
  filename_data.push_back(filename_DoubleMu_2017E);
  filename_data.push_back(filename_SingleMu_2017E);
  filename_data.push_back(filename_SingleEle_2017E);

  filename_data.push_back(filename_DoubleEG_2017F);
  filename_data.push_back(filename_MuonEG_2017F);
  filename_data.push_back(filename_DoubleMu_2017F);
  filename_data.push_back(filename_SingleMu_2017F);
  filename_data.push_back(filename_SingleEle_2017F);


  filename_fakeCR_data.push_back(filename_fakeCR_DoubleEG_2017B);
  filename_fakeCR_data.push_back(filename_fakeCR_MuonEG_2017B);
  filename_fakeCR_data.push_back(filename_fakeCR_DoubleMu_2017B);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleMu_2017B);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleEle_2017B);

  filename_fakeCR_data.push_back(filename_fakeCR_DoubleEG_2017C);
  filename_fakeCR_data.push_back(filename_fakeCR_MuonEG_2017C);
  filename_fakeCR_data.push_back(filename_fakeCR_DoubleMu_2017C);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleMu_2017C);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleEle_2017C);

  filename_fakeCR_data.push_back(filename_fakeCR_DoubleEG_2017D);
  filename_fakeCR_data.push_back(filename_fakeCR_MuonEG_2017D);
  filename_fakeCR_data.push_back(filename_fakeCR_DoubleMu_2017D);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleMu_2017D);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleEle_2017D);

  filename_fakeCR_data.push_back(filename_fakeCR_DoubleEG_2017E);
  filename_fakeCR_data.push_back(filename_fakeCR_MuonEG_2017E);
  filename_fakeCR_data.push_back(filename_fakeCR_DoubleMu_2017E);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleMu_2017E);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleEle_2017E);

  filename_fakeCR_data.push_back(filename_fakeCR_DoubleEG_2017F);
  filename_fakeCR_data.push_back(filename_fakeCR_MuonEG_2017F);
  filename_fakeCR_data.push_back(filename_fakeCR_DoubleMu_2017F);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleMu_2017F);
  filename_fakeCR_data.push_back(filename_fakeCR_SingleEle_2017F);


  filename_flipCR_data.push_back(filename_flipCR_DoubleEG_2017B);
  filename_flipCR_data.push_back(filename_flipCR_MuonEG_2017B);
  filename_flipCR_data.push_back(filename_flipCR_DoubleMu_2017B);
  filename_flipCR_data.push_back(filename_flipCR_SingleMu_2017B);
  filename_flipCR_data.push_back(filename_flipCR_SingleEle_2017B);

  filename_flipCR_data.push_back(filename_flipCR_DoubleEG_2017C);
  filename_flipCR_data.push_back(filename_flipCR_MuonEG_2017C);
  filename_flipCR_data.push_back(filename_flipCR_DoubleMu_2017C);
  filename_flipCR_data.push_back(filename_flipCR_SingleMu_2017C);
  filename_flipCR_data.push_back(filename_flipCR_SingleEle_2017C);

  filename_flipCR_data.push_back(filename_flipCR_DoubleEG_2017D);
  filename_flipCR_data.push_back(filename_flipCR_MuonEG_2017D);
  filename_flipCR_data.push_back(filename_flipCR_DoubleMu_2017D);
  filename_flipCR_data.push_back(filename_flipCR_SingleMu_2017D);
  filename_flipCR_data.push_back(filename_flipCR_SingleEle_2017D);

  filename_flipCR_data.push_back(filename_flipCR_DoubleEG_2017E);
  filename_flipCR_data.push_back(filename_flipCR_MuonEG_2017E);
  filename_flipCR_data.push_back(filename_flipCR_DoubleMu_2017E);
  filename_flipCR_data.push_back(filename_flipCR_SingleMu_2017E);
  filename_flipCR_data.push_back(filename_flipCR_SingleEle_2017E);

  filename_flipCR_data.push_back(filename_flipCR_DoubleEG_2017F);
  filename_flipCR_data.push_back(filename_flipCR_MuonEG_2017F);
  filename_flipCR_data.push_back(filename_flipCR_DoubleMu_2017F);
  filename_flipCR_data.push_back(filename_flipCR_SingleMu_2017F);
  filename_flipCR_data.push_back(filename_flipCR_SingleEle_2017F);
  
 
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH");
  MC_sample_cut_thu_unc.push_back("!(n_genW==2 && n_genZ<2 && genH_decayMode[1]>5) && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_gentau");
  MC_sample_cut_thu_unc.push_back("!(n_genW==2 && n_genZ<2 && genH_decayMode[1]>5) && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && recotauh_sel_isGenMatched[0]");
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_faketau");
  MC_sample_cut_thu_unc.push_back("!(n_genW==2 && n_genZ<2 && genH_decayMode[1]>5) && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1] && !recotauh_sel_isGenMatched[0]");

  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_htt");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]<=5 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_htt_gentau");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]<=5 && recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_htt_faketau");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]<=5 && !recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");

  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_hww");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]>5 && n_genW==4 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_hww_gentau");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]>5 && n_genW==4 && recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_hww_faketau");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]>5 && n_genW==4 && !recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");

  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_hzz");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]>5 && n_genZ==2 && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_hzz_gentau");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]>5 && n_genZ==2 && recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttH);
  MC_sample_name_thu_unc.push_back("ttH_hzz_faketau");
  MC_sample_cut_thu_unc.push_back("genH_decayMode[1]>5 && n_genZ==2 && !recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");

  filename_MC_thu_unc.push_back(filename_ttW);
  MC_sample_name_thu_unc.push_back("ttW");
  MC_sample_cut_thu_unc.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttW);
  MC_sample_name_thu_unc.push_back("ttW_gentau");
  MC_sample_cut_thu_unc.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttW);
  MC_sample_name_thu_unc.push_back("ttW_faketau");
  MC_sample_cut_thu_unc.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");

  filename_MC_thu_unc.push_back(filename_ttZ);
  MC_sample_name_thu_unc.push_back("ttZ");
  MC_sample_cut_thu_unc.push_back("recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttZ);
  MC_sample_name_thu_unc.push_back("ttZ_gentau");
  MC_sample_cut_thu_unc.push_back("recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
  filename_MC_thu_unc.push_back(filename_ttZ);
  MC_sample_name_thu_unc.push_back("ttZ_faketau");
  MC_sample_cut_thu_unc.push_back("!recotauh_sel_isGenMatched[0] && recolep_sel_isGenMatched[0] && recolep_sel_isGenMatched[1]");
 
 
  bTag_syst_names.push_back("JESUp");
  bTag_syst_names.push_back("JESDown");
  bTag_syst_names.push_back("LFUp");
  bTag_syst_names.push_back("LFDown");
  bTag_syst_names.push_back("HFUp");
  bTag_syst_names.push_back("HFDown");
  bTag_syst_names.push_back("HFStats1Up");
  bTag_syst_names.push_back("HFStats1Down");
  bTag_syst_names.push_back("HFStats2Up");
  bTag_syst_names.push_back("HFStats2Down");
  bTag_syst_names.push_back("LFStats1Up");
  bTag_syst_names.push_back("LFStats1Down");
  bTag_syst_names.push_back("LFStats2Up");
  bTag_syst_names.push_back("LFStats2Down");
  bTag_syst_names.push_back("CFErr1Up");
  bTag_syst_names.push_back("CFErr1Down");
  bTag_syst_names.push_back("CFErr2Up");
  bTag_syst_names.push_back("CFErr2Down");

  /*jetToTau_FR_syst_names.push_back("tauNormUp");
  jetToTau_FR_syst_names.push_back("tauNormDown");
  jetToTau_FR_syst_names.push_back("tauShapeUp");
  jetToTau_FR_syst_names.push_back("tauShapeDown");

  fake_syst_names.push_back("ele_up");
  fake_syst_names.push_back("ele_down");
  fake_syst_names.push_back("ele_pt1");
  fake_syst_names.push_back("ele_pt2");
  fake_syst_names.push_back("ele_be1");
  fake_syst_names.push_back("ele_be2");

  fake_syst_names.push_back("mu_up");
  fake_syst_names.push_back("mu_down");
  fake_syst_names.push_back("mu_pt1");
  fake_syst_names.push_back("mu_pt2");
  fake_syst_names.push_back("mu_be1");
  fake_syst_names.push_back("mu_be2");*/

  
}







void datacard_maker(TString var1, int nbin, float xmin, float xmax,
		    TString cut_cat1, TString file, bool syst=false){


 TString var = var1 + "*(" + var1 + Form("<=%f) + %f*(",xmax,0.999*xmax) + var1 + Form(">%f)",xmax);
  cout<<var<<endl;

  TString cut_cat = antiEle_WP+" && " + cut_cat1;

  initialize();


  
  vector<TString> cat_names;
  cat_names.push_back("ttH_2lss_1tau");


  vector<int> cat;
  cat.push_back(11);

  vector<int> cat_fakes;
  vector<int> cat_flips;
  for(unsigned int i=0;i<cat.size();i++){
    cat_flips.push_back(-1*cat[i]);
    cat_fakes.push_back(30+cat[i]);
  }
  
  TFile* f_new = TFile::Open(file,"RECREATE");
  


  for(unsigned int i_cat=0;i_cat<cat_names.size();i_cat++){

    cout<<cat_names[i_cat]<<endl;

    f_new->cd();
    //TDirectory* dir = f_new->mkdir(cat_names[i_cat]);
    //dir->cd();

    // NORMALIZATION FILES 

    vector<float> norm_MC;
    for(unsigned i_MC=0;i_MC<MC_sample_name.size();i_MC++){

      TString MC_weight = "MC_weight";
      if(MC_sample_name[i_MC].Contains("tHq"))
		MC_weight += "_tHq";
	  if(MC_sample_name[i_MC].Contains("tHW"))
		MC_weight += "_tHW";

      TH1F* h_MC_norm = single_plot(filename_norm_MC[i_MC],
                                    "HTauTauTree",
                                    "1",
                                    MC_weight + "*PU_weight_ICHEP18",
                                    3,0,3);

      norm_MC.push_back(h_MC_norm->Integral());

	}


    //////////////////////////////////////////
    //////////////////////////////////////////
    /////////          NOMINAL        ////////
    //////////////////////////////////////////
    //////////////////////////////////////////

	// NOMINAL
    for(unsigned i_MC=0;i_MC<MC_sample_name.size();i_MC++){

      TString MC_weight = "MC_weight";
      if(MC_sample_name[i_MC].Contains("tHq"))
		MC_weight += "_tHq";
	  if(MC_sample_name[i_MC].Contains("tHW"))
		MC_weight += "_tHW";

      TH1F* h_MC = single_plot(filename_MC[i_MC],
			"T",
			var,
			MC_weight+"*PU_weight_ICHEP18*triggerSF_weight*leptonSF_ttH_weight*bTagSF_CSVshape_weight*tauSF_weight*(" + MC_sample_cut[i_MC] + " && " + cut_cat + ")",
            nbin,xmin,xmax);
      
      h_MC->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);
      h_MC->SetNameTitle("x_"+MC_sample_name[i_MC],"x_"+MC_sample_name[i_MC]);
      makeBinContentsPositive(h_MC,true);
      h_MC->Write();

    }


    //TAU BACKGROUND TYPES

    vector<TString> bkg_type;
    bkg_type.push_back("");
    bkg_type.push_back("_gentau");
    bkg_type.push_back("_faketau");


    for(unsigned int i=0;i<bkg_type.size();i++){

      TH1F* h_TTH = (TH1F*)f_new->Get("x_ttH"+bkg_type[i]);
      h_TTH->Add( (TH1F*)f_new->Get("x_tHq"+bkg_type[i]) );
      h_TTH->Add( (TH1F*)f_new->Get("x_tHW"+bkg_type[i]) );
      h_TTH->SetNameTitle("x_TTH"+bkg_type[i],"x_TTH"+bkg_type[i]);
      h_TTH->Write();
      
      TH1F* h_TTZ = (TH1F*)f_new->Get("x_ttW"+bkg_type[i]);
      h_TTZ->Add( (TH1F*)f_new->Get("x_ttZ"+bkg_type[i]) );
      h_TTZ->Add( (TH1F*)f_new->Get("x_Convs"+bkg_type[i]) );
      h_TTZ->SetNameTitle("x_TTW"+bkg_type[i],"x_TTW"+bkg_type[i]);
      h_TTZ->Write();

      TH1F* h_EWK = (TH1F*)f_new->Get("x_WZ"+bkg_type[i]);
      h_EWK->Add( (TH1F*)f_new->Get("x_ZZ"+bkg_type[i]) );
      h_EWK->SetNameTitle("x_EWK"+bkg_type[i],"x_EWK"+bkg_type[i]);
      h_EWK->Write();

      TH1F* h_Rares = (TH1F*)f_new->Get("x_WWW"+bkg_type[i]);
      h_Rares->Add( (TH1F*)f_new->Get("x_WWZ"+bkg_type[i]) );
      h_Rares->Add( (TH1F*)f_new->Get("x_WZZ"+bkg_type[i]) );
      h_Rares->Add( (TH1F*)f_new->Get("x_ZZZ"+bkg_type[i]) );
      h_Rares->Add( (TH1F*)f_new->Get("x_WWss"+bkg_type[i]) );
      h_Rares->Add( (TH1F*)f_new->Get("x_tZq"+bkg_type[i]) );
      h_Rares->Add( (TH1F*)f_new->Get("x_TTTT"+bkg_type[i]) );
      h_Rares->Add( (TH1F*)f_new->Get("x_ttWW"+bkg_type[i]) );
      h_Rares->SetNameTitle("x_Rares"+bkg_type[i],"x_Rares"+bkg_type[i]);
      h_Rares->Write();

    }

 
    //FAKES FROM DATA

    TH1F* h_fakes =single_plot(filename_fakeCR_data,
			"T",
			var,
			"event_weight_ttH*(" + cut_cat + ")",
			nbin,xmin,xmax);
    
    h_fakes->Scale(luminosity/41298.); 
    h_fakes->SetNameTitle("x_fakes_data","x_fakes_data");
    makeBinContentsPositive(h_fakes,true);
    h_fakes->Write();
    


    //FAKES FROM MC

    /*TH1F* h_ttbar_DL_fakes_MC =single_plot(filename_ttbar_DL,
			"HTauTauTree_2lSS_1tau_fake",
			var,
			MC_weight+"*PU_weight_ICHEP18*triggerSF_weight*bTagSF_CSVshape_weight*event_weight_ttH*leptonSF_ttH_weight*tauSF_weight*(" + cut_cat + ")",
			nbin,xmin,xmax);
    
    TH1F* h_ttbar_DL_norm =single_plot(filename_norm_ttbar_DL,
			"HTauTauTree",
			"1",
			MC_weight+"*PU_weight_ICHEP18",
			3,0,3);
 
    h_ttbar_DL_fakes_MC->Scale(luminosity*XS_ttbar_DL/h_ttbar_DL_norm->Integral());

    TH1F* h_ttbar_SL_fakes_MC =single_plot(filename_ttbar_SL,
            "HTauTauTree_2lSS_1tau_fake",
            var,
            MC_weight+"*PU_weight_ICHEP18*triggerSF_weight*bTagSF_CSVshape_weight*event_weight_ttH*leptonSF_ttH_weight*tauSF_weight*(" + cut_cat + ")",
            nbin,xmin,xmax);

    TH1F* h_ttbar_SL_norm =single_plot(filename_norm_ttbar_SL,
            "HTauTauTree",
            "1",
            MC_weight+"*PU_weight_ICHEP18",
            3,0,3);

    h_ttbar_SL_fakes_MC->Scale(luminosity*XS_ttbar_SL/h_ttbar_SL_norm->Integral());


    TH1F* h_fakes_MC = (TH1F*)h_ttbar_DL_fakes_MC->Clone();
    h_fakes_MC->Add(h_ttbar_SL_fakes_MC,+1);
    h_fakes_MC->SetNameTitle("x_fakes_MC","x_fakes_MC");
    h_fakes_MC->Write();*/
    

    //FLIPS FROM DATA

    TH1F* h_flips =single_plot(filename_flipCR_data,
			"T",
			var,
			"event_weight_ttH*(" + cut_cat + ")",
			nbin,xmin,xmax);
    
    h_flips->Scale(luminosity/41298.); 
    h_flips->SetNameTitle("x_flips_data","x_flips_data");
    makeBinContentsPositive(h_flips,true);
    h_flips->Write();
    

    //DATA

    TH1F* h_data_obs =single_plot(filename_data,
		    "T",
		    var,
            Form("(category==%i && ",cat[i_cat]) + cut_cat + ")", 
            nbin,xmin,xmax);
      
    h_data_obs->Scale(luminosity/41298.); //Data files for 36.8 fb-1
      
    h_data_obs->SetNameTitle("x_data_obs","x_data_obs");
    makeBinContentsPositive(h_data_obs,true);
    h_data_obs->Write();
   


    if(!syst){
      f_new->Close();
      return;
    }

    cout<<"OK nominal"<<endl;


    //////////////////////////////////////////
    //////////////////////////////////////////
    /////////       SYSTEMATICS       ////////
    //////////////////////////////////////////
    //////////////////////////////////////////


    //////////////////////////////
    //////SYSTEMATICS B-TAG///////
    //////////////////////////////
    
    //OK!
    for(unsigned i_MC=0;i_MC<MC_sample_name.size();i_MC++){

      for(unsigned int i_b=0;i_b<bTag_syst_names.size();i_b++){ 

        TString MC_weight = "MC_weight";
        if(MC_sample_name[i_MC].Contains("tHq"))
		  MC_weight += "_tHq";
	    if(MC_sample_name[i_MC].Contains("tHW"))
		  MC_weight += "_tHW";
	      	     	    
	    TString cut = MC_weight+"*PU_weight_ICHEP18*triggerSF_weight*leptonSF_ttH_weight*tauSF_weight*bTagSF_CSVshape_weight_" + bTag_syst_names[i_b];
	    cut+=Form("*(category==%i &&",cat[i_cat]) + MC_sample_cut[i_MC] + " && " + cut_cat +")";
     
     	TH1F* h_MC_btag_syst = single_plot(filename_MC[i_MC],
     	    	"T",
     	    	var,
     	    	cut,
     	    	nbin,xmin,xmax);
    
        h_MC_btag_syst->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);      
    
    	TString h_name = "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
    	if(bTag_syst_names[i_b].Contains("Stats"))
    	   h_name = "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
    	if(bTag_syst_names[i_b]=="CFErr1Up")
    	   h_name = "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_btag_cErr1Up";
    	else if(bTag_syst_names[i_b]=="CFErr1Down")
    	   h_name = "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_btag_cErr1Down";
    	else if(bTag_syst_names[i_b]=="CFErr2Up")
    	   h_name = "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_btag_cErr2Up";
    	else if(bTag_syst_names[i_b]=="CFErr2Down")
    	   h_name = "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_btag_cErr2Down";	
    
    	h_MC_btag_syst->SetNameTitle(h_name,h_name);
               makeBinContentsPositive(h_MC_btag_syst);
    	h_MC_btag_syst->Write();
    
       }

    }
    

    for(unsigned int i_b=0;i_b<bTag_syst_names.size();i_b++){  

      for(unsigned int i_bkg=0;i_bkg<bkg_type.size();i_bkg++){//+1

	    TString h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";

	    TString h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";

	    TString h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";

	    TH1F* h_TTH = (TH1F*)f_new->Get(h_name_ttH);
	    h_TTH->Add( (TH1F*)f_new->Get(h_name_tHq) );
	    h_TTH->Add( (TH1F*)f_new->Get(h_name_tHW) );
	    h_TTH->SetNameTitle(h_name_TTH,h_name_TTH);
	    h_TTH->Write();

        TString h_name_ttZ = "x_ttZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	      if(bTag_syst_names[i_b]=="CFErr1Up")
	    h_name_ttZ = "x_ttZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	      else if(bTag_syst_names[i_b]=="CFErr1Down")
	    h_name_ttZ = "x_ttZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	      else if(bTag_syst_names[i_b]=="CFErr2Up")
	    h_name_ttZ = "x_ttZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	      else if(bTag_syst_names[i_b]=="CFErr2Down")
	    h_name_ttZ = "x_ttZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_ttG = "x_Convs"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_ttG = "x_Convs"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_ttG = "x_Convs"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_ttG = "x_Convs"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_ttG = "x_Convs"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_TTZ = "x_TTZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_TTZ = "x_TTZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_TTZ = "x_TTZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_TTZ = "x_TTZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_TTZ = "x_TTZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TH1F* h_TTZ = (TH1F*)f_new->Get(h_name_ttZ);
	    h_TTZ->Add( (TH1F*)f_new->Get(h_name_ttG) );
	    h_TTZ->SetNameTitle(h_name_TTZ,h_name_TTZ);
	    h_TTZ->Write();

	    TString h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TH1F* h_EWK = (TH1F*)f_new->Get(h_name_WZ);
	    h_EWK->Add( (TH1F*)f_new->Get(h_name_ZZ) );
	    h_EWK->SetNameTitle(h_name_EWK,h_name_EWK);
	    h_EWK->Write();


	    TString h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";

	    TString h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";

	    TString h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";

	    TString h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";

	    TString h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";
	
	    TString h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b].Contains("Stats"))
	      h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_ttHl_btag_"+bTag_syst_names[i_b];
	    if(bTag_syst_names[i_b]=="CFErr1Up")
	      h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Up";
	    else if(bTag_syst_names[i_b]=="CFErr1Down")
	      h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr1Down";
	    else if(bTag_syst_names[i_b]=="CFErr2Up")
	      h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Up";
	    else if(bTag_syst_names[i_b]=="CFErr2Down")
	      h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_ttHl_btag_cErr2Down";

	    TH1F* h_Rares = (TH1F*)f_new->Get(h_name_WWW);
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_WWZ) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_WZZ) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_ZZZ) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_WWss) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_tZq) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_TTTT) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_ttWW) );
	    h_Rares->SetNameTitle(h_name_Rares,h_name_Rares);
	    h_Rares->Write();
        }

    }

    cout<<"OK syst btag"<<endl;
    

    //////////////////////////////////
    /////SYSTEMATICS THEORETICAL//////
    //////////////////////////////////
    
    //OK!
    for(unsigned i_MC=0;i_MC<MC_sample_name_thu_unc.size();i_MC++){

      TString syst_names="CMS_ttHl_thu_shape_";
      if(MC_sample_name_thu_unc[i_MC].Contains("ttH"))
		syst_names+="ttH1";
      else if(MC_sample_name_thu_unc[i_MC].Contains("ttZ"))
		syst_names+="ttZ1";
      else if(MC_sample_name_thu_unc[i_MC].Contains("ttW"))
		syst_names+="ttW1";


      TH1F* h_nomin = (TH1F*)f_new->Get("x_"+MC_sample_name_thu_unc[i_MC]);
      float norm = h_nomin->Integral();
		    
      TString cut = "PU_weight_ICHEP18*triggerSF_weight*leptonSF_ttH_weight*bTagSF_CSVshape_weight*tauSF_weight";
      cut+=Form("*(category==%i && ",cat[i_cat]) + MC_sample_cut_thu_unc[i_MC] + " && " + cut_cat + ")";

      TH1F* h_MC_x1_up = single_plot(filename_MC_thu_unc[i_MC],
				    "T",
				    var,
				    "MC_weight_scale_muR2*"+cut,
				    nbin,xmin,xmax);
      
      //h_MC_x1_up->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);      
      h_MC_x1_up->Scale(norm/h_MC_x1_up->Integral());
      h_MC_x1_up->SetNameTitle("x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"_x1Up","x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"_x1Up");
      makeBinContentsPositive(h_MC_x1_up);
      h_MC_x1_up->Write();

      TH1F* h_MC_x1_down = single_plot(filename_MC_thu_unc[i_MC],
				    "T",
				    var,
				    "MC_weight_scale_muR0p5*"+cut,
				    nbin,xmin,xmax);

      //h_MC_x1_down->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);
      h_MC_x1_down->Scale(norm/h_MC_x1_down->Integral());
      h_MC_x1_down->SetNameTitle("x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"_x1Down","x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"_x1Down");
      makeBinContentsPositive(h_MC_x1_down);
      h_MC_x1_down->Write();

      TH1F* h_MC_y1_up = single_plot(filename_MC_thu_unc[i_MC],
				    "T",
				    var,
				    "MC_weight_scale_muF2*"+cut,
				    nbin,xmin,xmax);
      
      //h_MC_y1_up->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);
      h_MC_y1_up->Scale(norm/h_MC_y1_up->Integral());
      h_MC_y1_up->SetNameTitle("x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"_y1Up","x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"_y1Up");
      makeBinContentsPositive(h_MC_y1_up);
      h_MC_y1_up->Write();

      TH1F* h_MC_y1_down = single_plot(filename_MC_thu_unc[i_MC],
				    "T",
				    var,
				    "MC_weight_scale_muF0p5*"+cut,
				    nbin,xmin,xmax);
      
      //h_MC_y1_down->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);
      h_MC_y1_down->Scale(norm/h_MC_y1_down->Integral());
      h_MC_y1_down->SetNameTitle("x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"_y1Down","x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"_y1Down");
      makeBinContentsPositive(h_MC_y1_down);      
      h_MC_y1_down->Write();

      TH1F* ratio_x1_up = (TH1F*)h_MC_x1_up->Clone();
      ratio_x1_up->Divide(h_nomin);
      TF1* f_x1_up = new TF1("f_x1_up","pol1");
      ratio_x1_up->Fit(f_x1_up);
      double slope_x1_up = f_x1_up->GetParameter(1);

      TH1F* ratio_x1_down = (TH1F*)h_MC_x1_down->Clone();
      ratio_x1_down->Divide(h_nomin);
      TF1* f_x1_down = new TF1("f_x1_down","pol1");
      ratio_x1_down->Fit(f_x1_down);
      double slope_x1_down = f_x1_down->GetParameter(1);

      TH1F* ratio_y1_up = (TH1F*)h_MC_y1_up->Clone();
      ratio_y1_up->Divide(h_nomin);
      TF1* f_y1_up = new TF1("f_y1_up","pol1");
      ratio_y1_up->Fit(f_y1_up);
      double slope_y1_up = f_y1_up->GetParameter(1);

      TH1F* ratio_y1_down = (TH1F*)h_MC_y1_down->Clone();
      ratio_y1_down->Divide(h_nomin);
      TF1* f_y1_down = new TF1("f_y1_down","pol1");
      ratio_y1_down->Fit(f_y1_down);
      double slope_y1_down = f_y1_down->GetParameter(1);

      vector<double> slopes={slope_x1_up, slope_x1_down, slope_y1_up, slope_y1_down};
      int max_slope = distance(slopes.begin(), max_element(slopes.begin(),slopes.end()));
      int min_slope = distance(slopes.begin(), min_element(slopes.begin(),slopes.end()));

      TH1F* h_MC_thu_shapeUp; 
      if(max_slope==0)
		h_MC_thu_shapeUp = (TH1F*)h_MC_x1_up->Clone(); 
      else if(max_slope==1)
		h_MC_thu_shapeUp = (TH1F*)h_MC_x1_down->Clone(); 
      else if(max_slope==2)
		h_MC_thu_shapeUp = (TH1F*)h_MC_y1_up->Clone();
      else if(max_slope==3)
		h_MC_thu_shapeUp = (TH1F*)h_MC_y1_down->Clone();      
      h_MC_thu_shapeUp->SetNameTitle("x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"Up","x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"Up");
      h_MC_thu_shapeUp->Write();

      TH1F* h_MC_thu_shapeDown; 
      if(min_slope==0)
		h_MC_thu_shapeDown = (TH1F*)h_MC_x1_up->Clone();
      else if(min_slope==1)
		h_MC_thu_shapeDown = (TH1F*)h_MC_x1_down->Clone();
      else if(min_slope==2)
		h_MC_thu_shapeDown = (TH1F*)h_MC_y1_up->Clone();
      else if(min_slope==3)
		h_MC_thu_shapeDown = (TH1F*)h_MC_y1_down->Clone();      
      h_MC_thu_shapeDown->SetNameTitle("x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"Down","x_"+MC_sample_name_thu_unc[i_MC]+"_"+syst_names+"Down");
      h_MC_thu_shapeDown->Write();     
 
    }

    vector<TString> thu_uncert;
    thu_uncert.push_back("_x1Up");
    thu_uncert.push_back("_x1Down");
    thu_uncert.push_back("_y1Up");
    thu_uncert.push_back("_y1Down");
    thu_uncert.push_back("Up");
    thu_uncert.push_back("Down");
    

    for(unsigned int i=0;i<thu_uncert.size();i++){

      for(unsigned int i_bkg=0;i_bkg<bkg_type.size();i_bkg++){

	    TString h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_thu_shape_ttH1"+thu_uncert[i];
	    TString h_name_tHq = "x_tHq"+bkg_type[i_bkg]; //Just take nominal for tHq
	    TString h_name_tHW = "x_tHW"+bkg_type[i_bkg]; //Just take nominal for tHW
	    TString h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_thu_shape_ttH1"+thu_uncert[i];
	    
	    TH1F* h_TTH = (TH1F*)f_new->Get(h_name_ttH)->Clone();
	    h_TTH->Add( (TH1F*)f_new->Get(h_name_tHq) );
	    h_TTH->Add( (TH1F*)f_new->Get(h_name_tHW) );
	    h_TTH->SetNameTitle(h_name_TTH,h_name_TTH);
	    h_TTH->Write();

	    //TS
	    //TString h_name_ttZ = "x_ttZ"+bkg_type[i_bkg]+"_CMS_ttHl_thu_shape_ttZ"+thu_uncert[i];
	    //TString h_name_ttW = "x_ttW"+bkg_type[i_bkg]+"_CMS_ttHl_thu_shape_ttW"+thu_uncert[i];
	    //TString h_name_ttG = "x_Convs"+bkg_type[i_bkg]+"_CMS_ttHl_thu_shape_Convs"+thu_uncert[i];
	    //TString h_name_TTZ = "x_TTZ"+bkg_type[i_bkg]+"_CMS_ttHl_thu_shape_ttZ"+thu_uncert[i];
	    //TH1F* h_TTZ = (TH1F*)f_new->Get(h_name_ttZ)->Clone();
	    //h_TTZ->Add( (TH1F*)f_new->Get(h_name_ttW) );
	    //h_TTZ->Add( (TH1F*)f_new->Get(h_name_ttG) );
	    //h_TTZ->SetNameTitle(h_name_TTZ,h_name_TTZ);
	    //h_TTZ->Write();
    	

      }

    }

    cout<<"OK syst theoretical "<<endl;
    

    //////////////////////////////////
    ////// SYSTEMATICS JEC/TES ///////
    //////////////////////////////////
    
    /*for(unsigned i_MC=0;i_MC<MC_sample_name.size();i_MC++){
      
      TString MC_weight = "MC_weight";
      if(MC_sample_name[i_MC].Contains("tHq"))
		MC_weight += "_tHq";
	  if(MC_sample_name[i_MC].Contains("tHW"))
		MC_weight += "_tHW";
 
      TString cut = MC_weight + "*PU_weight_ICHEP18*triggerSF_weight*leptonSF_ttH_weight*bTagSF_CSVshape_weight*tauSF_weight";
      cut+=Form("*(category==%i &&",cat[i_cat]) + MC_sample_cut[i_MC]  + " && " + cut_cat + ")";
      
      TH1F* h_MC_JEC_up = single_plot(filename_MC_JECup[i_MC],
				"T",
				var,
				cut,
				nbin,xmin,xmax);

      h_MC_JEC_up->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);      
      h_MC_JEC_up->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_scale_jUp","x_"+MC_sample_name[i_MC]+"_CMS_scale_jUp");
      makeBinContentsPositive(h_MC_JEC_up);
      h_MC_JEC_up->Write();
      
      TH1F* h_MC_JEC_down = single_plot(filename_MC_JECdown[i_MC],
			    "T",
			    var,
			    cut,
			    nbin,xmin,xmax);
      
      h_MC_JEC_down->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);
      h_MC_JEC_down->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_scale_jDown","x_"+MC_sample_name[i_MC]+"_CMS_scale_jDown");
      makeBinContentsPositive(h_MC_JEC_down);
      h_MC_JEC_down->Write();

      TH1F* h_MC_TES_up = single_plot(filename_MC_TESup[i_MC],
				"T",
				var,
				cut,
				nbin,xmin,xmax);

      h_MC_TES_up->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);      
      h_MC_TES_up->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_scale_tUp","x_"+MC_sample_name[i_MC]+"_CMS_scale_tUp");
      makeBinContentsPositive(h_MC_TES_up);
      h_MC_TES_up->Write();
  
      TH1F* h_MC_TES_down = single_plot(filename_MC_TESdown[i_MC],
			    "T",
			    var,
			    cut,
			    nbin,xmin,xmax);

      h_MC_TES_down->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);      
      h_MC_TES_down->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_scale_tDown","x_"+MC_sample_name[i_MC]+"_CMS_scale_tDown");
      makeBinContentsPositive(h_MC_TES_down);
      h_MC_TES_down->Write();

    }
  
    vector<TString> JES_TES_uncert;
    JES_TES_uncert.push_back("jUp");
    JES_TES_uncert.push_back("jDown");
    JES_TES_uncert.push_back("tUp");
    JES_TES_uncert.push_back("tDown");


    for(unsigned int i=0;i<JES_TES_uncert.size();i++){

      for(unsigned int i_bkg=0;i_bkg<bkg_type.size();i_bkg++){
            
	    TString h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    
	    TH1F* h_TTH = (TH1F*)f_new->Get(h_name_ttH);
	    h_TTH->Add( (TH1F*)f_new->Get(h_name_tHq) );
	    h_TTH->Add( (TH1F*)f_new->Get(h_name_tHW) );
	    h_TTH->SetNameTitle(h_name_TTH,h_name_TTH);
	    h_TTH->Write();

	    TString h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    
	    TH1F* h_EWK = (TH1F*)f_new->Get(h_name_WZ);
	    h_EWK->Add( (TH1F*)f_new->Get(h_name_ZZ) );
	    h_EWK->SetNameTitle(h_name_EWK,h_name_EWK);
	    h_EWK->Write();

	    TString h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];
	    TString h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_scale_"+JES_TES_uncert[i];

	    TH1F* h_Rares = (TH1F*)f_new->Get(h_name_WWW);
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_WWZ) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_WZZ) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_ZZZ) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_WWss) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_tZq) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_TTTT) );
	    h_Rares->Add( (TH1F*)f_new->Get(h_name_ttWW) );
	    h_Rares->SetNameTitle(h_name_Rares,h_name_Rares);
	    h_Rares->Write();
      }

    }
    

    cout<<"OK JEC/TES "<<endl;*/
    
 
    ////////////////////////////////////
    //// SYSTEMATICS JET-TO-TAU FR /////
    ////////////////////////////////////
      
    
    for(unsigned i_MC=0;i_MC<MC_sample_name.size();i_MC++){
      
      if(!MC_sample_name[i_MC].Contains("faketau")) continue;
      
      for(unsigned int i_t=0;i_t<jetToTau_FR_syst_names.size();i_t++){       
		    
		TString MC_weight = "MC_weight";
        if(MC_sample_name[i_MC].Contains("tHq"))
		  MC_weight += "_tHq";
	    if(MC_sample_name[i_MC].Contains("tHW"))
		  MC_weight += "_tHW";
 
		TString cut = MC_weight + "*PU_weight_ICHEP18*triggerSF_weight*leptonSF_ttH_weight*bTagSF_CSVshape_weight*tauSF_weight_"+ jetToTau_FR_syst_names[i_t];
		cut+=Form("*(category==%i &&",cat[i_cat]) + MC_sample_cut[i_MC] + " && " + cut_cat +")";

		TH1F* h_MC_FRjt_syst = single_plot(filename_MC[i_MC],
			"T",
			var,
			cut,
			nbin,xmin,xmax);
	
      	h_MC_FRjt_syst->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);      
	    TString h_name = "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_";
	    if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	      h_name+="normUp";
	    else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	      h_name+="normDown";
	    else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	      h_name+="shapeUp";
	    else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	      h_name+="shapeDown";

	    h_MC_FRjt_syst->SetNameTitle(h_name,h_name);
	    makeBinContentsPositive(h_MC_FRjt_syst);
	    h_MC_FRjt_syst->Write();
      }

    }


    for(unsigned int i_t=0;i_t<jetToTau_FR_syst_names.size();i_t++){  
      
      for(unsigned int i_bkg=0;i_bkg<bkg_type.size();i_bkg++){
          
          if(!bkg_type[i_bkg].Contains("faketau")) continue;

	  TString h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_ttH+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_ttH+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_ttH+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_ttH+="shapeDown";
	  TString h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_tHq+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_tHq+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_tHq+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_tHq+="shapeDown";
	  
	  TString h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_tHW+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_tHW+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_tHW+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_tHW+="shapeDown";
      
	  TString h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_TTH+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_TTH+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_TTH+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_TTH+="shapeDown";	

	  TH1F* h_TTH = (TH1F*)f_new->Get(h_name_ttH);
	  h_TTH->Add( (TH1F*)f_new->Get(h_name_tHq) );
	  h_TTH->Add( (TH1F*)f_new->Get(h_name_tHW) );
	  h_TTH->SetNameTitle(h_name_TTH,h_name_TTH);
	  h_TTH->Write();

	  TString h_name_ttZ = "x_ttZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_ttZ+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_ttZ+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_ttZ+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_ttZ+="shapeDown";
	  TString h_name_ttG = "x_Convs"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_ttG+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_ttG+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_ttG+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_ttG+="shapeDown";	
	  TString h_name_TTZ = "x_TTZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_TTZ+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_TTZ+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_TTZ+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_TTZ+="shapeDown";	

	  TH1F* h_TTZ = (TH1F*)f_new->Get(h_name_ttZ);
	  h_TTZ->Add( (TH1F*)f_new->Get(h_name_ttG) );
	  h_TTZ->SetNameTitle(h_name_TTZ,h_name_TTZ);
	  h_TTZ->Write();
	
	  TString h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_WZ+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_WZ+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_WZ+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_WZ+="shapeDown";	
	  TString h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_ZZ+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_ZZ+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_ZZ+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_ZZ+="shapeDown";		
	  TString h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_EWK+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_EWK+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_EWK+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_EWK+="shapeDown";
		
	  TH1F* h_EWK = (TH1F*)f_new->Get(h_name_WZ);
	  h_EWK->Add( (TH1F*)f_new->Get(h_name_ZZ) );
	  h_EWK->SetNameTitle(h_name_EWK,h_name_EWK);
	  h_EWK->Write();
	
	  TString h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";	
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_WWW+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_WWW+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_WWW+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_WWW+="shapeDown";	
	  TString h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";		
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_WWZ+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_WWZ+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_WWZ+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_WWZ+="shapeDown";
	  TString h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_WZZ+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_WZZ+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_WZZ+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_WZZ+="shapeDown";		
	  TString h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_ZZZ+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_ZZZ+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_ZZZ+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_ZZZ+="shapeDown";
	  TString h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_WWss+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_WWss+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_WWss+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_WWss+="shapeDown";
	  TString h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_tZq+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_tZq+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_tZq+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_tZq+="shapeDown";
	  TString h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_TTTT+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_TTTT+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_TTTT+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_TTTT+="shapeDown";
	  TString h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_ttWW+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_ttWW+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_ttWW+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	  h_name_ttWW+="shapeDown";
	
	  TString h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
	    h_name_Rares+="normUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
	    h_name_Rares+="normDown";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
	    h_name_Rares+="shapeUp";
	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
	    h_name_Rares+="shapeDown";
	

	  TH1F* h_Rares = (TH1F*)f_new->Get(h_name_WWW);
	  h_Rares->Add( (TH1F*)f_new->Get(h_name_WWZ) );
	  h_Rares->Add( (TH1F*)f_new->Get(h_name_WZZ) );
	  h_Rares->Add( (TH1F*)f_new->Get(h_name_ZZZ) );
	  h_Rares->Add( (TH1F*)f_new->Get(h_name_WWss) );
	  h_Rares->Add( (TH1F*)f_new->Get(h_name_tZq) );
	  h_Rares->Add( (TH1F*)f_new->Get(h_name_TTTT) );
	  h_Rares->Add( (TH1F*)f_new->Get(h_name_ttWW) );
	  h_Rares->SetNameTitle(h_name_Rares,h_name_Rares);
	  h_Rares->Write();
	
      }

    }

    cout<<"OK syst jetToTau FR"<<endl;
    
 

    /////////////////////////////////
    ///// SYSTEMATICS TAU-ID ////////
    /////////////////////////////////

    
    /*for(unsigned i_MC=0;i_MC<MC_sample_name.size();i_MC++){

        if(MC_sample_name[i_MC].Contains("faketau") || MC_sample_name[i_MC].Contains("gentau")) continue;

        TH1F* h_MC_tauIDUp = (TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_faketau");
        h_MC_tauIDUp->Add((TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_gentau"),1.05);
        h_MC_tauIDUp->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_eff_tUp", "x_"+MC_sample_name[i_MC]+"_CMS_eff_tUp");
        h_MC_tauIDUp->Write();

     	TH1F* h_MC_tauIDDown = (TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_faketau");
     	h_MC_tauIDDown->Add((TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_gentau"),0.95);
     	h_MC_tauIDDown->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_eff_tDown", "x_"+MC_sample_name[i_MC]+"_CMS_eff_tDown");
     	h_MC_tauIDDown->Write();
     
     	TH1F* h_MC_FRjt_normUp = (TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_gentau");
     	h_MC_FRjt_normUp->Add((TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_faketau_CMS_ttHl_FRjt_normUp"));
     	h_MC_FRjt_normUp->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_normUp", "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_normUp");
     	h_MC_FRjt_normUp->Write();
     
     	TH1F* h_MC_FRjt_normDown = (TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_gentau");
     	h_MC_FRjt_normDown->Add((TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_faketau_CMS_ttHl_FRjt_normDown"));
     	h_MC_FRjt_normDown->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_normDown", "x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_normDown");
     	h_MC_FRjt_normDown->Write();
     
     	TH1F* h_MC_FRjt_shapeUp = (TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_gentau");
     	h_MC_FRjt_shapeUp->Add((TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_faketau_CMS_ttHl_FRjt_shapeUp"));
     	h_MC_FRjt_shapeUp->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_shapeUp","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_shapeUp");
     	h_MC_FRjt_shapeUp->Write();
     
     	TH1F* h_MC_FRjt_shapeDown = (TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_gentau");
     	h_MC_FRjt_shapeDown->Add((TH1F*)f_new->Get("x_"+MC_sample_name[i_MC]+"_faketau_CMS_ttHl_FRjt_shapeDown"));
     	h_MC_FRjt_shapeDown->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_shapeDown","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_FRjt_shapeDown");
     	h_MC_FRjt_shapeDown->Write();


    }


    vector<TString> syst_type_tauID;
    syst_type_tauID.push_back("Up");
    syst_type_tauID.push_back("Down");

    for(unsigned int i_syst=0;i_syst<2;i_syst++){

     	TString h_name_ttH = "x_ttH_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_tHq = "x_tHq_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_tHW = "x_tHW_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_TTH = "x_TTH_CMS_eff_t"+syst_type_tauID[i_syst];
 
     	TH1F* h_TTH = (TH1F*)f_new->Get(h_name_ttH);
     	h_TTH->Add( (TH1F*)f_new->Get(h_name_tHq) );
     	h_TTH->Add( (TH1F*)f_new->Get(h_name_tHW) );
     	h_TTH->SetNameTitle(h_name_TTH,h_name_TTH);
     	h_TTH->Write();

     	TString h_name_ttZ = "x_ttZ_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_ttG = "x_Convs_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_TTZ = "x_TTZ_CMS_eff_t"+syst_type_tauID[i_syst];
 
     	TH1F* h_TTZ = (TH1F*)f_new->Get(h_name_ttZ);
     	h_TTZ->Add( (TH1F*)f_new->Get(h_name_ttG) );
     	h_TTZ->SetNameTitle(h_name_TTZ,h_name_TTZ);
     	h_TTZ->Write();
	
     	TString h_name_WZ = "x_WZ_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_ZZ = "x_ZZ_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_EWK = "x_EWK_CMS_eff_t"+syst_type_tauID[i_syst];
		
     	TH1F* h_EWK = (TH1F*)f_new->Get(h_name_WZ);
     	h_EWK->Add( (TH1F*)f_new->Get(h_name_ZZ) );
     	h_EWK->SetNameTitle(h_name_EWK,h_name_EWK);
     	h_EWK->Write();

     	TString h_name_WWW = "x_WWW_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_WWZ = "x_WWZ_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_WZZ = "x_WZZ_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_ZZZ = "x_ZZZ_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_WWss = "x_WWss_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_tZq = "x_tZq_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_TTTT = "x_TTTT_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_ttWW = "x_ttWW_CMS_eff_t"+syst_type_tauID[i_syst];
     	TString h_name_Rares = "x_Rares_CMS_eff_t"+syst_type_tauID[i_syst];	
	
     	TH1F* h_Rares = (TH1F*)f_new->Get(h_name_WWW);
     	h_Rares->Add( (TH1F*)f_new->Get(h_name_WWZ) );
     	h_Rares->Add( (TH1F*)f_new->Get(h_name_WZZ) );
     	h_Rares->Add( (TH1F*)f_new->Get(h_name_ZZZ) );
     	h_Rares->Add( (TH1F*)f_new->Get(h_name_WWss) );
     	h_Rares->Add( (TH1F*)f_new->Get(h_name_tZq) );	     
     	h_Rares->Add( (TH1F*)f_new->Get(h_name_TTTT) );
     	h_Rares->Add( (TH1F*)f_new->Get(h_name_ttWW) );
     	h_Rares->SetNameTitle(h_name_Rares,h_name_Rares);
     	h_Rares->Write();

    }


    cout<<"OK syst tauID"<<endl;*/
    

    ////////////////////////////////////
    /////// SYSTEMATICS TAU-FAKES //////
    ////////////////////////////////////
    
    for(unsigned int i_t=0;i_t<jetToTau_FR_syst_names.size();i_t++){  

        for(unsigned int i_bkg=0;i_bkg<bkg_type.size();i_bkg++){
        	
            if(bkg_type[i_bkg].Contains("faketau") || bkg_type[i_bkg].Contains("gentau")) continue;
	
	    	TString h_name_ttH = "x_ttH"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
          	if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
          	  h_name_ttH+="normUp";
          	else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
          	  h_name_ttH+="normDown";
          	else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
          	  h_name_ttH+="shapeUp";
          	else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
          	  h_name_ttH+="shapeDown";
        	TString h_name_tHq = "x_tHq"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
        	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
        	    h_name_tHq+="normUp";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
        	    h_name_tHq+="normDown";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
        	    h_name_tHq+="shapeUp";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
        	    h_name_tHq+="shapeDown";
	    	TString h_name_tHW = "x_tHW"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
        	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
        	    h_name_tHW+="normUp";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
        	    h_name_tHW+="normDown";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
        	    h_name_tHW+="shapeUp";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
        	    h_name_tHW+="shapeDown";
	    	TString h_name_TTH = "x_TTH"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
        	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
        	    h_name_TTH+="normUp";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
        	    h_name_TTH+="normDown";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
        	    h_name_TTH+="shapeUp";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
        	    h_name_TTH+="shapeDown";
	
				
	    	TH1F* h_TTH = (TH1F*)f_new->Get(h_name_ttH);
	    	h_TTH->Add( (TH1F*)f_new->Get(h_name_tHq) );
	    	h_TTH->Add( (TH1F*)f_new->Get(h_name_tHW) );
	    	h_TTH->SetNameTitle(h_name_TTH,h_name_TTH);
	    	h_TTH->Write();

	    	//TS
	    	//TString h_name_ttZ = "x_ttZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
        	    //if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
        	    //  h_name_ttZ+="normUp";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
        	    //  h_name_ttZ+="normDown";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
        	    //  h_name_ttZ+="shapeUp";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
        	    //  h_name_ttZ+="shapeDown";
        	//TString h_name_ttG = "x_Convs"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
        	    //if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
        	    //  h_name_ttG+="normUp";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
        	    //  h_name_ttG+="normDown";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
        	    //  h_name_ttG+="shapeUp";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
        	    //  h_name_ttG+="shapeDown";
	    	//TString h_name_TTZ = "x_TTZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
        	    //if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
        	    //  h_name_TTZ+="normUp";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
        	    //  h_name_TTZ+="normDown";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
        	    //  h_name_TTZ+="shapeUp";
        	    //else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
        	    //  h_name_TTZ+="shapeDown";
	    	//TH1F* h_TTZ = (TH1F*)f_new->Get(h_name_ttZ);
	    	//h_TTZ->Add( (TH1F*)f_new->Get(h_name_ttG) );
	    	//h_TTZ->SetNameTitle(h_name_TTZ,h_name_TTZ);
	    	//h_TTZ->Write();


   			TString h_name_WZ = "x_WZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_WZ+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_WZ+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_WZ+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_WZ+="shapeDown";
    		TString h_name_ZZ = "x_ZZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_ZZ+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_ZZ+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_ZZ+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_ZZ+="shapeDown";
    		TString h_name_EWK = "x_EWK"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_EWK+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_EWK+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_EWK+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_EWK+="shapeDown";


			TH1F* h_EWK = (TH1F*)f_new->Get(h_name_WZ);
			h_EWK->Add( (TH1F*)f_new->Get(h_name_ZZ) );
			h_EWK->SetNameTitle(h_name_EWK,h_name_EWK);
			h_EWK->Write();

			TString h_name_WWW = "x_WWW"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_WWW+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_WWW+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_WWW+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_WWW+="shapeDown";
    		TString h_name_WWZ = "x_WWZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_WWZ+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_WWZ+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_WWZ+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_WWZ+="shapeDown";
    		TString h_name_WZZ = "x_WZZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_WZZ+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_WZZ+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_WZZ+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_WZZ+="shapeDown";
    		TString h_name_ZZZ = "x_ZZZ"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_ZZZ+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_ZZZ+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_ZZZ+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_ZZZ+="shapeDown";
    		TString h_name_WWss = "x_WWss"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_WWss+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_WWss+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_WWss+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_WWss+="shapeDown";
    		TString h_name_tZq = "x_tZq"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_tZq+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
    		    h_name_tZq+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_tZq+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_tZq+="shapeDown";
    		TString h_name_TTTT = "x_TTTT"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_TTTT+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
			    h_name_TTTT+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_TTTT+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
    		    h_name_TTTT+="shapeDown";
			TString h_name_ttWW = "x_ttWW"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
    		  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
    		    h_name_ttWW+="normUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
			    h_name_ttWW+="normDown";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
    		    h_name_ttWW+="shapeUp";
    		  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
				h_name_ttWW+="shapeDown";
        	TString h_name_Rares = "x_Rares"+bkg_type[i_bkg]+"_CMS_ttHl_FRjt_";
        	  if(jetToTau_FR_syst_names[i_t]=="tauNormUp")
        	    h_name_Rares+="normUp";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauNormDown")
        	    h_name_Rares+="normDown";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeUp")
        	    h_name_Rares+="shapeUp";
        	  else if(jetToTau_FR_syst_names[i_t]=="tauShapeDown")
        	    h_name_Rares+="shapeDown";

			TH1F* h_Rares = (TH1F*)f_new->Get(h_name_WWW);
			h_Rares->Add( (TH1F*)f_new->Get(h_name_WWZ) );
			h_Rares->Add( (TH1F*)f_new->Get(h_name_WZZ) );
			h_Rares->Add( (TH1F*)f_new->Get(h_name_ZZZ) );
			h_Rares->Add( (TH1F*)f_new->Get(h_name_WWss) );	
			h_Rares->Add( (TH1F*)f_new->Get(h_name_tZq) );
			h_Rares->Add( (TH1F*)f_new->Get(h_name_TTTT) );
			h_Rares->Add( (TH1F*)f_new->Get(h_name_ttWW) );
			h_Rares->SetNameTitle(h_name_Rares,h_name_Rares);
			h_Rares->Write();
	
      	}

    }


    cout<<"OK syst tau fakes"<<endl;
    


    ////////////////////////////////////////
    //// FAKE LEPTON CLOSURE SYSTEMATICS ///
    ////////////////////////////////////////
    /*
    TH1F* h_TT_DL_clos_ele_diff = single_plot(filename_ttbar_DL,
		"HTauTauTree_2lSS_1tau_fake",
		var,
		Form("MC_weight*PU_weight_ICHEP18*triggerSF_weight*bTagSF_CSVshape_weight*leptonSF_ttH_weight*tauSF_weight*(event_weight_ttH_ele_FR_TT_MC-event_weight_ttH_ele_FR_QCD_MC)*(category==%i && recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0] && ",cat_fakes[i_cat]) + cut_cat + ")",
		nbin,xmin,xmax);
    
    h_TT_DL_clos_ele_diff->Scale(luminosity*XS_ttbar_DL/h_ttbar_DL_norm->Integral());

    TH1F* h_TT_SL_clos_ele_diff = single_plot(filename_ttbar_SL,
        "HTauTauTree_2lSS_1tau_fake",
        var,
        Form("MC_weight*PU_weight_ICHEP18*triggerSF_weight*bTagSF_CSVshape_weight*leptonSF_ttH_weight*tauSF_weight*(event_weight_ttH_ele_FR_TT_MC-event_weight_ttH_ele_FR_QCD_MC)*(category==%i && recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0] && ",cat_fakes[i_cat]) + cut_cat + ")",
        nbin,xmin,xmax);

    h_TT_SL_clos_ele_diff->Scale(luminosity*XS_ttbar_SL/h_ttbar_SL_norm->Integral());

    TH1F* h_fakes_clos_ele_Up = (TH1F*)h_fakes->Clone();
    h_fakes_clos_ele_Up->Add(h_TT_DL_clos_ele_diff,+1);  
    h_fakes_clos_ele_Up->Add(h_TT_SL_clos_ele_diff,+1);
    h_fakes_clos_ele_Up->Scale(h_fakes->Integral()/h_fakes_clos_ele_Up->Integral());  
    h_fakes_clos_ele_Up->SetNameTitle("x_fakes_data_CMS_ttHl_Clos_e_shapeUp","x_fakes_data_CMS_ttHl_Clos_e_shapeUp");
    makeBinContentsPositive(h_fakes_clos_ele_Up);
    h_fakes_clos_ele_Up->Write();

    TH1F* h_fakes_clos_ele_Down = (TH1F*)h_fakes->Clone();
    h_fakes_clos_ele_Down->Add(h_TT_DL_clos_ele_diff,-1);  
    h_fakes_clos_ele_Down->Add(h_TT_SL_clos_ele_diff,-1);
    h_fakes_clos_ele_Down->Scale(h_fakes->Integral()/h_fakes_clos_ele_Down->Integral());  
    h_fakes_clos_ele_Down->SetNameTitle("x_fakes_data_CMS_ttHl_Clos_e_shapeDown","x_fakes_data_CMS_ttHl_Clos_e_shapeDown");
    makeBinContentsPositive(h_fakes_clos_ele_Down);
    h_fakes_clos_ele_Down->Write();

   	TH1F* h_TT_DL_clos_mu_diff = single_plot(filename_ttbar_DL,
			"HTauTauTree_2lSS_1tau_fake",
			var,
			Form("MC_weight*PU_weight_ICHEP18*triggerSF_weight*bTagSF_CSVshape_weight*leptonSF_ttH_weight*tauSF_weight*(event_weight_ttH_mu_FR_TT_MC-event_weight_ttH_mu_FR_QCD_MC)*(category==%i && recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0] && ",cat_fakes[i_cat]) + cut_cat + ")",
			nbin,xmin,xmax);
    
    h_TT_DL_clos_mu_diff->Scale(luminosity*XS_ttbar_DL/h_ttbar_DL_norm->Integral());

   	TH1F* h_TT_SL_clos_mu_diff = single_plot(filename_ttbar_SL,
   	     "HTauTauTree_2lSS_1tau_fake",
   	     var,
   	     Form("MC_weight*PU_weight_ICHEP18*triggerSF_weight*bTagSF_CSVshape_weight*leptonSF_ttH_weight*tauSF_weight*(event_weight_ttH_mu_FR_TT_MC-event_weight_ttH_mu_FR_QCD_MC)*(category==%i && recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0] && ",cat_fakes[i_cat]) + cut_cat + ")",                                   
   	     nbin,xmin,xmax);
	
   	h_TT_SL_clos_mu_diff->Scale(luminosity*XS_ttbar_SL/h_ttbar_SL_norm->Integral());


    TH1F* h_fakes_clos_mu_Up = (TH1F*)h_fakes->Clone();
    h_fakes_clos_mu_Up->Add(h_TT_DL_clos_mu_diff,+1);  
    h_fakes_clos_mu_Up->Add(h_TT_SL_clos_mu_diff,+1);
    h_fakes_clos_mu_Up->Scale(h_fakes->Integral()/h_fakes_clos_mu_Up->Integral());  
    h_fakes_clos_mu_Up->SetNameTitle("x_fakes_data_CMS_ttHl_Clos_m_shapeUp","x_fakes_data_CMS_ttHl_Clos_m_shapeUp");
    makeBinContentsPositive(h_fakes_clos_mu_Up);
    h_fakes_clos_mu_Up->Write();


    TH1F* h_fakes_clos_mu_Down = (TH1F*)h_fakes->Clone();
    h_fakes_clos_mu_Down->Add(h_TT_DL_clos_mu_diff,-1);  
    h_fakes_clos_mu_Down->Add(h_TT_SL_clos_mu_diff,-1);
    h_fakes_clos_mu_Down->Scale(h_fakes->Integral()/h_fakes_clos_mu_Down->Integral());  
    h_fakes_clos_mu_Down->SetNameTitle("x_fakes_data_CMS_ttHl_Clos_m_shapeDown","x_fakes_data_CMS_ttHl_Clos_m_shapeDown");
    makeBinContentsPositive(h_fakes_clos_mu_Down);
    h_fakes_clos_mu_Down->Write();

    cout<<"OK closure syst"<<endl;
    */   
 
    ///////////////////////////////////
    ///// FAKE LEPTON SYSTEMATICS /////
    ///////////////////////////////////
    
    /*for(unsigned int i_f=0;i_f<fake_syst_names.size();i_f++){
    
        TString weight = "event_weight_ttH_"+ fake_syst_names[i_f];
        TString cut = weight + Form("*(category==%i && recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0] && ",cat_fakes[i_cat]) + cut_cat + ")";

        TH1F* h_fakes_syst =single_plot(filename_data,
            "HTauTauTree_2lSS_1tau_fake",
            var,
            cut,
            nbin,xmin,xmax);

        h_fakes_syst->Scale(luminosity/41298.); //Data files for 35.9 fb-1
											
		for(unsigned int i_MC=0;i_MC<MC_sample_name.size();i_MC++){

	   		if(MC_sample_name[i_MC]=="ttH" || MC_sample_name[i_MC].Contains("ttbar")) continue;  	

	    	TString MC_weight = "MC_weight";
        	if(MC_sample_name[i_MC].Contains("tHq"))
		  		MC_weight += "_tHq";
	    	if(MC_sample_name[i_MC].Contains("tHW"))
		  		MC_weight += "_tHW";

            TString MC_cut = MC_weight + "*PU_weight_ICHEP18*triggerSF_weight*leptonSF_ttH_weight*bTagSF_CSVshape_weight*tauSF_weight*"+weight+Form("*(category==%i && recotauh_sel_byLooseIsolationMVArun2v2DBdR03oldDMwLT2017[0] && 1 && 1 &&",cat_fakes[i_cat]) + MC_sample_cut[i_MC] + " && " + cut_cat + ")";

	    	TH1F* h_MC_genmatch = single_plot(filename_MC[i_MC],
                "HTauTauTree_2lSS_1tau_fake",
				var,
				MC_cut,
				nbin,xmin,xmax);

            h_MC_genmatch->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);
            h_fakes_syst->Add(h_MC_genmatch,-1);
     	}

			
		TString h_name = "x_fakes_data";
        if(fake_syst_names[i_f]=="ele_up")
            h_name+="_CMS_ttHl_FRe_normUp";
        else if(fake_syst_names[i_f]=="ele_down")
            h_name+="_CMS_ttHl_FRe_normDown";
        else if(fake_syst_names[i_f]=="ele_pt1")
            h_name+="_CMS_ttHl_FRe_ptUp";
        else if(fake_syst_names[i_f]=="ele_pt2")
            h_name+="_CMS_ttHl_FRe_ptDown";
        else if(fake_syst_names[i_f]=="ele_b1")
            h_name+="_CMS_ttHl_FRe_bUp";
        else if(fake_syst_names[i_f]=="ele_b2")
            h_name+="_CMS_ttHl_FRe_bDown";
        else if(fake_syst_names[i_f]=="ele_ec1")
        	h_name+="_CMS_ttHl_FRe_ecUp";
        else if(fake_syst_names[i_f]=="ele_ec2")
            h_name+="_CMS_ttHl_FRe_ecDown";
	 	else if(fake_syst_names[i_f]=="ele_be1")
           	h_name+="_CMS_ttHl_FRe_beUp";
        else if(fake_syst_names[i_f]=="ele_be2")
           	h_name+="_CMS_ttHl_FRe_beDown";
        else if(fake_syst_names[i_f]=="mu_up")
            h_name+="_CMS_ttHl_FRm_normUp";
        else if(fake_syst_names[i_f]=="mu_down")
            h_name+="_CMS_ttHl_FRm_normDown";
        else if(fake_syst_names[i_f]=="mu_pt1")
            h_name+="_CMS_ttHl_FRm_ptUp";
        else if(fake_syst_names[i_f]=="mu_pt2")
           h_name+="_CMS_ttHl_FRm_ptDown";
        else if(fake_syst_names[i_f]=="mu_b1")
            h_name+="_CMS_ttHl_FRm_bUp";
        else if(fake_syst_names[i_f]=="mu_b2")
            h_name+="_CMS_ttHl_FRm_bDown";
        else if(fake_syst_names[i_f]=="mu_ec1")
            h_name+="_CMS_ttHl_FRm_ecUp";
        else if(fake_syst_names[i_f]=="mu_ec2")
            h_name+="_CMS_ttHl_FRm_ecDown";
	 	else if(fake_syst_names[i_f]=="mu_be1")
     	    h_name+="_CMS_ttHl_FRm_beUp";
     	else if(fake_syst_names[i_f]=="mu_be2")
     	    h_name+="_CMS_ttHl_FRm_beDown";

        if(!fake_syst_names[i_f].Contains("up") && !fake_syst_names[i_f].Contains("down"))
          	h_fakes_syst->Scale(h_fakes->Integral()/h_fakes_syst->Integral());

        h_fakes_syst->SetNameTitle(h_name,h_name);
        makeBinContentsPositive(h_fakes_syst);
        h_fakes_syst->Write();

    }


    cout<<"OK fake lep syst"<<endl;
    */

    ///////////////////////////////////////////
    ////// SYSTEMATICS LEPTON EFF. TIGHT /////
    //////////////////////////////////////////
   
    
    for(unsigned i_MC=0;i_MC<MC_sample_name.size();i_MC++){

      	TString MC_weight = "MC_weight";
        if(MC_sample_name[i_MC].Contains("tHq"))
		  	MC_weight += "_tHq";
	    if(MC_sample_name[i_MC].Contains("tHW"))
		  	MC_weight += "_tHW";

      	TString cut = MC_weight + Form("*PU_weight_ICHEP18*triggerSF_weight*leptonSF_ttH_weight*bTagSF_CSVshape_weight*tauSF_weight*(category==%i &&",cat[i_cat]) + MC_sample_cut[i_MC] + " && " + cut_cat;

      	TH1F* h_MC_ee = single_plot(filename_MC[i_MC],
			"T",
			var,
			cut + "&& (abs(recolep_sel_pdg[0])+abs(recolep_sel_pdg[1]))==22)",
			nbin,xmin,xmax);

      	TH1F* h_MC_em = single_plot(filename_MC[i_MC],
			"T",
			var,			    
			cut + "&& (abs(recolep_sel_pdg[0])+abs(recolep_sel_pdg[1]))==24)",
			nbin,xmin,xmax);

      	TH1F* h_MC_mm = single_plot(filename_MC[i_MC],
			"T",
			var,			    
			cut + "&& (abs(recolep_sel_pdg[0])+abs(recolep_sel_pdg[1]))==26)",
                        nbin,xmin,xmax);

      	h_MC_mm->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);
      	h_MC_em->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);
      	h_MC_ee->Scale(luminosity*XS[i_MC]/norm_MC[i_MC]);

      	TH1F* h_MC_lepEff_eltightUp = (TH1F*) h_MC_mm->Clone();
      	h_MC_lepEff_eltightUp->Add(h_MC_em,1.03);
      	h_MC_lepEff_eltightUp->Add(h_MC_ee,1.06);
      	h_MC_lepEff_eltightUp->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_eltightUp","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_eltightUp");
      	makeBinContentsPositive(h_MC_lepEff_eltightUp);
      	h_MC_lepEff_eltightUp->Write();

      	TH1F* h_MC_lepEff_eltightDown = (TH1F*) h_MC_mm->Clone();
      	h_MC_lepEff_eltightDown->Add(h_MC_em,0.97);
      	h_MC_lepEff_eltightDown->Add(h_MC_ee,0.94);
      	h_MC_lepEff_eltightDown->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_eltightDown","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_eltightDown");
      	makeBinContentsPositive(h_MC_lepEff_eltightDown);
      	h_MC_lepEff_eltightDown->Write();

      	TH1F* h_MC_lepEff_mutightUp = (TH1F*) h_MC_ee->Clone();
      	h_MC_lepEff_mutightUp->Add(h_MC_em,1.03);
      	h_MC_lepEff_mutightUp->Add(h_MC_mm,1.06);
      	h_MC_lepEff_mutightUp->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_mutightUp","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_mutightUp");
      	makeBinContentsPositive(h_MC_lepEff_mutightUp);
      	h_MC_lepEff_mutightUp->Write();

      	TH1F* h_MC_lepEff_mutightDown = (TH1F*) h_MC_ee->Clone();
      	h_MC_lepEff_mutightDown->Add(h_MC_em,0.97);
      	h_MC_lepEff_mutightDown->Add(h_MC_mm,0.94);
      	h_MC_lepEff_mutightDown->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_mutightDown","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_mutightDown");
      	makeBinContentsPositive(h_MC_lepEff_mutightDown);
      	h_MC_lepEff_mutightDown->Write();

      	TH1F* h_MC_lepEff_ellooseUp = (TH1F*) h_MC_mm->Clone();
      	h_MC_lepEff_ellooseUp->Add(h_MC_em,1.02);
      	h_MC_lepEff_ellooseUp->Add(h_MC_ee,1.04);
      	h_MC_lepEff_ellooseUp->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_ellooseUp","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_ellooseUp");
      	makeBinContentsPositive(h_MC_lepEff_ellooseUp);
      	h_MC_lepEff_ellooseUp->Write();
	
	    TH1F* h_MC_lepEff_ellooseDown = (TH1F*) h_MC_mm->Clone();
	    h_MC_lepEff_ellooseDown->Add(h_MC_em,0.98);
	    h_MC_lepEff_ellooseDown->Add(h_MC_ee,0.96);
	    h_MC_lepEff_ellooseDown->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_ellooseDown","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_ellooseDown");
	    makeBinContentsPositive(h_MC_lepEff_ellooseDown);
	    h_MC_lepEff_ellooseDown->Write();
	
	    TH1F* h_MC_lepEff_mulooseUp = (TH1F*) h_MC_ee->Clone();
	    h_MC_lepEff_mulooseUp->Add(h_MC_em,1.02);
	    h_MC_lepEff_mulooseUp->Add(h_MC_mm,1.04);
	    h_MC_lepEff_mulooseUp->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_mulooseUp","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_mulooseUp");
	    makeBinContentsPositive(h_MC_lepEff_mulooseUp);
	    h_MC_lepEff_mulooseUp->Write();
	
	    TH1F* h_MC_lepEff_mulooseDown = (TH1F*) h_MC_ee->Clone();
	    h_MC_lepEff_mulooseDown->Add(h_MC_em,0.98);
	    h_MC_lepEff_mulooseDown->Add(h_MC_mm,0.96);
	    h_MC_lepEff_mulooseDown->SetNameTitle("x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_mulooseDown","x_"+MC_sample_name[i_MC]+"_CMS_ttHl_lepEff_mulooseDown");
	    makeBinContentsPositive(h_MC_lepEff_mulooseDown);
      	h_MC_lepEff_mulooseDown->Write();

    }


    vector<TString> lepEff_syst;
    lepEff_syst.push_back("lepEff_eltightUp");
    lepEff_syst.push_back("lepEff_eltightDown");
    lepEff_syst.push_back("lepEff_mutightUp");
    lepEff_syst.push_back("lepEff_mutightDown");
    lepEff_syst.push_back("lepEff_ellooseUp");
    lepEff_syst.push_back("lepEff_ellooseDown");
    lepEff_syst.push_back("lepEff_mulooseUp");
    lepEff_syst.push_back("lepEff_mulooseDown");

    for(unsigned int i=0;i<lepEff_syst.size();i++){

      	TString h_name_ttH = "x_ttH_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_tHq = "x_tHq_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_tHW = "x_tHW_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_TTH = "x_TTH_CMS_ttHl_"+lepEff_syst[i];

      	TH1F* h_TTH = (TH1F*)f_new->Get(h_name_ttH)->Clone();
      	h_TTH->Add( (TH1F*)f_new->Get(h_name_tHq) );
      	h_TTH->Add( (TH1F*)f_new->Get(h_name_tHW) );
      	h_TTH->SetNameTitle(h_name_TTH,h_name_TTH);
      	h_TTH->Write();

      	TString h_name_WZ = "x_WZ_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_ZZ = "x_ZZ_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_EWK = "x_EWK_CMS_ttHl_"+lepEff_syst[i];
      
      	TH1F* h_EWK = (TH1F*)f_new->Get(h_name_WZ)->Clone();
      	h_EWK->Add( (TH1F*)f_new->Get(h_name_ZZ) );
      	h_EWK->SetNameTitle(h_name_EWK,h_name_EWK);
      	h_EWK->Write();

      	TString h_name_WWW = "x_WWW_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_WWZ = "x_WWZ_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_WZZ = "x_WZZ_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_ZZZ = "x_ZZZ_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_tZq = "x_tZq_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_TTTT = "x_TTTT_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_ttWW = "x_ttWW_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_WWss = "x_WWss_CMS_ttHl_"+lepEff_syst[i];
      	TString h_name_Rares = "x_Rares_CMS_ttHl_"+lepEff_syst[i];

      	TH1F* h_Rares = (TH1F*)f_new->Get(h_name_WWW)->Clone();
      	h_Rares->Add( (TH1F*)f_new->Get(h_name_WWZ) );
      	h_Rares->Add( (TH1F*)f_new->Get(h_name_WZZ) );
      	h_Rares->Add( (TH1F*)f_new->Get(h_name_ZZZ) );
      	h_Rares->Add( (TH1F*)f_new->Get(h_name_tZq) );
      	h_Rares->Add( (TH1F*)f_new->Get(h_name_TTTT) );
      	h_Rares->Add( (TH1F*)f_new->Get(h_name_WWss) );
      	h_Rares->Add( (TH1F*)f_new->Get(h_name_ttWW) );
      	h_Rares->SetNameTitle(h_name_Rares,h_name_Rares);
      	h_Rares->Write();
    }


    cout<<"OK syst lepEff tight"<<endl;
    
    
  }

  f_new->Close();
  return;

}



/*void datacard_maker_mvis_2lss1tau(){

  TString var="sqrt((recotauh_sel_e[0]+recotauh_sel_e[1])**2-(recotauh_sel_px[0]+recotauh_sel_px[1])**2-(recotauh_sel_py[0]+recotauh_sel_py[1])**2-(recotauh_sel_pz[0]+recotauh_sel_pz[1])**2)";

  
  int nbin = 20;
  float xmin = 0.;
  float xmax = 200.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_mvis_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file,true);


}

void datacard_maker_n_fakelep_2lss1tau(){

  TString var="n_recolep_fakeable";

  
  int nbin = 5;
  float xmin = 0.;
  float xmax = 5.;

  TString cut="1";

  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_n_fakelep_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}




void datacard_maker_n_fakeele_2lss1tau(){

  TString var="n_recoele_fakeable";

  
  int nbin = 5;
  float xmin = 0.;
  float xmax = 5.;

  TString cut="1";

  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_n_fakeele_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}



void datacard_maker_n_fakemu_2lss1tau(){

  TString var="n_recomu_fakeable";

  
  int nbin = 5;
  float xmin = 0.;
  float xmax = 5.;

  TString cut="1";

  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_n_fakemu_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}




void datacard_maker_n_faketau_2lss1tau(){

  TString var="n_recotauh";

  
  int nbin = 5;
  float xmin = 0.;
  float xmax = 5.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_n_faketau_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}



void datacard_maker_n_jet_2lss1tau(){

  TString var="n_recoPFJet";

  
  int nbin = 10;
  float xmin = 0.;
  float xmax = 10.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_n_jet_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}





void datacard_maker_n_jet_CSVloose_2lss1tau(){

  TString var="n_recoPFJet_btag_loose";

  
  int nbin = 6;
  float xmin = 0.;
  float xmax = 6.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_n_jet_CSVloose_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}





void datacard_maker_n_jet_CSVmedium_2lss1tau(){

  TString var="n_recoPFJet_btag_medium";

  
  int nbin = 5;
  float xmin = 0.;
  float xmax = 5.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_n_jet_CSVmedium_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}




void datacard_maker_ETmiss_2lss1tau(){

  TString var="PFMET";

  
  int nbin = 12;
  float xmin = 0.;
  float xmax = 300.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_ETmiss_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}






void datacard_maker_pT_lep_2lss1tau(){

  TString var="recolep_pt[0]";

  
  int nbin = 16;
  float xmin = 0.;
  float xmax = 200.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_pT_lep_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}




void datacard_maker_pT_mu_2lss1tau(){

  TString var="recolep_pt[0]";

  
  int nbin = 16;
  float xmin = 0.;
  float xmax = 200.;

  TString cut="abs(recolep_pdg[0])==13";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_pT_mu_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}




void datacard_maker_pT_ele_2lss1tau(){

  TString var="recolep_pt[0]";

  
  int nbin = 16;
  float xmin = 0.;
  float xmax = 200.;

  TString cut="abs(recolep_pdg[0])==11";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_pT_ele_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}




void datacard_maker_pT_tau1_2lss1tau(){


  TString var="recotauh_pt[0]";
  
  int nbin = 12;
  float xmin = 0.;
  float xmax = 120.;


  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_pT_tau1_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}


void datacard_maker_DM_tau1_2lss1tau(){


  TString var="recotauh_sel_decayMode[0]*(recotauh_sel_decayMode[0]<2) + 2*(recotauh_sel_decayMode[0]>=2)";
  
  int nbin = 5;
  float xmin = -1.5;
  float xmax = 3.5;

  TString cut = "1";

  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_DM_tau1_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}


void datacard_maker_pT_jet1_2lss1tau(){

  TString var="recoPFJet_pt[0]";

  int nbin = 16;
  float xmin = 0.;
  float xmax = 400.;

  TString cut="1";

  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_pT_jet1_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}


void datacard_maker_pT_jet2_2lss1tau(){

  TString var="recoPFJet_pt[1]";

  
  int nbin = 20;
  float xmin = 0.;
  float xmax = 200.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_pT_jet2_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}





void datacard_maker_pT_bjet1_2lss1tau(){

  TString var="recoPFJet_DeepCSVsort_pt[0]";

  
  int nbin = 25;
  float xmin = 0.;
  float xmax = 250.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_pT_bjet1_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}


void datacard_maker_pT_bjet2_2lss1tau(){

  TString var="recoPFJet_DeepCSVsort_pt[1]";

  
  int nbin = 25;
  float xmin = 0.;
  float xmax = 250.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_pT_bjet2_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}





void datacard_maker_CSV_jet1_2lss1tau(){

  TString var="recoPFJet_DeepCSVscore[0]";

  
  int nbin = 20;
  float xmin = 0.;
  float xmax = 1.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_DeepCSV_jet1_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}


void datacard_maker_CSV_jet2_2lss1tau(){

  TString var="recoPFJet_DeepCSVscore[1]";

  
  int nbin = 20;
  float xmin = 0.;
  float xmax = 1.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_DeepCSV_jet2_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}




void datacard_maker_mltau_2lss1tau(){

  TString var="min(sqrt((recolep_e[0]+recotauh_e[0])**2-(recolep_px[0]+recotauh_px[0])**2-(recolep_py[0]+recotauh_py[0])**2-(recolep_pz[0]+recotauh_pz[0])**2),sqrt((recolep_e[0]+recotauh_e[1])**2-(recolep_px[0]+recotauh_px[1])**2-(recolep_py[0]+recotauh_py[1])**2-(recolep_pz[0]+recotauh_pz[1])**2))";

  
  int nbin = 15;
  float xmin = 0.;
  float xmax = 150.;

  TString cut="1";

  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_mltau_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file);


}





void datacard_maker_nvtx_2lss1tau_syst(){

  TString var="npv";

  
  int nbin = 50;
  float xmin = 0.;
  float xmax = 50.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_nvtx_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file,true);


}
*/

/*void datacard_maker_BDT_2lss1tau(){

  //[0.0, 0.14, 0.18, 0.22, 0.28, 0.32, 0.35, 0.38, 0.43, 0.47, 0.53, 1.0]

  TString var="1*(MVA_2lss1tau>=0 && MVA_2lss1tau<0.14)+2*(MVA_2lss1tau>=0.14 && MVA_2lss1tau<0.18)+3*(MVA_2lss1tau>=0.18 && MVA_2lss1tau<0.22)+4*(MVA_2lss1tau>=0.22 && MVA_2lss1tau<0.28)+5*(MVA_2lss1tau>=0.28 && MVA_2lss1tau<0.32)+6*(MVA_2lss1tau>=0.32 && MVA_2lss1tau<0.35)+7*(MVA_2lss1tau>=0.35 && MVA_2lss1tau<0.38)+8*(MVA_2lss1tau>=0.38 && MVA_2lss1tau<0.43)+9*(MVA_2lss1tau>=0.43 && MVA_2lss1tau<0.47)+10*(MVA_2lss1tau>=0.47 && MVA_2lss1tau<0.53)+11*(MVA_2lss1tau>=0.53 && MVA_2lss1tau<=1.0) ";
 

  int nbin = 11;
  float xmin = 1.;
  float xmax = 12.;

  TString cut="1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_BDT_2lss1tau_"+antiEle_WP+"_7nov18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file,true);


}*/

void datacard_maker_MEM_2lSS_nomiss(){

  TString var="Integral_ttH/(Integral_ttH+1e-18*(Integral_ttbar_DL_fakelep_tlep+Integral_ttbar_DL_fakelep_ttau)+1e-1*Integral_ttZ+2e-1*Integral_ttZ_Zll)";

  
  int nbin = 10;
  float xmin = 0.;
  float xmax = 1.;

  TString cut = "integration_type==0";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_MEM_2lss1tau_nomiss_7dec18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file,true);


}

void datacard_maker_MEM_2lSS_missing(){

  TString var="Integral_ttH/(Integral_ttH+5e-15*(Integral_ttbar_DL_fakelep_tlep+Integral_ttbar_DL_fakelep_ttau)+5e-2*Integral_ttZ+5e-1*Integral_ttZ_Zll)";
  
  int nbin = 10;
  float xmin = 0.;
  float xmax = 1.;

  TString cut = "integration_type==1";


  TString file="/data_CMS/cms/mperez/ttH_2017/datacards/2lss1tau/datacard_MEM_2lss1tau_miss_7dec18.root";


  datacard_maker(var,nbin,xmin,xmax,cut,file,true);


}






/*void datacard_maker_all(){

  datacard_maker_BDT_2lss1tau();
  
  datacard_maker_n_fakelep_2lss1tau();
  datacard_maker_n_fakeele_2lss1tau();
  datacard_maker_n_fakemu_2lss1tau();
  datacard_maker_n_faketau_2lss1tau();
  datacard_maker_n_jet_2lss1tau();
  datacard_maker_n_jet_CSVloose_2lss1tau();
  datacard_maker_n_jet_CSVmedium_2lss1tau();
  datacard_maker_ETmiss_2lss1tau();
  datacard_maker_pT_lep_2lss1tau();
  datacard_maker_pT_tau1_2lss1tau();
  datacard_maker_pT_jet1_2lss1tau();
  datacard_maker_pT_jet2_2lss1tau();
  datacard_maker_CSV_jet1_2lss1tau();
  datacard_maker_CSV_jet2_2lss1tau();
  datacard_maker_pT_bjet1_2lss1tau();
  datacard_maker_pT_bjet2_2lss1tau();

}*/
