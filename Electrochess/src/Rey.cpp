#include "Rey.h"
#include "freeglut.h"

void Rey::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(NEGRO, NEGRO, NEGRO);
	else if (color == Pieza::BLANCA) glColor3ub(BLANCO, BLANCO, BLANCO);
	glutSolidSphere(0.4, 20, 20);
}

bool Rey::validmove(int fila, int columna)
{
	if (abs(fila - this->fila) <= 1 && abs(columna - this->columna) <= 1) return true;
	return false;
}
