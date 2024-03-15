#pragma once
#include "zodiaque.h"
#include "fourmi.h"
#include <windows.h>
#include <random>
#include <chrono>
#include <thread>
#include <string>
#include <cstdlib>


//Fonction pour savoir quel touche des keys arrows l'utilisateur a séléctionner
std::string KeyArrow()
{
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT_RECORD inp;
	DWORD num_of_events;

	bool exit = false;
	std::string key;

	do
	{
		ReadConsoleInput(hIn, &inp, 1, &num_of_events);

		switch (inp.EventType)
		{
		case KEY_EVENT:
			switch (inp.Event.KeyEvent.wVirtualKeyCode)
			{
			case VK_UP:
				key = "UP";
				exit = true;
				break;

			case VK_DOWN:
				key = "DOWN";
				exit = true;
				break;

			case VK_LEFT:
				key = "LEFT";
				exit = true;
				break;

			case VK_RIGHT:
				key = "RIGHT";
				exit = true;
				break;

			case VK_SPACE:
				key = "SPACE";
				exit = true;
				break;
			}
			break;
		}
	} while (!exit);
	return key ;
}

//Fonction pour mettre le curseur au cordonnée voulu
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Fonction pour effacer une certaine voulue du terminal
void clear(int x,int y, int w,int h) {
	gotoxy(x, y);
	for (int i = 0; i < h; i++)
	{
		for (int i = 0; i < w; i++)
		{
			std::cout << " ";
		}
		std::cout << " " << std::endl;
	}
}


//Fonction d'affichage du choix des modes
void graph(int i) {

	switch (i)
	{
	case 2:

		std::cout << "##################################################################################################################################" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                          histoire                            perso                         Entrainement                        #" << std::endl;
		std::cout << "#                         ----------                         ---------                         ---------                         #" << std::endl;
		std::cout << "#                             |                                  |                                 |                             #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                *                                                               #" << std::endl;
		std::cout << "#                                                               /|\\                                                              #" << std::endl;
		std::cout << "#                                                               / \\                                                              #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "##################################################################################################################################" << std::endl;
		break;
	case 1:
		std::cout << "##################################################################################################################################" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                          histoire                            perso                         Entrainement                        #" << std::endl;
		std::cout << "#                         ----------                         ---------                         ---------                         #" << std::endl;
		std::cout << "#                             |                                  |                                 |                             #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                             *                                                                                                  #" << std::endl;
		std::cout << "#                            /|\\                                                                                                 #" << std::endl;
		std::cout << "#                            / \\                                                                                                 #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "##################################################################################################################################" << std::endl;
		break;

	case 3:
		std::cout << "##################################################################################################################################" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                          histoire                            perso                         Entrainement                        #" << std::endl;
		std::cout << "#                         ----------                         ---------                         ---------                         #" << std::endl;
		std::cout << "#                             |                                  |                                 |                             #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                  *                             #" << std::endl;
		std::cout << "#                                                                                                 /|\\                            #" << std::endl;
		std::cout << "#                                                                                                 / \\                            #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "##################################################################################################################################" << std::endl;
		break;
	default:
		break;
	}
}

//Fonction d'affichages du choix des classes
void graph2(int i) {
	switch (i)
	{
	case 1:
		std::cout << "##################################################################################################################################" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                        villain                                                                   hero                          #" << std::endl;
		std::cout << "#                       ----------                                                               ---------                       #" << std::endl;
		std::cout << "#                           |                                                                        |                           #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                   \\*/                          #" << std::endl;
		std::cout << "#                                                                                                    |                           #" << std::endl;
		std::cout << "#                                                                                                   / \\                          #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "##################################################################################################################################" << std::endl;
		break;
	case 2:
		std::cout << "##################################################################################################################################" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                        villain                                                                   hero                          #" << std::endl;
		std::cout << "#                       ----------                                                               ---------                       #" << std::endl;
		std::cout << "#                           |                                                                        |                           #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                          \\*/                                                                                                   #" << std::endl;
		std::cout << "#                           |                                                                                                    #" << std::endl;
		std::cout << "#                          / \\                                                                                                   #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "#                                                                                                                                #" << std::endl;
		std::cout << "##################################################################################################################################" << std::endl;
		break;
		break;

	default:
		break;
	}
}

//Fonction d'affichage d'un adversaire
void graph3() {
	std::cout << "" << std::endl;
	std::cout << "   *                                                                         *" << std::endl;
	std::cout << "  /|\\                                                                       /|\\" << std::endl;
	std::cout << "  / \\                                                                       / \\" << std::endl;

}

