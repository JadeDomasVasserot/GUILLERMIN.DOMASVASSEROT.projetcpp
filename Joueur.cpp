#include "Joueur.h"
#include <string>

using namespace std;

Joueur::Joueur() {//Constructeur
	Nom = "";
	Argent = 0;
	MancheGagne = 0;
}
Joueur::Joueur(std::string nom, int Argent, int MancheG ) {//Constructeur
	Nom = nom;
	this->Argent = Argent;
	MancheGagne = MancheG;
}

Joueur::~Joueur(){//Destructeur
}

string Joueur::SetJoueur(string NomJoueur) //Change le nom du joueur
{	
	Nom = NomJoueur;
	return Nom;
}

string Joueur::SaisirJoueur() { //Retourne le nom saisi par l'utilisateur
	cout << "\nQuelle est le nom du joueur  ? ";
	cin >> Nom;
	cout << endl;
	return Nom;
}


void Joueur::ChoisirPokemon() {

//Déclaration des attaques 	
	Attaque Attaque0();
    Attaque LanceFlammes("Lance-Flammes", "Feu", 1, 100, 90, 15);
    Attaque Flammeche("Flammeche", "Feu", 0, 100, 40, 25);
    Attaque BulldO("Bulle d'O", "Eau", 1, 100, 65, 20);
    Attaque Hydroqueue("Hydroqueue", "Eau", 0, 90, 90, 10);
    Attaque AiredHerbe("Aire d'Herbe", "Plante", 1, 100, 80, 10);
    Attaque TranchHerbe("Tranch'Herbe", "Plante", 0, 95, 55, 25);
    Attaque Eclair("Eclair", "Electrick", 1, 100, 40, /*30*/2);
    Attaque PoingEclair("Poing-Eclair", "Electrick", 0, 100, 75, /*15*/2);
    Attaque PuissanceCachee("Puissance Cachee", "Normal", 1, 100, 60, 15);
    Attaque Echo("Echo", "Normal", 1, 100, 40, 15);
    Attaque Sonicboom("Sonicboom", "Normal", 1, 90, 20, 20);
    Attaque BallMeteo("Ball'Meteo", "Normal", 1, 100, 50, /*10*/ 2);
    Attaque Combogriffe("Combo-Griffe", "Normal", 0, 80, 18, 15);
    Attaque CrocdeMort("Croc de Mort", "Normal", 0, 90, 80, 15);
    Attaque Uppercut("Uppercut", "Normal", 0, 100, 70, 10);
    Attaque Escalade("Escalade", "Normal", 0, 85, 90, 20);
  
//Déclaration des Pokemons
    Pokemon Pokemon0();
    std::vector<Pokemon> PokemonDisponible; //Déclaration du tableau de pokemon
	Pokemon Tiplouf("Tiplouf", "Eau", "", 2200, 53, 1, 51, 61, 53, 56, 40);
    Pokemon Evoli("Evoli", "Normal", "", 2000, 55, 1, 55, 45, 50, 65, 55);
    Pokemon Rondoudou("Rondoudou", "Normal", "Fée", 2000, 115, 1, 45, 45, 20, 25, 20);
    Pokemon Carapuce("Carapuce", "Eau", "", 2200, 44, 1, 48, 50, 65, 64, 43);
    Pokemon Salameche("Salameche", "Feu", "", 2200, 39, 1, 52, 60, 43, 50, 65);
    Pokemon Bulbizarre("Bulbizarre", "Plante", "Poison", 2000, 45, 1, 49, 65, 49, 65, 45);
    Pokemon Pikachu("Pikachu", "Electrik", "", 2300, 35, 1, 55, 50, 40, 50, 90);
    Pokemon Caninos("Caninos", "Feu", "", 1900, 55, 1, 70, 70, 45, 50, 60);
    
//Ajout des différentes attaques aux pokemons
    Tiplouf.AjouterAttaque(BulldO);
    Tiplouf.AjouterAttaque(Hydroqueue);
    Tiplouf.AjouterAttaque(Echo);

    Evoli.AjouterAttaque(PuissanceCachee);
    Evoli.AjouterAttaque(Escalade);
    Evoli.AjouterAttaque(Combogriffe);

    Rondoudou.AjouterAttaque(BallMeteo);
    Rondoudou.AjouterAttaque(Uppercut);
    Rondoudou.AjouterAttaque(CrocdeMort);

    Caninos.AjouterAttaque(LanceFlammes);
    Caninos.AjouterAttaque(Flammeche);
    Caninos.AjouterAttaque(CrocdeMort);

    Pikachu.AjouterAttaque(Eclair);
    Pikachu.AjouterAttaque(PoingEclair);
    Pikachu.AjouterAttaque(BallMeteo);

    Bulbizarre.AjouterAttaque(AiredHerbe);
    Bulbizarre.AjouterAttaque(TranchHerbe);
    Bulbizarre.AjouterAttaque(Uppercut);

    Salameche.AjouterAttaque(Flammeche);
    Salameche.AjouterAttaque(LanceFlammes);
    Salameche.AjouterAttaque(PuissanceCachee);
    
    Carapuce.AjouterAttaque(BulldO);
    Carapuce.AjouterAttaque(Hydroqueue);
    Carapuce.AjouterAttaque(Sonicboom);

//Ajout des Pokémons au tableau des  pokemons disponibles
	PokemonDisponible.push_back(Pikachu);
	PokemonDisponible.push_back(Caninos);
	PokemonDisponible.push_back(Bulbizarre);
	PokemonDisponible.push_back(Salameche);
	PokemonDisponible.push_back(Tiplouf);
	PokemonDisponible.push_back(Evoli);
	PokemonDisponible.push_back(Carapuce);
	PokemonDisponible.push_back(Rondoudou);

	
	cout << "                       --- LISTE POKEMONS ---                  " << endl;
		
	for (int i = 0; i <= PokemonDisponible.size() - 1; i++) {//Pour toutes les lignes du tableau des pokémons disponible
		cout << "\nPokemon numero " << i + 1 << ". " << PokemonDisponible[i].GetNom() << " --> " << PokemonDisponible[i].GetPrix() <<" pokedollars" <<endl; //affichage du numero du nom et du prix
	}
	int PokemonChoix = 0;
	int i = 0;
	while (i < 3) { //Tant que le joueur n'a pas choisi 3 pokémons
		cout << "Choississer un pokemon, vous avez " << Argent << " pokedollars" << endl;
		cin >> PokemonChoix;
		if (PokemonChoix<9){ //Si le numéro du pokemon et correcte alors
			if (Argent >= PokemonDisponible[PokemonChoix - 1].GetPrix()) {	//Si le joueur a assez d'argent alors
				
				AjouterPokemon(PokemonDisponible[PokemonChoix - 1]); //On ajoute le pokemon de du tableau disponible au tableau du joueur
				
				Argent -= PokemonDisponible[PokemonChoix - 1].GetPrix(); //On soustrait le prix
				cout << "Il vous reste : " << Argent << " pokedollars" << endl;
				i++;//Le joueur a bien choisi un pokemon
			}
			else {//Sinon le joueur n'a pas assez d'argent
				cout << "Vous n'avez pas assez d'argent " << endl;
			}
		}
		else {//L'utilisateur a saisi une valeur incorrecte
			cout << "Il n'y a que 9 pokemons dans la liste" << endl;
		}
		Objet* BaieOran = new Objet("La Baie Oran ", " Baie qui restaure 10 PV lorsqu’elle est tenue par un Pokemon. ", 10, 500); //Déclaration de l'objet du jeu
		cout << "\n                       --- OBJETS ---                  " << endl;
		cout << "\n1. " <<  BaieOran->GetNomObjet() << " --> " << BaieOran->GetPrix() << " pokedollars. \n" << endl;//Affichage de l'objet
		cout << "Choissisez un objet (1) si vous avez les pokedollards sinon entrez 0, vous avez " <<  Argent << " pokedollars" << endl; //choix d'acheter ou non l'objet au pokémon
		bool ObjetChoisi = 0;
		cin >> ObjetChoisi;
		if (Argent >= BaieOran->GetPrix()) {//Si assez d'argent alors
			if (ObjetChoisi == 1) { //Si l'utilisateur veut un objet alors
				Pokemons[i-1].SetObjet(BaieOran);//Ajout de l'objet au pokemon du choisi du joueur
				Argent -= BaieOran->GetPrix();//Soustraction du prix
			}
			else {//sinon
				cout << "vous ne voulez pas acheter d'objet" << endl;
			}
		}//sinon
		else {
			cout << " Vous n'avez pas assez d'argent pour acheter l'objet" << endl;
		}
		
	}
	cout << "\n                       --- LISTE DES POKEMONS CHOISIS---                  " << endl;
	AfficherPokemon();//Affichage des trois pokémons et de leurs objets du joueur
}

