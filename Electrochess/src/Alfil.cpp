#pragma once
#include "Alfil.h"
#include "freeglut.h"
#include <cmath>

void Alfil::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(100, 100, 100);
	else if (color == Pieza::BLANCA) glColor3ub(255, 255, 255);
	glutSolidTorus(0.15, 0.3, 20, 20);
}

bool Alfil::validmove(Coordenadas origen, Coordenadas destino)
{
	if (((abs(destino.fila - origen.fila) + abs(destino.columna - origen.columna)) % 2 == 0) && (abs(destino.fila - origen.fila) == abs(destino.columna - origen.columna))) return true;
	return false;
}

