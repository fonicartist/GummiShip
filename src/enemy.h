#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "lazer.h"
#include "lazerList.h"

class Enemy {
private:
	int HP;

	sf::Sprite sprite;
	sf::Texture texture;
	sf::RectangleShape shape;

	void loadAssets();
	void render(sf::RenderWindow&);

public:
	Enemy();
	~Enemy();
	
	void update(sf::RenderWindow&, LazerList*);

	// Accessor Methods
	int getHP() {
		return HP;
	}
	float getX() {
		return shape.getPosition().x;
	};
	float getY() {
		return shape.getPosition().y;
	};
	void setX(float val) {
		shape.setPosition(val, getY());
	};
	void setY(float val) {
		shape.setPosition(getX(), val);
	};

};

#endif