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
	Sprite fondo{ "Fondo.png" };
	int SizeComidas = 0;
public:
	Tablero();
	void dibuja(Juego& juego);
	void cambiarEstado(Coordenadas origen, Coordenadas destino);
	void movEstado(Coordenadas origen, Coordenadas destino);
	void coronacion(Coordenadas origen, Coordenadas destino);
	Pieza* operator[](Coordenadas pos) const { return tab[pos.fila][pos.columna]; }
	void cleanTablero();
};


