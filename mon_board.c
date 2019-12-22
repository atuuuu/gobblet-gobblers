#include <stdio.h>
#include <stdlib.h>
#include "mon_board.h"

board new_game()
{
	board jeu;
	jeu = malloc(sizeof(board_s));
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			jeu->tableauSize[i][j]=NONE;
			jeu->tableauPlayer[i][j]=NO_PLAYER;
			for (int k = 0; k < 3; k++)
			{
				jeu->tableauComplet[i][j][k] = NO_PLAYER;
			}
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			jeu->compteurGobelet[i][j]=NB_INITIAL_PIECES;
		}
	}
	return jeu;
}


void destroy_game(board game)
{
	free(game);
}


player get_place_holder(board game, int line, int column)
{
	player place_holder = game->tableauPlayer[line][column];
	return place_holder;
}


size get_piece_size(board game, int line, int column)
{
	size piece_size = game->tableauSize[line][column];
	return piece_size;
}


player get_winner(board game)
{
	player winner=NO_PLAYER;
	player winner2=NO_PLAYER;

	for(int i=0; i < 2; i++)
	{
		//Vérifier les lignes, les colonnes et les diagonales
		if(game->tableauPlayer[0][0]==game->tableauPlayer[0][1] && game->tableauPlayer[0][0]==game->tableauPlayer[0][2] && game->tableauPlayer[0][0]!=NO_PLAYER) 
		{
			winner = game->tableauPlayer[0][0];
		}

		if(game->tableauPlayer[1][0]==game->tableauPlayer[1][1] && game->tableauPlayer[1][0]==game->tableauPlayer[1][2] && game->tableauPlayer[1][0]!=NO_PLAYER)
		{
			if(winner!=NO_PLAYER) winner2 = game->tableauPlayer[1][0];
			else winner = game->tableauPlayer[1][0];
		}

		if(game->tableauPlayer[2][0]==game->tableauPlayer[2][1] && game->tableauPlayer[2][0]==game->tableauPlayer[2][2] && game->tableauPlayer[2][0]!=NO_PLAYER)
		{
			if (winner != NO_PLAYER) winner2 = game->tableauPlayer[2][0];
			else winner = game->tableauPlayer[2][0];
		}

		if(game->tableauPlayer[0][0]==game->tableauPlayer[1][0] && game->tableauPlayer[0][0]==game->tableauPlayer[2][0] && game->tableauPlayer[0][0]!=NO_PLAYER)
		{
			if(winner != NO_PLAYER) winner2 = game->tableauPlayer[0][0];
			else winner = game->tableauPlayer[0][0];
		}

		if(game->tableauPlayer[0][1]==game->tableauPlayer[1][1] && game->tableauPlayer[0][1]==game->tableauPlayer[2][1] && game->tableauPlayer[0][1]!=NO_PLAYER)
		{
			if(winner != NO_PLAYER) winner2 = game->tableauPlayer[0][1];
			else winner = game->tableauPlayer[0][1];
		}

		if(game->tableauPlayer[0][2]==game->tableauPlayer[1][2] && game->tableauPlayer[0][2]==game->tableauPlayer[2][2] && game->tableauPlayer[0][2]!=NO_PLAYER)
		{
			if(winner != NO_PLAYER) winner2 = game->tableauPlayer[0][2];
			else winner = game->tableauPlayer[0][2];
		}
		
		if(game->tableauPlayer[0][0]==game->tableauPlayer[1][1] && game->tableauPlayer[0][0]==game->tableauPlayer[2][2] && game->tableauPlayer[0][0]!=NO_PLAYER)
		{
			if(winner != NO_PLAYER) winner2 = game->tableauPlayer[0][0];
			else winner = game->tableauPlayer[0][0];
		}

		if(game->tableauPlayer[0][2]==game->tableauPlayer[1][1] && game->tableauPlayer[0][2]==game->tableauPlayer[2][0] && game->tableauPlayer[0][2]!=NO_PLAYER)
		{
			if(winner != NO_PLAYER) winner2 = game->tableauPlayer[0][2];
			else winner = game->tableauPlayer[0][2];
		}
	}

	if(winner != NO_PLAYER && winner2 != NO_PLAYER && winner != winner2) winner = 3;

	return winner;
}


player next_player(player current_player)
{
	player returned_player=0;
	if(current_player==1) returned_player=2;
	else if(current_player==2) returned_player=1;

	return returned_player;
}


int get_nb_piece_in_house(board game, player checked_player, size piece_size)
{
	int nb_piece=game->compteurGobelet[checked_player-1][piece_size-1];

	return nb_piece;
}


int place_piece(board game, player current_player, size piece_size, int line, int column)
{
	int value=-1;
	if(line > 2 || line < 0 || column > 2 || column < 0) value = 3;
	else
	{
		if (game->compteurGobelet[current_player-1][piece_size-1] > 0)
		{
			if (piece_size > game->tableauSize[line][column])
			{
				game->tableauComplet[line][column][piece_size-1]=current_player;
				game->tableauSize[line][column] = piece_size;
				game->tableauPlayer[line][column] = current_player;
				game->compteurGobelet[current_player-1][piece_size-1]--;
				value = 0;
			}
			else value = 2;
		}
		else value = 1;
	}
	return value;
}


int move_piece(board game, int source_line, int source_column, int target_line, int target_column)
{
	int value=-1;			//On initialise la valeur de sortie
	size piece_size;		//On initialise la taille de la pièce déplacée

	//On vérifie que les coordonnées de la case sont valides
	if(source_line > 2 || source_line < 0 || source_column > 2 || source_column < 0 || target_line > 2 || target_line < 0 || target_column > 2 || target_column < 0) value = 3;	//Non : on retourne 3

	else	//Si oui :
	{
		if (game->tableauSize[source_line][source_column] != NONE)	//On vérifie qu'il y a bien un gobelet à déplacer sur la case
		{
			piece_size = game->tableauSize[source_line][source_column];	//Si oui, on récupère sa taille

			if (game->tableauSize[source_line][source_column] > game->tableauSize[target_line][target_column])	//On vérifie que le gobelet sur la case de départ est plus grand que le gobelet sur la case d'arrivé
			{
				game->tableauComplet[target_line][target_column][piece_size-1]=game->tableauComplet[source_line][source_column][piece_size-1];	//On donne à la case cible la valeur de la case source
				game->tableauSize[target_line][target_column] = piece_size;		//On enregistre la taille du nouveau gobelet sur la case de surface
				game->tableauPlayer[target_line][target_column] = game->tableauComplet[source_line][source_column][piece_size-1];	//On enregistre le nouveau détenteur de la case de surface
				
				game->tableauSize[source_line][source_column] = NONE;		//On efface la taille du gobelet de la case source
				game->tableauPlayer[source_line][source_column] = NO_PLAYER;	//On met à jour le détenteur de la case cible
				game->tableauComplet[source_line][source_column][piece_size-1] = NO_PLAYER;		//On efface la valeur de la case source dans le tableau principal

				for (int i = 0; i < 2; ++i)
				{
					if (game->tableauComplet[source_line][source_column][i]!=0)
					{
						game->tableauSize[source_line][source_column]=i+1;
						game->tableauPlayer[source_line][source_column]=game->tableauComplet[source_line][source_column][i];
					}
				}
				value = 0;			//Si tout se passe bien on renvoie 0
			}

			else value = 2;		//Si le gobelet déplacé ne peut pas recouvrir le gobelet de la case choisie on retourne 2
		}
		else value = 1;		//S'il n'y a pas de gobelet sur la case on renvoie 1
	}
	return value;
}
