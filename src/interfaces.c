#include "interfaces.h"
#include "scannerWollok.h"
#include <string.h>

extern objetos *lista;

typedef struct interfaces{
    char objetos[150];
    char metodos[150];
    struct  interfaces *siguiente;
}interfaces;

interfaces *listaInterfaces;

void crearInterfaces(){
    //inicializar la lista de interfaces
    limpiarLinea(listaInterfaces->objetos);
    limpiarLinea(listaInterfaces->metodos);
    listaInterfaces->siguiente = NULL;

    objetos *aux = lista;

    while (aux->siguiente != NULL) {
        //verifica que tenga metodos
        if (aux->metodos[0] != '\0') {
            char *metodo = strtok(aux->metodos, "\n");
            while(metodo != NULL){
                buscarCoincidencias(aux->nombre ,metodo);
                metodo = strtok(NULL, "\n");
            }
        }
        aux = aux->siguiente; 
    }
}

void buscarCoincidencias(char nombre[50], char *metodo){
    objetos *auxiliar = lista;
    while(auxiliar->siguiente != NULL){
        if (strcmp(auxiliar->nombre, nombre) == 0) {
            if (auxiliar->siguiente != NULL) {
                auxiliar = auxiliar->siguiente;
            }else {
            break;
            }
        }

        if (tieneMetodo(auxiliar->nombre, metodo)) {
        
        }
        
        auxiliar = auxiliar->siguiente;
    }
    
}

int tieneMetodo(char nombre[50], char *metodo){
    return 0;
}
