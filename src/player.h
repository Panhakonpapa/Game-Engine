#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



typedef struct {	
	float vectorX, vectorY; 
	float width, height; 
	float speed;
	float jumpactive;  
} Player;

Player* create_player(float x, float y, float w, float h, float speed);  
void distory_player(Player* player); 
void jump(Player* player); 
void handle_movement(Player* player, int dirx, int diry); 
void is_player_on_ground(Player* player, float gravity);  


