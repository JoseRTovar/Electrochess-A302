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
		calcLegalMoves(c);
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

	if (find == true)
	{
		cout << "(" << o.fila << "," << o.columna << ")" << " -> " << "(" << d.fila << "," << d.columna << ")" << endl;
		tablero.cambiarEstado(o, d);

		//Comprobaciones y acciones que se realizan al cambiar el estado de tablero
		jaque = checkJaque(tablero);
		cout << jaque << endl;
		vaciarLegalMoves();
		cambiarTurno();
		click = 0;
	}

	else
	{
		cout << "Movimiento no valido" << endl;
		vaciarLegalMoves();
		click = 0;
	}
}

Juego::Jaque_e Juego::checkJaque(Tablero& tablero)
{
	//Esta función chequea si alguna de las piezas del equipo que acaba de mover está haciendo jaque al rey
	//enemigo. Para ello, recorre todas las piezas del equipo que acaba de mover y comprueba si algún validmove
	//es la posición en la que se encuentre el rey opuesto. En caso afirmativo, devuelve el jaque, y en caso
	//contrario, devuelve que no hay jaque.
	Coordenadas oaux;
	Coordenadas daux;

	//Estos primeros dos bucles se podrían cambiar por 1 que recorre directamente las piezas del color que toca
	for (oaux.fila = 0; oaux.fila < N_FILAS; oaux.fila++)
	{
		for (oaux.columna = 0; oaux.columna < N_COLUMNAS; oaux.columna++)
		{
			if (tablero[oaux] != nullptr && tablero[oaux]->getColor() == (Pieza::Color_e)turno)
			{
				for (daux.fila = 0; daux.fila < N_FILAS; daux.fila++)
				{
					for (daux.columna = 0; daux.columna < N_COLUMNAS; daux.columna++)
					{
						if (tablero[oaux]->validMove(oaux, daux, tablero) && tablero[daux] != nullptr && tablero[daux]->getPieza() == Pieza::REY)
						{
							return (Jaque_e)!turno;
						}
					}
				}
			}
		}
	}
	return NO_JAQUE;
}

void Juego::calcLegalMoves(Coordenadas o)
{
	//Calculamos los movimientos legales de la pieza situada en la coordenada clicada, y los añadimos al array
	//de movimientos legales. El objetivo es añadir la norma de que un equipo no se puede meter en jaque o de que
	//si hay jaque, solo sean válidos los movimientos que hacen que salgas de él.

	//*********************************************************************************************************
	Coordenadas aux;
	for (aux.fila = 0; aux.fila < N_FILAS; aux.fila++)
	{
		for (aux.columna = 0; aux.columna < N_COLUMNAS; aux.columna++)
		{
			if (tablero[o]->validMove(o, aux, tablero) == true)
			{
				legalmoves[nlegalmoves++] = new Coordenadas(aux.fila, aux.columna);
			}
		}
	}
	//*********************************************************************************************************

	//La idea es que, dadas las coordenadas en las que hemos hecho click, calcular dentro de todos los posibles
	//movimientos de la pieza que esté en esa casilla, los que eviten el jaque. En caso de existir al menos uno,
	//la función devolverá true, pudiendo jugarse esa pieza, y en caso contrario, devolverá false, no permitiendo
	//jugar dicha pieza.

	//**********************************************************************************************************
	//Primero comprobamos los movimientos validos
	//Coordenadas dcomp; //Coordenadas del destino a comprobar
	//for (dcomp.fila = 0; dcomp.fila < N_FILAS; dcomp.fila++)
	//{
	//	for (dcomp.columna = 0; dcomp.columna < N_COLUMNAS; dcomp.columna++)
	//	{
	//		if (tablero[o] != nullptr && tablero[o]->validmove(o, dcomp, tablero) == true)
	//		{
	//			//Aquí habría que realizar el movimiento en una copia del tablero (que luego habria que deshacer?)
	//			tablero.setEstado(c, dcomp);

	//			//Aquí comprobamos si el equipo que hace el jaque sigue haciendo el jaque después de mover
	//			//la pieza (Realiza la comprobación en el tablero copia)
	//			Coordenadas oaux;
	//			Coordenadas daux;
	//			for (oaux.fila = 0; oaux.fila < N_FILAS; oaux.fila++)
	//			{
	//				for (oaux.columna = 0; oaux.columna < N_COLUMNAS; oaux.columna++)
	//				{
	//					if (tablero[oaux] != nullptr && tablero[oaux]->getColor() != (Pieza::color_t)turno)
	//					{
	//						for (daux.fila = 0; daux.fila < N_FILAS; daux.fila++)
	//						{
	//							for (daux.columna = 0; daux.columna < N_COLUMNAS; daux.columna++)
	//							{
	//								if (tablero[oaux]->validmove(oaux, daux, tablero) == true && tablero[daux] != nullptr && tablero[daux]->getPieza() == Pieza::REY)
	//								{
	//									//Sigue el jaque y la posicion vuelve a su sitio
	//									tablero.setEstado(dcomp, c);
	//								}
	//								//evitamos jaque:
	//								else if (tablero[oaux]->validmove(oaux, daux, tablero) == true && tablero[daux] != nullptr && tablero[oaux]->getColor() != (Pieza::color_t)turno && tablero[daux]->getPieza() == Pieza::REY)
	//								{
	//									//tablero[c]->añadiravoidJaque(new Coordenadas(dcomp.fila,dcomp.columna));
	//									cout << "Se ha guardado la coordenada: " << dcomp.fila << " " << dcomp.columna << endl;
	//									tablero.setEstado(dcomp, c);
	//								}
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	//*********************************************************************************************************
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
	tablero.dibuja(*this);
}
