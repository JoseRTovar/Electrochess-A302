#pragma once
#include "Reina.h"

void Reina::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(100, 100, 100);
	else if (color == Pieza::BLANCA) glColor3ub(255, 255, 255);
	glutSolidTeapot(0.3);
}

bool Reina::validmove(Coordenadas origen, Coordenadas destino)
{
	return true;
}

