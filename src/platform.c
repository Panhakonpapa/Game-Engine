#include "/home/panha/game/Game-FS/include/platform.h"
#include <stdio.h>
#include <SDL2/SDL.h>

void renderPlatforms(SDL_Renderer* renderer, SDL_Texture* platformTexture, Platform platforms[], int count) {
    for (int i = 0; i < count; ++i) {
        SDL_Rect renderQuad = { platforms[i].plat_x, platforms[i].plat_y, 50, 10 };  
        SDL_RenderCopy(renderer, platformTexture, NULL, &renderQuad);
    }
}

void pos_platform(Platform platform[], int startx, int starty, int spacing, int numPlatform) {
	for (int i = 0; i < numPlatform; i++) 
	{
		platform[i].plat_x = startx + i * spacing;
		platform[i].plat_y = starty; 	
	}
}

Platform* create_platform(int numPlatform) 
{
	Platform* platform = (Platform*)malloc(sizeof(Platform) * numPlatform); 
	if (platform != NULL)
	{ 				
		return platform; 
	}
	else {
		if (platform == NULL) {	
			free(platform); 
			printf("Error Memory won't able to alllcated so it drop fucntion <create_platform>\n");  	
		}
			
		exit(1); 
	}
}
p
void distroy_platform(Platform* platform)
{
	if (platform == NULL)	
	{	
		free(platform); 
	}
	else 
	{
		printf("Memory still being allocated"); 
	}
}

