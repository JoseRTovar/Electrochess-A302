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

class Juego;
class Tablero
{
public:
	Pieza* tab[N_FILAS][N_COLUMNAS];
	Pieza* Comidas[30];
	Sprite fondo{ "Fondo.png" }, jaquemate{ "jaquemate.png" };
	int SizeComidas = 0;
public:
	Tablero();
	void dibuja(Juego& juego,int JaqueMate);
	void cambiarEstado(Coordenadas origen, Coordenadas destino);
	void cambiarAux(Coordenadas origen, Coordenadas destino);
	void coronacion(Coordenadas origen, Coordenadas destino);
	Pieza* operator[](Coordenadas pos) const { return tab[pos.fila][pos.columna]; }
	void cleanTablero();
};


