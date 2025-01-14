#include "TH1.h"
#include "TH2.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TStyle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

void probplot() {
    gROOT->SetBatch(true);

    // Load the graphs
    auto stde = new TGraph("stdprob_mue.dat");
    auto stdmu = new TGraph("stdprob_mumu.dat");
    auto stdtau = new TGraph("stdprob_mutau.dat");

    auto live = new TGraph("livprob_mue.dat");
    auto livmu = new TGraph("livprob_mumu.dat");
    auto livtau = new TGraph("livprob_mutau.dat");

    // Set graph properties
    stde->GetXaxis()->SetRangeUser(0.25, 8.0);
    stdmu->GetXaxis()->SetRangeUser(0.25, 8.0);
    stdtau->GetXaxis()->SetRangeUser(0.25, 8.0);
    stde->SetTitle("Probability of Oscillation Standard vs Tandem;E (GeV); P_{#mu to #mu}");
    stde->GetXaxis()->CenterTitle();
    stde->GetYaxis()->CenterTitle();
    stde->GetYaxis()->SetNdivisions(505);

    // Set line colors
    //stde->SetLineColor(kBlue);
    //stdmu->SetLineColor(kRed);
    //stdtau->SetLineColor(kGreen);
    

    live->SetLineColor(kBlue);
    livmu->SetLineColor(kRed);
    livtau->SetLineColor(kGreen);

    // Set line styles for live graphs
    live->SetLineStyle(7);
    livmu->SetLineStyle(7);
    livtau->SetLineStyle(7);

    // Remove points by disabling markers
    stde->SetMarkerStyle(0);
    stdmu->SetMarkerStyle(0);
    stdtau->SetMarkerStyle(0);
    live->SetMarkerStyle(0);
    livmu->SetMarkerStyle(0);
    livtau->SetMarkerStyle(0);

    // Create and save the canvases
    TCanvas *canvas = new TCanvas("canvas");
    stde->Draw("AL");  // Draw axes and lines
    stdmu->Draw("L SAME");
    stdtau->Draw("L SAME");
    live->Draw("L SAME");
    livmu->Draw("L SAME");
    livtau->Draw("L SAME");
    canvas->Update();
    canvas->SaveAs("tandemprob_all.png");

    TCanvas *canvase = new TCanvas("canvase");
    canvase->SetLogx();
    stde->Draw("AL");
    live->Draw("L SAME");
    canvase->Update();
    canvase->SaveAs("tandemprob_e.png");

    TCanvas *canvasmu = new TCanvas("canvasmu");
    canvasmu->SetLogx();
    stdmu->Draw("AL");
    livmu->Draw("L SAME");
    canvasmu->Update();
    canvasmu->SaveAs("tandemprob_mu.png");

    TCanvas *canvastau = new TCanvas("canvastau");
    canvastau->SetLogx();
    stdtau->Draw("AL");
    livtau->Draw("L SAME");
    canvastau->Update();
    canvastau->SaveAs("tandemprob_tau.png");

    gApplication->Terminate(0);
}
