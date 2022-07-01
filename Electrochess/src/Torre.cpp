#pragma once
#include "Torre.h"

void Torre::dibuja()
{
	torrenegra.setCenter(0.4, 0.4);
	torrenegra.setSize(0.8, 0.8);
	torreblanca.setCenter(0.4, 0.4);
	torreblanca.setSize(0.8, 0.8);
	if (color == Pieza::NEGRA) torrenegra.draw();
	if (color == Pieza::BLANCA) torreblanca.draw();
}

bool Torre::validmove(Coordenadas origen, Coordenadas destino){
	if (Coordenadas::MovLineal(origen,destino)==true) return true;
	return false;
}

