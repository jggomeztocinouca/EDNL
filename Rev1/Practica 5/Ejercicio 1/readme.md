# Ejercicio 1
## Dado un árbol binario de enteros donde el valor de cada nodo es menor que el de sus hijos, implementa un subprograma para eliminar un valor del mismo preservando la propiedad de orden establecida. Explica razonadamente la elección de la estructura de datos.
### Nota: Se supone que en el árbol no hay elementos repetidos, y que el número de nodos del mismo no está acotado

La clave de este ejercicio es caer en que no se puede hacer con un APO, ya que te proporcionan un árbol binario, sin especificar ningún tipo, además de la indicación de que no hay elementos repetidos (en los APOs sí que los hay) y el número de elementos no está acotado (en el APO, al tener una implementación vectorial de posiciones relativas, el número de elementos sí está acotado).