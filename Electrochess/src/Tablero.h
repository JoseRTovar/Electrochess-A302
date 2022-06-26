#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
#define N_FILAS 8
#define N_COLUMNAS 8

struct Coordenadas //Innecesario cuando usemos ratón?
{
	int fila;
	int columna;
	Coordenadas(int fila = 0, int columna = 0) :fila(fila), columna(columna) {}
};

class Tablero
{
private:
	Pieza* tab[N_FILAS][N_COLUMNAS];
	bool turno = 0; //Blancas
public:
	Tablero();
	void dibuja();
	void cambiarEstado(int fo, int co, int fd, int cd, Pieza::pieza_t p, Pieza::color_t c);
	void cambiarTurno() { turno = !turno; }
	void click();
};