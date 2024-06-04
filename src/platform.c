#include "/home/panha/game/Game-FS/include/platform.h"
#include <stdio.h>

void pos_platform(Platform platform[], int numPlatform) {
	float origin = 200; 
	float diff_x = 50;
	for (int i = 0; i < numPlatform; i++) 
	{
		platform[i].plat_x = origin + diff_x;
		platform[i].plat_y = origin;
		if (platform[i].plat_x && platform[i].plat_y > 800)	
		{
			diff_x = -50; 	
		}
		if (platform[i].plat_x && platform[i].plat_y < 0) 
		{
			diff_x = 50; 
		}
		printf("%f\n", platform[i].plat_x); 	
		printf("%f\n", platform[i].plat_y); 
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
		if (platform == NULL) {	
			free(platform); 
			printf("Error Memory won't able to alllcated so it drop fucntion <create_platform>\n");  	
		}
			
		exit(1); 
	}
}

void distroy_platform(Platform* platform)
{
	if (platform == NULL)	
	{	
		free(platform); 
	}
	else 
	{
		printf("Memory still being allocated"); 
	}
}

