#include <algorithm>
#include "../Abin/AbinCeldasEnlazadas.h"
#include "./Ejercicio2.cpp"
#include "./Ejercicio3.cpp"

// Implementa un subprograma que determine si un árbol binario es o no pseudo-completo.
// En este problema entenderemos que un árbol es pseudo-completo, si en el penúltimo nivel
// del mismo cada uno de los nodos tiene dos hijos o ninguno.

template<typename T>
bool pseudoRec(const Abin<T>& A, const typename Abin<T>::nodo& n, int altura){
    if(n == Abin<T>::NODO_NULO){
        return true; // Un árbol vacío o con un solo nodo es pseudocompleto
    } else {
        if(profundidad(n) != altura-1){
            return (pseudoRec(A,A.hijoIzquierdo(n),altura) && pseudoRec(A,A.hijoDerecho(n),altura));
        }else{
            if((A.hijoIzquierdo(n) != Abin<T>::NODO_NULO && A.hijoDerecho(n) == Abin<T>::NODO_NULO) ||
                (A.hijoIzquierdo(n) == Abin<T>::NODO_NULO && A.hijoDerecho(n) != Abin<T>::NODO_NULO))
                    return false;
            return true;
        }
    }
}

template<typename T>
bool pseudo(const Abin<T>& A){
    pseudoRec(A, A.raiz(), altura(A));
}