#include "platform.h" 
Platform* create_platform(float x, float y, float w, float h)
{
	Platform* platform = (Platform*)malloc(sizeof(Platform)); 
	if (platform != NULL)
	{ 
		platform->x = x; 
		platform->y = y; 
		platform->w = w; 
		platform->h = h; 
	}
	else {
		free(platform); 
		exit(1); 
	}
	return platform; 
}

void distroy_platform(Platform* platform)
{
	free(platform); 
}
