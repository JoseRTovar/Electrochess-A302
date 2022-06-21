#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(int fila, int columna, color_t color) : Pieza(fila, columna, color, TORRE) {}
	virtual void dibuja();
	virtual Pieza::pieza_t getPieza() { return Pieza::getPieza(); }
	virtual Pieza::color_t getColor() { return Pieza::getColor(); }
	virtual int getFila() { return Pieza::getFila(); }
	virtual int getColumna() { return Pieza::getColumna(); }
	virtual bool validmove(int fila, int columna);

	virtual void setFila(int f) { fila = f; }
	virtual void setColumna(int c) { columna = c; }

	/*virtual bool tableroinmove(int fila, int columna) {
		if (fila < 0 || columna > 7) return false;
	}*/

	//Torre:
	virtual  Pieza::pieza_t eliminarPieza() {
		setFila(NULL);
		setColumna(NULL);
		return Pieza::NO_PIEZA;
	}
};
