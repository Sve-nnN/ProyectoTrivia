#include "pch.h"
#include "GameService.h"

GameService::GameService() {
	numberOfEnemies = rand() % 8 + 2;
	isFinish = false;

	corazones.push_back(new Corazon(20, 5));
	corazones.push_back(new Corazon(50, 5));
	corazones.push_back(new Corazon(80, 5));
}

GameService::~GameService() {

}


int  GameService::getCountEnemiesDelete() {
	return this->countEnemiesDelete;
}

bool GameService::getIsFinish() {
	return this->isFinish;
}

void  GameService::setIsFinish(bool isFinish) {
	this->isFinish = isFinish;
}



void GameService::createEnemies(int width, int height) {

	for (int i = 0; i < numberOfEnemies; i++)
	{
		Enemy* e = new Enemy(width, height, rand() % 2);
		enemies.push_back(e);
	}
}

void GameService::drawEveryThing(Graphics^ panel, Bitmap^ imagenEnemy) {
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->draw(panel, imagenEnemy);
	}
}

void GameService::drawHeart(Graphics^ panel, Bitmap^ imagenHeart) {
	for (int i = 0; i < corazones.size(); i++)
	{
		corazones[i]->draw(panel, imagenHeart);
	}
}

void GameService::moveEveryThing(Graphics^ panel) {
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->move(panel);
	}
}
/*void GameService::collision(Graphics^ panel) {
//TODO

}*/

