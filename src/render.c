#include "/home/panha/game/Game-FS/include/render.h"

void platform_init(SDL_Renderer* renderer, SDL_Texture* texture, Platform platform[], int numPlatform) {		
	for (int i = 0; i < numPlatform; i++)
	{
		SDL_Rect platRect = {platform[i].plat_y, platform[i].plat_y, platform[i].plat_w, platform[i].plat_h}; 
		render_platform(renderer, texture, &platRect); 
	}
} 	

void render_platform(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* rect) {
	
	if (renderer && texture && rect)
	{
		SDL_RenderCopy(renderer, texture, NULL, rect); 
	}
	else 
	{
		printf("render or texture can't load properly"); 
	}
}


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
		SDL_Window* window = SDL_CreateWindow(NULL, 
					SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, 
					800, 
					600,
					0); 	
			
		render->renderer = SDL_CreateRenderer(window, -1, 0); 
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
						SDL_DestroyRenderer(renderer);
						SDL_DestroyWindow(window);	
						distory_player(player);
						distroy_platform(platform); 	
						SDL_Quit();
						break; 
		
				}			
			}
		} 
}
