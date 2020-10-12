//C, C++
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <time.h>

using namespace std;

Int_t plots_geom01(){

  TString fileN;
  TString fileN_outPDf;
  //only PMT
  //900 V
  //fileN = "../root_data_L2/Run_001_Data_9_22_2020_Binary/Run_001_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_001_V900_noquartz.pdf";
  //1000
  //fileN = "../root_data_L2/Run_002_Data_9_22_2020_Binary/Run_002_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_002_V1000_noquartz.pdf";
  //1100
  //fileN = "../root_data_L2/Run_003_Data_9_22_2020_Binary/Run_003_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_003_V1100_noquartz.pdf";
  //1200
  //fileN = "../root_data_L2/Run_004_Data_9_22_2020_Binary/Run_004_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_004_V1200_noquartz.pdf";
  //800
  //fileN = "../root_data_L2/Run_005_Data_9_22_2020_Binary/Run_005_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_005_V800_noquartz.pdf";

  //fileN = "../root_data_L2/Run_002_Data_9_22_2020_Binary/Run_002_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_002_noquartz.pdf";
  //Quartz tube 240/1200
  //fileN = "../root_data_L2/Run_009_Data_9_22_2020_Binary/Run_009_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_009_tablet_240_1200.pdf";
  //Quartz tube 1200/4000
  //fileN = "../root_data_L2/Run_010_Data_9_22_2020_Binary/Run_010_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_010_tablet_1200_4000.pdf";
  //Quartz tube 500/1200
  //fileN = "../root_data_L2/Run_012_Data_9_22_2020_Binary/Run_012_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_012_tablet_500_1200.pdf";
  //Quartz box
  //fileN = "../root_data_L2/Run_013_Data_9_22_2020_Binary/Run_013_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_013_box.pdf";
  //Quartz box grease
  //fileN = "../root_data_L2/Run_014_Data_9_22_2020_Binary/Run_014_Data_9_22_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_014_box_grease.pdf";
  //Quartz box glue
  //fileN = "../root_data_L2/Run_015_Data_9_23_2020_Binary/Run_015_Data_9_23_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_015_box_glue.pdf";
  //Quartz box de-polishing 150
  //fileN = "../root_data_L2/Run_016_Data_9_23_2020_Binary/Run_016_Data_9_23_2020_Binary.bin.L1.root.L2.root";  
  //fileN_outPDf="RunID_016_box_de_polishing_150.pdf";
  
  TFile *f1 = new TFile(fileN.Data());

  TH1D *h1_10 = (TH1D*)f1->Get("h1_amplMax_ch_0");
  TH1D *h1_20 = (TH1D*)f1->Get("h1_amplMax_cut_ch_0");
  TH1D *h1_11 = (TH1D*)f1->Get("h1_amplMax_ch_2");
  TH1D *h1_21 = (TH1D*)f1->Get("h1_amplMax_cut_ch_2");
  TH1D *h1_12 = (TH1D*)f1->Get("h1_deltaTimeCFD_ch_2");
  TH1D *h1_22 = (TH1D*)f1->Get("h1_deltaTimeCFD_cut_ch_2");
  //TH1D *h1_1 = (TH1D*)f1->Get("h1_sigRiseT_ch_2");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_sigRiseT_cut_ch_2");
  //
  TH1D *h1_13 = (TH1D*)f1->Get("h1_amplMax_ch_1");
  TH1D *h1_23 = (TH1D*)f1->Get("h1_amplMax_cut_ch_1");
  //
  TH1D *h1_14 = (TH1D*)f1->Get("h1_sigChargeInWindowVT_ch_1");
  TH1D *h1_24 = (TH1D*)f1->Get("h1_sigChargeInWindowVT_cut_ch_1");
  //
  //TH1D *h1_15 = (TH1D*)f1->Get("h1_sigFallT_ch_1");
  //TH1D *h1_25 = (TH1D*)f1->Get("h1_sigFallT_cut_ch_1");
  TH1D *h1_15 = (TH1D*)f1->Get("h1_deltaTimeCFD_ch_1");
  TH1D *h1_25 = (TH1D*)f1->Get("h1_deltaTimeCFD_cut_ch_1");

  //TH1D *h1_1 = (TH1D*)f1->Get("h1_sigChargeInWindowVT_ch_2");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_sigChargeInWindowVT_cut_ch_2");
  //TH1D *h1_3 = (TH1D*)f1->Get("h1_sigChargeInWindowVT_cutCpFM2_ch_2");

  //Double_t nPions = h1_sigChargeInWindowVT_cut_ch_1->GetEntries();
  //Double_t nSigCpFM1 = h1_sigChargeInWindowVT_cutCpFM1_ch_1->GetEntries();
  //Double_t nSigCpFM2 = h1_sigChargeInWindowVT_cutCpFM2_ch_2->GetEntries();

  //cout<<"                 Number of selected pions  = "<<nPions<<endl
  //  <<"             Number of triggers from CpFM1 = "<<nSigCpFM1<<endl
  //  <<"             Number of triggers from CpFM2 = "<<nSigCpFM2<<endl;

  //Double_t nPE_CpFM1 = -TMath::Log((nPions - nSigCpFM1)/nPions);
  //Double_t nPE_CpFM2 = -TMath::Log((nPions - nSigCpFM2)/nPions);

  //cout<<" Number of detected p.e. per pion by CpFM1 = "<<nPE_CpFM1<<endl
  //  <<" Number of detected p.e. per pion by CpFM2 = "<<nPE_CpFM2<<" "<<endl
  //  <<"              Crostalk from CpFM1 to CpFM2 = "<<nPE_CpFM2*100/nPE_CpFM1<<" %"<<endl;

  //TH1D *h1_1 = (TH1D*)f1->Get("h1_amplMax_ch_2");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_amplMax_cut_ch_2");
  //TH1D *h1_3 = (TH1D*)f1->Get("h1_amplMax_cutCpFM2_ch_2");

  //TH1D *h1_1 = (TH1D*)f1->Get("h1_delta_timeCFD_CpFM2_m_trig");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_delta_timeCFD_CpFM2_m_trig_cut");
  //TH1D *h1_3 = (TH1D*)f1->Get("h1_delta_timeCFD_CpFM2_m_trig_cutCpFM2");

  //TH1D *h1_1 = (TH1D*)f1->Get("h1_amplMaxTime_ch_0");
  //TH1D *h1_1 = (TH1D*)f1->Get("h1_timeCFD_ch_0");
  //TH1D *h1_1 = (TH1D*)f1->Get("h1_amplMax_ch_0");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_amplMax_cut_ch_0");
  //TH1D *h1_1 = (TH1D*)f1->Get("h1_sigChargeInWindowVT_ch_1");
  //TH1D *h1_2 = (TH1D*)f1->Get("h1_sigChargeInWindowVT_cut_ch_1");

  h1_10->Rebin(80);
  h1_20->Rebin(80);
  h1_11->Rebin(80);
  h1_21->Rebin(80);
  h1_13->Rebin(10);
  h1_23->Rebin(10);
  h1_14->Rebin(4);
  h1_24->Rebin(4);
  h1_15->Rebin(2);
  h1_25->Rebin(2);
  //h1_3->Rebin(4);

  h1_10->SetTitle("trig0");
  h1_11->SetTitle("trig3");
  h1_12->SetTitle("#Delta t_{CFD} time_{trig3} - time_{trig0}");
  h1_13->SetTitle("PMT");
  h1_14->SetTitle("PMT");
  //h1_15->SetTitle("Fall time, ns");
  h1_15->SetTitle("#Delta t_{CFD} time_{pmt} - time_{trig0}");

  //TCanvas *c1 = new TCanvas("c1",fileN.Data(),10,10,800,800);
  //TCanvas *c1 = new TCanvas("c1",fileN.Data(),10,10,600,600);
  TCanvas *c1 = new TCanvas("c1",fileN.Data(),10,10,1800,1000);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  //gStyle->SetOptStat(kFALSE);
  //
  h1_10->SetLineColor(kBlack);
  h1_20->SetLineColor(kRed);
  h1_10->SetLineWidth(2.0);
  h1_20->SetLineWidth(2.0);
  //
  h1_11->SetLineColor(kBlack);
  h1_21->SetLineColor(kRed);
  h1_11->SetLineWidth(2.0);
  h1_21->SetLineWidth(2.0);
  //
  h1_12->SetLineColor(kBlack);
  h1_22->SetLineColor(kRed);
  h1_12->SetLineWidth(2.0);
  h1_22->SetLineWidth(2.0);
  //
  h1_13->SetLineColor(kBlack);
  h1_23->SetLineColor(kRed);
  h1_13->SetLineWidth(2.0);
  h1_23->SetLineWidth(2.0);
  //
  h1_14->SetLineColor(kBlack);
  h1_24->SetLineColor(kRed);
  h1_14->SetLineWidth(2.0);
  h1_24->SetLineWidth(2.0);
  //
  h1_15->SetLineColor(kBlack);
  h1_25->SetLineColor(kRed);
  h1_15->SetLineWidth(2.0);
  h1_25->SetLineWidth(2.0);
  //
  c1->Divide(3,2);
  //
  c1->cd(1);
  h1_10->Draw();
  h1_20->Draw("sames");
  h1_10->GetXaxis()->SetTitle("Amplitude, V");
  h1_10->GetXaxis()->SetRangeUser( -0.1, 1.4);
  //
  c1->cd(2);
  h1_11->Draw();
  h1_21->Draw("sames");
  h1_11->GetXaxis()->SetTitle("Amplitude, V");
  h1_11->GetXaxis()->SetRangeUser( -0.1, 2.1);
  //
  c1->cd(3);
  gPad->SetLogy();
  h1_12->Draw();
  h1_22->Draw("sames");
  h1_12->GetXaxis()->SetTitle("#Delta time, ns");
  h1_12->GetXaxis()->SetRangeUser( 5, 15);
  //
  c1->cd(4);
  gPad->SetLogy();
  h1_13->Draw();
  h1_23->Draw("sames");
  h1_13->GetXaxis()->SetTitle("Amplitude, V");
  h1_13->GetXaxis()->SetRangeUser( 0.0, 0.4);
  //h1_13->GetXaxis()->SetRangeUser( 0.04, 0.2);
  //h1_13->GetXaxis()->SetRangeUser( 0.02, 0.2);
  //h1_13->GetXaxis()->SetRangeUser( 0.0, 0.2);
  //
  c1->cd(5);
  gPad->SetLogy();
  h1_14->Draw();
  h1_24->Draw("sames");
  h1_14->GetXaxis()->SetTitle("Charge, nVs");
  h1_14->GetXaxis()->SetRangeUser(0.0, 3.0);
  //h1_14->GetXaxis()->SetRangeUser(0.2, 1.5);
  //h1_14->GetXaxis()->SetRangeUser(0.1, 1.5);
  //h1_14->GetXaxis()->SetRangeUser(0.0, 1.5);
  //
  c1->cd(6);
  gPad->SetLogy();
  h1_15->Draw();
  h1_25->Draw("sames");
  h1_15->GetXaxis()->SetTitle("#Delta time, ns");
  h1_15->GetXaxis()->SetRangeUser( 5, 25);
  //h1_15->GetXaxis()->SetRangeUser( 10, 20);
  //h1_15->GetXaxis()->SetTitle("#Fall time, ns");
  //h1_15->GetXaxis()->SetRangeUser( 0.0, 50.0);
  //h1_10->Draw();
  //h1_20->Draw("sames");

  c1->SaveAs(fileN_outPDf.Data());
  
  //h1_2->Draw();
  //h1_2->Fit("gaus");
  //h1_1->SetMaximum(20000);
  //h1_1->GetXaxis()->SetTitle("#Delta time (Trig3 - Trig1), ns");
  //h1_1->GetXaxis()->SetRangeUser( -12.0, -6.0);

  //h1_2->Fit("gaus");
  /*
  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  leg->AddEntry(h1_1, "All tracks (e^{-} @ 5.6 GeV/c)","l");
  leg->AddEntry(h1_2, "Selected good tracks (e^{-} @ 5.6 GeV/c)","l");
  leg->Draw();
  */
  
  return 0;
}
