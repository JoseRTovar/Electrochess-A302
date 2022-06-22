#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(Coordenadas posicion, color_t color) : Pieza(posicion, color, TORRE) {}
	virtual void dibuja();
	//virtual Pieza::pieza_t getPieza() { return Pieza::getPieza(); }
	//virtual Pieza::color_t getColor() { return Pieza::getColor(); }
	//virtual int getFila() { return Pieza::getFila(); }
	//virtual int getColumna() { return Pieza::getColumna(); }
	virtual bool validmove(int fila, int columna);
	//virtual void setFila(int f) { posicion.fila = f; }
	//virtual void setColumna(int c) { posicion.columna = c; }
	virtual  Pieza::pieza_t eliminarPieza() {
		setFila(NULL);
		setColumna(NULL);
		return Pieza::NO_PIEZA;
	}
};
