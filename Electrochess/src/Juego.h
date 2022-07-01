#pragma once
#include "Tablero.h"
#include "freeglut.h"

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

class Juego
{
private:
	bool turno = 0; 
	Tablero tablero;
	bool click = 0;
	Coordenadas raton; 
	Coordenadas raton_sel;
public:
	void botonRaton(int x, int y, int button, bool down); 
	void cambiarTurno() { turno = !turno; }
	void dibuja();
	Coordenadas click1();
	void click2(Coordenadas o);
	//bool NoSaltar(Coordenadas origen, Coordenadas destino);
};