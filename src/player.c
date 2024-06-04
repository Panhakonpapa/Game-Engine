#include "/home/panha/game/Game-FS/include/player.h"

Player* create_player(float x, float y, float w, float h, float speed) {
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

void jump(Player* player)
{
	player->p_jactive = 1; 	
	if (player->p_jactive == 1)
	{
		player->p_y -= sqrt(2.f * 300.f * 9.8); 
	}

	if (player->p_y + player->p_h >= 600)
	{
		player->p_y = 0; 
	}
}

void handle_movement(Player* player, int dirx, int diry)
{
	player->p_x += dirx * player->p_speed; 
	player->p_y += diry * player->p_speed;
}

void is_player_on_ground(Player* player, float gravity) 
{
	player->p_y += gravity; 	
	if (player->p_y + player->p_y >= 600)
	{
		player->p_y -= gravity; 
		player->p_jactive = 0; 	
	}
}

