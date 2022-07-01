#pragma once
#include "Reina.h"
#include "Tablero.h"

bool Reina::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::MovLineal(origen, destino) == true)
	{
		return Pieza::validmove(origen, destino, tablero);
	}
	else if (Coordenadas::MovDiagonal(origen, destino) == true) {
		return Pieza::validmove(origen, destino, tablero);
	}
	return false;
}

