#include <iostream>
#include "Pokemon.h"
#ifndef OBJET_H
#define OBJET_H

class Objet
{
private:
// Attributs
	std::string Nom, Description;
	int RestaurationPv, Prix;
	bool EstUtiliser;

public:
//Constructeurs / destructeurs
	Objet();
	~Objet();
	Objet(std::string nom, std::string descrip, int restaupv, int prix);

//Méthodes 
	int Action(Pokemon& PokemonObjet); //revoie les nouveaux PVs du pokemon
	void Afficher(); // affiche l'objet

//Getter
	bool GetUse() { return EstUtiliser; };
	int GetRestaurationPv() { return RestaurationPv; };
	std::string GetNomObjet() { return Nom; };
	std::string GetDescription() { return Description; };
	int GetPrix (){return Prix; };

//Setter
	void SetEstUtiliser() { EstUtiliser = 1; };

};
#endif // !OBJET_H