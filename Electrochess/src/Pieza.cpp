#pragma once
#include "Pieza.h"

 bool Pieza::validmove(int fo, int co, int fd, int cd) {

	 //No se salga del tablero (Esto no haría falta si usamos el ratón?
	 if ((fd > 7 || fd < 0) && (cd > 7 || cd < 0))
	 {
		 return false;
	 }
	 //Falta función para no saltar las piezas amigas
	 return true;
 }


