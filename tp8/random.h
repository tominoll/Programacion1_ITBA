#ifndef RAND_H
#define RAND_H

#include "config.h"

// armo el estado inicial de la matriz del mundo 
// los valores del 'borde' de la matriz son todos ceros 
// los valores del 'centro' son pseudo aleatorios dependiendo de la SEED definida en random.c
void random_init(int m[ALTO+2][ANCHO+2]);

#endif