#include "pch.h"
#include "Nave.h"

Nave::Nave(int x, float y, int dx, int height, int width, int lives)
	: Entity(x, y, dx, height, width)
{
	this->dy = 2;
	this->lives = lives;
}

Nave::~Nave() {

}

void Nave::setY(float y) {
	this->y = y;
}

float Nave::getX() {
	return this->x;
}

void Nave::setX(int x) {
	this->x = x;
}

void Nave::setLives(int lives) {
	this->lives = lives;
}

int Nave::getLives() {
	return this->lives;
}

void Nave::substractLive() {
	this->lives--;
}


void Nave::erase() {
	Console::SetCursorPosition(x, int(y)); cout << "   ";
	Console::SetCursorPosition(x, int(y) + 1); cout << "   ";
	Console::SetCursorPosition(x, int(y) + 2); cout << "   ";
}

void Nave::move(char key) {
	switch (key) {
	case 75:
		if (x > Console::WindowLeft + 2)
			x -= dx;
		break;
	case 80:
		if (y + height < Console::WindowHeight)
			y += dy;
		break;
	case 77:
		if (x + width < Console::WindowWidth)
			x += dx;
		break;
	case 72:
		if (y > Console::WindowTop)
			y -= dy;
		break;
	}
}

void Nave::draw() {
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(x, int(y)); cout << " O ";
	Console::SetCursorPosition(x, int(y) + 1); cout << "/I\\";
	Console::SetCursorPosition(x, int(y) + 2); cout << "/ \\";
}