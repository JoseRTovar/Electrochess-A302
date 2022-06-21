#include "Interaccion.h"
#include <iostream>
using namespace std;

void Interaccion::mueve(Tablero& t, Juego j)
{
	int filain, columnain;
	int filaout, columnaout;
	do
	{
		cout << "Posicion a jugar: " << endl;
		cin >> filain >> columnain;
		if (t.casilla[filain][columnain].getPieza() == Pieza::NO_PIEZA) cout << "Casilla vacia" << endl;
		else if (t.casilla[filain][columnain].getColor() != j.turno_color) cout << "No es su turno" << endl;
	} while (t.casilla[filain][columnain].getPieza() == Pieza::NO_PIEZA || t.casilla[filain][columnain].getColor() != j.turno_color);

	cout << t.casilla[filain][columnain].getFilapieza() << " , " << t.casilla[filain][columnain].getColumnapieza() << endl;
	do
	{
		cout << "Posicion donde juega: " << endl;
		cin >> filaout >> columnaout;
		if (t.casilla[filaout][columnaout].getColor() == j.turno_color) cout << "Ahi hay una pieza de tu mismo color" << endl;
		else if (t.casilla[filain][columnain].getValidmove(filaout, columnaout) == false) cout << "No es un movimiento valido" << endl;
	} while (t.casilla[filaout][columnaout].getColor() == j.turno_color || t.casilla[filain][columnain].getValidmove(filaout, columnaout) == false);

	t.casilla[filaout][columnaout].setPieza(t.casilla[filain][columnain].getPieza(), j.turno_color);
	t.casilla[filain][columnain].setPieza(Pieza::NO_PIEZA);
	j.cambiarTurno();
}