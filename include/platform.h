#include <stdlib.h>
#include "struct.h"
void renderPlatforms(SDL_Renderer* renderer, SDL_Texture* platformTexture, Platform platforms[], int count); 
void pos_platform(Platform platform[], int startx, int starty, int spacing, int numPlatform);  
Platform* create_platform(int numPlatform);
void distroy_platform(Platform* platform); 

