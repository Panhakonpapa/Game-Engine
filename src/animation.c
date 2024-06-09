#include <stdlib.h>
#include "/home/panha/game/Game-FS/include/animation.h" 

void print_debug(Animation* anime, int loop)
{
	printf("loop: %d, anmiaton: x %d\n", loop, anime->x_frame); 
}

SDL_Rect draw_animtaion(int x, int y, int w, int h)
{
	SDL_Rect dest_src = {x, y, w, h};
	return dest_src; 
}

Animation* init_indle_animation() 
{	
		Animation* animation = (Animation*)malloc(sizeof(Animation));  	
		if (animation != NULL)
		{			
			animation->x_frame = 0; 
			animation->y_frame = 0; 
			animation->w_frame = 50; 
			animation->h_frame = 48; 
			animation->n_frame = 6; 			
		}
		return animation; 
}

Animation* init_run_animation() 
{	
		Animation* animation = (Animation*)malloc(sizeof(Animation));  	
		if (animation != NULL)
		{			
			animation->x_frame = 0; 
			animation->y_frame = 0; 
			animation->w_frame = 50; 
			animation->h_frame = 48; 
			animation->n_frame = 8; 			
		}
		return animation; 
}

void free_anmiation(Animation* src_animation) 
{
	if (src_animation != NULL) {
		free(src_animation); 
	}
}

SDL_Rect src_sprite(Animation* animation, int loop)
{	
	SDL_Rect src = {animation->x_frame, animation->y_frame + loop * animation->h_frame, animation->w_frame, animation->h_frame}; 
	return src; 
}

void play_animation(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest) {
	if (renderer && texture != NULL) 
	{			
		SDL_RenderCopy(renderer, texture, src, dest);
	}	
}


