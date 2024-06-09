#include "/home/panha/game/Game-FS/include/render.h" 
#include "/home/panha/game/Game-FS/include/player.h"
#include "/home/panha/game/Game-FS/include/platform.h" 
#include "/home/panha/game/Game-FS/include/struct.h"
#include "/home/panha/game/Game-FS/include/physic.h"
int main() {
	Game game;
	SDL_Renderer* renderer; 
	SDL_Window* window; 
   	window = SDL_CreateWindow(NULL,
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				800,
				600,
				0); 	
		
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	/* Backgornd layer render */
	SDL_Texture* bg_layer[10]; 
	render_background(renderer, bg_layer);	

	/* Game property (config file in struct.h) */
	SDL_Event event;
	game.g_gameOver = false;	

	/* Player init */
	Player* player = create_player(400, 470, 90, 100, 10);  			
	
	/* Init anmation */	
	int current_frame = 0; 	
	int play = 0;  
	Animation* animation_idle = init_indle_animation();
	Animation* animation_run = init_run_animation();	
	Animation* animation_charge = init_charge_animation();

	/* Load player texture */
	SDL_Texture* texture_idle = create_texture(renderer, "/home/panha/Downloads/Blue_witch/B_witch_idle.png"); 		
	SDL_Texture* texture_run = create_texture(renderer, "/home/panha/Downloads/Blue_witch/B_witch_run.png"); 			
	SDL_Texture* texture_charge = create_texture(renderer, "/home/panha/Downloads/Blue_witch/B_witch_charge.png"); 

	/* Start the game loop if game is not over */
	while (game.g_gameOver == false)
	{		
			
						
		SDL_RenderClear(renderer);	
		for (int i = 0; i < 10; i++) {
			SDL_RenderCopy(renderer, bg_layer[i], NULL, NULL); 
		}			

		/* define the sourse of the objcet and the desternation */
		SDL_Rect dest_aniamtion = draw_animtaion(player->p_x, player->p_y, player->p_w, player->p_h);
		SDL_Rect src_idle = src_sprite(animation_idle, current_frame);	
		SDL_Rect src_run = src_sprite(animation_run, current_frame);								
		SDL_Rect src_charge = src_sprite(animation_run, current_frame);								
	
		/* Player indle Animation */
		current_frame++;  				
		if (current_frame > animation_idle->n_frame) 
		{
			current_frame = 0; 
		}
	
		/* switch and play diffrent animation */
		switch (play) {
			case 1: 		
				current_frame++;  				
				if (current_frame > animation_run->n_frame) 
				{
					current_frame = 0; 
				}
				play_animation(renderer, texture_run, &src_run, &dest_aniamtion);
				play = 0; 	
				break; 
			case 2:					
				current_frame++;  				
				if (current_frame > animation_charge->n_frame) 
				{
					current_frame = 0; 
				}
				play_animation(renderer, texture_charge, &src_charge, &dest_aniamtion);
				play = 0; 	
				break; 
			default:	
				play_animation(renderer, texture_idle, &src_idle, &dest_aniamtion); 				
				
		}
		/* SDL get even ot the game */	
		while (SDL_PollEvent(&event)) {
			switch (event.key.keysym.sym) {
				case SDLK_d:
					handle_movement(player, 1, 0);				
					play = 1;	
					break;
				case SDLK_a:
					handle_movement(player, -1, 0);	
					break;
				case SDLK_f: 
					play = 2;
					break; 
				case SDLK_SPACE:
					jump(player);
					break; 	
				case SDLK_q:
					game.g_gameOver = true;
					break;			
			}	 
					

		}

		apply_gravity(player, 50); 				
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
							
					for (int i = 0; i < 10; i++) {
						SDL_DestroyTexture(bg_layer[i]); 	
					}		
					free_anmiation(animation_run); 			
					free_anmiation(animation_idle); 			
					free_anmiation(animation_charge); 		
					SDL_Quit(); 
					return 0; 	
					break; 
	
			}			
		}
	}	
}
