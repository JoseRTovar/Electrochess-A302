#pragma once
#include "Casilla.h"
#include "freeglut.h"
#define BLANCAS 0
#define NEGRAS 1


class Pieza
{
protected:
	Casilla casilla;
protected:
	Pieza() {};
	Pieza(double fila, double columna);
public:
	void setCasilla(double fila, double columna);
};

