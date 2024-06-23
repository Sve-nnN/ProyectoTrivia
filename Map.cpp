#include "pch.h"
#include "Map.h"
#include "Aliado.h"

Map::Map(int width, int height, Player player) {
	this->width = width;
	this->height = height;
	playerX = player.getX();
	playerY = player.getY();
	dx = 0;
	dy = 0;
	indexX = 0;
	indexY = 0;
	visibility = true;
}

Map::~Map() {
}

void Map::draw(Graphics^ panel, Bitmap^ image, Player player, Aliado aliado, Bitmap^ aliadoImage) {
	// Dibujar el mapa
	Rectangle sectionShow = Rectangle(playerX - 20, playerY - 40, width, height);
	Rectangle zoom = Rectangle(0, 0, image->Width, image->Height);
	panel->DrawImage(image, zoom, sectionShow, GraphicsUnit::Pixel);

	// Dibujar el aliado en la posición fija
	int offsetX = -playerX + 20;
	int offsetY = -playerY + 40;
	aliado.draw(panel, aliadoImage, offsetX, offsetY);
}


void Map::move(Graphics^ panel, Player player) {
	// Code to move the map based on player's movement
	dx = player.getX() - playerX;
	dy = player.getY() - playerY;
	indexX += dx;
	indexY += dy;
	playerX = player.getX();
	playerY = player.getY();
}

Rectangle Map::getRectangle() {
	// Code to get the rectangle of the map
	return Rectangle(0, 0, width, height);
}