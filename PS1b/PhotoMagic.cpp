/************************************************************
 *Name: <John Hua>
 *Course name: <COMP.2040>
 *Assignment: <PS1b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2.7.2022>
 *Sources Of Help: <Dr Daly's Discord Server>
************************************************************/

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "FibLFSR.h"

// transform function
void transform(sf::Image& image, FibLFSR*);

int main(int argc, char* argv[])
{
	sf::Image image;
	if (!image.loadFromFile(argv[1]))
		return -1;

	FibLFSR fiblfsr(argv[3]);

	sf::Vector2u size = image.getSize();

	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted");

	// Load original image to window1
	sf::Texture texture;
	texture.loadFromImage(image);

	sf::Sprite sprite;
	sprite.setTexture(texture);

	// Encode image
	transform(image, &fiblfsr);	

	// Load encoded image to window2 from new sprite to avoid copying
	sf::Texture texture_2;
	texture_2.loadFromImage(image);

	sf::Sprite sprite_2;
	sprite_2.setTexture(texture_2);

	while (window1.isOpen() || window2.isOpen())
	{
		sf::Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}

		while (window2.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window2.close();
		}

		window1.clear(sf::Color::Black);
		window1.draw(sprite);
		window1.display();
		
		window2.clear(sf::Color::Black);
		window2.draw(sprite_2);
		window2.display();
	}

	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!image.saveToFile(argv[2]))
		return -1;

	return 0;
}

void transform(sf::Image& image, FibLFSR* fiblfsr) {

	// p is a pixelimage.getPixel(x, y);
	sf::Color p;

	for (unsigned int x = 0; x < image.getSize().x;  x++) {
		for (unsigned int y = 0; y < image.getSize().y; y++) {
			p = image.getPixel(x, y);
			p.r = p.r ^ fiblfsr->generate(10);
			p.g = p.g ^ fiblfsr->generate(8);
			p.b = p.b ^ fiblfsr->generate(13);
			image.setPixel(x, y, p);
		}
	}
}