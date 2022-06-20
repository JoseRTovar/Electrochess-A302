#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero()
{
	for (int fila = 0; fila < N_FIL; fila++)
	{
		for (int columna = 0; columna < N_COL; columna++)
		{
			casilla[fila][columna].setPosicion(fila, columna);
			if ((fila + columna) % 2 == 0)
				casilla[fila][columna].setColor(NEGRO);
			else
				casilla[fila][columna].setColor(BLANCO);
		}
	}
}

void Tablero::dibuja()
{
	for (int fila = 0; fila < N_FIL; fila++)
	{
		for (int columna = 0; columna < N_COL; columna++)
		{
			casilla[fila][columna].dibuja();
		}
	}
}