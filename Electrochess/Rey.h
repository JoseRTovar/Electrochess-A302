#pragma once
#include "src/Pieza.h"
#define n 2;

class Rey : public Pieza {
public:
	//hereda casilla y color de la clase pieza
	static const int CAPACITY = n;
	int num = 0;

	Rey* listaReyes[CAPACITY];

public:
	
	Rey(Casilla casilla, color color) : Pieza(casilla, color){
	
		for (int i = 0; i < CAPACITY; i++) { listaReyes[i] = NULL; }

	}

	Rey() {};  //Necesario para poder crear un rey en clase tablero
	
	void inicializa();
	//void dibuja();

	virtual void setPosicion(color color) {
		if (color == BLANCAS) {
			setCasilla(7.0, 5.0);
			setColor(255, 255, 255);  //Clase heredada de Pieza -> se aprovecha
		}
		else if (color == NEGRAS) {
			setCasilla(0.0, 5.0);
			setColor(0, 0, 0);        //Clase heredada de Pieza -> se aprovecha
		}
	}

	virtual void dibuja();

	//De momento no se usa
	
	//Si ej Ajedrez.cpp meto la lista de Reyes en vez de Rey da problemas este método

	void agregar(Rey* p)
	{
		if (num < CAPACITY) {
			listaReyes[num] = p;
		}
		num++;
	}
	
	
};