void Joueur::APP(Pokemon& Pokemon) {//Test des PPs
	if (Pokemon.GetAttaque(0).GetPP() == 0 && Pokemon.GetAttaque(1).GetPP() == 0 && Pokemon.GetAttaque(2).GetPP() == 0) {//Si le pokémons n'a plus aucun PPs alors
		Pokemon.SetPDV(0); //Set ses Pvs a 0 (mort)
	}
}

void Joueur::AjouterPokemon(Pokemon Pokemon) { //Ajout des pokémons à la liste du joueur
	Pokemons.push_back(Pokemon);
}
Attaque Joueur::ChoisirAttaque(Pokemon& Pokemon) {//Choisi l'attaque
	cout << "Le Pokemon "<< Pokemon.GetNom() << " de " << Nom << " va attaquer !" << endl;
	Pokemon.AfficherAttaques(); //Affiche les attaques
	int choix;
	bool PasJouer=1;//Bool jouer ou non
	do {//faire 
		cout << "Choisissez une attaque : ";
		cin >> choix;	//Choix de l'attaque
		if (Pokemon.GetAttaque(choix - 1).GetPP() != 0) {//Si l'attaque a des PPs alors le joueur a choisi
			PasJouer = 0;
		}
		else {//Sinon il n'as pas jouer 
			cout << "Vous n'avez plus de point de pouvoirs pour attaquer avec cette attaque." << endl;
			PasJouer = 1;
		}
	} while (PasJouer == 1);//tant que le joueur n'a pas joué
	return Pokemon.UsePokemonAttaque(choix-1);
}
void Joueur::RecupererPokemon() { //Affiche le Pokemon a récuperer selon la liste
	cout << "Quel pokemon souhaitez vous recuperer (saisir 1, 2 3) ?" << endl;
	AfficherPokemon();
	int  ChoixPokemon(0);
	cin >> ChoixPokemon;
	if (ChoixPokemon == 0) {
		cout << "vous avez recuperer le pokemon : "<< endl;
		Pokemons[ChoixPokemon + 1].Afficher() ;
	}
	else if (ChoixPokemon == 1) {
		cout << "vous avez recuperer le pokemon : "<< endl; 
		Pokemons[ChoixPokemon + 1].Afficher();
	}
	else if (ChoixPokemon == 2) {
		cout << "vous avez recuperer le pokemon : "<< endl;
		Pokemons[ChoixPokemon + 1].Afficher();
	}
	else {
		cout << "Vous n'avez que 3 pokemons, rechoisissez ! " << endl;
		cout << "Quel pokemon souhaitez vous recuperer (saisir 1, 2 3) ?" << endl;
		cin >> ChoixPokemon;
	}
	
}
void Joueur::AfficherPokemon() {//Affiche les pokemons d'un joueur
	for (int i = 0; i <= Pokemons.size() - 1; i++) {//pour tout les pokemons du tableau du joueur
		cout << "\nPokemon numero : " << i + 1 << ". " << endl; //On affiche le numéro 
		Pokemons[i].Afficher(); //Et le pokemon
	}
	
}

std::string Joueur::Afficher() {//Affichage des caractéristique du joueur
	return "\nJoueur : " + Nom + "\nManche Gagne : " + std::to_string(MancheGagne) + "\nArgent : " + std::to_string(Argent) + "\n"; // pokémon
}
void Joueur::LancerPokemon(Pokemon Pokemon) {//Affiche le pokemon a envoyer
	cout << "Choissez le pokemon que vous voulez envoyer combattre ! " << endl;//Choix du pokemon
	AfficherPokemon();
	int  ChoixPokemon(0);
	cin >> ChoixPokemon;
	if (ChoixPokemon == 0) {
		cout << "vous avez choisi le pokemon : " << endl;
		Pokemons[ChoixPokemon + 1].Afficher();
	}
	else if (ChoixPokemon == 1) {
		cout << "vous avez choisi le pokemon : " << endl;
		Pokemons[ChoixPokemon + 1].Afficher();
	}
	else if (ChoixPokemon == 2) {
		cout << "vous avez choisi le pokemon : " << endl;
		Pokemons[ChoixPokemon + 1].Afficher();
	}
	else {
		cout << "Vous n'avez pas choisi de pokemons, rechoisissez ! " << endl;
	}
	cout << "DUEL ! " << endl;
}


