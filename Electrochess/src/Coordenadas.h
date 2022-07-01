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
	static const bool MovLineal(Coordenadas origen, Coordenadas destino);
	static const bool MovDiagonal(Coordenadas origen, Coordenadas destino);
	static const bool Movdeunoenuno(Coordenadas origen, Coordenadas destino);
	static const bool MovCaballo(Coordenadas origen, Coordenadas destino);
	static const bool FueraTablero(Coordenadas c);
};
