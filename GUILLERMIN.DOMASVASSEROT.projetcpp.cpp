using namespace std; 
// Inclusion des fichiers .h
#include <iostream>
#include "Objet.h"
#include "Attaque.h"
#include "Jeu.h"
#include "Joueur.h"
#include "Pokemon.h"
int main() // Fonction main
{
    // Cr�ation de 2 objets joueurs 
        Joueur joueur1(" ", 10000, 0);
        Joueur joueur2(" ", 10000, 0);
    // Cr�ation de l'objet Partie
        Jeu Partie(joueur1, joueur2);
    // Appel de la m�thode Jouer
        Partie.Jouer();
}
