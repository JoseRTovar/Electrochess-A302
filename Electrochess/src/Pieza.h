#pragma once
#include <math.h>
#define NEGRO 100
#define BLANCO 255

class Pieza
{
public:
	enum pieza_t { NO_PIEZA = -1, REY, TORRE, ALFIL };
	enum color_t { NO_COLOR = -1, BLANCA, NEGRA };
protected:
	pieza_t pieza = NO_PIEZA;
	color_t color = NO_COLOR;
	int fila = 0;
	int columna = 0;
public:
	Pieza() {}
	Pieza(int fila, int columna, color_t c, pieza_t p) :fila(fila), columna(columna), color(c), pieza(p) {}
	virtual pieza_t getPieza() { return pieza; }
	virtual color_t getColor() { return color; }
	virtual int getFila() { return fila; }
	virtual int getColumna() { return columna; }
	virtual void dibuja() = 0;
	virtual bool validmove(int fila, int columna) = 0;

	bool tableroinmove(int fila, int columna) {
		if (fila < 0 || columna > 7) return false;
	}



	//Nuevo añadido

	virtual void setFila(int f) { fila = f; }
	virtual void setColumna(int c) { columna = c; }

	virtual pieza_t eliminarPieza() = 0;
};