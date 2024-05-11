#include "physic.h"
#include <math.h>
#define HEIGHT 600
#define WIDTH 800
#define JUMP_HEIGHT 100


//* 		Passed 			*//
void jumpTest(Objcet* objcet) {
	objcet->jumpactive = 1;
	if (objcet->jumpactive == 1)	
	{
		printf("[Test if jump is Active]\n"); 	
		printf("Passed\n");
		printf("Active: %d \n", objcet->jumpactive); 	
		int results;
		objcet->vectorY -= sqrt(2 * JUMP_HEIGHT * 10);   
		results = objcet->vectorY;
		printf("Vector: %d \n", results);		
		if (objcet->vectorY < 300) {
			printf("Passed\n");
			printf("Vector->Jump: %d \n", objcet->vectorY);  
		} else {
			printf("Failure\n"); 
		} 
		
	}

	if (objcet->vectorY + objcet->height >= HEIGHT || objcet->vectorY < 0)
	{
		printf("[Test for objcet on the ground]\n"); 	
		printf("Passed\n"); 
		objcet->jumpactive = 0;	
		printf("Active: %d\n", objcet->jumpactive); 	
	}	
}
//* 		Passed 			*//
bool objcet2Dcolite(Objcet* objcet1, Objcet* objcet2)
{
	return (objcet1->vectorX < objcet2->vectorX + objcet2->width &&
		objcet1->vectorX + objcet1->width > objcet2->vectorX &&
		objcet1->vectorY < objcet2->vectorY + objcet2->height &&
		objcet1->vectorY + objcet1->height > objcet2->vectorY); 
} 


int main() {
	Objcet objcet;
	Objcet player;
		
	printf("%b", objcet2Dcolite(&objcet, &player)); 
	
	return 0; 
}
