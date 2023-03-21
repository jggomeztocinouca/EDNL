#include "../Agen/agenCeldasEnlazadas.cpp"

// Ejercicio 2: Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol;
// determine la profundidad de éste nodo en el árbol.

template<typename T>
int profundidadRec(const Agen<T> &a, const typename Agen<T>::Nodo &n) {
    // if (n == Agen<T>::NODO_NULO) {
    //     return -1;
    // }
    if (n == a.raiz())
    {
        return 0;
    }
    else
    {
        return 1 + profundidadRec(a, a.padre(n));
    }
}

