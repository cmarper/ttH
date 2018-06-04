#include <assert.h>
#include "TH2F.h"
#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TH2Poly.h"


TFile *_file_recoToLoose_leptonSF_mu1 = NULL;
TFile *_file_recoToLoose_leptonSF_mu2 = NULL;
TFile *_file_recoToLoose_leptonSF_mu3 = NULL;
TFile *_file_recoToLoose_leptonSF_mu4 = NULL;
TH2F *_histo_recoToLoose_leptonSF_mu1 = NULL;
TH2F *_histo_recoToLoose_leptonSF_mu2 = NULL;
TH2F *_histo_recoToLoose_leptonSF_mu3 = NULL;
TGraphAsymmErrors *_histo_recoToLoose_leptonSF_mu4 = NULL;
TFile *_file_recoToLoose_leptonSF_el = NULL;
TH2F *_histo_recoToLoose_leptonSF_el1 = NULL;
TH2F *_histo_recoToLoose_leptonSF_el2 = NULL;
TH2F *_histo_recoToLoose_leptonSF_el3 = NULL;
TFile *_file_recoToLoose_leptonSF_gsf = NULL;
TH2F *_histo_recoToLoose_leptonSF_gsf = NULL;

float _get_recoToLoose_leptonSF_ttH(int pdgid, float pt, float eta, int nlep, float var){

  // nlep is ignored for the loose selection

  if (!_histo_recoToLoose_leptonSF_mu1) {
    _file_recoToLoose_leptonSF_mu1 = new TFile("lepSF/RunBCDEF_SF_ID.root","read");
    _file_recoToLoose_leptonSF_mu2 = new TFile("lepSF/scaleFactors_mu_DxyDzSip8mIso04_over_LooseID.root","read");
    //    _file_recoToLoose_leptonSF_mu3 = new TFile("lepSF/TnP_NUM_TightIP2D_DENOM_MediumID_VAR_map_pt_eta.root","read");
    _file_recoToLoose_leptonSF_mu4 = new TFile("lepSF/fits_mu_trkEffSF_2017_allTracks.root","read");
    _histo_recoToLoose_leptonSF_mu1 = (TH2F*)(_file_recoToLoose_leptonSF_mu1->Get("NUM_LooseID_DEN_genTracks_pt_abseta"));
    _histo_recoToLoose_leptonSF_mu2 = (TH2F*)(_file_recoToLoose_leptonSF_mu2->Get("NUM_ttHLoo_DEN_LooseID"));
    //    _histo_recoToLoose_leptonSF_mu3 = (TH2F*)(_file_recoToLoose_leptonSF_mu3->Get("SF")); # SCOMMENTARE SOTTO
    _histo_recoToLoose_leptonSF_mu4 = (TGraphAsymmErrors*)(_file_recoToLoose_leptonSF_mu4->Get("ratio_eff_eta3_dr030e030_corr"));
  }
  if (!_histo_recoToLoose_leptonSF_el1) {
//    _file_recoToLoose_leptonSF_el = new TFile("lepSF/el_scaleFactors_Moriond17.root","read");
//    _histo_recoToLoose_leptonSF_el1 = (TH2F*)(_file_recoToLoose_leptonSF_el->Get("GsfElectronToMVAVLooseFOIDEmuTightIP2D"));
//    _histo_recoToLoose_leptonSF_el2 = (TH2F*)(_file_recoToLoose_leptonSF_el->Get("MVAVLooseElectronToMini4"));
//    _histo_recoToLoose_leptonSF_el3 = (TH2F*)(_file_recoToLoose_leptonSF_el->Get("MVAVLooseElectronToConvVetoIHit1"));
  }
  if (!_histo_recoToLoose_leptonSF_gsf) {
//    _file_recoToLoose_leptonSF_gsf = new TFile("lepSF/egammaEffi.txt_EGM2D.root","read");
//    _histo_recoToLoose_leptonSF_gsf = (TH2F*)(_file_recoToLoose_leptonSF_gsf->Get("EGamma_SF2D"));
  }

  if (abs(pdgid)==13){

    // var is ignored for muons (handled in systsEnv.txt)

    float out = 1;

    TH2F *hist = _histo_recoToLoose_leptonSF_mu1;
    int ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
    int etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(fabs(eta))));
    out *= hist->GetBinContent(ptbin,etabin);

    if (_histo_recoToLoose_leptonSF_mu2){
    hist = _histo_recoToLoose_leptonSF_mu2;
    ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
    etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(fabs(eta))));
    out *= hist->GetBinContent(ptbin,etabin);
    }

    if (_histo_recoToLoose_leptonSF_mu3){
    hist = _histo_recoToLoose_leptonSF_mu3;
    ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
    etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(fabs(eta))));
    out *= hist->GetBinContent(ptbin,etabin);
    }

    TGraphAsymmErrors *hist1 = _histo_recoToLoose_leptonSF_mu4;
    float eta1 = std::max(float(hist1->GetXaxis()->GetXmin()+1e-5), std::min(float(hist1->GetXaxis()->GetXmax()-1e-5), eta));
    out *= hist1->Eval(eta1);

    return out;

  }

  if (abs(pdgid)==11){
    TH2F *hist = NULL;
    float out = 1;
    int ptbin, etabin;
    if (_histo_recoToLoose_leptonSF_el1){
    hist = _histo_recoToLoose_leptonSF_el1;
    ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
    etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(eta)));
    out *= hist->GetBinContent(ptbin,etabin)+var*hist->GetBinError(ptbin,etabin);
    }
    if (_histo_recoToLoose_leptonSF_el2){
    hist = _histo_recoToLoose_leptonSF_el2;
    ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
    etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(eta)));
    out *= hist->GetBinContent(ptbin,etabin)+var*hist->GetBinError(ptbin,etabin);
    }
    if (_histo_recoToLoose_leptonSF_el3){
    hist = _histo_recoToLoose_leptonSF_el3;
    ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
    etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(eta)));
    out *= hist->GetBinContent(ptbin,etabin)+var*hist->GetBinError(ptbin,etabin);
    }
    if (_histo_recoToLoose_leptonSF_gsf){
    hist = _histo_recoToLoose_leptonSF_gsf;
    etabin = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(eta))); // careful, different convention
    ptbin  = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(pt)));
    out *= (hist->GetBinContent(etabin,ptbin)+var*(hist->GetBinError(ptbin,etabin) + 0.01*((pt<20) || (pt>80))));
    }

    return out;
  }

  std::cout << "ERROR" << std::endl;
  std::abort();
  return 1;

}

