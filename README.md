# wollokAUML
herramienta para pasar codigo de wollok a uml para diagramas de clase

-no realiza las conexiones solo pasa los objetos y clases uml quitando los bloques y valores de las variables

TODO:
+hacer que tome las variables y metodos y los asigne al objeto o clase
+ señalizar los methodos con "+" y las variables y constantes con "-"
+hacer que tome varios archivos
+que pueda sintetizar todo en un solo archivo uml (posible implementacion: bucle while de archivos y el start y end por fuera para juntar todo en el mismo archivo)
+que pueda crear interfazes de uml tomando los elementos que tienen en comun los objetos (posible implementacion: tomar un objeto y un method y buscar otro objeto con el mismo method, si es unico no crea la interfaz, los method que den coincidencia se guardan su objeto dueño y luego se imprimen apuntando a la nueva interfaz)
+buscar una manera de crear las conexiones
