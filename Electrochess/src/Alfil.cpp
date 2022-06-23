#include "Alfil.h"
#include "freeglut.h"

void Alfil::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(100, 100, 100);
	else if (color == Pieza::BLANCA) glColor3ub(255, 255, 255);
	glutSolidTorus(0.15, 0.3, 20, 20);
}

bool Alfil::validmove(int fila, int columna)
{
	if((abs(fila-posicion.fila)+abs(columna-posicion.columna))%2==0 &&
		abs(fila-posicion.fila)==abs(columna-posicion.columna)
		&& ((limitetablero(fila, columna) != false))) return true;
	return false;
}

