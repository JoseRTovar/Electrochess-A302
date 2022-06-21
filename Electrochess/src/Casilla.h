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
private:
	int fila;
	int columna;
	Color color;
	Pieza* pieza;
public:
	Casilla();
	void setPosicion(int fila, int columna);
	void setColor(unsigned char color);
	void setPieza(Pieza::pieza_t p, Pieza::color_t c = Pieza::NO_COLOR);
	Pieza::pieza_t getPieza();
	Pieza::color_t getColor();
	int getFilapieza() { return pieza->getFila(); }
	int getColumnapieza() { return pieza->getColumna(); }
	bool getValidmove(int fila, int columna);
	void dibuja();
};

