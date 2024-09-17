#include "scannerWollok.h"
#include <string.h>

//esta en cero si no esta escribiendo una clase o objeto
int estaEscribiendoClase = 1;

char *scanner(char *linea)
{
  char *palabra = strtok(linea, " ");
  while (palabra != NULL)
  {
    if (esPalabra(palabra))
    {
      limpiarToken(token); 

      //detecta si la palabra es object o class
      escrituraClase(palabra);

      palabra = strtok(NULL, " ");

      //toma la siguiente palabra en caso de que sea una variable con property
      if (strcmp(palabra, "property")) {
        palabra = strtok(NULL, " ");
      }

      //limpia caracteres de apertura de bloque y asignacion
      palabra = strtok(palabra, "=");
      palabra = strtok(palabra, "{");
      return palabra;
    }
    palabra = strtok(NULL, " ");
  }
  return NULL;
}

void escrituraClase(char *palabra){
  if (strcmp(palabra, "object") || strcmp(palabra, "class")) {
    estaEscribiendoClase = 1;
  }else{
    estaEscribiendoClase = 0;
  }
}

void limpiarToken(char token[50]){
  for (int i = 0; i < 50; i++){
    token[i] = '\0';
  }
}

int esPalabra(char *palabra)
{
  return strcmp(palabra, "object") || strcmp(palabra, "class") || strcmp(palabra, "var") || strcmp(palabra, "const") || strcmp(palabra, "method");
}


int esEspacio(char ch)
{
  return ch == '\n' || ch == '\0';
}
