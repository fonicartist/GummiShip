#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "game.h"

using namespace std;

/*************************************
 * Main function starts the game and *
 * lets it run.						 *
 *************************************/
int main() {
	// Hide debug console
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);
	// Create a game object then start its loop.
	Game game;
	game.mainLoop();
	// Kill program by returning a value to the console
	return 0;
}