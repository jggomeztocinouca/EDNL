#include <algorithm>
#include "../Abin/AbinCeldasEnlazadas.h"

// Repite el ejercicio anterior para la representación enlazada de árboles binarios
// (punteros al padre, hijo izquierdo e hijo derecho).

template<typename T>
int alturaNodo(const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }
    else {
        return (1 + std::max(alturaRecPractica1(n->hijoIzquierdo), alturaRecPractica1(n->hijoDerecho)));
    }
}

template<typename T>
int alturaNodoGeneral(const Abin<T>& arbol, const typename Abin<T>::nodo n){
    return arbol.profundidadNodo(n);
}

template<typename T>
int profundidadNodo(const typename Abin<T>::nodo n){
    if (n == Abin<T>::NODO_NULO){
        return 0;
    }
    else {
        return (1 + profundidadRecPractica1(n->padre));
    }
}

template<typename T>
int profundidadNodoGeneral(const Abin<T>& arbol, const typename Abin<T>::nodo n){
    return arbol.profundidadNodo(n);
}
