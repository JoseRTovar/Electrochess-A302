#pragma once
#include "Tablero.h"
#include <iostream>
using namespace std;

class Pieza
{
public:
	enum pieza_t { NO_PIEZA = -1, REY, TORRE, ALFIL };
	enum color_t { NO_COLOR = -1, BLANCA, NEGRA };
protected:
	pieza_t pieza = NO_PIEZA;
	color_t color = NO_COLOR;
public:
	//Pieza() {}
	Pieza(color_t c, pieza_t p) : color(c), pieza(p) {}
	pieza_t getPieza() { return pieza; }
	color_t getColor() { return color; }
	virtual void dibuja() = 0;
	virtual bool validmove(int fo, int co, int fd, int cd, Tablero& t) = 0;
};