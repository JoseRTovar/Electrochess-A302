#pragma once
#include "Pieza.h"


class Torre : public Pieza
{
public:
	Sprite torrenegra{ "imagenes/Torre.png" };
	Sprite torreblanca{ "imagenes/Torreblanca.png" };
	Torre(color_t color) :Pieza(color, TORRE) {}
	virtual void dibuja();
	virtual bool validmove(Coordenadas origen, Coordenadas destino);
};