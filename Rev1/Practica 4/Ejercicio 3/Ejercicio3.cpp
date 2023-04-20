#include <Abb.hpp>

template<typename T>
void unionRec(Abb<T>& U, Abb<T>& A, Abb<T>& B)
{
    if(!A.vacio()){
        unionRec(U,A.izqdo(), B);
        U.insertar(A.elemento());
        unionRec(U,A.drcho(),B);
    }
    if(!B.vacio())
    {
        unionRec(U,A,B.izqdo());
        U.insertar(B.elemento());
        unionRec(U,A,B.drcho());
    }
}

template<typename T>
Abb<T> unionArboles(Abb<T>& A, Abb<T>& B){
    Abb<T> U;
    unionRec(U,A,B);
    return U;
}