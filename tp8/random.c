#include "random.h"

#define SEED 1103515245 // seed para la funcion rand()

static int rand(void); // genera un 0 o un 1 'pseudo aleatoriamente' a partir de una seed 

void random_init(int m[ALTO+2][ANCHO+2]){
    int i, j;
    for (i=0; i<ALTO+2; i++){ // armo el estado inicial de la matriz del mundo
        for (j=0; j<ANCHO+2; j++){
            if (i==0 || j==0 || i==ALTO+1 || j==ANCHO+1){ 
                m[i][j]=0; // los bordes son = 0
            }
            else {
                if (rand()){
                    m[i][j]=1;
                }
                else {
                    m[i][j]=0;
                }
            }
        }
    }
}

static int rand(void) // de stackoverflow
{
    // genera un 0 o un 1 'pseudo aleatoriamente' a partir de una seed 
    static unsigned long int next = 1;
    next = next * SEED + 9876;
    return (unsigned int)(next/65536) % 2;
}
