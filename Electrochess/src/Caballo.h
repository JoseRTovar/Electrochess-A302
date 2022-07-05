#pragma once
#include "Pieza.h"

class Caballo : public Pieza
{
public:
	Caballo(color_t color) :Pieza(color, CABALLO, "Caballoblanco.png", "Caballo.png") {}
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};
