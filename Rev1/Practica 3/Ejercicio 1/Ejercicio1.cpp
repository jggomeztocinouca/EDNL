#include <Agen.hpp>
#include <algorithm>

template<typename T>
int contarHijosNodos(const typename Agen<T>::nodo& n, const Agen<T>& A)
{
    int hijos = 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    while(hijo != Agen<T>::NODO_NULO)
    {
        hijos++;
        hijo = A.hermDrcho(n);
    }
    return hijos;
}

template<typename T>
int gradoArbolRec(const typename Agen<T>::nodo& n, const Agen<T>& A)
{
    int grado = contarHijosNodos(n,A); // Grado árbol vacío
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    while(hijo != Agen<T>::NODO_NULO)
    {
        grado = std::max(grado, gradoArbolRec(hijo,A));
        hijo = A.hermDrcho(hijo);
    }
    return grado;
}

template<typename T>
int gradoArbol(const Agen<T>& A)
{
    return gradoArbolRec(A.raiz(),A);
}
