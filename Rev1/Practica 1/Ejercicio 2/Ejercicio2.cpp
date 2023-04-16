#include <Abin.hpp>
#include <algorithm>

template<typename T>
int alturaRec(const typename Abin<T>::nodo& n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return -1; // La altura de un nodo hoja es 0.
        // Al generar una llamada adicional para acceder a este nodo nulo (A.hijoIzqdo o A.hijoDcho),
        // se produce un falso incremento que deberemos compensar devolviendo -1.
    }
    else {
        return 1 + std::max(
                    alturaRec(A.hijoIzqdo(n),A),
                    alturaRec(A.hijoDrcho(n),A)
                )
    }
}

template<typename T>
int altura(const Abin<T>& A)
{
    return alturaRec(A.raiz(), A);
}