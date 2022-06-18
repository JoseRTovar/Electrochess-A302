#pragma once
#include "freeglut.h"
#define NEGRO 100
#define BLANCO 255

struct Color
{
	unsigned char rojo = 0;
	unsigned char verde = 0;
	unsigned char azul = 0;
	void set() { glColor3ub(rojo, verde, azul); }
	Color() {};
};
