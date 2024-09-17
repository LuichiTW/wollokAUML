#include "scannerWollok.h"
#include "imprimirResultado.h"

char linea[100];
char token[50];

int main(){
  FILE *archivo = fopen("salida.txt", "r");
  if(archivo == NULL){
    printf("error al abrir archivo");
    return 1;
  }
  printf("@startuml \n");

  //toma el token
  while(fgets(linea, sizeof(linea), archivo)){

    if(!esEspacio(linea[0])){
      strcpy(token, scanner(linea));
      printf("%s \n", token);
   }
  }

  printf("@enduml \n");

  return 0; 
}
