#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
public:
	Sprite alfilnegro{ "imagenes/Alfil.png" };
	Sprite alfilblanco{ "imagenes/Alfilblanco.png" };
	Alfil(color_t color) :Pieza(color, ALFIL) {}
	virtual void dibuja();
	virtual bool validmove(Coordenadas origen, Coordenadas destino);
};
