#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
	Sprite reynegro{ "imagenes/Rey.png" };
	Sprite reyblanco{ "imagenes/Reyblanco.png" };
	Rey(color_t color) :Pieza(color, REY) {}
	virtual void dibuja();
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};






