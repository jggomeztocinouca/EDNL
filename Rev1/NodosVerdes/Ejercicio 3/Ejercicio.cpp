#include "AbinCeldasEnlazadas.h"

// PRELUDIO: Contar el número de nodos de un árbol binario que cumplen la condición:

// Ejercicio 2: Ser nostálgicos. Definimos un nodo nostálgico como aquel que tiene más pasado que futuro, es decir son los nodos que tienen más antecesores propios que descendientes propios.

template <typename T>
int profundidadNodo(typename Abin<T>::nodo n, Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return -1;
    }
    else
    {
        return 1 + profundidadRec(A.padre(n));
    }

}

template <typename T>
int numAntecesoresPropiosNodo(typename Abin<T>::nodo n, Abin<T>& A)
{
    // return profundidadNodo(n, A) + 1; No es necesario un +1, por definición, un antecesor propio es un ancestro, distinto de sí mismo.
    return profundidadNodo(n, A);
}

template <typename T>
int numSucesoresPropiosNodo(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        1 + numSucesoresPropiosNodo(A.hijoIzqdo(n),A) + numSucesoresPropiosNodo(A.hijoDrcho(n), A);
    }
}

template<typename T>
int nostalgicoRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        if(numAntecesoresPropiosNodo(n,A) > numSucesoresPropiosNodo(n,A))
        {
            return 1 + nostalgicoRec(A.hijoIzqdo(n),A) + nostalgicoRec(A.hijoDrcho(n),A);
        }
        else
        {
            return nostalgicoRec(A.hijoIzqdo(n),A) + nostalgicoRec(A.hijoDrcho(n),A);
        }
    }
}