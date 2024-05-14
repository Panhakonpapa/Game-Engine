#ifndef PLAYER_H 
#define PLAYER_H
#include "/home/panha/Game-Engine/Header/player.h"
#include "/home/panha/Game-Engine/Header/physic.h"


SDL_Texture* player(SDL_Renderer* renderer, const char* filename) 
{
	SDL_Surface* surface = IMG_Load(filename); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); 
	SDL_FreeSurface(surface); 
	return texture; 
}
void call_Player(Objcet* objcet) {
	objcet->vectorX = 400; 	
	objcet->vectorY = 300;
	objcet->width = 50; 
	objcet->height = 50;
	objcet->jumpactive = 0;
	objcet->speed = 10;
}
#endif 
