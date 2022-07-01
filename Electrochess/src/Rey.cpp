#include "Rey.h"
#include "Tablero.h"

bool Rey::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::Movdeunoenuno(origen, destino) == true)
	{
		return Pieza::validmove(origen, destino, tablero);
	}
	return false;
}