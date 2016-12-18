#ifndef  GAME_H
#define  GAME_H

#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

class Game {
private:
	// Enumeration controls the different states the game goes into.
	enum GameState { titleScreen, intro, worldSelect, garage,inGame, gameOver, pause } gameState_;

	bool giveAnother;
	int atkCount,
		jumpCount,
		points;
	double velocity;

	// Game objects

	// SFML Objects
	sf::RenderWindow window;

	sf::Clock clock;
	sf::Time deltaTime;

	sf::View camera;

	// In game text

	// Game Music

	// Game sounds but using music implementation

	// Background Pictures


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