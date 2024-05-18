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
	SDL_Texture* PlatformTexture = world(renderer, "/home/panha/Bug-fix/Game-FS/assets/pixil-frame-1.png");	
	SDL_Texture* BackgroundTexture = world(renderer, "/home/panha/Bug-fix/Game-FS/assets/bg.png"); 
	SDL_Texture* PlayerTexture = player(renderer, "/home/panha/Bug-fix/Game-FS/assets/pixil-frame-0.png"); 

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
			
		SDL_RenderClear(renderer);	
		SDL_RenderCopy(renderer, BackgroundTexture, NULL, NULL); 	
		
		player_init(renderer, PlayerTexture, &player); 		
		
		is_player_on_ground(&player, gravity); 	
		
		if (is_player_on_platform(&player, &platform1) || 
		    is_player_on_platform(&player, &platform2) || 
		    is_player_on_platform(&player, &platform3)) 
		{
			printf("%d %d\n", player.vectorX, player.vectorY); 	
			player.vectorY -= gravity; 	
		}
		
		platform_init(renderer, PlatformTexture, &platform1, &platform2, &platform3);

		SDL_RenderPresent(renderer);
		SDL_Delay(FPS); 	
	}	
	
	while (gameOver == true) {
		printf("gameOver\n");		
		while (SDL_PollEvent(&event)) {
		switch (event.key.keysym.sym) {
				case SDLK_q: 
					SDL_DestroyRenderer(renderer);
					SDL_DestroyTexture(PlatformTexture);
					SDL_DestroyTexture(BackgroundTexture); 
					SDL_DestroyWindow(window);	
					SDL_Quit();
					return 0;
					break; 
	
			}			
		}
	} 
}


