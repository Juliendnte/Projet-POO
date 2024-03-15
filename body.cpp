#include "body.h"


body::body() {
	m_dur = 0;
	m_name = "Rien";
}

body::body(int dur, std::string name) {
	m_dur = dur;
	m_name = name;
}

body::body(body const& Body) {
	m_dur = Body.m_dur;
	m_name = Body.m_name;
}

body::~body() {}

void body::recevoirDegat(int degat) {
	if (m_name != "Rien") 
		m_dur -= degat;
}

std::ostream& operator<<(std::ostream& os, body& d) {
	os << d.getName() << " / " << std::to_string(d.getDur()) << " PV         ";

	return os;
}