#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "CelestialBody.h"

CelestialBody::CelestialBody() { }

CelestialBody::CelestialBody(double xp, double yp, double xv, double yv, double m, std::string img)
{

    xpos = xp;
    ypos = yp;
    xvel = xv;
    yvel = yv;
    mass = m;
    filename = img;

}

void CelestialBody::renderToWindow(const sf::Vector2u& window_size, double universe_radius) {

    /*Translate viewport to Cartesian coordinate system*/
    double xNew = (((universe_radius*2)/2) + xpos) * (window_size.x/(universe_radius*2));
    double yNew = (((universe_radius*2)/2) - ypos) * (window_size.y/(universe_radius*2));
    
    /*Gets bounding box of sprite and sets origin to center by dividing width/height by 2*/
    sf::FloatRect sprite_dimensions = sprite.getGlobalBounds();
    sprite.setOrigin(sprite_dimensions.width/2, sprite_dimensions.height/2);

    sprite.setPosition(xNew, yNew);

}

void CelestialBody::loadSprite() {

    sf::Image image;

	if (!image.loadFromFile(filename))
        std::cout << "Cannot load image file." << std::endl;

    texture.loadFromImage(image); 

	sprite.setTexture(texture);
    
}

/*Mutator Functions*/
void CelestialBody::setXpos(double x) {

    xpos = x;

}

double CelestialBody::getXpos() {

    return xpos;

}

void CelestialBody::setYpos(double y) {

    ypos = y;

}

double CelestialBody::getYpos() {

    return ypos;

}

void CelestialBody::setXvel(double xv) {

    xvel = xv;

}

double CelestialBody::getXvel() {

    return xvel;

}


void CelestialBody::setYvel(double yv) {

    yvel = yv;

}

double CelestialBody::getYvel() {

    return yvel;

}


void CelestialBody::setMass(double m) {

    mass = m;

}

double CelestialBody::getMass() {

    return mass;

}

void CelestialBody::setFx(double fx) {
    Fx = fx;
}

double CelestialBody::getFx() {
    return Fx;
}

void CelestialBody::setFy(double fy) {
    Fy = fy;
}

double CelestialBody::getFy() {
    return Fy;
}

void CelestialBody::setFileName(std::string file) {

    filename = file;

}

std::string CelestialBody::getFileName() {
    return filename;
}
