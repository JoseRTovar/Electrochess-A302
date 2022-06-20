#pragma once
#include "Rey.h"
#include "Tablero.h"
#include "Game.h"
//#include "Moves.h"

class Mundo
{
private:
	Tablero tablero;
	Game juego;
	//Moves mover;
	float x_ojo;
	float y_ojo;
	float z_ojo;
public:
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
};