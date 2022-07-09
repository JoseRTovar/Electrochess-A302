#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Caballo.h"
#include "Peon.h"
#include "ETSIDI.h"
using ETSIDI::playMusica;
using ETSIDI::stopMusica;

#define N_FILAS 8
#define N_COLUMNAS 8

//****************************************************************************************************************
// Clase que se encarga de almacenar los datos del juego en cada momento (Posición de las piezas y piezas comidas)
//****************************************************************************************************************


class Juego;
class Tablero
{
public:
	Pieza* tab[N_FILAS][N_COLUMNAS];
	Pieza* Comidas[30];
	int SizeComidas = 0;
public:
	Tablero();
	Pieza* operator[](Coordenadas pos) const { return tab[pos.fila][pos.columna]; }
	void cambiarEstado(Coordenadas origen, Coordenadas destino);
	void movEstado(Coordenadas origen, Coordenadas destino);
	void coronacion(Coordenadas origen, Coordenadas destino);
	void cleanTablero();
	void dibuja(Juego& juego);
};


