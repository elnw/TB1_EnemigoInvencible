#pragma once
using namespace System;
using namespace System::Drawing;

class CEnemigo
{
public:
	int ataque;
	int Stamina;
	int Vida;
	int Velocidad;
	int X;
	int Y;
	int dx;
	int dy;
	int IndiceX;
	int Ancho;
	int Largo;

	void Dibujar(BufferedGraphics ^buffer, Bitmap ^bmp)
	{
		Rectangle porcionAUsar = Rectangle(Ancho * IndiceX, Largo, Ancho, Largo);

		Rectangle aumento = Rectangle(X, Y, Ancho * 1, Largo * 1);
		buffer->Graphics->DrawImage(bmp, aumento, porcionAUsar, GraphicsUnit::Pixel);
	}

	void Mover(BufferedGraphics buffer, Bitmap bmp, bool personaje)
	{
		if (personaje)
		{
			dx *= 1;
		}
		else { dx *= -1; }

	}

};




#pragma once
