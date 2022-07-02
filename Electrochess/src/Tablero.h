#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Caballo.h"
#include "ETSIDI.h"
using ETSIDI::playMusica;
using ETSIDI::stopMusica;

#define N_FILAS 8
#define N_COLUMNAS 8

class Tablero
{
public:
	Pieza* tab[N_FILAS][N_COLUMNAS];
	Pieza* Comidas[30]; //Lista de piezas comidas
public:
	Tablero();
	void dibuja();
	void MoverPieza(Coordenadas origen, Coordenadas destino);
	Pieza* operator[](Coordenadas pos) const { return tab[pos.fila][pos.columna]; }
};