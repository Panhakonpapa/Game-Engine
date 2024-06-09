#include "/home/panha/game/Game-FS/include/render.h"

SDL_Texture* create_texture(SDL_Renderer* renderer, const char* filename) 
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

SDL_Rect layer1(int x, int y, int w, int h) 
{
	SDL_Rect layer1 = {x,  y,  w, h};
	return layer1; 
}


SDL_Rect layer2(int x, int y, int w, int h) 
{
	SDL_Rect layer2 = {x,  y, w, h};
	return layer2; 
}
void create_background(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest) {
	if (texture != NULL && renderer != NULL)	
	{		
		SDL_RenderCopy(renderer, texture, src, dest);
	}
}
