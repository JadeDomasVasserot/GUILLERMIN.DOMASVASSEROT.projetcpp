#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "Objet.h"
#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur
{

public:
//Attributs
	std::string Nom;
	int MancheGagne, Argent;
	std::vector<Pokemon>Pokemons;

//Constructeurs / destructeurs
	Joueur();
	Joueur(std::string nom, int Argent, int MancheG);
	~Joueur();

//Getter
	std::string GetJoueurNom() {return Nom;}
	int GetManche() {return MancheGagne;}
	int GetArgent() {return Argent;}
	Pokemon& GetPokemon(int numero) { return Pokemons[numero]; } //retourne le pokemon num�ro X du joueur

//Setter
	std::string SetJoueur(std::string NomJoueur); //set Nom
	std::string SaisirJoueur(); //Saisie du joueur
	
//M�thode	
	void ChoisirPokemon();//d�claration pok�mons+attaques
	void AjouterPokemon(Pokemon Pokemon);//Ajouter dans liste joueur
	Attaque ChoisirAttaque(Pokemon& Pokemon); //choisi une attaque du pok�mon
	void RecupererPokemon();//recupere le pokemon
	void AfficherPokemon(); //affiche les pok�mons du joueur
	std::string Afficher();//affiche le joueur
	void LancerPokemon(Pokemon Pokemon);//lance un Pokemon
	void APP(Pokemon& Pokemon);//v�rifie si toutes les attaques du pokemons sont � 0 PP 
};

#endif // !JOUEUR_H