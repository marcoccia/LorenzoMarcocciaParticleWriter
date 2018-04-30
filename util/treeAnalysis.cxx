#include <iostream>
#include <stdlib.h>
// ADDING ROOT HEADERS
#include "TTree.h"
#include "TH1.h"
#include "TFile.h"
#include "TObject.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TF1.h"
#include "TStyle.h"
#include "TColor.h"
#include "TGraph.h"
#include "TLine.h"
#include "TProfile.h"


using namespace std;
int main()
{
 	TFile *f = new TFile("file.root"); 
	cout<<"Reading file.root......"<<endl;
	TTree *t_el = (TTree*)f->Get("electrons");
	TTree *t_mu = (TTree*)f->Get("muons");
	TTree *t_pi = (TTree*)f->Get("pions");
	
	TH1F *h_el_plus = new TH1F("helectronsplus","Electrons energy", 25, 0., 600.);
	TH1F *h_mu_plus = new TH1F("hmuonsplus","Muons energy",         25, 0., 600.);
	TH1F *h_pi_plus = new TH1F("hpionsplus","Pions energy",         25, 0., 600.);
	TH1F *h_el_minus = new TH1F("helectronsminus","electronsminus_E",25, 0., 600.);
	TH1F *h_mu_minus = new TH1F("hmuonsminus","muonsminus_E",        25, 0., 600.);
	TH1F *h_pi_minus = new TH1F("hpionsminus","pionsminus_E",        25, 0., 600.);
 	
	int charge_el; t_el->SetBranchAddress("charge", &charge_el);
	int charge_mu; t_mu->SetBranchAddress("charge", &charge_mu);
	int charge_pi; t_pi->SetBranchAddress("charge", &charge_pi);
	float energy_el; t_el->SetBranchAddress("e", &energy_el);
	float energy_mu; t_mu->SetBranchAddress("e", &energy_mu);
	float energy_pi; t_pi->SetBranchAddress("e", &energy_pi);
	
	for(int i=0; i<t_el->GetEntries(); i++){
		t_el->GetEntry(i);
		if(charge_el==-1)     h_el_minus->Fill(energy_el);
		else if(charge_el==1) h_el_plus->Fill(energy_el);
	}
	
	for(int j=0; j<t_mu->GetEntries(); j++){
		t_mu->GetEntry(j);
		if(charge_mu==-1)     h_mu_minus->Fill(energy_mu);
		else if(charge_mu==1) h_mu_plus->Fill(energy_mu);
	}
	
	for(int k=0; k<t_pi->GetEntries(); k++){
		t_pi->GetEntry(k);
		if(charge_pi==-1)    h_pi_minus->Fill(energy_pi);
		else if(charge_pi==1)h_pi_plus->Fill(energy_pi);
	}

	TFile *file = TFile::Open("macros/fit.root","UPDATE");
	
// ------------------------------------- ELECTRONS ---------------------------------------------------------------------------
 	TCanvas *c1= new TCanvas("c1","1",1400,700);
	TLegend *leg = new TLegend(0.65,0.65,0.95,0.85); 
	
	leg->SetFillStyle(0); leg->SetBorderSize(0); 
	leg->AddEntry(h_el_plus, "e^{+}", "lep"); 
	leg->AddEntry(h_el_minus,"e^{-}", "lep"); 
	gStyle->SetOptStat(0);
			
	cout<<"Fitting energy distributions of electrons and showing fit results......"<<endl;
	cout<<"---------------------------- ELECTRONS FIT RESULT ------------------------------------"<<endl;
	
	TF1 *fel_plus = new TF1("fel_plus","gaus",0.,1500.);
	h_el_plus->Fit(fel_plus);
 	h_el_plus->SetLineColor(kRed);
 	fel_plus->SetLineColor(kRed);
	h_el_plus->GetYaxis()->SetTitle("Events");
	h_el_plus->GetXaxis()->SetTitle("Energy [GeV]");
	
	cout<<"                  "<<endl;
	cout<<"  e+ ChiSquare/NDF = "<<(fel_plus->GetChisquare()*1.)/(fel_plus->GetNDF()*1.)<<endl;    
	cout<<"                  "<<endl;
	
	TF1 *fel_minus = new TF1("fel_minus","gaus",0.,1500.);
	h_el_minus->Fit(fel_minus);
 	h_el_minus->SetLineColor(kBlack);
	fel_minus->SetLineColor(kBlack);
	h_el_minus->GetYaxis()->SetTitle("Events");
	h_el_minus->GetXaxis()->SetTitle("Energy [GeV]");
	cout<<"                  "<<endl;
	cout<<"  e- ChiSquare/NDF = "<<(fel_minus->GetChisquare()*1.)/(fel_minus->GetNDF()*1.)<<endl;    
	cout<<"                  "<<endl;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	
	h_el_plus ->Draw("E");
	h_el_minus->Draw("E same");
	fel_plus->Draw("same");
	fel_minus->Draw("same");
	leg->Draw();
	c1->Write("electronFit",TObject::kOverwrite);
 	c1->SaveAs("macros/electrons.png");
 		
// ------------------------------------- MUONS --------------------------------------------------------------------------
	
	TCanvas *c2= new TCanvas("c2","2",1400,700);
	c2->cd();
	TLegend *leg2 = new TLegend(0.65,0.65,0.95,0.85); 
	
	leg2->SetFillStyle(0); leg2->SetBorderSize(0); 
	leg2->AddEntry(h_mu_plus, "#mu^{+}","lep"); 
	leg2->AddEntry(h_mu_minus,"#mu^{-}","lep"); 
	gStyle->SetOptStat(0);
	
	cout<<"Fitting energy distributions of muons and showing fit results......"<<endl;
	cout<<"---------------------------- MUONS FIT RESULT ------------------------------------"<<endl;
	
	TF1 *fel_plus2 = new TF1("fel_plus2","gaus",0.,1500.);
	h_mu_plus->Fit(fel_plus2);
	h_mu_plus->SetLineColor(kRed);
	fel_plus2->SetLineColor(kRed);
	h_mu_plus->GetYaxis()->SetTitle("Events");
	h_mu_plus->GetXaxis()->SetTitle("Energy [GeV]");
	h_mu_plus->SetMaximum(400);
	
	cout<<"                  "<<endl;
	cout<<"  mu+ ChiSquare/NDF = "<<(fel_plus2->GetChisquare()*1.)/(fel_plus2->GetNDF()*1.)<<endl;    
	cout<<"                  "<<endl;
	
	TF1 *fel_minus2 = new TF1("fel_minus2","gaus",0.,1500.);
	h_mu_minus->Fit(fel_minus2);
	h_mu_minus->SetLineColor(kBlack);
	fel_minus2->SetLineColor(kBlack);
	
	cout<<"                  "<<endl;
	cout<<"  mu- ChiSquare/NDF = "<<(fel_minus2->GetChisquare()*1.)/(fel_minus2->GetNDF()*1.)<<endl;    
	cout<<"                  "<<endl;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	
	h_mu_plus ->Draw("E");
	h_mu_minus->Draw("E same");
	fel_plus2->Draw("same");
	fel_minus2->Draw("same");
	leg2->Draw();
	c2->Write("muonFit",TObject::kOverwrite);	
	c2->SaveAs("macros/muons.png");
		
// ------------------------------------- PIONS --------------------------------------------------------------------------

	TCanvas *c3= new TCanvas("c3","3",1400,700);
	c3->cd();
	TLegend *leg3 = new TLegend(0.65,0.65,0.95,0.85); 
	
	leg3->SetFillStyle(0); leg3->SetBorderSize(0); 
	leg3->AddEntry(h_mu_plus, "#pi^{+}","lep"); 
	leg3->AddEntry(h_mu_minus,"#pi^{-}","lep"); 
	gStyle->SetOptStat(0);
	
	cout<<"Fitting energy distributions of pions and showing fit results......"<<endl;
	cout<<"---------------------------- PIONS FIT RESULT ------------------------------------"<<endl;
	
	TF1 *fel_plus3 = new TF1("fel_plus3","gaus",0.,1500.);
	h_pi_plus->Fit(fel_plus3);
	h_pi_plus->SetLineColor(kRed);
	fel_plus3->SetLineColor(kRed);
	h_pi_plus->GetYaxis()->SetTitle("Events");
	h_pi_plus->GetXaxis()->SetTitle("Energy [GeV]");

	cout<<"                  "<<endl;
	cout<<"  pi+ ChiSquare/NDF = "<<(fel_plus3->GetChisquare()*1.)/(fel_plus3->GetNDF()*1.)<<endl;    
	cout<<"                  "<<endl;
	
	TF1 *fel_minus3 = new TF1("fel_minus3","gaus",0.,1500.);
	h_pi_minus->Fit(fel_minus3);
	h_pi_minus->SetLineColor(kBlack);
	fel_minus3->SetLineColor(kBlack);
	h_pi_minus->GetYaxis()->SetTitle("Events");
	h_pi_minus->GetXaxis()->SetTitle("Energy [GeV]");
	cout<<"                  "<<endl;
	cout<<"  pi- ChiSquare/NDF = "<<(fel_minus3->GetChisquare()*1.)/(fel_minus3->GetNDF()*1.)<<endl;    
	cout<<"                  "<<endl;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	
	h_pi_plus ->Draw("E");
	h_pi_minus->Draw("E same");
	fel_plus3->Draw("same");
	fel_minus3->Draw("same");
	leg3->Draw();	
	c3->Write("pionFit",TObject::kOverwrite);
	c3->SaveAs("macros/pions.png");	
	file->Close();
} 
