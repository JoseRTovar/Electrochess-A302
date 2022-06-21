#pragma once
#include "Rey.h"
#include "Tablero.h"
#include "Interaccion.h"

class Mundo
{
private:
	Tablero tablero;
	Juego juego;
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