#include "personnage.h"
#include <random>
#include <vector>
#include <string>
#include <chrono>

/*
Classe virtual pur sert essentiellement de placard
Chaque personnage a un type de nen est selon ce type de nen il a des stats différentes
Lorsque l'histoire commence on choisie soit Héros soit Ennemie
Si l'on prend Héros nos adversaire deviendront les Fourmies
Mais si l'on prend Ennemie nos adversaire deviendront les Zodiaques
*/

std::vector<std::string> TypeNen{
		"Renforcement",
		"Emission",
		"Transformation",
		"Materialisation",
		"Manipulation ",
		"Specification"
};

std::random_device rd;
std::mt19937 generator(rd());


personnage::personnage() {
	m_nom = "PNJ";
	std::uniform_int_distribution<int> distribution(0, TypeNen.size()-1);
	m_typeNen = TypeNen[distribution(generator)];
	if (m_typeNen == "Renforcement") {
		m_vie = 100;
		m_nen = 15;
		m_equipement = new equipement(*new head(13, "casque"), *new body(13, "plastron"), *new legs(13, "protège tibia"));
	}
	else if (m_typeNen == "Emission") {
		m_vie = 100;
		m_nen = 50;
		m_equipement = new equipement();
	}
	else if (m_typeNen == "Transformation") {
		m_vie = 100;
		m_nen = 15;
		m_equipement = new equipement(*new arme("sabre",30,3));
	}
	else if (m_typeNen == "Materialisation") {
		m_vie = 100;
		m_nen = 15;
		m_equipement = new equipement(*new arme("machette", 16, 10));
	}
	else if (m_typeNen == "Manipulation") {
		m_vie = 140;
		m_nen = 15;
		m_equipement = new equipement();
	}
	else {
		m_vie = 110;
		m_nen = 20;
		m_equipement = new equipement(*new arme("couteau",13,7), *new head(4, "chapeau"), *new body(4, "veste"), *new legs(4, "pantalon"));
	}
}

personnage::personnage(std::string nom,  std::string typeNen) {
	m_nom = nom;
	m_typeNen = typeNen;
	if (m_typeNen == "Renforcement") {
		m_vie = 100;
		m_nen = 15;
		m_equipement = new equipement(*new head(13, "casque"), *new body(13, "plastron"), *new legs(13, "protège tibia"));
	}
	else if (m_typeNen == "Emission") {
		m_vie = 100;
		m_nen = 50;
		m_equipement = new equipement();
	}
	else if (m_typeNen == "Transformation") {
		m_vie = 100;
		m_nen = 15;
		m_equipement = new equipement(*new arme("sabre", 30, 3));
	}
	else if (m_typeNen == "Materialisation") {
		m_vie = 100;
		m_nen = 15;
		m_equipement = new equipement(*new arme("machette", 16, 10));
	}
	else if (m_typeNen == "Manipulation") {
		m_vie = 140;
		m_nen = 15;
		m_equipement = new equipement();
	}
	else {
		m_vie = 110;
		m_nen = 20;
		m_equipement = new equipement(*new arme("couteau", 13, 7), *new head(4, "chapeau"), *new body(4, "veste"), *new legs(4, "pantalon"));
	}
}

personnage::personnage(std::string nom, int vie, int nen, std::string typeNen, equipement & Equipement) {
	m_nom = nom;
	m_vie = vie;
	m_nen = nen;
	m_typeNen = typeNen;
	m_equipement = &Equipement;
}


personnage::~personnage() {
	std::cout << "Personnage détruit" << std::endl;
	delete m_equipement;
}

//Methode virtual
void personnage::display() {
	std::cout << " *  <--" << *m_equipement->getHead() << "  " << std::endl;
	std::cout << "/|\\ <--" << *m_equipement->getBody() << "  " << std::endl;
	std::cout << "/ \\ <--" << *m_equipement->getLegs() << "  " << std::endl;
	std::cout << "Arme :" << *m_equipement->getArme() << "  " << std::endl;
	std::cout << "Personnage : " << m_nom << " possède " << std::to_string(m_vie) << " de pdv, a un nen de type " << m_typeNen << " avec une capacité de " << std::to_string(m_nen) + "          " << std::endl;
}

void personnage::hit(personnage& cible) {
	if (m_nen > 0) {//Si le personnage a encore du nen
		cible.recevoirDegat(m_equipement->getArme()->getDegat());//Il prend un pourcentage aléatoire de dégat sur l'une de ses armures
		m_nen -= 1;
		std::cout << "\n" + m_nom << " a attaqué " << cible.getNom() << " avec " << m_equipement->getArme()->getNom() << " de " << std::to_string(m_equipement->getArme()->getDegat()) << " point de degat       " << std::endl;
		if (m_equipement->getArme()->getDur() > 0 ) {//S'il l'a encore de la durabité
			m_equipement->getArme()->setDur(m_equipement->getArme()->getDur() - 1);//On lui baisse la durabilité de son arme
			std::cout << "L'arme " << m_equipement->getArme()->getNom() << "  a perdu 1 point de damage elle est maintenant a " << std::to_string(m_equipement->getArme()->getDur()) + "       " << std::endl;
		}
		else {//Sinon il perd son arme
			m_equipement->setArme(new arme());
		}
	}
	else {
		if (m_nom != "PNJ") {
			std::cout << "VOUS N'AVEZ PLUS DE NEN      " << std::endl;
		}
		else {
			regenNen();
		}
	}
}


void personnage::recevoirDegat(int degat) {
	int random_number = random_with_time_seed(1,4);//3 chance sur 4 que l'attaque va sur un équipement
	switch (random_number)
	{
	case 1:
		if (m_equipement->getHead()->isAlive()) {
			random_number = random_with_time_seed(0, degat-1);//L'équipement prend un nombre de dégat aléatoire
			if (random_number > m_equipement->getHead()->getDur()) {//Pour que la durabilité ne soit pas dans les négatifs
				random_number -= m_equipement->getHead()->getDur();
				m_equipement->getHead()->setDur(0);
			} else
				m_equipement->getHead()->setDur(m_equipement->getHead()->getDur() - random_number);
		}
		else
			random_number = 0;

		break;

	case 2:
		if (m_equipement->getBody()->isAlive()) {
			random_number = random_with_time_seed(0, degat-1);
			if (random_number > m_equipement->getHead()->getDur()) {
				random_number -= m_equipement->getHead()->getDur();
				m_equipement->getHead()->setDur(0);
			}
			else
				m_equipement->getHead()->setDur(m_equipement->getHead()->getDur() - random_number);
		}
		else
			random_number = 0;
		break;

	case 3:
		if (m_equipement->getLegs()->isAlive()) {
			random_number = random_with_time_seed(0, degat);
			if (random_number > m_equipement->getHead()->getDur()) {
				random_number -= m_equipement->getHead()->getDur();
				m_equipement->getHead()->setDur(0);
			}
			else
				m_equipement->getHead()->setDur(m_equipement->getHead()->getDur() - random_number);
		}
		else
			random_number = 0; 
		break;
	default:
		random_number = 0;
		break;
	}

	int degatsFinaux = degat - random_number;//Je retire aux dégats finaux les points que j'ai déjà enlevé dans une des armures
	if (degatsFinaux >= 0)//Sécurité pour pas qu'il a des point de vie en plus
		m_vie -= degatsFinaux;
}

//Création d'un random car celui de base est nul
int random_with_time_seed(int min, int max) {
	auto current_time = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(current_time);
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}