#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cambiar mas adelante por los headers
#include "scannerWollok.c"
#include "imprimirResultado.c"

char linea[100];
char token[50];

int main(){
  FILE *archivo = fopen("salida.txt", "r");
  if(archivo == NULL){
    printf("error al abrir archivo");
    return 1;
  }
  printf("@startuml");

  //toma el token
  while(fgets(linea, sizeof(linea), archivo)){

    if(!esEspacio(linea[0])){
      strcpy(token, scanner(linea));
   }
  }

  printf("@enduml");

  return 0; 
}
