#include "scannerWollok.h"
#include <stdio.h>
#include <string.h>

//esta en cero si no esta escribiendo una clase o objeto
int estaEscribiendoClase = 1;
//esta en cero si esta no esta escribiendo una variable (cuando es class, object y method se considera 0)
int estaEscribiendoVariable = 1;
char token[50];

void scanner(char *linea)
{
  char *palabra = strtok(linea, " ");
  limpiarToken(token);
  while (palabra != NULL)
  {
    if (esPalabra(palabra))
    {

      //detecta si la palabra es object o class
      escrituraClase(palabra);

      palabra = strtok(NULL, " ");

      //toma la siguiente palabra en caso de que sea una variable con property
      if (strcmp(palabra, "property") == 0) {
        palabra = strtok(NULL, " ");
      }

      //limpia caracteres de apertura de bloque y asignacion
      palabra = strtok(palabra, "=");
      palabra = strtok(palabra, "{");
      strcpy(token, palabra); 
    }
    palabra = strtok(NULL, " ");
  }
  printf("%s\n", token);
}

void escrituraVariable(char *palabra){
  if (strcmp(palabra, "var") == 0) {
    estaEscribiendoVariable = 1;
  }else {
    estaEscribiendoVariable = 0;
  }
}

void escrituraClase(char *palabra){
  if (strcmp(palabra, "object") == 0|| strcmp(palabra, "class")== 0) {
    estaEscribiendoClase = 1;
  }else{
    estaEscribiendoClase = 0;
  }
}

void limpiarLinea(char linea[150]){
  for (int i = 0; i < 150; i++){
    linea[i] = '\0';
  }
}

void limpiarToken(char token[50]){
  for (int i = 0; i < 50; i++){
    token[i] = '\0';
  }
}

int esPalabra(char *palabra)
{
  return strcmp(palabra, "object") == 0|| strcmp(palabra, "class") == 0|| strcmp(palabra, "var") == 0|| strcmp(palabra, "const") == 0|| strcmp(palabra, "method") == 0;
}


