#include "scannerWollok.h"
#include <stdio.h>
#include <string.h>

//esta en cero si no esta escribiendo una clase o objeto
int estaEscribiendoClase = 1;
//esta en cero si esta no esta escribiendo una variable (cuando es class, object y method se considera 0)
int estaEscribiendoVariable = 1;
char token[50];

objetos *lista = NULL;

void scanner(char *linea)
{
  char *palabra = strtok(linea, " ");


  limpiarToken(token);
  while (palabra != NULL)
  {

    if (esPalabra(palabra))
    {
      //flags para la impresion del token      
      escrituraClase(palabra);
      escrituraVariable(palabra);

      palabra = strtok(NULL, " ");

      //toma la siguiente palabra en caso de que sea una variable con property
      if (strcmp(palabra, "property") == 0) {
        palabra = strtok(NULL, " ");
      }

      //limpia caracteres de apertura de bloque y asignacion
      palabra = strtok(palabra, "=");
      palabra = strtok(palabra, "{");
      strcpy(token, palabra); 

      //copia el token y lo guarda para luego formar las interfaces
      agregarObjeto(token);
      
    }

    palabra = strtok(NULL, " ");
  }
}

void agregarObjeto(char token[50])
{
  if (estaEscribiendoClase)
  {
    if (lista == NULL)
    {
      // inicializar la lista
      lista = malloc(sizeof(objetos));
      if (lista == NULL)
      {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
      }
      strcpy(lista->nombre, token);
      //printf("%s\n", lista->nombre);
      limpiarLinea(lista->metodos);
      lista->siguiente = NULL;
    }
    else
    {
      // inicializar el nuevo nodo
      objetos *nuevoNodo = malloc(sizeof(objetos));
      if (nuevoNodo == NULL)
      {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
      }
      strcpy(nuevoNodo->nombre, token);
      limpiarLinea(nuevoNodo->metodos);
      nuevoNodo->siguiente = NULL;
      // agregar el nuevo nodo al final de la lista
      objetos *aux = lista;
      while (aux->siguiente != NULL)
      {
        aux = aux->siguiente;
      }
      aux->siguiente = nuevoNodo;
      //printf("%s\n", nuevoNodo->nombre);
    }
  }
  else if (!estaEscribiendoVariable)
  {    
    // va hacia el ultimo objeto agregado
    if (lista == NULL) {
      perror("Error: lista es NULL");
      exit(EXIT_FAILURE);
    }
    objetos *aux = lista;
    while (aux->siguiente != NULL)
    {
      aux = aux->siguiente;
    }
    //printf("%s\n", token);
    agregarMetodo(aux, token);
  }
}

void agregarMetodo(objetos *auxiliar,char token[50]){
  int contador = 0;
  //formato del string esperado: vida()\ncomer()\n
  while(auxiliar->metodos[contador] != '\0' && auxiliar->metodos[contador] != '\n'){
    contador++;
  }
  for (int i = 0; token[i] != '\0'; i++) {
    auxiliar->metodos[contador + i] = token[i];
  }
  contador = 0;
  while(auxiliar->metodos[contador] != '\0' && auxiliar->metodos[contador] != '\n'){
    contador++;
  }
  auxiliar->metodos[contador] = '\n';
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
  return strcmp(palabra, "object") == 0|| strcmp(palabra, "class") == 0|| strcmp(palabra, "var") == 0|| strcmp(palabra, "const") == 0|| strcmp(palabra, "method") == 0;
}


