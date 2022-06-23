#include "Pieza.h"

bool Pieza::validmove(int fo, int co, int fd, int cd, Tablero& t)
{
	//No se salga del tablero (Esto no haría falta si usamos el ratón?
	if ((fd > 7 || fd < 0) && (cd > 7 || cd < 0))
	{
		cout << "Fuera del tablero" << endl;
		return false;
	}
	//Falta función para no saltar las piezas amigas
	t.cambiarEstado(fo, co, fd, cd, pieza, color);
	return true;
}