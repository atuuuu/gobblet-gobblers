#include <stdio.h>
#include "SDL/include/SDL2/SDL.h"
#include "mes_fonctions.h"
#include "mes_fonctions_SDL.h"
#include "Secure_SDL.h"


void img_menu(SDL_Window* fenetre)
{
	SDL_Surface* menu = Secure_SDL_LoadBMP("images_jeu/menus/Accueil gobblet_gobblers.bmp");
	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);
	SDL_BlitSurface(menu,NULL,surface,NULL);
	SDL_UpdateWindowSurface(fenetre);
}


void img_fondJeu(SDL_Window* fenetre, player joueur, Img_jeu banqueImage)
{
	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);
	SDL_Surface* fondJeu = Secure_SDL_LoadBMP("images_jeu/menus/plateauJeu_Gobblet_Gobblers.bmp");

	SDL_Rect posPetitGobeletRouge;
	posPetitGobeletRouge.x = POS_PETIT_GOB_ROUGE_X;
	posPetitGobeletRouge.y = POS_PETIT_GOB_ROUGE_Y;

	SDL_Rect posMoyenGobeletRouge;
	posMoyenGobeletRouge.x = POS_MOYEN_GOB_ROUGE_X;
	posMoyenGobeletRouge.y = POS_MOYEN_GOB_ROUGE_Y;

	SDL_Rect posGrandGobeletRouge;
	posGrandGobeletRouge.x = POS_GRAND_GOB_ROUGE_X;
	posGrandGobeletRouge.y = POS_GRAND_GOB_ROUGE_Y;

	SDL_Rect posPetitGobeletBleu;
	posPetitGobeletBleu.x = POS_PETIT_GOB_BLEU_X;
	posPetitGobeletBleu.y = POS_PETIT_GOB_BLEU_Y;

	SDL_Rect posMoyenGobeletBleu;
	posMoyenGobeletBleu.x = POS_MOYEN_GOB_BLEU_X;
	posMoyenGobeletBleu.y = POS_MOYEN_GOB_BLEU_Y;

	SDL_Rect posGrandGobeletBleu;
	posGrandGobeletBleu.x = POS_GRAND_GOB_BLEU_X;
	posGrandGobeletBleu.y = POS_GRAND_GOB_BLEU_Y;


	SDL_BlitSurface(fondJeu,NULL,surface,NULL);

	SDL_BlitSurface(banqueImage.petitGobBleu, NULL, surface, &posPetitGobeletBleu);
	SDL_BlitSurface(banqueImage.moyenGobBleu, NULL, surface, &posMoyenGobeletBleu);
	SDL_BlitSurface(banqueImage.grandGobBleu, NULL, surface, &posGrandGobeletBleu);

	SDL_BlitSurface(banqueImage.petitGobRouge, NULL, surface, &posPetitGobeletRouge);
	SDL_BlitSurface(banqueImage.moyenGobRouge, NULL, surface, &posMoyenGobeletRouge);
	SDL_BlitSurface(banqueImage.grandGobRouge, NULL, surface, &posGrandGobeletRouge);
}






void img_actualiserTableau(SDL_Window* fenetre, board grille, Img_jeu banqueImage)
{
	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);

	SDL_Rect coordCase[3][3];
	initialiserTableauCoord(coordCase);


	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				switch(grille->tableauComplet[i][j][k])
				{
					case NO_PLAYER:
						SDL_BlitSurface(NULL, NULL, surface, &coordCase[i][j]);
						break;

					case PLAYER_1:
						if(k==0)
						{
							SDL_BlitSurface(banqueImage.petitGobBleu, NULL, surface, &coordCase[i][j]);
						}
						if(k==1)
						{
							SDL_BlitSurface(banqueImage.moyenGobBleu, NULL, surface, &coordCase[i][j]);
						}
						if(k==2)
						{
							SDL_BlitSurface(banqueImage.grandGobBleu, NULL, surface, &coordCase[i][j]);
						}
						break;

					case PLAYER_2:
						if(k==0)
						{
							SDL_BlitSurface(banqueImage.petitGobRouge, NULL, surface, &coordCase[i][j]);
						}
						if(k==1)
						{
							SDL_BlitSurface(banqueImage.moyenGobRouge, NULL, surface, &coordCase[i][j]);
						}
						if(k==2)
						{
							SDL_BlitSurface(banqueImage.grandGobRouge, NULL, surface, &coordCase[i][j]);
						}
						break;
				}
			}
			
		}
	}
}


