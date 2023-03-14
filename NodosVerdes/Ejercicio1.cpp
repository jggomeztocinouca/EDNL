#include "../Abin/AbinCeldasEnlazadas.h"

// PRELUDIO: Contar el número de nodos de un árbol binario que cumplen la condición:

// Ejercicio 1: Tener exactamente 3 nietos

template <typename T>
int tresNietosRec(typename Abin<T>::NODO_NULO n, Abin<T>& A){
    int contador = 0;
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO){
        // Terminar
    }
}

template <typename T>
int tresNietos(Abin<T>& A){
    int contador = 0;
    if(!A.arbolVacioB()){
        contador = tresNietosRec(A, A.raizB());
    }
}