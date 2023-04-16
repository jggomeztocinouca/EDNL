#include <Abin.hpp>

template<typename T>
int contarNodosRec(const typename Abin<T>::nodo& n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        return 1 + contarNodosRec(A.hijoIzqdo(n), A) + contarNodosRec(A.hijoDrcho(n),A)
    }
}

template<typename T>
int contarNodos(const Abin<T>& A)
{
    return contarNodosRec(A.raiz(), A);
}