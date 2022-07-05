#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
public:
	Peon(color_t color) :Pieza(color, PEON, "Peonblanco.png", "Peon.png") {}
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};
