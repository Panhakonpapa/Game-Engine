#ifndef STRUCT_H 
#define STRUCT_H
#include <SDL2/SDL.h>

typedef struct {
	float plat_x;  
	float plat_y; 
	float plat_w; 
	float plat_h; 
} Platform;

typedef struct {	
	int p_x; 
	int p_y; 
	int p_w; 
	int p_h; 
	int p_jactive; 
	int p_speed; 
} Player;

typedef struct {
	int g_start; 	
	int g_gameOver; 
	int g_checkAsset; 
	int g_checkRender;
	int g_playMusic;
} Game;

typedef struct {		
	char* name; 
	int n_frame; 
	int w_frame; 
	int h_frame; 
	int x_frame; 
	int y_frame;	
} Animation;

typedef struct {
	SDL_Renderer* renderer; 
	SDL_Window* window; 		
	SDL_Texture* texture; 
	SDL_Surface* surface; 
} Render;

#endif 
