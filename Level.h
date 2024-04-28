#pragma once

class Level{
private:
	int number;
	int enemyCount;
	int requiredQuestions;
	int timeLimit;
public:
	Level();

	Level(int number, int enemyCount, int requiredQuestions, int timeLimit);
	~Level();

	int getNumber();
	int getEnemyCount();
	int getRequiredQuestions();
	int getTimeLimit();
};

