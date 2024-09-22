#include "imprimirResultado.h"
#include "interfaces.h"
#include <stdio.h>
#include <string.h>

extern char token[50];
extern int estaEscribiendoClase;
extern int estaEscribiendoVariable;
extern interfaces *listaInterfaces;
int primeraInteracion = 1;

void imprimirResultado(){
    //printf("%d", !esEspacio(token[0]));
    if (!esEspacio(token[0])) {
        if(estaEscribiendoClase){
            if (!estaEscribiendoVariable && !primeraInteracion) {
                printf("}\n");
            }
            printf("class %s\n", token);
            printf("{\n");
            primeraInteracion = 0;
        }else{
            if (estaEscribiendoVariable) {
                printf("-%s\n", token);
            }else{
                printf("+%s\n", token);
            }
        }
    }
}

void imprimirInterfaces(){
    if(listaInterfaces != NULL){
        interfaces *auxiliar = listaInterfaces;
        int numeroInterfaz = 0;
        while(auxiliar != NULL){
            printf("interfaz%d\n", numeroInterfaz);
            printf("{\n");
            imprimirMetodos(auxiliar->metodos);
            printf("}\n");
            imprimirObjetos(auxiliar->objetos, numeroInterfaz);
            numeroInterfaz++;
            auxiliar = auxiliar->siguiente;
        }
    }
}

void imprimirMetodos(char metodos[150]){
    if (metodos[0] != '\0') {
        char *palabra = strtok(metodos, "\n");
        while (palabra != NULL) {
            printf("%s\n", palabra);
            palabra = strtok(NULL, "\n");
        }
    }
}

void imprimirObjetos(char objetos[150], int numeroInterfaz){
    if (objetos[0] != '\0') {
        char *palabra = strtok(objetos, "\n");
        while (palabra != NULL) {
            printf("%s", palabra);
            printf(" --> interfaz%d\n", numeroInterfaz);
            palabra = strtok(NULL, "\n");
        }
    }
}

//funcion para limpiar la lista de interfaces
void limpiarListaInterfaces(){

    interfaces *aux = listaInterfaces; 
    while(listaInterfaces != NULL){
        aux = listaInterfaces;
        listaInterfaces = listaInterfaces->siguiente;
        free(aux);
    }

}


int esEspacio(char ch)
{
    return ch == '\n' || ch == '\0' || ch == ' ';
}
