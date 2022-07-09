#include "Juego.h"

//Método para comprobar que el primer click para seleccionar una pieza es válido.
Coordenadas Juego::click0()
{
	Coordenadas c = raton;

	if (tablero[c] == nullptr)
		cout << "Casilla vacia" << endl;

	else if (tablero[c]->getColor() != (Pieza::Color_e)turno)
		cout << "No es tu turno" << endl;

	//Al seleccionar una pieza clacula todos sus movimientos legales, en caso de no haber, se elimina la selección
	//y no se puede jugar esa pieza. Esta función devuelve las coordenadas seleccionadas
	else
	{
		calcLegalMoves(c, (Pieza::Color_e)turno);
		if (nlegalmoves == 0)
		{
			cout << "No se puede jugar esta pieza " << endl;
			vaciarLegalMoves();
			click = 0;
		}

		else
		{
			cout << "Se puede jugar esta pieza " << endl;
			click = 1;
		}
	}

	return c;
}

//Función para indicar las coordenadas a las que se va a mover la pieza que se encuentra en las coordenadas 
//seleccionadas en el click0
void Juego::click1(Coordenadas o)
{
	Coordenadas d = raton;
	bool find = false;

	//Si las coordenadas del segundo click coinciden con coordenadas válidas para esa pieza, esta se puede mover.
	for (int i = 0; i < nlegalmoves; i++)
	{
		if (d.fila == legalmoves[i]->fila && d.columna == legalmoves[i]->columna)
			find = true;
	}

	if (find == true)
	{
		//Se añade sonido al movimiento de las piezas
		if (tablero[d] != nullptr)
		{
			playMusica("Take.mp3");
			cout << "Pieza comida " << endl;
		}
		else playMusica("Move.mp3");

		//Se imprime en consola el movimiento realizado y se le pasa la información del nuevo estado al tablero
		o.print() << "->";
		d.print() << endl;
		tablero.cambiarEstado(o, d);

		//Comprobaciones y acciones que se realizan al cambiar el estado de tablero
		if (checkJaqueMate((Pieza::Color_e)!turno))
		{
			cout << "JAQUE MATE" << endl;
			JaqueMate = 1;
			tablero.cleanTablero();
		}
		else
		{
			jaque = checkJaque(tablero, (Pieza::Color_e)!turno);
			if (jaque == 1) cout << "JAQUE" << endl;
			vaciarLegalMoves();
			cambiarTurno();
			click = 0;
		}
	}
	else
	{
		cout << "Movimiento no valido" << endl;
		vaciarLegalMoves();
		click = 0;
	}
}

//Función que se encarga de chequear si en un estado determinado del tablero, el rey de un color se encuentra en 
//jaque. Para ello, comprueba si existe alguna pieza que lo esté atacando.
bool Juego::checkJaque(Tablero& tablero, Pieza::Color_e color)
{
	for (int f = 0; f < N_FILAS; f++)
	{
		for (int c = 0; c < N_COLUMNAS; c++)
		{
			Coordenadas daux(f, c);
			if (tablero[daux] != nullptr && tablero[daux]->getPieza() == Pieza::REY && tablero[daux]->getColor() == color)
			{
				for (int f = 0; f < N_FILAS; f++)
				{
					for (int c = 0; c < N_COLUMNAS; c++)
					{
						Coordenadas oaux(f, c);
						if (tablero[oaux] != nullptr && tablero[oaux]->getColor() == !color && tablero[oaux]->validMove(oaux, daux, tablero))
							return true;
					}
				}
			}
		}
	}
	return false;
}

