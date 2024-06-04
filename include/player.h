#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "struct.h"
Player* create_player(float x, float y, float w, float h, float speed);  
void distory_player(Player* player); 
void jump(Player* player); 
void handle_movement(Player* player, int dirx, int diry); 
void is_player_on_ground(Player* player, float gravity);  


