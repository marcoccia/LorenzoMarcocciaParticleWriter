#include "LorentzMomentum.h"

using namespace std;

#ifndef _MYPION_H
#define _MYPION_H

class myPion : public LorentzMomentum{
	
	public:
		myPion();
		myPion(double px, double py, double pz, int charge);
		~myPion();
		double getCharge() const {return m_charge;}		
		double getProperLifetime() const {return m_lifetime;};
		double getLabLifetime() const {return this->getGamma()*m_lifetime;}
			
	private:
		double m_lifetime;
		int m_charge;
		
		void init();
		
};

#endif