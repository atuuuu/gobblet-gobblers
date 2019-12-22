#include <stdio.h>


void analyse_serie(board grille, player serie[])
{
	player place_holder = get_place_holder(grille, 0, 0);
	if(place_holder == get_place_holder(grille, 0, 1)) serie[0] = place_holder;
	if(place_holder == get_place_holder(grille, 1, 1)) serie[1] = place_holder;
	if(place_holder == get_place_holder(grille, 1, 2)) serie[2] = place_holder;

	place_holder = get_place_holder(grille, 0, 2);
	if(place_holder == get_place_holder(grille, 0, 1)) serie[3] = place_holder;
	if(place_holder == get_place_holder(grille, 1, 1)) serie[4] = place_holder;
	if(place_holder == get_place_holder(grille, 2, 2)) serie[5] = place_holder;

	place_holder = get_place_holder(grille, 1, 0);
	if(place_holder == get_place_holder(grille, 0, 1)) serie[6] = place_holder;
	if(place_holder == get_place_holder(grille, 2, 1)) serie[7] = place_holder;

	place_holder = get_place_holder(grille, 1, 2);
	if(place_holder == get_place_holder(grille, 0, 1)) serie[8] = place_holder;
	if(place_holder == get_place_holder(grille, 2, 1)) serie[9] = place_holder;

	place_holder = get_place_holder(grille, 2, 0);
	if(place_holder == get_place_holder(grille, 1, 0)) serie[10] = place_holder;
	if(place_holder == get_place_holder(grille, 1, 1)) serie[11] = place_holder;
	if(place_holder == get_place_holder(grille, 2, 1)) serie[12] = place_holder;

	place_holder = get_place_holder(grille, 2, 0);
	if(place_holder == get_place_holder(grille, 1, 1)) serie[13] = place_holder;
	if(place_holder == get_place_holder(grille, 1, 2)) serie[14] = place_holder;
	if(place_holder == get_place_holder(grille, 2, 1)) serie[15] = place_holder;
}