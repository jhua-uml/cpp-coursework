/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps3>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <2.28.2022>*/
/*Sources Of Help: <StackOverflow>*/
/*Copyright 2022 <John Hua>
/************************************************************/
#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Triangle.h"

Triangle::Triangle() {}


void Triangle::drawfTree(sf::RenderTarget& target,
                         int depth,
                         sf::CircleShape& base) {
            if (depth < 1) return;

            if (depth % 2 == 0) {
                base.setFillColor(sf::Color::Blue);
            } else {
                base.setFillColor(sf::Color::Red);
            }
            target.draw(base);

            auto rad = base.getRadius();
            sf::FloatRect tBounds = base.getGlobalBounds();

            auto leftT = base;
            leftT.setRadius(rad/2);
            leftT.setOrigin(leftT.getGlobalBounds().width/2,
                            leftT.getGlobalBounds().width/2);
            leftT.move(tBounds.width/2, tBounds.height*.75);
            drawfTree(target, depth-1, leftT);

            auto rightT = base;
            rightT.setRadius(rad/2);
            rightT.setOrigin(rightT.getGlobalBounds().width/2,
                             rightT.getGlobalBounds().width/2);
            rightT.move(-(tBounds.width*.75), (tBounds.height*.25));
            drawfTree(target, depth-1, rightT);


            auto bottomT = base;
            bottomT.setRadius(rad/2);
            bottomT.setOrigin(bottomT.getGlobalBounds().width/2,
                              bottomT.getGlobalBounds().width/2);
            bottomT.move(tBounds.width*.25, -(tBounds.height*.75));
            drawfTree(target, depth-1, bottomT);
}
