#include "args.h"
#include <stdio.h>

void argumentos(int argc, char* argv[], char* cla[], char* val[], char* par[]){
    int i;
    for (i=1 ; i < argc ; i++){ // i=1, porque argv[0] es ./main        
        if (argv[i][0] == '-'){
            *(cla++) = argv[i]; // guardo la clave con '-'
            if (i+1 == argc){ // si tengo una clave al final del argv
                *(val++) = ""; 
            }
            else{
                i++;
                *(val++) = argv[i]; // guardo el valor de la clave
            }
        }
        else {
            *(par++) = argv[i]; // guardo parametro
        }
    }

    *(cla++) = ""; // agrego el terminador
    *(val++) = ""; 
    *(par++) = ""; 
}