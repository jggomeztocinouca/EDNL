#include <Abin.hpp>
#include <algorithm>

template<typename T>
int alturaNodo(const typename Abin<T>::nodo& n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO)
    {
        return -1; // La altura de un nodo hoja es 0,
        // pero generamos una llamada adicional con sus hijos izquierdo y derecho (Nulos)
    }
    else
    {
        return 1 + std::max(alturaNodo(A.hijoIzqdo(n),A), alturaNodo(A.hijoDrcho(n)),A);
    }
}

template<typename T>
int desequilibrioRec(const typename Abin<T>::nodo& n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return 0; // El desequilibrio en un árbol vacío es 0
    }
    else
    {
        int desequilibrioNodoActual = abs(alturaNodo(A.hijoIzqdo(n)) - alturaNodo(A.hijoDrcho(n)));
        return std::max(desequilibrioNodoActual, std::max(desequilibrioRec(A.hijoIzqdo(n),A), desequilibrioRec(A.hijoDrcho(n),A)));
    }
}

template<typename T>
int desequilibrio(const Abin<T>& A)
{
    return desequilibrioRec(A.raiz(), A);
}