void img_montrerTailleChoisie(SDL_Window* fenetre, player joueur, size tailleGobelet)
{
	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);
	SDL_Surface* cadre_gobChoisit = Secure_SDL_LoadBMP("images_jeu/éléments/cadre_gobChoisit.bmp");
	SDL_SetColorKey(cadre_gobChoisit, SDL_TRUE, SDL_MapRGB(cadre_gobChoisit->format, 0, 0, 0));

	SDL_Rect posCase;

	if (joueur == PLAYER_1)
	{
		if(tailleGobelet == 0)
		{
			posCase.x = -500;
			posCase.y = -500;
		}
		if(tailleGobelet == 1)
		{
			posCase.x = POS_PETIT_GOB_BLEU_X - 20;
			posCase.y = POS_PETIT_GOB_BLEU_Y - 20;
		}
		if(tailleGobelet == 2)
		{
			posCase.x = POS_MOYEN_GOB_BLEU_X - 20;
			posCase.y = POS_MOYEN_GOB_BLEU_Y - 20;
		}
		if (tailleGobelet == 3)
		{
			posCase.x = POS_GRAND_GOB_BLEU_X - 20;
			posCase.y = POS_GRAND_GOB_BLEU_Y - 20;
		}
	}
	if (joueur == PLAYER_2)
	{
		if(tailleGobelet == 0)
		{
			posCase.x = -500;
			posCase.y = -500;
		}
		if(tailleGobelet == 1)
		{
			posCase.x = POS_PETIT_GOB_ROUGE_X - 20;
			posCase.y = POS_PETIT_GOB_ROUGE_Y - 20;
		}
		if (tailleGobelet == 2)
		{
			posCase.x = POS_MOYEN_GOB_ROUGE_X - 20;
			posCase.y = POS_MOYEN_GOB_ROUGE_Y - 20;
		}
		if (tailleGobelet == 3)
		{
			posCase.x = POS_GRAND_GOB_ROUGE_X - 20;
			posCase.y = POS_GRAND_GOB_ROUGE_Y - 20;
		}
	}
	SDL_BlitSurface(cadre_gobChoisit, NULL, surface, &posCase);
	SDL_UpdateWindowSurface(fenetre);
}


