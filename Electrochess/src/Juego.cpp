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

	/*	glColor3ub(250, 255, 180);
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);//start drawing a line loop
		glVertex3d(0, 0, 0);//left of window
		glVertex3d(1,0,0);//bottom of window
		glVertex3d(1,1,0);//right of window
		glVertex3d(0,1,0);//top of window
		glEnd();//end drawing of line loop*/

		click = 1;
	}
	return c;
}

void Juego::click2(Coordenadas o)
{
	Coordenadas d = raton;

	if (tablero[d] != nullptr && tablero[d]->getColor() == (Pieza::color_t)turno)
		cout << "Pieza del mismo color" << endl;

	else if (tablero[o]->validmove(o, d) == true && NoSaltar(o,d) == true)
	{
		cout << "(" << o.fila << "," << o.columna << ")" << " -> " << "(" << d.fila << "," << d.columna << ")" << endl;
		click = 0;
		tablero.MoverPieza(o, d);
		cambiarTurno();
	}
}

bool Juego::NoSaltar(Coordenadas origen, Coordenadas destino) {

	int aux;

	//ARRIBA ABAJO
	if (destino.fila != origen.fila && destino.columna == origen.columna)
	{
		aux = (destino.fila - origen.fila) / abs(destino.fila - origen.fila);
		while (abs(destino.fila - origen.fila) > 1)
		{
			origen.fila = origen.fila + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//DERECHA E IZQUIERDA
	else if (destino.columna != origen.columna && destino.fila == origen.fila)
	{
		aux = (destino.columna - origen.columna) / abs(destino.columna - origen.columna);
		while (abs(destino.columna - origen.columna) > 1)
		{
			origen.columna = origen.columna + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//DIAGONAL IZQ -> DCHA ARRIBA Y ABAJO
	else if ((destino.columna-origen.columna==destino.fila-origen.fila) && destino.columna != origen.columna && destino.fila != origen.fila)
	{
		aux = (destino.columna - origen.columna) / abs(destino.columna - origen.columna);
		while (abs(destino.columna - origen.columna) > 1)
		{
			origen.columna = origen.columna + aux;
			origen.fila = origen.fila + aux;
			if (tablero[origen] != nullptr) return false;
		}
	}

	//DIAGONAL DCHA -> IZQ
	else if (destino.columna != origen.columna && destino.fila != origen.fila)
	{
		aux = (destino.columna - origen.columna) / abs(destino.columna - origen.columna);
		while (abs(destino.columna - origen.columna) > 1)
		{
			origen.columna = origen.columna + aux;
			origen.fila = origen.fila - aux;
			if (tablero[origen] != nullptr) return false;
		}
	}
	return true;
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