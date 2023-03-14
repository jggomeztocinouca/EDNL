#include <algorithm>
#include "../Abin/AbinCeldasEnlazadas.h"

// Implementa un subprograma que calcule la altura de un árbol binario

template<typename T>
int alturaRec(const Abin<T>& A, const typename Abin<T>::nodo n){
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else
        return (1 + std::max(alturaRec(A, A.hijoIzquierdo(n)), alturaRec(A, A.hijoDerecho(n))));
}

template<typename T>
int altura(const Abin<T>& A){
    return alturaRec(A, A.raiz());
}

