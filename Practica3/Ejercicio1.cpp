#include "../Agen/agenCeldasEnlazadas.cpp"

// Ejercicio 1: Implementa un subprograma que dado un árbol general nos calcule su grado. El grado de un árbol es el máximo número de hijos que tiene un nodo.


//  El grado de un árbol se define como el máximo número de hijos que tiene un nodo.
template <typename T>
// La función toma dos argumentos: un nodo n del árbol general A
// y devuelve un entero que representa el grado del árbol.
int gradoRec(const typename Agen<T>::nodo n, const Agen<T>& A)
{
    if (n == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int grado = 0;
        while(hijo != Agen<T>::NODO_NULO)
        {
            hijo = A.hermDrcho(n);
            grado++;
        }
        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            grado = max(grado, gradoRec(n));
            hijo = A.hermDrcho(n);
        }
        return grado;
    }
}

template <typename T>
int grado(const Agen<T>& A){
    return gradoRec(A.raiz(),A);
}