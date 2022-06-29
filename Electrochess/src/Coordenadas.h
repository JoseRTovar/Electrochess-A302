#pragma once
#include <cmath>

class Coordenadas
{
public:
	int fila;
	int columna;
public:
	Coordenadas() {}
	Coordenadas(int fila, int columna) :fila(fila), columna(columna) {}
	int getFila() { return fila; }
	void setFila(Coordenadas coordenadas) { fila = coordenadas.fila; }
	int getColumna() { return columna; }
	void setColumna(Coordenadas coordenadas) { columna = coordenadas.columna; }

};