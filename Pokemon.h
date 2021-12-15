#include <iostream>
#include <vector>
#include "Attaque.h"

#ifndef POKEMON_H
#define POKEMON_H
class Objet;
class Pokemon
{
protected:
//Attributs
	std::string Nom, Type, Type2;
	int Prix, PointDeVie , AttaqueP, AttaqueSpéciale, Defense, DefenseSpeciale, Vitesse;
	int Niveau;
	std::vector<Attaque> Attacks; //Tableau des trois attaques
	Objet* ObjetTenu; // Attribut objet du pokemon auquel il fait référence
	
public:
//Constructeurs
	Pokemon();	
	~Pokemon();
	Pokemon(std::string nom, std::string type, std::string type2, int prix, int pdv, int niv, int attack, int attackspe, int def, int defspe, int vitesse);
	
//Méthode 
	void AjouterAttaque(Attaque AttaName); // Ajoute une attaque
	void Attaquer(Pokemon& PokemonEstAttaque, Attaque Attaque);// Attaque choisir + CalculDegat() par rapport à l'attaque (paramètre le pokémon estattaqué + *this Pokemonquiattaque
	void UtiliserObjet(); // Utilise l'objet
	bool EstKo();	// Renvoie 0 1 si mort ou vivant
	void AfficherAttaques(); //Affiche le vector Attacks
	void Afficher();	//Affiche les caracéristiques du pokémon
	Attaque UsePokemonAttaque(int choix); //Utilise l'attaque

//Getter
	std::string GetNom() { return Nom; }; 
	std::string GetType1() { return Type; };
	std::string GetType2() { return Type2; };
	double GetPrix() { return Prix; };
	int GetPDV() { return PointDeVie; };
	int GetAttaqueP() { return AttaqueP; }
	int GetAttaqueS(){return AttaqueSpéciale;};
	int GetDef() {return Defense;};
	int GetDefS() { return DefenseSpeciale; };
	int GetVitesse() { return Vitesse; };
	int GetNiveau() { return Niveau; };
	Objet* GetObjet() { return ObjetTenu; };
	Attaque GetAttaque(int num) { return Attacks[num]; }; //renvoie une attaque du tableau

//Setter
	void SetPDV(int NewPDV) { PointDeVie = NewPDV; };
	void SetObjet(Objet* ObjetTenu) {this->ObjetTenu = ObjetTenu;}

};

#endif POKEMON_H
