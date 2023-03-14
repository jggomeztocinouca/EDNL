#include <algorithm>
#include "../Abin/AbinCeldasEnlazadas.h"
#include "./Ejercicio2.cpp"

// Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
// definido (el desequilibrio de un árbol binario) como el máximo desequilibrio de todos sus nodos.
// El desequilibrio de un nodo se define como la diferencia entre las alturas de los subárboles del mismo.

template <typename T>
int desiquilibrioRec(const Abin<T>& A, const typename Abin<T>::nodo n)
{
    if (n == Abin<T>::NODO_NULO){
        return -1; // Aunque es correcto, por definición el desequilibrio de un nodo_nulo es 0
    }
    else {
        int diferencia = std::abs(alturaRec(A, A.hijoIzquierdo(n)) - alturaRec(A, A.hijoDerecho(n)));
        return std::max(diferencia, std::max(desiquilibrioRec(A,A.hijoIzquierdo()), desiquilibrioRec(A,A.hijoDerecho())));
    }
}


