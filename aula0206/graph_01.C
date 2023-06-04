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

void graph_01(){

  //auto grBSMn  = new TGraph("BSMprobability_cmueDUNEn.dat");
    auto grmue  = new TGraph("probability_vac_mu_e.dat");
    auto grmumu  = new TGraph("probability_vac_mu_mu.dat");
    auto grmutau = new TGraph("probability_vac_mu_tau.dat");
    

    grmumu->GetXaxis()->SetRangeUser(0.25,10.0);
    grmumu->GetYaxis()->SetRangeUser(0,1);
    //gr->GetYaxis()->SetRangeUser(0,0.2);
    grmumu->SetTitle("Probabilidade de oscilacao mu");
    grmumu->GetXaxis()->CenterTitle();
    grmumu->GetYaxis()->CenterTitle();
    grmumu->GetYaxis()->SetNdivisions(505);

    
    
    
    grmumu->SetLineWidth(2);
    grmue->SetLineColor(kBlue);
    grmue->SetLineWidth(2);
    grmutau->SetLineColor(kRed);
    grmutau->SetLineWidth(2);
    

    grmumu->Draw();
    grmue->Draw("SAME");
    grmutau->Draw("SAME");
}