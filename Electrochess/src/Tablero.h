#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#define N_FILAS 8
#define N_COLUMNAS 8


class Tablero
{
private:
	Pieza* tab[N_FILAS][N_COLUMNAS];
	Pieza* Comidas[30]; //Lista de piezas comidas
	bool turno = 0; //Blancas -> trasladarlo a Game
public:
	Tablero();
	void dibuja();
	void MoverPieza(Coordenadas origen, Coordenadas destino);
	void cambiarTurno() { turno = !turno; }
	void click();
};