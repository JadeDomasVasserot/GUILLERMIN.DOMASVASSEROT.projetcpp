#include "Objet.h"
#include <iostream>
using namespace std;
Objet::Objet() { //Constructeur
	Nom = "";
}
Objet::~Objet() { //Destucteur

}

Objet::Objet(string nom, string descrip, int restaupv, int prix) { //Constructeur
	Nom = nom;
	Description = descrip;
	RestaurationPv = restaupv;
	EstUtiliser = 0;
	Prix = prix;
}
void Objet::Afficher(){ //Affiche l'objet
	cout <<"Le nom de cette baie est : "<< Nom <<". "<< endl;
	cout <<"Description : "<< Description << endl;
	cout << "Elle restaure : "<<RestaurationPv <<" PV."<< endl;
	cout << "Son prix est de  : " << Prix << endl;
}
int Objet::Action(Pokemon& PokemonObjet) { //renvoie les nouveaux PVs du pokemon
	cout << "La vie du pokemon est de : " << PokemonObjet.GetPDV()<<endl; //cout des PVs
	cout << "La restauration de cet objet : " << Nom <<" est de : " << RestaurationPv << endl; //cout objet
	int PdvHeal = PokemonObjet.GetPDV() + RestaurationPv; //calcul des nouveaux PVs
	return PdvHeal;
}