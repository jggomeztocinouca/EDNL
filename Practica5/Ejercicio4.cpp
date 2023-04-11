// Un árbol es estrictamente ternario si todos sus nodos son hojas o tienen tres hijos.
// Escribe una función que, dado un árbol de grado arbitrario, nos indique si es o no estrictamente ternario.

#include "../Agen/Agen.hpp"

template<typename T>
bool ternarioRec(const typename Agen<T>::nodo& n, const Agen<T>& A){
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
        return true;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int numHijos = 0;
        while(hijo != Agen<T>::NODO_NULO){
            numHijos++;
            hijo = A.hermDrcho(hijo);
        }
        if(numHijos != 3)
            return false;
        else{
            hijo = A.hijoIzqdo(n);
            while(hijo != Agen<T>::NODO_NULO){
                if(!ternarioRec(hijo, A))
                    return false;
                hijo = A.hermDrcho(hijo);
            }
            return true;
        }
    }
}

template<typename T>
bool ternario(const Agen<T>& A){
    return ternarioRec(A.raiz(), A);
}