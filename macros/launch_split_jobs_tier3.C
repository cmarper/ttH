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

  /*for(unsigned int j=0;j<11;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_ttH_Hnonbb_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_ttH_Hnonbb_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<11;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/ttH/ntuple_ttH_Hnonbb_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/ttH/HTauTauTree_ttH_Hnonbb_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<11;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/ttH/ntuple_ttH_Hnonbb_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/ttH/HTauTauTree_ttH_Hnonbb_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<11;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/ttH/ntuple_ttH_Hnonbb_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/ttH/HTauTauTree_ttH_Hnonbb_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<11;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/ttH/ntuple_ttH_Hnonbb_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/ttH/HTauTauTree_ttH_Hnonbb_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/
/*
  for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tHq_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_tHq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttH/HTauTauTree_tHq_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tHq_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/ttH/ntuple_tHq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/ttH/HTauTauTree_tHq_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tHq_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/ttH/ntuple_tHq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/ttH/HTauTauTree_tHq_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tHq_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/ttH/ntuple_tHq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/ttH/HTauTauTree_tHq_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tHq_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/ttH/ntuple_tHq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/ttH/HTauTauTree_tHq_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/
/*  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_ttZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/ttV/ntuple_ttZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/ttV/HTauTauTree_ttZ_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/ttV/ntuple_ttZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/ttV/HTauTauTree_ttZ_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/ttV/ntuple_ttZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/ttV/HTauTauTree_ttZ_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/ttV/ntuple_ttZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/ttV/HTauTauTree_ttZ_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_ttZ_lowmass_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttZ_lowmass_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }



    for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/ttV/ntuple_ttZ_lowmass_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/ttV/HTauTauTree_ttZ_lowmass_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/ttV/ntuple_ttZ_lowmass_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/ttV/HTauTauTree_ttZ_lowmass_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();  

  }


   for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/ttV/ntuple_ttZ_lowmass_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/ttV/HTauTauTree_ttZ_lowmass_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/ttV/ntuple_ttZ_lowmass_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/ttV/HTauTauTree_ttZ_lowmass_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_ttW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttW_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }
 
    for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttW_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/ttV/ntuple_ttW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/ttV/HTauTauTree_ttW_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttW_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/ttV/ntuple_ttW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/ttV/HTauTauTree_ttW_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttW_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/ttV/ntuple_ttW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/ttV/HTauTauTree_ttW_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttW_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/ttV/ntuple_ttW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/ttV/HTauTauTree_ttW_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

 */ 
  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttWW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_ttWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ttWW_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttWW_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/Rares/ntuple_ttWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/Rares/HTauTauTree_ttWW_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttWW_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/Rares/ntuple_ttWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/Rares/HTauTauTree_ttWW_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

   for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttWW_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/Rares/ntuple_ttWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/Rares/HTauTauTree_ttWW_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttWW_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/Rares/ntuple_ttWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/Rares/HTauTauTree_ttWW_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
