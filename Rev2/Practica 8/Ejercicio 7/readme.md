# Ejercicio 7
## El archipi�lago de Grecoland (Zuelandia) est� formado �nicamente por dos islas, Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2 ciudades son costeras (obviamente C1 ? N1 y C2 ? N2). 
## Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las ciudades del archipi�lago. 
## El hurac�n Isadore acaba de devastar el archipi�lago, con lo que todas las carreteras y puentes construidos en su d�a han desaparecido. 
## En esta terrible situaci�n se pide ayuda a la ONU, que acepta reconstruir el archipi�lago (es decir volver a comunicar todas las ciudades del archipi�lago) siempre que se haga al m�nimo coste.

## De cara a poder comparar costes de posibles reconstrucciones se asume lo siguiente:
### - El coste de construir cualquier carretera o cualquier puente es proporcional a su longitud (distancia eucl�dea entre las poblaciones de inicio y fin de la carretera o del puente).
### - Cualquier puente que se construya siempre ser� m�s caro que cualquier carretera que se construya.

## De cara a poder calcular los costes de VIAJAR entre cualquier ciudad del archipi�lago se considerar� lo siguiente:
### El coste directo de viajar, es decir de utilizaci�n de una carretera o de un puente, coincidir� con su longitud (distancia eucl�dea entre las poblaciones origen y destino de la carretera o del puente).

## En estas condiciones, implementa un subprograma que calcule el coste m�nimo de viajar entre dos ciudades de Grecoland, origen y destino, despu�s de haberse reconstruido el archipi�lago, dados los siguientes datos:
### - Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
### - Lista de ciudades de Deimos representadas mediante sus coordenadas cartesianas.
### - Lista de ciudades costeras de Fobos.
### - Lista de ciudades costeras de Deimos.
### - Ciudad origen del viaje.
### - Ciudad destino del viaje.