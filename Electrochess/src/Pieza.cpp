#include "Pieza.h"

void Pieza::setColor(unsigned char color)
{
	this->color.rojo = this->color.verde = this->color.azul = color;
}

void Pieza::setCasilla(double fila, double columna)
{
	casilla.fila = fila;
	casilla.columna = columna;
}
