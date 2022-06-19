
#pragma once
#include "freeglut.h"
#include "Pieza.h"

//coolor
#define NEGRO 100
#define BLANCO 255

//turno
#define BLANCAS 0
#define NEGRAS 1


struct Color
{
	unsigned char rojo = 0;
	unsigned char verde = 0;
	unsigned char azul = 0;
	void set() { glColor3ub(rojo, verde, azul); }
	Color() {};
};


class Juego {
public:
	bool turno = 0;

	Juego() {};

	bool getTurno() { return turno; }
	void setTurno(bool turno) { this->turno = turno; }

};


