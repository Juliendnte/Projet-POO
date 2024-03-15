#include "arme.h"


arme::arme() {
	m_degat = 10;
	m_name = "Rien";
	m_dur = 0;
}

arme::arme(std::string nom, int degats, int dur) {
	m_degat = degats;
	m_name = nom;
	m_dur = dur;
}

arme::arme(arme const& Arme) {
	m_degat = Arme.m_degat;
	m_name = Arme.m_name;
	m_dur = Arme.m_dur;
}

arme::~arme() {
	std::cout << "arme détruite" << std::endl;
}

void arme::recevoirDegat(int degat) {
	if (m_name != "Poing") 
		m_dur -= degat;
}


std::ostream& operator<<(std::ostream& os, arme& d) {
	os << d.getNom() << " / " << std::to_string(d.getDur()) << " PV / " << std::to_string(d.getDegat()) << " point d'attaque       ";

	return os;
}