#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey(color_t color) :Pieza(color, REY, "Reyblanco.png", "Rey.png") {}
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};






