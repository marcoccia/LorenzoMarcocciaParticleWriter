#include "LorentzMomentum.h"

using namespace std;

#ifndef _MYOTHERMUON_H
#define _MYOTHERMUON_H

class myOtherMuon : public LorentzMomentum{
	
	public:
		myOtherMuon();
		myOtherMuon(double px, double py, double pz, int charge);
		~myOtherMuon();
		//double getPX() const {return m_lm->getPX();}
		//double getPY() const {return m_lm->getPY();}
		//double getPZ() const {return m_lm->getPZ();}
		//double getM() const {return m_lm->getMass();}
		//double getE()const {return m_lm->getE();}
		//double getBeta() const {return m_lm->getBeta();}
		//double getGamma() const {return m_lm->getGamma();}
		double getCharge() const {return m_charge;}
		//void setPX(double px){m_lm->setPX(px);}
		//void setPY(double py){m_lm->setPY(py);}
		//void setPZ(double pz){m_lm->setPZ(pz);}
		//void setM(double mass){m_mass=mass;} -> WE DON'T WANT THIS, MUONS HAVE ALWAYS THE SAME MASS
		double getProperLifetime() const {return m_lifetime;};
		//double getLabLifetime() const {return m_lm->getGamma()*m_lifetime;}
		double getLabLifetime() const {return this->getGamma()*m_lifetime;}
		
	
	private:
		//LorentzMomentum *m_lm;
		double m_lifetime;
		int m_charge;
		
		void init();
		
};

#endif
