#pragma once
#include "hero.h"

class zodiaque: public hero
{
private:
	std::string m_signe_chinois;
public:

	//Constructeur 
	zodiaque(std::string signe);

	//Methode
	void display() override;

	//Getteur
	inline std::string getSigneChinois() override { return m_signe_chinois; }
};

std::vector<std::string> getlisteSignes();
void remove(std::string strToRemove);