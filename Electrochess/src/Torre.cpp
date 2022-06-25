#pragma once
#include "Torre.h"
#include "freeglut.h"

void Torre::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(100, 100, 100);
	else if (color == Pieza::BLANCA) glColor3ub(255, 255, 255);
	glutSolidCube(0.8);
}

//bool Torre::validmove(int fila, int columna)
//{
//
//	if ((((fila != posicion.fila) && (columna == posicion.columna)) || ((columna != posicion.columna) && (fila == posicion.fila))) && (limitetablero(fila, columna) != false)) return true;
//	return false;
//}

bool Torre::validmove(int fo, int co, int fd, int cd){

	if((fd != fo && cd == co) || (cd != co && fo == fd))
	{
		Pieza::validmove(fo, co, fd, cd);
	}
	return false;
}
