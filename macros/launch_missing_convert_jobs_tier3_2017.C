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

    TString ScriptName1 = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_17.sh");
    ofstream myscript1;
    myscript1.open (ScriptName1.Data());
    myscript1 << "#!/bin/bash\n";
    myscript1 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript1 << "eval `scramv1 runtime -sh`\n";
    myscript1 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript1 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript1 << "root -b -l <<EOF\n";
    myscript1 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript1 << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,17,false);\n";
    myscript1 << ".q\n";
    myscript1 << "EOF\n";
    myscript1.close();  

    TString ScriptName2 = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_18.sh");
    ofstream myscript2;
    myscript2.open (ScriptName2.Data());
    myscript2 << "#!/bin/bash\n";
    myscript2 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript2 << "eval `scramv1 runtime -sh`\n";
    myscript2 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript2 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript2 << "root -b -l <<EOF\n";
    myscript2 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript2 << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,18,false);\n";
    myscript2 << ".q\n";
    myscript2 << "EOF\n";
    myscript2.close();

    TString ScriptName3 = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_20.sh");
    ofstream myscript3;
    myscript3.open (ScriptName3.Data());
    myscript3 << "#!/bin/bash\n";
    myscript3 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript3 << "eval `scramv1 runtime -sh`\n";
    myscript3 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript3 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript3 << "root -b -l <<EOF\n";
    myscript3 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript3 << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,20,false);\n";
    myscript3 << ".q\n";
    myscript3 << "EOF\n";
    myscript3.close(); 

    TString ScriptName4 = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_21.sh");
    ofstream myscript4;
    myscript4.open (ScriptName4.Data());
    myscript4 << "#!/bin/bash\n";
    myscript4 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript4 << "eval `scramv1 runtime -sh`\n";
    myscript4 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript4 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript4 << "root -b -l <<EOF\n";
    myscript4 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript4 << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,21,false);\n";
    myscript4 << ".q\n";
    myscript4 << "EOF\n";
    myscript4.close();  

    TString ScriptName5 = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_22.sh");
    ofstream myscript5;
    myscript5.open (ScriptName5.Data());
    myscript5 << "#!/bin/bash\n";
    myscript5 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript5 << "eval `scramv1 runtime -sh`\n";
    myscript5 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript5 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript5 << "root -b -l <<EOF\n";
    myscript5 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript5 << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,22,false);\n";
    myscript5 << ".q\n";
    myscript5 << "EOF\n";
    myscript5.close(); 

    TString ScriptName6 = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_23.sh");
    ofstream myscript6;
    myscript6.open (ScriptName6.Data());
    myscript6 << "#!/bin/bash\n";
    myscript6 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript6 << "eval `scramv1 runtime -sh`\n";
    myscript6 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript6 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript6 << "root -b -l <<EOF\n";
    myscript6 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript6 << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,23,false);\n";
    myscript6 << ".q\n";
    myscript6 << "EOF\n";
    myscript6.close(); 

    TString ScriptName7 = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_24.sh");
    ofstream myscript7;
    myscript7.open (ScriptName7.Data());
    myscript7 << "#!/bin/bash\n";
    myscript7 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript7 << "eval `scramv1 runtime -sh`\n";
    myscript7 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript7 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript7 << "root -b -l <<EOF\n";
    myscript7 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript7 << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,24,false);\n";
    myscript7 << ".q\n";
    myscript7 << "EOF\n";
    myscript7.close(); 

    TString ScriptName8 = Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_25.sh");
    ofstream myscript8;
    myscript8.open (ScriptName8.Data());
    myscript8 << "#!/bin/bash\n";
    myscript8 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript8 << "eval `scramv1 runtime -sh`\n";
    myscript8 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript8 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript8 << "root -b -l <<EOF\n";
    myscript8 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript8 << "convert_tree(\"SingleEle_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,25,false);\n";
    myscript8 << ".q\n";
    myscript8 << "EOF\n";
    myscript8.close(); 


    TString ScriptName9 = Form("script_tier3_data/convert_DoubleMu_2017D_ICHEP18_4.sh");
    ofstream myscript9;
    myscript9.open (ScriptName9.Data());
    myscript9 << "#!/bin/bash\n";
    myscript9 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript9 << "eval `scramv1 runtime -sh`\n";
    myscript9 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript9 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript9 << "root -b -l <<EOF\n";
    myscript9 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript9 << "convert_tree(\"DoubleMu_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,4,false);\n";
    myscript9 << ".q\n";
    myscript9 << "EOF\n";
    myscript9.close(); 

    TString ScriptName10 = Form("script_tier3_data/convert_DoubleMu_2017D_ICHEP18_5.sh");
    ofstream myscript10;
    myscript10.open (ScriptName10.Data());
    myscript10 << "#!/bin/bash\n";
    myscript10 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript10 << "eval `scramv1 runtime -sh`\n";
    myscript10 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript10 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript10 << "root -b -l <<EOF\n";
    myscript10 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript10 << "convert_tree(\"DoubleMu_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,5,false);\n";
    myscript10 << ".q\n";
    myscript10 << "EOF\n";
    myscript10.close(); 

    TString ScriptName11 = Form("script_tier3_data/convert_DoubleMu_2017D_ICHEP18_6.sh");
    ofstream myscript11;
    myscript11.open (ScriptName11.Data());
    myscript11 << "#!/bin/bash\n";
    myscript11 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript11 << "eval `scramv1 runtime -sh`\n";
    myscript11 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript11 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript11 << "root -b -l <<EOF\n";
    myscript11 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript11 << "convert_tree(\"DoubleMu_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,6,false);\n";
    myscript11 << ".q\n";
    myscript11 << "EOF\n";
    myscript11.close(); 

    TString ScriptName12 = Form("script_tier3_data/convert_DoubleEG_2017D_ICHEP18_2.sh");
    ofstream myscript12;
    myscript12.open (ScriptName12.Data());
    myscript12 << "#!/bin/bash\n";
    myscript12 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript12 << "eval `scramv1 runtime -sh`\n";
    myscript12 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript12 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript12 << "root -b -l <<EOF\n";
    myscript12 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript12 << "convert_tree(\"DoubleEG_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,2,false);\n";
    myscript12 << ".q\n";
    myscript12 << "EOF\n";
    myscript12.close(); 

    TString ScriptName13 = Form("script_tier3_data/convert_DoubleEG_2017D_ICHEP18_8.sh");
    ofstream myscript13;
    myscript13.open (ScriptName13.Data());
    myscript13 << "#!/bin/bash\n";
    myscript13 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript13 << "eval `scramv1 runtime -sh`\n";
    myscript13 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript13 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript13 << "root -b -l <<EOF\n";
    myscript13 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript13 << "convert_tree(\"DoubleEG_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,8,false);\n";
    myscript13 << ".q\n";
    myscript13 << "EOF\n";
    myscript13.close(); 

    TString ScriptName14 = Form("script_tier3_data/convert_DoubleEG_2017D_ICHEP18_9.sh");
    ofstream myscript14;
    myscript14.open (ScriptName14.Data());
    myscript14 << "#!/bin/bash\n";
    myscript14 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript14 << "eval `scramv1 runtime -sh`\n";
    myscript14 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript14 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript14 << "root -b -l <<EOF\n";
    myscript14 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript14 << "convert_tree(\"DoubleEG_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,9,false);\n";
    myscript14 << ".q\n";
    myscript14 << "EOF\n";
    myscript14.close(); 


    TString ScriptName15 = Form("script_tier3_data/convert_MuonEG_2017D_ICHEP18_3.sh");
    ofstream myscript15;
    myscript15.open (ScriptName15.Data());
    myscript15 << "#!/bin/bash\n";
    myscript15 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript15 << "eval `scramv1 runtime -sh`\n";
    myscript15 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript15 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript15 << "root -b -l <<EOF\n";
    myscript15 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript15 << "convert_tree(\"MuonEG_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,3,false);\n";
    myscript15 << ".q\n";
    myscript15 << "EOF\n";
    myscript15.close(); 

    TString ScriptName16 = Form("script_tier3_data/convert_MuonEG_2017D_ICHEP18_4.sh");
    ofstream myscript16;
    myscript16.open (ScriptName16.Data());
    myscript16 << "#!/bin/bash\n";
    myscript16 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript16 << "eval `scramv1 runtime -sh`\n";
    myscript16 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript16 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript16 << "root -b -l <<EOF\n";
    myscript16 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript16 << "convert_tree(\"MuonEG_2017D_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,4,false);\n";
    myscript16 << ".q\n";
    myscript16 << "EOF\n";
    myscript16.close();

    TString ScriptName17 = Form("script_tier3_data/convert_SingleMu_2017E_ICHEP18_1.sh");
    ofstream myscript17;
    myscript17.open (ScriptName17.Data());
    myscript17 << "#!/bin/bash\n";
    myscript17 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript17 << "eval `scramv1 runtime -sh`\n";
    myscript17 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript17 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript17 << "root -b -l <<EOF\n";
    myscript17 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript17 << "convert_tree(\"SingleMu_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,1,false);\n";
    myscript17 << ".q\n";
    myscript17 << "EOF\n";
    myscript17.close();

    TString ScriptName18 = Form("script_tier3_data/convert_SingleMu_2017E_ICHEP18_58.sh");
    ofstream myscript18;
    myscript18.open (ScriptName18.Data());
    myscript18 << "#!/bin/bash\n";
    myscript18 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript18 << "eval `scramv1 runtime -sh`\n";
    myscript18 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript18 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript18 << "root -b -l <<EOF\n";
    myscript18 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript18 << "convert_tree(\"SingleMu_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,58,false);\n";
    myscript18 << ".q\n";
    myscript18 << "EOF\n";
    myscript18.close();

    TString ScriptName19 = Form("script_tier3_data/convert_SingleMu_2017E_ICHEP18_81.sh");
    ofstream myscript19;
    myscript19.open (ScriptName19.Data());
    myscript19 << "#!/bin/bash\n";
    myscript19 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript19 << "eval `scramv1 runtime -sh`\n";
    myscript19 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript19 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript19 << "root -b -l <<EOF\n";
    myscript19 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript19 << "convert_tree(\"SingleMu_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,81,false);\n";
    myscript19 << ".q\n";
    myscript19 << "EOF\n";
    myscript19.close();

    TString ScriptName20 = Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_20.sh");
    ofstream myscript20;
    myscript20.open (ScriptName20.Data());
    myscript20 << "#!/bin/bash\n";
    myscript20 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript20 << "eval `scramv1 runtime -sh`\n";
    myscript20 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript20 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript20 << "root -b -l <<EOF\n";
    myscript20 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript20 << "convert_tree(\"SingleEle_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,20,false);\n";
    myscript20 << ".q\n";
    myscript20 << "EOF\n";
    myscript20.close();

    TString ScriptName21 = Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_21.sh");
    ofstream myscript21;
    myscript21.open (ScriptName21.Data());
    myscript21 << "#!/bin/bash\n";
    myscript21 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript21 << "eval `scramv1 runtime -sh`\n";
    myscript21 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript21 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript21 << "root -b -l <<EOF\n";
    myscript21 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript21 << "convert_tree(\"SingleEle_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,21,false);\n";
    myscript21 << ".q\n";
    myscript21 << "EOF\n";
    myscript21.close();  

    TString ScriptName22 = Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_22.sh");
    ofstream myscript22;
    myscript22.open (ScriptName22.Data());
    myscript22 << "#!/bin/bash\n";
    myscript22 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript22 << "eval `scramv1 runtime -sh`\n";
    myscript22 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript22 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript22 << "root -b -l <<EOF\n";
    myscript22 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript22 << "convert_tree(\"SingleEle_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,22,false);\n";
    myscript22 << ".q\n";
    myscript22 << "EOF\n";
    myscript22.close();

    TString ScriptName23 = Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_23.sh");
    ofstream myscript23;
    myscript23.open (ScriptName23.Data());
    myscript23 << "#!/bin/bash\n";
    myscript23 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript23 << "eval `scramv1 runtime -sh`\n";
    myscript23 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript23 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript23 << "root -b -l <<EOF\n";
    myscript23 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript23 << "convert_tree(\"SingleEle_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,23,false);\n";
    myscript23 << ".q\n";
    myscript23 << "EOF\n";
    myscript23.close();

    TString ScriptName24 = Form("script_tier3_data/convert_DoubleEG_2017E_ICHEP18_0.sh");
    ofstream myscript24;
    myscript24.open (ScriptName24.Data());
    myscript24 << "#!/bin/bash\n";
    myscript24 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript24 << "eval `scramv1 runtime -sh`\n";
    myscript24 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript24 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript24 << "root -b -l <<EOF\n";
    myscript24 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript24 << "convert_tree(\"DoubleEG_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,0,false);\n";
    myscript24 << ".q\n";
    myscript24 << "EOF\n";
    myscript24.close();

    TString ScriptName25 = Form("script_tier3_data/convert_DoubleEG_2017E_ICHEP18_20.sh");
    ofstream myscript25;
    myscript25.open (ScriptName25.Data());
    myscript25 << "#!/bin/bash\n";
    myscript25 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript25 << "eval `scramv1 runtime -sh`\n";
    myscript25 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript25 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript25 << "root -b -l <<EOF\n";
    myscript25 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript25 << "convert_tree(\"DoubleEG_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,20,false);\n";
    myscript25 << ".q\n";
    myscript25 << "EOF\n";
    myscript25.close();

    TString ScriptName26 = Form("script_tier3_data/convert_DoubleEG_2017E_ICHEP18_21.sh");
    ofstream myscript26;
    myscript26.open (ScriptName26.Data());
    myscript26 << "#!/bin/bash\n";
    myscript26 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript26 << "eval `scramv1 runtime -sh`\n";
    myscript26 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript26 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript26 << "root -b -l <<EOF\n";
    myscript26 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript26 << "convert_tree(\"DoubleEG_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,21,false);\n";
    myscript26 << ".q\n";
    myscript26 << "EOF\n";
    myscript26.close();

    TString ScriptName27 = Form("script_tier3_data/convert_DoubleMu_2017E_ICHEP18_11.sh");
    ofstream myscript27;
    myscript27.open (ScriptName27.Data());
    myscript27 << "#!/bin/bash\n";
    myscript27 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript27 << "eval `scramv1 runtime -sh`\n";
    myscript27 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript27 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript27 << "root -b -l <<EOF\n";
    myscript27 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript27 << "convert_tree(\"DoubleMu_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,11,false);\n";
    myscript27 << ".q\n";
    myscript27 << "EOF\n";
    myscript27.close();

    TString ScriptName28 = Form("script_tier3_data/convert_DoubleMu_2017E_ICHEP18_15.sh");
    ofstream myscript28;
    myscript28.open (ScriptName28.Data());
    myscript28 << "#!/bin/bash\n";
    myscript28 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript28 << "eval `scramv1 runtime -sh`\n";
    myscript28 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript28 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript28 << "root -b -l <<EOF\n";
    myscript28 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript28 << "convert_tree(\"DoubleMu_2017E_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,15,false);\n";
    myscript28 << ".q\n";
    myscript28 << "EOF\n";
    myscript28.close();

    for(unsigned int j=5;j<10;j++){

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

    for(unsigned int j=21;j<28;j++){

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

    for(unsigned int j=34;j<36;j++){

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

    TString ScriptName29 = Form("script_tier3_data/convert_DoubleMu_2017F_ICHEP18_37.sh");
    ofstream myscript29;
    myscript29.open (ScriptName29.Data());
    myscript29 << "#!/bin/bash\n";
    myscript29 << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript29 << "eval `scramv1 runtime -sh`\n";
    myscript29 << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript29 << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript29 << "root -b -l <<EOF\n";
    myscript29 << ".L Helpers_convert_ttH_2017_v6.C+\n";
    myscript29 << "convert_tree(\"DoubleMu_2017F_ICHEP18\",0,\"byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017\",true,0,37,false);\n";
    myscript29 << ".q\n";
    myscript29 << "EOF\n";
    myscript29.close();

    for(unsigned int j=12;j<17;j++){

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

}


void launch_scripts(){

    TString LaunchExec1 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec1 += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_17.sh");
    gSystem->Exec(LaunchExec1.Data());

    TString LaunchExec2 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec2 += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_18.sh");
    gSystem->Exec(LaunchExec2.Data());

    TString LaunchExec3 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec3 += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_20.sh");
    gSystem->Exec(LaunchExec3.Data());

    TString LaunchExec4 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec4 += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_21.sh");
    gSystem->Exec(LaunchExec4.Data());

    TString LaunchExec5 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec5 += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_22.sh");
    gSystem->Exec(LaunchExec5.Data());

    TString LaunchExec6 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec6 += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_23.sh");
    gSystem->Exec(LaunchExec6.Data());

    TString LaunchExec7 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec7 += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_24.sh");
    gSystem->Exec(LaunchExec7.Data());

    TString LaunchExec8 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec8 += Form("script_tier3_data/convert_SingleEle_2017D_ICHEP18_25.sh");
    gSystem->Exec(LaunchExec8.Data());

    TString LaunchExec9 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec9 += Form("script_tier3_data/convert_DoubleMu_2017D_ICHEP18_4.sh");
    gSystem->Exec(LaunchExec9.Data());

    TString LaunchExec10 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec10 += Form("script_tier3_data/convert_DoubleMu_2017D_ICHEP18_5.sh");
    gSystem->Exec(LaunchExec10.Data());

    TString LaunchExec11 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec11 += Form("script_tier3_data/convert_DoubleMu_2017D_ICHEP18_6.sh");
    gSystem->Exec(LaunchExec11.Data());

    TString LaunchExec29 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec29 += Form("script_tier3_data/convert_DoubleEG_2017D_ICHEP18_2.sh");
    gSystem->Exec(LaunchExec29.Data());

    TString LaunchExec12 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec12 += Form("script_tier3_data/convert_DoubleEG_2017D_ICHEP18_8.sh");
    gSystem->Exec(LaunchExec12.Data());

    TString LaunchExec13 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec13 += Form("script_tier3_data/convert_DoubleEG_2017D_ICHEP18_9.sh");
    gSystem->Exec(LaunchExec13.Data());

    TString LaunchExec14 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec14 += Form("script_tier3_data/convert_MuonEG_2017D_ICHEP18_3.sh");
    gSystem->Exec(LaunchExec14.Data());

    TString LaunchExec15 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec15 += Form("script_tier3_data/convert_MuonEG_2017D_ICHEP18_4.sh");
    gSystem->Exec(LaunchExec15.Data());

    TString LaunchExec16 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec16 += Form("script_tier3_data/convert_SingleMu_2017E_ICHEP18_1.sh");
    gSystem->Exec(LaunchExec16.Data());

    TString LaunchExec17 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec17 += Form("script_tier3_data/convert_SingleMu_2017E_ICHEP18_58.sh");
    gSystem->Exec(LaunchExec17.Data());

    TString LaunchExec18 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec18 += Form("script_tier3_data/convert_SingleMu_2017E_ICHEP18_81.sh");
    gSystem->Exec(LaunchExec18.Data());

    TString LaunchExec19 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec19 += Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_20.sh");
    gSystem->Exec(LaunchExec19.Data());

    TString LaunchExec20 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec20 += Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_21.sh");
    gSystem->Exec(LaunchExec20.Data());

    TString LaunchExec21 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec21 += Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_22.sh");
    gSystem->Exec(LaunchExec21.Data());

    TString LaunchExec22 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec22 += Form("script_tier3_data/convert_SingleEle_2017E_ICHEP18_23.sh");
    gSystem->Exec(LaunchExec22.Data());

    TString LaunchExec23 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec23 += Form("script_tier3_data/convert_DoubleEG_2017E_ICHEP18_0.sh");
    gSystem->Exec(LaunchExec23.Data());

    TString LaunchExec24 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec24 += Form("script_tier3_data/convert_DoubleEG_2017E_ICHEP18_20.sh");
    gSystem->Exec(LaunchExec24.Data());

    TString LaunchExec25 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec25 += Form("script_tier3_data/convert_DoubleEG_2017E_ICHEP18_21.sh");
    gSystem->Exec(LaunchExec25.Data());

    TString LaunchExec26 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec26 += Form("script_tier3_data/convert_DoubleMu_2017E_ICHEP18_11.sh");
    gSystem->Exec(LaunchExec26.Data());

    TString LaunchExec27 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec27 += Form("script_tier3_data/convert_DoubleMu_2017E_ICHEP18_15.sh");
    gSystem->Exec(LaunchExec27.Data());

    for(unsigned int j=5;j<10;j++){
    
        TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
        LaunchExec += Form("script_tier3_data/convert_DoubleMu_2017F_ICHEP18_%i.sh",j);
        gSystem->Exec(LaunchExec.Data());       
    }

    for(unsigned int j=21;j<28;j++){
    
        TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
        LaunchExec += Form("script_tier3_data/convert_DoubleMu_2017F_ICHEP18_%i.sh",j);
        gSystem->Exec(LaunchExec.Data());       
    }

    for(unsigned int j=34;j<36;j++){
    
        TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
        LaunchExec += Form("script_tier3_data/convert_DoubleMu_2017F_ICHEP18_%i.sh",j);
        gSystem->Exec(LaunchExec.Data());       
    }

    TString LaunchExec28 = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec28 += Form("script_tier3_data/convert_DoubleMu_2017F_ICHEP18_37.sh");
    gSystem->Exec(LaunchExec28.Data()); 

    for(unsigned int j=12;j<17;j++){
    
        TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
        LaunchExec += Form("script_tier3_data/convert_MuonEG_2017F_ICHEP18_%i.sh",j);
        gSystem->Exec(LaunchExec.Data());       
    }         

}
