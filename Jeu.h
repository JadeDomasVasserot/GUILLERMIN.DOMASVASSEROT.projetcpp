#include <iostream>
#include "Joueur.h"
#ifndef JEU_H
#define JEU_H

class Jeu
{
private :
	Joueur Joueur1, Joueur2; // Attributs de type Joueur
public:
	//Construteurs
		Jeu(); //Constructeur par défaut
		~Jeu();//Destructeur
		Jeu(Joueur j1, Joueur j2); //Constructeur surchargé
	//Méthodes
		void Jouer();
		void ListeJoueur(Joueur Joueur1, Joueur Joueur2);

};
#endif // !JEU_H