TFile *_file_looseToTight_leptonSF_mu_2lss = NULL;
TH2F *_histo_looseToTight_leptonSF_mu_2lss = NULL;
TFile *_file_looseToTight_leptonSF_el_2lss = NULL;
TH2F *_histo_looseToTight_leptonSF_el_2lss = NULL;
TFile *_file_looseToTight_leptonSF_mu_3l = NULL;
TH2F *_histo_looseToTight_leptonSF_mu_3l = NULL;
TFile *_file_looseToTight_leptonSF_el_3l = NULL;
TH2F *_histo_looseToTight_leptonSF_el_3l = NULL;

float _get_looseToTight_leptonSF_ttH(int pdgid, float pt, float eta, int nlep, float var){

  // var is ignored in all cases (systematics handled in systsEnv.txt)

  if (!_histo_looseToTight_leptonSF_mu_2lss) {
    _file_looseToTight_leptonSF_mu_2lss = new TFile("lepSF/lepMVAEffSF_m_2lss.root","read");
    _histo_looseToTight_leptonSF_mu_2lss = (TH2F*)(_file_looseToTight_leptonSF_mu_2lss->Get("sf"));
  }
  if (!_histo_looseToTight_leptonSF_el_2lss) {
    _file_looseToTight_leptonSF_el_2lss = new TFile("lepSF/lepMVAEffSF_e_2lss.root","read");
    _histo_looseToTight_leptonSF_el_2lss = (TH2F*)(_file_looseToTight_leptonSF_el_2lss->Get("sf"));
  }
  if (!_histo_looseToTight_leptonSF_mu_3l) {
    _file_looseToTight_leptonSF_mu_3l = new TFile("lepSF/lepMVAEffSF_m_3l.root","read");
    _histo_looseToTight_leptonSF_mu_3l = (TH2F*)(_file_looseToTight_leptonSF_mu_3l->Get("sf"));
  }
  if (!_histo_looseToTight_leptonSF_el_3l) {
    _file_looseToTight_leptonSF_el_3l = new TFile("lepSF/lepMVAEffSF_e_3l.root","read");
    _histo_looseToTight_leptonSF_el_3l = (TH2F*)(_file_looseToTight_leptonSF_el_3l->Get("sf"));
  }

  TH2F *hist = 0;
  if (abs(pdgid)==13) hist = (nlep>2) ? _histo_looseToTight_leptonSF_mu_3l : _histo_looseToTight_leptonSF_mu_2lss;
  else if (abs(pdgid)==11) hist = (nlep>2) ? _histo_looseToTight_leptonSF_el_3l : _histo_looseToTight_leptonSF_el_2lss;
  if (!hist) {std::cout << "ERROR" << std::endl; std::abort();}
  int ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
  int etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(fabs(eta))));
  return hist->GetBinContent(ptbin,etabin);

}

