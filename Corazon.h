#pragma once
using namespace System::Drawing;

class Corazon 
{
protected:
	int x, y;
	int indiceX;
	int indiceY;
	int dx, dy;
	int width;
	int height;
public:
	Corazon(int _x, int _y);
	~Corazon();

	void draw(Graphics^ g, Bitmap^ bmp);

};