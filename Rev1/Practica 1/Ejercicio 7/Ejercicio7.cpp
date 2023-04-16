#include <Abin.hpp>
#include <algorithm>

template<typename T>
bool condicionesPseudoCompleto(const typename Abin<T>::nodo& n, const Abin<T>& A)
{
    if ((A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO) ||
        (A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO))
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<typename T>
int alturaNodo(const typename Abin<T>::nodo& n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return -1; // La altura de un nodo hoja es 0.
        // Al generar una llamada adicional para los hijos izquierdo y derecho de la hoja (nulos),
        // deberemos compensar el falso incremento devolviendo -1.
    }
    else
    {
        return 1 + std::max(alturaNodo(A.hijoIzqdo(n),A), alturaNodo(A.hijoDrcho(n),A));
    }
}

template<typename T>
int profundidadNodo(const typename Abin<T>::nodo& n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return -1; // La profundidad no es aplicable a un árbol vacío,
        // ya que no hay nodo al que calcular una profundidad.
    }
    if(n == A.raiz())
    {
        return 0; // La profundidad del nodo raíz es 0.
    }
    else
    {
        return 1 + alturaNodo(A.padre(n),A);
    }
}

template<typename T>
bool pseudocompletoRec(const typename Abin<T>::nodo& n, int alturaArbol, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return true;
    }
    else
    {
        if(profundidadNodo(n,A) == alturaArbol-1) // Está en el penúltimo nivel
            // La profundidad del último nivel corresponde a la altura del árbol,
            // ya que la altura de un árbol es la longitud del camino desde el nodo más profundo hasta la raíz.
            // Por tanto, la profundidad del penúltimo nivel es igual a la altura del árbol - 1
        {
            return condicionesPseudoCompleto(n,A);
        }
        else
        {
            // Comprobamos la condición por cada subárbol que conforma el árbol
            return (pseudocompletoRec(A.hijoIzqdo(n), alturaArbol, A) && pseudocompletoRec(A.hijoDrcho(n), alturaArbol, A));
        }
    }
}

template<typename T>
bool pseudocompleto(const Abin<T>& A)
{
    int alturaArbol = alturaNodo(A.raiz(),A);
    return pseudocompletoRec(A.raiz(), alturaArbol, A);
}
