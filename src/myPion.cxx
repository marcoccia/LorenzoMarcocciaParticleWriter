#include "myPion.h"

#ifndef _MYPION_CXX
#define _MYPION_CXX

myPion::myPion() : LorentzMomentum()
{
	this->init();
	
}

myPion::myPion(double px, double py, double pz, int charge) : LorentzMomentum(px,py,pz,139.57)
{
	this->init();
	m_charge=charge;	
}

void myPion::init()
{
	m_lifetime=2.6e-8; //in seconds
	m_charge=0;
}

#endif