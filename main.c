#include "game_libs.h"

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
	SDL_Texture* PlatformTexture = world(renderer, "/home/panha/game/Game-FS/assets/ground.png");	
	SDL_Texture* BackgroundTexture = world(renderer, "/home/panha/game/Game-FS/assets/bg.png"); 
	SDL_Texture* PlayerTexture = player(renderer, "/home/panha/game/Game-FS/assets/pee.png"); 	
	SDL_Texture* Lader = world(renderer, "/home/panha/game/Game-FS/assets/pixil-frame-2.png");
	SDL_Texture* Coins = world(renderer, "/home/panha/game/Game-FS/assets/coins.png");

	/* SDL get EVent */	
	SDL_Event event;
	int gameOver = false;
	float gravity = 5.f; 	
	/* calling platform */	
	Platform platform1, platform2, platform3, platform4, platform5;
	Dimon dimon1, dimon2, dimon3, dimon4, dimon5, dimon6, dimon7, dimon8, dimon9, dimon10;

	create_platform(&platform1, 370.f, 370.f, 300.f, 50.f); 
	create_platform(&platform2, 100.f, 200.f, 300.f, 50.f);
	create_platform(&platform3, 590.f, 500.f, 300.f, 50.f); 	
	create_platform(&platform4, 200.f, 210.f, 10.f, 300.f);	
	create_platform(&platform5, 0.f, 550.f, 800.f, 50.f);
	
	init_coins(&dimon1, 100, 540, 20, 20, 1); 
	init_coins(&dimon2, 200, 540, 20, 20, 1); 
	init_coins(&dimon3, 300, 540, 20, 20, 1); 	
	init_coins(&dimon4, 400, 540, 20, 20, 1); 
	init_coins(&dimon5, 500, 540, 20, 20, 1); 
	init_coins(&dimon6, 600, 540, 20, 20, 1); 
	init_coins(&dimon7, 800, 540, 20, 20, 1); 
	init_coins(&dimon8, 350, 540, 20, 20, 1); 
	init_coins(&dimon9, 340, 540, 20, 20, 1);
	Player player; 	
	create_Player(&player, 0, 400, 50, 50, 20);
	
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
				case SDLK_w: 
					handle_movement(&player, 0, -1);
					break; 	
				case SDLK_s: 
					handle_movement(&player, 0, 1); break; 
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
		    is_player_on_platform(&player, &platform3) || 
		    is_player_on_platform(&player, &platform4) ||  
		    is_player_on_platform(&player, &platform5)) 
					
		{
			// printf("%d %d\n", player.vectorX, player.vectorY); 						
			player.vectorY -= gravity; 			
			if (is_player_on_platform(&player, &platform4)) {
				update_platform(&platform1, 400, 200); 			
				update_platform(&platform3, 600, 100); 	
			}		
		}	
		if (is_player_on_platform(&player, &platform1)) {
			update_platform(&platform3, 600, 400); 	
			printf("No"); 	
		}
		platform_init(renderer, PlatformTexture, &platform1, &platform2, &platform3, &platform4, &platform5, Lader);

		SDL_Rect coin0 = {dimon1.x, dimon1.y, dimon1.w, dimon1.h}; 			
		SDL_Rect coin1 = {dimon2.x, dimon2.y, dimon2.w, dimon2.h};
		SDL_Rect coin2 = {dimon3.x, dimon3.y, dimon3.w, dimon3.h};
		SDL_Rect coin3 = {dimon4.x, dimon4.y, dimon4.w, dimon4.h};
		SDL_Rect coin4 = {dimon5.x, dimon5.y, dimon5.w, dimon5.h};
		SDL_Rect coin5 = {dimon6.x, dimon6.y, dimon6.w, dimon6.h};
		SDL_Rect coin6 = {dimon7.x, dimon7.y, dimon7.w, dimon7.h};	
		SDL_Rect coin7 = {dimon8.x, dimon8.y, dimon8.w, dimon8.h};
		SDL_Rect coin8 = {dimon9.x, dimon9.y, dimon9.w, dimon9.h};
		
		
		if (detect_Dimon(&dimon1, &player)) {
			dimon1.set_render = 0; 
		} else if (dimon1.set_render == 1) {	
			SDL_RenderCopy(renderer, Coins, NULL, &coin0);
		} 
			
		if (detect_Dimon(&dimon2, &player)) {
			dimon2.set_render = 0; 
		} else if (dimon2.set_render == 1) {	
			SDL_RenderCopy(renderer, Coins, NULL, &coin2);
		}
		
		if (detect_Dimon(&dimon3, &player)) {
			dimon3.set_render = 0; 
		} else if (dimon3.set_render == 1) {	
			SDL_RenderCopy(renderer, Coins, NULL, &coin3);
		} 
				
		if (detect_Dimon(&dimon4, &player)) {
			dimon4.set_render = 0; 
		} else if (dimon4.set_render == 1) {	
			SDL_RenderCopy(renderer, Coins, NULL, &coin4);
		}	
		
		if (detect_Dimon(&dimon5, &player)) {
			dimon5.set_render = 0; 
		} else if (dimon5.set_render == 1) {	
			SDL_RenderCopy(renderer, Coins, NULL, &coin5);
		} 
				
		if (detect_Dimon(&dimon6, &player)) {
			dimon6.set_render = 0; 
		} else if (dimon6.set_render == 1) {	
			SDL_RenderCopy(renderer, Coins, NULL, &coin6);
		}
		
		if (detect_Dimon(&dimon7, &player)) {
			dimon7.set_render = 0; 
		} else if (dimon3.set_render == 1) {	
			SDL_RenderCopy(renderer, Coins, NULL, &coin7);
		} 
				
		if (detect_Dimon(&dimon8, &player)) {
			dimon8.set_render = 0; 
		} else if (dimon8.set_render == 1) {	
			SDL_RenderCopy(renderer, Coins, NULL, &coin8);
		}

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
					SDL_DestroyTexture(Lader); 	
					SDL_DestroyTexture(Coins); 
					SDL_DestroyWindow(window);	
					SDL_Quit();
					return 0;
					break; 
	
			}			
		}
	} 
}


