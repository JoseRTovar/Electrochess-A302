#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#define N_FILAS 8
#define N_COLUMNAS 8

struct Coordenadas //Innecesario cuando usemos rat�n?
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
	//PRUEBA
	void NoSaltar(int filai, int columnai, int filadestino, int columnadestino, bool error) {
		for (int i = filai; i < filadestino; i++) {
			if (tab[filai][columnai] == nullptr) tab[filai][columnai] = tab[filai + 1][columnai];
			if (tab[i][columnai]->getColor() == (Pieza::color_t)turno) { //probar ci
				cout << "No se pueden saltar piezas" << endl;
				error = 1;
			}
		}
	}

};