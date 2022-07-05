#pragma once
#include "Torre.h"
#include "Tablero.h"

bool Torre::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero) 
{
	if (Coordenadas::MovLineal(origen, destino) == true)
	{
		return Pieza::validmove(origen, destino, tablero);
	}
	return false;
}

