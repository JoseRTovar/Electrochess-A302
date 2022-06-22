#include "Casilla.h"

void Casilla::setPosicion(int fila, int columna)
{
	posicion.fila = fila;
	posicion.columna = columna;
	rojo = verde = azul = 0;
}

void Casilla::setColor(byte r, byte v, byte a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Casilla::setPieza(Pieza::pieza_t p, Pieza::color_t c)
{
	switch (p)
	{
	case Pieza::REY:
		pieza = new Rey(posicion, c);
		break;
	case Pieza::TORRE:
		pieza = new Torre(posicion, c);
		break;
	case Pieza::ALFIL:
		pieza = new Alfil(posicion, c);
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

Pieza::color_t Casilla::getColorPieza()
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
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3d(posicion.columna, posicion.fila, 0.0);
	glVertex3d(posicion.columna + 1.0, posicion.fila, 0.0);
	glVertex3d(posicion.columna + 1.0, posicion.fila + 1.0, 0.0);
	glVertex3d(posicion.columna, posicion.fila + 1.0, 0.0);
	glEnd();
	glEnable(GL_LIGHTING);

	if (pieza != nullptr)
	{
		glTranslatef(posicion.columna + 0.5, posicion.fila + 0.5, 0);
		pieza->dibuja();
		glTranslatef(-posicion.columna - 0.5, -posicion.fila - 0.5, 0);
	}
}