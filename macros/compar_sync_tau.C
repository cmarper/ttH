#include <fstream>
#include <iostream>
#include <sstream>
#include <TString.h>
#include <TFile.h>
#include <TChain.h>
#include <TBranch.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <TGaxis.h>
#include <TLatex.h>
#include "Helpers.C"


void compar( TString institute = "ND" ){

  TString log_file;
  if (institute == "ND") { log_file = "../sync/log_ND_tau.txt";}
  if (institute == "IHEP") { log_file = "../sync/log_IHEP_tau.txt";}
  std::ifstream infile(log_file);

  TChain * tree = new TChain("syncTree");
  tree->Add("/data_CMS/cms/mperez/ttH_test_2016/syncNtuples/syncNtuple_ttH.root");
  int nEntries = tree->GetEntries();

  int _nEvent;
  //Long64_t _nEvent;
  int _n_presel_tau;

  tree->SetBranchAddress("nEvent",&_nEvent);
  tree->SetBranchAddress("n_presel_tau",&_n_presel_tau);

  //int i=0;
  int nEntry=0;
  string line;
  while(getline(infile,line)){   
    /*if(i==0){
      i++;
      continue;
    }*/

    std::istringstream iss(line);
    vector<float> var;
    for(unsigned int j=0;j<19;j++)
      var.push_back(-1);


    iss >> var[0] >> var[1] >> var[2] >> var[3] >> var[4] >> var[5] >> var[6] >> var[7] >> var[8] ;

    //int event_log = var[0];
    //if((log_file.Contains("CERN") || log_file.Contains("NDNebr"))  && (var[0]==132692 || var[0]==1465225))
      //continue;

    _n_presel_tau = 0;

    /*int nEntry_init = nEntry;

    while(_nEvent=var[0] && nEntry!=nEntry_init-1){
      tree->GetEntry(nEntry);
      nEntry++;
      if(nEntry>nEntries)
  nEntry = 0;
    }

    if(nEntry==nEntry_init-1)
      cout<<"Problem"<<endl;*/

    tree->GetEntry(nEntry);
    while(_n_presel_tau==0 && nEntry<nEntries){
      nEntry++;
      tree->GetEntry(nEntry);
    }

   if(abs(_nEvent-var[0])>1e-5){
      cout<<"Different"<<endl;
      cout<<"Event #"<<_nEvent<<endl;
      cout<<"ND has "<<var[0]<<endl;
      return;
    }

    nEntry++;

  }


  cout<<"Congratulations! You are synced!"<<endl;

  return;


}




TH1F* histo_fromlog(TString log_file, int varnumber, int nbin, float min, float max){

  TH1F* h=new TH1F("h","h",nbin,min,max);
  
  std::ifstream infile(log_file);


  int i=0;
  string line;
  while(getline(infile,line)){   
    
    i++;

    std::istringstream iss(line);
    vector<float> var;
    for(unsigned int j=0;j<18;j++)
      var.push_back(-1);


    iss >> var[0] >> var[1] >> var[2] >> var[3] >> var[4] >> var[5] >> var[6] >> var[7] >> var[8] ;


    h->Fill(var[varnumber]);


  }

  return h;


}








