#include "Juego.h"

Coordenadas Juego::click0()
{
	Coordenadas c = raton;

	if (tablero[c] == nullptr)
		cout << "Casilla vacia" << endl;

	else if (tablero[c]->getColor() != (Pieza::Color_e)turno)
		cout << "No es tu turno" << endl;

	else
	{
		calcLegalMoves(c, (Pieza::Color_e)turno);
		if (nlegalmoves == 0)
		{
			cout << "No se puede jugar esta pieza " << nlegalmoves << endl;
			vaciarLegalMoves();
			click = 0;
		}

		else
		{
			cout << "Se puede jugar esta pieza " << nlegalmoves << endl;
			click = 1;
		}
	}

	return c;
}

void Juego::click1(Coordenadas o)
{
	Coordenadas d = raton;
	bool find = false;

	for (int i = 0; i < nlegalmoves; i++)
	{
		if (d.fila == legalmoves[i]->fila && d.columna == legalmoves[i]->columna)
			find = true;
	}

	if (tablero[d] != nullptr)
	{
		playMusica("Take.mp3");
		cout << "Pieza comida " << endl;
	}
	else playMusica("Move.mp3");

	if (find == true)
	{
		cout << "(" << o.fila << "," << o.columna << ")" << " -> " << "(" << d.fila << "," << d.columna << ")" << endl;
		tablero.cambiarEstado(o, d);

		//Comprobaciones y acciones que se realizan al cambiar el estado de tablero
		if (checkJaqueMate((Pieza::Color_e)!turno))
		{
			cout << "JAQUE MATE" << endl; //INCLUIR PANTALLA DE JAQUE MATE / GAME OVER
			JaqueMate = 1;
			tablero.cleanTablero(); //Para que no se puedan mover mas piezas
		}
		else
		{
			jaque = checkJaque(tablero, (Pieza::Color_e)!turno);
			if(jaque==1) cout << "JAQUE" << endl; // INCLUIR PANTALLA DE JAQUE
			vaciarLegalMoves();
			cambiarTurno();
			click = 0;
		}
	}
	else
	{
		cout << "Movimiento no valido" << endl;
		vaciarLegalMoves();
		click = 0;
	}

}

bool Juego::checkJaque(Tablero& tablero, Pieza::Color_e color)
{
	for (int f = 0; f < N_FILAS; f++)
	{
		for (int c = 0; c < N_COLUMNAS; c++)
		{
			Coordenadas daux(f, c);
			if (tablero[daux] != nullptr && tablero[daux]->getPieza() == Pieza::REY && tablero[daux]->getColor() == color)
			{
				for (int f = 0; f < N_FILAS; f++)
				{
					for (int c = 0; c < N_COLUMNAS; c++)
					{
						Coordenadas oaux(f, c);
						if (tablero[oaux] != nullptr && tablero[oaux]->getColor() == !color && tablero[oaux]->validMove(oaux, daux, tablero))
							return true;
					}
				}
			}
		}
	}
	return false;
}

bool Juego::checkJaqueMate(Pieza::Color_e color)
{
	vaciarLegalMoves();
	for (int f = 0; f < N_FILAS; f++)
	{
		for (int c = 0; c < N_COLUMNAS; c++)
		{
			Coordenadas oaux(f, c);
			if (tablero[oaux] != nullptr && tablero[oaux]->getColor() == color)
			{
				calcLegalMoves(oaux, color);
				if (nlegalmoves != 0) return false;
			}
		}
	}
	return true;
}

void Juego::calcLegalMoves(Coordenadas o, Pieza::Color_e color)
{
	Pieza* pieza = tablero[o];
	Coordenadas aux;
	for (aux.fila = 0; aux.fila < N_FILAS; aux.fila++)
	{
		for (aux.columna = 0; aux.columna < N_COLUMNAS; aux.columna++)
		{
			if (pieza->validMove(o, aux, tablero) == true)
			{
				Tablero tablero_aux = tablero;
				tablero_aux.cambiarAux(o, aux);
				if (checkJaque(tablero_aux, color) == false)
				{
					legalmoves[nlegalmoves++] = new Coordenadas(aux.fila, aux.columna);
				}
			}
		}
	}
}

void Juego::vaciarLegalMoves()
{
	for (int i = 0; i < nlegalmoves; i++)
	{
		delete legalmoves[i];
		legalmoves[i] = nullptr;
	}
	nlegalmoves = 0;
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
		if (Coordenadas::fueraTablero(raton) == true) cout << "Fuera del tablero" << endl;
		else if (click == 0) raton_sel = click0();
		else if (click == 1) click1(raton_sel);
	}
}

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
	tablero.dibuja(*this,JaqueMate);
}
