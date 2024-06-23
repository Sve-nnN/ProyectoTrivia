#include "pch.h"
#include "Corazon.h"

Corazon::Corazon(int _x , int _y) {
	x = _x;
	y = _y;
	indiceX = indiceY = 0;
	dx = dy = 1;
	width = 25;
	height = 25;
}

Corazon::~Corazon() {

}

void Corazon::draw(Graphics^ g, Bitmap^ bmp) {
	int tamanoAncho = bmp->Width;
	int tamanoAlto = bmp->Height;

	Rectangle porcion = Rectangle(indiceX * tamanoAncho, indiceY * tamanoAlto, tamanoAncho, tamanoAlto);

	Rectangle aumento = Rectangle(x, y, width, height);
	g->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
}