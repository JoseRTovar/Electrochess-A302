#include "Tablero.h"

Tablero::Tablero()
{
	for (int fila = 0; fila < N_FILAS; fila++)
	{
		for (int columna = 0; columna < N_COLUMNAS; columna++)
		{
			tab[fila][columna] = nullptr;
		}
	}

	for(int i= 0;i < 30; i++)
	{
		Comidas[i] = nullptr;
	}

	tab[0][4] = new Rey(Pieza::BLANCA);
	tab[7][4] = new Rey(Pieza::NEGRA);
	tab[0][0] = new Torre(Pieza::BLANCA);
	tab[0][7] = new Torre(Pieza::BLANCA);
	tab[7][0] = new Torre(Pieza::NEGRA);
	tab[7][7] = new Torre(Pieza::NEGRA);
	tab[0][2] = new Alfil(Pieza::BLANCA);
	tab[0][5] = new Alfil(Pieza::BLANCA);
	tab[7][2] = new Alfil(Pieza::NEGRA);
	tab[7][5] = new Alfil(Pieza::NEGRA);
	tab[0][3] = new Reina(Pieza::BLANCA);
	tab[7][3] = new Reina(Pieza::NEGRA);
}

void Tablero::MoverPieza(Coordenadas origen, Coordenadas destino)
{
	int sizecomidas = 0;
	if (tab[destino.fila][destino.columna] != nullptr)
	{
		Comidas[sizecomidas++] = tab[destino.fila][destino.columna];
		cout << "Pieza comida " << endl;
	}
	
	tab[destino.fila][destino.columna] = tab[origen.fila][origen.columna];
	tab[origen.fila][origen.columna] = nullptr;
}

void Tablero::dibuja()
{
	for (int fila = 0; fila < N_FILAS; fila++)
	{
		for (int columna = 0; columna < N_COLUMNAS; columna++)
		{
			glDisable(GL_LIGHTING);
			if ((fila + columna) % 2 == 0) glColor3ub(100, 100, 100);
			else glColor3ub(255, 255, 255);
			glBegin(GL_POLYGON);
			glVertex3d(columna, fila, 0.0);
			glVertex3d(columna + 1.0, fila, 0.0);
			glVertex3d(columna + 1.0, fila + 1.0, 0.0);
			glVertex3d(columna, fila + 1.0, 0.0);
			glEnd();
			glEnable(GL_LIGHTING);
		}
	}
}

