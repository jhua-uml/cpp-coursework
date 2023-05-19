/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps2a>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <2.12.2022>*/
/*Sources Of Help: <Daly's Comp4 Discord Server / Boost Documentation>*/
/************************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "CelestialBody.h"
#include "Universe.h"

int main () {

	/*Read in the first two lines of planets.txt (the number of celestial bodies then the universe radius*/
	int num_body;
	std::cin >> num_body;
	std::cout << num_body << std::endl; // Testing if it read correctly

	double universe_radius;
	std::cin >> universe_radius;
	std::cout << universe_radius<< std::endl;

	/*Instantiate the Universe*/
	Universe solar_system(universe_radius);
	
	/*Create RenderWindow*/
	sf::RenderWindow window(sf::VideoMode(500, 500), "Solar System");
	sf::Vector2u window_size = window.getSize(); // Store render window x,y coordinates

	/*Manually create CelestialBody objects*/
    //CelestialBody sun(0, 0, 0, 0, 0, "sun.gif");
    //CelestialBody earth(1.4960e+11, 0, 0, 0, 0, "earth.gif");
	//CelestialBody mars(2.2790e+11, 0, 0, 0, 0, "mars.gif");
	//CelestialBody mercury(5.7900e+10, 0, 0, 0, 0, "mercury.gif");

	/*Have the Universe class instantiate new CelestialBody objects*/
	//solar_system.body.push_back (new CelestialBody(2.2790e+11, 0, 0, 0, 0, "mars.gif"));
	//solar_system.body.push_back (new CelestialBody(5.7900e+10, 0, 0, 0, 0, "mercury.gif"));
	//solar_system.body.push_back (new CelestialBody(0.0000e+00, 0, 0, 0, 0, "sun.gif"));
	//solar_system.body.push_back (new CelestialBody(1.0820e+11, 0, 0, 0, 0, "venus.gif"));


	/*For loop to instantiate new celestial bodies, initialize the parameters from the overloaded
	input stream operator, then load the image, texture, and sprite*/
	for(int i = 0; i < num_body; i++) {
		solar_system.body.push_back (new CelestialBody);
		std::cin >> solar_system.body[i];
		solar_system.body[i]->loadSprite();
	}

    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		/*Draw the sprites and position them onto the viewport. Can maybe clean
		this up later with a for-loop.*/
		
		window.draw(*solar_system.body[0]);
		window.draw(*solar_system.body[1]);
		window.draw(*solar_system.body[2]);
		window.draw(*solar_system.body[3]);
		window.draw(*solar_system.body[4]);

		solar_system.body[0]->renderToWindow(window_size, universe_radius);
		solar_system.body[1]->renderToWindow(window_size, universe_radius);
		solar_system.body[2]->renderToWindow(window_size, universe_radius);
		solar_system.body[3]->renderToWindow(window_size, universe_radius);
		solar_system.body[4]->renderToWindow(window_size, universe_radius);
		//solar_system.renderToWindow(solar_system.body[0]); (NOT USED)
		window.display();

	}
	return 0;
}