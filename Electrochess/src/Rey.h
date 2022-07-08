#pragma once
#include "Pieza.h"

//****************************
//Clase Rey heredada de Pieza
//****************************

class Rey : public Pieza
{
public:
	Rey(Color_e color) :Pieza(color, REY, "Reyblanco.png", "Rey.png") {}
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};





