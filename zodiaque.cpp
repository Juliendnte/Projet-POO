#include "zodiaque.h"

/*
Les zodiaques sont les adversaires des ennemies au début de l'aventure on combat un des 12 zodiaques
Jusqu'à affronté le dernier zodiaque
Si on gagne se combat le jeu est finie
*/

std::vector<std::string> listeSignes{
        "Rat",
        "Boeuf",
        "Tigre",
        "Lapin",
        "Dragon",
        "Serpent",
        "Cheval",
        "Mouton",
         "Singe",
         "Coq",
         "Chien",
         "Cochon"
};


zodiaque::zodiaque(std::string signe) : hero() {
	m_signe_chinois = signe;
}
 
//Methodes virtual
void zodiaque::display() {
	std::cout << " *  <--" << *m_equipement->getHead() << std::endl;
	std::cout << "/|\\ <--" << *m_equipement->getBody() << std::endl;
	std::cout << "/ \\ <--" << *m_equipement->getLegs() << std::endl;
	std::cout << "Arme :" << *m_equipement->getArme() << std::endl;
	std::cout << "Zodiaque : " << m_nom << " de signe du " << m_signe_chinois << " possède " << std::to_string(m_vie) << " de pdv, a un nen de type " << m_typeNen << " avec une capacité de " << std::to_string(m_nen) << " a " << std::to_string(m_etoile) << " étoiles" << std::endl;
}

std::vector<std::string> getlisteSignes() {
    return listeSignes;
}

void remove(std::string strToRemove) {
    std::vector<std::string>& listeStrings = listeSignes;
    auto it = std::find(listeStrings.begin(), listeStrings.end(), strToRemove);
    if (it != listeStrings.end()) {
        listeStrings.erase(it);
    }
}