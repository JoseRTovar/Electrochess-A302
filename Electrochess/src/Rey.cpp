#include "Rey.h"
#include "freeglut.h"

void Rey::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(100, 100, 100);
	else if (color == Pieza::BLANCA) glColor3ub(255, 255, 255);
	glutSolidSphere(0.4, 20, 20);
}

bool Rey::validmove(int fila, int columna)
{
	if (abs(fila - posicion.fila) <= 1 && abs(columna - posicion.columna) <= 1) return true;
	return false;
}
