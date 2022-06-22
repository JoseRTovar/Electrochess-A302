//#include "Interaccion.h"
//#include <iostream>
//using namespace std;
//
//void Interaccion::mueve(Tablero& t, Juego j)
//{
//	int filain, columnain;
//	int filaout, columnaout;
//	do
//	{
//		cout << "Posicion a jugar: " << endl;
//		cin >> filain >> columnain;
//		if (t.casilla[filain][columnain].getPieza() == Pieza::NO_PIEZA) cout << "Casilla vacia" << endl;
//		else if (t.casilla[filain][columnain].getColor() != j.turno_color) cout << "No es su turno" << endl;
//	} while (t.casilla[filain][columnain].getPieza() == Pieza::NO_PIEZA || t.casilla[filain][columnain].getColor() != j.turno_color);
//
//	cout << t.casilla[filain][columnain].getFilapieza() << " , " << t.casilla[filain][columnain].getColumnapieza() << endl;
//	do
//	{
//		cout << "Posicion donde juega: " << endl;
//		cin >> filaout >> columnaout;
//		if (t.casilla[filaout][columnaout].getColor() == j.turno_color) cout << "Ahi hay una pieza de tu mismo color" << endl;
//		else if (t.casilla[filain][columnain].getValidmove(filaout, columnaout) == false) cout << "No es un movimiento valido" << endl;
//	} while (t.casilla[filaout][columnaout].getColor() == j.turno_color || t.casilla[filain][columnain].getValidmove(filaout, columnaout) == false);
//
//	NoSaltar(t, j, filain, columnain, filaout, columnaout);
//	JaqueMate(t, filaout, columnaout);
//	t.casilla[filaout][columnaout].setPieza(t.casilla[filain][columnain].getPieza(), j.turno_color);
//	t.casilla[filain][columnain].setPieza(Pieza::NO_PIEZA);
//	//JaqueMate(t, filaout, columnaout);
//
//
//}
//
//
////HAY QUE ACABAR DE HACERLA BIEN
////NO ENCUENTRO EL FALLO -> QUIERO QUE RECORRA TODAS LAS CASILLAS Y QUE ME INVALIDE EL MOVIMIENTO A LA CASILLA DE DESTINO CUANDO HAY DE SU MISMO COLOR ENTRE MEDIAS
//void Interaccion::NoSaltar(Tablero& t, Juego juego, int filai, int columnai, int filao, int columnao) {
//
//	//Recorre filas y no las salta
//	if(filai != filao){
//		for (int i = filai + 1; i < filao + 1 ; i++) {
//			if ((t.casilla[i][columnai].getColor() == juego.turno_color)) {
//				t.casilla[filai][columnai].getValidmove(filao, columnao) == false;
//			}
//		}
//	}
//
//	if (columnai != columnao) {
//		for (int i = columnai + 1; i < columnao + 1; i++) {
//			if (t.casilla[filai][i].getColor() == juego.turno_color) {
//				t.casilla[filai][columnai].getValidmove(filao, columnao) == false;
//			}
//		}
//	}
//
//}
//
//void Interaccion::JaqueMate(Tablero& t, int filaout, int columnaout) {
//
//	if (t.casilla[filaout][columnaout].getPieza() == Pieza::REY) {
//	for (int fila = 0; fila < 8; fila++)
//	{
//		for (int columna = 0; columna < 8; columna++)
//		{
//			
//				t.casilla[fila][columna].setPieza(Pieza::NO_PIEZA);
//			
//		}
//	}
//	
//	cout << "Game Over, rey comido";
//	}
//}