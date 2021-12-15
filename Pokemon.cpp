#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Objet.h"
#include "Joueur.h"
using namespace std;
Pokemon::Pokemon() { //Constructeur par défaut
	
}
Pokemon:: ~Pokemon() { //Destructeur

}
Pokemon::Pokemon(std::string nom, std::string type, std::string type2, int prix, int pdv, int niv, int attack, int attackspe, int def, int defspe, int vitesse) { //Constructeur

	Nom = nom;
	Type = type;
	Type2 = type2;
	Prix = prix;
	PointDeVie = pdv;
	Niveau = niv;
	AttaqueP = attack;
	AttaqueSpéciale = attackspe;
	Defense = def;
	DefenseSpeciale = defspe;
	Vitesse = vitesse;
	ObjetTenu = new Objet("Pas d'objet", " ",0,0) ;

}

void Pokemon::AjouterAttaque(Attaque AttaName) { //Push_back (ajoute) une attaque dans le vecteur attacks
	Attacks.push_back(AttaName);
}

void Pokemon::Attaquer(Pokemon& PokemonEstAttaque, Attaque Attaque) { //methode attaquer
	cout <<"\n" << GetNom() << " va attaquer "<< PokemonEstAttaque.GetNom() << " avec " << Attaque.GetAttaqueNom() << endl; //Narration
	cout << "Le pokemon va perdre " 
	<< Attaque.CalculerDegats(*this, PokemonEstAttaque) << " points de vie " << endl; // cout les dégats reçu en fctn des deux pokémons et de l'attaque
	PokemonEstAttaque.SetPDV(PokemonEstAttaque.GetPDV()-Attaque.CalculerDegats(*this, PokemonEstAttaque));//Set les PVs du pokemon attaqué par soustraction des dégats a ses Pvs.
	cout << "Il reste " << PokemonEstAttaque.GetPDV() << " PDV a " << PokemonEstAttaque.GetNom() << endl << endl; //cout des Pvs restant
	Attaque.SetPP(Attaque.GetPP() - 1);//enlève un PP à l'attaque
}


void Pokemon::UtiliserObjet() {
	if (ObjetTenu->GetUse()== 0 && ObjetTenu->GetNomObjet() != "Pas d'objet")	//si l'objet n'est pas utilisé alors
	{
		cout << "Voulez-vous utiliser votre objet (appuyer sur 1 si oui ): " << ObjetTenu->GetNomObjet() << " ? " ;
		bool ChoixUse = 0;
		cin >> ChoixUse;
		if (ChoixUse == 1) {	//si l'utilisateur veut utiliser l'objet alors
			PointDeVie = ObjetTenu->Action(*this); //Set les PVs au nombre de Pvs calculés par la fonction action 
			cout << "Le pokemon utilise" << ObjetTenu->GetNomObjet() << " ses pv sont de : " << PointDeVie << endl << endl; //cout 
			ObjetTenu->SetEstUtiliser();//Set l'utilisation de l'objet a 1
		}
		else {	//sinon il n'utilise pas l'objet
			cout << "Vous ne voulez pas utiliser votre objet \n" << endl;
		}
	}
	else { //sinon le pokemon n'a plus d'objet
		cout << "Votre pokemon n'a plus d'objet. \n" << endl;

	}
	
}
bool Pokemon::EstKo() {	//retourne l'etat du pokemon
	if (PointDeVie > 0) { //si les Pvs du pokémon sont supérieurs à 0 alors
		return 0; //il est vivant 
	}
	else if (Attacks[0].GetPP() == 0 && Attacks[1].GetPP() == 0 && Attacks[2].GetPP() == 0) { // ou sinon touts les PPs sont à 0 alors
		return 1; //il  est mort
	}
	else {
		return 1; //sinon il est mort
	}
}

void Pokemon::AfficherAttaques() {//affiche les attaques
	for (int i = 0; i <= Attacks.size()-1; i++) { //pour toutes les lignes du tableau
		cout << i+1 <<". "<< Attacks[i].GetAttaqueNom()<<". Le nombre de PP utilise sera de : "<< Attacks[i].GetPP() << endl; //cout du nom et des PPs
	}
}
void Pokemon::Afficher() {  //affiche les caractèristiques du pokémon

	cout << 
		"\nNom : " << Nom << 
		"\nType : " << Type << 
		"\nType2 : " << Type2 <<
		"\nPrix : " << Prix <<
		"\nNiveau : " << Niveau <<
		"\nPoint de vie : " << PointDeVie <<
		"\nAttaqueP : " << AttaqueP <<
		"\nAttaque Speciale : " << AttaqueSpéciale <<
		"\nDefense : " << Defense <<
		"\nDefense speciale : " << DefenseSpeciale <<
		"\nVitesse : " << Vitesse <<
		"\nObjet : " << ObjetTenu->GetNomObjet() << endl;
		
}

Attaque Pokemon::UsePokemonAttaque(int choix) { //enlève un PP a l'attaque
	Attacks[choix].SetPP(Attacks[choix].GetPP() - 1);
	return Attacks[choix];
}

