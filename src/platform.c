#include "platform.h"
#include <stdio.h>

void pos_platform(Platform platform[], int numPlatform) {
	float origin = 200; 
	float diff_x = 50;
	for (int i = 0; i < numPlatform; i++) 
	{
		platform[i].x = origin + diff_x;
		platform[i].y = origin;
		origin += 200; 
		diff_x += 50;
		printf("%f\n", platform[i].x); 	
		printf("%f\n", platform[i].y); 
	}
}

Platform* create_platform(int numPlatform) 
{
	Platform* platform = (Platform*)malloc(sizeof(Platform) * numPlatform); 
	if (platform != NULL)
	{ 				
		return platform; 
	}
	else {
		free(platform); 
		exit(1); 
	}
}

void distroy_platform(Platform* platform)
{
	if (platform != NULL)	
	{	
		free(platform); 
	}
	else 
	{
		printf("Memory still being allocated"); 
	}
}

