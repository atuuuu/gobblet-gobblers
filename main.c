#include <stdio.h>
#include <stdlib.h>
#include "SDL/include/SDL2/SDL.h"
#include "Secure_SDL.h"
#include "mes_fonctions.h"
#include "mes_fonctions_SDL.h"
#include "mes_fonctions_son.h"

//Les fonctions Secure_ permettent d'utiliser la SDL de manière sécurisée
//Les fonctions img_ servent à l'affichage de l'interface graphique
//Les fonctions verif_ servent à vérifier des conditions tout en affichant une partie de l'interface (moins compréhensible, plus optimisée)
//Les fonctions event_ permettent de gérer les inputs

//Joueur 1 est bleu, joueur 2 est rouge

int main(int argc, char** argv)
{
	Secure_SDL_Init(SDL_INIT_VIDEO);	//Démarage de la librairie SDL
	son_init();

	int packVoix = atu;

	SDL_Event event;
	player joueur = PLAYER_1;	//Déclaration et initialisation des variables
	Coord tableauCase[9];

	Img_jeu banqueImage;
	initialiserImageGobelet(&banqueImage);

	Son_jeu banqueSon;
	son_initBanqueSon(&banqueSon, packVoix);

	initialiserTableauCase(tableauCase);

	unsigned int finTour = 0, action, resteGobelet = 0, actualiser = 0, clic, lireSon=0;
	Coord caseChoisie , caseSource, caseCible;
	size tailleGobelet, ancienTailleGobelet;	//TailleGobelet stocke la taille du gobelet choisi, ancienTailleGobelet permet de ne rafraichir les affichages QUE si la taille du gobelet a changée

	SDL_Window* fenetre = Secure_SDL_CreateWindow("Gobblet Gobblers",1920,1040);	//Création de la fenetre de jeu
	son_ambiance(banqueSon);

	do
	{
		board grille = new_game();
		img_menu(fenetre);

		event_recupChoixMenu(fenetre, banqueImage);	//Permet de lancer ou de quitter le jeu

		while(get_winner(grille) == 0 || get_winner(grille) == 3)
		{
			lireSon = 0;
			clic = 0;
			actualiser = 0;
			do
			{
				joueur=next_player(joueur);	//On change de joueur

				son_choixAction(banqueSon);
				action = event_recupererActionJoueur(fenetre, joueur, grille, tableauCase, banqueImage);
				img_fondJeu(fenetre, joueur, banqueImage);
				img_actualiserTableau(fenetre, grille, banqueImage);
				verif_afficherGobeletJoueur(fenetre, joueur, grille, &resteGobelet);
				SDL_UpdateWindowSurface(fenetre);

				if(action==1)
				{
					son_choixTaille(banqueSon);
					do
					{

						SDL_WaitEvent(&event);	//On récupère l'action du joueur

						if(event.type == SDL_MOUSEBUTTONDOWN) clic = 1;
						if(event.type == SDL_MOUSEBUTTONUP) clic = 0;

						tailleGobelet = event_recupererTailleGobelet(fenetre, joueur, grille, event, banqueImage);
						img_dragNdrop(fenetre, event, tailleGobelet, banqueImage, joueur, grille, 0, clic);
						caseChoisie = event_recupCase(event, banqueImage);

						if (ancienTailleGobelet != tailleGobelet)	//Pour éviter le scintillement lié à l'actualisation à chaque mouvement de la souris
						{
							img_fondJeu(fenetre,joueur, banqueImage);
							img_actualiserTableau(fenetre, grille, banqueImage);
							verif_afficherGobeletJoueur(fenetre, joueur, grille, &resteGobelet);
							ancienTailleGobelet = tailleGobelet;
						}

						img_montrerTailleChoisie(fenetre, joueur, tailleGobelet);
						
					} while (place_piece(grille, joueur, tailleGobelet, caseChoisie.x, caseChoisie.y) != 0);
					finTour = 1;
					img_fondJeu(fenetre,joueur, banqueImage);
					img_actualiserTableau(fenetre, grille, banqueImage);
				}
				else if(action == 2)
				{
					do
					{
						son_choixCase(banqueSon);
						do
						{
							if(actualiser)
							{
								son_actionImpossible(banqueSon);
								img_fondJeu(fenetre,joueur, banqueImage);
								img_actualiserTableau(fenetre, grille, banqueImage);
								actualiser = 0;
							}

							SDL_PollEvent(&event);
							caseSource = event_recupCase(event, banqueImage);

						}while(get_place_holder(grille, caseSource.x, caseSource.y) != joueur);
						actualiser = 1;

						son_choixCase(banqueSon);
						do
						{
							img_dragNdrop(fenetre, event, get_piece_size(grille, caseSource.x, caseSource.y), banqueImage, joueur, grille, 1, clic);
							SDL_UpdateWindowSurface(fenetre);
							SDL_WaitEvent(&event);
							caseCible = event_recupCase(event, banqueImage);
						}while(caseCible.x > 2 || caseCible.y > 2);
					}while(move_piece(grille, caseSource.x, caseSource.y, caseCible.x, caseCible.y) != 0);

					img_fondJeu(fenetre,joueur, banqueImage);
					img_actualiserTableau(fenetre, grille, banqueImage);
				}
			}while(finTour==0);
		}
		img_actualiserTableau(fenetre, grille, banqueImage);

		img_victoire(fenetre,get_winner(grille), banqueImage);
		son_victoire(banqueSon);
		event_recupRejouer(0, banqueImage);

		destroy_game(grille);
	}while(1);
	return EXIT_SUCCESS;
}
