#include "physic.h" 
#include <SDL2/SDL_image.h>
#define WIDTH 800 
#define HEIGHT 600 
int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Renderer* renderer;
	SDL_Window* window;
	window = SDL_CreateWindow(NULL, 
				SDL_WINDOWPOS_UNDEFINED, 
				SDL_WINDOWPOS_UNDEFINED, 
				WIDTH, 
				HEIGHT,
				0); 	
	renderer = SDL_CreateRenderer(window, -1, 0); 	
	while (1)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	return 0; 
} 



