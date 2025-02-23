#include <vectors.hpp>

void rotate(float* x, float* y, float theta)
{
	*x = *x * cos(theta) - *y * sin(theta);
	*y = *x * sin(theta) + *y * cos(theta);
}

sf::Vector3f cross(sf::Vector3f a, sf::Vector3f b)
{
	sf::Vector3f result;

	result.x = a.y * b.z - a.z - b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;

	return result;
}

float dot(sf::Vector3f a, sf::Vector3f b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
