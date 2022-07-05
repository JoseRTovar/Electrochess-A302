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
	Pieza* Comidas[30]; //Lista de piezas comidas
	Sprite fondo{ "Fondo.png" };
	int SizeComidas = 0;
public:
	Tablero();
	void dibuja(Juego& juego);
	void cambiarEstado(Coordenadas origen, Coordenadas destino);
	Pieza* operator[](Coordenadas pos) const { return tab[pos.fila][pos.columna]; }
};
