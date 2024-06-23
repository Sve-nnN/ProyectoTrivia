#pragma once
using namespace System::Drawing;

class Aliado
{
protected:
	int x, y;
	int indiceX;
	int indiceY;
	int dx, dy;
	int width;
	int height;
public:
	Aliado(int _x, int _y);
	~Aliado();

	void draw(Graphics^ g, Bitmap^ bmp, int offsetX, int offsetY);
};