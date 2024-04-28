#pragma once
#include "Entity.h"
class Enemy :public Entity {
private:
	ConsoleColor enemyColor;
public:
	Enemy(int x, float y, int dx, int height, int width, int index);
	~Enemy();

	void erase() override;
	void move();
	void draw() override;

};

