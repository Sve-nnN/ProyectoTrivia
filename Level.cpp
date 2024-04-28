#include "Level.h"

Level::Level(){}
Level::Level(int number, int enemyCount, int requiredQuestions, int timeLimit) {
	this->number = number;
	this->enemyCount = enemyCount;
	this->requiredQuestions = requiredQuestions;
	this->timeLimit = timeLimit;
}
Level::~Level() {

}
int Level::getNumber() {
	return this->number;
}	
int Level::getEnemyCount() {
	return this->enemyCount;
}
int Level::getRequiredQuestions() {
	return this->requiredQuestions;
}
int	Level::getTimeLimit() {
	return this->timeLimit;
}
