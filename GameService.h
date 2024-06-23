#pragma once
#include <vector>
#include "Player.h"
#include"Enemy.h"
#include"Corazon.h"

using namespace std;

class GameService
{
private:
	vector<Enemy*>enemies;
	vector<Corazon*>corazones;
	int numberOfEnemies;

	int countEnemiesDelete = 0;
	bool isFinish;


public:
	GameService();
	~GameService();



	void createEnemies(int width, int height);
	void drawEveryThing(Graphics^ panel, Bitmap^ imagenEnemy);
	void drawHeart(Graphics^ panel, Bitmap^ imagenHeart);
	void moveEveryThing(Graphics^ panel);

	int getCountEnemiesDelete();
	bool getIsFinish();
	void setIsFinish(bool isFinish);
//	void drawAliado(Graphics^ panel, Bitmap^ imagenAliado);
};