void verif_afficherGobeletJoueur(SDL_Window* fenetre, player joueur, board grille, unsigned int* resteGobelet)
{
	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);
	SDL_Surface* chiffreZero = SDL_LoadBMP("images_jeu/chiffres/chiffreZero.bmp");
	SDL_SetColorKey(chiffreZero, SDL_TRUE, SDL_MapRGB(chiffreZero->format, 255, 255, 255));
	SDL_Surface* chiffreUn = SDL_LoadBMP("images_jeu/chiffres/chiffreUn.bmp");
	SDL_SetColorKey(chiffreUn, SDL_TRUE, SDL_MapRGB(chiffreUn->format, 255, 255, 255));
	SDL_Surface* chiffreDeux = SDL_LoadBMP("images_jeu/chiffres/chiffreDeux.bmp");
	SDL_SetColorKey(chiffreDeux, SDL_TRUE, SDL_MapRGB(chiffreDeux->format, 255, 255, 255));

	SDL_Rect posChiffreBleu[3];
	SDL_Rect posChiffreRouge[3];

	posChiffreBleu[2].x = POS_CHIFFRE_PETIT_BLEU_X;
	posChiffreBleu[2].y = POS_CHIFFRE_PETIT_BLEU_Y;

	posChiffreRouge[0].x = POS_CHIFFRE_PETIT_ROUGE_X;
	posChiffreRouge[0].y = POS_CHIFFRE_PETIT_ROUGE_Y;

	posChiffreBleu[1].x = POS_CHIFFRE_MOYEN_BLEU_X;
	posChiffreBleu[1].y = POS_CHIFFRE_MOYEN_BLEU_Y;

	posChiffreRouge[1].x = POS_CHIFFRE_MOYEN_ROUGE_X;
	posChiffreRouge[1].y = POS_CHIFFRE_MOYEN_ROUGE_Y;

	posChiffreBleu[0].x = POS_CHIFFRE_GRAND_BLEU_X;
	posChiffreBleu[0].y = POS_CHIFFRE_GRAND_BLEU_Y;

	posChiffreRouge[2].x = POS_CHIFFRE_GRAND_ROUGE_X;
	posChiffreRouge[2].y = POS_CHIFFRE_GRAND_ROUGE_Y;

	for (int i = 1; i < 4; i++)
	{
		if (joueur == 1)
		{
			switch(get_nb_piece_in_house(grille,joueur,i))
			{
				case 0:
					SDL_BlitSurface(chiffreZero, NULL, surface, &posChiffreBleu[i-1]);	//Colle le chiffre correspondant au nombre de gobelet restant
					break;
				case 1:
					SDL_BlitSurface(chiffreUn, NULL, surface, &posChiffreBleu[i-1]);	//Colle le chiffre correspondant au nombre de gobelet restant
					*resteGobelet = 1;
					break;
				case 2:
					SDL_BlitSurface(chiffreDeux, NULL, surface, &posChiffreBleu[i-1]);	//Colle le chiffre correspondant au nombre de gobelet restant
					*resteGobelet = 1;
					break;
			}
		}
		else
		{
			switch(get_nb_piece_in_house(grille,joueur,i))
			{
				case 0:
					SDL_BlitSurface(chiffreZero, NULL, surface, &posChiffreRouge[i-1]);	//Colle le chiffre correspondant au nombre de gobelet restant
					break;
				case 1:
					SDL_BlitSurface(chiffreUn, NULL, surface, &posChiffreRouge[i-1]);	//Colle le chiffre correspondant au nombre de gobelet restant
					*resteGobelet = 1;
					break;
				case 2:
					SDL_BlitSurface(chiffreDeux, NULL, surface, &posChiffreRouge[i-1]);	//Colle le chiffre correspondant au nombre de gobelet restant
					*resteGobelet = 1;
					break;
			}
		}
	}
}


void event_recupChoixMenu(SDL_Window* fenetre, Img_jeu banqueImage)
{
	SDL_Event choix;
	int continuer = 1;	//Si sortie vaut 0 alors on continue, sinon le programme s'arrète

	while(continuer)
	{
		SDL_WaitEvent(&choix);
		switch(choix.type)
		{
			case SDL_QUIT:
				exit(EXIT_SUCCESS);
				break;
			case SDL_MOUSEBUTTONUP:
				if(choix.button.y > 427  && choix.button.y < 590)
				{
					continuer = 0;
				}
			case SDL_MOUSEMOTION:
				if(choix.button.y > 427  && choix.button.y < 590)
				{
					SDL_SetCursor(banqueImage.main);
				}
				if(choix.button.y < 427  || choix.button.y > 590)
				{
					SDL_SetCursor(banqueImage.fleche);
				}
		}
	}
	SDL_SetCursor(banqueImage.fleche);
}


int event_recupererActionJoueur(SDL_Window* fenetre, player joueur, board grille, Coord tableauCase[], Img_jeu banqueImage)
{
	int actionChoisie = 0, continuer = 1;

	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);
	SDL_Surface* choix;
	choix = Secure_SDL_LoadBMP("images_jeu/menus/recupActionJoueur.bmp");
	SDL_SetColorKey(choix, SDL_TRUE, SDL_MapRGB(choix->format, 129,129,129));

	SDL_BlitSurface(choix,NULL,surface,NULL);

	img_rayerActionInterdite(fenetre, joueur, grille, tableauCase);	//Si une action est interdite, alors elle est rayée

	SDL_UpdateWindowSurface(fenetre);

	SDL_Event event;

	do
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				exit(EXIT_SUCCESS);
				break;

			case SDL_MOUSEBUTTONUP:
				if (event.button.x > 540 && event.button.x < 1240 && event.button.y > 275 && event.button.y < 400 && verif_actionFaisable(1, joueur, grille, tableauCase))
				{
					continuer = 0;
					actionChoisie = 1;
				}
				else if (event.button.x > 540 && event.button.x < 1400 && event.button.y > 700 && event.button.y < 750 && verif_actionFaisable(2, joueur, grille, tableauCase))
				{
					continuer = 0;
					actionChoisie = 2;
				}
				break;
			case SDL_MOUSEMOTION:
				if (event.button.x > 540 && event.button.x < 1240 && event.button.y > 275 && event.button.y < 400 && verif_actionFaisable(1, joueur, grille, tableauCase))
				{
					SDL_SetCursor(banqueImage.main);
				}
				else if (event.button.x > 540 && event.button.x < 1400 && event.button.y > 700 && event.button.y < 750 && verif_actionFaisable(2, joueur, grille, tableauCase))
				{
					SDL_SetCursor(banqueImage.main);
				}
				else SDL_SetCursor(banqueImage.fleche);
				break;

		}
	}while(continuer==1);

	SDL_SetCursor(banqueImage.fleche);
	return actionChoisie;
}



