#ifndef PHYSIC_H 
#define PHYSIC_H 
#include "/home/panha/game/Game-FS/include/struct.h"
#include "/home/panha/game/Game-FS/include/player.h"

#include <stdbool.h>
void handle_movement(Player* player, int dirx, int diry); 
void jump(Player* player); 
void apply_gravity(Player* player, int gravity);  
bool collision(Player* player, Player* dest); 

#endif 
