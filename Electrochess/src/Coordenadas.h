#pragma once
#include <cmath>

class Coordenadas
{
public:
	int fila = 0;
	int columna = 0;
public:
	Coordenadas() {}
	Coordenadas(int fila, int columna) :fila(fila), columna(columna) {}
	static const bool MovLineal(Coordenadas origen, Coordenadas destino);
	static const bool MovDiagonal(Coordenadas origen, Coordenadas destino);
	static const bool Movdeunoenuno(Coordenadas origen, Coordenadas destino);
	static const bool MovCaballo(Coordenadas origen, Coordenadas destino);
	static const bool Condpeonb(Coordenadas origen, Coordenadas destino);
	static const bool Condpeonn(Coordenadas origen, Coordenadas destino);
	static const bool Condcomepeonb(Coordenadas origen, Coordenadas destino);
	static const bool Condcomepeonn(Coordenadas origen, Coordenadas destino);
	static const bool Condpeonbfirstmove(Coordenadas origen, Coordenadas destino);
	static const bool Condpeonnfirstmove(Coordenadas origen, Coordenadas destino);
	static const bool FueraTablero(Coordenadas c);
};