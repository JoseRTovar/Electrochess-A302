#pragma once
#include "Pieza.h"

class Caballo : public Pieza
{
public:
	Caballo(Color_e color) :Pieza(color, CABALLO, "Caballoblanco.png", "Caballo.png") {}
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};

