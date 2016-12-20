#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>

class Ship {
public:

	int HP;

	sf::Sprite sprite;
	sf::Texture texture;

private:

	// Constructor & Destructor
	Ship();
	~Ship();

};

#endif