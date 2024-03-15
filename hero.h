#pragma once
#include "personnage.h"

class hero: public personnage
{
protected:
	int m_etoile;

public:

	//Constructeur 
	hero();
	hero(std::string nom ,std::string typeNen);
	hero(int etoile);

	//Methodes
	void display() override;

	//Getteur Setteur
	inline int getEtoile() override { return m_etoile; }
	inline int getMort() override  { return -1; }

	inline void setEtoile(int etoile) override { m_etoile = etoile; }
	inline void setMort(int mort) override { return; }

	virtual std::string getSigneChinois();
	virtual std::vector<std::string> getlisteRang();
};

