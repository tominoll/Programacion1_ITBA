#include <stdio.h>
#include "get_number.h"

int get_number(void){
    int c, num, error, enter, quit;
  
    do {
        num = 0;
        error = 0;
        enter = 0;
        quit = 0;
        printf("¿Cuántas generaciones quiere avanzar? ");
        while ( (c = getchar()) != '\n') {
            if ((c-'0')>=0 && (c-'0')<=9 && !quit){ 
                num = num*10 + (c-'0');    // voy guardando los numeros 
                enter++;
                }
            else if ((c == 'q' || c == 'Q') && !quit && enter==0){
                quit++;
                enter++;
            }
            else { 
                error=1; // caracter invalido
            } 
        }
    }
    while (error > 0); // si se ingreso caracteres invalidos, vuelve a preguntar

    if (enter==0){
        num = 1; // si se ingreso solo enter, devuelve un 1
    }
    else if (enter==1){
        if (quit){ // si se ingreso ''q' o 'Q' devuelve un -1
            num = -1;
        }
    }
    
    return num;
}
