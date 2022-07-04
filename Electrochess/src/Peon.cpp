#pragma once
#include "Peon.h"
#include "Tablero.h"

bool Peon::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if(color==BLANCA)
	{
			if (origen.fila == 1) 
			{
				if (Coordenadas::Condpeonbfirstmove(origen, destino) == true || Coordenadas::Condpeonb(origen, destino) == true || ((Coordenadas::Condcomepeonb(origen, destino) == true) && tablero[destino] != nullptr))
				{
					return true;
				}
			}
			else if(origen.fila != 1) 
			{
				if ((Coordenadas::Condpeonb(origen, destino) == true) && tablero[destino] == nullptr) 
				{
					return Pieza::validmove(origen, destino, tablero);
				}
				else if ((Coordenadas::Condcomepeonb(origen, destino) == true) && tablero[destino] != nullptr) 
				{
					return Pieza::validmove(origen, destino, tablero);
				}
			}	
	}
	else if (color == NEGRA)
	{
		if (origen.fila == 6)
		{
			if (Coordenadas::Condpeonnfirstmove(origen, destino) == true || Coordenadas::Condpeonn(origen, destino) == true || ((Coordenadas::Condcomepeonn(origen, destino) == true) && tablero[destino] != nullptr))
			{
				return true;
			}
		}
		else if (origen.fila != 6)
		{
			if ((Coordenadas::Condpeonn(origen, destino) == true) && tablero[destino] == nullptr)
			{
				return Pieza::validmove(origen, destino, tablero);
			}
			else if ((Coordenadas::Condcomepeonn(origen, destino) == true) && tablero[destino] != nullptr)
			{
				return Pieza::validmove(origen, destino, tablero);
			}
		}
	}
	return false;
}

