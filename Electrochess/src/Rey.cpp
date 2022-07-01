#include "Rey.h"
#include "Tablero.h"

void Rey::dibuja()
{
	reynegro.setCenter(0.4, 0.4);
	reynegro.setSize(0.8, 0.8);
	reyblanco.setCenter(0.4, 0.4);
	reyblanco.setSize(0.8, 0.8);
	if (color == Pieza::NEGRA) reynegro.draw();
	if (color == Pieza::BLANCA) reyblanco.draw();
}

bool Rey::validmove(Coordenadas origen, Coordenadas destino, Tablero& tablero)
{
	if (Coordenadas::Movdeunoenuno(origen, destino) == true) {
		Pieza::validmove(origen, destino, tablero);
	}
	return false;
}