#pragma once
#include <cmath>

class Coordenadas {
public:
	int fila, columna;
	Coordenadas() {};
	Coordenadas(int _fila, int _columna) :fila(_fila), columna(_columna) {}

	int getFila() { return fila; }
	void setFila(Coordenadas coordenadas) { fila = coordenadas.fila; }
	int getColumna() { return columna; }
	void setColumna(Coordenadas coordenadas) { columna = coordenadas.columna; }
};