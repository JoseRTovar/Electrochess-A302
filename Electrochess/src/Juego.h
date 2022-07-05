#pragma once
#include "Tablero.h"
#include "freeglut.h"
#define MAX_MOVES 27

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

class Juego
{
public:
	enum jaque_t { NO_JAQUE = -1, JAQUE_B, JAQUE_N };
private:
	Tablero tablero;
	bool turno;
	jaque_t jaque;
	Coordenadas* legalmoves[MAX_MOVES];
	int nlegalmoves;
	bool click;
	Coordenadas raton;
	Coordenadas raton_sel;
public:
	Juego() :
		turno(0),
		jaque(NO_JAQUE),
		click(0),
		nlegalmoves(0)
	{
		for (int i = 0; i < MAX_MOVES; i++)
			legalmoves[i] = nullptr;
	}
	Coordenadas click0();
	void click1(Coordenadas o);
	void botonRaton(int x, int y, int button, bool down);
	void cambiarTurno() { turno = !turno; }
	jaque_t checkJaque(Tablero tablero);
	void Calclegalmoves(Coordenadas o);
	void vaciarlegalmoves()
	{
		for (int i = 0; i < nlegalmoves; i++)
		{
			delete legalmoves[i];
			legalmoves[i] = nullptr;
		}
		nlegalmoves = 0;
	}
	Coordenadas* operator[](int pos) const { return legalmoves[pos]; }
	int getlegalmoves() { return nlegalmoves; }
	void dibuja();
};