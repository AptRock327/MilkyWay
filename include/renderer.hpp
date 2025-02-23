#ifndef __RENDERER_HPP
#define __RENDERER_HPP

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <global.hpp>
#include <vectors.hpp>

/** Loads a model from a wavefront obj file into a vector of vertices and faces.
 * @verts - pointer to matrix of vertices to be filled with object data
 * @faces - pointer to matrix of faces to be filled with object data
 * Returns: none
 */
void loadModel(const char* filename, std::vector<std::vector<float>>* verts, std::vector<std::vector<int>>* faces);

/** Renderes a model on an SFML window using matrices of vertices and faces.
 * @verts - matrix of object vertices
 * @faces - matrix of object faces
 * @window - pointer to an SFML RenderWindow object
 * @color - SFML color that the object will be drawn in
 * @camera - SFML vector corresponding to camera x, y, z positions
 * @theta - SFML vector containing thetaX and thetaY, which correspond to horizontal and vertical camera rotation
 * Returns: None
 */
void renderModel(std::vector<std::vector<float>> verts, std::vector<std::vector<int>> faces,
				sf::RenderWindow* window, sf::Color color, sf::Vector3f camera, sf::Vector2f theta);

#endif
