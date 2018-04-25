#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include "Particle.h"    
#include "myMuon.h"
#include "myElectron.h"
#include "myPion.h"
#include "LorentzMomentum.h"
// ADDING ROOT HEADERS
#include "TTree.h"
#include "TFile.h"
#include "TObject.h"
using namespace std;

int main()
{
    TFile *f = new TFile("file.root","RECREATE");	
    TTree *particle[3];
	
    particle[0] = new TTree ("electrons", "electrons");
    particle[1] = new TTree ("muons", "muons");
    particle[2] = new TTree ("mions", "pions");
	
    float px, py, pz, m;
    int pid, charge;
	
    for (int i=0; i<=2; i++){
        particle[i]->Branch("pid",    &pid,    "pid/I");
        particle[i]->Branch("charge", &charge, "charge/I");
        particle[i]->Branch("px",     &px,     "px/F"); 
        particle[i]->Branch("py",     &py,     "py/F"); 
        particle[i]->Branch("pz",     &pz,     "pz/F"); 
        particle[i]->Branch("m",      &m,      "m/F");        
    }

    int rowcount=0;
	ifstream myfile ("particle_list.txt");
    string line, type_string, charge_string, px_string, py_string, pz_string;
    vector <string> v;

     if (myfile.is_open()){
		
        while ( getline (myfile,line) ){
            rowcount++;
            if (rowcount>2){ //skip the first two lines
                istringstream buf(line);
                vector <string> v;
                for(string word; buf >> word; ) v.push_back(word);			
                type_string   = v[0];
                charge_string = v[1];
                px_string     = v[2];
                py_string     = v[3];
                pz_string     = v[4];
            
                if (type_string=="electron") {
                    myElectron *electron = new myElectron(atof(px_string.c_str()), atof(py_string.c_str()), atof(pz_string.c_str()), atof(charge_string.c_str()) );
                    pid = 0;
                    m  = electron->getMass();
                    px = electron->getPX();
                    py = electron->getPY();
                    pz = electron->getPZ();
                    charge = electron->getCharge();
                    particle[0]->Fill();
                }
                else if (type_string=="muon" ) {
                    myMuon *muon = new myMuon(atof(px_string.c_str()), atof(py_string.c_str()), atof(pz_string.c_str()), atof(charge_string.c_str()) );
                    pid = 1;
                    m  = muon->getM();
                    px = muon->getPX();
                    py = muon->getPY();
                    pz = muon->getPZ();
                    charge = muon->getCharge();
                    particle[1]->Fill();
                 }
                 else if (type_string=="pion" ) {
                    myPion *pion = new myPion(atof(px_string.c_str()), atof(py_string.c_str()), atof(pz_string.c_str()), atof(charge_string.c_str()) );
                    pid = 2;
                    m  = pion->getMass();
                    px = pion->getPX();
                    py = pion->getPY();
                    pz = pion->getPZ();
                    charge = pion->getCharge();
                    particle[2]->Fill();
                 }
            } 
        }
         
        myfile.close();

    }
    else cout<<" FILE NOT FOUND"<<endl;
 //   STORE TREES
     for (int j=0; j<=2; j++){
 	particle[j]->Write("",TObject::kOverwrite);
     }
    
    return 0;
}
