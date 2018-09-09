#pragma once
#include <vector>
#include <math.h>

using namespace std;

using namespace System::Drawing;
enum Direcciones { Ninguna, Arriba, Abajo, Derecha, Izquierda };
class CPersonaje
{
public:

	double Largo;
	double Ancho;
	int x;
	int y;
	int dx;
	int dy;
	int IndiceX;
	int IndiceY;


	Direcciones Direccion;

	Direcciones UltimaDireccion;


	vector<int> col;
	vector<int> fil;

	CPersonaje() {
		x = 0;
		y =0;
		//Largo = 80;
		//Ancho = 45;
		dx = 0;
		dy = 0;
		IndiceX = 0;
		IndiceY = 0;
	}

	void Dibujar(BufferedGraphics ^buffer, Bitmap ^bmp)
	{
		Ancho = bmp->Width / 4;
		Largo = bmp->Height / 4;

		Rectangle porcionAUsar = Rectangle(Ancho * IndiceX, Largo*IndiceY, Ancho, Largo);

		Rectangle aumento = Rectangle(x, y, Ancho * 1, Largo * 1);
		
		buffer->Graphics->DrawImage(bmp, aumento, porcionAUsar, GraphicsUnit::Pixel);
		
	}

	void Mover(BufferedGraphics ^buffer, Bitmap ^bmp)
	{
		

		switch (Direccion)
		{
		case Direcciones::Arriba:
			IndiceY = 3;
			if (IndiceX >= 0 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 0;
			dx = 0;
			dy = -5;
			UltimaDireccion = Direcciones::Arriba;
			break;

		case Direcciones::Abajo:

			if (IndiceX >= 0 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 0;
			IndiceY = 0;
			dx = 0;
			dy = 5;
			UltimaDireccion = Direcciones::Abajo;
			break;

		case Direcciones::Derecha:
			IndiceY = 2;
			if (IndiceX >= 0 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 1;
			dx = 5;
			dy = 0;
			UltimaDireccion = Direcciones::Derecha;
			break;

		case Direcciones::Izquierda:
			IndiceY = 1;
			if (IndiceX >= 0 && IndiceX <3)
				IndiceX++;
			else
				IndiceX = 0;
			dx = -5;
			dy = 0;
			UltimaDireccion = Direcciones::Izquierda;
			break;

		case Direcciones::Ninguna:
			dx = dy = 0;
			switch (Direcciones::Ninguna)
			{
			case Direcciones::Arriba:
				IndiceX = 0;

				break;
			case Direcciones::Abajo:
				IndiceX = 0;

				break;
			case Direcciones::Derecha:
				IndiceX = 0;
				IndiceY = 1;
				break;
			case Direcciones::Izquierda:
				IndiceX = 0;
				IndiceY = 0;
				break;
			}
			break;

			/*if (mapa[x][y] != 0)
			{
			x = 0;
			y = 0;
			}*/
		}
		x += dx;
		y += dy;
		Dibujar(buffer, bmp);
	}

	int AtaqueDebil( int posEneX, int posEneY, int AnchoEne, int LargoEne)
	{
		int r1, r2;

		r1 = Ancho / 2;
		r2 = AnchoEne / 2;

		//verificacion colision
		int centro1, centro2, centro3, centro4;

		centro1 = x + r1;
		centro2 = y + r2;
		centro3 = y + r1;
		centro4 = x + r2;

		double distancia = sqrt((abs(centro2 - centro1) * abs(centro2 - centro1)) + (abs(centro4 - centro3) * abs(centro4 - centro3)));

		if (r1 + r2> distancia && r1 + r2> distancia)
		{
			return 10;
			

		}
		return 0;
	}

	}


	;

#pragma once
