#pragma once
#include "Caballo.h"
#include "Tablero.h"

//Definicion de movimientos validos en saltos L, excluida de Pieza por su excepcion
bool Caballo::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (tablero[destino] != nullptr && tablero[destino]->getColor() == color) return false;
	if (Coordenadas::movCaballo(origen, destino) == true) return true;

	return false;
}