//Función que se encarga de comprobar si el estado actual del tablero es Jaque mate. Comprueba si de las pieza 
//del color susceptible de esta bajo jaque mate, existe alguna que tenga un movimiento valido, si no es así, es 
//Jaque mate.
bool Juego::checkJaqueMate(Pieza::Color_e color)
{
	vaciarLegalMoves();
	for (int f = 0; f < N_FILAS; f++)
	{
		for (int c = 0; c < N_COLUMNAS; c++)
		{
			Coordenadas oaux(f, c);
			if (tablero[oaux] != nullptr && tablero[oaux]->getColor() == color)
			{
				calcLegalMoves(oaux, color);
				if (nlegalmoves != 0) return false;
			}
		}
	}
	return true;
}

//Función que se encarga de calcular todos los movimientos legales de una pieza, es decir, que además de que
//cumplan con su propia regla de movimiento, protejan al rey si están en jaque o no se permita auto introducirse
//en jaque mate. En caso de encontrar un movimiento válido lo almacena en un array.
void Juego::calcLegalMoves(Coordenadas o, Pieza::Color_e color)
{
	Pieza* pieza = tablero[o];
	Coordenadas aux;
	for (aux.fila = 0; aux.fila < N_FILAS; aux.fila++)
	{
		for (aux.columna = 0; aux.columna < N_COLUMNAS; aux.columna++)
		{
			if (pieza->validMove(o, aux, tablero) == true)
			{
				Tablero tablero_aux = tablero;
				tablero_aux.movEstado(o, aux);
				if (checkJaque(tablero_aux, color) == false)
				{
					legalmoves[nlegalmoves++] = new Coordenadas(aux.fila, aux.columna);
				}
			}
		}
	}
}

//Función para vaciar los movimientos legales calculados cada vez que una pieza es pulsada con el ratón.
void Juego::vaciarLegalMoves()
{
	for (int i = 0; i < nlegalmoves; i++)
	{
		delete legalmoves[i];
		legalmoves[i] = nullptr;
	}
	nlegalmoves = 0;
}

//Función que gestiona el control de los botones del ratón y convierte las coordenadas generales a coordenadas del
//tablero. 
void Juego::botonRaton(int x, int y, int button, bool down)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	raton.fila = (int)(abs(posY));
	raton.columna = (int)(posX);

	//Permite distinguir entre el primer y segundo click (Primer click seleccionar, segundo mover).
	if (down)
	{
		if (Coordenadas::fueraTablero(raton) == true) cout << "Fuera del tablero" << endl;
		else if (click == 0) raton_sel = click0();
		else if (click == 1) click1(raton_sel);
	}
}

//Función para dibujar todos los elementos del juego.
void Juego::dibuja()
{
	gluLookAt(4, 4, 15,			    // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);			   // definimos hacia arriba (eje Y)

	Coordenadas coord;
	for (coord.fila = 0; coord.fila < N_FILAS; coord.fila++)
	{
		for (coord.columna = 0; coord.columna < N_COLUMNAS; coord.columna++)
		{
			if (tablero[coord] != nullptr)
			{
				glTranslatef(coord.columna + 0.5, coord.fila + 0.5, 0);
				tablero[coord]->dibuja();
				glTranslatef(-coord.columna - 0.5, -coord.fila - 0.5, 0);
			}
		}
	}

	if (JaqueMate == 1 && turno == Pieza::NEGRA) {
		jaquematen.setCenter(-2, -3);
		jaquematen.setSize(4, 2);
		jaquematen.draw();
		playMusica("Gameover.mp3");
	}

	else if (JaqueMate == 1 && turno == Pieza::BLANCA) {
		jaquemateb.setCenter(-2, -3);
		jaquemateb.setSize(4, 2);
		jaquemateb.draw();
		playMusica("Gameover.mp3");
	}

	if (jaque == 1) {
		Jaque.setCenter(-2.75, -8.2);
		Jaque.setSize(2.64, 1.16);
		Jaque.draw();
	}

	tablero.dibuja(*this);

	//Dibuja el fondo de la pantalla
	fondo.setCenter(3.6, 1.45);
	fondo.setSize(14.9, 11.175);
	fondo.draw();
}

