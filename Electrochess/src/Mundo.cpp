#include "Mundo.h"
#include <math.h>

void Mundo::inicializa()
{
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;


	for (int fila = 0; fila < 8; fila++)
	{
		for (int columna = 0; columna < 8; columna++)
		{
			casilla[fila][columna].setPosicion(fila, columna);
			if ((fila + columna) % 2 == 0)
				casilla[fila][columna].setColor(100, 100, 100);
			else
				casilla[fila][columna].setColor(255, 255, 255);
		}
	}

	casilla[0][4].setPieza(Pieza::REY, Pieza::BLANCA);
	casilla[7][4].setPieza(Pieza::REY, Pieza::NEGRA);
	casilla[0][0].setPieza(Pieza::TORRE, Pieza::BLANCA);
	casilla[0][7].setPieza(Pieza::TORRE, Pieza::BLANCA);
	casilla[7][0].setPieza(Pieza::TORRE, Pieza::NEGRA);
	casilla[7][7].setPieza(Pieza::TORRE, Pieza::NEGRA);
	casilla[0][2].setPieza(Pieza::ALFIL, Pieza::BLANCA);
	casilla[0][5].setPieza(Pieza::ALFIL, Pieza::BLANCA);
	casilla[7][2].setPieza(Pieza::ALFIL, Pieza::NEGRA);
	casilla[7][5].setPieza(Pieza::ALFIL, Pieza::NEGRA);
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	
	for (int fila = 0; fila < 8; fila++)
	{
		for (int columna = 0; columna < 8; columna++)
		{
			casilla[fila][columna].dibuja();
		}
	}
}

Coordenadas Mundo::click1()
{
	int fil, col;
	Coordenadas c;

	do
	{
		cout << "Posicion a jugar: " << endl;
		cin >> fil >> col;
		if (casilla[fil][col].getPieza() == Pieza::NO_PIEZA)
			cout << "Casilla vacia" << endl;
		else if (casilla[fil][col].getColorPieza() != (Pieza::color_t)turno)
			cout << "No es tu turno" << endl;
	} while (casilla[fil][col].getPieza() == Pieza::NO_PIEZA || casilla[fil][col].getColorPieza() != (Pieza::color_t)turno);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			if (casilla[fil][col].getValidmove(i, j) == true)
			{
				if ((i + j) % 2 == 0)
					casilla[i][j].setColor(200, 150, 150);
				else
					casilla[i][j].setColor(200, 100, 100);
			}
	}

	c.fila = fil;
	c.columna = col;
	return c;
}

void Mundo::click2(Coordenadas c)
{
	int fil, col;
	do
	{
		cout << "Posicion donde juega: " << endl;
		cin >> fil >> col;
		if (casilla[c.fila][c.columna].getValidmove(fil, col) == false)
			cout << "No es un movimiento valido" << endl;
		else if (casilla[fil][col].getColorPieza() == (Pieza::color_t)turno)
			cout << "Ahi hay una pieza de tu mismo color" << endl;
		else if (casilla[fil][col].getColorPieza() == (Pieza::color_t)!turno)
			cout << "Tecnicamente has comido" << endl;
	} while (casilla[c.fila][c.columna].getValidmove(fil, col) == false || (casilla[fil][col].getPieza() != Pieza::NO_PIEZA && casilla[fil][col].getColorPieza() == (Pieza::color_t)turno && casilla[c.fila][c.columna].getValidmove(fil, col) == true));

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
				casilla[i][j].setColor(100, 100, 100);
			else
				casilla[i][j].setColor(255, 255, 255);
		}
	}

	casilla[fil][col].setPieza(casilla[c.fila][c.columna].getPieza(), (Pieza::color_t)turno);
	casilla[c.fila][c.columna].setPieza(Pieza::NO_PIEZA);
	cambiarTurno();
}
