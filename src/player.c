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

void platform_init(SDL_Renderer* renderer, Platform* platform1, Platform* platform2, Platform* platform3) {	
	SDL_Rect plat1 = {platform1->x, platform1->y, platform1->w, platform1->h}; 	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
	SDL_RenderFillRect(renderer, &plat1); 	

		
	SDL_Rect plat2 = {platform2->x, platform2->y, platform2->w, platform2->h}; 	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
	SDL_RenderFillRect(renderer, &plat2);

		
	SDL_Rect plat3 = {platform3->x, platform3->y, platform3->w, platform3->h}; 	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
	SDL_RenderFillRect(renderer, &plat3);

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

void player_init(SDL_Renderer* renderer, Player* player) {	
	SDL_Rect Player = {player->vectorX, player->vectorY, player->width, player->height}; 
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);		
	SDL_RenderFillRect(renderer, &Player);
}
#endif 
