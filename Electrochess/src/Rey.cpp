#include "Rey.h"
#include "Tablero.h"

//Definicion de movimientos validos unitarios + la definicion comun de Pieza 
bool Rey::validMove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::movUnitario(origen, destino) == true)
		return Pieza::validMove(origen, destino, tablero);

	return false;
}
