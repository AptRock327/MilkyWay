#include <renderer.hpp>

void renderModel(std::vector<std::vector<float>> verts, std::vector<std::vector<int>> faces,
				sf::RenderWindow* window, sf::Color color, sf::Vector3f camera, sf::Vector2f theta)
{
	for(int i = 0; i < (int)faces.size(); i++)
	{
		std::vector<int> face = faces.at(i);

		sf::ConvexShape triangle;
		triangle.setPointCount(3);

		std::vector<sf::Vector3f> trianglePoints;

		for(int j = 0; j < 3; j++)
		{
			std::vector<float> v0 = verts.at(face.at(j));
			std::vector<float> v1 = verts.at(face.at( (j+1)%3 ));

			float x0prime = v0.at(0);
			float y0prime = v0.at(1);
			float z0prime = v0.at(2);
			float x1prime = v1.at(0);
			float y1prime = v1.at(1);
			float z1prime = v1.at(2);

			rotate(&x0prime, &z0prime, theta.x);
			rotate(&x1prime, &z1prime, theta.x);
			rotate(&y0prime, &z0prime, theta.y);
			rotate(&y1prime, &z1prime, theta.y);
	
			int x0 = ((x0prime+camera.x)/(-z0prime+camera.z)+1.0) * WIDTH/2.0;
			int y0 = ((y0prime+camera.y)/(-z0prime+camera.z)+1.0) * HEIGHT/2.0;
			int x1 = ((x1prime+camera.x)/(-z1prime+camera.z)+1.0) * WIDTH/2.0;
			int y1 = ((y1prime+camera.y)/(-z1prime+camera.z)+1.0) * HEIGHT/2.0;
	
			triangle.setPoint(j, sf::Vector2f(x0, HEIGHT-y0));
			triangle.setPoint((j+1)%3, sf::Vector2f(x1, HEIGHT-y1));

			trianglePoints.push_back(sf::Vector3f(0, 0, 0));
			trianglePoints.at(j).x = v0.at(0);
			trianglePoints.at(j).y = v0.at(1);
			trianglePoints.at(j).z = v0.at(2);
		}

		sf::Vector3f U = trianglePoints.at(1) - trianglePoints.at(0);
		sf::Vector3f V = trianglePoints.at(2) - trianglePoints.at(0);

		sf::Vector3f normal = cross(U, V);

		Normalize(&normal);

		//Directional light with vector (1, 1, 0)
		sf::Vector3f light;
		light.x = 1; light.y = 1; light.z = 0;

		Normalize(&light);

		float luminosity = dot(light, normal);

		//Bound luminosity
		if(luminosity < 0.2) luminosity = 0.2; if(luminosity > 1) luminosity = 1;

		triangle.setFillColor(sf::Color(color.r * luminosity, color.g * luminosity, color.b * luminosity));
		window->draw(triangle);
	}
}
