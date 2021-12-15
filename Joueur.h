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
	Pokemon& GetPokemon(int numero) { return Pokemons[numero]; } //retourne le pokemon numéro X du joueur

//Setter
	std::string SetJoueur(std::string NomJoueur); //set Nom
	std::string SaisirJoueur(); //Saisie du joueur
	
//Méthode	
	void ChoisirPokemon();//déclaration pokémons+attaques
	void AjouterPokemon(Pokemon Pokemon);//Ajouter dans liste joueur
	Attaque ChoisirAttaque(Pokemon& Pokemon); //choisi une attaque du pokémon
	void RecupererPokemon();//recupere le pokemon
	void AfficherPokemon(); //affiche les pokémons du joueur
	std::string Afficher();//affiche le joueur
	void LancerPokemon(Pokemon Pokemon);//lance un Pokemon
	void APP(Pokemon& Pokemon);//vérifie si toutes les attaques du pokemons sont à 0 PP 
};

#endif // !JOUEUR_H