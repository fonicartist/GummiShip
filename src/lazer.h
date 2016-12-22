#ifndef LAZER_H
#define LAZER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Lazer {
private:
	int dmg;
	sf::Vector2f velocity;

	sf::Sprite sprite;
	sf::Texture texture;

	void loadAssets(int);

public:
	Lazer(float, float, float, int);
	~Lazer();

	void update();

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

	sf::Sprite getSprite() {
		return sprite;
	}

	sf::Vector2f getVelocity() {
		return velocity;
	}

};

#endif