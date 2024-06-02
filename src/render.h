#include "player.h"
#include "platform.h"
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
void platform_init(SDL_Renderer* renderer, SDL_Texture* texture, Platform* platform1, Platform* platform2, Platform* platform3, Platform* platform4, Platform* platform5, SDL_Texture* lader); 	
SDL_Texture* player(SDL_Renderer* renderer, const char* filename);
SDL_Texture* world(SDL_Renderer* renderer, const char* filename);  
