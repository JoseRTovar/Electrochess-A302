#include "Juego.h"
#include "Inicio.h"
#include "freeglut.h"
#include <iostream>

int start = 0;

Juego juego;
Inicio inicio;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnMouseClick(int button, int state, int x, int y); //esta funcion sera llamada para gestionar el ratón
void OnKeyboardDown(unsigned char key, int x_t, int y_t); //detectar inicio del juego

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (start == 1) juego.dibuja(); //dibuja el tablero y las piezas
	else inicio.dibuja();			//dibuja la pantalla de inicio

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnMouseClick(int b, int state, int x, int y)
{
	bool down = (state == GLUT_DOWN);
	if (b == GLUT_LEFT_BUTTON)
		juego.botonRaton(x, y, b, down);
	glutPostRedisplay();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	switch (key)
	{
	case ' ':
		if (start == 0) {
			start = 1;
			stopMusica();
		}
	default:
		break;
	}
	glutPostRedisplay();
}






