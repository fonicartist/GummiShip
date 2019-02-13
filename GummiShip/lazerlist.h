#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#include "lazer.h"

class LazerList {
private:
	struct node {
		node* next = NULL;
		Lazer* lazer;
	};

	node* head;
	node* tail;
	int listSize;

	// Queue manipulation methods
	void pop();

	void render(sf::RenderWindow&);

public:
	LazerList();
	~LazerList();

	void add(Lazer*);
	bool checkCollision(float, float, float, float);

	int getSize() {
		return listSize;
	}
	void update(sf::RenderWindow&);

};