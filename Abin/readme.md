# Especificación de las operaciones del TAD Abin

### Abin ()
#### Post-condición: 
Crea y devuelve un árbol vacío.
### void insertarRaiz (const T& e)
#### Pre-condición: 
El árbol está vacío.
#### Post-condición: 
Inserta el nodo raíz cuyo contenido será e. 
### void insertarHijoIzqdo (nodo n, const T& e)
#### Pre-condición: 
n es un nodo del árbol que no tiene hijo izquierdo.
#### Post-condición: 
Inserta el elemento e como hijo izquierdo del nodo n. 
### void insertarHijoDrcho (nodo n, const T& e)
#### Pre-condición:  
n es un nodo del árbol que no tiene hijo derecho.
#### Post-condición: 
Inserta el elemento e como hijo derecho del nodo n.
### void eliminarHijoIzqdo (nodo n)
#### Pre-condición: 
n es un nodo del árbol.
Existe hijoIzqdoB(n) y es una hoja.
#### Post-condición:  
Destruye el hijo izquierdo del nodo n. 
### void eliminarHijoDrcho (nodo n)
#### Pre-condición: 
n es un nodo del árbol.
Existe hijoDrchoB(n) y es una hoja.
#### Post-condición:  
Destruye el hijo derecho del nodo n. 
### void eliminarRaiz ()
#### Pre-condición: 
El árbol no está vacío y raiz() es una hoja.
#### Post-condición: 
Destruye el nodo raíz. El árbol queda vacío
### bool arbolVacio () const
#### Post-condición: 
Devuelve true si el árbol está vacío y false en caso contrario.
### const T& elemento(nodo n) const
### const T& elemento(nodo n)
#### Pre-condición: 
n es un nodo del árbol.
#### Post-condición: 
Devuelve el elemento del nodo n.
### nodo raíz () const
#### Post-condición: 
Devuelve el nodo raíz del árbol. Si el árbol está vacío, devuelve NODO_NULO. 
### nodo padre (nodo n) const
#### Pre-condición:  
n es un nodo del árbol.
#### Post-condición: 
Devuelve el padre del nodo n. Si n es el nodo raíz, devuelve NODO_NULO. 
### nodo hijoIzqdo (nodo n) const
#### Pre-condición: 
n es un nodo del árbol.
#### Post-condición: 
Devuelve el nodo hijo izquierdo del nodo n. Si no existe, devuelve
NODO_NULO. 
### nodo hijoDrcho (nodo n) const
#### Pre-condición: 
n es un nodo de A. 
#### Post-condición:  
Devuelve el nodo hijo derecho del nodo n. Si no existe, devuelve
NODO_NULO.
