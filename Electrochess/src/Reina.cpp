#pragma once
#include "Reina.h"
#include "Tablero.h"

bool Reina::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::movLineal(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	else if (Coordenadas::movDiagonal(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	return false;
}