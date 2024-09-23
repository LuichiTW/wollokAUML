# wollokAUML
Herramienta para pasar codigo de wollok a uml para diagramas de clase.
El codigo tiene que ser compilado despues de clonar el repositorio
```
gcc src/main.c src/scannerWollok.c src/imprimirResultado.c -o <nombre que quiera>
```

Luego mueva el ejecutable a la carpeta donde se ubican los archivos .wlk, esto generara un archivo salida.plantuml que podra ser leido por plantUML

AVISO: no realiza las conexiones solo pasa los objetos y clases uml quitando los bloques y valores de las variables.
