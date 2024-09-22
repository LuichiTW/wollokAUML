#ifndef INTERFACES_H 
#define INTERFACES_H 

#include <string.h>

typedef struct interfaces{
    char objetos[150];
    char metodos[150];
    struct  interfaces *siguiente;
}interfaces;

void crearInterfaces();
void buscarCoincidencias(char nombre[50], char *metodo);
int tieneMetodo(char metodos[150], char *metodo);
void agregarMetodoInterfaces(char metodos[150],char *token);
void agregarNombreInterfaz(char objetos[150],char nombre[50]);
void limpiarLista();

#endif //INTERFACES_H
