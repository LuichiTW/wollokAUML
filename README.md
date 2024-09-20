# wollokAUML
Herramienta para pasar codigo de wollok a uml para diagramas de clase.
El codigo tiene que ser compilado despues de clonar el repositorio
```
gcc src/main.c src/scannerWollok.c src/imprimirResultado.c -o <nombre que quiera>
```

Luego mueva el ejecutable a la carpeta donde se ubican los archivos .wlk, esto generara un archivo salida.txt que podra ser leido por plantUML

AVISO: no realiza las conexiones solo pasa los objetos y clases uml quitando los bloques y valores de las variables[^1]

TODO:
+que pueda crear interfazes de uml tomando los elementos que tienen en comun los objetos (posible implementacion: tomar un objeto y un method y buscar otro objeto con el mismo method, si es unico no crea la interfaz, los method que den coincidencia se guardan su objeto dueño y luego se imprimen apuntando a la nueva interfaz)

+buscar una manera de crear las conexiones
