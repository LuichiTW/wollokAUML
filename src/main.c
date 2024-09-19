#include "scannerWollok.h"
#include "imprimirResultado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    
#include <dirent.h>    


int main(){

  char linea[150];
  DIR *dir;
  struct dirent *ent;

  //abrir la carpeta
  dir = opendir(".");
  if (dir == NULL) {
    perror("error al abrir carpeta");
    return 1;
  }

  printf("@startuml \n");

  while ((ent = readdir(dir)) != NULL) {
    //verificar si es un archivo .wlk
    if (ent->d_type == DT_REG){
      int longitud = strlen(ent->d_name);
      if (longitud >= 4 && strcmp(&ent->d_name[longitud - 4], ".wlk") == 0) {
        char *nombre = ent->d_name;

        //abre el archivo en lectura
        FILE *archivo = fopen(nombre, "r");
        if(archivo == NULL){
          printf("error al abrir archivo");
          return 1;
        }

        //toma el token
        while(fgets(linea, sizeof(linea), archivo) != NULL){
          scanner(linea);
          imprimirResultado();
          limpiarLinea(linea);
        }
        fclose(archivo);

      }
    }
  }

  //se agrega una llave de cierre para cerrar el ultimo objeto
  printf("}\n");


  printf("@enduml \n");
  return 0; 
}
