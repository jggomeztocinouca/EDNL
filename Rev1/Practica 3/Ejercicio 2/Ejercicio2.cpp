#include <Agen.hpp>

template<typename T>
int profundidadNodo(const typename Agen<T>::nodo& n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
    {
        return -1; // Motivo 1: La profundidad de un nodo nulo no es definible.
        // Motivo 2: Necesitamos que la llamada a este nodo nulo devuelva -1
        // porque generamos una llamada adicional (después de acceder a la raíz)
        // y no necesitamos que esta quede registrada
    }
    else
    {
        return 1 + profundidadNodo(A.padre(n),A);
    }
}
