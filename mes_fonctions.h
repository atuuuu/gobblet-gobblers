#ifndef MES_FONCTIONS_H_29112019
#define MES_FONCTIONS_H_29112019
#include "mon_board.h"


#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)	//Pour la gestion des couleurs sur tout les OS
    #define color(param) printf("\033[0%sm",param)
#endif


#if defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
#endif

#if defined(_WIN32) || defined(_WIN64)//Fonction couleur pour la console windows
	void couleur(int t,int f);//Pour l'affichage en couleur sous windows
#endif


typedef struct
{
	int x;
	int y;
}Coord;

typedef struct
{
	int compteurGobelet[3];
}InfoJoueur;

void clear();
void viderBuffer();
int lireEntier();
int recupererActionJoueur();
int preparerPoserGobelet(player joueur, board grille, Coord tableauCase[]);
int preparerDeplacerGobelet(player joueur, board grille, Coord tableauCase[]);
void initialiserTableauCase(Coord tableau[]);
void initialiserCompteurGobelet(int compteur[]);
void afficher_tableau(board grille,Coord tableauCase[]);
int verifierVictoire(board grille);

#endif