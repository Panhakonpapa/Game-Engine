#ifndef HEADER 
#define HEADER 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	float x, y; 
	float w, h; 
} Platform;

typedef struct {	
	float vectorX, vectorY; 
	float width, height; 
	float speed;
	float jumpactive;  
} Player;

typedef struct {
	float x, y; 
	float w, h; 
	int set_render; 
} Dimon;

SDL_Texture* player(SDL_Renderer* renderer, const char* filename);  
SDL_Texture* world(SDL_Renderer* renderer, const char* filename);  
void handle_movement(Player* player, int dirx, int diry);
void jump(Player* player);
void create_Player(Player* player, float x, float y, float w, float h, float speed); 
void create_platform(Platform* platform, float x, float y, float w, float h); 
void is_player_on_ground(Player* player, float gravity); 
bool is_player_on_platform(Player* player, Platform* platfromsrc); 
void platform_init(SDL_Renderer* renderer, SDL_Texture* texture, Platform* platform1, Platform* platform2, Platform* platform3, Platform* platform4, Platform* platform5, SDL_Texture* lader);
void player_init(SDL_Renderer* renderer, SDL_Texture* texture , Player* player); 
void update_platform(Platform* platform, int posx, int posy);
void init_coins(Dimon* dimon, float x, float y, float w, float h, int set);  
bool detect_Dimon(Dimon* dimon, Player* player);

#endif 
