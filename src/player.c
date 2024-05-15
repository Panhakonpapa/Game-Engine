#ifndef PLAYER_H 
#define PLAYER_H
#include "/home/panha/Game-Engine/Header/player.h"
#define HEIGHT 600 
SDL_Texture* player(SDL_Renderer* renderer, const char* filename) 
{
	SDL_Surface* surface = IMG_Load(filename); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); 
	SDL_FreeSurface(surface); 
	return texture; 
}

void call_Player(Player* player) {
	player->vectorX = 400; 	
	player->vectorY = 300;
	player->width = 50; 
	player->height = 50;
	player->jumpactive = 0;
	player->speed = 10;
}
void jump(Player* player)
{
	player->jumpactive = 1; 	
	if (player->jumpactive == 1)
	{
		player->vectorY -= sqrt(2 * 100 * 9.8); 
	}

	if (player->vectorY + player->height >= HEIGHT)
	{
		player->jumpactive = 0; 
	}
}

void movement(Player* player, int dirx, int diry)
{
	player->vectorX += dirx * player->speed; 
	player->vectorY += diry * player->speed;
}

#endif 
