#pragma once
#include "Tablero.h"

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

class Juego
{
private:
	bool turno = 0; //Empiezan blancas (0)
	Tablero tablero;
	bool leftButton; //botón izquierdo
	bool rightButton; //botón derecho
	int xcell_sel, ycell_sel; //celda seleccionada con el ratón
public:
	void MovimientoRaton(int x, int y, int button, bool down); // movimiento de ratón
	void ConvCoord(double x, double y, int& cell_x, int& cell_y); // conversión coordenadas a celdas
	void cambiarTurno() { turno = !turno; }
	void dibuja();
	void interaccionJugador();
};