void img_rayerActionInterdite(SDL_Window* fenetre, player joueur_actuel, board grille, Coord tableauCase[])
{
	int poser = 0, deplacer = 0;														//Déclaration des variables
	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);
	SDL_Surface* croix = Secure_SDL_LoadBMP("images_jeu/éléments/croix.bmp");
	SDL_SetColorKey(croix, SDL_TRUE, SDL_MapRGB(croix->format, 255, 255, 255));
	SDL_Rect posPoser, posDeplacer;

	posPoser.x = 530;
	posPoser.y = 315;

	posDeplacer.x = 530;
	posDeplacer.y = 715;

	for (int i = 0; i < 9; ++i)	//Si le joueur à un gobelet visible sur au moins une case il peut le déplacer
	{
		if (get_place_holder(grille, tableauCase[i].x, tableauCase[i].y) == joueur_actuel)
		{
			deplacer = 1;
		}
	}

	for (int i = 1; i < 4; ++i)	//On teste pour toutes les tailles de gobelets
	{
		if (get_nb_piece_in_house(grille, joueur_actuel, i) > 0)	//Si pour au moins une taille le joueur à encore des gobelets
		{
			poser = 1;	//On retourne 1
		}
	}

	if (poser == 0) SDL_BlitSurface(croix, NULL, surface, &posPoser);
	if (deplacer == 0) SDL_BlitSurface(croix, NULL, surface, &posDeplacer);
}


int verif_actionFaisable(int actionChoisie, player joueur_actuel, board grille, Coord tableauCase[])
{
	int valeurSortie = 0;	//Valeur de sortie, 0 si l'action testée n'est pas faisable, 1 si l'action testée est faisable
	if (actionChoisie == 1)	//On vérifie si le joueur peut encore poser des gobelets
	{
		for (int i = 1; i < 4; ++i)	//On teste pour toutes les tailles de gobelets
		{
			if (get_nb_piece_in_house(grille, joueur_actuel, i) > 0)	//Si pour au moins une taille le joueur à encore des gobelets
			{
				valeurSortie = 1;	//On retourne 1
			}
		}
	}
	if (actionChoisie == 2)
	{
		for (int i = 0; i < 9; ++i)	//Si le joueur à un gobelet visible sur au moins une case il peut le déplacer
		{
			if (get_place_holder(grille, tableauCase[i].x, tableauCase[i].y) == joueur_actuel)
			{
				valeurSortie = 1;
			}
		}
	}
	return valeurSortie;
}


Coord event_recupCase(SDL_Event event, Img_jeu banqueImage)
{
	Coord casePrise;
	casePrise.x = 4;
	casePrise.y = 4;

	SDL_Rect coordCase[3][3];
	initialiserTableauCoord(coordCase);

	if(event.type==SDL_QUIT)
	{
		exit(EXIT_SUCCESS);
	}
	if(event.type == SDL_MOUSEBUTTONUP || event.type == SDL_MOUSEBUTTONDOWN)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (event.button.x > coordCase[i][j].x && event.button.x < (coordCase[i][j].x + LARGEUR_CASE) && event.button.y > coordCase[i][j].y && event.button.y < (coordCase[i][j].y + HAUTEUR_CASE))
				{
					casePrise.x = i;
					casePrise.y = j;
				}
			}
		}
	}
	if(event.type == SDL_MOUSEMOTION)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (event.button.x > coordCase[i][j].x && event.button.x < (coordCase[i][j].x + LARGEUR_CASE) && event.button.y > coordCase[i][j].y && event.button.y < (coordCase[i][j].y + HAUTEUR_CASE))
				{
					SDL_SetCursor(banqueImage.main);
				}
			}
		}
	}

	return casePrise;
}


