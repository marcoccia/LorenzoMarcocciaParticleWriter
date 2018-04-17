#include "myMuon.h"

#ifndef _MYMUON_CXX
#define _MYMUON_CXX

myMuon::myMuon()
{
	this->init();
	
}

myMuon::myMuon(double px, double py, double pz, int charge)
{
	this->init();
	m_charge=charge;
	m_lm->setPX(px);
	m_lm->setPY(py);
	m_lm->setPZ(pz);		
}

void myMuon::init()
{
	m_lm=new LorentzMomentum();
	m_lm->setMass(105.658); //in MeV
	m_lifetime=2.196e-6; //in seconds
	m_charge=0;
}

myMuon::~myMuon()
{
	delete m_lm;
}

#endif
