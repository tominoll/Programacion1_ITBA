#ifndef ARGS_H
#define ARGS_H

// funcion que recibe las entradas y las separa el 3 arrays
// cla: lo que empieza con un guion
// val: lo que esta despues de la clave, aunque tenga guion
// par: el resto de los argumentos de entrada
void argumentos(int argc, char* argv[], char* cla[], char* val[], char* par[]);

#endif 