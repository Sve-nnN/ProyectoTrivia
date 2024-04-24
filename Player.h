#pragma once
#include "Entity.h"

class Player: public Entity
{
private:
	int lives;
public:
	Player(int x, int y, int dx, int height, int width, int lives);
	~Player();

	void setY(int y);
	float getX();
	void setX(int x);
	int  getLives();
	void setLives(int lives);
	void substractLive();
	void erase() override;
	void move(char key);
	void draw() override;
};

