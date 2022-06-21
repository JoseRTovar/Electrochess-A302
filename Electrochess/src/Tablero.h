#pragma once
#include "Casilla.h"

class Tablero
{
public:
	static const int N_COL = 8;
	static const int N_FIL = 8;
	Casilla casilla[N_FIL][N_COL];
public:
	Tablero();
	void dibuja();
	friend class interaccion;
};
