#include "Coordenadas.h"

//Movimiento recto (Torre y Reina)
bool Coordenadas::movLineal(Coordenadas origen, Coordenadas destino)
{
	if ((destino.fila != origen.fila && destino.columna == origen.columna) || (destino.columna != origen.columna && destino.fila == origen.fila)) return true;
	return false;
}

//Movimiento diagonal (Alfil y Reina)
bool Coordenadas::movDiagonal(Coordenadas origen, Coordenadas destino)
{
	if (((abs(destino.fila - origen.fila) + abs(destino.columna - origen.columna)) % 2 == 0) && (abs(destino.fila - origen.fila) == abs(destino.columna - origen.columna))) return true;
	return false;
}

//Algoritmo matematico para la condicion diagonal del calculo de trayectorias "no saltar"
bool Coordenadas::noSaltarDiag_one(Coordenadas origen, Coordenadas destino)
{
	if ((destino.columna - origen.columna == destino.fila - origen.fila) && destino.columna != origen.columna && destino.fila != origen.fila) return true;
	return false;
}

//Movimiento del Rey
bool Coordenadas::movUnitario(Coordenadas origen, Coordenadas destino)
{
	if (abs(destino.fila - origen.fila) <= 1 && abs(destino.columna - origen.columna) <= 1) return true;
	return false;
}

//Movimiento del Caballo
bool Coordenadas::movCaballo(Coordenadas origen, Coordenadas destino)
{
	if (((abs(destino.fila - origen.fila) == 1) && (abs(destino.columna - origen.columna) == 2)) || ((abs(destino.fila - origen.fila) == 2) && (abs(destino.columna - origen.columna) == 1))) return true;
	return false;
}

//Movimiento Peon blanco
bool Coordenadas::movPeon_b(Coordenadas origen, Coordenadas destino)
{
	if (destino.fila == origen.fila + 1 && destino.columna == origen.columna) return true;
	return false;
}

//Movimiento Peon negro
bool Coordenadas::movPeon_n(Coordenadas origen, Coordenadas destino)
{
	if (destino.fila == origen.fila - 1 && destino.columna == origen.columna) return true;
	return false;
}

//Movimiento para comer de Peon blanco
bool Coordenadas::comePeon_b(Coordenadas origen, Coordenadas destino)
{
	if ((abs(destino.columna - origen.columna) == 1) && (destino.fila == origen.fila + 1)) return true;
	return false;
}

//Movimiento para comer de Peon negro
bool Coordenadas::comePeon_n(Coordenadas origen, Coordenadas destino)
{
	if ((abs(destino.columna - origen.columna) == 1) && (destino.fila == origen.fila - 1)) return true;
	return false;
}

//Primer movimiento de Peon blanco
bool Coordenadas::primerMovePeon_b(Coordenadas origen, Coordenadas destino)
{
	if (destino.fila == origen.fila + 2 && destino.columna == origen.columna) return true;
	return false;
}

//Primer movimiento de Peon negro
bool Coordenadas::primerMovePeon_n(Coordenadas origen, Coordenadas destino)
{
	if (destino.fila == origen.fila - 2 && destino.columna == origen.columna) return true;
	return false;
}

//Coordenadas válidas únicamente dentro del tablero
bool Coordenadas::fueraTablero(Coordenadas c)
{
	if (c.fila > 7 || c.fila < 0 || c.columna > 7 || c.columna < 0) return true;
	return false;
}

ostream& Coordenadas::print(ostream& o)
{
	switch (columna)
	{
	case 0:
		o << "a";
		break;
	case 1:
		o << "b";
		break;
	case 2:
		o << "c";
		break;
	case 3:
		o << "d";
		break;
	case 4:
		o << "e";
		break;
	case 5:
		o << "f";
		break;
	case 6:
		o << "g";
		break;
	case 7:
		o << "h";
		break;
	}
	o << fila + 1;
	return o;
}