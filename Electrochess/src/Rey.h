#pragma once
#include "Pieza.h"

//#include "ETSIDI.h"

//using ETSIDI::SpriteSequence;

class Rey : public Pieza
{
public:
	Rey(int fila, int columna, color_t color) :Pieza(fila, columna, color, REY) {}
	//SpriteSequence sprite{ "imagenes/Rey.png", 5 };
	virtual void dibuja();
	virtual Pieza::pieza_t getPieza() { return Pieza::getPieza(); }
	virtual Pieza::color_t getColor() { return Pieza::getColor(); }
	virtual int getFila() { return Pieza::getFila(); }
	virtual int getColumna() { return Pieza::getColumna(); }
	friend class Interaccion;
	virtual bool validmove(int fila, int columna);

	virtual void setFila(int f) { fila = f; }
	virtual void setColumna(int c) { columna = c; }

	/*virtual bool tableroinmove(int fila, int columna) {
		if (fila < 0 || columna > 7) return false;
	}*/

	//Nueva:
	virtual Pieza::pieza_t eliminarPieza() {
		setFila(NULL);
		setColumna(NULL);
		return Pieza::NO_PIEZA;
	}
};





