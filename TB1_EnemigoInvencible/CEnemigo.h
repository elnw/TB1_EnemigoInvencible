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
	double Ancho;
	double Largo;

	CEnemigo() {

		random_device rd;
		mt19937  gen(rd());


		uniform_int_distribution<> dis(10, 1000);

		Vida = dis(gen);
		Velocidad = dis(gen);
		Stamina = dis(gen);
		IndiceX = 0;
		IndiceY = 0;
		//Ancho = 73;
		//Largo = 87;
		X = 200;
		Y = 300;
	}

	void Dibujar(BufferedGraphics ^buffer, Bitmap ^bmp)
	{
		Ancho = bmp->Width / 4;
		Largo = bmp->Height / 4;

		Rectangle porcionAUsar = Rectangle(Ancho * IndiceX, Largo*IndiceY, Ancho, Largo);

		Rectangle aumento = Rectangle(X, Y, Ancho * 1, Largo * 1);
		buffer->Graphics->DrawImage(bmp, aumento, porcionAUsar, GraphicsUnit::Pixel);
	}

	void Mover(BufferedGraphics ^buffer, Bitmap ^bmp, int xJugador, int yJugador, int AnchoJ, int LargoJ)
	{
		Ancho = bmp->Width / 4;
		Largo = bmp->Height / 4;
		if (IndiceX >= 0 && IndiceX < 3) {
			IndiceX++;
		}
		else {
			IndiceX = 0;
		}


		if (xJugador+AnchoJ < X ) {
			//Jugador izquierda, enemigo izquierda
			dx = -1*10;
			IndiceY = 1;
			
		}
		if (yJugador+LargoJ < Y) {
			//jugador arriba, enemigo arriba
			IndiceY = 3;
			

			dy = -1 * 10;
		}
		if (xJugador+AnchoJ == X) {
			dx = 0 * 10;
		}
		if (yJugador+AnchoJ == Y) {
			dy = 0 * 10;
		}
		if (xJugador > X+Ancho) {
			//jugador derecha, enemigo derecha
			IndiceY = 2;
			
			dx = 1 * 10;
		}
		if (yJugador > Y+Ancho) {
			//enemigo baja
			IndiceY = 0;

			

			dy = 1 * 10;
		}

		X += dx;
		Y += dy;
		Dibujar(buffer, bmp);

	}

};




#pragma once
