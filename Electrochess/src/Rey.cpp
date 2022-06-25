#include "Rey.h"
#include "freeglut.h"

void Rey::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(100, 100, 100);
	else if (color == Pieza::BLANCA) glColor3ub(255, 255, 255);
	glutSolidSphere(0.4, 20, 20);
}

bool Rey::validmove(int fo, int co, int fd, int cd)
{
	if (abs(fd - fo) <= 1 && abs(cd - co) <= 1)
	{
		return true;
		//Pieza::validmove(fo, co, fd, cd);->Cagada ponerlo ahi ya esta heredado JAAJAJ
	}
		return false;
}
