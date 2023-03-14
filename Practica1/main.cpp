#include <iostream>
#include <fstream>
#include "../Abin/AbinCeldasEnlazadas.h"
#include "../Abin/abin_E-S.h"

/* ---------------------------------------------------------------------------------------- Ejercicio 1 ---------------------------------------------------------------------------------------- */

// Implementa un subprograma que calcule el número de nodos de un árbol binario

template<typename T>
int numeroNodosRec(Abin<T>& A, typename Abin<T>::nodo n){
    if(n==Abin<T>::NODO_NULO){
        return 0;
    } else {
        return 1 + numeroNodosRec(A, A.hijoIzquierdo(n)) + numeroNodosRec(A, A.hijoDerecho(n));
    }
}

template<typename T>
int numeroNodos(Abin<T>& A){
    return numeroNodosRec(A, A.raiz());
}

/* ---------------------------------------------------------------------------------------- Ejercicio 2 ---------------------------------------------------------------------------------------- */

// Implementa un subprograma que calcule la altura de un árbol binario

template<typename T>
int alturaRec(Abin<T>& A, typename Abin<T>::nodo n){
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else
        return (1 + std::max(alturaRec(A, A.hijoIzquierdo(n)), alturaRec(A, A.hijoDerecho(n))));
}

template<typename T>
int altura(Abin<T>& A){
    return alturaRec(A, A.raiz());
}

/* ---------------------------------------------------------------------------------------- Ejercicio 3 ---------------------------------------------------------------------------------------- */

// Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine la profundidad de este nodo en dicho árbol.

// Aquí, nos especifican que dados un árbol binario y un nodo, por lo que no es necesario hacer una función general que llame a otra.

template<typename T>
int getDepth(Abin<T>& A, typename Abin<T>::nodo n){
    if (n==A.raiz()){ // A priori
        return 0;
    } else {
        return 1 + getDepth(A,A.padre(n));
    }
}

// A posteriori sería n == NODO_NULO y restar -1 a la profundidad
// return -1 en vez de return 0

/* ---------------------------------------------------------------------------------------- Ejercicio 4 ---------------------------------------------------------------------------------------- */

// Añade dos nuevas operaciones al TAD árbol binario,
// una que calcule la profundidad de un nodo
// y otra que calcule la altura de un nodo
// en un árbol dado

// Implementa esta operación para la representación vectorial

/* ---------------------------------------------------------------------------------------- Ejercicio 5 ---------------------------------------------------------------------------------------- */

// Repite el ejercicio anterior para la representación enlazada de árboles binarios
// (punteros al padre, hijo izquierdo e hijo derecho).

template<typename T>
int alturaRecPractica1(typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }
    else {
        return (1 + std::max(alturaRecPractica1(n->hijoIzquierdo), alturaRecPractica1(n->hijoDerecho)));
    }
}

template<typename T>
int alturaPractica1(const Abin<T>& arbol){
    return alturaRecPractica1(arbol.r);
}

template<typename T>
int profundidadRecPractica1(typename Abin<T>::nodo n){
    if (n == Abin<T>::NODO_NULO){
        return 0;
    }
    else {
        return (1 + profundidadRecPractica1(n->padre));
    }
}

template<typename T>
int profundidadPractica1(const Abin<T>& arbol){
    return profundidadRecPractica1(arbol.raiz());
}

/* ------------------------------------------------------------------------------------ Programa de pruebas ------------------------------------------------------------------------------------ */

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
int main ()
{
    Abin<tElto> A, B;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin
    ofstream fs("abin.dat"); // Abrir fichero de salida.
    imprimirAbin(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();
    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B); // En std::cout

    // Ejercicio 1: Número de nodos
    cout << "Numero de nodos del árbol A: " << numeroNodos(A) << endl;

    // Ejercicio 2: Altura de un árbol binario
    cout << "Altura del árbol A: " << altura(A) << endl;

    // Ejercicio 3: Profundidad de un nodo del árbol A dado
    cout << "Profundidad de un nodo dado: " << getDepth(A, A.hijoDerecho(A.hijoIzquierdo(A.hijoIzquierdo(A.raiz()))));

    // Ejercicio 4: Altura y profundidad con métodos propios del TAD Abin Vectorial

    // Ejercicio 5: Altura y profundidad con métodos propios del TAD Abin Celdas Enlazadas


}