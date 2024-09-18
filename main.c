#include "scannerWollok.h"
//#include "imprimirResultado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    


int main(){
  FILE *archivo = fopen("example.wlk", "r");
  if(archivo == NULL){
    printf("error al abrir archivo");
    return 1;
  }

  char linea[150];

  printf("@startuml \n");
  //toma el token
  while(fgets(linea, sizeof(linea), archivo) != NULL){
    scanner(linea);
    limpiarLinea(linea);
  }

  printf("@enduml \n");

  fclose(archivo);
  return 0; 
}
