#include "struct.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>


void play_animation(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);  
SDL_Rect src_sprite(Animation* animation, int loop); 
void free_anmiation(Animation* src_animation);  
void print_debug(Animation* anime, int loop); 
SDL_Rect draw_animtaion(int x, int y, int w, int h); 
Animation* init_indle_animation(); 
Animation* init_run_animation(); 

