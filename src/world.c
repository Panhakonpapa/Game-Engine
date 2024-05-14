#ifndef WORLD 
#define WORLD
#include "/home/panha/Game-Engine/Header/world.h"
SDL_Texture* world(SDL_Renderer* renderer, const char* filename) {
	SDL_Surface* surface = IMG_Load(filename);
	if (surface == NULL) 
	{
		printf("Print: Error> Couldn't load the png\n"); 
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);	
	if (texture == NULL)
	{		
		printf("Print: Error> Couldn't load the png\n"); 
	}
	SDL_FreeSurface(surface);
	return texture; 
}
#endif 
