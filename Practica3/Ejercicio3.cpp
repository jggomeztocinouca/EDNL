#include <algorithm>
#include "../Agen/agenCeldasEnlazadas.cpp"

// Ejercicio 3: Se define el desequilibrio de un árbol general como:
// la máxima diferencia entre las alturas de los subárboles más bajo y más alto de cada nivel.
// Implementa un subprograma que calcule el grado de desequilibrio de un árbol general.

template <typename T>
int alturaNodoRec(const typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO)
    {
        return -1; // Altura de NODO_NULO
    }
    else
    {
        int altura = -1;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            altura = max(altura, alturaNodoRec(hijo,A));
            hijo = A.hermDrcho(n);
        }
        return 1 + altura;
    }
}

template <typename T>
int alturaMinRec(const typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO)
    {
        return -1; // Altura de NODO_NULO
    }
    else
    {
        int alturaMin = 0; // La altura mínima de todas las hojas es 0
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            alturaMin = std::min(alturaMin, alturaMinRec(hijo,A));
            hijo = A.hermDrcho(n);
        }
        return 1 + alturaMin;
    }
}

// Desequilibrio 0, 1 y 2 nivel = 0
template<typename T>
int desequilibrioRec(const typename Agen<T>::nodo n,  const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int altura = 0;
        while(hijo != Agen<T>::NODO_NULO)
        {
            altura = std::max(altura,
                              abs(alturaNodoRec(hijo,A)- alturaNodoRec(A.hermDrcho(hijo),A)));
            hijo = A.hermDrcho(n);
        }
        return std::max(altura,
                        std::max(desequilibrioRec(A.hijoIzqdo(n)),
                                 desequilibrioRec(A.hermDrcho(n)))
                        );
    }
}
