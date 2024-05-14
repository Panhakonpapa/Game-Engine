#include "Header/physic.h" 
#include "Header/world.h"
#include "Header/player.h"
#include <stdbool.h>

#define WIDTH 800 
#define HEIGHT 600 
#define FPS 16 

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Renderer* renderer;
	SDL_Window* window;
	/* SDL Create window */	
	window = SDL_CreateWindow(NULL, 
				SDL_WINDOWPOS_UNDEFINED, 
				SDL_WINDOWPOS_UNDEFINED, 
				WIDTH, 
				HEIGHT,
				0); 	
	
	/* SDL Create renderer */	
	renderer = SDL_CreateRenderer(window, -1, 0); 
	/* SDL get EVent */	
	SDL_Event event;
	int gameOver = true; 	
	
	while (gameOver == true)  
	{		
		while (SDL_PollEvent(&event)) {
			switch (event.key.keysym.sym) {
				case SDLK_s: 
					break; 
				case SDLK_w:
					break; 
				case SDLK_d:
					break; 
				case SDLK_a:
					break; 
				case SDLK_q:
					break;
			}	
		}	
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPresent(renderer);
		SDL_Delay(FPS); 	
	}	
	
	while (gameOver == false) {
		printf("gameOver\n");		
		while (SDL_PollEvent(&event)) {
		switch (event.key.keysym.sym) {
				case SDLK_q: 
					SDL_DestroyRenderer(renderer);
					SDL_DestroyWindow(window);	
					SDL_Quit();
					return 0;
					break; 
	
			}			
		}
	} 
}


