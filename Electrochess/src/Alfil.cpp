#pragma once
#include "Alfil.h"
#include "Tablero.h"

void Alfil::dibuja()
{
	alfilnegro.setCenter(0.4, 0.4);
	alfilnegro.setSize(0.8, 0.8);
	alfilblanco.setCenter(0.4, 0.4);
	alfilblanco.setSize(0.8, 0.8);
	if (color == Pieza::NEGRA) alfilnegro.draw();
	if (color == Pieza::BLANCA) alfilblanco.draw();
}

bool Alfil::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::MovDiagonal(origen, destino) == true) {
		Pieza::validmove(origen, destino, tablero);
	}
	return false;
}