size event_recupererTailleGobelet(SDL_Window* fenetre, player joueur, board grille, SDL_Event event, Img_jeu banqueImage)	//Joueur 1 est rouge, joueur 2 est bleu
{
	static size gobChoisi;	//Pour éviter d'avoir un gobelet aléatoire ou nul lorsqu'on appelle à nouveau la fonction

	if (event.type == SDL_QUIT)
	{
		exit(EXIT_SUCCESS);
	}


	if (joueur == PLAYER_2)
	{
		switch(event.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.x > POS_PETIT_GOB_ROUGE_X && event.button.x < (POS_PETIT_GOB_ROUGE_X + TAILLE_PETIT_GOB) && event.button.y > POS_PETIT_GOB_ROUGE_Y && event.button.y < (POS_PETIT_GOB_ROUGE_Y + TAILLE_PETIT_GOB ))
				{
					gobChoisi = SMALL;
				}
				if (event.button.x > POS_MOYEN_GOB_ROUGE_X && event.button.x < (POS_MOYEN_GOB_ROUGE_X + TAILLE_MOYEN_GOB) && event.button.y > POS_MOYEN_GOB_ROUGE_Y && event.button.y < (POS_MOYEN_GOB_ROUGE_Y + TAILLE_MOYEN_GOB ))
				{
					gobChoisi = MEDIUM;
				}
				if (event.button.x > POS_GRAND_GOB_ROUGE_X && event.button.x < (POS_GRAND_GOB_ROUGE_X + TAILLE_GRAND_GOB) && event.button.y > POS_GRAND_GOB_ROUGE_Y && event.button.y < (POS_GRAND_GOB_ROUGE_Y + TAILLE_GRAND_GOB ))
				{
					gobChoisi = LARGE;
				}
				break;

			case SDL_MOUSEMOTION:
				if (event.button.x > POS_PETIT_GOB_ROUGE_X && event.button.x < (POS_PETIT_GOB_ROUGE_X + TAILLE_PETIT_GOB) && event.button.y > POS_PETIT_GOB_ROUGE_Y && event.button.y < (POS_PETIT_GOB_ROUGE_Y + TAILLE_PETIT_GOB ))
				{
					SDL_SetCursor(banqueImage.main);
				}
				else if (event.button.x > POS_MOYEN_GOB_ROUGE_X && event.button.x < (POS_MOYEN_GOB_ROUGE_X + TAILLE_MOYEN_GOB) && event.button.y > POS_MOYEN_GOB_ROUGE_Y && event.button.y < (POS_MOYEN_GOB_ROUGE_Y + TAILLE_MOYEN_GOB ))
				{
					SDL_SetCursor(banqueImage.main);
				}
				else if (event.button.x > POS_GRAND_GOB_ROUGE_X && event.button.x < (POS_GRAND_GOB_ROUGE_X + TAILLE_GRAND_GOB) && event.button.y > POS_GRAND_GOB_ROUGE_Y && event.button.y < (POS_GRAND_GOB_ROUGE_Y + TAILLE_GRAND_GOB ))
				{
					SDL_SetCursor(banqueImage.main);
				}
				break;
		}
	}

	else if (joueur == PLAYER_1)
	{
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.x > POS_PETIT_GOB_BLEU_X && event.button.x < (POS_PETIT_GOB_BLEU_X + TAILLE_PETIT_GOB) && event.button.y > POS_PETIT_GOB_BLEU_Y && event.button.y < (POS_PETIT_GOB_BLEU_Y + TAILLE_PETIT_GOB ))
			{
				gobChoisi = SMALL;
			}
			if (event.button.x > POS_MOYEN_GOB_BLEU_X && event.button.x < (POS_MOYEN_GOB_BLEU_X + TAILLE_MOYEN_GOB) && event.button.y > POS_MOYEN_GOB_BLEU_Y && event.button.y < (POS_MOYEN_GOB_BLEU_Y + TAILLE_MOYEN_GOB ))
			{
				gobChoisi = MEDIUM;
			}
			if (event.button.x > POS_GRAND_GOB_BLEU_X && event.button.x < (POS_GRAND_GOB_BLEU_X + TAILLE_GRAND_GOB) && event.button.y > POS_GRAND_GOB_BLEU_Y && event.button.y < (POS_GRAND_GOB_BLEU_Y + TAILLE_GRAND_GOB ))
			{
				gobChoisi = LARGE;
			}
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			if (event.button.x > POS_PETIT_GOB_BLEU_X && event.button.x < (POS_PETIT_GOB_BLEU_X + TAILLE_PETIT_GOB) && event.button.y > POS_PETIT_GOB_BLEU_Y && event.button.y < (POS_PETIT_GOB_BLEU_Y + TAILLE_PETIT_GOB ))
			{
				SDL_SetCursor(banqueImage.main);
			}
			else if (event.button.x > POS_MOYEN_GOB_BLEU_X && event.button.x < (POS_MOYEN_GOB_BLEU_X + TAILLE_MOYEN_GOB) && event.button.y > POS_MOYEN_GOB_BLEU_Y && event.button.y < (POS_MOYEN_GOB_BLEU_Y + TAILLE_MOYEN_GOB ))
			{
				SDL_SetCursor(banqueImage.main);
			}
			else if (event.button.x > POS_GRAND_GOB_BLEU_X && event.button.x < (POS_GRAND_GOB_BLEU_X + TAILLE_GRAND_GOB) && event.button.y > POS_GRAND_GOB_BLEU_Y && event.button.y < (POS_GRAND_GOB_BLEU_Y + TAILLE_GRAND_GOB ))
			{
				SDL_SetCursor(banqueImage.main);
			}
		}
	}

	if(gobChoisi == NONE) gobChoisi = SMALL;	//Sécurité anti-crash

	return gobChoisi;
}


