#ifndef MES_FONCTIONS_SON_21122019
#define MES_FONCTIONS_SON_21122019

#include "SDL/include/SDL2/SDL_Mixer.h"

#define poipoi 1
#define zimmy 2
#define atu 3
#define epic 4

typedef struct Son_jeu
{
	int pack;
	Mix_Music* ambiance;

	Mix_Chunk* choixAction1;
	Mix_Chunk* choixAction2;
	Mix_Chunk* choixAction3;

	Mix_Chunk* choixCase1;

	Mix_Chunk* choixTaille1;
	Mix_Chunk* choixTaille2;

	Mix_Chunk* victoire1;
	Mix_Chunk* victoire2;
	Mix_Chunk* victoire3;
	Mix_Chunk* victoire4;
	Mix_Chunk* victoire5;
	Mix_Chunk* victoire6;

	Mix_Chunk* actionImpossible1;
	Mix_Chunk* actionImpossible2;
	Mix_Chunk* actionImpossible3;
	Mix_Chunk* actionImpossible4;
	Mix_Chunk* actionImpossible5;
} Son_jeu;

void son_init();
void son_ambiance(Son_jeu banqueSon);
void son_choixAction(Son_jeu banqueSon);
void son_choixCase(Son_jeu banqueSon);
void son_choixTaille(Son_jeu banqueSon);
void son_victoire(Son_jeu banqueSon);
void son_actionImpossible(Son_jeu banqueSon);
void son_initBanqueSon(Son_jeu* banqueSon, int packVoix);

#endif
