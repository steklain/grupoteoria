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

void make_plot(){

   auto gr  = new TGraph("probability_DUNE_mu_tau.dat"); //nome do arquivo.dat

    gr->GetXaxis()->SetRangeUser(0.25,10.0);
    gr->GetYaxis()->SetRangeUser(0,1);
    //gr->GetYaxis()->SetRangeUser(0,0.2);
    gr->SetTitle("Probability mu->tau"); // titulo
    gr->GetXaxis()->CenterTitle();
    gr->GetYaxis()->CenterTitle();
    gr->GetYaxis()->SetNdivisions(505);

    gr->SetLineStyle(7);
    
    
    gr->SetLineColor(kBlue);
    gr->SetLineWidth(2);
    

    gr->Draw();
    
}