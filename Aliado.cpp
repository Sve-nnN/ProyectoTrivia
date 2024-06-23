#include "pch.h"
#include "Aliado.h"

Aliado::Aliado(int _x, int _y) {
	x = _x;
	y = _y;
	indiceX = indiceY = 0;
	dx = dy = 1;
	width = 30;
	height = 30;
}

Aliado::~Aliado() {

}

void Aliado::draw(Graphics^ g, Bitmap^ bmp, int offsetX, int offsetY) {
	int tamanoAncho = bmp->Width / 4;
	int tamanoAlto = bmp->Height / 4;

	Rectangle porcion = Rectangle(indiceX * tamanoAncho, indiceY * tamanoAlto, tamanoAncho, tamanoAlto);

	Rectangle aumento = Rectangle(x + offsetX, y + offsetY, width, height);
	g->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
}