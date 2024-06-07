#include "/home/panha/game/Game-FS/include/physic.h"


#define GRAVITY 10

void handle_movement(Player* player, int dirx, int diry)
{
	if (dirx == 1) 
	{			
		player->p_x += dirx * player->p_speed; 
	}
	if (diry == 1) 
	{
		player->p_y += diry * player->p_speed;

	}
}
void apply_gravity(Player* player) 
{
	player->p_y += GRAVITY; 	
	if (player->p_y + player->p_y >= 600)
	{
		player->p_y -= GRAVITY; 
		player->p_jactive = 0; 	
	}
}

bool collision(Player* player, Player* dest) 
{
	return (player->p_x < dest->p_x + dest->p_w &&
		player->p_y + player->p_w > dest->p_x &&
		player->p_y < dest->p_y + dest->p_h &&
		player->p_y + player->p_h > dest->p_y); 
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
