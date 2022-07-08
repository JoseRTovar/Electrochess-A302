#pragma once
#include "Pieza.h"

//****************************
//Clase Caballo heredada de Pieza
//****************************

class Caballo : public Pieza
{
public:
	Caballo(Color_e color) :Pieza(color, CABALLO, "Caballoblanco.png", "Caballo.png") {}
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};

