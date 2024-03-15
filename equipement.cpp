#include "equipement.h"

equipement::equipement() {
	m_arme = new arme();
	m_head =  new head();
	m_body = new body();
	m_legs =  new legs();
}

equipement::equipement(arme & Arme, head & Head, body & Body, legs & Legs){
	m_arme = &Arme;
	m_head = &Head;
	m_body = &Body;
	m_legs = &Legs;
}

equipement::equipement( head& Head, body& Body, legs& Legs) {
	m_arme = new arme();
	m_head = &Head;
	m_body = &Body;
	m_legs = &Legs;
}

equipement::equipement(arme& Arme) {
	m_arme = &Arme;
	m_head = new head();
	m_body = new body();
	m_legs = new legs();
}

equipement::~equipement() {
	std::cout << "equipement detruit" << std::endl;
	delete m_arme;
	delete m_head;
	delete m_body;
	delete m_legs;
}