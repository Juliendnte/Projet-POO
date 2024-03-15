#pragma once
#include "head.h"
#include "body.h"
#include "legs.h"
#include "arme.h"


class equipement
{

private:
	head* m_head;
	body* m_body;
	legs* m_legs;
	arme* m_arme;


public:

	//Constructeur / Destructeur
	equipement();
	equipement(arme & Arme, head & Head, body & Body, legs & Legs);
	equipement(head& Head, body& Body, legs& Legs);
	equipement(arme& Arme);
	~equipement();

	//Getteur Setteur
	inline 	head* getHead() { return m_head; }
	inline 	body* getBody() { return m_body; }
	inline 	legs* getLegs() { return m_legs; }
	inline 	arme* getArme() { return m_arme; }

	inline 	void setArme(arme* arm) { m_arme = arm; }

};