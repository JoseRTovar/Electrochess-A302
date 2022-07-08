#pragma once
#include "Pieza.h"
#include "Tablero.h"

bool Pieza::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	int aux;

	//Se revisa si la casilla está ocupada por una pieza del mismo color que el turno 
	if (tablero[destino] != nullptr && tablero[destino]->getColor() == color) return false;

	//COMPROBACION DE TRAYECTORIA. Objetivo: no saltar entre piezas
	//LINEAL EN FILAS 
	if (destino.fila != origen.fila && destino.columna == origen.columna)
	{
		aux = (destino.fila - origen.fila) / abs(destino.fila - origen.fila);
		while (abs(destino.fila - origen.fila) > 1)
		{
			origen.fila = origen.fila + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//LINEAL EN COLUMNAS
	else if (destino.columna != origen.columna && destino.fila == origen.fila)
	{
		aux = (destino.columna - origen.columna) / abs(destino.columna - origen.columna);
		while (abs(destino.columna - origen.columna) > 1)
		{
			origen.columna = origen.columna + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//DIAGONAL DE IZQUIERDA A DERECHA
	else if (Coordenadas::noSaltarDiag_one(origen,destino) == true)
	{
		aux = (destino.columna - origen.columna) / abs(destino.columna - origen.columna);
		while (abs(destino.columna - origen.columna) > 1)
		{
			origen.columna = origen.columna + aux;
			origen.fila = origen.fila + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//DIAGONAL DE DERECHA A IZQUIERDA
	else if (destino.columna != origen.columna && destino.fila != origen.fila)
	{
		aux = (destino.columna - origen.columna) / abs(destino.columna - origen.columna);
		while (abs(destino.columna - origen.columna) > 1)
		{
			origen.columna = origen.columna + aux;
			origen.fila = origen.fila - aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	return true;
}
