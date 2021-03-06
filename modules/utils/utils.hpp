#pragma once

#include <windows.h>
#include "conio.h"
#include <iostream>
// Devuelve la aultra de la terminal
int getWindowHeight();

// Devuelve la anchura de la terminal
int getWindowWidth();


// Devuelve la posicion en x de una porcentaje de la anchura de la terminal
int getWPos(int percentage);

// Devuelve la posicion en y de una porcentaje de la altura de la terminal
int getHPos(int percentage);

const char* getIColor(int i);

#include "utils.cpp" 