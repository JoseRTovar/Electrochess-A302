#include "Casilla.h"

void Casilla::setColor(unsigned char color)
{
	this->color.rojo = this->color.verde = this->color.azul = color;
}

void Casilla::setPosicion(double fila, double columna)
{
	this->fila = fila;
	this->columna = columna;
}

void Casilla::dibuja()
{
	glDisable(GL_LIGHTING);
	color.set();
	glBegin(GL_POLYGON);
	glVertex3d(columna, fila, 0.0);
	glVertex3d(columna + 1.0, fila, 0.0);
	glVertex3d(columna + 1.0, fila + 1.0, 0.0);
	glVertex3d(columna, fila + 1.0, 0.0);
	glEnd();
	glEnable(GL_LIGHTING);
}