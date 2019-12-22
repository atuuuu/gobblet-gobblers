#include "SDL/include/SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>


int Secure_SDL_Init(Uint32 flags)
{	
	if(SDL_Init(flags)==-1)
	{
		printf("Echec de l'initialisation de la SDL : %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	return EXIT_SUCCESS;
}


SDL_Window* Secure_SDL_CreateWindow(const char* nom, int largeur, int hauteur)
{
	SDL_Window* window = SDL_CreateWindow(nom, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, largeur, hauteur, SDL_WINDOW_SHOWN);
	
	if(window==NULL)
	{
		printf("Erreur de création de la fenetre : %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	return window;
}


SDL_Surface* Secure_SDL_LoadBMP(const char* path)
{
	SDL_Surface* picture = SDL_LoadBMP(path);
	if(picture == NULL)
	{
		printf("Impossible d'ouvrir l'image");
		exit(EXIT_FAILURE);
	}

	return picture;
}