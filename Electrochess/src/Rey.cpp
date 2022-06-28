#include "Rey.h"
#include "freeglut.h"

void Rey::dibuja()
{
	reynegro.setCenter(0.4, 0.4);
	reynegro.setSize(0.8, 0.8);
	reyblanco.setCenter(0.4, 0.4);
	reyblanco.setSize(0.8, 0.8);
	if (color == Pieza::NEGRA) reynegro.draw();
	if (color == Pieza::BLANCA) reyblanco.draw();
}

bool Rey::validmove(Coordenadas origen, Coordenadas destino)
{
	if (abs(destino.fila - origen.fila) <= 1 && abs(destino.columna - origen.columna) <= 1) return true;
	return false;
}
