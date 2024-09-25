#include "scannerWollok.h"
#include <stdio.h>
#include <string.h>

extern char palabraAnterior[50];
//esta en cero si no esta escribiendo una clase o objeto
int estaEscribiendoClase = 1;
//esta en cero si esta no esta escribiendo una variable (cuando es class, object y method se considera 0)
int estaEscribiendoVariable = 1;
int tieneHerencia = 0;
char token[50];
char claseHeredada[50];

void scanner(char *linea)
{
  char *palabra = strtok(linea, " ");
  char *nombre;
  char *siguiente;

  limpiarToken(token);
  while (palabra != NULL)
  {

    if (esPalabra(palabra))
    {
      //detecta si la palabra es object o class
      escrituraClase(palabra);
      escrituraVariable(palabra);

      palabra = strtok(NULL, " ");

      //toma la siguiente palabra en caso de que sea una variable con property o un override de un metodo
      if (strcmp(palabra, "property") == 0 || strcmp(palabra, "override") == 0) {
        palabra = strtok(NULL, " ");
      }

      siguiente = strtok(NULL, " ");
      if (siguiente != NULL && strcmp(siguiente, "inherits") == 0) {
        tieneHerencia = 1;
        siguiente = strtok(NULL, " ");
        siguiente = strtok(siguiente, "{");
        limpiarToken(claseHeredada);
        strcpy(claseHeredada, siguiente);
      }else if (estaEscribiendoClase){
        tieneHerencia = 0;
      }    

      //limpia caracteres de apertura de bloque y asignacion
      palabra = strtok(palabra, "=");
      palabra = strtok(palabra, "{");
      strcpy(token, palabra); 
      limpiarToken(palabraAnterior);
      strcpy(palabraAnterior, token); 
    }
    palabra = strtok(NULL, " ");

  }
}

void escrituraVariable(char *palabra){
  if (strcmp(palabra, "var") == 0 || strcmp(palabra, "const") == 0) {
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
  return strcmp(palabra, "object") == 0|| strcmp(palabra, "class") == 0|| strcmp(palabra, "var") == 0|| strcmp(palabra, "const") == 0|| strcmp(palabra, "method") == 0 || strcmp(palabra, "override") == 0;
}


