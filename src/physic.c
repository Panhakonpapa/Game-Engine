#ifndef PHYSIC 
#define PHYSIC 
#include "Header/physic.h"

#define WIDTH 800
#define HEIGHT 600
#define VELOCITY_JUMP 100 
#define VELOCITY_EARTH 10  
#define SPEEDS 10


void jump(Objcet* objcet) {
	objcet->jumpactive = 1;

	if (objcet->jumpactive == 1)	
	{
		objcet->vectorY -= sqrt(2 * VELOCITY_JUMP * VELOCITY_EARTH); 
	}
	if (objcet->vectorY + objcet->height >= HEIGHT || objcet->vectorY < 0)
	{
		objcet->jumpactive = 0;	
	}	
}

void movement(Objcet* object, int drx, int dry, int speed) {
	object->vectorX += drx * speed;	
	object->vectorY += dry * speed;
} 

bool objcet2Dcolite(Objcet* objcet1, Objcet* objcet2)
{
	return (objcet1->vectorX < objcet2->vectorX + objcet2->width &&
		objcet1->vectorX + objcet1->width > objcet2->vectorX &&
		objcet1->vectorY < objcet2->vectorY + objcet2->height &&
		objcet1->vectorY + objcet1->height > objcet2->vectorY); 
} 
void checkwinbound(Objcet* objcet, int width, int height) {
	if (objcet->vectorX + objcet->width > width) {
	
		objcet->vectorX = width; 
	}
	if (objcet->vectorY + objcet->height > height)
	{
		objcet->vectorY = height; 
	}
	if (objcet->vectorX  < 0)
	{
		objcet->vectorX = 0;  
	}	
	if (objcet->vectorY  < 0)
	{
		objcet->vectorY = 0;  
	}
}

#endif 
