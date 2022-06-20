#pragma once
#include "freeglut.h"
#include "Rey.h"
#include "Torre.h"

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
	double fila;
	double columna;
	Color color;
	Pieza* pieza;
public:
	Casilla();
	void setPosicion(double fila, double columna);
	void setColor(unsigned char color);
	void setPieza(Pieza::pieza_t p, Pieza::color_t c);
	void dibuja();
};


