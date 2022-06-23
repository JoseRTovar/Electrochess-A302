#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(Coordenadas posicion, color_t color) : Pieza(posicion, color, TORRE) {}
	virtual void dibuja();
	virtual bool validmove(int fila, int columna);
	//virtual  Pieza::pieza_t eliminarPieza() {
	//	setFila(NULL);
	//	setColumna(NULL);
	//	return Pieza::NO_PIEZA;
	//}
};
