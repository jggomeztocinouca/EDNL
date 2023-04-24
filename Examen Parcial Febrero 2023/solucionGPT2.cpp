#include <Agen.hpp>

template<typename T>
bool similares(typename Agen<T>::nodo nA, typename Agen<T>::nodo nB, const Agen<T>& A, const Agen<T>& B)
{
    if(nA == Agen<T>::NODO_NULO && nB == Agen<T>::NODO_NULO) // Árbol vacío
    {
        return true;
    }
    else if (A.hijoIzqdo(nA) == Agen<T>::NODO_NULO && B.hijoIzqdo(nB) == Agen<T>::NODO_NULO) // Son hojas
    {
        if(A.elemento(nA) == B.elemento(nB))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        typename Agen<T>::nodo hijoA = A.hijoIzqdo(nA);
        typename Agen<T>::nodo hijoB = B.hijoIzqdo(nB);
        while(hijoA != Agen<T>::NODO_NULO && hijoB != Agen<T>::NODO_NULO)
        {
            if (!similares(hijoA, hijoB, A, B)) // Agregar condición
            {
                return false;
            }
            hijoA = A.hermDrcho(hijoA); // Corregir argumento
            hijoB = B.hermDrcho(hijoB); // Corregir argumento
        }
        if(hijoA == Agen<T>::NODO_NULO && hijoB == Agen<T>::NODO_NULO)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

template<typename T>
bool similares(const Agen<T>& A, const Agen<T>& B)
{
    return similares(A.raiz(), B.raiz(), A, B);
}