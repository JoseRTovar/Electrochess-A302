#pragma once
#include "Alfil.h"
#include "Tablero.h"

bool Alfil::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::movDiagonal(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	return false;
}