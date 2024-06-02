#ifndef STRUCT_H 
#define STRUCT_H

typedef struct {
	float x, y; 
	float w, h; 
} Platform;

typedef struct {	
	float vectorX, vectorY; 
	float width, height; 
	float speed;
	float jumpactive;  
} Player;

#endif 
