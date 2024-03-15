#include "hero.h"

hero::hero() : personnage() {
	m_etoile = 0;
}

hero::hero(std::string nom, std::string typeNen) : personnage(nom, typeNen) {
	m_etoile = 0;
}

hero::hero(int etoile) : personnage() {
	m_etoile = etoile;
}

//Methodes virtual
void hero::display() {
	std::cout << " *  <--" << *m_equipement->getHead() << std::endl;
	std::cout << "/|\\ <--" << *m_equipement->getBody() << std::endl;
	std::cout << "/ \\ <--" << *m_equipement->getLegs() << std::endl;
	std::cout << "Arme :" << *m_equipement->getArme() << std::endl;
	std::cout << "Hero : " << m_nom << " possède " << std::to_string(m_vie) << " de pdv, a un nen de type " << m_typeNen << " avec une capacité de " << std::to_string(m_nen) << " a " << std::to_string(m_etoile) << " étoiles       " << std::endl;
}

std::string hero::getSigneChinois() {
	return "null";
}
std::vector<std::string> hero::getlisteRang() {
	return { "null" };
}