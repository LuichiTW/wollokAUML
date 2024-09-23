#include "imprimirResultado.h"
#include <stdio.h>

extern char token[50];
extern int estaEscribiendoClase;
extern int estaEscribiendoVariable;
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


int esEspacio(char ch)
{
    return ch == '\n' || ch == '\0' || ch == ' ';
}
