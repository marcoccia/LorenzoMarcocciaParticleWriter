#include <iostream>
#include "LorentzMomentum.h"
#include "myOtherMuon.h"
//adding ROOT headers
#include "TRandom3.h"
#include "TFile.h"
#include "TH1F.h"

using namespace std;
double LIGHTSPEED=3e8; //3*10^8 m/s

int main()
{
	cout<<"---Welcome in runMC---"<<endl;
	
	unsigned int seed = 12345;
	TRandom3* g_rand=new TRandom3(seed);
	
	int NMUONS=1e6;
	double BEAM_PX_MEAN=1000.; //in MeV
	double BEAM_PX_WIDTH=1.; //in MeV
	
	//we prepare the output
	TFile* fout=new TFile("output.root","RECREATE");
	TH1F* h_energy=new TH1F("energy","energy", 100,0,5.);
	TH1F* h_charge=new TH1F("charge","charge", 3,-1.5,1.5);
	TH1F* h_time=new TH1F("time_decay","time of decay (milliseconds)", 100,0,1);
	TH1F* h_distance=new TH1F("distance_decay","distance of decay (meters)", 100,0,100000);
	
	//we generate a beam of NMUONS muons with a gaussianly distributed moemntum along the x axis, and momentum 0 along y and z; also
	//charge is randomly assigned
	for(int im=0; im<NMUONS; im++)
	{
		//we randomly decide a charge
		int charge=0;
		if(g_rand->Rndm()>0.5) charge=1.;
		else charge=-1;
		//we randomly decide px
		double px=g_rand->Gaus(BEAM_PX_MEAN,BEAM_PX_WIDTH);
		double py=0.;
		double pz=0.;
		if(px<0) continue; //we only keep muons moving forward
		
		myOtherMuon *muon = new myOtherMuon(px,py,pz,charge);
		//std::cout<<"created muon "<<im<<" with energy "<<muon->getE()<<" px py pz "<<muon->getPX()<<" "<<muon->getPY()<<" "<<muon->getPZ()<<" charge "<<muon->getCharge()<<" beta "<<muon->getBeta()<<" gamma "<<muon->getGamma()<<endl;

		h_energy->Fill(muon->getE());
		h_charge->Fill(muon->getCharge());
		//the probability for a muon to decay at a given time is P=e^{-t/Tau_LAB}
		//then, if we want to cacluate the random time when the particle decays, we can invert the formula
		//t=-gamma*Tau_LAB*log(P)
		//we throw a random probability
		double prob=g_rand->Rndm();
		double randomTime=-1.*muon->getLabLifetime()*log(prob);
		double distance=randomTime*muon->getBeta()*LIGHTSPEED; //the distance is in meters
		h_time->Fill(randomTime*1e3);
		h_distance->Fill(distance);
		
		delete muon;
		
	}
	fout->Write();
	//one may want to manually write things one by one instead e.g. fout->WriteTobject(h_energy);
	delete h_energy;
	delete fout;
	
	
	return 1;
}
