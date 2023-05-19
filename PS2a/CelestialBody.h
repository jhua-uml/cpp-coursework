#ifndef CelestialBody_H
#define CelestialBody_H
#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CelestialBody : public sf::Drawable
{
	public:
		/*Constructors*/
		CelestialBody();
		CelestialBody(double xp, double yp, double xv, double yv, double m, std::string img);

		/*Mutator Functions*/
		void setXpos(double x);
		void setYpos(double y);
		void setXvel(double xv);
		void setYvel(double yv);
		void setMass(double m);
		void setFileName(std::string file);

		/*Load the image file and set the texture and sprite*/
		void loadSprite();

		/*Translate viewport to Cartesian coordinates and set sprite's origin (0,0) to be centered*/
		void renderToWindow(const sf::Vector2u& window_size, double universe_radius);

	private:
		/*Private virtual void draw function*/
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
    		target.draw(sprite);
		}

		/*Private member variables*/
		double xpos;
		double ypos;
		double xvel;
		double yvel;
		double mass;
		std::string filename;
		
		/*Sprite and texture member variables*/
		sf::Sprite sprite;
		sf::Texture texture;
};

#endif