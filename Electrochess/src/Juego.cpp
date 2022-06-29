#include "Juego.h"
#include "freeglut.h"

void Juego::MovimientoRaton(int x, int y, int button, bool down)
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

	ConvCoord(posX, posY, xcell_sel, ycell_sel);

	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;

	//escribe las coordenadas de la celda donde está el ratón
	if (down) {
		if (xcell_sel > 7 || xcell_sel < 0 || ycell_sel > 7 || ycell_sel < 0)
		{
			cout << "FUERA DEL TABLERO" << endl;
		}
		else {
			cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;
		}
	}
}

void Juego::ConvCoord(double x, double y, int& cell_x, int& cell_y)
{
	cell_x = (int)(abs(y));
	cell_y = (int)(x);
}

void Juego::interaccionJugador()
{
	//Aquí es donde habría que pedir las coordenadas, llamar al validmove, cambiar el turno etc.

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

	tablero.dibuja();
}