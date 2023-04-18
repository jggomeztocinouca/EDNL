#include <Abin.hpp>

template<typename T>
bool similaresRec(const typename Abin<T>::nodo& nA, const typename Abin<T>::nodo& nB, const Abin<T>& A, const Abin<T>& B)
{
    if (nA == Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO)
    {
        return true; // Dos árboles vacíos son similares
    }
    else if ((nA == Abin<T>::NODO_NULO && nB != Abin<T>::NODO_NULO) || nA != Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO)
    {
        return false; // Si la ramificación es distinta, no son árboles similares
    }
    else
    {
        return similaresRec(A.hijoIzqdo(nA), B.hijoIzqdo(nB), A, B) && similaresRec(A.hijoDrcho(nA), B.hijoDrcho(nB), A, B);
    }
}

template<typename T>
bool similares(const Abin<T>& A, const Abin<T>& B)
{
    return similaresRec(A.raiz(), B.raiz(), A, B);
}