#include "player.h"
#include "platform.h"
#include "animation.h"
#include "struct.h"
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
SDL_Texture* create_texture(SDL_Renderer* renderer, const char* filename);  
void create_background(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);  
SDL_Rect layer1(int x, int y, int w, int h); 
SDL_Rect layer2(int x, int y, int w, int h); 