void compar_EventNumber_tau( TString institute = "ND"){

  TChain * tree = new TChain("HTauTauTree");
  tree->Add("/data_CMS/cms/mperez/ttH_test_2016/ntuples_converted/nominal/ttH/syncNtuple_ttH_multilep_0_byLooseIsolationMVArun2v1DBdR03oldDMwLT.root"); 
 
  TH1F* h = new TH1F("h","h",500000,0,500000);
  tree->Draw("EventNumber>>h","n_recotauh>=1","goff");

  TH1F* h_sync; 
  if (institute == "ND") {h_sync = histo_fromlog("../sync/log_ND_tau.txt",0,500000,0,500000);}
  if (institute == "IHEP") {h_sync = histo_fromlog("../sync/log_IHEP_tau.txt",0,500000,0,500000);}

  h->SetTitle("EventNumber");
  h->SetLineColor(1);
  h->SetLineWidth(2);
  h->SetStats(0);
  h->SetMaximum(2);

  h_sync->SetLineColor(kOrange-2);
  h_sync->SetFillColor(kOrange-2);
  
  
  TLegend* leg=new TLegend(0.5,0.65,0.75,0.85);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->AddEntry(h,"LLR");
  if (institute == "ND") {leg->AddEntry(h_sync,"ND");}
  if (institute == "IHEP") {leg->AddEntry(h_sync,"IHEP");}

  TCanvas* c=new TCanvas("c","c",650,600);
  c->SetLeftMargin(0.15);

  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetGridx();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  
  h->GetYaxis()->SetTitle("Number of events");
  h->GetXaxis()->SetTitle("EventNumber");
  
  h->Draw();
  cout<<h->GetEntries()<<endl;;
  h_sync->Draw("same");
  cout<<h_sync->GetEntries()<<endl;;
  leg->Draw("same");

  // Do not draw the Y axis label on the upper plot and redraw a small
  // axis instead, in order to avoid the first label (0) to be clipped.
  h->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis = new TGaxis( 0, 0.5, 0, h->GetMaximum(), 0.5,h->GetMaximum(),510,"");
  axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis->SetLabelSize(15);
  axis->Draw();
  
   // lower plot will be in pad
  c->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.2);
  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad
  
  // Define the ratio plot
  TH1F *h_ratio = (TH1F*)h->Clone("h_ratio");
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetMinimum(0.9);  // Define Y ..
  h_ratio->SetMaximum(1.1); // .. range
  h_ratio->Sumw2();
  h_ratio->SetStats(0);      // No statistics on lower plot
  h_ratio->Divide(h_sync);
  h_ratio->SetMarkerStyle(20);
  h_ratio->Draw("histp");       // Draw the ratio plot
  
  // Y axis histo_etaul plot settings
  h->GetYaxis()->SetTitleSize(20);
  h->GetYaxis()->SetTitleFont(43);
  h->GetYaxis()->SetTitleOffset(1.5);
  
  // Ratio plot (h_ratio) settings
  h_ratio->SetTitle(""); // Remove the ratio title
  
  h_ratio->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis2 = new TGaxis( 0, 0.91, 0, 1.09, 0.91, 1.09, 505,"");
  axis2->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis2->SetLabelSize(15);
  axis2->Draw();
  
  // Y axis ratio plot settings
  if (institute == "ND") {h_ratio->GetYaxis()->SetTitle("LLR/ND");}
  if (institute == "IHEP") {h_ratio->GetYaxis()->SetTitle("LLR/IHEP");}
  h_ratio->GetYaxis()->SetNdivisions(505);
  h_ratio->GetYaxis()->SetTitleSize(20);
  h_ratio->GetYaxis()->SetTitleFont(43);
  h_ratio->GetYaxis()->SetTitleOffset(1.5);
  //h_ratio->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h_ratio->GetYaxis()->SetLabelSize(15);

  
  // X axis ratio plot settings
  h_ratio->GetXaxis()->SetTitleSize(20);
  h_ratio->GetXaxis()->SetTitleFont(43);
  h_ratio->GetXaxis()->SetTitleOffset(3.);
  h_ratio->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h_ratio->GetXaxis()->SetLabelSize(15);


  TString plotname;
  if (institute == "ND") {plotname="sync/EventNumber_tau_LLR_ND";}
  if (institute == "IHEP") {plotname="sync/EventNumber_tau_LLR_IHEP";}
  c->SaveAs("../plots/pdf/"+plotname+".pdf");
  c->SaveAs("../plots/png/"+plotname+".png");

  return;

}









