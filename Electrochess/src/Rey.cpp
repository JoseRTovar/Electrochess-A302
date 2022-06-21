#include "Rey.h"
#include "freeglut.h"

void Rey::dibuja()
{
	/*
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
	glPushMatrix();
	sprite.setState(1);
	sprite.draw();
	glPopMatrix();
	*/
	if (color == Pieza::NEGRA)  glColor3ub(NEGRO, NEGRO, NEGRO);
	else if (color == Pieza::BLANCA) glColor3ub(BLANCO, BLANCO, BLANCO);
	glutSolidSphere(0.4, 20, 20);
}

/*
bool Rey::validmove(int fila, int columna)
{
	if (abs(fila - this->fila) <= 1 && abs(columna - this->columna) <= 1) return true;
	return false;
}
*/

//El rey ya se mueve segun sus movimientos, no se puede mover en diagonal
bool Rey::validmove(int fila, int columna)
{
	if ((abs((fila + columna) - ((this->fila) + (this->columna))) == 1) && (tableroinmove(fila, columna) != false)) return true;
	return false;
}

/*
//ARRIBA
		case 'w':
			casilla.setPosicion(casilla.fila + 1.0, casilla.columna);
			setPos(casilla.fila + 1.0, casilla.columna);
			break;
			//DERECHA
		case 'd':
			casilla.setPosicion(casilla.fila, casilla.columna + 1.0);
			setPos(casilla.fila, casilla.columna + 1.0);
			break;
			//ABAJO
		case 's':
			casilla.setPosicion(casilla.fila - 1, casilla.columna);
			setPos(casilla.fila - 1, casilla.columna);
			break;
			//IZQUIERDA
		case'a':
			casilla.setPosicion(casilla.fila, casilla.columna - 1);
			setPos(casilla.fila, casilla.columna - 1);
			break;

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