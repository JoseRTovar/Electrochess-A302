#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(color_t color) : Pieza(color, TORRE) {}
	void dibuja();
};