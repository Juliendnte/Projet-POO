#include "legs.h"


legs::legs() {
	m_dur = 0;
	m_name = "Rien";
}

legs::legs(int dur, std::string name) {
	m_dur = dur;
	m_name = name;
}

legs::legs(legs const& Legs) {
	m_dur = Legs.m_dur;
	m_name = Legs.m_name;
}

legs::~legs() {
	std::cout << "legs suppr" << std::endl;
}

void legs::recevoirDegat(int degat) {
	if (m_name != "Rien") 
		m_dur -= degat;
}

std::ostream& operator<<(std::ostream& os, legs& d) {
	os << d.getName() << " / " << std::to_string(d.getDur()) << " PV       ";
	return os;
}