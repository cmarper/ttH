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

/* 
 for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttHJet_Hnonbb_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttHJet_Hnonbb_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttHJet_Hnonbb_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttHJet_Hnonbb_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttHJet_Hnonbb_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

 
 /*for(unsigned int j=0;j<4;j++){. //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THQ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THQ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THQ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THQ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THQ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THQ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THQ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THQ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THQ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THQ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/


 /*for(unsigned int j=0;j<2;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<2;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THW_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<2;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THW_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<2;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THW_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<2;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_THW_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"THW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_lowmass_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_lowmass_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_lowmass_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_lowmass_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttZ_lowmass_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
  /*
  for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttW_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n"; 
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttW_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttW_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttW_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttWW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttWW_ICHEP2018\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttWW_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttWW_ICHEP2018\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttWW_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttWW_ICHEP2018\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttWW_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttWW_ICHEP2018\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttWW_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttWW_ICHEP2018\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
  
  /*for(unsigned int j=0;j<7;j++){ //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_ttbar_DL_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttbar_DL_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<25;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_ttbar_DL_ext_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttbar_DL_ext_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<13;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_ttbar_SLfromT_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttbar_SLfromT_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<49;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_ttbar_SLfromTbar_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttbar_SLfromTbar_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
 
  /*for(unsigned int j=0;j<6;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_WG_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WG_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<15;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_ZG_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZG_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
  
  /* for(unsigned int j=0;j<1;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_tG_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"tG_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
 /*
 for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttG_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttG_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttG_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttG_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttG_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttG_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttG_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttG_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ttG_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ttG_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
  
  /*for(unsigned int j=0;j<1;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_WpWp_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WpWp_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_WpWp_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WpWp_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_WpWp_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WpWp_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_WpWp_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WpWp_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_WpWp_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WpWp_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*  
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/
  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
 /*
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/
  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWW_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWW_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWW_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWW_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/
  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/
  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WWZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WWZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WW_DoubleScat_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WW_DoubleScat_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_WW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"WW_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/
  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC/convert_ZZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"ZZ_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<15;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_tZq_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"tZq_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<15;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_tZq_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"tZq_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<15;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_tZq_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"tZq_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<15;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_tZq_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"tZq_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<15;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_tZq_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"tZq_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
 for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_TTTT_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"TTTT_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_TTTT_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"TTTT_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_TTTT_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"TTTT_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_TTTT_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"TTTT_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,+1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

 /* for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC/convert_TTTT_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"TTTT_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true,0,-1);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  for(unsigned int j=0;j<36;j++){

    TString ScriptName = Form("script_tier3_MC/convert_TTLeptons_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"TTLeptons_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<57;j++){

    TString ScriptName = Form("script_tier3_MC/convert_TTSemileptonic_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"TTSemileptonic_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }
  
  /* for(unsigned int j=0;j<2;j++){  //FIXME

    TString ScriptName = Form("script_tier3_MC/convert_DYBJets_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DYBJets_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",true);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
  */

//***************//
//***************//
/*
  for(unsigned int j=0;j<19;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleEG_2017B_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleEG_2017B_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<31;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleEG_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleEG_2017C_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<13;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleEG_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleEG_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<28;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleEG_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleEG_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<38;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleEG_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleEG_2017F_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*//*
  for(unsigned int j=0;j<7;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleMu_2017B_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleMu_2017B_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<24;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleMu_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleMu_2017C_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<12;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleMu_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleMu_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<26;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleMu_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleMu_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<40;j++){

    TString ScriptName = Form("script_tier3_data/convert_DoubleMu_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"DoubleMu_2017F_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*//*
  for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_data/convert_MuonEG_2017B_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"MuonEG_2017B_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_data/convert_MuonEG_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"MuonEG_2017C_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_data/convert_MuonEG_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"MuonEG_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<10;j++){

    TString ScriptName = Form("script_tier3_data/convert_MuonEG_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"MuonEG_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<17;j++){

    TString ScriptName = Form("script_tier3_data/convert_MuonEG_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"MuonEG_2017F_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<74;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleMu_2017B_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleMu_2017B_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<83;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleMu_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleMu_2017C_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<37;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleMu_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleMu_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<83;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleMu_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleMu_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<85;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleMu_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleMu_2017F_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*//*
  for(unsigned int j=0;j<30;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleEle_2017B_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleEle_2017B_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/
/*
  for(unsigned int j=0;j<67;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleEle_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleEle_2017C_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<27;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<53;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleEle_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

 for(unsigned int j=0;j<67;j++){

    TString ScriptName = Form("script_tier3_data/convert_SingleEle_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript << "convert_tree(\"SingleEle_2017F_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,"<< j << ",false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/
}



void launch_scripts(){
       
/*
  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttHJet_Hnonbb_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
  /*for(unsigned int j=0;j<4;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THQ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THQ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THQ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THQ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THQ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }


  for(unsigned int j=0;j<2;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<2;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THW_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<2;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THW_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<2;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THW_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<2;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_THW_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }*/
/*
  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }*/
/*
  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttZ_lowmass_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }


  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttW_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttW_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttW_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttW_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttWW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttWW_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttWW_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttWW_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }


  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttWW_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttG_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttG_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttG_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttG_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ttG_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
  /*for(unsigned int j=0;j<1;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WpWp_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WpWp_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WpWp_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WpWp_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WpWp_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }
  */
/*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }*/
/*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*//*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }*/
/*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWW_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWW_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWW_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWW_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
   }
*//*
   for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }*/
/*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/ /*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }*/
/*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WWZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_tG_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WW_DoubleScat_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_WW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_ZZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
 */
 /*for(unsigned int j=0;j<15;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_tZq_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<15;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_tZq_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<15;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_tZq_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<15;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_tZq_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<15;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_tZq_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }*/
/*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_TTTT_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }*/
/*
  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_TTTT_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_TTTT_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_TTTT_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_TTTT_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
  */
  /*for(unsigned int j=0;j<2;j++){  //FIXME
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_DYBJets_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }*/

  for(unsigned int j=0;j<36;j++){  
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_TTLeptons_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<57;j++){  

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_MC/convert_TTSemileptonic_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

  }

  //***************//
  //***************//
/*
  for(unsigned int j=0;j<19;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleEG_2017B_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<31;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleEG_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<13;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleEG_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<28;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleEG_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<38;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleEG_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<7;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleMu_2017B_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<24;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleMu_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<12;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleMu_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<26;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleMu_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<40;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_DoubleMu_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }


  for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_MuonEG_2017B_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_MuonEG_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<5;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_MuonEG_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<10;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_MuonEG_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<17;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_MuonEG_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<74;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleMu_2017B_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<83;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleMu_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<37;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleMu_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<83;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleMu_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<85;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleMu_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<30;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleEle_2017B_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<67;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleEle_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<27;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<53;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }

  for(unsigned int j=0;j<67;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_data/convert_SingleEle_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
    
  }
*/
}