void compar_pt_tau( TString institute = "ND"){

  TChain * tree = new TChain("HTauTauTree");
  tree->Add("/data_CMS/cms/mperez/ttH_test_2016/ntuples_converted/nominal/ttH/syncNtuple_ttH_multilep_0_byLooseIsolationMVArun2v1DBdR03oldDMwLT.root");
  
  TH1F* h = new TH1F("h","h",100,0,500);
  tree->Draw("recotauh_pt[0]>>h","n_recotauh>=1","goff");

  TH1F* h_sync;
  if (institute == "ND") {h_sync = histo_fromlog("../sync/log_ND_tau.txt",1,100,0,500);}
  if (institute == "IHEP") {h_sync = histo_fromlog("../sync/log_IHEP_tau.txt",1,100,0,500);}
  
  h_sync->SetTitle("Leading tau pT");
  h_sync->SetStats(0);
  h_sync->SetMaximum(1.25*h_sync->GetMaximum());

  h_sync->SetLineColor(kOrange-2);
  h_sync->SetFillColor(kOrange-2);

  h->SetLineColor(1);
  h->SetLineWidth(2);
  
  for(unsigned int i=0; i<5000000;i++){
    int LLR = h->GetBinContent(i);
    int ND;
    int IHEP;
    if (institute == "ND"){ ND = h_sync->GetBinContent(i);}
    if (institute == "IHEP"){ IHEP = h_sync->GetBinContent(i);}

    if( (institute == "ND") && (LLR!=ND) ) {
      cout<<"i="<<i<<endl;
      cout<<"LLR="<<LLR<<endl;
      cout<<"ND="<<ND<<endl;
    }

    if( (institute == "IHEP") && (LLR!=IHEP) ) {
      cout<<"i="<<i<<endl;
      cout<<"LLR="<<LLR<<endl;
      cout<<"IHEP="<<IHEP<<endl;
    }
  }
  
  TLegend* leg=new TLegend(0.5,0.65,0.75,0.85);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->AddEntry(h,"LLR");
  if (institute == "ND") {leg->AddEntry(h_sync,"ND");}
  if (institute == "IHEP"){leg->AddEntry(h_sync,"IHEP");}

  TCanvas* c=new TCanvas("c","c",650,600);
  c->SetLeftMargin(0.15);


  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  
  h_sync->GetYaxis()->SetTitle(Form("Number of events / %.2f [GeV]",binning(h)));
  h->GetXaxis()->SetTitle("p_{T} [GeV]");
  
  h_sync->Draw();
  cout<<h_sync->GetEntries()<<endl;;
  h->Draw("same");
  cout<<h->GetEntries()<<endl;;
  leg->Draw("same");

  // Do not draw the Y axis label on the upper plot and redraw a small
  // axis instead, in order to avoid the first label (0) to be clipped.
  h_sync->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis = new TGaxis( 0, 0.5, 0, h_sync->GetMaximum(), 0.5,h_sync->GetMaximum(),510,"");
  axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis->SetLabelSize(15);
  axis->Draw();
  
   // lower plot will be in pad
  c->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.25);
  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad
  
  // Define the ratio plot
  TH1F *h_ratio = (TH1F*)h->Clone("h_ratio");
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetMinimum(0.9);  // Define Y ..
  h_ratio->SetMaximum(1.1); // .. range
  h_ratio->Sumw2();
  h_ratio->SetStats(0);      // No statistics on lower plot
  h_ratio->Divide(h_sync);
  h_ratio->SetMarkerStyle(20);
  h_ratio->Draw("histp");       // Draw the ratio plot
  
  // Y axis histo_etaul plot settings
  h_sync->GetYaxis()->SetTitleSize(20);
  h_sync->GetYaxis()->SetTitleFont(43);
  h_sync->GetYaxis()->SetTitleOffset(1.45);
  
  // Ratio plot (h_ratio) settings
  h_ratio->SetTitle(""); // Remove the ratio title
  
  h_ratio->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis2 = new TGaxis( 0, 0.91, 0, 1.09, 0.91, 1.09, 505,"");
  axis2->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis2->SetLabelSize(15);
  axis2->Draw();
  
  // Y axis ratio plot settings
  if (institute == "ND"){h_ratio->GetYaxis()->SetTitle("LLR/ND");}
  if (institute == "IHEP"){h_ratio->GetYaxis()->SetTitle("LLR/IHEP");}
  h_ratio->GetYaxis()->SetNdivisions(505);
  h_ratio->GetYaxis()->SetTitleSize(20);
  h_ratio->GetYaxis()->SetTitleFont(43);
  h_ratio->GetYaxis()->SetTitleOffset(1.5);
  //h_ratio->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h_ratio->GetYaxis()->SetLabelSize(15);

  
  // X axis ratio plot settings
  h_ratio->GetXaxis()->SetTitleSize(17);
  h_ratio->GetXaxis()->SetTitleFont(43);
  h_ratio->GetXaxis()->SetTitleOffset(4.);
  h_ratio->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h_ratio->GetXaxis()->SetLabelSize(15);


  TString plotname;
  if (institute == "ND") {plotname="sync/pt_tau_LLR_ND";}
  if (institute == "IHEP") {plotname="sync/pt_tau_LLR_IHEP";}
  c->SaveAs("../plots/pdf/"+plotname+".pdf");
  c->SaveAs("../plots/png/"+plotname+".png");

  return;

}










