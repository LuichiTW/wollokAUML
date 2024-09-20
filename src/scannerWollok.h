#ifndef SCANNER_H 
#define SCANNER_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>    

typedef struct objetos{
  char nombre[50];
  char metodos[150];
  struct objetos *siguiente;
}objetos;

void scanner(char *linea);
void agregarObjeto(char token[50]);
void agregarMetodo(objetos *auxiliar,char token[50]);
void escrituraClase(char *palabra);
void escrituraVariable(char *palabra);
void limpiarLinea(char linea[150]);
void limpiarToken(char token[50]);
int esPalabra(char *palabra);

#endif //SCANNER_H
