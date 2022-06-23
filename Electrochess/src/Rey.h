#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey(Coordenadas posicion, color_t color) :Pieza(posicion, color, REY) {}
	virtual void dibuja();
	virtual bool validmove(int fila, int columna);
	//virtual Pieza::pieza_t eliminarPieza() {
	//	setFila(NULL);
	//	setColumna(NULL);
	//	return Pieza::NO_PIEZA;
	//}
};