void compar_eta_tau( TString institute = "ND"){

  TChain * tree = new TChain("HTauTauTree");
  tree->Add("/data_CMS/cms/mperez/ttH_test_2016/ntuples_converted/nominal/ttH/syncNtuple_ttH_multilep_0_byLooseIsolationMVArun2v1DBdR03oldDMwLT.root");
  
  TH1F* h = new TH1F("h","h",75,-3,3);
  tree->Draw("recotauh_eta[0]>>h","n_recotauh>=1","goff");
  
  TH1F* h_sync;
  if (institute == "ND") {h_sync = histo_fromlog("../sync/log_ND_tau.txt",2,75,-3,3);}
  if (institute == "IHEP") {h_sync = histo_fromlog("../sync/log_IHEP_tau.txt",2,75,-3,3);}

  h_sync->SetTitle("Leading tau #eta");
  h_sync->SetStats(0);
  h_sync->SetMaximum(1.25*h_sync->GetMaximum());

  h_sync->SetLineColor(kOrange-2);
  h_sync->SetFillColor(kOrange-2);

  h->SetLineColor(1);
  h->SetLineWidth(2);
  
  
  TLegend* leg=new TLegend(0.7,0.65,0.85,0.85);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->AddEntry(h,"LLR");
  if (institute == "ND"){leg->AddEntry(h_sync,"ND");}
  if (institute == "IHEP"){leg->AddEntry(h_sync,"IHEP");}

  TCanvas* c=new TCanvas("c","c",650,600);
  c->SetLeftMargin(0.15);


  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  
  h_sync->GetYaxis()->SetTitle(Form("Number of events / %.2f",binning(h)));
  h->GetXaxis()->SetTitle("#eta");
  
  h_sync->Draw();
  cout<<h_sync->GetEntries()<<endl;;
  h->Draw("same");
  cout<<h->GetEntries()<<endl;;
  leg->Draw("same");

  // Do not draw the Y axis label on the upper plot and redraw a small
  // axis instead, in order to avoid the first label (0) to be clipped.
  h_sync->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis = new TGaxis( -3, 0.5, -3, h_sync->GetMaximum(), 0.5,h_sync->GetMaximum(),510,"");
  axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis->SetLabelSize(15);
  axis->Draw();
  
   // lower plot will be in pad
  c->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.25);
  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad
  
  // Define the ratio plot
  TH1F *h_ratio = (TH1F*)h->Clone("h_ratio");
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetMinimum(0.9);  // Define Y ..
  h_ratio->SetMaximum(1.1); // .. range
  h_ratio->Sumw2();
  h_ratio->SetStats(0);      // No statistics on lower plot
  h_ratio->Divide(h_sync);
  h_ratio->SetMarkerStyle(20);
  h_ratio->Draw("histp");       // Draw the ratio plot
  
  // Y axis histo_etaul plot settings
  h_sync->GetYaxis()->SetTitleSize(20);
  h_sync->GetYaxis()->SetTitleFont(43);
  h_sync->GetYaxis()->SetTitleOffset(1.45);
  
  // Ratio plot (h_ratio) settings
  h_ratio->SetTitle(""); // Remove the ratio title
  
  h_ratio->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis2 = new TGaxis( -3, 0.91, -3, 1.09, 0.91, 1.09, 505,"");
  axis2->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis2->SetLabelSize(15);
  axis2->Draw();
  
  // Y axis ratio plot settings
  if (institute == "ND"){h_ratio->GetYaxis()->SetTitle("LLR/ND");}
  if (institute == "IHEP"){h_ratio->GetYaxis()->SetTitle("LLR/IHEP");}
  h_ratio->GetYaxis()->SetNdivisions(505);
  h_ratio->GetYaxis()->SetTitleSize(20);
  h_ratio->GetYaxis()->SetTitleFont(43);
  h_ratio->GetYaxis()->SetTitleOffset(1.5);
  //h_ratio->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h_ratio->GetYaxis()->SetLabelSize(15);

  
  // X axis ratio plot settings
  h_ratio->GetXaxis()->SetTitleSize(17);
  h_ratio->GetXaxis()->SetTitleFont(43);
  h_ratio->GetXaxis()->SetTitleOffset(4.);
  h_ratio->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h_ratio->GetXaxis()->SetLabelSize(15);

  TString plotname;
  if (institute == "ND"){plotname="sync/eta_tau_LLR_ND";}
  if (institute == "IHEP"){plotname="sync/eta_tau_LLR_IHEP";}
  c->SaveAs("../plots/pdf/"+plotname+".pdf");
  c->SaveAs("../plots/png/"+plotname+".png");

  return;

}








