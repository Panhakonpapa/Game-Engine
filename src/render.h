#include "player.h"
#include "platform.h"
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
SDL_Texture* player(SDL_Renderer* renderer, const char* filename);
SDL_Texture* world(SDL_Renderer* renderer, const char* filename);  
void render_platform(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* rect); 
void platform_init(SDL_Renderer* renderer, SDL_Texture* texture, Platform platform[], int num); 
