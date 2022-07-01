#pragma once
#include <iostream>
#include "ETSIDI.h"
#include "freeglut.h"
#include "Coordenadas.h"

using ETSIDI::Sprite;
using namespace std;

class Tablero;
class Pieza
{
public:
	enum pieza_t { NO_PIEZA = -1, REY, TORRE, ALFIL, REINA };
	enum color_t { NO_COLOR = -1, BLANCA, NEGRA };
protected:
	pieza_t pieza = NO_PIEZA;
	color_t color = NO_COLOR;
	Sprite imagen;
public:
	Pieza(color_t c, pieza_t p, const char* im_b, const char* im_n) :
		color(c),
		pieza(p),
		imagen(c == BLANCA ? im_b : im_n)
	{
		imagen.setCenter(0.4, 0.4);
		imagen.setSize(0.8, 0.8);
	};

	pieza_t getPieza() { return pieza; }
	color_t getColor() { return color; }
	virtual void dibuja() { imagen.draw(); }
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};