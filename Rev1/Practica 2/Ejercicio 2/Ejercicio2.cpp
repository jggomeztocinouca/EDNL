#include <Abin.hpp>

template<typename T>
void arbolReflejadoRec(const typename Abin<T>::nodo& nA, const typename Abin<T>::nodo& nB, const Abin<T>& A, Abin<T>& B)
{
    if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoDrcho(nB, A.elemento(A.hijoIzqdo(nA)));
        arbolReflejadoRec(A.hijoIzqdo(nA), B.hijoDrcho(nB), A, B);
    }
    if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoIzqdo(nB, A.elemento(A.hijoDrcho(nA)));
        arbolReflejadoRec(A.hijoDrcho(nA), B.hijoIzqdo(nB), A, B);
    }
}

template<typename T>
const Abin<T> arbolReflejado(const Abin<T>& A)
{
    Abin<T> B;
    if (A.raiz() != Abin<T>::NODO_NULO)
    {
        B.insertarRaiz(A.raiz());
        arbolReflejadoRec(A.raiz(), B.raiz(), A, B);
    }
    return B;
}