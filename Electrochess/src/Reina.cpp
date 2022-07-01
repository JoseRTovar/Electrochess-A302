#pragma once
#include "Reina.h"

void Reina::dibuja()
{
	reinanegra.setCenter(0.4, 0.4);
	reinanegra.setSize(0.8, 0.8);
	reinablanca.setCenter(0.4, 0.4);
	reinablanca.setSize(0.8, 0.8);
	if (color == Pieza::NEGRA) reinanegra.draw();
	if (color == Pieza::BLANCA) reinablanca.draw();
}

bool Reina::validmove(Coordenadas origen, Coordenadas destino)
{
	if (Coordenadas::MovLineal(origen, destino) == true) return true;
	else if (Coordenadas::MovDiagonal(origen, destino) == true) return true;
	return false;
}

