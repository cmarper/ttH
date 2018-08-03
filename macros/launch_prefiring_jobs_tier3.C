#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <iostream>
#include <map>
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TStyle.h>
#include <TROOT.h>
#include <sstream>
#include <TBranchElement.h>
#include <fstream>
#include <TROOT.h>
#include <TSystem.h>

using namespace std;



void create_scripts(){

/*  for(unsigned int j=0;j<11;j++){

     TString ScriptName = Form("script_tier3_MC_prefire/convert_ttHJet_Hnonbb_ICHEP18_%i_prefiring.sh",j);
     ofstream myscript;
     myscript.open (ScriptName.Data());
     myscript << "#!/bin/bash\n";
     myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
     myscript << "eval `scramv1 runtime -sh`\n";
     myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
     myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
     myscript << "root -b -l <<EOF\n";
     myscript << ".L Helpers_convert_ttH_2017_v8_withprefiring.C+\n";
     myscript << "convert_tree(\"ttHJet_Hnonbb_ICHEP18_prefiring\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
     myscript << ".q\n";
     myscript << "EOF\n";
     myscript.close();

  }
*/
  for(unsigned int j=0;j<11;j++){

     TString ScriptName = Form("script_tier3_MC_prefire/split_ttH_Hnonbb_ICHEP18_%i_prefiring.sh",j);
     ofstream myscript;
     myscript.open (ScriptName.Data());
     myscript << "#!/bin/bash\n";
     myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
     myscript << "eval `scramv1 runtime -sh`\n";
     myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
     myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
     myscript << "root -b -l <<EOF\n";
     myscript << ".L tree_splitter_2lSS_prefiring.C+\n";
     myscript << "split_tree_2lSS(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_ttH_Hnonbb_prefiring_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_prefiring_" << j << ".root\");\n";
     myscript << ".q\n";
     myscript << "EOF\n";
     myscript.close();   
  
   }

}



void launch_scripts(){

/*  for(unsigned int j=0;j<11;j++){
    
     TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
     LaunchExec += Form("script_tier3_MC_prefire/convert_ttHJet_Hnonbb_ICHEP18_%i_prefiring.sh",j);
     gSystem->Exec(LaunchExec.Data());
        
  }
*/ 

  for(unsigned int j=1;j<11;j++){
     
     TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
     LaunchExec += Form("script_tier3_MC_prefire/split_ttH_Hnonbb_ICHEP18_%i_prefiring.sh",j);
     gSystem->Exec(LaunchExec.Data());
       
  }

}
