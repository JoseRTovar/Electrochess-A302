#pragma once
#include "Peon.h"
#include "Tablero.h"

bool Peon::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{

	if(color==BLANCA){
		
		if ((Coordenadas::Condpeonb(origen, destino) == true) && tablero[destino] == nullptr) {
			return Pieza::validmove(origen, destino, tablero);
		}
		else if ((Coordenadas::Condcomepeonb(origen, destino) == true) && tablero[destino] != nullptr) {
			return Pieza::validmove(origen, destino, tablero);
		}
	}
	else if (color == NEGRA) {

		if ((Coordenadas::Condpeonn(origen, destino) == true) && tablero[destino] == nullptr) {
			return Pieza::validmove(origen, destino, tablero);
		}
		else if ((Coordenadas::Condcomepeonn(origen, destino) == true) && tablero[destino] != nullptr) {
			return Pieza::validmove(origen, destino, tablero);
		}
	}
	return false;
}

