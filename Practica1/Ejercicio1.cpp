#include "../Abin/AbinCeldasEnlazadas.h"

// Implementa un subprograma que calcule el número de nodos de un árbol binario

template<typename T>
int numeroNodosRec(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(n==Abin<T>::NODO_NULO){
        return 0;
    } else {
        return 1 + numeroNodosRec(A, A.hijoIzquierdo(n)) + numeroNodosRec(A, A.hijoDerecho(n));
    }
}

template<typename T>
int numeroNodos(const Abin<T>& A){
    return numeroNodosRec(A, A.raiz());
}

