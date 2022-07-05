#pragma once
#include "Tablero.h"
#include "freeglut.h"
#define MAX_MOVES 27

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

class Juego
{
private:
	Tablero tablero;
	bool turno;
	bool jaque;
	Coordenadas* legalmoves[MAX_MOVES];
	int nlegalmoves;
	bool click;
	Coordenadas raton;
	Coordenadas raton_sel;
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
	void vaciarLegalMoves()
	{
		for (int i = 0; i < nlegalmoves; i++)
		{
			delete legalmoves[i];
			legalmoves[i] = nullptr;
		}
		nlegalmoves = 0;
	}
	Coordenadas* operator[](int pos) const { return legalmoves[pos]; }
	int getLegalMoves() { return nlegalmoves; }
	bool checkJaqueMate(Pieza::Color_e color);
	void dibuja();
};