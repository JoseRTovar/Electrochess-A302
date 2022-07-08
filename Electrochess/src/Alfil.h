#pragma once
#include "Pieza.h"

//****************************
//Clase Alfil heredada de Pieza
//****************************

class Alfil : public Pieza
{
public:
	Alfil(Color_e color) :Pieza(color, ALFIL, "Alfilblanco.png", "Alfil.png") {}
	virtual bool validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};
