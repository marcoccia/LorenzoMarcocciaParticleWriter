#include "myElectron.h"

#ifndef _MYELECTRON_CXX
#define _MYELECTRON_CXX

myElectron::myElectron() : LorentzMomentum()
{
	this->init();
	
}

myElectron::myElectron(double px, double py, double pz, int charge) : LorentzMomentum(px,py,pz,0.511)
{
	this->init();
	m_charge=charge;	
}

void myElectron::init()
{
	m_lifetime=10e30; //in seconds
	m_charge=0;
}

#endif
