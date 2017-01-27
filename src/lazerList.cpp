#include "lazerList.h"

LazerList::LazerList() {

	head = NULL;
	tail = NULL;
	listSize = 0;

}

bool LazerList::checkCollision(float x1, float x2, float y1, float y2) {
	node* nodePtr;
	
	if (head != NULL) {
		nodePtr = head;
		while (nodePtr != NULL) {
			//printf("Starting check on collision with list.\n");
			if (nodePtr->lazer->getY() < y2 && nodePtr->lazer->getY() > y1)
				if (nodePtr->lazer->getX() < x2 && nodePtr->lazer->getX() > x1)
				{
					nodePtr->lazer->changeHit();
					printf("Lazer made contact with enemy!\n");
					return true;
				}
			nodePtr = nodePtr->next;
		}
	}
	return false;

}

void LazerList::add(Lazer* lazer) {
	node *newNode = new node;
	node *nodePtr;

	newNode->lazer = lazer;

	if (head == NULL) {
		printf("Head is empty. Adding node at the beginning.\n");
		head = newNode;
		tail = newNode;
		listSize++;
	}
	else {
		printf("Head is not empty. Adding node at the end.\n");
		nodePtr = head;
		while (nodePtr != NULL) {
			if (nodePtr->next == NULL) {
				nodePtr->next = newNode;
				tail = newNode;
				listSize++;
				printf("New node inserted. Updating tail.\n");
				break;
			}
			nodePtr = nodePtr->next;
			printf("Looped again.\n");
		}
	}
	printf("%i\n",listSize);
}

void LazerList::pop() {
	node* nodePtr;
	node* nextPtr;

	if (head == NULL) {
		printf("Head is empty. Nothing to pop.\n");
		listSize = 0;
		tail = NULL;
	}
	else {
		printf("Head is not empty. Popping nodes.\n");
		nodePtr = head;
		while (nodePtr != NULL)
			if (nodePtr->lazer->getY() < -100 || nodePtr->lazer->isHit()) {
				printf("Deleting node.\n");
				nextPtr = nodePtr->next;
				head = nodePtr->next;
				delete nodePtr;
				listSize--;
				nodePtr = nextPtr;
			}
			else
				break;
		if (listSize == 0) {
			printf("Assigning flags as NULL.\n");
			head = NULL;
			tail = NULL;
		}
	}
	printf("%i\n", listSize);

}

void LazerList::update(sf::RenderWindow& window) {
	node *nodePtr;

	if (head != NULL) {
		nodePtr = head;
		while (nodePtr != NULL) {
			nodePtr->lazer->update();
			nodePtr = nodePtr->next;
		}
	}
	nodePtr = head;
	if (nodePtr != NULL)
		if (nodePtr->lazer->getY() < -100 || nodePtr->lazer->isHit())
			pop();
	

	render(window);

}

void LazerList::render(sf::RenderWindow& window) {
	node *nodePtr;

	if (head != NULL) {
		nodePtr = head;
		while (nodePtr != NULL) {
			window.draw(nodePtr->lazer->getSprite());
			nodePtr = nodePtr->next;
		}
	}

}

LazerList::~LazerList() {

}