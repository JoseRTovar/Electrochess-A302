#pragma once
#include "Torre.h"
#include "Tablero.h"

bool Torre::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::movLineal(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	return false;
}

