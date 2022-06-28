#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
	Reina(color_t color) :Pieza(color, REINA) {}
	virtual void dibuja();
	virtual bool validmove(Coordenadas origen, Coordenadas destino);
};