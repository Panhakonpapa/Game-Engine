#include "player.h"

 Player* create_player(float x, float y, float w, float h, float speed) {
	Player* player = (Player *)malloc(sizeof(Player)); 	
	if (player != NULL) 
	{	
		player->vectorX = x; 	
		player->vectorY = y;
		player->width = w; 
		player->height = h;
		player->jumpactive = 0;
		player->speed = speed;
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
	player->jumpactive = 1; 	
	if (player->jumpactive == 1)
	{
		player->vectorY -= sqrt(2.f * 300.f * 9.8); 
	}

	if (player->vectorY + player->height >= 600)
	{
		player->jumpactive = 0; 
	}
}

void handle_movement(Player* player, int dirx, int diry)
{
	player->vectorX += dirx * player->speed; 
	player->vectorY += diry * player->speed;
}

void is_player_on_ground(Player* player, float gravity) 
{
	player->vectorY += gravity; 	
	if (player->vectorY + player->height >= 600)
	{
		player->vectorY -= gravity; 
		player->jumpactive = 0; 	
	}
}

