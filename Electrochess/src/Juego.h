#pragma once
#include "Tablero.h"

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

class Juego
{
private:
	bool turno = 0; //Empiezan blancas (0)
	Tablero tablero;
	bool leftButton; //bot�n izquierdo
	bool rightButton; //bot�n derecho
	int xcell_sel, ycell_sel; //celda seleccionada con el rat�n
public:
	void MovimientoRaton(int x, int y, int button, bool down); // movimiento de rat�n
	void ConvCoord(double x, double y, int& cell_x, int& cell_y); // conversi�n coordenadas a celdas
	void cambiarTurno() { turno = !turno; }
	void dibuja();
	void interaccionJugador();
};