void compar_phi_tau( TString institute = "ND"){

  TChain * tree = new TChain("HTauTauTree");
  tree->Add("/data_CMS/cms/mperez/ttH_test_2016/ntuples_converted/nominal/ttH/syncNtuple_ttH_multilep_0_byLooseIsolationMVArun2v1DBdR03oldDMwLT.root"); 

  TH1F* h = new TH1F("h","h",80,-3.2,3.2);
  tree->Draw("recotauh_phi[0]>>h","n_recotauh>=1","goff");

  TH1F* h_sync;
  if (institute == "ND") {h_sync = histo_fromlog("../sync/log_ND_tau.txt",3,80,-3.2,3.2);}
  if (institute == "IHEP") {h_sync = histo_fromlog("../sync/log_IHEP_tau.txt",3,80,-3.2,3.2);}

  h_sync->SetTitle("Leading tau #phi");
  h_sync->SetStats(0);
  h_sync->SetMaximum(1.25*h_sync->GetMaximum());

  h_sync->SetLineColor(kOrange-2);
  h_sync->SetFillColor(kOrange-2);

  h->SetLineColor(1);
  h->SetLineWidth(2);
  
  
  TLegend* leg=new TLegend(0.7,0.65,0.85,0.85);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->AddEntry(h,"LLR");
  if (institute == "ND"){leg->AddEntry(h_sync,"ND");}
  if (institute == "IHEP"){leg->AddEntry(h_sync,"IHEP");}

  TCanvas* c=new TCanvas("c","c",650,600);
  c->SetLeftMargin(0.15);


  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  
  h_sync->GetYaxis()->SetTitle(Form("Number of events / %.2f",binning(h)));
  h->GetXaxis()->SetTitle("#phi");
  
  h_sync->Draw();
  cout<<h_sync->GetEntries()<<endl;;
  h->Draw("same");
  cout<<h->GetEntries()<<endl;;
  leg->Draw("same");

  // Do not draw the Y axis label on the upper plot and redraw a small
  // axis instead, in order to avoid the first label (0) to be clipped.
  h_sync->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis = new TGaxis( -3.2, 0.5, -3.2, h_sync->GetMaximum(), 0.5,h_sync->GetMaximum(),510,"");
  axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis->SetLabelSize(15);
  axis->Draw();
  
   // lower plot will be in pad
  c->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.25);
  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad
  
  // Define the ratio plot
  TH1F *h_ratio = (TH1F*)h->Clone("h_ratio");
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetMinimum(0.9);  // Define Y ..
  h_ratio->SetMaximum(1.1); // .. range
  h_ratio->Sumw2();
  h_ratio->SetStats(0);      // No statistics on lower plot
  h_ratio->Divide(h_sync);
  h_ratio->SetMarkerStyle(20);
  h_ratio->Draw("histp");       // Draw the ratio plot
  
  // Y axis histo_etaul plot settings
  h_sync->GetYaxis()->SetTitleSize(20);
  h_sync->GetYaxis()->SetTitleFont(43);
  h_sync->GetYaxis()->SetTitleOffset(1.45);
  
  // Ratio plot (h_ratio) settings
  h_ratio->SetTitle(""); // Remove the ratio title
  
  h_ratio->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis2 = new TGaxis( -3.2, 0.91, -3.2, 1.09, 0.91, 1.09, 505,"");
  axis2->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis2->SetLabelSize(15);
  axis2->Draw();
  
  // Y axis ratio plot settings
  if (institute == "ND"){h_ratio->GetYaxis()->SetTitle("LLR/ND");}
  if (institute == "IHEP"){h_ratio->GetYaxis()->SetTitle("LLR/IHEP");}
  h_ratio->GetYaxis()->SetNdivisions(505);
  h_ratio->GetYaxis()->SetTitleSize(20);
  h_ratio->GetYaxis()->SetTitleFont(43);
  h_ratio->GetYaxis()->SetTitleOffset(1.5);
  //h_ratio->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h_ratio->GetYaxis()->SetLabelSize(15);

  
  // X axis ratio plot settings
  h_ratio->GetXaxis()->SetTitleSize(17);
  h_ratio->GetXaxis()->SetTitleFont(43);
  h_ratio->GetXaxis()->SetTitleOffset(4.);
  h_ratio->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h_ratio->GetXaxis()->SetLabelSize(15);


  TString plotname;
  if (institute == "ND"){plotname="sync/phi_tau_LLR_ND";}
  if (institute == "IHEP"){plotname="sync/phi_tau_LLR_IHEP";}
  c->SaveAs("../plots/pdf/"+plotname+".pdf");
  c->SaveAs("../plots/png/"+plotname+".png");

  return;

}








