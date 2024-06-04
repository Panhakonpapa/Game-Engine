#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main() {
	SDL_Init(SDL_INIT_EVERYTHING); 	
	SDL_Renderer* renderer; 
	SDL_Window* window; 
	window = SDL_CreateShapedWindow(NULL, 
				SDL_WINDOWPOS_UNDEFINED, 
				SDL_WINDOWPOS_UNDEFINED, 
				800, 
				600,
				0); 
	renderer = SDL_CreateRenderer(window, -1, 0); 
	SDL_Rect dst = {400, 300, 158, 140};
	int frame = 0;
		
	SDL_Surface* surface = IMG_Load("/home/panha/Downloads/Monsters_Creatures_Fantasy/Skeleton/Attack.png"); 	
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
	
	while (1) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
		SDL_RenderClear(renderer);	
			 
		SDL_Rect src = {frame * 150, 0, 158, 140}; 
		frame++; 
		if (frame > 8) {
			frame = 0; 
		}
		SDL_RenderCopy(renderer, texture, &src, &dst); 
		SDL_RenderPresent(renderer);	
		SDL_Delay(160); 
	}
} 

