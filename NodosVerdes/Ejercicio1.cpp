#include "../Abin/AbinCeldasEnlazadas.h"

// PRELUDIO: Contar el número de nodos de un árbol binario que cumplen la condición:

// Ejercicio 1: Tener exactamente 3 nietos

template <typename T>
int numNietosNodo(typename Abin<T>::nodo n, Abin<T>& A){
    int contador = 0;
    if(A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO){
        contador++;
    }
    if(A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO){
        contador++;
    }
    if(A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO){
        contador++;
    }
    if(A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO){
        contador++;
    }
    return contador;
}

template <typename T>
int tresNietosRec(typename Abin<T>::nodo n, Abin<T>& A){
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }

    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO)
    {
        if(numNietosNodo(n) == 3)
        {
            return 1 + tresNietosRec(A.hijoIzqdo(n),A) + tresNietosRec(A.hijoDrcho(n),A);
        }
    }
    return tresNietosRec(A.hijoIzqdo(n),A) + tresNietosRec(A.hijoDrcho(n),A);
}

template <typename T>
int tresNietos(Abin<T>& A)
{
    if(!A.arbolVacio())
    {
        return tresNietosRec(A, A.raizB());
    }
    else
    {
        return 0;
    }
}