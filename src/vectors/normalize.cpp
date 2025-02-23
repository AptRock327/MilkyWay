#include <vectors.hpp>

// Calculates 1/sqrt(x). Fast.
float fastInvSqrt(float x)
{
	int i = *(int*)&x;
	i = 0x5F3759DF - (i >> 1);
	float y = *(float*)&i;

	return y * (1.5f - ( x * 0.5f * y * y ));
}

void Normalize(sf::Vector3f* vector)
{
	float multiplier = fastInvSqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
	vector->x *= multiplier;
	vector->y *= multiplier;
	vector->y *= multiplier;
}
