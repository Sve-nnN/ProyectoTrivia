#pragma once
#include "Entity.h"
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
class GameService{
private:
	Player* player;
	vector<Entity*> entities;
	
	int currentLevel;
	vector<Level> levels;

	time_t timeT;

public:
	GameService();
	~GameService();

	void addEntities();
	void deleteEntities();

	void eraseEntities();
	void moveEntities();
	void drawEntities();

	Level* getCurrentLevelInfo();
	bool advanceToNextLevel();
	void resetGame();
	void endGame();



	void checkGameResult();
	void detectCollisions();


	Player* getPlayer();

};

