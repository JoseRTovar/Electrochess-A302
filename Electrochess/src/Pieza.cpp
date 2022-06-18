#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza(double fila, double columna)
{
	casilla.fila = fila;
	casilla.columna = columna;
}

void Pieza::setCasilla(double fila, double columna)
{
	casilla.setPosicion(fila + 0.5, columna + 0.5);
}


