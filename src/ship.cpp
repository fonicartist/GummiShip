// Implementation file for Ship object.
#include "ship.h"

// Constructor
Ship::Ship() {

	exhaustCounter = 0;
	shootCounter = 0;
	lazerguns = 1;
	movement_ = still;

	loadAssets();

}

// Load files associated with ship
void Ship::loadAssets() {
	// Sprite sheets
	exhaustTexture.loadFromFile("..\\assets\\sprites\\exhaust.png");
	texture.loadFromFile("..\\assets\\sprites\\highwind.png");
	// Sound effects
	lazerSound.openFromFile("..\\assets\\sounds\\pew.ogg");

	exhaust.setTexture(exhaustTexture);
	exhaust.setTextureRect(sf::IntRect(132, 0, 132, 63));
	exhaust.setOrigin(66.f, 31.f);
	exhaust.setPosition(220, 700);
	exhaust.setScale(sf::Vector2f(0.90f, 0.90f));

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(132, 0, 132, 134));
	sprite.setOrigin(66.f, 132.f);
	sprite.setPosition(220, 700);
	sprite.setScale(sf::Vector2f(0.90f, 0.90f));

}

void Ship::exhaustAnim() {
	exhaust.setTextureRect(sf::IntRect(132 * movement_, 64 * (exhaustCounter/5), 132, 63));
	exhaust.setScale(sf::Vector2f(0.90f - exhaustCounter / 200.f, 0.90f - exhaustCounter / 150.f));
	if (exhaustCounter == 19)
		exhaustCounter = -1;
}

void Ship::inputHandler(sf::Event& event) {
	// Handles inputs that are one-shots 
}

void Ship::update(sf::RenderWindow& window, LazerList* lazerList) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootCounter == 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (lazerguns == 1) {
				Lazer* lazer = new Lazer(getX() - 20, -4, -25, leftShot);
				lazerList->add(lazer);
			}
			else if (lazerguns == 2) {
				Lazer* lazer = new Lazer(getX() - 30, -4, -25, leftShot);
				lazerList->add(lazer);
				Lazer* lazer2 = new Lazer(getX() - 10, -4, -25, leftShot);
				lazerList->add(lazer2);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (lazerguns == 1) {
				Lazer* lazer = new Lazer(getX() + 20, 4, -25, rightShot);
				lazerList->add(lazer);
			}
			else if (lazerguns == 2) {
				Lazer* lazer = new Lazer(getX() + 30, 4, -25, rightShot);
				lazerList->add(lazer);
				Lazer* lazer2 = new Lazer(getX() + 10, 4, -25, rightShot);
				lazerList->add(lazer2);
			}
		}
		else {
			if (lazerguns == 1) {
				Lazer* lazer = new Lazer(getX(), 0, -25, straightShot);
				lazerList->add(lazer);
			}
			else if (lazerguns == 2) {
				Lazer* lazer = new Lazer(getX() - 10, 0, -25, straightShot);
				lazerList->add(lazer);
				Lazer* lazer2 = new Lazer(getX() + 10, 0, -25, straightShot);
				lazerList->add(lazer2);
			}
		}
		shootCounter = 7;
		lazerSound.play();
	}

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
	if (shootCounter > 0)
		shootCounter--;

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