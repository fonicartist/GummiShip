#include "enemy.h"

Enemy::Enemy(int x, int y) {
	HP = 6;
	direction = pow(-1, rand() % 2);
	loadAssets(x, y);
}

void Enemy::loadAssets(int x, int y) {

	shape.setFillColor(sf::Color::Magenta);
	shape.setSize(sf::Vector2f(100.f, 100.f));
	shape.setOrigin(50, 50);
	shape.setPosition(100+x, -580+y);

}

void Enemy::update(sf::RenderWindow& window, LazerList* lazerList, int &points) {
	float leftx, rightx, topy, bottomy;
	leftx = shape.getPosition().x - 45;
	rightx = leftx + 90;
	topy = shape.getPosition().y -45;
	bottomy = topy + 90;

	if (getX() < 40)
		direction *= -1;
	else if (getX() > 488)
		direction *= -1;
	setX(getX() + 8 * direction);
	setY(getY() + rand() % 4 - rand() % 3 + 2);
	if (getY() < 200)
		setY(getY() + rand() % 5);

	if (lazerList->checkCollision(leftx, rightx, topy, bottomy)) {
		HP--;
		points += 10;
	}
	
	//printf("%i, %i, %i, %i\n", leftx, rightx, topy, bottomy);
	render(window);

}

void Enemy::render(sf::RenderWindow& window) {

	window.draw(shape);
	
}

Enemy::~Enemy() {

}