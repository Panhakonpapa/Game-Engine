#include "/home/panha/game/Game-FS/include/player.h"

Player* create_player(int x, int y, int w, int h, int speed) {
	Player* player = (Player *)malloc(sizeof(Player)); 	
	if (player != NULL) 
	{	
		player->p_x = x; 	
		player->p_y = y;
		player->p_w = w; 
		player->p_h = h;
		player->p_jactive = 0;
		player->p_speed = speed;
	}
	else 
	{
		free(player); 	
		exit(1);  
	}
	return player; 
 }

void distory_player(Player* player)
{
	free(player); 
}
