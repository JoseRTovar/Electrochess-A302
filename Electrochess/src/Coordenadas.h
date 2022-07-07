#pragma once
#include <cmath>

//****************************************************************************************************************
// Clase para referenciar la posición en el tablero, sus métodos realizan las operaciones matemáticas necesarias
// para cada tipo de movimiento.
//****************************************************************************************************************


class Coordenadas
{
public:
	int fila = 0;
	int columna = 0;
public:
	Coordenadas() {}
	Coordenadas(int fila, int columna) :fila(fila), columna(columna) {}
	static bool movLineal(Coordenadas origen, Coordenadas destino);
	static bool movDiagonal(Coordenadas origen, Coordenadas destino);
	static bool noSaltarDiag_one(Coordenadas origen, Coordenadas destino);
	static bool movUnitario(Coordenadas origen, Coordenadas destino);
	static bool movCaballo(Coordenadas origen, Coordenadas destino);
	static bool movPeon_b(Coordenadas origen, Coordenadas destino);
	static bool movPeon_n(Coordenadas origen, Coordenadas destino);
	static bool comePeon_b(Coordenadas origen, Coordenadas destino);
	static bool comePeon_n(Coordenadas origen, Coordenadas destino);
	static bool primerMovePeon_b(Coordenadas origen, Coordenadas destino);
	static bool primerMovePeon_n(Coordenadas origen, Coordenadas destino);
	static bool fueraTablero(Coordenadas c);
};