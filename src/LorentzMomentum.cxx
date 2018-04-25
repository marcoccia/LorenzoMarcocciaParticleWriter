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

LorentzMomentum LorentzMomentum::operator+(LorentzMomentum &c)
{
    LorentzMomentum out2= LorentzMomentum(m_px+c.getPX(), m_py+c.getPY(), m_pz+c.getPZ(), m_mass+c.getMass() );
    return out2;
}

double LorentzMomentum::operator*(LorentzMomentum &d)
{
    double out3= double(sqrt(pow(m_mass,2)+pow(m_px,2)+pow(m_py,2)+pow(m_pz,2))*d.getE() - m_px*d.getPX() - m_py*d.getPY() - m_pz*d.getPZ());
    return out3;
}

void LorentzMomentum::Print() const
{
	cout<<"LorMom px="<<m_px<<" py="<<m_py<<" pz="<<m_pz<<" mass "<<m_mass<<" energy "<<getE()<<endl;
	//we can also write cout<<"LorMom px="<<m_px<<" py="<<m_py<<" pz="<<m_pz<<" mass "<<m_mass<<" energy "<<this->getE()<<endl;
	//or cout<<"LorMom px="<<this->getPX()<<" py="<<this->getPY()<<" pz="<<this->getPZ()<<" mass "<<this->getMass()<<" energy "<<this->getE()<<endl;
}
#endif
