#include "Jeu.h" //Inclusion de Jeu.h
#include <iostream>

using namespace std;

//Constructeur par d�faut
Jeu::Jeu() {

}

// Destructeur
Jeu::~Jeu() {

}

//Constructeur surcharg�
Jeu::Jeu(Joueur j1,Joueur j2) {
	Joueur1 = j1;
	Joueur2 = j2;
}
// M�thode Jouer qui comporte le jeu
void Jeu::Jouer() {
	bool Partie = 0;
	cout << "--------   BIENVENUE DANS LE JEU COMBAT DE POKEMON !    --------\n" << endl << "Si vous voulez commencer une partie, entrez 1 ! " << endl;
	cin >> Partie;
	while (Partie == 1) { //D�termine si la partie est en marche
		Joueur joueur1(" ", 8000, 0); //Cr�ation du joueur 1
			joueur1.SaisirJoueur(); //Saisir le nom du joueur 1
			joueur1.ChoisirPokemon(); // Choix des pokemons du joueur 1
		Joueur joueur2(" ", 8000, 0); //Cr�ation du joueur 2
			joueur2.SaisirJoueur();	//Saisir le nom du joueur 1
			joueur2.ChoisirPokemon();	// Choix des pokemons du joueur 2
			ListeJoueur(joueur1, joueur2); // Afficher la liste des joueurs
		int NumeroPokemon = 0;
		cout << "\n -- La partie commence ! --\n" << endl;
		while (joueur1.MancheGagne < 2 && joueur2.MancheGagne < 2) { // Faire le jeu en 2 manches gagn�e --> jouer tant que un des joueurs n'a pas MancheGagne = 2
			joueur1.APP(joueur1.GetPokemon(NumeroPokemon)); // V�rifier si le pokemon du joueur 1 a encore des PP � ses attaques
			if (joueur1.GetPokemon(NumeroPokemon).EstKo()) { //V�rifier si le pokemon du joueur 1 est KO
				cout << "Pokemon KO car vous n'avez plus de PP sur aucune attaque" << endl;
				joueur2.MancheGagne += 1; // Ajouter 1 � MancheGagne car le pokemon du joueur 2 n'a plus de PP
				cout << " Le nombre du manche gagnee du joueur : " << joueur2.GetJoueurNom() << " est de " << joueur2.MancheGagne << endl << endl;
				cout << "\nManche suivante ! " << endl;
				NumeroPokemon += 1; // Changer de pok�mon
			}
			joueur2.APP(joueur2.GetPokemon(NumeroPokemon)); //V�rifier si le pokemon du joueur 2 a encore des PP � ses attaques
			if (joueur2.GetPokemon(NumeroPokemon).EstKo()) { //V�rifier si le pokemon du joueur 2 est KO
					cout << "Pokemon KO car vous n'avez plus de PP" << endl;
					joueur1.MancheGagne += 1; // Ajouter 1 � MancheGagne car le pokemon du joueur 1 n'a plus de PP
					cout << " Le nombre du manche gagnee du joueur : " << joueur1.GetJoueurNom() << " est de " << joueur1.MancheGagne << endl << endl;
					cout << "\nManche suivante ! " << endl;
					NumeroPokemon += 1;// Changer de pok�mon
			}
			
				if (joueur1.GetPokemon(NumeroPokemon).GetVitesse() > joueur2.GetPokemon(NumeroPokemon).GetVitesse()) { // Chercher si pok�mon du joueur 1 � une vitesse sup�rieur au pok�mon du joueur 2
					joueur1.GetPokemon(NumeroPokemon).Attaquer(joueur2.GetPokemon(NumeroPokemon), joueur1.ChoisirAttaque(joueur1.GetPokemon(NumeroPokemon))); // Choisir l'attaque et Attaquer
					joueur1.GetPokemon(NumeroPokemon).UtiliserObjet(); // Demander si on utilise l'objet
					if (joueur2.GetPokemon(NumeroPokemon).EstKo()) {  //V�rifier si le pokemon du joueur 2 est KO
						cout << "Pokemon KO car vous n'avez plus de pv" << endl;
						joueur1.MancheGagne += 1; // Ajouter 1 � MancheGagne car le pokemon du joueur 1 n'a plus de PV
						cout << " Le nombre du manche gagnee du joueur : " << joueur1.GetJoueurNom() << " est de " << joueur1.MancheGagne << endl << endl;
						cout << "\nManche suivante ! " << endl;
						NumeroPokemon += 1;// Changer de pok�mon
					}
					else {
						// Si il est pas KO le pok�mon du joueur 2 alors il attaque � son tour
						joueur2.GetPokemon(NumeroPokemon).Attaquer(joueur1.GetPokemon(NumeroPokemon), joueur2.ChoisirAttaque(joueur2.GetPokemon(NumeroPokemon)));  // Choisir l'attaque et Attaquer
						joueur2.GetPokemon(NumeroPokemon).UtiliserObjet();// Demander si on utilise l'objet
						if (joueur1.GetPokemon(NumeroPokemon).EstKo()) { //V�rifier si le pokemon du joueur 1 est KO
							cout << "Pokemon KO " << endl;
							joueur2.MancheGagne += 1; // Ajouter 1 � MancheGagne car le pokemon du joueur 2 n'a plus de PV
							cout << joueur2.MancheGagne << endl;
							cout << " Le nombre du manche gagnee du joueur : " << joueur2.GetJoueurNom() << " est de " << joueur2.MancheGagne << endl;
							cout << "\nManche suivante ! " << endl;
							NumeroPokemon += 1;// Changer de pok�mon
						}
					}
				}
				else {// Le pok�mon du joueur 2 a une vitese + �lev�e que celui du joueur 1
					joueur2.GetPokemon(NumeroPokemon).Attaquer(joueur1.GetPokemon(NumeroPokemon), joueur2.ChoisirAttaque(joueur2.GetPokemon(NumeroPokemon))); // Choisir l'attaque et Attaquer
					joueur2.GetPokemon(NumeroPokemon).UtiliserObjet(); // Demander si on utilise l'objet
					if (joueur1.GetPokemon(NumeroPokemon).EstKo()) { //V�rifier si le pokemon du joueur 1 est KO
						cout << "Pokemon KO car vous n'avez plus de pv" << endl;
						joueur2.MancheGagne += 1; //Ajouter 1 � MancheGagne car le pokemon du joueur 2 n'a plus de PV
						cout << " Le nombre du manche gagnee du joueur : " << joueur2.GetJoueurNom() << " est de " << joueur2.MancheGagne << endl;
						cout << "\nManche suivante ! " << endl;
						NumeroPokemon += 1; // Changer de pok�mon
					}
					else {//Si il est pas KO le pok�mon du joueur 1 alors il attaque � son tour
						joueur1.GetPokemon(NumeroPokemon).Attaquer(joueur2.GetPokemon(NumeroPokemon), joueur1.ChoisirAttaque(joueur1.GetPokemon(NumeroPokemon)));// Choisir l'attaque et Attaquer
						joueur1.GetPokemon(NumeroPokemon).UtiliserObjet();// Demander si on utilise l'objet
						if (joueur2.GetPokemon(NumeroPokemon).EstKo()) {//V�rifier si le pokemon du joueur 2 est KO
							cout << "Pokemon KO car vous n'avez plus de pv " << endl;
							joueur1.MancheGagne += 1; // Ajouter 1 � MancheGagne car le pokemon du joueur 2 n'a plus de PV
							cout << " Le nombre du manche gagnee du joueur : " << joueur1.GetJoueurNom() << " est de " << joueur1.MancheGagne << endl;
							cout << "\nManche suivante ! " << endl;
							NumeroPokemon += 1; // Changer de pok�mon
						}
					}
				}
		} //fin du while pour les 2 manches gagnantes
		cout << "Bravo ! Le joueur ";
		if (joueur1.MancheGagne == 2) {
			cout << joueur1.GetJoueurNom();
		}
		else {
			joueur2.GetJoueurNom();
		}
		cout<<" a remporte 2 manches ! " << endl;
		
	Partie = 0;
	cout << "Fin de la partie !" << endl;	
	cout << "Voulez-vous rejouer ? Si oui entrez 1 ! Sinon bonne journee !!!";
	cin >> Partie;
	}// fin du while de la partie
	
}
// M�thode qui affiche la liste des joueurs gr�ce aux m�thodes Afficher de la classe Joueur
void Jeu::ListeJoueur(Joueur Joueur1, Joueur Joueur2){
	
	cout << "\n\n --- LISTE DES JOUEURS --- " << endl;
	cout << Joueur1.Afficher() << endl;
	cout << Joueur2.Afficher() << endl;
}
