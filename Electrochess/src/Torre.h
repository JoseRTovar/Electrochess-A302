#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(int fila, int columna, color_t color) : Pieza(fila, columna, color, TORRE) {}
	virtual void dibuja();
	virtual Pieza::pieza_t getPieza() { return Pieza::getPieza(); }
	virtual Pieza::color_t getColor() { return Pieza::getColor(); }
	virtual int getFila() { return Pieza::getFila(); }
	virtual int getColumna() { return Pieza::getColumna(); }
	virtual bool validmove(int fila, int columna);
};