#include "Tablero.h"
#include "freeglut.h"
#include <math.h>

void Tablero::inicializa()
{
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;
	casilla = new Casilla * [N_FIL];
	for (int fila = 0; fila < N_FIL; fila++)
	{
		casilla[fila] = new Casilla[N_COL];
		for (int columna = 0; columna < N_COL; columna++)
		{
			casilla[fila][columna].setPosicion(fila, columna);
			if ((fila + columna) % 2 == 0)
				casilla[fila][columna].setColor(NEGRO);
			else
				casilla[fila][columna].setColor(BLANCO);
		}
	}
}

void Tablero::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	for (int fila = 0; fila < N_FIL; fila++)
	{
		for (int columna = 0; columna < N_COL; columna++)
		{
			casilla[fila][columna].dibuja();
		}
	}
}

void Tablero::tecla(unsigned char key)
{

}

void Tablero::mueve()
{

}

void Tablero::rotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}
