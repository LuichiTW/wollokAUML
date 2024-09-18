object tom{
  var energia = 80
  var posicion = 0
  method velocidad()= energia.div(10) + 5
  method correrA(raton) {
    energia = self.velocidad() * 0.5 * (self.posicion() - raton.posicion()).abs()
    posicion = raton.posicion()
  }
  method posicion() = posicion 
  method posicion(nuevaPosicion) {
    posicion = nuevaPosicion
  } 
  method esMasVeloz(raton) = self.velocidad() > raton.velocidad() 
}

object jerry{
  const peso = 3  
  const posicion = 10
  method velocidad() = 10 - peso 
  method posicion() = posicion 

}

object robotRaton{
  const velocidad = 8
  const posicion = 12
  method velocidad() = velocidad 
  method posicion() = posicion 
}