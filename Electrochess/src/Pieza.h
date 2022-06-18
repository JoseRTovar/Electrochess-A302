#pragma once
#include "Casilla.h"

class Pieza
{
protected:
	Casilla casilla;
	Color color;
public:
	//POLIMORFISMO -> VIRTUAL BASE
	virtual void setColor(unsigned char color);
	virtual void setCasilla(double fila, double columna);
	virtual void dibuja() = 0;
};

