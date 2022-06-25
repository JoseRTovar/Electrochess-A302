#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Pieza.h"
#include "Alfil.h"
#define N_FILAS 8
#define N_COLUMNAS 8

class Tablero
{
private:
	Pieza* tab[N_FILAS][N_COLUMNAS];
	bool turno = 0; //Blancas
public:
	Tablero();
	void inicializa();
	void dibuja();
	void cambiarEstado(int fo, int co, int fd, int cd, Pieza::pieza_t p, Pieza::color_t c);
	void click();
	void cambiarTurno() { turno = !turno; }
};