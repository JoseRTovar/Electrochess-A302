#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
public:
	Alfil(Coordenadas posicion, color_t color) :Pieza(posicion, color, ALFIL) {}
	virtual void dibuja();
	virtual bool validmove(int fila, int columna);
	//virtual Pieza::pieza_t eliminarPieza() {
	//	setFila(NULL);
	//	setColumna(NULL);
	//	return Pieza::NO_PIEZA;
	//}
};