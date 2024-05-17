#include "Header/player.h"
#include "Header/physic.h"

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
	int gameOver = false;
	int gravity = 10; 	
	/* calling platform */	
	Platform platform1, platform2, platform3;
	create_platform(&platform1, 370, 370, 200, 10); 	
	create_platform(&platform2, 100, 370, 200, 10);
	create_platform(&platform3, 580, 390, 200, 10); 

	/* Calling player Objcet */	
	Player player; 	
	create_Player(&player, 400, 400, 50, 50, 20);
	
	while (gameOver == false)  
	{		
		while (SDL_PollEvent(&event)) {
			switch (event.key.keysym.sym) {
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

		player_init(renderer, &player); 	
		
		is_player_on_ground(&player, gravity); 	
		
		if (is_player_on_platform(&player, &platform1) || 
		    is_player_on_platform(&player, &platform2) || 
		    is_player_on_platform(&player, &platform3)) 
		{
			printf("%d %d\n", player.vectorX, player.vectorY); 	
			player.vectorY -= gravity; 	
		}
		
		platform_init(renderer, &platform1, &platform2, &platform3);

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


