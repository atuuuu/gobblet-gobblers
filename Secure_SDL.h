#ifndef SECURE_SDL_H_01112019
#define SECURE_SDL_H_01112019

int Secure_SDL_Init(Uint32 flags);
SDL_Window* Secure_SDL_CreateWindow(const char* nom, int largeur, int hauteur);
SDL_Surface* Secure_SDL_LoadBMP(const char* path);

#endif