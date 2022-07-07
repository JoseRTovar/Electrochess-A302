#pragma once
#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"
#define MAX_MOVES 27

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };
using ETSIDI::Sprite;

//****************************************************************************************************************
// Clase que gestiona todos los acontecimientos del juego. Se trata de una clase superior a tablero y piezas,
// encargada de comunicar al jugador con el tablero. Recibe la información del exterior y se la transmite al
// tablero, siendo este el que presenta toda la información en cada momento del juego.
//****************************************************************************************************************

class Juego
{
private:
	Tablero tablero;
	bool turno, jaque, click;
	Coordenadas* legalmoves[MAX_MOVES];
	int nlegalmoves;
	Coordenadas raton, raton_sel;
	int JaqueMate = 0;
public:
	Juego() : turno(0), jaque(0), click(0), nlegalmoves(0)
	{
		for (int i = 0; i < MAX_MOVES; i++)
			legalmoves[i] = nullptr;
	}
	Coordenadas click0();
	void click1(Coordenadas o);
	void botonRaton(int x, int y, int button, bool down);
	void cambiarTurno() { turno = !turno; }
	bool checkJaque(Tablero& tablero, Pieza::Color_e color);
	void calcLegalMoves(Coordenadas o, Pieza::Color_e color);
	void vaciarLegalMoves();
	Coordenadas* operator[](int pos) const { return legalmoves[pos]; }
	int getLegalMoves() { return nlegalmoves; }
	bool checkJaqueMate(Pieza::Color_e color);
	void dibuja();
};