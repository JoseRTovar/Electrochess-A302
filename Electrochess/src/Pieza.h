#pragma once
#define NEGRO 100
#define BLANCO 255

class Pieza
{
public:
	enum pieza_t { NO_PIEZA = 0, REY, TORRE };
	enum color_t { NO_COLOR = 0, BLANCA, NEGRA };
protected:
	pieza_t pieza;
	color_t color;
public:
	Pieza(color_t c, pieza_t p) :color(c), pieza(p) {}
	virtual void dibuja() = 0;
};

