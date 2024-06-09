#include "/home/panha/game/Game-FS/include/render.h"

SDL_Texture* create_texture(SDL_Renderer* renderer, const char* filename) 
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

void render_background(SDL_Renderer* renderer, SDL_Texture* texture_location[]) {	
		
	char* array_layer[] = {
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0011_0.png",
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0010_1.png",
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0009_2.png", 
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0008_3.png", 
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0006_4.png", 		
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0005_5.png", 	
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0003_6.png",  	
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0002_7.png",  	
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0001_8.png",  		
		"/home/panha/Downloads/Free Pixel Art Forest/PNG/Background layers/Layer_0000_9.png", 	
	}; 
	for (int i = 0; i < 10; i++) {			
		
		SDL_Surface* surface = IMG_Load(array_layer[i]); 	
		if (surface == NULL) 
		{
			printf("Print: Error> Couldn't load the png\n"); 
		}
		texture_location[i] = SDL_CreateTextureFromSurface(renderer, surface); 	
		if (texture_location[i] == NULL)
		{		
			printf("Print: Error> Couldn't load the png\n"); 
		}
		SDL_FreeSurface(surface); 
	}	
}

