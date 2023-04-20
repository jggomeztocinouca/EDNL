#include <Agen.hpp>

typename Agen<int>::nodo busquedaNodoRec(const typename Agen<int>::nodo& n, int x, const Agen<int>& A)
{
    if(n == Agen<int>::NODO_NULO)
    {
        return Agen<int>::NODO_NULO;
    }
    else if(A.elemento(n) == x)
    {
        return n;
    }
    else
    {
        typename Agen<int>::nodo nodoBuscar = Agen<int>::NODO_NULO;
        typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<int>::NODO_NULO && nodoBuscar == Agen<int>::NODO_NULO)
        {
            nodoBuscar = busquedaNodoRec(hijo, x, A);
            hijo = A.hermDrcho(n);
        }
        return nodoBuscar;
    }
}

typename Agen<int>::nodo busquedaNodo(int x, const Agen<int>& A)
{
    return busquedaNodoRec(A.raiz(), x, A);
}

void podaNodoRec(const typename Agen<int>::nodo& n, Agen<int>& A)
{
    if(n != Agen<int>::NODO_NULO)
    {
        typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<int>::NODO_NULO)
        {
            podaNodoRec(hijo,A);
            A.eliminarHijoIzqdo(n);
            hijo = A.hermDrcho(hijo);
        }
    }
}

void podaNodo(int x, Agen<int>& A)
{
    if(!A.arbolVacio()) {
        typename Agen<int>::nodo nodoPodar = busquedaNodo(x,A);
        if(nodoPodar != Agen<int>::NODO_NULO)
        {
            podaNodoRec(nodoPodar, A);
        }
    }
}