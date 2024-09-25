#include "imprimirResultado.h"
#include "scannerWollok.h"
#include <stdio.h>
#include <string.h>

extern char token[50];
extern char claseHeredada[50];
extern int estaEscribiendoClase;
extern int estaEscribiendoVariable;
extern int tieneHerencia; 
int primeraInteracion = 1;
char palabraAnterior[50];

void imprimirResultado(){
    //printf("%d", !esEspacio(token[0]));
    if (!esEspacio(token[0])) {
        if(estaEscribiendoClase){
            if (!estaEscribiendoVariable && !primeraInteracion) {
                printf("}\n");
                imprimirHerencia();
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

void imprimirHerencia(){
    if (tieneHerencia) {
        printf("%s --|> ", palabraAnterior);
        printf("%s\n", claseHeredada);
    }
}

int esEspacio(char ch)
{
    return ch == '\n' || ch == '\0' || ch == ' ';
}
