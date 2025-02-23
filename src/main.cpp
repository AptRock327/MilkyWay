#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <global.hpp>
#include <renderer.hpp>
#include <physics.hpp>

void handleInput(sf::Vector3f* camera, sf::Vector2f* theta, sf::RenderWindow* window)
{	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			camera->x+=0.02;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			camera->x-=0.02;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			camera->z-=0.01;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			camera->z+=0.01;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			camera->y-=0.01;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			camera->y+=0.01;
		}
		theta->x = -(float)sf::Mouse::getPosition(*window).x/100;
		theta->y = (float)sf::Mouse::getPosition(*window).y/100;
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Milky Way");

	std::vector<std::vector<float>> verts1;
	std::vector<std::vector<int>> faces1;

	if(argc > 1) loadModel(argv[1], &verts1, &faces1);
	else
	{
		printf("Syntax: milkyWay [waveform obj file]\n");
		return -1;
	}

	std::cout << "test" << std::endl;

	sf::Vector3f camera;
	camera.x = 0.0f;
	camera.y = 0.0f;
	camera.z = 1.3f;

	sf::Vector2f theta;
	theta.x = 0.0f;
	theta.y = 0.0f;

	RigidBody body(6.0f, 6.0f, -9.81f, 0.001f, 0, 0, 6.0f, false, 0, 0, 0, true, 0, true);

	sf::Time elapsedTime;
	sf::Clock r;

	bool started = false;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed) window.close();
		}

	  	sf::Time deltaTime = sf::milliseconds(2);
		elapsedTime += r.restart();
		
  		while( elapsedTime >= deltaTime )
		{	
			recalculate(&body);
        		elapsedTime -= deltaTime;
    		}

		handleInput(&camera, &theta, &window);
		window.clear();
		renderModel(verts1, faces1, &window, sf::Color(255, 255, 255), camera+sf::Vector3f(*body.xOffset, *body.x, 3),
				sf::Vector2f(theta.x, theta.y));
		//window.draw(triangle);
		window.display();
	}

	return 0;
}
