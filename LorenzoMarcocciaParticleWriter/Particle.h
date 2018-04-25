#include <iostream>
#include <cmath>

class Particle{ 

    public:
         
        enum ParticleType{ 
            UNKNOWN=0,
            ELECTRON=1, 
            MUON=2,
            PION=3
            };
            
    Particle(Particle::ParticleType type, double px, double py, double pz, int q);
        
    private:
        ParticleType m_type;
        double m_px, m_py, m_pz, m_mass, m_q;

};

