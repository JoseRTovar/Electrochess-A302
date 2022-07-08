#pragma once
#include "Reina.h"
#include "Tablero.h"

//Definicion de movimientos validos en diagonal y lineal + la definicion comun de Pieza 
bool Reina::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::movLineal(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	else if (Coordenadas::movDiagonal(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	return false;
}