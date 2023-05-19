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

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
    		target.draw(sprite);
		}
		double win_size;
		
		double radius;
		sf::Sprite sprite;
		sf::Texture texture;
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

/*Passing a pointer to the object (NOT USED)*/

/*void Universe::renderToWindow(CelestialBody *&body)
{

	body->sprite.setPosition(200, 200);

}
*/

#endif