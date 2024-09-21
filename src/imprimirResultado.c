#include "imprimirResultado.h"
#include "interfaces.h"
#include <stdio.h>

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
            imprimirMetodos(auxiliar->metodos);
            imprimirObjetos(auxiliar->objetos);
            numeroInterfaz++;
            auxiliar = auxiliar->siguiente;
        }
    }
}

void imprimirMetodos(char metodos[150]){
}

void imprimirObjetos(char objetos[150]){
}

int esEspacio(char ch)
{
    return ch == '\n' || ch == '\0' || ch == ' ';
}