float leptonSF_ttH(int pdgid, float pt, float eta, int nlep, float var=0){

  float recoToLoose = _get_recoToLoose_leptonSF_ttH(pdgid,pt,eta,nlep,var=0);
  float looseToTight = _get_looseToTight_leptonSF_ttH(pdgid,pt,eta,nlep,var);
  float res = recoToLoose*looseToTight;
  if (!(res>0)) {std::cout << "ERROR" << std::endl; std::abort();}
  return res;

}

//TFile *file_triggerSF_ttH = NULL;
//TH2Poly* t2poly_triggerSF_ttH_mm = NULL;
//TH2Poly* t2poly_triggerSF_ttH_ee = NULL;
//TH2Poly* t2poly_triggerSF_ttH_em = NULL;
//TH2Poly* t2poly_triggerSF_ttH_3l = NULL;

float triggerSF_ttH(int pdgid1, float pt1, int pdgid2, float pt2, int nlep, float shift = 0){

  if (nlep>=3) return 1.0+shift*0.05;

  int comb = abs(pdgid1)+abs(pdgid2);

  if (comb==22) return (pt1<30) ? (0.937+shift*0.027) : (0.991+shift*0.002); // ee
  else if (comb==24) { // em
    if (pt1<35) return 0.952+shift*0.008;
    else if (pt1<50) return 0.983+shift*0.003;
    else return 1.0+shift*0.001;
  }
  else if (comb==26) return (pt1<35) ? (0.972+shift*0.006) : (0.994+shift*0.001); // mm

  std::cout << "ERROR: triggerSF_ttH called with wrong input, returning 1" << std::endl;
  return 1;

}

//Trigger SF for 1l+2tau
TFile *file_triggerSF_ttH_e = NULL;
TFile *file_triggerSF_ttH_m = NULL;
TH2F* h_triggerSF_ttH_e = NULL;
TH2F* h_triggerSF_ttH_m = NULL;

float triggerSF_ttH_1l(int pdgid, float pt, float eta, float var=0){

  if (!(file_triggerSF_ttH_e && file_triggerSF_ttH_m)) {
    file_triggerSF_ttH_e = new TFile("lepSF/ElTriggerPerformance_Sep27.root");
    h_triggerSF_ttH_e = (TH2F*)(file_triggerSF_ttH_e->Get("electrontrig_sf_eta_pt"));
    file_triggerSF_ttH_m = new TFile("lepSF/MuonTriggerPerformance_Sep06.root");
    h_triggerSF_ttH_m = (TH2F*)(file_triggerSF_ttH_m->Get("muontrig_sf_abseta_pt"));

    if (!(h_triggerSF_ttH_e && h_triggerSF_ttH_m)) {
      std::cout << "Impossible to load trigger scale factors!" << std::endl;
      file_triggerSF_ttH_e->ls();
      file_triggerSF_ttH_e = NULL;
      file_triggerSF_ttH_m->ls();
      file_triggerSF_ttH_m = NULL;
    }
  }

  TH2F* hist = NULL;
  if (abs(pdgid)==13) hist = h_triggerSF_ttH_m;
  else if (abs(pdgid)==11) hist = h_triggerSF_ttH_e;

  float searchPt = TMath::Min(pt,float(499.0));
  float searchEta = eta;
  if(abs(pdgid)==13) searchEta = fabs(eta);
  int bin = hist->FindBin(searchEta, searchPt);
  float nomval = hist->GetBinContent(bin);
  float error = hist->GetBinError(bin);
  float SF = nomval + var*error;
  return SF;

}