void compar_E_tau( TString institute = "ND"){

  TChain * tree = new TChain("HTauTauTree");
  tree->Add("/data_CMS/cms/mperez/ttH_test_2016/ntuples_converted/nominal/ttH/syncNtuple_ttH_multilep_0_byLooseIsolationMVArun2v1DBdR03oldDMwLT.root"); 

  TH1F* h = new TH1F("h","h",100,0,500);
  tree->Draw("recotauh_e[0]>>h","n_recotauh>=1","goff");

  TH1F* h_sync;
  if (institute == "ND") {h_sync = histo_fromlog("../sync/log_ND_tau.txt",4,100,0,500);}
  if (institute == "IHEP") {h_sync = histo_fromlog("../sync/log_IHEP_tau.txt",4,100,0,500);}

  h_sync->SetTitle("Leading tau Energy");
  h_sync->SetStats(0);
  h_sync->SetMaximum(1.25*h_sync->GetMaximum());

  h_sync->SetLineColor(kOrange-2);
  h_sync->SetFillColor(kOrange-2);

  h->SetLineColor(1);
  h->SetLineWidth(2);
  
  
  TLegend* leg=new TLegend(0.7,0.65,0.85,0.85);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->AddEntry(h,"LLR");
  if (institute == "ND") {leg->AddEntry(h_sync,"ND");}
  if (institute == "IHEP") {leg->AddEntry(h_sync,"IHEP");}
  

  TCanvas* c=new TCanvas("c","c",650,600);
  c->SetLeftMargin(0.15);


  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  
  h_sync->GetYaxis()->SetTitle(Form("Number of events / %.2f [GeV]",binning(h)));
  h->GetXaxis()->SetTitle("E [GeV]");
  
  h_sync->Draw();
  cout<<h_sync->GetEntries()<<endl;;
  h->Draw("same");
  cout<<h->GetEntries()<<endl;;
  leg->Draw("same");

  // Do not draw the Y axis label on the upper plot and redraw a small
  // axis instead, in order to avoid the first label (0) to be clipped.
  h_sync->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis = new TGaxis( 0, 0.5, 0, h_sync->GetMaximum(), 0.5,h_sync->GetMaximum(),510,"");
  axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis->SetLabelSize(15);
  axis->Draw();
  
   // lower plot will be in pad
  c->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.25);
  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad
  
  // Define the ratio plot
  TH1F *h_ratio = (TH1F*)h->Clone("h_ratio");
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetMinimum(0.9);  // Define Y ..
  h_ratio->SetMaximum(1.1); // .. range
  h_ratio->Sumw2();
  h_ratio->SetStats(0);      // No statistics on lower plot
  h_ratio->Divide(h_sync);
  h_ratio->SetMarkerStyle(20);
  h_ratio->Draw("histp");       // Draw the ratio plot
  
  // Y axis histo_etaul plot settings
  h_sync->GetYaxis()->SetTitleSize(20);
  h_sync->GetYaxis()->SetTitleFont(43);
  h_sync->GetYaxis()->SetTitleOffset(1.45);
  
  // Ratio plot (h_ratio) settings
  h_ratio->SetTitle(""); // Remove the ratio title
  
  h_ratio->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis2 = new TGaxis( 0, 0.91, 0, 1.09, 0.91, 1.09, 505,"");
  axis2->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis2->SetLabelSize(15);
  axis2->Draw();
  
  // Y axis ratio plot settings
  if (institute == "ND") {h_ratio->GetYaxis()->SetTitle("LLR/ND");}
  if (institute == "IHEP") {h_ratio->GetYaxis()->SetTitle("LLR/IHEP");}
  h_ratio->GetYaxis()->SetNdivisions(505);
  h_ratio->GetYaxis()->SetTitleSize(20);
  h_ratio->GetYaxis()->SetTitleFont(43);
  h_ratio->GetYaxis()->SetTitleOffset(1.5);
  //h_ratio->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h_ratio->GetYaxis()->SetLabelSize(15);

  
  // X axis ratio plot settings
  h_ratio->GetXaxis()->SetTitleSize(17);
  h_ratio->GetXaxis()->SetTitleFont(43);
  h_ratio->GetXaxis()->SetTitleOffset(4.);
  h_ratio->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h_ratio->GetXaxis()->SetLabelSize(15);

  TString plotname;
  if (institute == "ND") {plotname="sync/E_tau_LLR_ND";}
  if (institute == "IHEP") {plotname="sync/E_tau_LLR_IHEP";}
  c->SaveAs("../plots/pdf/"+plotname+".pdf");
  c->SaveAs("../plots/png/"+plotname+".png");

  return;

}






