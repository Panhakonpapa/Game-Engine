#ifndef PLAYER_H 
#define PLAYER_H

#include "/home/panha/Bug-fix/Game-FS/Header/player.h"

#define HEIGHT 600 


/* World Bulding part */
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
void create_platform(Platform* platform, int x, int y, int w, int h)
{
	platform->x = x; 
	platform->y = y; 
	platform->w = w; 
	platform->h = h; 
}




/* Player part */
SDL_Texture* player(SDL_Renderer* renderer, const char* filename) 
{
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

void create_Player(Player* player, int x, int y, int w, int h, int speed) {
	player->vectorX = x; 	
	player->vectorY = y;
	player->width = w; 
	player->height = h;
	player->jumpactive = 0;
	player->speed = speed;
}
void jump(Player* player)
{
	player->jumpactive = 1; 	
	if (player->jumpactive == 1)
	{
		player->vectorY -= sqrt(2 * 300 * 9.8); 
	}

	if (player->vectorY + player->height >= HEIGHT)
	{
		player->jumpactive = 0; 
	}
}

void handle_movement(Player* player, int dirx, int diry)
{
	player->vectorX += dirx * player->speed; 
	player->vectorY += diry * player->speed;
}

void is_player_on_ground(Player* player, int gravity) 
{
	if (player->vectorY + player->vectorY >= HEIGHT)
	{
		player->vectorY -= gravity; 
		player->jumpactive = 0; 	
	}
}

bool is_player_on_platform(Player* player, Platform* platfromsrc) {
	return (player->vectorX <  platfromsrc->x + platfromsrc->w &&
		player->vectorX + player->width > platfromsrc->x &&
		player->vectorY < platfromsrc->y + platfromsrc->h &&
		player->vectorY + player->height > platfromsrc->y);  
}
#endif 
