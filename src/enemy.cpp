#include "enemy.h"

Enemy::Enemy() {
	HP = 2;
	loadAssets();
}

void Enemy::loadAssets() {

	shape.setFillColor(sf::Color::Magenta);
	shape.setSize(sf::Vector2f(100.f, 100.f));
	shape.setOrigin(50, 50);
	shape.setPosition(220, 100);

}

void Enemy::update(sf::RenderWindow& window, LazerList* lazerList) {
	float leftx, rightx, topy, bottomy;
	leftx = shape.getPosition().x - 45;
	rightx = leftx + 90;
	topy = shape.getPosition().y -45;
	bottomy = topy + 90;

	if (lazerList->checkCollision(leftx, rightx, topy, bottomy)) {
		HP--;
	}
	
	printf("%i, %i, %i, %i\n", leftx, rightx, topy, bottomy);
	render(window);

}

void Enemy::render(sf::RenderWindow& window) {

	window.draw(shape);
	
}

Enemy::~Enemy() {

}