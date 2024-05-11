#include "Header/physic.h" 
#include "Header/world.h"
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
	SDL_Texture* Backgound = world(renderer, "/home/panha/Game-Engine/assets/world/PREVIEWS/Hills Free (update 3.0).png"); 	
	while (1)
	{
				
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, Backgound, NULL, NULL); 	
		SDL_RenderPresent(renderer);
		SDL_Delay(16); 	
	}
	return 0; 
} 



