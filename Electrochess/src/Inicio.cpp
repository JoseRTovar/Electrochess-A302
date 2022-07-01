#include "Inicio.h"

void Inicio::TextoInicial(float x, float y, float z, void* font, const char* string) 
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

	//stopMusica;
	//playMusica("sonidos/Route66.mp3");
	logo.setCenter(0, 0);
	logo.setSize(3.244, 1.501);
	logo.draw();

	glDisable(GL_LIGHTING);
	glColor3ub(250, 255, 180);
	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 0.0);
	glVertex3d(0, 7, 0.0);
	glVertex3d(7, 7, 0.0);
	glVertex3d(7, 0, 0.0);
	glEnd();

	glColor3ub(0, 0, 255);
	TextoInicial(2, 5, 1, (void*)(int)GLUT_BITMAP_TIMES_ROMAN_24, "ELECTROCHESS");

	glColor3ub(0, 0, 255);
	TextoInicial(1.5, 4, 1, (void*)(int)GLUT_BITMAP_9_BY_15, "Pulse Espacio para comenzar");

	glColor3ub(0, 0, 255);
	TextoInicial(4.2, 0.9, 1, (void*)(int)GLUT_BITMAP_HELVETICA_10, "Jose Alejandro Ramos Tovar");
	TextoInicial(4.2, 0.7, 1, (void*)(int)GLUT_BITMAP_HELVETICA_10, "Mario Sanchez Garcia");
	TextoInicial(4.2, 0.5, 1, (void*)(int)GLUT_BITMAP_HELVETICA_10, "Pablo Lopez Lopez");

	glEnable(GL_LIGHTING);
}