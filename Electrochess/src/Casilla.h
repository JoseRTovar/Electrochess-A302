#pragma once
#include "Juego.h"

class Casilla
{
public:
	double fila = 0.0;
	double columna = 0.0;
	Color color;
public:
	Casilla() {};
	void setColor(unsigned char color);
	void setPosicion(double fila, double columna);
	double getFila() { return fila; }
	double getColumna() { return columna; }
	void dibuja();
};

