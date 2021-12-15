#include "Attaque.h" // Inclusion de attaque.h
#include "Pokemon.h" //  Inclusion de pokemon.h
using namespace std;
// Constructeurs et destructeurs
Attaque::Attaque() {
}
Attaque::~Attaque() {
}
Attaque::Attaque(string nom, string type, bool categorieAttaque, int precision, int puissance, int pp) {
	Nom = nom;
	Type = type;
	CategorieAttaque = categorieAttaque;
	Precision = precision;
	Puissance = puissance;
	PP = pp;
}


int Attaque::CalculerDegats(Pokemon attaquant, Pokemon& defenseur) {
	double PVp = 0;
	if (CategorieAttaque == 0) { 
		PVp = (((double)attaquant.GetNiveau() * 0.4 + 2) * (double)attaquant.GetAttaqueP() * (double)Puissance) / ((double)defenseur.GetDef() * 50) + 2;
	}
	else if (CategorieAttaque == 1) {
		PVp = (((double)attaquant.GetNiveau() * 0.4 + 2) * (double)attaquant.GetAttaqueS() * (double)Puissance) / ((double)defenseur.GetDefS() * 50) + 2;
	}
	if (Type == attaquant.GetType1() or Type == attaquant.GetType2()) { PVp *= 1.5; }

	return PVp;
}
/*La m�thode CalculerDegat permet de calculer les d�gats en renvoyant le nombre de pv � soustraire au pv du pok�mon. Elle cherche � savoir si c'est une attaque normale
ou sp�ciale*/

void Attaque::AfficherAttaque() {
	cout << "Le nom de l'attaque est : " << Nom << endl;
	cout << "Le type de l'attaque est : " << Type << endl;
	cout << "La categorie d'attaque de l'attaque est : " << CategorieAttaque << endl;
	cout << "La precision de l'attaque est : " << Precision << endl;
	cout << "La puissance de l'attaque est : " << Puissance << endl;
	cout << "Les points de pouvoirs  de l'attaque est : " << PP << endl;
}
/*La m�thode AfficherAttaque permet d'afficher les caract�ristiques d'une attaque*/