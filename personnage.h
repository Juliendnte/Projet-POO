#pragma once
#include "equipement.h"
#include <vector>

class personnage
{
protected:
	int m_vie;
	std::string m_nom;
	int m_nen;
	std::string m_typeNen;
	equipement* m_equipement;


public:

	//Constructeur / Destructeur
	personnage();
	personnage(std::string nom, std::string typeNen);
	personnage(std::string nom, int vie, int nen, std::string typeNen, equipement & Equipment);
	~personnage();

	//Methodes
	virtual void display();
	void hit(personnage& cible);
	void recevoirDegat(int degat);
	inline bool isAlive() { return m_vie > 0; }
	inline void regenNen() { setNen(m_nen + 2); }

	//Getteur Setteur
	inline std::string getNom() { return m_nom; }
	inline int getVie() { return m_vie; }
	inline int getNen() { return m_nen; }
	inline equipement* getEquipement() { return m_equipement; }
	inline std::string getTypeNen() { return m_typeNen; }

	inline void setVie(int vie) {  m_vie = vie; }
	inline void setNen(int nen) {  m_nen = nen; }
	inline void setEquipement(equipement* equipement) { m_equipement = equipement; }
	inline void setTypeNen(std::string type) { m_typeNen = type; }
	inline void setNom(std::string nom) { m_nom = nom; }

	//Virtualisation pure
	virtual inline void setEtoile(int etoile) = 0;
	virtual inline void setMort(int mort) = 0;
	virtual int getEtoile() = 0;
	virtual int getMort() = 0;
	virtual std::string getSigneChinois() = 0;
	virtual std::vector<std::string> getlisteRang() = 0;
};

int random_with_time_seed(int min, int max);
