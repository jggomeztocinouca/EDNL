#include "../Abin/AbinCeldasEnlazadas.h"

// Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine la profundidad de este nodo en dicho árbol.

// Aquí, nos especifican que dados un árbol binario y un nodo, por lo que no es necesario hacer una función general que llame a otra.

template<typename T>
int profundidad(const Abin<T>& A, const typename Abin<T>::nodo n){
    if (n==A.raiz()){ // A priori
        return 0;
    } else {
        return 1 + profundidad(A,A.padre(n));
    }
}

 // A posteriori sería n == NODO_NULO y restar -1 a la profundidad
 // return -1 en vez de return 0