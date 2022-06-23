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
	pieza_t getPieza() { return pieza; }
	color_t getColor() { return color; }
	int getFila() { return posicion.fila; }
	int getColumna() { return posicion.columna; }
	virtual bool validmove(int fila, int columna) = 0;
	virtual void dibuja() = 0;
	bool limitetablero(int fila, int columna) { if (fila < 0 || columna > 7) return false; }
	//virtual pieza_t eliminarPieza() = 0;
};