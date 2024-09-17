#include <string.h>    

 int esEspacio(char ch){
   return ch == '\n'|| ch == '\0'; 
 }   
    
char *scanner(char *linea){
  char *palabra = strtok(linea, " ");
  char token[50];
  while (palabra != NULL) {
     if(esPalabra(palabra)){
       
     }else{
       return " ";
     }

    palabra = strok(NULL, " ");
  }
   return token;
 }


 int esPalabra(palabra){
   return strcmp(palabra, "object") || strcmp(palabra, "class") || strcmp(palabra, "var") || strcmp(palabra, "const") || strcmp(palabra, "method");
;
 }
