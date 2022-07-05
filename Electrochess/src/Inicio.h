#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "freeglut.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;
using ETSIDI::playMusica;
using ETSIDI::stopMusica;

class Inicio
{
public:
	Sprite portada{ "Inicio.png" };
	virtual void dibuja();
	void textoInicial(float x, float y, float z, void* font, const char* string);
};