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
        typename Agen<T>::nodo h = A.hijoIzqdo(n);
        int contador = 0;
        while(h != Agen<T>::NODO_NULO)
        {
            contador++;
            h = A.hermDrcho(h);
        }
        return max(contador,max(gradoRec(A.hijoIzqdo(n),A), gradoRec(A.hermDrcho(n),A)));
    }
}