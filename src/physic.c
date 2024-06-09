#include "/home/panha/game/Game-FS/include/physic.h"



void handle_movement(Player* player, int dirx, int diry)
{
			
	player->p_x += dirx * player->p_speed; 	
	player->p_y += diry * player->p_speed;
}

void apply_gravity(Player* player, int gravity)  
{
	player->p_y += gravity; 
	player->p_x += gravity; 	
	if (player->p_y - 25 > 470)
	{
		player->p_y -= gravity; 
		player->p_x -= gravity; 
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
	player->p_x += 10; 
	player->p_y -= 100; 
}


