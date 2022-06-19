#pragma once
#include "Casilla.h"
#include "Juego.h"

class Pieza
{
protected:

	Casilla casilla;
	Color color;

public:
	Pieza() {}
	
	//POLIMORFISMO -> VIRTUAL BASE
	virtual void setColor(unsigned char color);
	virtual void setCasilla(double fila, double columna);
	virtual void dibuja() = 0;

	virtual void mueve(unsigned char key, Juego juego);


};

