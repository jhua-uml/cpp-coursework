/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps3>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <2.28.2022>*/
/*Sources Of Help: <StackOverflow>*/
/*Copyright 2022 <John Hua>
/************************************************************/
#ifndef _HOME_JHUA_COMPUTING_IV_PS3_TRIANGLE_H_
#define _HOME_JHUA_COMPUTING_IV_PS3_TRIANGLE_H_
#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Triangle :  public sf::Drawable {
 public:
        Triangle();

        void drawfTree(sf::RenderTarget& target, int depth,
                       sf::CircleShape& base);


 private:
        /*Private virtual void draw function*/
        virtual void draw(sf::RenderTarget& target,
                          sf::RenderStates states) const {}

        double length;
        int depth;
};

#endif  // _HOME_JHUA_COMPUTING_IV_PS3_TRIANGLE_H_
