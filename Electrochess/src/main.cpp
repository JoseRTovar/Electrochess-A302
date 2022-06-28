#include "Tablero.h"
#include "freeglut.h"
#include <iostream>

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

Tablero tablero;
//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnMouseClick(int button, int state, int x, int y); //esta funcion sera llamada para gestionar el ratón
//void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion no es necesaria en este caso
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
	glutMouseFunc(OnMouseClick);
	//glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()

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

	tablero.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

/*void OnTimer(int value)
{
	//poner aqui el código de animacion

	tablero.click();

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}*/

void OnMouseClick(int b, int state, int x, int y) {

	bool down = (state == GLUT_DOWN);
	int button;

	if (b == GLUT_LEFT_BUTTON) {
		button = MOUSE_LEFT_BUTTON;
		cout << "MOUSE_LEFT_BUTTON" << endl;
	}
	if (b == GLUT_RIGHT_BUTTON) {
		button = MOUSE_RIGHT_BUTTON;
		cout << "MOUSE_RIGHT_BUTTON" << endl;
	}
	glutPostRedisplay();
}





