// Implementation file for Game object.
#include "game.h"
using namespace std;

/************************************************
 * Constructor Game() creates a new Game object *
 * containing everything else when the program  *
 * starts up.									*
 ************************************************/
Game::Game() {
	// Create game render window
	window.create(sf::VideoMode(440, 720), "Gummi Ship");
	window.setMouseCursorVisible(true);
	window.setKeyRepeatEnabled(false);

	//window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);

	camera.setCenter(220, 360);

	GummiShip = new Ship();
	lazerList = new LazerList();
	gameState_ = titleScreen;

	loadAssets();
}

/************************************************
 * The mainLoop() function handles in game		*
 * occurences while the program window remains	*
 * open.										*
 ************************************************/
void Game::mainLoop() {
	sf::Event event;
	deltaTime = sf::Time::Zero;
	gameTime = sf::Time::Zero;

	while (window.isOpen()) {
		sf::Time elapsedTime = clock.restart();
		deltaTime += elapsedTime;
		if (gameState_ == inGame)
			gameTime += elapsedTime;

		while (deltaTime > TimePerFrame) {
			// Reset deltaTime
			deltaTime -= TimePerFrame;

			// Check for events
			while (window.pollEvent(event))
				handleEvent(event);

			// Update in game time
			if (gameState_ == inGame)
				pointsText.setString(to_string((int)(gameTime.asSeconds() * 17)));

			// Switch between different gamestates

			checkMusic();
			
		}
		update();
	}
}

void Game::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::Closed)
		window.close();

	// Close window by escape or set full screen
	if (sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Escape && (gameState_ == titleStart || gameState_ == titleScreen)) {
			window.close();
		}

	// Change gamestates
	switch (gameState_) {
	case titleScreen:
		if (sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			gameState_ = inGame;
		break;
	case inGame:
		GummiShip->inputHandler(event);
		break;
	default: break;
	}

}

void Game::loadAssets() {
	// Load game images
	easyBGTexture.loadFromFile("..\\assets\\bg\\easybg.png");
	easyBGTexture2.loadFromFile("..\\assets\\bg\\easybg2.png");
	// Load sprite textures
	
	// Load music files
	blast1.openFromFile("..\\assets\\music\\blastaway1.ogg");
	blast2.openFromFile("..\\assets\\music\\blastaway2.ogg");
	blast3.openFromFile("..\\assets\\music\\blastaway3.ogg");
	starsInTheSky.openFromFile("..\\assets\\music\\preciousStarsInTheSky.ogg");
	shipmeister.openFromFile("..\\assets\\music\\shipmeistersHumoresque.ogg");
	// Load sound files
	whitenoise.openFromFile("..\\assets\\sounds\\whitenoise.ogg");
	// Load fonts
	scoreFont.loadFromFile("..\\assets\\fonts\\KHGummiShip.ttf");

	//ship.setTexture(shipTexture);
	//ship.setTextureRect(sf::IntRect(1*132, 0, 132, 134));
	//ship.setOrigin(66.f, 132.f);
	//ship.setPosition(220, 700);
	//ship.setScale(sf::Vector2f(0.90f,0.90f));

	easyBG[0].setTexture(easyBGTexture);
	easyBG[0].setOrigin(220.f, -720.f);
	easyBG[0].setPosition(220, -8640);
	easyBG[1].setTexture(easyBGTexture2);
	easyBG[1].setOrigin(220.f, -720.f);
	easyBG[1].setPosition(220, -17280);

	pointsText.setFont(scoreFont);
	pointsText.setColor(sf::Color(255, 200, 50, 255));
	pointsText.setCharacterSize(32);
	pointsText.setPosition(10, 25);
	pointsText.setStyle(sf::Text::Italic);

	scoreText.setFont(scoreFont);
	scoreText.setString("SCORE");
	scoreText.setColor(sf::Color(255, 135, 0, 255));
	scoreText.setCharacterSize(20);
	scoreText.setPosition(10, 6);
	scoreText.setStyle(sf::Text::Italic);

}

void Game::checkMusic() {
	// Play title theme music
	if (starsInTheSky.getStatus() != sf::Music::Playing && (gameState_ == titleStart || gameState_ == titleScreen))
		starsInTheSky.play();
	else if (starsInTheSky.getStatus() == sf::Music::Playing && (gameState_ != titleStart && gameState_ != titleScreen))
		starsInTheSky.stop();
	// Play easy mode mission music
	if (blast1.getStatus() != sf::Music::Playing && gameState_ == inGame)
		blast1.play();
	else if (blast1.getStatus() == sf::Music::Playing && gameState_ != inGame )
		blast1.stop();
	if (whitenoise.getStatus() != sf::Music::Playing && gameState_ == inGame)
		whitenoise.play();
	else if (whitenoise.getStatus() == sf::Music::Playing && gameState_ != inGame)
		whitenoise.stop();
}

void Game::update() {

	// Camera
	camera.setSize(sf::Vector2f(440, 720));
	//camera.setCenter(220, 360);
	camera.zoom(1.0);
	window.setView(camera);
	if (gameState_ == inGame) {
		easyBG[0].move(sf::Vector2f(0.f, 24.f));
		easyBG[1].move(sf::Vector2f(0.f, 24.f));
		for (int i = 0; i < 2; i++)
			if (easyBG[i].getPosition().y >= 0)
				easyBG[i].setPosition(220, -17280);
	}
	render();

}

void Game::render() {

	window.clear();

	switch (gameState_) {
	case inGame:
		for (int i = 0; i < 2; i++)
			window.draw(easyBG[i]);
		lazerList->update(window);
		GummiShip->update(window, lazerList);
		window.draw(pointsText);
		window.draw(scoreText);
		break;
	default: break;
	}
	window.display();

}

/************************************************
 * Destructor ~Game() deletes any objects and	*
 * instances before the program shuts down.		*
 ************************************************/
Game::~Game() {

}