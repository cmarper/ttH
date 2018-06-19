#include <TString.h>
#include <TSystem.h>
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;



void create_scripts(){


  /*for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_PU/PU_ttH_Hnonbb_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_ttH_Hnonbb_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttH/ntuple_PU_ttH_Hnonbb_"<<j<<".root\",\"HTauTauTree\", \"ttHJetToNonbb\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/


  /*for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_PU/PU_WWW_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_WWW_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_WWW_"<<j<<".root\",\"HTauTauTree\", \"WWW\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_PU/PU_WWZ_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_WWZ_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_WWZ_"<<j<<".root\",\"HTauTauTree\", \"WWZ\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_PU/PU_WZZ_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_WZZ_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_WZZ_"<<j<<".root\",\"HTauTauTree\", \"WZZ\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<1;j++){

    TString ScriptName = Form("script_tier3_PU/PU_ZZZ_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_ZZZ_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/Rares/ntuple_PU_ZZZ_"<<j<<".root\",\"HTauTauTree\", \"ZZZ\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }*/

  for(unsigned int j=0;j<3;j++){

    TString ScriptName = Form("script_tier3_PU/PU_ttW_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_ttW_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_PU_ttW_"<<j<<".root\",\"HTauTauTree\", \"TTW\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<4;j++){

    TString ScriptName = Form("script_tier3_PU/PU_ttZ_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_ttZ_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/ttV/ntuple_PU_ttZ_"<<j<<".root\",\"HTauTauTree\", \"TTZ\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

  for(unsigned int j=0;j<6;j++){

    TString ScriptName = Form("script_tier3_PU/PU_WZ_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/EWK/ntuple_WZ_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/EWK/ntuple_PU_WZ_"<<j<<".root\",\"HTauTauTree\", \"WZ\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }

/*  for(unsigned int j=0;j<5;j++){

    TString ScriptName = Form("script_tier3_PU/PU_TTLeptons_ICHEP18_%i.sh",j);
    
    ofstream myscript;
    myscript.open (ScriptName.Data());
    myscript << "#!/bin/bash\n";
    myscript << "cd /home/llr/cms/mperez/ttH/2017/CMSSW_9_4_6/src/\n";
    myscript << "eval `scramv1 runtime -sh`\n";
    myscript << "cd /home/llr/cms/mperez/ttH/MEM_Analysis/ttH/macros\n";
    myscript << "export X509_USER_PROXY=/home/llr/cms/mperez/.t3/proxy.cert\n";
    myscript << "root -b -l <<EOF\n";
    myscript << ".L add_PU_weight.C+\n";
    myscript << "create_PUtree(\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/TT/ntuple_TTLeptons_"<<j<<"_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017.root\",\"/data_CMS/cms/mperez/ttH_2017/ntuples_converted/nominal/TT/ntuple_PU_TTLeptons_"<<j<<".root\",\"HTauTauTree\", \"TTToDiLep\");\n";
    myscript << ".q\n";
    myscript << "EOF\n";
    myscript.close();   

  }
*/

}




void launch_scripts(){


  /*for(unsigned int j=0;j<5;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_ttH_Hnonbb_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }*/
   
  /*for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_WWW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_WWZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_WZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

  for(unsigned int j=0;j<1;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_ZZZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }*/

   for(unsigned int j=0;j<3;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_ttW_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

   for(unsigned int j=0;j<4;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_ttZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

   for(unsigned int j=0;j<6;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_WZ_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }

 /*  for(unsigned int j=0;j<5;j++){
    
    TString LaunchExec = "/opt/exp_soft/cms/t3/t3submit_new ";
    LaunchExec += Form("script_tier3_PU/PU_TTLeptons_ICHEP18_%i.sh",j);
    gSystem->Exec(LaunchExec.Data());
        
    }*/
  


}
