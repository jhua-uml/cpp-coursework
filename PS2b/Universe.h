#ifndef Universe_H
#define Universe_H
#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;


class Universe : public sf::Drawable
{
	public:
		/*Constructor(s)*/
		Universe(double rad);

		/*Vector of pointers to objects (CelestialBody)*/
		std::vector<CelestialBody*> body;

		/*Overloaded input stream operator*/
		friend istream& operator>>(std::istream& input, CelestialBody *&body);

		/*Step function to simulate physics of CelestialBodies*/
		void step(double simulationTime, CelestialBody *&body);


	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
    		target.draw(sprite);
		}
		double win_size;
		
		double radius;
		sf::Sprite sprite;
		sf::Texture texture;

		const double grav_constant = 6.67e-11;
};


Universe::Universe(double rad) {
	radius = rad;
}

/*Overloaded istream operator to take inputs. Passes the pointer(*) to object by reference(&) to avoid copying*/
istream& operator>>(istream& input, CelestialBody *&body) {

	double _xpos;
	double _ypos;
	double _xvel;
	double _yvel;
	double _mass;
	std::string _filename;

	input >> _xpos >> _ypos >> _xvel >> _yvel >> _mass >> _filename;

	body->setXpos(_xpos);
	body->setYpos(_ypos);
	body->setXvel(_xvel);
	body->setYvel(_yvel);
	body->setMass(_mass);
	body->setFileName(_filename);

	return input;
}

void Universe::step(double dT, CelestialBody *&body) {

	// a = F/m
	double xA = body->getFx()/body->getMass();
	double yA = body->getFy()/body->getMass();

	// v = v0 + dT*a
	body->setXvel(body->getXvel() + dT*xA);
	body->setYvel(body->getYvel() + dT*yA);

	// s = s0 + dT*v
	body->setXpos(body->getXpos() + dT*body->getXvel());
	body->setYpos(body->getYpos() + dT*body->getYvel());
}


/*Passing a pointer to the object (NOT USED)*/

/*void Universe::renderToWindow(CelestialBody *&body)
{

	body->sprite.setPosition(200, 200);

}
*/

#endif