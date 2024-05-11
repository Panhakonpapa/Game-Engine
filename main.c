#include "Header/physic.h" 
#include "Header/world.h"
#include "Header/player.h"
#define WIDTH 800 
#define HEIGHT 600 
#define FPS 16 
#define NUM_FRAME 6 
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
	SDL_Texture* BackgoundTexture = world(renderer, "/home/panha/Game-Engine/assets/world/PREVIEWS/Hills Free (update 3.0).png"); 	
	SDL_Texture* PlayerTexture = player(renderer, "/home/panha/Game-Engine/assets/B_witch_idle.png"); 	
	while (1) 
	{		
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, BackgoundTexture, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(FPS); 	
	}	
	    SDL_DestroyTexture(BackgoundTexture);			 
	    SDL_DestroyTexture(PlayerTexture);
	    SDL_DestroyRenderer(renderer);
	    SDL_DestroyWindow(window);
	    SDL_Quit();
	return 0; 
} 



