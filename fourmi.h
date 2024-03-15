#pragma once
#include "ennemie.h"

class fourmi : public ennemie
{
private:
	std::string m_rang;

public:

	//Constructeur 
	fourmi();
	fourmi(std::string rang);

	//Methode
	void display() override;

	//Getteur
	inline std::string getRang() { return m_rang; }

};

std::vector<std::string> getlisteRang() ;
void removeRang();