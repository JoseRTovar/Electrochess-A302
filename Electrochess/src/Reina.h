#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
	Sprite reinanegra{ "imagenes/Reina.png" };
	Sprite reinablanca{ "imagenes/Reinablanca.png" };
	Reina(color_t color) :Pieza(color, REINA) {}
	virtual void dibuja();
	virtual bool validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero);
};