#include "LorentzMomentum.h"

using namespace std;

#ifndef _MYELECTRON_H
#define _MYELECTRON_H

class myElectron : public LorentzMomentum{
	
	public:
		myElectron();
		myElectron(double px, double py, double pz, int charge);
		~myElectron();
		double getCharge() const {return m_charge;}		
		double getProperLifetime() const {return m_lifetime;};
		double getLabLifetime() const {return this->getGamma()*m_lifetime;}
			
	private:
		double m_lifetime;
		int m_charge;
		
		void init();
		
};

#endif