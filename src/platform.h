#include <stdlib.h>

typedef struct {
	float x, y; 
	float w, h; 
} Platform;

Platform* create_platform(float x, float y, float w, float h); 
