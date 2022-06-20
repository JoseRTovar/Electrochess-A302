#include "Mundo.h"
#include <math.h>

void Mundo::inicializa()
{
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;
	tablero.casilla[0][4].setPieza(Pieza::REY, Pieza::BLANCA);
	tablero.casilla[7][4].setPieza(Pieza::REY, Pieza::NEGRA);
	tablero.casilla[0][0].setPieza(Pieza::TORRE, Pieza::BLANCA);
	tablero.casilla[0][7].setPieza(Pieza::TORRE, Pieza::BLANCA);
	tablero.casilla[7][0].setPieza(Pieza::TORRE, Pieza::NEGRA);
	tablero.casilla[7][7].setPieza(Pieza::TORRE, Pieza::NEGRA);
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	tablero.dibuja();
}

void Mundo::tecla(unsigned char key)
{

}

void Mundo::mueve()
{

}

void Mundo::rotarOjo()
{
	double dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	double ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}