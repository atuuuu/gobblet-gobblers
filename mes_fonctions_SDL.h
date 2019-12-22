#ifndef MES_FONCTIONS_SDL_H_30112019
#define MES_FONCTIONS_SDL_H_30112019

#define POS_TABLEAU_X 440	//Position du tableau en largeur
#define POS_TABLEAU_Y 20	//Position du tableau en hauteur
#define POS_CASE_X 340		//Position dans laquelle on pose un pion dans une case (en largeur)
#define POS_CASE_Y 340		//Position dans laquelle on pose un pion dans une case (en hauteur)
#define LARGEUR_CASE 280	//largeur de la case
#define HAUTEUR_CASE 290	//hauteur de la case
#define TAILLE_BARRE 45		//Demi largeur d'une barre séparant 2 cases

//Petit gobelet :

#define POS_PETIT_GOB_BLEU_X 150
#define POS_PETIT_GOB_BLEU_Y 788

#define POS_PETIT_GOB_ROUGE_X 1630
#define POS_PETIT_GOB_ROUGE_Y 26

#define TAILLE_PETIT_GOB 250

#define POS_CHIFFRE_PETIT_BLEU_X 30
#define POS_CHIFFRE_PETIT_BLEU_Y 160

#define POS_CHIFFRE_PETIT_ROUGE_X 1505
#define POS_CHIFFRE_PETIT_ROUGE_Y 12

//Moyen gobelet :

#define POS_MOYEN_GOB_BLEU_X 150
#define POS_MOYEN_GOB_BLEU_Y 520

#define POS_MOYEN_GOB_ROUGE_X 1630
#define POS_MOYEN_GOB_ROUGE_Y 300

#define TAILLE_MOYEN_GOB 250

#define POS_CHIFFRE_MOYEN_BLEU_X 30
#define POS_CHIFFRE_MOYEN_BLEU_Y 480

#define POS_CHIFFRE_MOYEN_ROUGE_X 1505
#define POS_CHIFFRE_MOYEN_ROUGE_Y 290

//Grand gobelet :

#define POS_GRAND_GOB_BLEU_X 150
#define POS_GRAND_GOB_BLEU_Y 188

#define POS_GRAND_GOB_ROUGE_X 1630
#define POS_GRAND_GOB_ROUGE_Y 590

#define TAILLE_GRAND_GOB 250

#define POS_CHIFFRE_GRAND_BLEU_X 30
#define POS_CHIFFRE_GRAND_BLEU_Y 790

#define POS_CHIFFRE_GRAND_ROUGE_X 1505
#define POS_CHIFFRE_GRAND_ROUGE_Y 600

typedef struct
{
	SDL_Surface *petitGobRouge, *petitGobBleu, *moyenGobRouge, *moyenGobBleu, *grandGobRouge, *grandGobBleu, *victoireJoueur1, *victoireJoueur2, *curseur;
	SDL_Cursor *main, *fleche;
}Img_jeu;


void img_menu(SDL_Window* fenetre);

void event_recupChoixMenu(SDL_Window* fenetre, Img_jeu banqueImage);

void img_fondJeu(SDL_Window* fenetre, player joueur, Img_jeu banqueImage);

void img_actualiserTableau(SDL_Window* fenetre, board grille, Img_jeu banqueImage);

int event_recupererActionJoueur(SDL_Window* fenetre, player joueur, board grille, Coord tableauCase[], Img_jeu banqueImage);

int verif_actionFaisable(int actionChoisie, player joueur_actuel, board grille, Coord tableauCase[]);

void img_montrerTailleChoisie(SDL_Window* fenetre, player joueur, size tailleGobelet);

Coord event_recupCase(SDL_Event event, Img_jeu banqueImage);

void verif_afficherGobeletJoueur(SDL_Window* fenetre, player joueur, board grille, unsigned int* resteGobelet);
//-Affiche les gobelets restants du joueur 
//-Passe la variable resteGobelet à 1 si il reste des gobelets au joueur

size event_recupererTailleGobelet(SDL_Window* fenetre, player joueur, board grille, SDL_Event event, Img_jeu banqueImage);

/**
* @brief Raye les actions qui ne sont pas effectuable par le joueur
*/
void img_rayerActionInterdite(SDL_Window* fenetre, player joueur_actuel, board grille, Coord tableauCase[]);

void img_victoire(SDL_Window* fenetre, player vainqueur, Img_jeu banqueImage);

void initialiserTableauCoord(SDL_Rect coordCase[][3]);

void img_dragNdrop(SDL_Window* fenetre, SDL_Event event, size tailleGobelet, Img_jeu banqueImage, player joueur, board grille, int force, int clic);

void initialiserImageGobelet(Img_jeu* banqueImage);

void event_recupRejouer(unsigned int rejouer, Img_jeu banqueImage);

#endif
