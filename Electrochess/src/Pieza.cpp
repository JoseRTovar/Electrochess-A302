#pragma once
#include "Pieza.h"


Pieza::color_t Pieza::getColor() {
	//if (color == nullptr) return Pieza::NO_COLOR; -> PROBLEMON
	if (nullptr) return Pieza::NO_COLOR; //HAY QUE ARREGLARLO
	return color;
}

Pieza::pieza_t Pieza::getPieza() {
	if (nullptr) return Pieza::NO_PIEZA;
	//if (pieza == NO_PIEZA) return nullptr;
	return pieza; 
}

 bool Pieza::validmove(int fo, int co, int fd, int cd) {

	 if ((fd > 7 || fd < 0) || (cd > 7 || cd < 0))
	 {
		 return false;
	 }
	 //Falta función para no saltar las piezas amigas

	 return true;
 }


