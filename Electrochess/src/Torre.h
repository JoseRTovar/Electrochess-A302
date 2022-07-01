#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(color_t color) :Pieza(color, TORRE, "Torreblanca.png", "Torre.png") {}
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};