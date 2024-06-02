#include "src/render.h" 
#include "src/player.h"
#include "src/platform.h" 
#define WIDTH 800 
#define HEIGHT 600 
#define FPS 16 

int g_gameOver = false; 
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
	//SDL_Texture* PlatformTexture = world(renderer, "/home/panha/game/Game-FS/assets/ground.png");	
	SDL_Texture* BackgroundTexture = world(renderer, "/home/panha/game/Game-FS/assets/bg.png"); 
	//SDL_Texture* PlayerTexture = player(renderer, "/home/panha/game/Game-FS/assets/pee.png"); 	
		
	Player* player = create_player(200.f, 200.f, 50.f, 50.f, 10.f); 
	Platform* platform = create_platform(20); 				
	pos_platform(platform, 20);

	printf("Player %f %f\n", player->vectorX, player->vectorY); 	

	SDL_Event event; 
	while (g_gameOver == false)  
	{		
		while (SDL_PollEvent(&event)) {
			switch (event.key.keysym.sym) {
				case SDLK_d:
					handle_movement(player, 1, 0); 
					break; 
				case SDLK_a:
					handle_movement(player, -1, 0); 
					break;
				case SDLK_SPACE: 
					jump(player); 
					break; 	
				case SDLK_q:
					g_gameOver = true; 
					break; 
			}	
		}	
			
		SDL_RenderClear(renderer);	
		SDL_RenderCopy(renderer, BackgroundTexture, NULL, NULL); 	
						

		SDL_RenderPresent(renderer);
		SDL_Delay(FPS); 	
	}	
	
	while (g_gameOver == true) {
		printf("gameOver\n");		
		while (SDL_PollEvent(&event)) {
		switch (event.key.keysym.sym) {
				case SDLK_q: 
					SDL_DestroyRenderer(renderer);
					//SDL_DestroyTexture(PlatformTexture);
					//SDL_DestroyTexture(BackgroundTexture);
					SDL_DestroyWindow(window);	
					distory_player(player);
					distroy_platform(platform); 	
					SDL_Quit();
					return 0;
					break; 
	
			}			
		}
	} 
}


