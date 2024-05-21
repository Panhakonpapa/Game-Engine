#ifndef FOOD_H 
#define FOOD_H
#include "/home/panha/Bug-fix/Game-FS/Header/player_and_world.h"
#include <stdbool.h>
typedef struct {
	int x, y; 
	int w, h; 
} Dimon;

void init_coins(Dimon* dimon, int x, int y, int w, int h); 
bool detect_Dimon(Dimon* dimon, Player* player); 

#endif 
