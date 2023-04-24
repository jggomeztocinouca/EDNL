#include <Agen.hpp>

template<typename T>
bool similares(typename Agen<T>::nodo nA, typename Agen<T>::nodo nB, const Agen<T>& A, const Agen<T>& B)
{
    if(nA == Agen<T>::NODO_NULO && nB == Agen<T>::NODO_NULO) // Árbol vacío
    {
        return true;
    }
    else if(nA == Agen<T>::NODO_NULO || nB == Agen<T>::NODO_NULO) // Uno de los nodos es nulo
    {
        return false;
    }
    else if (A.hijoIzqdo(nA) == Agen<T>::NODO_NULO && B.hijoIzqdo(nB) == Agen<T>::NODO_NULO) // Son hojas
    {
        return A.elemento(nA) == B.elemento(nB);
    }
    else
    {
        typename Agen<T>::nodo hijoA = A.hijoIzqdo(nA);
        typename Agen<T>::nodo hijoB = B.hijoIzqdo(nB);

        while(hijoA != Agen<T>::NODO_NULO && hijoB != Agen<T>::NODO_NULO)
        {
            if(!similares(hijoA, hijoB, A, B))
            {
                return false;
            }
            hijoA = A.hermDrcho(hijoA);
            hijoB = B.hermDrcho(hijoB);
        }

        // Si ambos hijos son nulos, entonces los árboles son similares
        return (hijoA == Agen<T>::NODO_NULO && hijoB == Agen<T>::NODO_NULO);
    }
}

template<typename T>
bool similares(const Agen<T>& A, const Agen<T>& B)
{
    return similares(A.raiz(), B.raiz(), A, B);
}
