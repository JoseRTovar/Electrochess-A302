#pragma once
#include "Peon.h"
#include "Tablero.h"

//Definicion de movimientos validos para el Peon
//Primer movimiento de cada peon especial y demas movimientos normales
bool Peon::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (color == BLANCA)
	{
		if (origen.fila == 1)
		{
			if ((Coordenadas::primerMovePeon_b(origen, destino) == true && tablero[destino] == nullptr)|| Coordenadas::movPeon_b(origen, destino) == true || ((Coordenadas::comePeon_b(origen, destino) == true) && tablero[destino] != nullptr && tablero[destino]->getColor() != color))
				return Pieza::validMove(origen, destino, tablero);

		}

		else if (origen.fila != 1)
		{
			if ((Coordenadas::movPeon_b(origen, destino) == true) && tablero[destino] == nullptr)
				return Pieza::validMove(origen, destino, tablero);

			else if ((Coordenadas::comePeon_b(origen, destino) == true) && tablero[destino] != nullptr)
				return Pieza::validMove(origen, destino, tablero);
		}
	}

	else if (color == NEGRA)
	{
		if (origen.fila == 6)
		{
			if ((Coordenadas::primerMovePeon_n(origen, destino) == true && tablero[destino] == nullptr) || Coordenadas::movPeon_n(origen, destino) == true || ((Coordenadas::comePeon_n(origen, destino) == true) && tablero[destino] != nullptr && tablero[destino]->getColor() != color))
				return Pieza::validMove(origen, destino, tablero);
		}

		else if (origen.fila != 6)
		{
			if ((Coordenadas::movPeon_n(origen, destino) == true) && tablero[destino] == nullptr)
				return Pieza::validMove(origen, destino, tablero);

			else if ((Coordenadas::comePeon_n(origen, destino) == true) && tablero[destino] != nullptr)
				return Pieza::validMove(origen, destino, tablero);
		}
	}

	return false;
}