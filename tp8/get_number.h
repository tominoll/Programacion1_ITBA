#ifndef GETNUM_H
#define GETNUM_H

// funcion para preguntarle al usuario cuantas generaciones quiere avanzar
// si los caracteres ingresados son invalidos, vuelve a preguntarle al usuario
// si no se ingresa nada, solo aprieta enter, devuelve un 1
// si se ingresa un numero valido devuelve ese int
// si se ingresa 'q' o 'Q' devuelve un -1
int get_number(void);

#endif