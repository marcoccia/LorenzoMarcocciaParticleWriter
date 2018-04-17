#include "myOtherMuon.h"

#ifndef _MYOTHERMUON_CXX
#define _MYOTHERMUON_CXX

myOtherMuon::myOtherMuon() : LorentzMomentum()
{
	this->init();
	
}

myOtherMuon::myOtherMuon(double px, double py, double pz, int charge) : LorentzMomentum(px,py,pz,105.658)
{
	this->init();
	m_charge=charge;
	//m_lm->setPX(px);
	//m_lm->setPY(py);
	//m_lm->setPZ(pz);		
}

void myOtherMuon::init()
{
	//m_lm=new LorentzMomentum();
	//m_lm->setMass(105.658); //in MeV
	m_lifetime=2.196e-6; //in seconds
	m_charge=0;
}

myOtherMuon::~myOtherMuon()
{
	//delete m_lm;
}

#endif
