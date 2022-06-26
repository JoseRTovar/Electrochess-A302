#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey(color_t color) :Pieza(color, REY) {}
	virtual void dibuja();
	virtual bool validmove(int fo, int co, int fd, int cd);
};






