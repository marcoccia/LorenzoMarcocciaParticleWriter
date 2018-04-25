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
    TFile *f = new TFile("myfile.root","UPDATE");	
    TTree *particle[3];
	
    particle[0] = new TTree ("Electrons", "Electrons");
    particle[1] = new TTree ("Muons", "Muons");
    particle[2] = new TTree ("Pions", "Pions");
	
    float px, py, pz, m;
    int ID, charge;
	
    for (int i=0; i<=2; i++){
        particle[i]->Branch("ID",     &ID,     "ID/I");
        particle[i]->Branch("charge", &charge, "charge/I");
        particle[i]->Branch("px",     &px,     "eta/F"); 
        particle[i]->Branch("py",     &py,     "phi/F"); 
        particle[i]->Branch("pz",     &pz,     "pt/F"); 
        particle[i]->Branch("m",      &m,      "m/F");        
	}
    
    ifstream myfile ("/data/Tutorial_lorenzo_05/myFirstRepository/particle_list.txt");
    string line, type_string, charge_string, px_string, py_string, pz_string;
    vector <string> v;
    int rowcount=0;
    
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
            
                if ( type_string=="electron") {
                    myElectron *electron = new myElectron(atof(px_string.c_str()), atof(py_string.c_str()), atof(pz_string.c_str()), atof(charge_string.c_str()) );
                    ID = 0;
                    m  = electron->getMass();
                    px = electron->getPX();
                    py = electron->getPY();
                    pz = electron->getPZ();
                    charge = electron->getCharge();
//                     delete electron;
                }
                if ( type_string=="muon" ) {
                    myMuon *muon = new myMuon(atof(px_string.c_str()), atof(py_string.c_str()), atof(pz_string.c_str()), atof(charge_string.c_str()) );
                    ID = 1;
                    m  = muon->getM();
                    px = muon->getPX();
                    py = muon->getPY();
                    pz = muon->getPZ();
                    charge = muon->getCharge();
                    delete muon;
                 }
                 if ( type_string=="pion" ) {
                    myPion *pion = new myPion(atof(px_string.c_str()), atof(py_string.c_str()), atof(pz_string.c_str()), atof(charge_string.c_str()) );
                    ID = 2;
                    m  = pion->getMass();
                    px = pion->getPX();
                    py = pion->getPY();
                    pz = pion->getPZ();
                    charge = pion->getCharge();
//                     delete pion;
                 }
            }
        }
            f->Close();	
            
    
    }
    else cout<<" FILE NOT FOUND"<<endl;
    
    // STORE TREES
    for (int i=0; i<=2; i++){
	particle[i]->Write("",TObject::kOverwrite);
    }
    
    
    return 0;
}