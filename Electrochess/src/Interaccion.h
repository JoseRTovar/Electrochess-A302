#pragma once
#include "Rey.h"
#include "Tablero.h"

class Juego
{
public:
	Pieza::color_t turno_color = Pieza::BLANCA;
public:
	Juego() {}
	void cambiarTurno() { turno_color = (Pieza::color_t)!turno_color; }
};

class Interaccion
{
public:
	static void mueve(Tablero& t, Juego j);
	static void JaqueMate(Tablero& t, int filai, int columnai, int filao, int columnao);
	static void Comer(Tablero& t, Juego juego, int filai, int columnai, int filao, int columnao);
};
