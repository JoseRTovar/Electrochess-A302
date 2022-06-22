#include "Torre.h"
#include "freeglut.h"

void Torre::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(NEGRO, NEGRO, NEGRO);
	else if (color == Pieza::BLANCA) glColor3ub(BLANCO, BLANCO, BLANCO);
	glutSolidCube(0.8);
}

bool Torre::validmove(int fila, int columna)
{

	if ((((fila != this->fila) && (columna == this->columna)) || ((columna != this->columna) && (fila == this->fila))) && (tableroinmove(fila, columna) != false)) return true;
	return false;
	//Filas y columnas distintas y dentro del tablero 

}
