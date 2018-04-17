#ifndef _LORENTZMOMENTUM_CXX
#define _LORENTZMOMENTUM_CXX

#include "LorentzMomentum.h"
#include <iostream>

using namespace std;

LorentzMomentum::LorentzMomentum()
{
	m_px=0;
	m_py=0;
	m_pz=0;
	m_mass=0;
}

LorentzMomentum::LorentzMomentum(double px, double py, double pz, double mass)
{
	m_px=px;
	m_py=py;
	m_pz=pz;
	m_mass=mass;
}

double LorentzMomentum::getBeta() const
{
	double energy=this->getE();
	double beta=0;
	if(energy<0.000001)
	{
		std::cout<<"ERROR in LorentzMomentum::getBeta(), energy is 0!"<<std::endl;
	}
	else beta=this->getP()/this->getE();
	return beta;
}

double LorentzMomentum::getGamma() const
{
	double beta=this->getBeta();
	double gamma=-1;
	if(beta==1.)
	{
		std::cout<<"ERROR in LorentzMomentum::getGamma(), beta is 1 so gamma would be infinite!"<<std::endl;
	}
	else gamma=(1./(sqrt(1-pow(beta,2))));
	return gamma;
}

void LorentzMomentum::Print() const
{
	cout<<"LorMom px="<<m_px<<" py="<<m_py<<" pz="<<m_pz<<" mass "<<m_mass<<" energy "<<getE()<<endl;
	//we can also write cout<<"LorMom px="<<m_px<<" py="<<m_py<<" pz="<<m_pz<<" mass "<<m_mass<<" energy "<<this->getE()<<endl;
	//or cout<<"LorMom px="<<this->getPX()<<" py="<<this->getPY()<<" pz="<<this->getPZ()<<" mass "<<this->getMass()<<" energy "<<this->getE()<<endl;
}
#endif
