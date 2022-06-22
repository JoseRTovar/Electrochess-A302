#pragma once
#include <math.h>

struct Coordenadas
{
	int fila;
	int columna;
	Coordenadas(int fila = 0, int columna = 0) :fila(fila), columna(columna) {}
};

class Pieza
{
public:
	enum pieza_t { NO_PIEZA = -1, REY, TORRE, ALFIL };
	enum color_t { NO_COLOR = -1, BLANCA, NEGRA };
protected:
	pieza_t pieza = NO_PIEZA;
	color_t color = NO_COLOR;
	Coordenadas posicion;
public:
	Pieza() {}
	Pieza(Coordenadas posicion, color_t c, pieza_t p) :posicion(posicion), color(c), pieza(p) {}
	virtual pieza_t getPieza() { return pieza; }
	virtual color_t getColor() { return color; }
	virtual int getFila() { return posicion.fila; }
	virtual int getColumna() { return posicion.columna; }
	virtual bool validmove(int fila, int columna) = 0;
	virtual void dibuja() = 0;
	bool limitetablero(int fila, int columna) { if (fila < 0 || columna > 7) return false; }
	virtual void setFila(int f) { posicion.fila = f; }
	virtual void setColumna(int c) { posicion.columna = c; }
	virtual pieza_t eliminarPieza() = 0;
};