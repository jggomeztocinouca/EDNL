#include "../Agen/agenCeldasEnlazadas.cpp"

template <typename T>
Agen<T>::nodo busquedaNodo_Rec(const typename Agen<T>::nodo n, int x, const Agen<T>)
{
    if(n == Agen<T>::NODO_NULO)
    {
        return Agen<T>::NODO_NULO;
    }

    if()
}

template <typename T>
Agen<T>::nodo busquedaNodo(int x, const Agen<T>& A)
{
    return busquedaNodo_Rec(A.raiz(),x,A);
}


/*
 * Esquema para recorrer hijos de un Agen
 * nodo = A.hijoIzqd(n);
 * while(hijo!=NODO_NULO)
 * {
 *      LLamada recursiva;
 *      hijo = A.hermDrcho(hijo);
 *      A.eliminarHijoIzqdo(n);
 * }
 */