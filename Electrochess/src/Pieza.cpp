#pragma once
#include "Pieza.h"
#include "Tablero.h"

bool Pieza::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	int aux;

	//Revisa si la casilla está ocupada por una pieza de tu color
	if (tablero[destino] != nullptr && tablero[destino]->getColor() == color) return false;

	//no saltar -> Algoritmo para comprobar trayectoria
	//ARRIBA ABAJO 
	if (destino.fila != origen.fila && destino.columna == origen.columna)
	{
		aux = (destino.fila - origen.fila) / abs(destino.fila - origen.fila);
		while (abs(destino.fila - origen.fila) > 1)
		{
			origen.fila = origen.fila + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//DERECHA E IZQUIERDA
	else if (destino.columna != origen.columna && destino.fila == origen.fila)
	{
		aux = (destino.columna - origen.columna) / abs(destino.columna - origen.columna);
		while (abs(destino.columna - origen.columna) > 1)
		{
			origen.columna = origen.columna + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//DIAGONAL IZQ -> DCHA ARRIBA Y ABAJO
	else if ((destino.columna - origen.columna == destino.fila - origen.fila) && destino.columna != origen.columna && destino.fila != origen.fila)
	{
		aux = (destino.columna - origen.columna) / abs(destino.columna - origen.columna);
		while (abs(destino.columna - origen.columna) > 1)
		{
			origen.columna = origen.columna + aux;
			origen.fila = origen.fila + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//DIAGONAL DCHA -> IZQ
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
