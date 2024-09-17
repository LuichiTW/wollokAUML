#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>    

extern char token[50];

char *scanner(char *linea);
void escrituraClase(char *palabra);
void limpiarToken(char token[50]);
int esPalabra(char *palabra);
int esEspacio(char ch);
