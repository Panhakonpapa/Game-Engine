#ifndef PLAYER_H 
#define PLAYER_H
#include"Header/player.h"
SDL_Texture* player(SDL_Renderer* renderer, const char* filename) 
{
	SDL_Surface* surface = IMG_Load(filename); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); 
	SDL_FreeSurface(surface); 
	return texture; 
}
#endif 
