#include <Abin.hpp>

template<typename T>
bool tiene3nietos(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO || A.hijoDrcho(n) == Abin<T>::NODO_NULO)
    {
        return false;
    }
    else
    {
        int contador = 0;
        typename Abin<T>::nodo hijoIzqdo = A.hijoIzqdo(n);
        typename Abin<T>::nodo hijoDrcho = A.hijoDrcho(n);
        if(hijoIzqdo != Abin<T>::NODO_NULO)
        {
            if(A.hijoIzqdo(hijoIzqdo) != Abin<T>::NODO_NULO){
                contador++;
            }

            if(A.hijoDrcho(hijoIzqdo) != Abin<T>::NODO_NULO) {
                contador++;
            }
        }
        if(hijoDrcho != Abin<T>::NODO_NULO) {
            if (A.hijoIzqdo(hijoDrcho) != Abin<T>::NODO_NULO) {
                contador++;
            }
            if (A.hijoDrcho(hijoDrcho) != Abin<T>::NODO_NULO) {
                contador++;
            }
        }
        if(contador!=3){
            return false;
        }
        else
        {
            return true;
        }
    }
}

template<typename T>
int tresNietosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        if(tiene3nietos(n,A))
        {
            return 1 + tresNietosRec(A.hijoIzqdo(n),A) + tresNietosRec(A.hijoDrcho(n),A);
        }
        else
        {
            return tresNietosRec(A.hijoIzqdo(n),A) + tresNietosRec(A.hijoDrcho(n),A);
        }
    }
}

template<typename T>
int tresNietos(const Abin<T>& A){
    return tresNietosRec(A.raiz(),A);
}
