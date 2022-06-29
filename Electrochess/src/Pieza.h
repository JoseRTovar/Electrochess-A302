#pragma once
#include <iostream>
#include "ETSIDI.h"
#include "freeglut.h"
#include "Coordenadas.h"
using ETSIDI::Sprite;
using namespace std;

class Pieza
{
public:
	enum pieza_t { NO_PIEZA = -1, REY, TORRE, ALFIL, REINA };
	enum color_t { NO_COLOR = -1, BLANCA, NEGRA };
protected:
	pieza_t pieza = NO_PIEZA;
	color_t color = NO_COLOR;
public:
	Pieza(color_t c, pieza_t p) : color(c), pieza(p) {};
	pieza_t getPieza() { return pieza; }
	color_t getColor() { return color; }
	virtual void dibuja() = 0;
	virtual bool validmove(Coordenadas origen, Coordenadas destino) = 0;
};