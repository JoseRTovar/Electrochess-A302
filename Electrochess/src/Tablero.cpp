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
	inicializa();
}

void Tablero::inicializa()
{
	
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
	case Pieza::NO_PIEZA:
		delete tab[fd][cd];
		//case Pieza::ALFIL:
		//	tab[fd][cd] = new Alfil(posicion, c);
		//	break;
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


		}
	}

	for (int fila = 0; fila < N_FILAS; fila++)
	{
		for (int columna = 0; columna < N_COLUMNAS; columna++)
		{
			if (tab[fila][columna] != nullptr)
			{
				glTranslatef(columna + 0.5, fila + 0.5, 0);
				tab[fila][columna]->dibuja();
				glTranslatef(-columna - 0.5, - fila - 0.5, 0);
			}
		}
	}
}

void Tablero::click() {

		int fi, ci, fo, co;

		cout << "Posicion de origen: " << endl;
		cin >> fi >> ci;
		cout << "Posicion de destino: " << endl;
		cin >> fo >> co;

		/*
		do {
				cout << "Posicion de origen: " << endl;
				cin >> fi >> ci;
				cout << "Posicion de destino: " << endl;
				cin >> fo >> co;

				if((tab[fi][ci]->validmove(fi, ci, fo, co) == false))
					cout << "Movimiento no valido" << endl;

		} while ((tab[fi][ci]->validmove(fi, ci, fo, co) == false));*/
		
		Pieza::pieza_t tipo = tab[fi][ci]->getPieza();
		Pieza::color_t color = tab[fi][ci]->getColor();

		do{
		cambiarEstado(fi, ci, fo, co, tipo, color);
		} while ((tab[fi][ci]->validmove(fi, ci, fo, co) == true));

}