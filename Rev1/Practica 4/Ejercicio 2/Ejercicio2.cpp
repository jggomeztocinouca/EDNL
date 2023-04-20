#include <Abb.hpp>

template<typename T>
void equilibrarAbbRec(const Abb<T>& A, Abb<T>& B)
{
    if(!A.vacio())
    {
        equilibrarAbbRec(A.izqdo(),B);
        B.insertar(A.elemento());
        equilibrarAbbRec(A.drcho(),B);
    }
}

template<typename T>
void equilibrarAbb(Abb<T>& A)
{
    Abb<T> B;
    equilibrarAbbRec(A,B);
    A = B;
}