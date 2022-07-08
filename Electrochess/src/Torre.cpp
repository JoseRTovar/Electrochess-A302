#pragma once
#include "Torre.h"
#include "Tablero.h"

//Definicion de movimientos validos lineales + la definicion comun de Pieza 
bool Torre::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::movLineal(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	return false;
}

