#include "Rey.h"
#include "freeglut.h"

void Rey::dibuja() 
{
	color.set();
	glTranslatef(casilla.getColumna() + 0.5, casilla.getFila() + 0.5, 0);
	glutSolidSphere(0.4, 20, 20);
	glTranslatef(-casilla.getColumna() - 0.5, -casilla.getFila() - 0.5, 0);
}

