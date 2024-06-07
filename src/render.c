#include "/home/panha/game/Game-FS/include/render.h"

SDL_Texture* texture(SDL_Renderer* renderer, const char* filename) 
{
	SDL_Surface* surface = IMG_Load(filename); 	
	if (surface == NULL) 
	{
		printf("Print: Error> Couldn't load the png\n"); 
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); 	
	if (texture == NULL)
	{		
		printf("Print: Error> Couldn't load the png\n"); 
	}
	SDL_FreeSurface(surface); 
	return texture; 
}

void game_loop(Render* render, Player* player, Game* game, Platform* platform, Animation* animation) {	
		render->window = SDL_CreateWindow(NULL, 
					SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, 
					800, 
					600,
					0); 	
			
		render->renderer = SDL_CreateRenderer(render->window, -1, 0); 
		SDL_Event event; 	
		while (game->g_gameOver == false)  
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
						game->g_gameOver = true; 
						break; 
				}	
			}	
							
			SDL_RenderClear(render->renderer);	
			SDL_RenderCopy(render->renderer, render->texture, NULL, NULL);
							

			SDL_RenderPresent(render->renderer);
			SDL_Delay(150); 	
		}	

		
		while (game->g_gameOver == true) {
			printf("gameOver\n");		
			while (SDL_PollEvent(&event)) {
			switch (event.key.keysym.sym) {
					case SDLK_q: 
						SDL_DestroyRenderer(render->renderer);
						SDL_DestroyWindow(render->window);	
						distory_player(player);
						distroy_platform(platform); 	
						SDL_Quit();
						break; 
		
				}			
			}
		} 
}
