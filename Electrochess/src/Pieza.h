#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Coordenadas.h"
using ETSIDI::Sprite;

//*****************************************************************************************************************************
//Clase base Pieza encargada de definir todos tus atributos y m�todos de forma que se puedan hereden a todos los tipos de pieza
//*****************************************************************************************************************************

class Tablero;
class Pieza
{
public:
	enum Pieza_e { NO_PIEZA = -1, REY, TORRE, ALFIL, REINA, CABALLO, PEON };
	enum Color_e { NO_COLOR = -1, BLANCA, NEGRA };
protected:
	Pieza_e pieza = NO_PIEZA;
	Color_e color = NO_COLOR;
	Sprite imagen;
public:
	Pieza(Color_e c, Pieza_e p, const char* im_b, const char* im_n) :
		color(c),
		pieza(p),
		imagen(c == BLANCA ? im_b : im_n)
	{
		imagen.setCenter(0.4, 0.4);
		imagen.setSize(0.8, 0.8);
	};
	Pieza_e getPieza() { return pieza; }
	Color_e getColor() { return color; }
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
	virtual void dibuja() { imagen.draw(); }
};