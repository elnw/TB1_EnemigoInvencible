#pragma once
#include <vector>
using namespace std;

using namespace System::Drawing;
enum Direcciones { Ninguna, Arriba, Abajo, Derecha, Izquierda };
class CPersonaje
{
public:

	int Largo;
	int Ancho;
	int x;
	int y;
	int dx;
	int dy;
	int IndiceX;
	Direcciones Direccion;

	Direcciones UltimaDireccion;


	vector<int> col;
	vector<int> fil;

	void Dibujar(BufferedGraphics ^buffer, Bitmap ^bmp)
	{
		Rectangle porcionAUsar = Rectangle(Ancho * IndiceX, Largo, Ancho, Largo);

		Rectangle aumento = Rectangle(x, y, Ancho * 1, Largo * 1);
		buffer->Graphics->DrawImage(bmp, aumento, porcionAUsar, GraphicsUnit::Pixel);
	}

	void Mover(BufferedGraphics ^buffer, Bitmap ^bmp)
	{
		switch (Direccion)
		{
		case Direcciones::Arriba:
			if (IndiceX >= 1 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 1;
			dx = 0;
			dy = -5;
			UltimaDireccion = Direcciones::Arriba;
			break;

		case Direcciones::Abajo:

			if (IndiceX >= 1 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 1;
			dx = 0;
			dy = 5;
			UltimaDireccion = Direcciones::Abajo;
			break;

		case Direcciones::Derecha:

			if (IndiceX >= 1 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 1;
			dx = 5;
			dy = 0;
			UltimaDireccion = Direcciones::Derecha;
			break;

		case Direcciones::Izquierda:

			if (IndiceX >= 1 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 1;
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

				break;
			case Direcciones::Izquierda:
				IndiceX = 0;

				break;
			}
			break;

			/*if (mapa[x][y] != 0)
			{
			x = 0;
			y = 0;
			}*/
		}
		Dibujar(buffer, bmp);
	}

};



#pragma once
