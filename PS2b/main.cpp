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
#include <math.h>

#include "CelestialBody.h"
#include "Universe.h"

int main (int argc, char* argv[]) {

	/*Read in the first two lines of planets.txt (the number of celestial bodies then the universe radius*/
	int num_body;
	std::cin >> num_body;
	std::cout << num_body << std::endl; // Testing if it read correctly

	double universe_radius;
	std::cin >> universe_radius;
	std::cout << universe_radius<< std::endl;

	/*Time variables*/
	double elapsedTime = 0.0;
	double simulationTime = atof(argv[2]);
	double endTime = atof(argv[1]);
	//double simulationTime = 25000.0;
	//double endTime = 157788000.0;

	/*General force variables*/
	double radius;
	double force;
	const double G = 6.67e-11;

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
	//solar_system.body.push_back (new CelestialBody(1.4960e+11, 0, 0, 2.9800e+04, 5.9740e+24, "earth.gif"));
	//solar_system.body.push_back (new CelestialBody(0.0000e+00, 0, 0, 0, 0, "sun.gif"));
	//solar_system.body.push_back (new CelestialBody(1.0820e+11, 0, 0, 0, 0, "venus.gif"));


	/*For loop to instantiate new celestial bodies, initialize the parameters from the overloaded
	input stream operator, then load the image, texture, and sprite*/


	for(int i = 0; i < num_body; i++) {
		solar_system.body.push_back (new CelestialBody);
		std::cin >> solar_system.body[i];
		solar_system.body[i]->loadSprite();
	}

	window.setFramerateLimit(60.0);
	
    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (elapsedTime <= endTime) {

			/*Calculate the net forces using nested loop. This will calculate
			the force body 'j' will exert on body 'i' except when i=j. Forces
			have to be calculated before calculating the new velocities and
			positions.*/
			for (int i = 0; i < num_body; i++) {
				solar_system.body[i]->setFx(0.0);
				solar_system.body[i]->setFy(0.0);
				for (int j = 0; j < num_body; j++) {
					if (i != j) {
						
						radius = sqrt(pow((solar_system.body[j]->getXpos() - solar_system.body[i]->getXpos()), 2)
									+ pow((solar_system.body[j]->getYpos() - solar_system.body[i]->getYpos()), 2));

						force = (G * solar_system.body[i]->getMass() * solar_system.body[j]->getMass())/pow(radius, 2);

						solar_system.body[i]->setFx(solar_system.body[i]->getFx() + force * ((solar_system.body[j]->getXpos() - solar_system.body[i]->getXpos())/radius));
						solar_system.body[i]->setFy(solar_system.body[i]->getFy() + force * ((solar_system.body[j]->getYpos() - solar_system.body[i]->getYpos())/radius));

					}
				}
			}
		
			/*Loop to calculate new velocity and position with the universe's step function*/
			for(int i = 0; i < num_body; i++) {
				solar_system.step(simulationTime, solar_system.body[i]);
			}

			elapsedTime += simulationTime;

		}

		/*Loop to plot the bodies after calculating the new position*/
		for(int i = 0; i < num_body; i++) {
			window.draw(*solar_system.body[i]);
			solar_system.body[i]->renderToWindow(window_size, universe_radius);
		}
		std::cout << elapsedTime << endl;
		window.display();
		window.clear(sf::Color::Black);

	}

	fstream log;
	log.open("planets.txt", fstream::app);
	log << endl << "Simulation after " << endTime/simulationTime << " steps." << endl;
	log << num_body << endl;
	log << universe_radius << endl;
	
	for(int i = 0; i < num_body; i++) {
		log <<   solar_system.body[i]->getXpos() << "	" 
			<<   solar_system.body[i]->getYpos() << "	"
			<<   solar_system.body[i]->getXvel() << "	"
			<<   solar_system.body[i]->getYvel() << "	"
			<<   solar_system.body[i]->getMass() << "	"
			<<   solar_system.body[i]->getFileName() << endl;
			   
	}

	log.close();

	return 0;
}