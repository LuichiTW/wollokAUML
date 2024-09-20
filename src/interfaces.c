#include "interfaces.h"
#include "scannerWollok.h"
#include <string.h>

extern objetos *lista;

void crearInterfaces(){
    objetos *aux = lista;

    while (aux->siguiente != NULL) {
        //verifica que tenga metodos
        if (aux->metodos[0] != '\0') {
            char *metodo = strtok(aux->metodos, "\n");
        }
        aux = aux->siguiente; 
    }
}
