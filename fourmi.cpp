#include "fourmi.h"
#include <vector>
/*
Les fourmies sont les adversaires des héros au début de l'aventure on combat une ouvrière
Puis on combat des adversaires au rang plus prestigieux
Jusqu'à affronté la reine 
Si on gagne se combat le jeu est finie
*/
std::vector<std::string> listeRang{
        "ouvrière",
        "esclavagistes",
        "agricultrices",
        "puéricultrices",
        "exploratrices",
        "soldates",
        "mâle",
        "reine"
};

fourmi::fourmi() : ennemie() {
    m_rang = listeRang[0];
}

fourmi::fourmi(std::string rang) : ennemie() {
	m_rang = rang;
}

//Fonction virtual
void fourmi::display() {
	std::cout << " *  <--" << *m_equipement->getHead() << std::endl;
	std::cout << "/|\\ <--" << *m_equipement->getBody() << std::endl;
	std::cout << "/ \\ <--" << *m_equipement->getLegs() << std::endl;
	std::cout << "Arme :" << *m_equipement->getArme() << std::endl;
    std::cout << "Fourmie : " << m_nom << " de rang " << m_rang << " possède " << std::to_string(m_vie) << " de pdv, a un nen de type " << m_typeNen << " avec une capacité de " << std::to_string(m_nen) << ", a tué " << std::to_string(m_mort) << "       " << std::endl;
}

std::vector<std::string> getlisteRang() {
    return listeRang;
}

void removeRang() {
    listeRang.erase(listeRang.begin());
}