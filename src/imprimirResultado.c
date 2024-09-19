#include "imprimirResultado.h"
#include <stdio.h>

extern char token[50];
extern int estaEscribiendoClase;
extern int estaEscribiendoVariable;

void imprimirResultado(){
    if (!esEspacio(token[0])) {
        if(estaEscribiendoClase){
            if (!estaEscribiendoVariable) {
                printf("}\n");
            }
            printf("class %s\n", token);
            printf("{\n");
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