void compar_dxy_tau( TString institute = "ND"){

  TChain * tree = new TChain("HTauTauTree");
  tree->Add("/data_CMS/cms/mperez/ttH_test_2016/ntuples_converted/nominal/ttH/syncNtuple_ttH_multilep_0_byLooseIsolationMVArun2v1DBdR03oldDMwLT.root"); 

  TH1F* h = new TH1F("h","h",40,-0.02,0.02);
  tree->Draw("recotauh_dxy[0]>>h","n_recotauh>=1","goff");

  TH1F* h_sync; 
  if (institute == "ND") {h_sync = histo_fromlog("../sync/log_ND_tau.txt",6,40,-0.02,0.02);}
  if (institute == "IHEP") {h_sync = histo_fromlog("../sync/log_IHEP_tau.txt",6,40,-0.02,0.02);}

  h_sync->SetTitle("Leading tau dxy");
  h_sync->SetStats(0);
  h_sync->SetMaximum(1.25*h_sync->GetMaximum());
 
  h_sync->SetLineColor(kOrange-2);
  h_sync->SetFillColor(kOrange-2);

  h->SetLineColor(1);
  h->SetLineWidth(2);
  
  
  TLegend* leg=new TLegend(0.45,0.65,0.65,0.85);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->AddEntry(h,"LLR");
  if (institute == "ND") {leg->AddEntry(h_sync,"ND");}
  if (institute == "IHEP") {leg->AddEntry(h_sync,"IHEP");}
  

  TCanvas* c=new TCanvas("c","c",650,600);
  c->SetLeftMargin(0.15);


  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  
  h_sync->GetYaxis()->SetTitle(Form("Number of events / %.2f [mm]",10*binning(h)));
  h->GetXaxis()->SetTitle("dxy [cm]");
  
  h_sync->Draw();
  cout<<h_sync->GetEntries()<<endl;;
  h->Draw("same");
  cout<<h->GetEntries()<<endl;;
  leg->Draw("same");

  // Do not draw the Y axis label on the upper plot and redraw a small
  // axis instead, in order to avoid the first label (0) to be clipped.
  h_sync->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis = new TGaxis( 0, 0.5, 0, h_sync->GetMaximum(), 0.5,h_sync->GetMaximum(),510,"");
  axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis->SetLabelSize(15);
  axis->Draw();
  
   // lower plot will be in pad
  c->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.25);
  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad
 
 
  // Define the ratio plot
  TH1F *h_ratio = (TH1F*)h->Clone("h_ratio");
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetMinimum(0.9);  // Define Y ..
  h_ratio->SetMaximum(1.1); // .. range
  h_ratio->Sumw2();
  h_ratio->SetStats(0);      // No statistics on lower plot
  h_ratio->Divide(h_sync);
  h_ratio->SetMarkerStyle(20);
  h_ratio->Draw("histp");       // Draw the ratio plot
  
  // Y axis histo_etaul plot settings
  h_sync->GetYaxis()->SetTitleSize(20);
  h_sync->GetYaxis()->SetTitleFont(43);
  h_sync->GetYaxis()->SetTitleOffset(1.45);
  
  // Ratio plot (h_ratio) settings
  h_ratio->SetTitle(""); // Remove the ratio title
  
  h_ratio->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis2 = new TGaxis( 0, 0.91, 0, 1.09, 0.91, 1.09, 505,"");
  axis2->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis2->SetLabelSize(15);
  axis2->Draw();
  
  // Y axis ratio plot settings
  if (institute == "ND") {h_ratio->GetYaxis()->SetTitle("LLR/ND");}
  if (institute == "IHEP") {h_ratio->GetYaxis()->SetTitle("LLR/IHEP");}
  h_ratio->GetYaxis()->SetNdivisions(505);
  h_ratio->GetYaxis()->SetTitleSize(20);
  h_ratio->GetYaxis()->SetTitleFont(43);
  h_ratio->GetYaxis()->SetTitleOffset(1.5);
  //h_ratio->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h_ratio->GetYaxis()->SetLabelSize(15);

  
  // X axis ratio plot settings
  h_ratio->GetXaxis()->SetTitleSize(17);
  h_ratio->GetXaxis()->SetTitleFont(43);
  h_ratio->GetXaxis()->SetTitleOffset(4.);
  h_ratio->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h_ratio->GetXaxis()->SetLabelSize(15);


  TString plotname;
  if (institute == "ND") {plotname="sync/dxy_tau_LLR_ND";}
  if (institute == "IHEP") {plotname="sync/dxy_tau_LLR_IHEP";}
  c->SaveAs("../plots/pdf/"+plotname+".pdf");
  c->SaveAs("../plots/png/"+plotname+".png");

  return;

}






