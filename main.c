#include "Header/player.h"

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
	int gravity; 
	int gameOver = false;
	/* calling platform */	
	Platform platform;
	create_platform(&platform, 370, 370, 100, 50); 
	/* Calling player Objcet */	
	Player player; 	
	create_Player(&player, 400, 400, 50, 50, 20);
	
	while (gameOver == false)  
	{		
		while (SDL_PollEvent(&event)) {
			switch (event.key.keysym.sym) {
				case SDLK_s:
					handle_movement(&player, 0, 1); 
					break; 
				case SDLK_w:
					handle_movement(&player, 0, -1); 
					break; 
				case SDLK_d:
					handle_movement(&player, 1, 0); 
					break; 
				case SDLK_a:
					handle_movement(&player, -1, 0); 
					break;
				case SDLK_SPACE: 
					jump(&player); 
					break; 	
				case SDLK_q:
					gameOver = true; 
					break; 
			}	
		}	
			
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		

		SDL_Rect Player = {player.vectorX, player.vectorY, player.width, player.height}; 
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);		
		SDL_RenderFillRect(renderer, &Player);
		gravity += 10; 
		is_player_on_ground(&player, gravity); 	
		if (is_player_on_platform(&player, &platform) == true) 
		{
			printf("%d %d\n", player.vectorX, player.vectorY); 	
			player.vectorX = platform.x - player.vectorX;
			player.vectorY = platform.y - player.vectorY; 
		}
		
		SDL_Rect Platform = {platform.x, platform.y, platform.w, platform.h}; 	
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
		SDL_RenderFillRect(renderer, &Platform); 	
		
		SDL_RenderPresent(renderer);
		SDL_Delay(FPS); 	
	}	
	
	while (gameOver == true) {
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


