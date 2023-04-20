
#include <Abin.hpp>

template<typename T>
typename Abin<T>::nodo busquedaNodoRec(const typename Abin<T>::nodo& n, T elemento, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return Abin<T>::NODO_NULO;
    }
    else if (A.elemento(n) == elemento)
    {
        return n;
    }
    else
    {
        typename Abin<T>::nodo nodoBuscado = Abin<T>::NODO_NULO;
        nodoBuscado = busquedaNodoRec(A.hijoIzqdo(n),elemento,A);
        if(nodoBuscado == Abin<T>::NODO_NULO)
        {
            nodoBuscado = busquedaNodoRec(A.hijoDrcho(n),elemento,A);
        }
        return nodoBuscado;
    }
}

template<typename T>
typename Abin<T>::nodo busquedaNodo(T elemento, const Abin<T>& A)
{
    return busquedaNodoRec(A.raiz(), elemento, A);
}

template<typename T>
void eliminarNodo(const typename Abin<T>::nodo& n, Abin<T>& A)
{
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
    { // Es un nodo hoja
        if(n == A.raiz())
        {
            A.eliminarRaiz();
        }
        else if(n == A.hijoIzqdo(A.padre(n)))
        {
            A.eliminarHijoIzqdo(A.padre(n));
        }
        else
        {
            A.eliminarHijoDrcho(A.padre(n));
        }
    }
    else
    {
        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO)
        {
            if(A.elemento(A.hijoIzqdo(n)) < A.elemento(A.hijoDrcho(n)))
            {
                A.elemento(n) = A.elemento(A.hijoIzqdo(n));
                eliminarNodo(A.hijoIzqdo(n));
            }
            else{
                A.elemento(n) = A.elemento(A.hijoDrcho(n));
                eliminarNodo(A.hijoDrcho(n));
            }
        }
        else if (A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
        {
            A.elemento(n) = A.elemento(A.hijoIzqdo(n));
            eliminarNodo(A.hijoIzqdo(n));
        }
        else
        {
            A.elemento(n) = A.elemento(A.hijoDrcho(n));
            eliminarNodo(A.hijoDrcho(n));
        }
    }
}