#include "ennemie.h"

ennemie::ennemie() : personnage() {
	m_mort = 0;
}

ennemie::ennemie(std::string nom, std::string typeNen) : personnage(nom, typeNen) {
	m_mort = 0;
}

ennemie::ennemie(int mort, std::string nom, int vie, int nen, std::string typeNen, equipement& Equipment) : personnage(nom, vie, nen, typeNen, Equipment) {
	m_mort = mort;
}

//Methodes virtual
void ennemie::display() {
	std::cout << " *  <--" << *m_equipement->getHead() << std::endl;
	std::cout << "/|\\ <--" << *m_equipement->getBody() << std::endl;
	std::cout << "/ \\ <--" << *m_equipement->getLegs() << std::endl;
	std::cout << "Arme :" << *m_equipement->getArme() << std::endl;
	std::cout << "Ennemie : " << m_nom << " poss�de " << std::to_string(m_vie) << " de pdv, a un nen de type " << m_typeNen << " avec une capacit� de " << std::to_string(m_nen) << ", a tu� " << std::to_string(m_mort) << "       " << std::endl;
}

std::string ennemie::getSigneChinois() {
	return "null";
}
std::vector<std::string> ennemie::getlisteRang() {
	return { "null" };
}