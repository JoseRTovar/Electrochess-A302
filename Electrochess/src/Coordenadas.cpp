#include "Coordenadas.h"

bool Coordenadas::movLineal(Coordenadas origen, Coordenadas destino)
{
	if ((destino.fila != origen.fila && destino.columna == origen.columna) || (destino.columna != origen.columna && destino.fila == origen.fila)) return true;
	return false;
}

bool Coordenadas::movDiagonal(Coordenadas origen, Coordenadas destino)
{
	if (((abs(destino.fila - origen.fila) + abs(destino.columna - origen.columna)) % 2 == 0) && (abs(destino.fila - origen.fila) == abs(destino.columna - origen.columna))) return true;
	return false;
}

bool Coordenadas::movUnitario(Coordenadas origen, Coordenadas destino)
{
	if (abs(destino.fila - origen.fila) <= 1 && abs(destino.columna - origen.columna) <= 1) return true;
	return false;
}

bool Coordenadas::movCaballo(Coordenadas origen, Coordenadas destino)
{
	if (((abs(destino.fila - origen.fila) == 1) && (abs(destino.columna - origen.columna) == 2)) || ((abs(destino.fila - origen.fila) == 2) && (abs(destino.columna - origen.columna) == 1))) return true;
	return false;
}

bool Coordenadas::movPeon_b(Coordenadas origen, Coordenadas destino)
{
	if (destino.fila == origen.fila + 1 && destino.columna == origen.columna) return true;
	return false;
}

bool Coordenadas::movPeon_n(Coordenadas origen, Coordenadas destino)
{
	if (destino.fila == origen.fila - 1 && destino.columna == origen.columna) return true;
	return false;
}

bool Coordenadas::comePeon_b(Coordenadas origen, Coordenadas destino)
{
	if ((abs(destino.columna - origen.columna) == 1) && (destino.fila == origen.fila + 1)) return true;
	return false;
}

bool Coordenadas::comePeon_n(Coordenadas origen, Coordenadas destino)
{
	if ((abs(destino.columna - origen.columna) == 1) && (destino.fila == origen.fila - 1)) return true;
	return false;
}

bool Coordenadas::primerMovePeon_b(Coordenadas origen, Coordenadas destino)
{
	if (destino.fila == origen.fila + 2 && destino.columna == origen.columna) return true;
	return false;
}

bool Coordenadas::primerMovePeon_n(Coordenadas origen, Coordenadas destino)
{
	if (destino.fila == origen.fila - 2 && destino.columna == origen.columna) return true;
	return false;
}

bool Coordenadas::fueraTablero(Coordenadas c)
{
	if (c.fila > 7 || c.fila < 0 || c.columna > 7 || c.columna < 0) return true;
	return false;
}