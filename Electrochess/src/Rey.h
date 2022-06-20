#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey(color_t color) :Pieza(color, REY) {}
	void dibuja();
};


