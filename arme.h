#pragma once
#include <iostream>
#include <string>

class arme
{
private:

	int m_dur;
	std::string m_name;
	int m_degat;

public:

	//Constructeur / Destructeur
	arme();
	arme(std::string nom, int degats,int dur);
	arme(arme const& Arme);
	~arme();

	//Methode
	virtual void recevoirDegat(int degat);
	virtual inline bool isAlive() { return m_dur > 0; }

	//Getteur Setteur
	inline int getDegat() { return m_degat; }
	inline std::string getNom() { return m_name; }
	inline int getDur() { return m_dur; }


	inline void setDegat(int degat) { m_degat = degat; }
	inline void setNom(std::string nom) { m_name = nom; }
	inline void setDur(int dur) { m_dur = dur; }

};

//Operator pour std::cout << 
std::ostream& operator<<(std::ostream& os, arme& d);