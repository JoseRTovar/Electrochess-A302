#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
	Reina(color_t color) :Pieza(color, REINA, "Reinablanca.png", "Reina.png") {}
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};