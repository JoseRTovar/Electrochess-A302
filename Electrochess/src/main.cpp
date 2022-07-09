#include "Juego.h"
#include "Inicio.h"
#include "freeglut.h"
#include <iostream>

Juego juego;
Inicio inicio;
int start = 0;

//CALLBACKS FUNCIONES
void OnDraw(void); //LLamada para el dibujo
void OnMouseClick(int button, int state, int x, int y); //LLamada para la gestion del raton
void OnKeyboardDown(unsigned char key, int x_t, int y_t); //LLamada para la gestion del teclado
void resize(int width, int height); //LLamada para no maximizar pantalla

int main(int argc, char* argv[])
{
	//Se inicializa el gestor de ventanas GLUT y se crea la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//Se habilitan luces y se define la perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Se registran los callbacks
	glutDisplayFunc(OnDraw);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);

	//Se evita el maximizar la pantalla
	glutReshapeFunc(resize);

	//Se pasa el control a GLUT, que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Definicion del punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (start == 1) juego.dibuja(); //dibuja el tablero y las piezas
	else inicio.dibuja();			//dibuja la pantalla de inicio

	glutSwapBuffers();
}

//INTERACCION POR RATON 
void OnMouseClick(int b, int state, int x, int y)
{
	bool down = (state == GLUT_DOWN);
	if (b == GLUT_LEFT_BUTTON)
		juego.botonRaton(x, y, b, down);
	glutPostRedisplay();
}

//INTERACCION POR TECLADO
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

	switch (key)
	{
		//START
	case ' ':
		if (start == 0)
		{
			start = 1;
			stopMusica();
		}
	default:
		break;
	}
	glutPostRedisplay();
}

//AJUSTES DE PANTALLA
void resize(int width, int height)
{
	// Impide maximizar la pantalla:
	glutReshapeWindow(800, 600);
}






