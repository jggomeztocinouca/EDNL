#include <Abb.hpp>
#include<vector>

template<typename T>
void poda(const T& elemento, Abb<T>& A)
{
    A.buscar(elemento).~Abb();
}