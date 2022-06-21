#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey(int fila, int columna, color_t color) :Pieza(fila, columna, color, REY) {}
	virtual void dibuja();
	virtual Pieza::pieza_t getPieza() { return Pieza::getPieza(); }
	virtual Pieza::color_t getColor() { return Pieza::getColor(); }
	virtual int getFila() { return Pieza::getFila(); }
	virtual int getColumna() { return Pieza::getColumna(); }
	friend class Interaccion;
	virtual bool validmove(int fila, int columna);
};



