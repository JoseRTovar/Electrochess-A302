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


bool Alfil::validmove(int fo, int co, int fd, int cd) {

	if (((abs(fd - fo) + abs(cd - co)) % 2 == 0) && (abs(fd - fo) == abs(cd - co)))
	{
		return true;
		//Pieza::validmove(fo, co, fd, cd);->Cagada ponerlo ahi ya esta heredado JAAJAJ
	}
	return false;
}

