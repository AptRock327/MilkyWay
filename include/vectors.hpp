#ifndef __VECTORS_HPP
#define __VECTORS_HPP

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

/** Normalizes a vector (makes its length equal to 1 while keeping relative proportionality).
 * @vector - pointer to SFML vector to normalize
 * Returns: none
 */
void Normalize(sf::Vector3f* vector);

/** Rotates a vector [x, y] by an angle theta.
 * @x - pointer to x value of vector to be rotated
 * @y - pointer to y value of vector to be rotated
 * @theta - angle for the vector to be rotated by
 * Returns: none
 */
void rotate(float* x, float* y, float theta);

/** Calculates the dot product of two vectors.
 * @a - SFML vector being the multiplicand of the dot product
 * @b - SFML vector being the multiplier of the dot product
 * Returns: the value of the dot product
 */
float dot(sf::Vector3f a, sf::Vector3f b);

/** Calculates the cross product of two vectors.
 * @a - SFML vector being the multiplicand of the cross product
 * @b - SFML vector being the multiplier of the cross product
 * Returns: result of the cross product
 */
sf::Vector3f cross(sf::Vector3f a, sf::Vector3f b);

#endif
