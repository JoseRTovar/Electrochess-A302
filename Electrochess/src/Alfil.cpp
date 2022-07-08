#pragma once
#include "Alfil.h"
#include "Tablero.h"

//Definicion de movimientos validos en diagonal + la definicion comun de Pieza 
bool Alfil::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::movDiagonal(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	return false;
}