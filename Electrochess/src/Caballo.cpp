#pragma once
#include "Caballo.h"
#include "Tablero.h"

bool Caballo::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (tablero[destino] != nullptr && tablero[destino]->getColor() == color) return false;
	if (Coordenadas::movCaballo(origen, destino) == true) return true;

	return false;
}