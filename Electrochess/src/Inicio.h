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
	Sprite logo{ "imagenes/Logo_color.png" };
	virtual void dibuja();
	void TextoInicial(float x, float y, float z, void* font, const char* string);
};