#ifndef HEADER 
#define HEADER 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int x, y; 
	int w, h; 
} Platform;

SDL_Texture* world(SDL_Renderer* renderer, const char* filename);
void create_platform(Platform* platform, int x, int y, int w, int h); 

typedef struct {	
	int vectorX, vectorY; 
	int width, height; 
	int speed;
	int jumpactive;  
} Player;

SDL_Texture* player(SDL_Renderer* renderer, const char* filename);  
void handle_movement(Player* player, int dirx, int diry);
void jump(Player* player);
void create_Player(Player* player, int x, int y, int w, int h, int speed); 
void is_player_on_ground(Player* player, int gravity); 
bool is_player_on_platform(Player* player, Platform* platfromsrc); 
void platform_init(SDL_Renderer* renderer, SDL_Texture* texture, Platform* platform1, Platform* platform2, Platform* platform3);
void player_init(SDL_Renderer* renderer, SDL_Texture* texture , Player* player); 
#endif 
