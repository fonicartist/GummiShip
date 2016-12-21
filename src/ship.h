#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Ship {
private:
	// Ship properties
	enum Movement {left, still, right} movement_;
	int armor,		// Ship Stats
		HP;
	int exhaustCounter;		// Animation counter for exhuast

	//SFML Variables
	sf::Sprite exhaust,
			   sprite;
	sf::Texture exhaustTexture,
				texture;
	sf::Music lazer,
			  spin,
			  rocket;

	// Animation
	void exhaustAnim();

	// Methods
	void loadAssets();
	void render(sf::RenderWindow&);

public:
	// Constructor & Destructor
	Ship();
	~Ship();

	void inputHandler(sf::Event&);
	void update(sf::RenderWindow&);

	// Accessor Methods
	float getX() {
		return sprite.getPosition().x;
	};
	float getY() {
		return sprite.getPosition().y;
	};
	void setX(float val) {
		sprite.setPosition(val, getY());
	};
	void setY(float val) {
		sprite.setPosition(getX(), val);
	};

};

#endif