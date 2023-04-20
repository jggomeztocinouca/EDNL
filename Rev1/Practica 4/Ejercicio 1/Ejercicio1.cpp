#include <Abb.hpp>

template<typename T>
void poda(const T& elemento, Abb<T>& A)
{
    A.buscar(elemento).~Abb();
}