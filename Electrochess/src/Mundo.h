#pragma once
#include "Casilla.h"
#include <iostream>
using namespace std;

class Mundo
{
private:
	Casilla casilla[8][8];
	bool turno = 0;
	float x_ojo;
	float y_ojo;
	float z_ojo;
public:
	void inicializa();
	Coordenadas click1();
	void click2(Coordenadas c);
	void cambiarTurno() { turno = !turno; }
	void dibuja();
};