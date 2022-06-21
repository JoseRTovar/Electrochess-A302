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

	//Comer(t, j, filain, columnain, filaout, columnaout);
	t.casilla[filaout][columnaout].setPieza(t.casilla[filain][columnain].getPieza(), j.turno_color);
	t.casilla[filain][columnain].setPieza(Pieza::NO_PIEZA);
	//JaqueMate(t, filain, columnain, filaout, columnaout);


}

//Para futuras intervenciones:
void Interaccion::JaqueMate(Tablero& t, int filai, int columnai, int filao, int columnao) {


	for (int fila = 0; fila < 8; fila++)
	{
		for (int columna = 0; columna < 8; columna++)
		{
			if (t.casilla[filai][columnai].getPieza() != Pieza::REY) {
				t.casilla[fila][columna].setPieza(Pieza::NO_PIEZA);
			}
		}
	}
}


//HAY QUE ACABAR DE HACERLA BIEN
//NO ENCUENTRO EL FALLO -> QUIERO QUE RECORRA TODAS LAS CASILLAS Y QUE ME INVALIDE EL MOVIMIENTO A LA CASILLA DE DESTINO CUANDO HAY DE SU MISMO COLOR ENTRE MEDIAS
void Interaccion::Comer(Tablero& t, Juego juego, int filai, int columnai, int filao, int columnao) {

	for (int fila = 0; fila < 8; fila++)
	{
		for (int columna = 0; columna < 8; columna++)
		{
			if (t.casilla[fila][columna].getColor() == juego.turno_color) {
				fila = filao;
				columna = columnao;
				t.casilla[filai][columnai].getValidmove(filao, columnao) == false;
			}
		}
	}

}