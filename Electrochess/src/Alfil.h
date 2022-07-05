#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
public:
	Alfil(Color_e color) :Pieza(color, ALFIL, "Alfilblanco.png", "Alfil.png") {}
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};
