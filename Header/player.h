#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <stdio.h>
typedef struct {	
	int vectorX, vectorY; 
	int width, height; 
	int speed;
	int jumpactive;  
} Player;
SDL_Texture* player(SDL_Renderer* renderer, const char* filename);  
void movement(Player* player, int dirx, int diry);
void jump(Player* player);
void call_Player(Player* player); 

