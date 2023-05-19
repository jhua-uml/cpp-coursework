/*
 * Created by: John Hua
 * Computing IV, Instructor: Professor Daly
 * Assignment: ps0, due: 1/24/2022
 * 
 * 
 * Comments: This program is an introductory to using the SFML libraries. It implements
 * detecting keypresses to change the position of the sprite as well using the getSize()
 * function to detect when the sprite's position is out bounds of the window region.
 *
 * 
 * 
 */
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>



int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 300), "Pig Sprite");
    sf::Texture pig;
    if (!pig.loadFromFile("sprite.png")) {
        cout << "Unable to load piggie sprite." << endl;
        return 0;
    }
    sf::Texture octo;
    if (!octo.loadFromFile("octo.png")) {
        cout << "Unable to load octo sprite." << endl;
        return 0;
    }

    sf::Sprite piggieSprite;
    piggieSprite.setTexture(pig);
    piggieSprite.setScale(0.2, 0.2);

    sf::Sprite octoSprite;
    octoSprite.setTexture(octo);
    octoSprite.setScale(0.2, 0.2);

    while (window.isOpen())
    {

        sf::Vector2f pos =  piggieSprite.getPosition();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            piggieSprite.move(1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            piggieSprite.move(-1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            piggieSprite.move(0, -1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            piggieSprite.move(0, 1);
        }

        window.clear();
        if ((pos.x < 0 || pos.x > window.getSize().x) ||
           (pos.y < 0 || pos.y > window.getSize().y)) {
            window.draw(octoSprite);
        } else {
            window.draw(piggieSprite);
        }  
        window.display();
    }

    return 0;
}