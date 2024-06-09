#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "struct.h"
Player* create_player(int x, int y, int w, int h, int speed);  
void distory_player(Player* player); 
void jump(Player* player); 
void handle_movement(Player* player, int dirx, int diry); 


