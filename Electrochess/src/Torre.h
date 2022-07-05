#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(Color_e color) :Pieza(color, TORRE, "Torreblanca.png", "Torre.png") {}
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};
