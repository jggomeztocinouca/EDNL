# Ejercicio 12
## El archipi�lago de Grecoland (Zuelandia) est� formado �nicamente por dos islas, Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2 ciudades son costeras (obviamente C1 ? N1 y C2 ? N2). 
## Se desea construir un puente que una ambas islas. 
## Nuestro problema es elegir el puente a construir entre todos los posibles, sabiendo que el coste de construcci�n del puente se considera irrelevante. 
## Por tanto, escogeremos aquel puente que minimice el coste global de viajar entre todas las ciudades de las dos islas, teniendo en cuenta las siguientes premisas:
### 1. Se asume que el coste viajar entre las dos ciudades que una el puente es 0.
### 2. Para poder plantearse las mejoras en el transporte que implica la construcci�n de un puente frente a cualquier otro, se asume que se realizar�n exactamente el mismo n�mero de viajes entre cualesquiera ciudades del archipi�lago. 
   ### Por ejemplo, se considerar� que el n�mero de viajes entre la ciudad P de Fobos y la Q de Deimos ser� el mismo que entre las ciudades R y S de la misma isla. 
   ### Dicho de otra forma, todos los posibles trayectos a realizar dentro del archipi�lago son igual de importantes.
## Dadas las matrices de costes directos de Fobos y Deimos y las listas de ciudades costeras de ambas islas, implementa un subprograma que calcule las dos ciudades que unir� el puente