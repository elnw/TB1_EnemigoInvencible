#pragma once
using namespace System;
using namespace System::Drawing;
#include <random>
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
	int IndiceY;
	int Ancho;
	int Largo;

	CEnemigo() {
		random_device rd;
		mt19937  gen(rd());


		uniform_int_distribution<> dis(10, 1000);

		Vida = dis(gen);
		Velocidad = dis(gen);
		Stamina = dis(gen);
		IndiceX = 0;
		IndiceY = 0;
		Ancho = 63;
		Largo = 83;
		X = 200;
		Y = 300;
	}

	void Dibujar(BufferedGraphics ^buffer, Bitmap ^bmp)
	{
		Rectangle porcionAUsar = Rectangle(Ancho * IndiceX, Largo*IndiceY, Ancho, Largo);

		Rectangle aumento = Rectangle(X, Y, Ancho * 1, Largo * 1);
		buffer->Graphics->DrawImage(bmp, aumento, porcionAUsar, GraphicsUnit::Pixel);
	}

	void Mover(BufferedGraphics ^buffer, Bitmap ^bmp, int xJugador, int yJugador, int AnchoJ, int LargoJ)
	{
		if (xJugador+AnchoJ < X ) {
			dx = -1*10;
			IndiceY = 2;
			if (IndiceX >= 0 && IndiceX <= 3) {
				IndiceX++;
			}
			else {
				IndiceX = 0;
			}
		}
		if (yJugador+LargoJ < Y) {
			IndiceY = 4;
			if (IndiceX >= 0 && IndiceX <= 5) {
				IndiceX++;
			}
			else {
				IndiceX = 0;
			}

			dy = -1 * 10;
		}
		if (xJugador+AnchoJ == X) {
			dx = 0 * 10;
		}
		if (yJugador+AnchoJ == Y) {
			dy = 0 * 10;
		}
		if (xJugador > X+Ancho) {
			dx = 1 * 10;
		}
		if (yJugador > Y+Ancho) {
			IndiceY = 0;

			if (IndiceX >= 0 && IndiceX <= 3) {
				IndiceX++;
			}
			else {
				IndiceX = 0;
			}

			dy = 1 * 10;
		}

		X += dx;
		Y += dy;
		Dibujar(buffer, bmp);

	}

};




#pragma once
