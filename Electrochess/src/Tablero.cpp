#include "Tablero.h"
#include "freeglut.h"

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

Tablero::Tablero()
{
	for (int fila = 0; fila < N_FILAS; fila++)
	{
		for (int columna = 0; columna < N_COLUMNAS; columna++)
		{
			tab[fila][columna] = nullptr;
		}
	}
	tab[0][4] = new Rey(Pieza::BLANCA);
	tab[7][4] = new Rey(Pieza::NEGRA);
	tab[0][0] = new Torre(Pieza::BLANCA);
	tab[0][7] = new Torre(Pieza::BLANCA);
	tab[7][0] = new Torre(Pieza::NEGRA);
	tab[7][7] = new Torre(Pieza::NEGRA);
	tab[0][2] = new Alfil(Pieza::BLANCA);
	tab[0][5] = new Alfil(Pieza::BLANCA);
	tab[7][2] = new Alfil(Pieza::NEGRA);
	tab[7][5] = new Alfil(Pieza::NEGRA);
	tab[0][3] = new Reina(Pieza::BLANCA);
	tab[7][3] = new Reina(Pieza::NEGRA);

}

void Tablero::MoverPieza(Coordenadas origen, Coordenadas destino)
{
	int sizecomidas = 0;

	if (tab[destino.fila][destino.columna] != nullptr) {
		Comidas[sizecomidas++] = tab[destino.fila][destino.columna];
		cout << "Has comido el tipo de pieza:" << tab[destino.fila][destino.columna]->getPieza() << endl;
		//Dibujar 
	}

	tab[destino.fila][destino.columna]= tab[origen.getFila()][origen.getColumna()];

	tab[origen.fila][origen.columna] = nullptr; 
	//esto habia dicho el profe que no no?? no me acuerdo bien de como ha dicho que moviesemos sin borrarla en cuanto a dibujo
}

void Tablero::dibuja()
{
	gluLookAt(4, 4, 15,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

	for (int fila = 0; fila < N_FILAS; fila++)
	{
		for (int columna = 0; columna < N_COLUMNAS; columna++)
		{
			if (tab[fila][columna] != nullptr)
			{
				glTranslatef(columna + 0.5, fila + 0.5, 0);
				tab[fila][columna]->dibuja();
				glTranslatef(-columna - 0.5, -fila - 0.5, 0);
			}

			glDisable(GL_LIGHTING);
			if ((fila + columna) % 2 == 0) glColor3ub(100, 100, 100);
			else glColor3ub(255, 255, 255);
			glBegin(GL_POLYGON);
			glVertex3d(columna, fila, 0.0);
			glVertex3d(columna + 1.0, fila, 0.0);
			glVertex3d(columna + 1.0, fila + 1.0, 0.0);
			glVertex3d(columna, fila + 1.0, 0.0);
			glEnd();
			glEnable(GL_LIGHTING);

		}
	}
}

void Tablero::MovimientoRaton(int x, int y, int button, bool down) {
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

	ConvCoord(posX, posY, xcell_sel, ycell_sel);

	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;

	//escribe las coordenadas de la celda donde está el ratón
	if (down)
		cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;

}

void Tablero::ConvCoord(double x, double y, int& cell_x, int& cell_y)
{
	cell_x = (int)(abs(y));
	cell_y = (int)(x);
}

void Tablero::click()
{
	Coordenadas origen, destino;
	bool error;

	do
	{
		error = 0;
		cout << "Posicion de origen: " << endl;
		cin >> origen.fila >> origen.columna;

		if (origen.fila > 7 || origen.fila < 0 || origen.columna > 7 || origen.columna < 0)
		{
			cout << "FUERA DEL TABLERO" << endl;
			error = 1;
		}
		else if (tab[origen.fila][origen.columna] == nullptr)
		{
			cout << "CASILLA VACIA" << endl;
			error = 1;
		}
		else if (tab[origen.fila][origen.columna]->getColor() != (Pieza::color_t)turno)
		{
			cout << "NO ES SU TURNO" << endl;
			error = 1;
		}
	} while (error == 1);

	do
	{
		error = 0;
		cout << "Posicion de destino: " << endl;
		cin >> destino.fila >> destino.columna;

		if (destino.fila > 7 || destino.fila < 0 || destino.columna > 7 || destino.columna < 0)
		{
			cout << "FUERA DEL TABLERO" << endl;
			error = 1;
		}
		else if (tab[origen.fila][origen.columna]->validmove(origen,destino) == false)
		{
			cout << "MOVIMIENTO NO VALIDO" << endl;
			error = 1;
		}

		else if (tab[destino.fila][destino.columna] != nullptr)
		{
			if (tab[destino.fila][destino.columna]->getColor() == (Pieza::color_t)turno)
			{
				cout << "ESTA PIEZA ES DE TU PROPIO TEAM:" << (Pieza::color_t)turno << endl;
				error = 1;
			}
		
			else if (tab[destino.fila][destino.columna]->getPieza() == Pieza::REY) {
				cout << "JAQUE" << endl;
				error = 1;
			}
			else if (tab[destino.fila][destino.columna]->getColor() == (Pieza::color_t)!turno)
				cout << "FICHA COMIDA" << endl;
		}
	} while (error == 1);

	MoverPieza(origen,destino);
	cambiarTurno();

}

