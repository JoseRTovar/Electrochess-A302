#include "Coordenadas.h"

const bool Coordenadas::MovDiagonal(Coordenadas origen, Coordenadas destino) {
	if (((abs(destino.fila - origen.fila) + abs(destino.columna - origen.columna)) % 2 == 0) && (abs(destino.fila - origen.fila) == abs(destino.columna - origen.columna))) return true;
	return false;
}

const bool Coordenadas::MovLineal(Coordenadas origen, Coordenadas destino) {
	if ((destino.fila != origen.fila && destino.columna == origen.columna) || (destino.columna != origen.columna && destino.fila == origen.fila)) return true;
	return false;
}

const bool Coordenadas::Movdeunoenuno(Coordenadas origen, Coordenadas destino){
	if (abs(destino.fila - origen.fila) <= 1 && abs(destino.columna - origen.columna) <= 1) return true;
	return false;
}

const bool Coordenadas::FueraTablero(Coordenadas c){
	if (c.fila > 7 || c.fila < 0 || c.columna > 7 || c.columna < 0) return true;
	return false;
}

const bool Coordenadas::MovCaballo(Coordenadas origen, Coordenadas destino) {
	if (((abs(destino.fila - origen.fila) == 1) && (abs(destino.columna - origen.columna) == 2)) || ((abs(destino.fila - origen.fila) == 2) && (abs(destino.columna - origen.columna) == 1))) return true;
	return false;
}