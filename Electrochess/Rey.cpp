#include "Rey.h"
#include "freeglut.h"

void Rey::inicializa() {

	Rey reyblanco;
	Rey reynegro;
	agregar(&reyblanco);
	//reyblanco.dibuja();
	reyblanco.setPosicion(BLANCAS);

	agregar(&reynegro);
	//reynegro.dibuja();
	reynegro.setPosicion(NEGRAS);
	
}

void Rey::dibuja() {

	glTranslatef(casilla.getFila(), casilla.getColumna(), 0);
	glutSolidSphere(0.4, 20, 20);
	glTranslatef(-casilla.getFila(), -casilla.getColumna(), 0);
	//Color ya se fija en el metodo setPosicion

}