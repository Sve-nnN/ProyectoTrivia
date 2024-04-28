#include "Enemy.h"

Enemy::Enemy(int x, float y, int dx, int height, int width, int index):Entity(x,y,dx,height,width) {
	this->enemyColor = ConsoleColor::Red;

}
Enemy::~Enemy() {

}

void Enemy::erase() {
	Console::ForegroundColor = enemyColor;
	Console::SetCursorPosition(x, int(y)); cout << "      ";
	Console::SetCursorPosition(x, int(y) + 1); cout << "      ";
	Console::SetCursorPosition(x, int(y) + 2); cout << "      ";

}
void Enemy::move() {
	if (y < Console::WindowTop + 1 || y + height > Console::WindowHeight) {
		dy *= -1;
	}
	y += dy;

}
void Enemy::draw() {
	Console::ForegroundColor = enemyColor;

	//Imprimir figura del enemigo
	Console::SetCursorPosition(x, int(y)); cout << "  /" << char(92) << "  ";
	Console::SetCursorPosition(x, int(y) + 1); cout << " /  " << char(92) << " ";
	Console::SetCursorPosition(x, int(y) + 2); cout << " |  | ";

}