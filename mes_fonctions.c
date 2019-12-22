#include <stdio.h>
#include <stdlib.h>
#include "mes_fonctions.h"
#include "mon_board.h"


void clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}


int lireEntier()
{
	char entierLettre;
	int entier;
	fgets(&entierLettre,2,stdin);
	entier = strtol(&entierLettre,NULL,10);

	while(getchar()!='\n');
	
	return entier;
}

void viderBuffer()
{
	while(getchar()!='\n');
}


int recupererActionJoueur()
{
	unsigned int actionChoisie = 3;

	while(actionChoisie != 1 && actionChoisie != 2)
	{
		printf("Que voulez vous faire ? Poser un gobelet ? (tapez 1) ou déplacer un gobelet ? (tapez 2) : ");		//On demande au joueur ce qu'il veut faire
		actionChoisie=lireEntier();
	}

	return actionChoisie;
}


void initialiserCompteurGobelet(int compteur[])
{
	for (int j = 0; j < 3; ++j)
	{
		compteur[j]=NB_INITIAL_PIECES;
	}
}


int preparerPoserGobelet(player joueur, board grille, Coord tableauCase[])
{
	size tailleGobelet;
	unsigned int resteGobelet = 0, caseChoisie;
	unsigned int tailleChoisie=3;
	int retour=0;

	static InfoJoueur compteurDeGobelet[2];

	initialiserCompteurGobelet(compteurDeGobelet[joueur].compteurGobelet);

	for (int i = 1; i < 4; ++i)
	{
		if(get_nb_piece_in_house(grille,joueur,i)>0) resteGobelet=1;
	}

	if(resteGobelet)
	{
		do
		{
			printf("Dans quelle case souhaitez vous poser votre gobelet ? (entre 1 et 9) : ");
			caseChoisie=lireEntier();
		}while(caseChoisie==0 || caseChoisie > 10);
		caseChoisie--;

		do
		{
			printf("Quelle taille de gobelet souhaitez vous choisir ? (1 : petit, 2 : moyen, 3 : grand)\n");
			tailleChoisie=lireEntier();	
		}while(tailleChoisie==0 || tailleChoisie>3);

		tailleGobelet = tailleChoisie;


		if (tailleGobelet>get_piece_size(grille,tableauCase[caseChoisie].x,tableauCase[caseChoisie].y))
		{
			switch(place_piece(grille,joueur,tailleGobelet,tableauCase[caseChoisie].x,tableauCase[caseChoisie].y))
			{
				case 0:
					retour=1;
					break;
				case 1:
					printf("Vous n'avez plus de gobelet de cette taille !\n");
					break;
				case 2:
					printf("Votre gobelet est trop petit pour être mis ici\n");
					break;
				case 3:
					printf("La case selectionnée n'existe pas\n");
					break;
				default:
					printf("erreur inconnue\n");
					break;
			}
			
		}
	}
	else
	{
		printf("Vous n'avez plus de gobelet\n");
	}
	
	return retour;
}


int preparerDeplacerGobelet(player joueur, board grille, Coord tableauCase[])
{
	unsigned int caseChoisie=11;
	unsigned int caseSource=10;
	int retour=0;

	do
	{
		printf("Ou se trouve le gobelet que vous souhaitez déplacer ?\n");
		caseSource=lireEntier();
		caseSource--;

		printf("case de joueur : %d\n",get_place_holder(grille,tableauCase[caseSource].x,tableauCase[caseSource].y));
		printf("joueur : %d\n\n",joueur);
	}while((caseSource>8));

	do
	{
		printf("Dans quelle case souhaitez vous déplacer votre gobelet ? (entre 1 et 9) : ");
		caseChoisie=lireEntier();
	}while(caseChoisie==0 || caseChoisie > 10);
	caseChoisie--;

	if (get_piece_size(grille,tableauCase[caseSource].x,tableauCase[caseSource].y) > get_piece_size(grille,tableauCase[caseChoisie].x,tableauCase[caseChoisie].y) && get_place_holder(grille,tableauCase[caseSource].x,tableauCase[caseSource].y) == joueur)
	{
		switch(move_piece(grille,tableauCase[caseSource].x,tableauCase[caseSource].y,tableauCase[caseChoisie].x,tableauCase[caseChoisie].y))
		{
			case 0:
				retour=1;
				break;
			case 1:
				printf("Vous n'avez pas de gobelet sur cette case !\n");
				break;
			case 2:
				printf("Votre gobelet est trop petit pour être mis ici\n");
				break;
			case 3:
				printf("La case selectionnée n'existe pas\n");
				break;
			default:
				printf("erreur inconnue\n");
				break;
		}
		
	}
	else
	{
		printf("Vous ne pouvez pas faire ça !\n");
	}
	return retour;
}

	
void initialiserTableauCase(Coord tableau[])
{
	for (int i = 8; i > -1; i--)
	{
		tableau[i].x=(8-i)/3;
		tableau[i].y=i%3;
	}

	tableau[9].x = -1;
	tableau[9].y = -1;
}


void afficher_tableau(board grille,Coord tableauCase[])
{
	printf("Grille de jeu :\n");
	printf("╔═══╦═══╦═══╗\n");	//Affiche la ligne du haut de la grille
	for (int i = 0; i < 3; i++)
	{
		if(i>0) printf("╠═══╬═══╬═══╣\n");	//Affiche les lignes de séparation de la grille

		for (int j = 0; j < 3; j++)
		{
			if (get_place_holder(grille,i,j)==1)
			{
				#if defined(_WIN32) || defined(_WIN64)
					printf("║");
					couleur(12,0);
					printf(" %d ",get_piece_size(grille,i,j));
					couleur(15,0);
				#endif
				#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
					printf("║");
					color("31");
					printf(" %d ",get_piece_size(grille,i,j));
					color("0");
				#endif
				
			}
			else if(get_place_holder(grille,i,j)==2)
			{
				#if defined(_WIN32) || defined(_WIN64)
					printf("║");
					couleur(11,0);
					printf(" %d ",get_piece_size(grille,i,j));
					couleur(15,0);
				#endif
				#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
					printf("║");
					color("34");
					printf(" %d ",get_piece_size(grille,i,j));
					color("0");
				#endif
			}
			else
			{
				printf("║   ");
			}
		}
		printf("║\n");
	}
	printf("╚═══╩═══╩═══╝\n\n");	//Affiche la dernière ligne de la grille

	printf("Grille d'exemple :\n");
	printf("╔═══╦═══╦═══╗\n");	//Pour que l'utilisateur sache quelle case à quel numéro
	printf("║ 7 ║ 8 ║ 9 ║\n");
	printf("╠═══╬═══╬═══╣\n");
	printf("║ 4 ║ 5 ║ 6 ║\n");
	printf("╠═══╬═══╬═══╣\n");
	printf("║ 1 ║ 2 ║ 3 ║\n");
	printf("╚═══╩═══╩═══╝\n\n\n");
}

#if defined(_WIN32) || defined(_WIN64)//Fonction couleur pour la console windows
	void couleur(int t,int f)//Pour l'affichage en couleur sous windows
	{
	        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	        SetConsoleTextAttribute(H,f*16+t);
	}
#endif

