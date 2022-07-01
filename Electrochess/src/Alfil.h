#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
public:
	Alfil(color_t color) :Pieza(color, ALFIL, "Alfilblanco.png", "Alfil.png") {}
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};
