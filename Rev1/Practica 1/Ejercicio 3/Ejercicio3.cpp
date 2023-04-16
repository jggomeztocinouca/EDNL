#include <Abin.hpp>

template<typename T>
int profundidadNodoRec(const typename Abin<T>::nodo& n, const Abin<T>& A){
    if(n == A.raiz())
    {
        return 0; // La profundidad del nodo raíz es 0
    }
    else if(n == Abin<T>::NODO_NULO){
        return -1; // El concepto de profundidad no se aplica a árboles vacíos
    }
    else
    {
        return 1 + profundidadNodoRec(A.padre(n),A);
    }
}
