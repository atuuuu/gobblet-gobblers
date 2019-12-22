#include <stdio.h>
#include "SDL/include/SDL2/SDL.h"
#include "SDL/include/SDL2/SDL_mixer.h"
#include "mes_fonctions_son.h"
#include <time.h>

void son_init()
{
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_AllocateChannels(1);
	Mix_Volume(1, 128);
	Mix_VolumeMusic(16);
	srand(time(NULL));
}

void son_initBanqueSon(Son_jeu* banqueSon, int packVoix)
{
	banqueSon->ambiance = Mix_LoadMUS("soundpack/ambiance.mp3");
	banqueSon->pack=packVoix;

	switch(packVoix)
	{
		/*case zimmy:
			banqueSon->choixAction = Mix_LoadMUS("soundpack/zimmy/choixAction.mp3");
			banqueSon->choixCase = Mix_LoadMUS("soundpack/zimmy/choixCase.mp3");
			banqueSon->choixTaille = Mix_LoadMUS("soundpack/zimmy/choixTaille.mp3");
			banqueSon->victoire = Mix_LoadMUS("soundpack/zimmy/victoire.mp3");
			banqueSon->actionImpossible = Mix_LoadMUS("soundpack/zimmy/actionImpossible.mp3");
			break;

		case poipoi:
			banqueSon->choixAction = Mix_LoadMUS("soundpack/poipoi/choixAction.mp3");
			banqueSon->choixCase = Mix_LoadMUS("soundpack/poipoi/choixCase.mp3");
			banqueSon->choixTaille = Mix_LoadMUS("soundpack/poipoi/choixCase.mp3");
			banqueSon->victoire = Mix_LoadMUS("soundpack/poipoi/victoire.mp3");
			banqueSon->actionImpossible = Mix_LoadMUS("soundpack/poipoi/actionImpossible.mp3");
			break;*/

		case atu:
			banqueSon->choixAction1 = Mix_LoadWAV("soundpack/atu/choixAction.wav");
			banqueSon->choixCase1 = Mix_LoadWAV("soundpack/atu/choixCase.wav");
			banqueSon->choixTaille1 = Mix_LoadWAV("soundpack/atu/choixTaille.wav");
			banqueSon->victoire1 = Mix_LoadWAV("soundpack/atu/victoire.wav");
			banqueSon->actionImpossible1 = Mix_LoadWAV("soundpack/atu/actionImpossible.wav");
			break;

		case epic:
			banqueSon->choixAction1 = Mix_LoadWAV("soundpack/epic/choixAction1.wav");
			banqueSon->choixAction2 = Mix_LoadWAV("soundpack/epic/choixAction2.wav");
			banqueSon->choixAction3 = Mix_LoadWAV("soundpack/epic/choixAction3.wav");
			banqueSon->choixCase1 = Mix_LoadWAV("soundpack/epic/choixCase1.wav");
			banqueSon->choixTaille1 = Mix_LoadWAV("soundpack/epic/choixTaille1.wav");
			banqueSon->choixTaille2 = Mix_LoadWAV("soundpack/epic/choixTaille2.wav");
			banqueSon->victoire1 = Mix_LoadWAV("soundpack/epic/victoire1.wav");
			banqueSon->victoire2 = Mix_LoadWAV("soundpack/epic/victoire2.wav");
			banqueSon->victoire3 = Mix_LoadWAV("soundpack/epic/victoire3.wav");
			banqueSon->victoire4 = Mix_LoadWAV("soundpack/epic/victoire4.wav");
			banqueSon->victoire5 = Mix_LoadWAV("soundpack/epic/victoire5.wav");
			banqueSon->victoire6 = Mix_LoadWAV("soundpack/epic/victoire6.wav");
			banqueSon->actionImpossible1 = Mix_LoadWAV("soundpack/epic/actionImpossible1.wav");
			banqueSon->actionImpossible2 = Mix_LoadWAV("soundpack/epic/actionImpossible2.wav");
			banqueSon->actionImpossible3 = Mix_LoadWAV("soundpack/epic/actionImpossible3.wav");
			banqueSon->actionImpossible4 = Mix_LoadWAV("soundpack/epic/actionImpossible4.wav");
			banqueSon->actionImpossible5 = Mix_LoadWAV("soundpack/epic/actionImpossible5.wav");
			break;
	}
}

void son_ambiance(Son_jeu banqueSon)
{
	Mix_PlayMusic(banqueSon.ambiance, -1);
}

void son_choixAction(Son_jeu banqueSon)
{
	if(banqueSon.pack == epic)
	{
		switch(rand()%3)
		{
			case 0:
				Mix_PlayChannel(0, banqueSon.choixAction1, 0);
				break;

			case 1:
				Mix_PlayChannel(0, banqueSon.choixAction2, 0);
				break;

			case 2:
				Mix_PlayChannel(0, banqueSon.choixAction3, 0);
				break;
		}
	}
	else if(banqueSon.pack == atu)
	{
		Mix_PlayChannel(0, banqueSon.choixAction1, 0);
	}
}

void son_choixCase(Son_jeu banqueSon)
{
	if(banqueSon.pack == epic)
	{
		Mix_PlayChannel(0, banqueSon.choixCase1, 0);
	}
	else if(banqueSon.pack == atu)
	{
		Mix_PlayChannel(0, banqueSon.choixCase1, 0);
	}
}

void son_choixTaille(Son_jeu banqueSon)
{
	if(banqueSon.pack == epic)
	{
		switch(rand()%2)
		{
			case 0:
				Mix_PlayChannel(0, banqueSon.choixTaille1, 0);
				break;

			case 1:
				Mix_PlayChannel(0, banqueSon.choixTaille2, 0);
				break;
		}
	}
	else if(banqueSon.pack == atu)
	{
		Mix_PlayChannel(0, banqueSon.choixTaille1, 0);
	}
}

void son_victoire(Son_jeu banqueSon)
{
	if(banqueSon.pack == epic)
	{
		switch(rand()%7)
		{
			case 0:
				Mix_PlayChannel(0, banqueSon.victoire1, 0);
				break;

			case 1:
				Mix_PlayChannel(0, banqueSon.victoire2, 0);
				break;

			case 3:
				Mix_PlayChannel(0, banqueSon.victoire3, 0);
				break;

			case 4:
				Mix_PlayChannel(0, banqueSon.victoire4, 0);
				break;

			case 5:
				Mix_PlayChannel(0, banqueSon.victoire5, 0);
				break;

			case 6:
				Mix_PlayChannel(0, banqueSon.victoire6, 0);
				break;
		}
	}
	else if(banqueSon.pack == atu)
	{
		Mix_PlayChannel(0, banqueSon.victoire1, 0);
	}
}

void son_actionImpossible(Son_jeu banqueSon)
{
	if(banqueSon.pack == epic)
	{
		switch(rand()%6)
		{
			case 0:
				Mix_PlayChannel(0, banqueSon.actionImpossible1, 0);
				break;

			case 1:
				Mix_PlayChannel(0, banqueSon.actionImpossible2, 0);
				break;

			case 3:
				Mix_PlayChannel(0, banqueSon.actionImpossible3, 0);
				break;

			case 4:
				Mix_PlayChannel(0, banqueSon.actionImpossible4, 0);
				break;

			case 5:
				Mix_PlayChannel(0, banqueSon.actionImpossible5, 0);
				break;
		}
	}
	else if(banqueSon.pack == atu)
	{
		Mix_PlayChannel(0, banqueSon.actionImpossible1, 0);
	}
}
