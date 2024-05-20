#include <stdio.h>
#include "args.h"

int main(int argc, char* argv[]){

    // arreglos de claves, de valores y de otros parametros.
    char* claves[argc]; // los arrays tienen tamaño de argc
    char* valores[argc];
    char* parametros[argc];

    argumentos(argc, argv, claves, valores, parametros);

    int i = 0;
    while (claves[i][0] != '\0'){ // imprimo las opciones
        printf("Opcion %d: Clave: %s Valor: %s\n", i+1, claves[i]+1, valores[i]); // claves[i]+1 para no imprimir el '-' 
        i++;
    }

    i = 0;
    while (parametros[i][0] != '\0'){ // imprimo los parametros
        printf("Parametro %d: %s\n", i+1, parametros[i]);
        i++;
    }

    return 0;
}