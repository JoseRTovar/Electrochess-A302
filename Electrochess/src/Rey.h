#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey() :Pieza() {}

	//Rey(Casilla casilla, Color color) : Pieza(casilla, color) {}

	virtual void dibuja();
};

