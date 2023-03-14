// Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
// es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho similares.
// Implementa un subprograma que determine si dos árboles binarios son similares.

#include "../Abin/AbinCeldasEnlazadas.h"

template<typename T>
bool similaresRec(const typename Abin<T>::nodo n1, const Abin<T>& A, const typename Abin<T>::nodo n2, const Abin<T>& B){
    if (n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
    {
        return true; // Ambos nodos son nulos, por tanto son similares
    }
    else if (n1 == Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO)
    {
        return false; // Si ambos nodos no son nulos (simultáneamente), pero uno de ellos sí lo es, no son similares.
    }
    else
    {
        return  similaresRec(A.hijoIzquierdo(n1),   A,  B.hijoIzquierdo(n2), B) && // IMPORTANTE: Poner siempre nodo y después árbol
                similaresRec(A.hijoDerecho(n1),     A,  B.hijoDerecho(n2),   B);
    }
}

template<typename T>
bool similares(const Abin<T>& A, const Abin<T>& B){
    return similaresRec(A.raiz(), A, B.raiz(), B);
}

