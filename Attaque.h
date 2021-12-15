#include <iostream>
#include <vector>
#ifndef ATTAQUE_H
#define ATTAQUE_H
class Pokemon; // Inclusion de la classe pokémon 
class Attaque 
{
private: 
	//Attributs
		std::string Nom, Type; // De type string
		bool CategorieAttaque; // De type booléen
		int Precision, Puissance, PP; // De type int
	
public:
	//Constructeur
		Attaque(); // Constructeur par défaut
		~Attaque(); // Destructeur
		Attaque(std::string Nom, std::string Type, bool CategorieAttaque, int Precision, int Puissance, int PP); // Constructeur surchargé

	//Getter

		std::string GetAttaqueNom() { return Nom; }; 
		std::string GetAttaqueType() { return Type; };
		bool GetCategorieAttaque() { return CategorieAttaque; };
		int GetAttaquePrecision() { return Precision; };
		int GetAttaquePuissance() { return Puissance; };
		int GetPP() { return PP; }
	//Méthode

		int CalculerDegats(Pokemon attaquant, Pokemon& defenseur);
		void AfficherAttaque();

	//Setter

		void SetPP(int NewPP) { PP = NewPP; };
	
};


#endif // !ATTAQUE_H