#pragma once
#include "Pieza.h"

//****************************
//Clase Peon heredada de Pieza
//****************************

class Peon : public Pieza
{
public:
	Peon(Color_e color) :Pieza(color, PEON, "Peonblanco.png", "Peon.png") {}
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};
