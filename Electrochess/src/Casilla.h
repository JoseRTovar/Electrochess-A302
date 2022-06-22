#pragma once
#include "freeglut.h"
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
typedef unsigned char byte;

class Casilla
{
private:
	Coordenadas posicion;
	Pieza* pieza;
	byte rojo;
	byte verde;
	byte azul;
public:
	Casilla() :pieza(nullptr) {}
	void setPosicion(int fila, int columna);
	void setColor(byte r, byte v, byte a);
	void setPieza(Pieza::pieza_t p, Pieza::color_t c = Pieza::NO_COLOR);
	Pieza::pieza_t getPieza();
	Pieza::color_t getColorPieza();
	int getFilapieza() { return pieza->getFila(); }
	int getColumnapieza() { return pieza->getColumna(); }
	bool getValidmove(int fila, int columna);
	void dibuja();

	Pieza::pieza_t eliminarPieza() {
		delete pieza;
		pieza = nullptr;
		return Pieza::NO_PIEZA;
	}
};


