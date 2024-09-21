#include "interfaces.h"
#include "scannerWollok.h"
#include <string.h>

extern objetos *lista;

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
            //revisar si causa bugs
            if (auxiliar->siguiente != NULL) {
                auxiliar = auxiliar->siguiente;
            }else {
            break;
            }
        }

        if (tieneMetodo(auxiliar->metodos, metodo)) {
        agregarMetodoInterfaces(listaInterfaces->metodos, metodo);
        agregarNombreInterfaz(listaInterfaces->objetos, auxiliar->nombre);
        }
        
        auxiliar = auxiliar->siguiente;
    }
    
}

int tieneMetodo(char metodos[150], char *metodo){
    //verifica que tenga metodos
    if (metodos[0] != '\0') {
        char *unMetodo = strtok(metodos, "\n");
        while(unMetodo != NULL){
            if (strcmp(unMetodo, metodo) == 0) {
                return 1;
            }
            metodo = strtok(NULL, "\n");
        }
    }
    return 0;
}

void agregarMetodoInterfaces(char metodos[150],char *token){
  //formato del string esperado: vida()\ncomer()\n
  int contador = 0;
    //busca el espacio vacio
  while(metodos[contador] != '\0' && metodos[contador] != '\n'){
    contador++;
  }
  for (int i = 0; token[i] != '\0'; i++) {
    metodos[contador + i] = token[i];
  }
  contador = 0;
  while(metodos[contador] != '\0' && metodos[contador] != '\n'){
    contador++;
  }
  metodos[contador] = '\n';
}

void agregarNombreInterfaz(char objetos[150],char nombre[50]){
  //formato del string esperado: juan\nmaria\n
  int contador = 0;
    //busca el espacio vacio
  while(objetos[contador] != '\0' && objetos[contador] != '\n'){
    contador++;
  }
  for (int i = 0; nombre[i] != '\0'; i++) {
    objetos[contador + i] = nombre[i];
  }
  contador = 0;
  while(objetos[contador] != '\0' && objetos[contador] != '\n'){
    contador++;
  }
  objetos[contador] = '\n';
}
