#include "Particle.h"
#include <cmath>

Particle::Particle(Particle::ParticleType type, double px, double py, double pz, int q) 
{
    m_type=type;
    m_px=px;
    m_py=py;
    m_pz=pz;
    m_q=q;
    if(type==Particle::ELECTRON)  m_mass = 0.511; // MeV 
    else if(type==Particle::MUON) m_mass = 105.658; 
    else if(type==Particle::PION) m_mass = 139.670; 
    else std::cout<<"WARNING, PARTICLE MUST BE electron, muon or pion"<<std::endl; 
    m_mass = -1; //so its clear that is not defined
    
}

