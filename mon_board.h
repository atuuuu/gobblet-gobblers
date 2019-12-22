#ifndef BOARD_H_29112019
#define BOARD_H_29112019

#define NB_PLAYERS 2
#define NB_INITIAL_PIECES 2
#define DIMENSIONS 3
#define NB_SIZES 3

typedef enum size_e {NONE, SMALL, MEDIUM, LARGE} size;

typedef enum players_e {NO_PLAYER, PLAYER_1, PLAYER_2} player;

typedef struct board_s
{
	player tableauComplet[DIMENSIONS][DIMENSIONS][NB_SIZES];	//Première enrée : lignes 	Deuxième entrée : colonnes 	Troisième entrée : taille de la pièce (de 0 à 2)	Valeur : le joueur qui possède la case
	size tableauSize[DIMENSIONS][DIMENSIONS];
	player tableauPlayer[DIMENSIONS][DIMENSIONS];
	int compteurGobelet[NB_SIZES][DIMENSIONS];
}board_s;

typedef board_s* board;


//Prototypes des fonctions
board new_game();

void destroy_game(board game);

player next_player(player current_player);


player get_place_holder(board game, int line, int column);

size get_piece_size(board game, int line, int column);

player get_winner(board game);

int get_nb_piece_in_house(board game, player checked_player, size piece_size);


int place_piece(board game, player current_player, size piece_size, int line, int column);

int move_piece(board game, int source_line, int source_column, int target_line, int target_column);

#endif