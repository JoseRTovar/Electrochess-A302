#include "Alfil.h"
#include "freeglut.h"

void Alfil::dibuja()
{
	if (color == Pieza::NEGRA)  glColor3ub(NEGRO, NEGRO, NEGRO);
	else if (color == Pieza::BLANCA) glColor3ub(BLANCO, BLANCO, BLANCO);
	//glRotatef(45.0, 0.0, 0.0, 1.0);
	glutSolidTorus(0.15, 0.3, 20, 20);

}

bool Alfil::validmove(int fila, int columna)
{
	if ((abs(((fila + columna) - ((this->fila) + (this->columna))) >= 0) || (((fila + columna) - ((this->fila) + (this->columna))) == 2) && ((tableroinmove(fila, columna) != false)))) return true;
	return false;

}

//if ((abs(((fila + columna) - ((this->fila) + (this->columna))) >= 0) || (((fila + columna) - ((this->fila) + (this->columna))) == 2) && ((tableroinmove(fila, columna) != false)))) return true;

/*
//DIAGONAL ARRIBA IZQUIERDA
		case't':
			casilla.setPosicion(casilla.fila + 1.0, casilla.columna - 1);
			setPos(casilla.fila + 1.0, casilla.columna - 1);
			break;
			//DIAGONAL ARRIBA DERECHA
		case 'y':
			casilla.setPosicion(casilla.fila + 1.0, casilla.columna + 1);
			setPos(casilla.fila + 1.0, casilla.columna + 1);
			break;

			//DIAGONAL ABAJO DERECHA
		case 'h':
			casilla.setPosicion(casilla.fila - 1.0, casilla.columna + 1);
			setPos(casilla.fila - 1.0, casilla.columna + 1);
			break;
			//DIAGONAL ABAJO IZQUIERDA
		case 'j':
			casilla.setPosicion(casilla.fila - 1.0, casilla.columna - 1);
			setPos(casilla.fila - 1.0, casilla.columna - 1);
			break;

*/