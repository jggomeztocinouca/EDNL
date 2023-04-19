#include <Agen.hpp>
#include <algorithm>

template<typename T>
int alturaNodoRec(const typename Agen<T>::nodo& n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
    {
        return -1;
        // La definición de altura no es aplicable a un nodo nulo,
        // pero al generar una llamada adicional para llegar a este (desde una hoja),
        // deberemos contrarrestarlo devolviendo -1.
    }
    else
    {
        int altura = INT_MIN;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            altura = std::max(altura, alturaNodoRec(hijo,A) + 1);
            hijo = A.hermDrcho(hijo);
        }
        return altura;
    }
}

template<typename T>
int desequilibrioAux(const typename Agen<T>::nodo& n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
    {
        return -1; // La diferencia de alturas de un árbol vacío es 0
        // Al generar una llamada adicional (para llegar al nodo nulo),
        // deberemos contrarrestar devolviendo -1
    }
    else
    {
        int alturaMin = INT_MAX;
        int alturaMax = INT_MIN;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            alturaMin = std::min(alturaMin, alturaNodoRec(hijo, A) + 1);
            alturaMax = std::max(alturaMax, alturaNodoRec(hijo, A) + 1);
            hijo = A.hermDrcho(hijo);
        }
        return alturaMax-alturaMin;
    }
}

template<typename T>
int desequilibrio(const Agen<T>& A)
{
    return desequilibrioAux(A.raiz(),A);
}