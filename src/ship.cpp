// Implementation file for Ship object.
#include "ship.h"

// Constructor
Ship::Ship() {

	exhaustCounter = 0;
	movement_ = still;

	loadAssets();

}

// Load files associated with ship
void Ship::loadAssets() {
	// Sprite sheets
	exhaustTexture.loadFromFile("..\\assets\\sprites\\exhaust.png");
	texture.loadFromFile("..\\assets\\sprites\\highwind.png");
	// Sound effects

	exhaust.setTexture(exhaustTexture);
	exhaust.setTextureRect(sf::IntRect(1 * 132, 0, 132, 63));
	exhaust.setOrigin(66.f, 31.f);
	exhaust.setPosition(220, 700);
	exhaust.setScale(sf::Vector2f(0.90f, 0.90f));

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(1 * 132, 0, 132, 134));
	sprite.setOrigin(66.f, 132.f);
	sprite.setPosition(220, 700);
	sprite.setScale(sf::Vector2f(0.90f, 0.90f));

}

void Ship::exhaustAnim() {
	exhaust.setTextureRect(sf::IntRect(132 * movement_, 64 * (exhaustCounter/5), 132, 63));
	if (exhaustCounter == 19)
		exhaustCounter = -1;
}

void Ship::update(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sprite.move(sf::Vector2f(-8.f, 0.f));
		movement_ = left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		sprite.move(sf::Vector2f(8.f, 0.f));
		movement_ = right;
	}
	else {
		movement_ = still;
	}
	if (sprite.getPosition().x < 10)
		sprite.setPosition(5, sprite.getPosition().y);
	else if (sprite.getPosition().x > 430)
		sprite.setPosition(435, sprite.getPosition().y);

	// Update animations and sprites
	sprite.setTextureRect(sf::IntRect(132 * movement_, 0, 132, 134));
	exhaust.setPosition(getX(), exhaust.getPosition().y);
	exhaustAnim();
	exhaustCounter++;

	// Render the updates
	render(window);

}

void Ship::render(sf::RenderWindow& window) {

	window.draw(exhaust);
	window.draw(sprite);

}

// Destructor
Ship::~Ship() {

}