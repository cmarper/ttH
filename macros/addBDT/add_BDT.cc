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

#include "add_BDT_1l2tau.cc"
#include "add_BDT_2lss1tau.cc"
#include "add_BDT_2l2tau.cc"
#include "add_BDT_3l1tau.cc"



int main(){
   
  std::vector<string> treename;
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
  //treename.push_back("HTauTauTree_3l_ttZ_lepMVA_CR");
  treename.push_back("HTauTauTree_1l_2tau");
  treename.push_back("HTauTauTree_1l_2tau_fake_CR");
  treename.push_back("HTauTauTree_1l_2tau_2jet_CR");
  treename.push_back("HTauTauTree_2l_2tau");
  treename.push_back("HTauTauTree_2l_2tau_fake_CR");

  string file = "/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split";

  add_BDT_1l2tau(file+".root",file+"_BDT_1l2tau.root",treename);
  add_BDT_2lss1tau(file+".root",file+"_BDT_2lss1tau.root",treename);
  add_BDT_2l2tau(file+".root",file+"_BDT_2l2tau.root",treename);
  add_BDT_3l1tau(file+".root",file+"_BDT_3l1tau.root",treename);
  

  return 0;

}
