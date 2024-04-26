
#include "Player.h"

Player::Player(int x, int y, int dx, int height, int width, int lives) : Entity(x, y, dx, height, width)
{
	this->dy = 2;
	this->lives = lives;
}


Player::~Player() {

}

void Player::setY(int y) {
	this->y = y;
}

float Player::getX() {
	return this->x;
}

void Player::setX(int x) {
	this->x = x;
}

void Player::setLives(int lives) {
	this->lives = lives;
}

int Player::getLives() {
	return this->lives;
}

void Player::substractLive() {
	this->lives--;
}


void Player::erase() {
	Console::SetCursorPosition(x, int(y)); cout << "   ";
	Console::SetCursorPosition(x, int(y) + 1); cout << "   ";
	Console::SetCursorPosition(x, int(y) + 2); cout << "   ";
}

void Player::move(char key) {
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

void Player::draw() {
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(x, int(y)); cout << " O ";
	Console::SetCursorPosition(x, int(y) + 1); cout << "/I\\";
	Console::SetCursorPosition(x, int(y) + 2); cout << "/ \\";
}