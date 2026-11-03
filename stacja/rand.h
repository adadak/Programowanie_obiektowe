#include <stdlib.h>

float getRandomNumber(float lowLimit, float highLimit)
{
	return ((float)rand()/RAND_MAX * (highLimit-lowLimit)) + lowLimit;
}
