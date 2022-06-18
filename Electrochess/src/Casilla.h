#pragma once
#include "freeglut.h"
#define NEGRO 100
#define BLANCO 255

struct Color
{
	unsigned char rojo = 0;
	unsigned char verde = 0;
	unsigned char azul = 0;
	void set() { glColor3ub(rojo, verde, azul); }
	Color() {};
};

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