/* 
  for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttG_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_ttG_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/ttV/HTauTauTree_ttG_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttG_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/ttV/ntuple_ttG_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/ttV/HTauTauTree_ttG_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttG_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/ttV/ntuple_ttG_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/ttV/HTauTauTree_ttG_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttG_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
   	 myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/ttV/ntuple_ttG_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/ttV/HTauTauTree_ttG_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ttG_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/ttV/ntuple_ttG_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/ttV/HTauTauTree_ttG_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<2;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/EWK/ntuple_WW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WW_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/EWK/ntuple_ZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_ZZ_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/EWK/ntuple_ZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/EWK/HTauTauTree_ZZ_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/EWK/ntuple_ZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/EWK/HTauTauTree_ZZ_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/EWK/ntuple_ZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/EWK/HTauTauTree_ZZ_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/EWK/ntuple_ZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/EWK/HTauTauTree_ZZ_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<12;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/EWK/ntuple_WZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/EWK/HTauTauTree_WZ_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

   for(unsigned int j=0;j<12;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/EWK/ntuple_WZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/EWK/HTauTauTree_WZ_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<12;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/EWK/ntuple_WZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/EWK/HTauTauTree_WZ_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<12;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/EWK/ntuple_WZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/EWK/HTauTauTree_WZ_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<12;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/EWK/ntuple_WZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/EWK/HTauTauTree_WZ_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }


  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WW_DoubleScat_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_WW_DoubleScat_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WW_DoubleScat_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }


  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWW_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_WWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWW_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWW_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/Rares/ntuple_WWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/Rares/HTauTauTree_WWW_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWW_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/Rares/ntuple_WWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/Rares/HTauTauTree_WWW_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWW_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/Rares/ntuple_WWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/Rares/HTauTauTree_WWW_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWW_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/Rares/ntuple_WWW_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/Rares/HTauTauTree_WWW_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_WWZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WWZ_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/Rares/ntuple_WWZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/Rares/HTauTauTree_WWZ_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/Rares/ntuple_WWZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/Rares/HTauTauTree_WWZ_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/Rares/ntuple_WWZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/Rares/HTauTauTree_WWZ_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WWZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/Rares/ntuple_WWZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/Rares/HTauTauTree_WWZ_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }


  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_WZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WZZ_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

    for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/Rares/ntuple_WZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/Rares/HTauTauTree_WZZ_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/Rares/ntuple_WZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/Rares/HTauTauTree_WZZ_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/Rares/ntuple_WZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/Rares/HTauTauTree_WZZ_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WZZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/Rares/ntuple_WZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/Rares/HTauTauTree_WZZ_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZZ_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_ZZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_ZZZ_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }
 
   for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZZ_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/Rares/ntuple_ZZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/Rares/HTauTauTree_ZZZ_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZZ_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/Rares/ntuple_ZZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/Rares/HTauTauTree_ZZZ_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZZ_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/Rares/ntuple_ZZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/Rares/HTauTauTree_ZZZ_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_ZZZ_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/Rares/ntuple_ZZZ_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/Rares/HTauTauTree_ZZZ_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }


  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WpWp_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_WpWp_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_WpWp_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WpWp_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/Rares/ntuple_WpWp_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/Rares/HTauTauTree_WpWp_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WpWp_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/Rares/ntuple_WpWp_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/Rares/HTauTauTree_WpWp_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WpWp_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/Rares/ntuple_WpWp_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/Rares/HTauTauTree_WpWp_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_WpWp_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/Rares/ntuple_WpWp_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/Rares/HTauTauTree_WpWp_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<2;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_TTTT_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_TTTT_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_TTTT_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<2;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_TTTT_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/Rares/ntuple_TTTT_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/Rares/HTauTauTree_TTTT_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<2;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_TTTT_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/Rares/ntuple_TTTT_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/Rares/HTauTauTree_TTTT_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<2;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_TTTT_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/Rares/ntuple_TTTT_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/Rares/HTauTauTree_TTTT_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<2;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_TTTT_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/Rares/ntuple_TTTT_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/Rares/HTauTauTree_TTTT_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<9;j++){ 

    TString ScriptName = Form("script_tier3_MC_split/split_TTLeptons_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/TT/ntuple_TTLeptons_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/TT/HTauTauTree_TTLeptons_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<43;j++){
    
    TString ScriptName = Form("script_tier3_MC_split/split_TTSemileptonic_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/TT/ntuple_TTSemileptonic_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/TT/HTauTauTree_TTSemileptonic_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();
  
  }
*/
/*
  for(unsigned int j=0;j<14;j++){
    
    TString ScriptName = Form("script_tier3_MC_split/split_tZq_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_tZq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Rares/HTauTauTree_tZq_split_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();
  
  }

  for(unsigned int j=0;j<14;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tZq_ICHEP18_JECup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECup/Rares/ntuple_tZq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECup/Rares/HTauTauTree_tZq_split_JECup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<14;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tZq_ICHEP18_JECdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/JECdown/Rares/ntuple_tZq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_JECdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/JECdown/Rares/HTauTauTree_tZq_split_JECdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<14;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tZq_ICHEP18_TESup_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESup/Rares/ntuple_tZq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESup.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESup/Rares/HTauTauTree_tZq_split_TESup_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<14;j++){

    TString ScriptName = Form("script_tier3_MC_split/split_tZq_ICHEP18_TESdown_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/TESdown/Rares/ntuple_tZq_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_TESdown.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/TESdown/Rares/HTauTauTree_tZq_split_TESdown_" << j << ".root\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }



 // DATA
  for(unsigned int j=0;j<83;j++){

    TString ScriptName = Form("script_tier3_data_split/split_SingleMu_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/SingleMu/2017C/ntuple_SingleMu_2017C_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/SingleMu/2017C/HTauTauTree_SingleMu_2017C_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

   for(unsigned int j=0;j<67;j++){

    TString ScriptName = Form("script_tier3_data_split/split_SingleEle_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/SingleEle/2017C/ntuple_SingleEle_2017C_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/SingleEle/2017C/HTauTauTree_SingleEle_2017C_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<31;j++){

    TString ScriptName = Form("script_tier3_data_split/split_DoubleEG_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/DoubleEG/2017C/ntuple_DoubleEG_2017C_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/DoubleEG/2017C/HTauTauTree_DoubleEG_2017C_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }

  for(unsigned int j=0;j<24;j++){

    TString ScriptName = Form("script_tier3_data_split/split_DoubleMu_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/DoubleMu/2017C/ntuple_DoubleMu_2017C_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/DoubleMu/2017C/HTauTauTree_DoubleMu_2017C_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }

  for(unsigned int j=0;j<8;j++){

    TString ScriptName = Form("script_tier3_data_split/split_MuonEG_2017C_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/MuonEG/2017C/ntuple_MuonEG_2017C_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/MuonEG/2017C/HTauTauTree_MuonEG_2017C_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }


   for(unsigned int j=0;j<37;j++){

    TString ScriptName = Form("script_tier3_data_split/split_SingleMu_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/SingleMu/2017D/ntuple_SingleMu_2017D_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/SingleMu/2017D/HTauTauTree_SingleMu_2017D_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
  
  for(unsigned int j=0;j<27;j++){

    TString ScriptName = Form("script_tier3_data_split/split_SingleEle_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/SingleEle/2017D/ntuple_SingleEle_2017D_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/SingleEle/2017D/HTauTauTree_SingleEle_2017D_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<13;j++){

    TString ScriptName = Form("script_tier3_data_split/split_DoubleEG_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/DoubleEG/2017D/ntuple_DoubleEG_2017D_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/DoubleEG/2017D/HTauTauTree_DoubleEG_2017D_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }

  for(unsigned int j=0;j<12;j++){

    TString ScriptName = Form("script_tier3_data_split/split_DoubleMu_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/DoubleMu/2017D/ntuple_DoubleMu_2017D_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/DoubleMu/2017D/HTauTauTree_DoubleMu_2017D_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }

  for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_data_split/split_MuonEG_2017D_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/MuonEG/2017D/ntuple_MuonEG_2017D_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/MuonEG/2017D/HTauTauTree_MuonEG_2017D_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }

  for(unsigned int j=0;j<83;j++){

    TString ScriptName = Form("script_tier3_data_split/split_SingleMu_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/SingleMu/2017E/ntuple_SingleMu_2017E_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/SingleMu/2017E/HTauTauTree_SingleMu_2017E_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<53;j++){

    TString ScriptName = Form("script_tier3_data_split/split_SingleEle_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/SingleEle/2017E/ntuple_SingleEle_2017E_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/SingleEle/2017E/HTauTauTree_SingleEle_2017E_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<28;j++){

    TString ScriptName = Form("script_tier3_data_split/split_DoubleEG_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/DoubleEG/2017E/ntuple_DoubleEG_2017E_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/DoubleEG/2017E/HTauTauTree_DoubleEG_2017E_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }

  for(unsigned int j=0;j<26;j++){

    TString ScriptName = Form("script_tier3_data_split/split_DoubleMu_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/DoubleMu/2017E/ntuple_DoubleMu_2017E_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/DoubleMu/2017E/HTauTauTree_DoubleMu_2017E_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }

  for(unsigned int j=0;j<10;j++){

    TString ScriptName = Form("script_tier3_data_split/split_MuonEG_2017E_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/MuonEG/2017E/ntuple_MuonEG_2017E_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/MuonEG/2017E/HTauTauTree_MuonEG_2017E_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   
  }

*/  
/*
  for(unsigned int j=0;j<85;j++){

    TString ScriptName = Form("script_tier3_data_split/split_SingleMu_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/SingleMu/2017F/ntuple_SingleMu_2017F_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/SingleMu/2017F/HTauTauTree_SingleMu_2017F_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  
    for(unsigned int j=0;j<67;j++){

    TString ScriptName = Form("script_tier3_data_split/split_SingleEle_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/SingleEle/2017F/ntuple_SingleEle_2017F_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/SingleEle/2017F/HTauTauTree_SingleEle_2017F_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }


  for(unsigned int j=0;j<40;j++){

    TString ScriptName = Form("script_tier3_data_split/split_DoubleMu_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/DoubleMu/2017F/ntuple_DoubleMu_2017F_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/DoubleMu/2017F/HTauTauTree_DoubleMu_2017F_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }

  for(unsigned int j=0;j<38;j++){

    TString ScriptName = Form("script_tier3_data_split/split_DoubleEG_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/DoubleEG/2017F/ntuple_DoubleEG_2017F_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/DoubleEG/2017F/HTauTauTree_DoubleEG_2017F_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }


for(unsigned int j=0;j<17;j++){

    TString ScriptName = Form("script_tier3_data_split/split_MuonEG_2017F_ICHEP18_%i.sh",j);
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L tree_splitter_2017_v7.C+\n";
    myscript << "split_tree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Data/MuonEG/2017F/ntuple_MuonEG_2017F_"<< j <<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\" , \"/data_CMS/cms/mperez/ttH_2017/ntuples_splitted/nominal/Data/MuonEG/2017F/HTauTauTree_MuonEG_2017F_split_" << j << ".root\",0,0,false);\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();

  }
*/
}



