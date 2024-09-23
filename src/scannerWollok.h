#ifndef SCANNER_H 
#define SCANNER_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>    

void scanner(char *linea);
void escrituraClase(char *palabra);
void escrituraVariable(char *palabra);
void limpiarLinea(char linea[150]);
void limpiarToken(char token[50]);
int esPalabra(char *palabra);

#endif //SCANNER_H