void img_victoire(SDL_Window* fenetre, player vainqueur, Img_jeu banqueImage)
{
	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);

	if(vainqueur == PLAYER_1)
	{
		SDL_BlitSurface(banqueImage.victoireJoueur1, NULL, surface, NULL);
	}
	if(vainqueur == PLAYER_2)
	{
		SDL_BlitSurface(banqueImage.victoireJoueur2, NULL, surface, NULL);
	}
	SDL_UpdateWindowSurface(fenetre);
}


void initialiserTableauCoord(SDL_Rect coordCase[][3])
{
	for (int i = 0; i < 3; ++i)		//Initialisation des coordonnées
	{
		for (int j = 0; j < 3; ++j)
		{
			coordCase[i][j].x = POS_TABLEAU_X + (POS_CASE_X + TAILLE_BARRE + 5) * i;
			coordCase[i][j].y = POS_TABLEAU_Y + (POS_CASE_Y + TAILLE_BARRE) * j - 20;
		}
	}
}


void img_dragNdrop(SDL_Window* fenetre,SDL_Event event, size tailleGobelet, Img_jeu banqueImage, player joueur, board grille, int force, int clic)
{
	SDL_Surface* surface = SDL_GetWindowSurface(fenetre);
	static SDL_Rect posSouris;

	if((clic || force) && tailleGobelet!=NONE && (get_nb_piece_in_house(grille, joueur, tailleGobelet) || force))
	{
		if(event.button.x != posSouris.x)
		{
			posSouris.x = event.button.x - 100;
			posSouris.y = event.button.y - 100;

			img_fondJeu(fenetre, joueur, banqueImage);
			img_actualiserTableau(fenetre, grille, banqueImage);
			verif_afficherGobeletJoueur(fenetre, joueur, grille, &clic);	//clic vaut forcément 1 si on est ici

			if(joueur == PLAYER_1)
			{
				switch(tailleGobelet)
				{
					case SMALL:
						SDL_BlitSurface(banqueImage.petitGobBleu, NULL, surface, &posSouris);
						break;
					case MEDIUM:
						SDL_BlitSurface(banqueImage.moyenGobBleu, NULL, surface, &posSouris);
						break;
					case LARGE:
						SDL_BlitSurface(banqueImage.grandGobBleu, NULL, surface, &posSouris);
						break;
				}
			}
			else
			{
				switch(tailleGobelet)
				{
					case SMALL:
						SDL_BlitSurface(banqueImage.petitGobRouge, NULL, surface, &posSouris);
						break;
					case MEDIUM:
						SDL_BlitSurface(banqueImage.moyenGobRouge, NULL, surface, &posSouris);
						break;
					case LARGE:
						SDL_BlitSurface(banqueImage.grandGobRouge, NULL, surface, &posSouris);
						break;
				}
			}
		}
	}
}


