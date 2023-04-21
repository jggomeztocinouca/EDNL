#include "../Abin/AbinCeldasEnlazadas.h"

template <typename T>
int numNietosNodo(typename Abin<T>::nodo n, Abin<T>& A)
{
    int contador = 0;

    typename Abin<T>::nodo hijoIzqdo = A.hijoIzqdo(n);
    typename Abin<T>::nodo hijoDrcho = A.hijoDrcho(n);
    if(hijoIzqdo != Abin<T>::NODO_NULO)
    {
        if(A.hijoIzqdo(hijoIzqdo) != Abin<T>::NODO_NULO){
            contador++;
        }


        if(A.hijoDrcho(hijoIzqdo) != Abin<T>::NODO_NULO) {
            contador++;
        }
    }

    if(hijoDrcho != Abin<T>::NODO_NULO) {
        if (A.hijoIzqdo(hijoDrcho) != Abin<T>::NODO_NULO) {
            contador++;
        }
        if (A.hijoDrcho(hijoDrcho) != Abin<T>::NODO_NULO) {
            contador++;
        }
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