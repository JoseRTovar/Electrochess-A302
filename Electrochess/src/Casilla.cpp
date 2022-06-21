#include "Casilla.h"

Casilla::Casilla()
{
	fila = 0.0;
	columna = 0.0;
	pieza = nullptr;
}

void Casilla::setPosicion(int fila, int columna)
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
		pieza = new Rey(fila, columna, c);
		break;
	case Pieza::TORRE:
		pieza = new Torre(fila, columna, c);
		break;
	case Pieza::NO_PIEZA:
		//Este delete hay que cambiarlo porq si antes no había pieza, delete igual?
		delete pieza;
		pieza = nullptr;
		break;
	}
}

Pieza::pieza_t Casilla::getPieza()
{
	if (pieza == nullptr) return Pieza::NO_PIEZA;
	return pieza->getPieza();
}

Pieza::color_t Casilla::getColor()
{
	if (pieza == nullptr) return Pieza::NO_COLOR;
	return pieza->getColor();
}

bool Casilla::getValidmove(int fila, int columna)
{
	//if (pieza == nullptr) return false;
	return pieza->validmove(fila, columna);
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