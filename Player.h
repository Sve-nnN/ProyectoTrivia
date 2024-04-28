#pragma once
#include "Entity.h"

class Player: public Entity
{
private:
	int lives;
	int preguntasContestadas;
	int preguntasCorrectas;
	int preguntasRequeridas;
public:
	Player(int x, int y, int dx, int height, int width, int lives);
	~Player();

	int getPreguntasContestadas();
	void setPreguntasContestadas(int preguntasContestadas);
	int getPreguntasCorrectas();
	void setPreguntasCorrectas(int preguntasCorrectas);
	int getPreguntasRequeridas();
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