void initialiserImageGobelet(Img_jeu* banqueImage)
{
	banqueImage->petitGobRouge = Secure_SDL_LoadBMP("images_jeu/éléments/petitGobelet_rouge.bmp");
	SDL_SetColorKey(banqueImage->petitGobRouge, SDL_TRUE, SDL_MapRGB(banqueImage->petitGobRouge->format, 255,255,255));	//Pour rendre le blanc transparent

	banqueImage->moyenGobRouge = Secure_SDL_LoadBMP("images_jeu/éléments/moyenGobelet_rouge.bmp");
	SDL_SetColorKey(banqueImage->moyenGobRouge, SDL_TRUE, SDL_MapRGB(banqueImage->moyenGobRouge->format, 255,255,255));

	banqueImage->grandGobRouge = Secure_SDL_LoadBMP("images_jeu/éléments/grosGobelet_rouge.bmp");
	SDL_SetColorKey(banqueImage->grandGobRouge, SDL_TRUE, SDL_MapRGB(banqueImage->grandGobRouge->format, 255,255,255));

	banqueImage->petitGobBleu = Secure_SDL_LoadBMP("images_jeu/éléments/petitGobelet_bleu.bmp");
	SDL_SetColorKey(banqueImage->petitGobBleu, SDL_TRUE, SDL_MapRGB(banqueImage->petitGobBleu->format, 255,255,255));

	banqueImage->moyenGobBleu = Secure_SDL_LoadBMP("images_jeu/éléments/moyenGobelet_bleu.bmp");
	SDL_SetColorKey(banqueImage->moyenGobBleu, SDL_TRUE, SDL_MapRGB(banqueImage->moyenGobBleu->format, 255,255,255));

	banqueImage->grandGobBleu = Secure_SDL_LoadBMP("images_jeu/éléments/grosGobelet_bleu.bmp");
	SDL_SetColorKey(banqueImage->grandGobBleu, SDL_TRUE, SDL_MapRGB(banqueImage->grandGobBleu->format, 255,255,255));

	banqueImage->victoireJoueur1 = Secure_SDL_LoadBMP("images_jeu/menus/victoireJoueur1.bmp");
	banqueImage->victoireJoueur2 = Secure_SDL_LoadBMP("images_jeu/menus/victoireJoueur2.bmp");

	banqueImage->main = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
	banqueImage->fleche = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);

}


void event_recupRejouer(unsigned int rejouer, Img_jeu banqueImage)
{
	SDL_Event event;

	while(!rejouer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				exit(EXIT_SUCCESS);
			case SDL_MOUSEBUTTONUP:
				if(event.button.x > 550 && event.button.x < 700 && event.button.y > 650 && event.button.y < 750) rejouer = 1;
				if(event.button.x > 1100 && event.button.x < 1300 && event.button.y > 650 && event.button.y < 750) exit(EXIT_SUCCESS);
				break;
			case SDL_MOUSEMOTION:
				SDL_SetCursor(banqueImage.fleche);
				if(event.button.x > 1100 && event.button.x < 1300 && event.button.y > 650 && event.button.y < 750) SDL_SetCursor(banqueImage.main);
				else if(event.button.x > 550 && event.button.x < 700 && event.button.y > 650 && event.button.y < 750) SDL_SetCursor(banqueImage.main);
				else SDL_SetCursor(banqueImage.fleche);
				break;
		}
	}
	SDL_SetCursor(banqueImage.fleche);
}