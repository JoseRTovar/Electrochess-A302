#pragma once
#include "Caballo.h"
#include "Tablero.h"

bool Caballo::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (tablero[destino] != nullptr && tablero[destino]->getColor() == color) return false;
	if (Coordenadas::MovCaballo(origen, destino) == true) return true;
	return false;
}