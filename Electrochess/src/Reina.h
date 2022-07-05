#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
	Reina(Color_e color) :Pieza(color, REINA, "Reinablanca.png", "Reina.png") {}
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};