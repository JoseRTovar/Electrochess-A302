#pragma once
#include "Casilla.h"
#include "freeglut.h"


enum color { BLANCAS = 0, NEGRAS = 1 };


class Pieza
{
protected:
	Casilla casilla;
	color _color;
protected:
	//Necesarios los tres constructures
	Pieza() {};


	//Se debe comprimir estos dos constructores en uno mas adelante
	Pieza(Casilla casilla,color color):casilla(casilla),_color(color) {}

	Pieza(double fila, double columna);
public:
	void setCasilla(double fila, double columna);
	

	//Dibujar el color con la escala RGB
	void setColor(unsigned char rojo, unsigned char verde, unsigned char azul) {
		glColor3ub(rojo, verde, azul);
	}

	//Color de la pieza (Blanca o negra)
	void setColor(color color) {
		_color = color;
	}

	/*double getColumna() {
		return casilla.columna;
	}

	double getFila() {
		return casilla.fila;
	}*/

	//POLIMORFISMO -> VIRTUAL BASE
	
	virtual void setPosicion(color color) = 0;

	virtual void dibuja() = 0;

};

