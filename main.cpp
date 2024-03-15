#include "ProjectPOO.h"
#include <locale>

int main() {
	setlocale(LC_ALL, "");//Mis a jour de l'UTF-8 dans le programme
	int i = 2; 
	std::string nom;
	std::cout << "Bienvenue dans le project POO de Julien DANTE" << std::endl;
	std::cout << "Touche les KEY ARROW pour bouger et SPACE pour entrer" << std::endl;
	std::cout << "Avant que ton aventure commence tu dois d'abord choisir ta classe :" << std::endl;
	personnage& perso = classe(choose1());//Choix de classe du personnage
	gotoxy(0, 24);
	std::cout << "Tu pourras aller voir sur quel type de nen tu es tombé, puis commencé un entrainement pour te familiariser au système de combat,\n et enfin commencer l'histoire." << std::endl;
	std::cout << "Mais d'abord , dit moi comment tu t’appelles" << std::endl;
	std::cin >>	nom;
	perso.setNom(nom);
	do 
	{
		switch (choose2(i))
		{
		case 1:
			clear(0, 24, 150, 10);
			story(perso);
			break;
		case 2:
			clear(0, 24, 150, 10);
			gotoxy(0, 24);
			perso.display();
			break;
		case 3:
			clear(0, 24, 150, 10);
			training(perso);
			break;
		default:
			break;
		}
	} while (perso.isAlive());
	std::cout << "Vous avez perdu le jeu !\n\n\n" << std::endl;
	delete &perso;
	return 0;
}
