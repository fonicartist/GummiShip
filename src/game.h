#ifndef  GAME_H
#define  GAME_H

#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#include "enemy.h"
#include "lazerList.h"
#include "ship.h"

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

class Game {
private:
	// Enumeration controls the different states the game goes into.
	enum GameState { titleStart, titleScreen, intro, worldSelect, garage,inGame, gameOver, pause } gameState_;

	bool giveAnother;
	int atkCount,
		jumpCount,
		points;
	double velocity;

	// Game objects
	Ship *GummiShip;
	LazerList *lazerList;
	Enemy *enemy;

	// SFML Objects
	sf::RenderWindow window;

	sf::Clock clock;
	sf::Time deltaTime,
			 gameTime;

	sf::View camera;

	// Fonts for in-game text
	sf::Font titleFont,
			 scoreFont;

	// In game text
	sf::Text titleText,
			 pressText,
			 scoreText,
			 pointsText;

	// Game Music
	sf::Music blast1,
			  blast2,
			  blast3,
			  starsInTheSky,
			  shipmeister;

	// Game sounds but using music implementation
	sf::Music whitenoise;

	// Background Pictures
	sf::Sprite easyBG[2];

	// Game sprites
	sf::Sprite ship;

	// Sprite textures
	sf::Texture easyBGTexture,
				easyBGTexture2,
				shipTexture;

	// Game mechanic functions
	void handleEvent(sf::Event &event);

	void playIntro();
	void titleUpdate();
	void gameoverUpdate();
	void loadAssets();
	void checkMusic();
	void checkHit();
	void velocityUpdate();
	void update();
	void render();

public:
	Game();
	~Game();
	void mainLoop();

};

#endif 