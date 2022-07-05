#include "Inicio.h"

void Inicio::textoInicial(float x, float y, float z, void* font, const char* string)
{
	const char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void Inicio::dibuja()
{
	gluLookAt(4, 4, 15,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

	playMusica("Route66.mp3");
	portada.setCenter(3.6, 1.45);
	portada.setSize(14.9, 11.175);
	portada.draw();
}