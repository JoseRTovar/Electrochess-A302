#pragma once
#include "Alfil.h"
#include "Tablero.h"

bool Alfil::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::MovDiagonal(origen, destino) == true)
	{
		return Pieza::validmove(origen, destino, tablero);
	}
	return false;
}