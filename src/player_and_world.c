#ifndef PLAYER_H 
#define PLAYER_H

#include "/home/panha/Bug-fix/Game-FS/Header/player_and_world.h"

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

void platform_init(SDL_Renderer* renderer, SDL_Texture* texture, Platform* platform1, Platform* platform2, Platform* platform3, Platform* platform4, Platform* platform5, SDL_Texture* lader) {	
	SDL_Rect plat1 = {platform1->x, platform1->y, platform1->w, platform1->h}; 	
	SDL_RenderCopy(renderer, texture, NULL, &plat1); 

	SDL_Rect plat2 = {platform2->x, platform2->y, platform2->w, platform2->h}; 		
	SDL_RenderCopy(renderer, texture, NULL, &plat2); 

	SDL_Rect plat3 = {platform3->x, platform3->y, platform3->w, platform3->h}; 		
	SDL_RenderCopy(renderer, texture, NULL, &plat3); 

	
	SDL_Rect plat4 = {platform4->x, platform4->y, platform4->w, platform4->h}; 		
	SDL_RenderCopy(renderer, lader, NULL, &plat4); 
	
	SDL_Rect plat5 = {platform5->x, platform5->y, platform5->w, platform5->h}; 		
	SDL_RenderCopy(renderer, texture, NULL, &plat5); 

} 	
void update_platform(Platform* platform, int new_posx, int new_posy) {
	platform->x = new_posx;
	platform->y = new_posy; 
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
		player->vectorY -= sqrt(2 * 100 * 9.8); 
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
	player->vectorY += gravity; 	
	if (player->vectorY + player->height >= HEIGHT)
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

void player_init(SDL_Renderer* renderer, SDL_Texture* texture, Player* player) {	
	SDL_Rect Player = {player->vectorX, player->vectorY, player->width, player->height}; 
		
	SDL_RenderCopy(renderer, texture, NULL, &Player); 
}
#endif 
