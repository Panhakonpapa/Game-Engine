#include "render.h"
void platform_init(SDL_Renderer* renderer, SDL_Texture* texture, Platform platform[], int numPlatform) {		
	for (int i = 0; i < numPlatform; i++)
	{
		SDL_Rect platRect = {platform[i].y, platform[i].y, platform[i].w, platform[i].h}; 
		render_platform(renderer, texture, &platRect); 
	}
} 	

void render_platform(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* rect) {
	
	if (renderer && texture && rect)
	{
		SDL_RenderCopy(renderer, texture, NULL, rect); 
	}
	else 
	{
		printf("render or texture can't load properly"); 
	}
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

