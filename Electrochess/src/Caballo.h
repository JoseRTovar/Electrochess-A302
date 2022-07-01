#pragma once
#include "Pieza.h"

class Caballo : public Pieza
{
public:
	Caballo(color_t color) :Pieza(color, CABALLO, "Caballoblanco.png", "Caballonegro.png") {}
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};