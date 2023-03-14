// Para un árbol binario B, podemos construir el árbol binario reflejado B^R
// cambiando los subárboles izquierdo y derecho en cada nodo.
// Implementa un subprograma que devuelva el árbol binario reflejado de uno dado.

#include "../Abin/AbinCeldasEnlazadas.h"

template<typename T>
void arbolReflejado_Rec(const typename Abin<T>::nodo n1, const Abin<T>& A, const typename Abin<T>::nodo n2, Abin<T>& B)
{
    if(A.hijoIzquierdo(n1) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoDerecho(n2, A.elemento(A.hijoIzquierdo(n1)));
        arbolReflejado_Rec(A.hijoIzquierdo(n1), A, B.hijoDerecho(n2), B);
    }

    if(A.hijoDerecho(n1) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoIzquierdo(n2, A.elemento(A.hijoDerecho(n1)));
        arbolReflejado_Rec(A.hijoDerecho(n1), A, B.hijoIzquierdo(n2), B);
    }
}

template<typename T>
Abin<T> arbolReflejado(const Abin<T>& A)
{
    Abin<T> B;
    if (!A.arbolVacio())
    {
        B.insertarRaiz(A.elemento(A.raiz()));
        arbolReflejado_Rec(A.raiz(), A, B.raiz(), B);
    }

    return B;
}