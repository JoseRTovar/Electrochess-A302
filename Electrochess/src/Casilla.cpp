#include "Casilla.h"

Casilla::Casilla()
{
	fila = 0.0;
	columna = 0.0;
	pieza = nullptr;
}

void Casilla::setPosicion(double fila, double columna)
{
	this->fila = fila;
	this->columna = columna;
}

void Casilla::setColor(unsigned char color)
{
	this->color.rojo = this->color.verde = this->color.azul = color;
}

void Casilla::setPieza(Pieza::pieza_t p, Pieza::color_t c)
{
	switch (p)
	{
	case Pieza::REY:
		pieza = new Rey(c);
		break;
	case Pieza::TORRE:
		pieza = new Torre(c);
		break;
	}
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
	if (pieza != nullptr)
	{
		glTranslatef(columna + 0.5, fila + 0.5, 0);
		pieza->dibuja();
		glTranslatef(-columna - 0.5, -fila - 0.5, 0);
	}
}