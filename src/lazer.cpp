#include "lazer.h"

Lazer::Lazer(float pos, float x, float y, int direction) {
	sprite.setPosition(pos, 640);
	velocity = sf::Vector2f(x, y);
	hit = false;
	printf("New lazer created at (%d,%d).\n", pos,700);
	loadAssets(direction);
}

void Lazer::loadAssets(int direction) {
	texture.loadFromFile("..\\assets\\sprites\\lazer.png");

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(132*direction, 0, 132, 83));
	sprite.setOrigin(66.f, 0.f);
	//sprite.setPosition(220, -60);
	sprite.setScale(sf::Vector2f(0.90f, 0.90f));

}

void Lazer::update() {
	if (getY() > -100)
		sprite.move(velocity);
		
}

Lazer::~Lazer() {

}