void compar_dz_tau( TString institute = "ND"){

  TChain * tree = new TChain("HTauTauTree");
  tree->Add("/data_CMS/cms/mperez/ttH_test_2016/ntuples_converted/nominal/ttH/syncNtuple_ttH_multilep_0_byLooseIsolationMVArun2v1DBdR03oldDMwLT.root"); 

  TH1F* h = new TH1F("h","h",51,-0.05,0.05);
  tree->Draw("recotauh_dz[0]>>h","n_recotauh>=1","goff");

  TH1F* h_sync; 
  if (institute == "ND") {h_sync = histo_fromlog("../sync/log_ND_tau.txt",7,51,-0.05,0.05);}
  if (institute == "IHEP") {h_sync = histo_fromlog("../sync/log_IHEP_tau.txt",7,51,-0.05,0.05);}

  h_sync->SetTitle("Leading tau dz");
  h_sync->SetStats(0);
  h_sync->SetMaximum(1.25*h_sync->GetMaximum());

  h_sync->SetLineColor(kOrange-2);
  h_sync->SetFillColor(kOrange-2);

  h->SetLineColor(1);
  h->SetLineWidth(2);
  
  
  TLegend* leg=new TLegend(0.65,0.65,0.85,0.85);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->AddEntry(h,"LLR");
  if (institute == "ND") {leg->AddEntry(h_sync,"ND");}
  if (institute == "IHEP") {leg->AddEntry(h_sync,"IHEP");}
  

  TCanvas* c=new TCanvas("c","c",650,600);
  c->SetLeftMargin(0.15);


  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  
  h_sync->GetYaxis()->SetTitle(Form("Number of events / %.2f [mm]",10*binning(h)));
  h->GetXaxis()->SetTitle("dz [cm]");
  
  h_sync->Draw();
  cout<<h_sync->GetEntries()<<endl;;
  h->Draw("same");
  cout<<h->GetEntries()<<endl;;
  leg->Draw("same");

  // Do not draw the Y axis label on the upper plot and redraw a small
  // axis instead, in order to avoid the first label (0) to be clipped.
  h_sync->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis = new TGaxis( -0.05, 0.5, -0.05, h_sync->GetMaximum(), 0.5,h_sync->GetMaximum(),510,"");
  axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis->SetLabelSize(15);
  axis->Draw();
  
   // lower plot will be in pad
  c->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.25);
  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad
  
  // Define the ratio plot
  TH1F *h_ratio = (TH1F*)h->Clone("h_ratio");
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetMinimum(0.9);  // Define Y ..
  h_ratio->SetMaximum(1.1); // .. range
  h_ratio->Sumw2();
  h_ratio->SetStats(0);      // No statistics on lower plot
  h_ratio->Divide(h_sync);
  h_ratio->SetMarkerStyle(20);
  h_ratio->Draw("histp");       // Draw the ratio plot
  
  // Y axis histo_etaul plot settings
  h_sync->GetYaxis()->SetTitleSize(20);
  h_sync->GetYaxis()->SetTitleFont(43);
  h_sync->GetYaxis()->SetTitleOffset(1.45);
  
  // Ratio plot (h_ratio) settings
  h_ratio->SetTitle(""); // Remove the ratio title
  
  h_ratio->GetYaxis()->SetLabelSize(0.);
  TGaxis *axis2 = new TGaxis( -0.05, 0.91, -0.05, 1.09, 0.91, 1.09, 505,"");
  axis2->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  axis2->SetLabelSize(15);
  axis2->Draw();
  
  // Y axis ratio plot settings
  if (institute == "ND") {h_ratio->GetYaxis()->SetTitle("LLR/ND");}
  if (institute == "IHEP") {h_ratio->GetYaxis()->SetTitle("LLR/IHEP");}
  h_ratio->GetYaxis()->SetNdivisions(505);
  h_ratio->GetYaxis()->SetTitleSize(20);
  h_ratio->GetYaxis()->SetTitleFont(43);
  h_ratio->GetYaxis()->SetTitleOffset(1.5);
  //h_ratio->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h_ratio->GetYaxis()->SetLabelSize(15);

  
  // X axis ratio plot settings
  h_ratio->GetXaxis()->SetTitleSize(17);
  h_ratio->GetXaxis()->SetTitleFont(43);
  h_ratio->GetXaxis()->SetTitleOffset(4.);
  h_ratio->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h_ratio->GetXaxis()->SetLabelSize(15);


  TString plotname;
  if (institute == "ND") {plotname="sync/dz_tau_LLR_ND";}
  if (institute == "IHEP") {plotname="sync/dz_tau_LLR_IHEP";}
  c->SaveAs("../plots/pdf/"+plotname+".pdf");
  c->SaveAs("../plots/png/"+plotname+".png");

  return;

}

