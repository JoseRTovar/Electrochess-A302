#include "Tablero.h"
#include "Juego.h"

//CONSTRUCTOR DEL TABLERO -> Se posicionan todas las piezas sobre el tablero y se contruyte el array de piezas y piezas comidas
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
	tab[0][1] = new Caballo(Pieza::BLANCA);
	tab[0][6] = new Caballo(Pieza::BLANCA);
	tab[7][1] = new Caballo(Pieza::NEGRA);
	tab[7][6] = new Caballo(Pieza::NEGRA);
	for (int i = 0; i < 8; i++)
	{
		tab[1][i] = new Peon(Pieza::BLANCA);
		tab[6][i] = new Peon(Pieza::NEGRA);
	}
	for (int i = 0; i < 30; i++)
	{
		Comidas[i] = nullptr;
	}

}

//Metodo que elimina todas las piezas del tablero
void Tablero::cleanTablero()
{
	for (int fila = 0; fila < N_FILAS; fila++)
	{
		for (int columna = 0; columna < N_COLUMNAS; columna++)
		{
			tab[fila][columna] = nullptr;
		}
	}
}

//Metodo encargado del movimiento de las piezas del tablero
void Tablero::cambiarEstado(Coordenadas origen, Coordenadas destino)
{
	//PIEZAS COMIDAS
	if (tab[destino.fila][destino.columna] != nullptr)
	{
		Comidas[SizeComidas++] = tab[destino.fila][destino.columna];
	}

	//CORONACION DE LOS PEONES
	if ((destino.fila == 7 || destino.fila == 0) && tab[origen.fila][origen.columna]->getPieza() == Pieza::PEON)
		coronacion(origen, destino);
	
	//CAMBIAR ESTADO NORMAL 
	else
		movEstado(origen, destino);

}

//Cambiar el estado del tablero 
void Tablero::movEstado(Coordenadas origen, Coordenadas destino) 
{
	tab[destino.fila][destino.columna] = tab[origen.fila][origen.columna];
	tab[origen.fila][origen.columna] = nullptr;
}

//MOVIMIENTO ESPECIAL CON POSIBILIDAD DE SELECCION DE PIEZA -> CORONACION DE LOS PEONES
void Tablero::coronacion(Coordenadas origen, Coordenadas destino)
{
	int pieza;

	cout << "Por que pieza quiere cambiar su peon: " << endl;
	cout << "Torre(1)" << endl;
	cout << "Alfil(2)" << endl;
	cout << "Reina(3)" << endl;
	cout << "Caballo(4)" << endl;
	cin >> pieza;

	switch (pieza) {
	case 1:
		if (tab[origen.fila][origen.columna]->getColor() == Pieza::BLANCA)
		{
			tab[destino.fila][destino.columna] = new Torre(Pieza::BLANCA);
		}
		else  tab[destino.fila][destino.columna] = new Torre(Pieza::NEGRA);
		cout << "Torre nueva" << endl;
		break;
	case 2:
		if (tab[origen.fila][origen.columna]->getColor() == Pieza::BLANCA)
		{
			tab[destino.fila][destino.columna] = new Alfil(Pieza::BLANCA);
		}
		else tab[destino.fila][destino.columna] = new Alfil(Pieza::NEGRA);
		cout << "Alfil nuevo" << endl;
		break;
	case 3:
		if (tab[origen.fila][origen.columna]->getColor() == Pieza::BLANCA)
		{
		tab[destino.fila][destino.columna] = new Reina(Pieza::BLANCA);
		}
		else tab[destino.fila][destino.columna] = new Reina(Pieza::NEGRA);
		cout << "Reina nueva" << endl;
		break;
	case 4:
		if (tab[origen.fila][origen.columna]->getColor() == Pieza::BLANCA)
		{
			tab[destino.fila][destino.columna] = new Caballo(Pieza::BLANCA);
		}
		else tab[destino.fila][destino.columna] = new Caballo(Pieza::NEGRA);
		cout << "Caballo nuevo" << endl;
		break;
	}
	tab[origen.fila][origen.columna] = nullptr;

}

//METODO DE DIBUJO 
void Tablero::dibuja(Juego& juego)
{
	//Dibuja de un color verde las casillas a las que es posible mover la pieza seleccionada
	for (int i = 0; i < juego.getLegalMoves(); i++)
	{
		if ((juego[i]->fila + juego[i]->columna) % 2 == 0)  glColor3ub(50, 150, 50);
		else glColor3ub(100, 200, 100);
		glBegin(GL_POLYGON);
		glVertex3d(juego[i]->columna, juego[i]->fila, 0.0);
		glVertex3d(juego[i]->columna + 1.0, juego[i]->fila, 0.0);
		glVertex3d(juego[i]->columna + 1.0, juego[i]->fila + 1.0, 0.0);
		glVertex3d(juego[i]->columna, juego[i]->fila + 1.0, 0.0);
		glEnd();
		glEnable(GL_LIGHTING);
	}

	//Dibuja el tablero por completo
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

	//Dibuja las piezas comidas
	int ColumnaB = -1, ColumnaN = 9, Columna = 0;
	int FilaB = N_FILAS-1, FilaN = N_FILAS-1, Fila = N_FILAS-1;
	int blancas = 0, negras = 0;
	for (int i = 0;i < 30;i++) {
		if (Comidas[i] != nullptr) {
			if (Comidas[i]->getColor() == Pieza::BLANCA) {
				if (blancas == N_FILAS) {
					FilaB = N_FILAS-1;
					ColumnaB = -2;
				}
				Fila = FilaB--;
				Columna = ColumnaB;
				blancas++;
			}
			else {
				if (negras == N_FILAS) {
					FilaN = N_FILAS-1;
					ColumnaN = 10;
				}
				Fila = FilaN--;
				Columna = ColumnaN;
				negras++;
			}
			glTranslatef(Columna, Fila, 0);
			Comidas[i]->dibuja();
			glTranslatef(-Columna, -Fila, 0);
		}
	}
	//Dibuja el fondo de la pantalla
	fondo.setCenter(3.6, 1.45);
	fondo.setSize(14.9, 11.175);
	fondo.draw();
}

