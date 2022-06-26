#include "Tablero.h"
#include "freeglut.h"

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
}

void Tablero::cambiarEstado(int fo, int co, int fd, int cd, Pieza::pieza_t p, Pieza::color_t c)
{
	switch (p)
	{
	case Pieza::REY:
		tab[fd][cd] = new Rey(c);
		break;
	case Pieza::TORRE:
		tab[fd][cd] = new Torre(c);
		break;
	case Pieza::ALFIL:
		tab[fd][cd] = new Alfil(c);
		break;
	}
	tab[fo][co] = nullptr;
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

			if (tab[fila][columna] != nullptr)
			{
				glTranslatef(columna + 0.5, fila + 0.5, 0);
				tab[fila][columna]->dibuja();
				glTranslatef(-columna - 0.5, -fila - 0.5, 0);
			}
		}
	}
}

void Tablero::click()
{
	int fi, ci, fo, co;
	bool error;

	do
	{
		error = 0;
		cout << "Posicion de origen: " << endl;
		cin >> fi >> ci;

		if (fi > 7 || fi < 0 || ci > 7 || ci < 0)
		{
			cout << "FUERA DEL TABLERO" << endl;
			error = 1;
		}
		else if (tab[fi][ci] == nullptr)
		{
			cout << "CASILLA VACIA" << endl;
			error = 1;
		}
		else if (tab[fi][ci]->getColor() != (Pieza::color_t)turno)
		{
			cout << "NO ES SU TURNO" << endl;
			error = 1;
		}
	} while (error == 1);

	do
	{
		error = 0;
		cout << "Posicion de destino: " << endl;
		cin >> fo >> co;

		if (fo > 7 || fo < 0 || co > 7 || co < 0)
		{
			cout << "FUERA DEL TABLERO" << endl;
			error = 1;
		}
		else if (tab[fi][ci]->validmove(fi, ci, fo, co) == false)
		{
			cout << "MOVIMIENTO NO VALIDO" << endl;
			error = 1;
		}
		else if (tab[fo][co] != nullptr)
		{
			if (tab[fo][co]->getColor() == (Pieza::color_t)turno)
			{
				cout << "ESTA PIEZA ES DE TU PROPIO TEAM:" << (Pieza::color_t)turno << endl;
				error = 1;
			}
			else if (tab[fo][co]->getColor() == (Pieza::color_t)!turno)
				cout << "FICHA COMIDA" << endl;
		}
	} while (error == 1);

	cambiarEstado(fi, ci, fo, co, tab[fi][ci]->getPieza(), tab[fi][ci]->getColor());
	cambiarTurno();
}