//Fonction d'affichage du choix d'attaque
void graph4(int i) {
	switch (i)
	{
	case 1:
		gotoxy(100, 2);
		std::cout << "Attaque       <--" << std::endl;
		gotoxy(100, 3);
		std::cout << "Recharge           " << std::endl;
		break;
	case 2:
		gotoxy(100, 2);
		std::cout << "Attaque             " << std::endl;
		gotoxy(100, 3);
		std::cout << "Recharge      <--" << std::endl;
		break;
	default:
		break;
	}
}


//Fonction de boucle pour le choix des classes
int choose1() {
	std::string name;
	int i = 1;
	std::cout << "Met toi en grand écran pour une meilleur expérience" << std::endl;
	gotoxy(0, 0);//Curseur au coordonnée 0;0
	KeyArrow();
	KeyArrow();
	graph2(i);
	do {
		gotoxy(0, 0);
		name = KeyArrow();
		if (name == "LEFT") {
			i--;
			if (i < 1) {
				i = 2;
			}
			graph2(i);
			name = KeyArrow();
		}
		else if (name == "RIGHT") {
			i++;
			if (i > 2) {
				i = 1;
			}
			graph2(i);
			name = KeyArrow();

		}
	} while (name != "SPACE");
	return i;
}

//Fonction de boucle pour le choix des modes
int choose2(int &i) {
	std::string name;
	gotoxy(0, 0);
	graph(i);
	do {
		gotoxy(0, 0);
		name = KeyArrow();
		if (name == "LEFT") {
			i --;
			if (i < 1) {
				i = 3;
			}
			graph(i);
			name = KeyArrow();
		}
		else if (name == "RIGHT") {
			i++;
			if (i > 3) {
				i = 1;
			}
			graph(i);
			name = KeyArrow();

		}
	} while (name != "SPACE");
	return i;
}

//Fonction de boucle pour le choix des attaques
int choose3(int &i) {
	std::string name;
	KeyArrow();
	KeyArrow();
	gotoxy(100, 0);
	std::cout << "Choissisez votre attaque" << std::endl;
	graph4(i);
	do {
		gotoxy(100, 6);
		name = KeyArrow();
		if (name == "UP") {
			i--;
			if (i < 1) {
				i = 2;
			}
			graph4(i);
			name = KeyArrow();
		}
		else if (name == "DOWN") {
			i++;
			if (i > 2) {
				i = 1;
			}
			graph4(i);
			name = KeyArrow();

		}
	} while (name != "SPACE");
	return i;
}


//Fonction renvoyant la classe voulue
personnage& classe(int i) {
	if (i == 1) {
		hero* perso = new hero();
		return *perso;
	}
	else {
		ennemie* perso = new ennemie();
		return *perso;
	}
}

//Fonction renvoyant la classe pour l'adversaire
personnage& classe2(int i) {	
	if (i == -1) {
		zodiaque* adv1 = new zodiaque(getlisteSignes()[random_with_time_seed(0, getlisteSignes().size() - 1)]);
		return *adv1;
	}
	else {
		fourmi* adv1 = new fourmi();
		return *adv1;
	}
}

//Fonction renvoyant la classe pour l'adversaire d'entrainement
personnage& classe3() {
	std::string nom;
	std::cout << "Voulez-vous entrainé avec quel type d'adversaire soit\n1/Un Héros\n2/Un Ennemie\n3/Un Zodiaque\n4/Une Fourmie chimére" << std::endl;
	std::cin >> nom;

	if (nom == "1") {
		hero* adv = new hero();
		return *adv;
	}
	else if (nom == "2") {
		ennemie* adv = new ennemie();
		return *adv;
	}
	else if (nom == "3") {
		zodiaque* adv = new zodiaque(getlisteSignes()[random_with_time_seed(0, getlisteSignes().size() - 1)]);
		return *adv;
	}
	else if (nom == "4") {
		fourmi* adv = new fourmi();
		return *adv;
	} 
	else {
		std::cout << "...trop nul " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));//Attendre 10sec
		exit(EXIT_SUCCESS);
	}
}

//Fonction renvoyant les caractéristique de notre classe
personnage& classe4(int i, personnage& p) {
	if (i == 1) {
		hero* perso = new hero(p.getNom(), p.getTypeNen());
		return *perso;
	}
	else {
		ennemie* perso = new ennemie(p.getNom(), p.getTypeNen());
		return *perso;
	}
}


