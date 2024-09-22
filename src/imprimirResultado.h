#ifndef IMPRIMIR_H 
#define IMPRIMIR_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>    


void imprimirResultado();
void imprimirInterfaces();
void imprimirMetodos(char metodos[150]);
void imprimirObjetos(char objetos[150], int numeroInterfaz);
void limpiarListaInterfaces();
int esEspacio(char ch);

#endif //IMPRIMIR_H
