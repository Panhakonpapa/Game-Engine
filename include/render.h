#include "player.h"
#include "platform.h"
#include "animation.h"
#include "struct.h"
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
SDL_Texture* create_texture(SDL_Renderer* renderer, const char* filename);  
void render_background(SDL_Renderer* renderer, SDL_Texture* texture_layer[]); 
