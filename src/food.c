#include "/home/panha/Bug-fix/Game-FS/Header/food.h"
#include <stdbool.h>
void init_coins(Dimon* dimon, int x, int y, int w, int h) {
	dimon->x = x; 
	dimon->y = y; 
	dimon->w = w; 
	dimon->h = h; 
}

bool detect_Dimon(Dimon* dimon, Player* player) {
	return (dimon->x < player->vectorX + player->width &&
		dimon->x + dimon->w > player->vectorX && 
		dimon->y < player->vectorY + player->height &&
		dimon->y + dimon->h > player->vectorY); 
}