//Fonction de la bagarre
void combat(personnage& perso, personnage& adv) {
	int i = 1;
	while (perso.isAlive() && adv.isAlive()) {
		gotoxy(0, 5);//Pour ne pas faire derouler le terminal et rester au même endroit
		adv.display();//Affichage des stats de l'adversaire

		if (choose3(i) == 1) {
			clear(0, 10, 100, 7);
			gotoxy(0, 10);
			perso.hit(adv);//mon personnage attaque l'adversaire 
		}
		else {
			clear(0, 10, 100, 7);
			gotoxy(0, 10);
			perso.regenNen();// Regeneration du "mana"
			std::cout << "Votre nen est maintenant a " + std::to_string(perso.getNen()) + "\n\n" << std::endl;
			gotoxy(0, 10);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));//Attendre 1sec
		adv.hit(perso);
	}
}

//Fonction du mode histoire
void story(personnage & perso){
	system("cls");
	gotoxy(0, 0);
	graph3();

	int vie = perso.getVie();//Variable tampon
	int nen = perso.getNen();
	int mort = perso.getMort();
	int etoile = perso.getEtoile();
	std::string typeNen = perso.getTypeNen();
	personnage& save = *new hero(perso.getNom(), perso.getTypeNen());
	equipement& equip = *save.getEquipement();

	personnage &adv = classe2(perso.getEtoile());

	std::cout << "VOUS AVEZ RENCONTRE UN ADVERSAIRE" << std::endl;
	
	combat(perso, adv); //Fight

	if (!adv.isAlive()) {//Si adversaire mort (comme ça plus même si mon perso est mort je gagne tout de même)
		if (perso.getEtoile() == -1) {//Si perso est un ennemie
			if (adv.getSigneChinois().size() > 1) {//S'il reste des adversaires
				remove(adv.getSigneChinois());
				perso.setVie(vie);
				perso.setNen(nen);
				perso.setTypeNen(typeNen);
				perso.setMort(mort + 1);
				perso.setEquipement(&equip);
			}
			else {
				delete& perso;
				delete& adv;
				delete& save;
				system("cls");
				std::cout << "Bravo vous avez fini le jeu" << std::endl;
				exit(EXIT_SUCCESS);
			}
		}
		else {
			if (perso.getlisteRang().size() > 1) {
				removeRang();
				perso.setVie(vie);
				perso.setNen(nen);
				perso.setTypeNen(typeNen);
				perso.setEtoile(etoile + 1);
				perso.setEquipement(&equip);
			}
			else {
				delete& perso;
				delete& adv;
				delete& save;
				system("cls");
				std::cout << "Bravo vous avez fini le jeu" << std::endl;
			}
		}
		std::cout << "Vous avez gagné votre combat vous allez être regénérer et gagnez des points \n-1/ PV \n-2/ Nen \n-3/ Degat" << std::endl;
		int choix;
		std::cin >> choix;
		switch (choix)
		{
		case 1:
			perso.setVie(perso.getVie() + 5);
			std::cout << "Vous avez gagné 5PV " << std::endl;
			break;
		case 2:
			perso.setNen(perso.getNen() + 5);
			std::cout << "Vous avez gagné 5 point de nen " << std::endl;
			break;
		case 3:
			perso.getEquipement()->getArme()->setDegat(perso.getEquipement()->getArme()->getDegat() + 5);
			std::cout << "Vous avez gagné 5 point de dégat " << std::endl;
			break;
		default:
			std::cout << "Vous ne méritez pas de point bonus " << std::endl;
			break;
		}
		
	}

	delete& adv;
	system("cls");
}

//Fonction du mode entrainement
void training(personnage & perso) {
	system("cls");
	std::string choix;
	gotoxy(0, 0);
	std::cout << "BIENVENUE DANS L'ENTRAINEMENT" << std::endl;
	std::cout << "Vous allez rencontrés des adversaires plutôt fort êtes vous prêt a faire cette aventure" << std::endl;
	std::cout << "Press : v || Press : x  (v = ok et x = echap)" << std::endl;
	std::cin >> choix;
	if (choix != "v") {
		return;
	}
	graph3();
	int i;
	if (perso.getEtoile() == -1)
		i = 2;
	else
		i = 1;
	personnage& per = classe4(i, perso); //Pour que je ne modifie pas le vrai perso
	personnage& adv = classe3();
	system("cls");
	graph3();

	combat(per, adv);

	if (per.isAlive())
		std::cout << "Bravo pour votre victoire continuez à vous entrainez comme cela" << std::endl;
	else
		std::cout << "Vous avez perdu mais continuez à vous entrainez vous allez réussir" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	delete& per;
	delete& adv;
	system("cls");
}
