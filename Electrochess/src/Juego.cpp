#include "Juego.h"

void Juego::dibuja()
{
	gluLookAt(4, 4, 15,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

	Coordenadas coord;
	for (coord.fila = 0; coord.fila < N_FILAS; coord.fila++)
	{
		for (coord.columna = 0; coord.columna < N_COLUMNAS; coord.columna++)
		{
			if (tablero[coord] != nullptr)
			{
				glTranslatef(coord.columna + 0.5, coord.fila + 0.5, 0);
				tablero[coord]->dibuja();
				glTranslatef(-coord.columna - 0.5, -coord.fila - 0.5, 0);
			}
		}
	}
	tablero.dibuja();
}

Coordenadas Juego::click1()
{
	Coordenadas c = raton;


	if (tablero[c] == nullptr)
		cout << "Casilla vacia" << endl;

	else if (tablero[c]->getColor() != (Pieza::color_t)turno)
		cout << "No es tu turno" << endl;

	else
	{
		cout << "Se puede jugar esta pieza" << endl;
		click = 1;
	}

	//Lo que conlleva el jaque vendria aqui

	return c;
}

void Juego::click2(Coordenadas o)
{
	Coordenadas d = raton;

	if (tablero[o]->validmove(o, d, tablero) == false) {
		cout << "Esta pieza no se puede mover -> bloqueo" << endl;
		click = 0;
	}

	if (tablero[o]->validmove(o, d, tablero) == true)
	{
		cout << "(" << o.fila << "," << o.columna << ")" << " -> " << "(" << d.fila << "," << d.columna << ")" << endl;
		click = 0;
		tablero.MoverPieza(o, d);
		checkJaque();
		cambiarTurno();
	}
}

void Juego::checkJaque()
{
	Coordenadas oaux;
	Coordenadas daux;
	for (oaux.fila = 0; oaux.fila < N_FILAS; oaux.fila++)
	{
		for (oaux.columna = 0; oaux.columna < N_COLUMNAS; oaux.columna++)
		{
			if (tablero[oaux] != nullptr && tablero[oaux]->getColor() == (Pieza::color_t)turno)
			{
				for (daux.fila = 0; daux.fila < N_FILAS; daux.fila++)
				{
					for (daux.columna = 0; daux.columna < N_COLUMNAS; daux.columna++)
					{
						if (tablero[oaux]->validmove(oaux, daux, tablero) && tablero[daux] != nullptr && tablero[daux]->getPieza() == Pieza::REY)
						{
							cout << "Jaque" << endl;
							jaque = 1;
						}
					}
				}
			}
		}
	}
}

void Juego::botonRaton(int x, int y, int button, bool down)
{
	// gestiona el control de los botones del ratón
	// convierte de coordenadas generales (mundo) a coordenadas del tablero (celda)

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	raton.fila = (int)(abs(posY));
	raton.columna = (int)(posX);

	//Se podria poner quizas un metodo en coordenadas pa saber si son validas
	if (down)
	{
		if (Coordenadas::FueraTablero(raton) == true) cout << "Fuera del tablero" << endl;

		else if (click == 0) raton_sel = click1();

		else if (click == 1) click2(raton_sel);
	}
}