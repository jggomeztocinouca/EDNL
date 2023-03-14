#include "../Abin/AbinCeldasEnlazadas.h"

// PRELUDIO: Contar el número de nodos de un árbol binario que cumplen la condición:

// Ejercicio 2: Tener el  doble de nietos que de bisnietos

template <typename T>
int numNietosNodo(typename Abin<T>::nodo n, Abin<T>& A)
{
    int contador = 0;
    if(A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO)
    {
        contador++;
    }
    if(A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO)
    {
        contador++;
    }
    if(A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO)
    {
        contador++;
    }
    if(A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO)
    {
        contador++;
    }
    return contador;
}

template <typename T>
int numBisnietosNodo(typename Abin<T>::nodo n, Abin<T>& A)
{
    int contador = 0;
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
    {
        contador += numNietosNodo(A.hijoIzqdo(n), A);
    }
    if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
    {
        contador += numNietosNodo(A.hijoDrcho(n), A);
    }
    return contador;
}

template <typename T>
int dobleBisnietosRec(typename Abin<T>::nodo n, Abin<T>& A)

{
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else if(numNietosNodo(n, A) == 2 * numBisnietosNodo(n, A))
    {
        return 1 + dobleBisnietosRec(A.hijoIzqdo(n), A) + dobleBisnietosRec(A.hijoDrcho(n), A);
    }
    else
    {
        return dobleBisnietosRec(A.hijoIzqdo(n), A) + dobleBisnietosRec(A.hijoDrcho(n), A);
    }
}


template <typename T>
int dobleBisnietos(Abin<T>& A){
    int contador = 0;
    if(!A.arbolVacioB()){
        contador = dobleBisnietosRec(A, A.raizB());
    }
    return contador;
}