#pragma once
#include "Rey.h"

class Tablero
{
public:
	static const int N_FILAS = 8;
	static const int N_COLUMNAS = 8;
private:
	Pieza* tab[N_FILAS][N_COLUMNAS];
public:
	Tablero();
	void inicializa();
	void dibuja();
	void cambiarEstado(int fo, int co, int fd, int cd, Pieza::pieza_t p, Pieza::color_t c);
};
