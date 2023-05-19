/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps3>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <2.28.2022>*/
/*Sources Of Help: <StackOverflow>*/
/*Copyright 2022 <John Hua>
/************************************************************/

#include <iostream>
#include <math.h>

#include "Triangle.h"

void fTree(sf::RenderTarget &target, double radius, int depth, Triangle &frac);

int main(int argc, char* argv[]) {
double length = std::stod(argv[1]);
int depth = std::stoi(argv[2]);

sf::RenderWindow window(sf::VideoMode(750, 750), "Sierpenski's Triangle");
// Store render window x,y coordinates
sf::Vector2u window_size = window.getSize();

Triangle fractal;

while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        window.close();
    }
    fTree(window, length, depth, fractal);
    window.display();
    window.clear(sf::Color::White);
}
    return 0;
}

void fTree(sf::RenderTarget &target, double radius, int depth, Triangle &frac) {
    sf::CircleShape circle(radius, 3);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(1);

    sf::FloatRect circ_bounds = circle.getGlobalBounds();
    circle.setOrigin(circ_bounds.width/2, circ_bounds.height/2);
    circle.setPosition(target.getSize().x / 2.f, target.getSize().y / 2.f);

    frac.drawfTree(target, depth, circle);
}
