#include "/home/panha/game/Game-FS/include/render.h" 
#include "/home/panha/game/Game-FS/include/player.h"
#include "/home/panha/game/Game-FS/include/platform.h" 
#include "/home/panha/game/Game-FS/include/struct.h"

#define WIDTH 800 
#define HEIGHT 600 
#define FPS 16 

int main() {
	Game game;
	Player player; 
	SDL_Renderer* renderer; 
	SDL_Window* window; 
   	window = SDL_CreateWindow(NULL,
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				1000,
				900,
				0); 	
		
	renderer = SDL_CreateRenderer(window, -1, 0);
		
	SDL_Texture* bg0 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0011_0.png"); 		
	SDL_Texture* bg1 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0010_1.png"); 	
	SDL_Texture* bg2 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0009_2.png"); 		
	SDL_Texture* bg3 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0008_3.png"); 		
	SDL_Texture* bg4 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0006_4.png");		
	SDL_Texture* bg5 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0005_5.png");	
	SDL_Texture* bg6 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0003_6.png"); 	
	SDL_Texture* bg7 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0002_7.png"); 	
	SDL_Texture* bg8 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0001_8.png"); 		
	SDL_Texture* bg9 = create_texture(renderer, "/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0000_9.png"); 	
	
	SDL_Event event;
	game.g_gameOver = false;	
	SDL_Texture* texture = create_texture(renderer, "/home/panha/Downloads/Blue_witch/B_witch_idle.png"); 	
	SDL_Rect dest_aniamtion = draw_animtaion(400, 700, 150, 150);
	Animation* animation = init_indle_animation();
	int current_frame = 0; 	
	while (game.g_gameOver == false)
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
					game.g_gameOver = true;
					break;
			}	
		}	
						
		SDL_RenderClear(renderer);
			
		SDL_RenderCopy(renderer, bg0, NULL, NULL);			
		SDL_RenderCopy(renderer, bg1, NULL, NULL);			
		SDL_RenderCopy(renderer, bg2, NULL, NULL);				
		SDL_RenderCopy(renderer, bg3, NULL, NULL);				
		SDL_RenderCopy(renderer, bg4, NULL, NULL);				
		SDL_RenderCopy(renderer, bg5, NULL, NULL);				
		SDL_RenderCopy(renderer, bg6, NULL, NULL);									
		SDL_RenderCopy(renderer, bg7, NULL, NULL);
		SDL_RenderCopy(renderer, bg8, NULL, NULL);			
		SDL_RenderCopy(renderer, bg9, NULL, NULL);			
		
		current_frame++;
		if (current_frame > 6)
		{
			current_frame = 0; 
		}
		
		SDL_Rect src = src_sprite(animation, current_frame);
		play_animation(renderer, texture, &src, &dest_aniamtion); 
		
		SDL_RenderPresent(renderer);
		SDL_Delay(90); 	
	}	

	
	while (game.g_gameOver == true) {
		printf("gameOver\n");		
		while (SDL_PollEvent(&event)) {
		switch (event.key.keysym.sym) {
				case SDLK_q:
					SDL_DestroyRenderer(renderer);
					SDL_DestroyWindow(window);	
					SDL_DestroyTexture(bg1); 		
					SDL_DestroyTexture(bg2); 		
					SDL_DestroyTexture(bg3); 		
					SDL_DestroyTexture(bg4); 		
					SDL_DestroyTexture(bg5); 					
					SDL_DestroyTexture(bg6);	
					SDL_DestroyTexture(bg7);
					//distory_player(player);
					//distroy_platform(platform); 		
					SDL_Quit(); 
					return 0; 	
					break; 
	
			}			
		}
	}	
}
