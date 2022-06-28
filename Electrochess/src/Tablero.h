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
protected:
	bool leftButton;					//botón izquierdo
	bool rightButton;					//botón derecho
	int xcell_sel, ycell_sel;			//celda seleccionada con el ratón
public:
	Tablero();
	void dibuja();
	void MovimientoRaton(int x, int y, int button, bool down); // movimiento de ratón
	void ConvCoord(double x, double y, int& cell_x, int& cell_y); // conversión coordenadas a celdas
	void MoverPieza(Coordenadas origen, Coordenadas destino);
	void cambiarTurno() { turno = !turno; }
	void click();
};