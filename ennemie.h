#pragma once
#include "personnage.h"

class ennemie: public personnage
{
protected:
	int m_mort;

public:
	 
	//Constructeur
	ennemie();
	ennemie(std::string nom,  std::string typeNen);
	ennemie(int mort, std::string nom, int vie, int nen, std::string typeNen, equipement& Equipment);

	//Methode
	void display() override;

	//Getteur Setteur
	inline int getMort()override { return m_mort; }
	inline int getEtoile()override { return -1; }

	inline void setEtoile(int etoile) override { return; }
	inline void setMort(int mort) override { m_mort = mort; }

	virtual std::string getSigneChinois();
	virtual std::vector<std::string> getlisteRang();

};

