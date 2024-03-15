#include "head.h"


head::head() {
	m_dur = 0;
	m_name = "Rien";
}

head::head(int dur, std::string name) {
	m_dur = dur;
	m_name = name;
}

head::head(head const& Head) {
	m_dur = Head.m_dur;
	m_name = Head.m_name;
}

head::~head() {
	std::cout << "head suppr" << std::endl;
}

void head::recevoirDegat(int degat) {
	if (m_name != "Rien")
		m_dur -= degat;
}

std::ostream& operator<<(std::ostream& os, head& d) {
	os << d.getName() << " / " << std::to_string(d.getDur()) << " PV       ";

	return os;
}