void launch_scripts(){
       

/*  for(unsigned int j=0;j<11;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<11;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<11;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<11;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<11;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttH_Hnonbb_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
/*
   for(unsigned int j=0;j<4;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tHq_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

    for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tHq_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tHq_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tHq_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tHq_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
 /* for(unsigned int j=0;j<8;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }


  for(unsigned int j=0;j<1;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttZ_lowmass_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

 
  for(unsigned int j=0;j<6;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttW_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttW_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttW_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
  /*for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";    LaunchExec += Form("script_tier3_MC_split/split_ttW_ICHEP18_TESdown_%i.sh",j);
    LaunchExec += Form("script_tier3_MC_split/split_ttW_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }


   for(unsigned int j=0;j<1;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WpWp_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

    for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WpWp_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WpWp_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WpWp_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WpWp_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  */for(unsigned int j=0;j<1;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttWW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

    for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttWW_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttWW_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttWW_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttWW_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
/*
  for(unsigned int j=0;j<5;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttG_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<5;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttG_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<5;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttG_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<5;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttG_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<5;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ttG_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
/*  for(unsigned int j=0;j<2;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<8;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<8;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<12;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<12;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<12;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<12;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<12;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
  /*for(unsigned int j=0;j<1;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WW_DoubleScat_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<1;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

 for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWW_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWW_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWW_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWW_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WWZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
 
  for(unsigned int j=0;j<1;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_WZZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZZ_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZZ_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZZ_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<2;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_TTTT_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_ZZ_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }


  for(unsigned int j=0;j<2;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_TTTT_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

    for(unsigned int j=0;j<2;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_TTTT_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<2;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_TTTT_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<2;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_TTTT_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
/*
  for(unsigned int j=0;j<14;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tZq_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<14;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tZq_ICHEP18_TESup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

    for(unsigned int j=0;j<14;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tZq_ICHEP18_JECup_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<14;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tZq_ICHEP18_JECdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }

  for(unsigned int j=0;j<14;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_tZq_ICHEP18_TESdown_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
  }
*/
/*
  for(unsigned int j=0;j<9;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_TTLeptons_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

  for(unsigned int j=0;j<43;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_MC_split/split_TTSemileptonic_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }

//DATA
  for(unsigned int j=0;j<83;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_SingleMu_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

    for(unsigned int j=0;j<67;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_SingleEle_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<31;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_DoubleEG_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

 
  for(unsigned int j=0;j<24;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_DoubleMu_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<8;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_MuonEG_2017C_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }*/
/*
  for(unsigned int j=0;j<37;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_SingleMu_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<27;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_SingleEle_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<13;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_DoubleEG_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

 
  for(unsigned int j=0;j<12;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_DoubleMu_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<5;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_MuonEG_2017D_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }
  
  for(unsigned int j=0;j<83;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_SingleMu_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<53;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_SingleEle_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<28;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_DoubleEG_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

 
  for(unsigned int j=0;j<26;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_DoubleMu_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<10;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_MuonEG_2017E_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }


  for(unsigned int j=0;j<85;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_SingleMu_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }
  
  for(unsigned int j=0;j<67;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_SingleEle_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }


  for(unsigned int j=0;j<40;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_DoubleMu_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<38;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_DoubleEG_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }
   
  for(unsigned int j=0;j<17;j++){

    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit ";
    LaunchExec += Form("script_tier3_data_split/split_MuonEG_2017F_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());

    }
*/
}
