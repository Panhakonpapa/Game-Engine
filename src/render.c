#include "render.h"

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

