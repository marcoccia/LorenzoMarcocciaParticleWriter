#include <iostream>
#include <cmath>

using namespace std;

#ifndef _LORENTZMOMENTUM_H
#define _LORENTZMOMENTUM_H

class LorentzMomentum{
	
	public:
		LorentzMomentum();
		LorentzMomentum(double px, double py, double pz, double m);
		double getPX() const {return m_px;}
		double getPY() const {return m_py;}
		double getPZ() const {return m_pz;}
		double getMass() const {return m_mass;}
		double getE()const {return sqrt(pow(m_px,2)+pow(m_py,2)+pow(m_pz,2)+pow(m_mass,2));}
		double getP() const {return sqrt(pow(m_px,2)+pow(m_py,2)+pow(m_pz,2));};
		void setPX(double px){m_px=px;}
		void setPY(double py){m_py=py;}
		void setPZ(double pz){m_pz=pz;}
		void setMass(double mass){m_mass=mass;}
		double getBeta() const;
		double getGamma() const;
		void Print() const;
	
	private:
		double m_px,m_py,m_pz,m_mass;
};

#endif
