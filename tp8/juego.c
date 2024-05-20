#include <stdio.h>
#include "juego.h"
 
#include "random.h"
#include "get_number.h"

static void generaciones(int g, int m[ALTO+2][ANCHO+2], int a[ALTO][ANCHO]); // avanzo "g" generaciones hacia adelante
static void adyacentes (int matriz[ALTO+2][ANCHO+2], int matriz_a[ALTO][ANCHO]); // cuento las celulas vivas adyacentes a cada casillero y guardo ese numero en la matriz_a
static void actualizacion(int m[ALTO+2][ANCHO+2], int a[ALTO][ANCHO]); // actualizo el mundo por las reglas del juego
static void display(int m[ALTO+2][ANCHO+2]); // imprimo en pantalla el estado actual del mundo
    
void juego_vida(void){
    int mundo[ALTO+2][ANCHO+2]; //= {{0,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,1,1,0},{0,0,0,0,1,0},{0,0,0,0,1,0},{0,0,0,0,0,0}}; 
                                // ALTO+2 y ANCHO+2 porque va a tener todos ceros alrededor que no se actualizan
                                // si quiere cargar un mundo comente la linea de random_init(mundo); y ponga aca: 
                                // = {{0,0,0, ... ,0},{0,b,b ... ,b,0}, ... ,{0,b,b ... ,b,0}, {0,0,0, ... ,0}}; donde b=1 para una celula viva y b=0 para una celula muerta
    int adyacente[ALTO][ANCHO]; // matriz con la cantidad de celulas vivas adyacentes a cada celda
    int gen = 0;
    int delta_gen = 0;

    printf("--- JUEGO DE LA VIDA ---\n");
	printf("(Presione 'q' para salir)\n\n");
    random_init(mundo); 
    printf("Generación %d:\n", gen);
    display(mundo);

    while(delta_gen >= 0){
        printf("---------------------------\n");
        delta_gen = get_number(); // pregunto cuantas generaciones quiere avanzar
        if (delta_gen>=0){
            generaciones(delta_gen, mundo, adyacente);
            gen += delta_gen;
            printf("Generación %d:\n", gen);
            display(mundo);
        }
    }
}

static void generaciones(int g, int m[ALTO+2][ANCHO+2], int a[ALTO][ANCHO]){
    int i;
    for (i=0; i<g; i++){ // avanzo "g" generaciones hacia adelante
        adyacentes(m, a); 
        actualizacion(m, a);
    }
}

static void adyacentes (int matriz[ALTO+2][ANCHO+2], int matriz_a[ALTO][ANCHO]){
    int i;
    int t;
	for (i=1; i<=ALTO; i++) { // cuento las celulas vivas adyacentes a cada casillero y guardo ese numero en la matriz adyacentes	
		for (t=1; t<=ANCHO; t++) {
			int cuenta=0;
			cuenta+=matriz[i-1][t-1]+matriz[i-1][t]+matriz[i-1][t+1] //Se suman las casillas adyacentes a la misma
				   +matriz[i][t-1]+				matriz[i][t+1]+
					matriz[i+1][t-1]+matriz[i+1][t]+matriz[i+1][t+1];

			matriz_a[i-1][t-1]=cuenta; //Se guardan los resultados en la matriz adyacentes
		}
	}
}

static void actualizacion(int m[ALTO+2][ANCHO+2], int a[ALTO][ANCHO]){
    int i, j, ady, cel;
    
    for (i=1; i<ALTO+1; i++){ // actualizo el mundo por las reglas del juego
        for (j=1; j<ANCHO+1; j++){
            ady = a[i-1][j-1];
            cel = m[i][j];
            if (cel){ // hay una celula viva
                if (ady<2 || ady>3){
                    m[i][j] = 0;
                }
            }
            else { // no hay celula 
                if (ady == 3){
                    m[i][j] = 1;
                }
            }
        }
    }
}

static void display(int m[ALTO+2][ANCHO+2]){
    int i, j;
    int celulas = 0;
    for (i=1; i<ALTO+1; i++){ // imprimo en pantalla el estado actual del mundo
        for (j=1; j<ANCHO+1; j++){
			printf("|%c",m[i][j]?'*':' '); // si esta viva pongo un '*'
			celulas += m[i][j]; // cuento las celulas vivas 
        }
        printf("|\n");
    }
    printf("Células Vivas: %d\n", celulas);
}
