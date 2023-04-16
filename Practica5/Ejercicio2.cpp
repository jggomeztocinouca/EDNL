/* Un montículo min-max tiene una estructura similar a la de un montículo ordinario (árbol parcialmente ordenado),
 * pero la ordenación parcial consiste en que los elementos que se encuentran en un nivel par (0, 2, 4,...)
 * son menores o iguales que sus elementos descendientes,
 * mientras que los elementos que se encuentran en un nivel impar (1, 3, 5,...) son mayores o iguales que sus descendientes.
 * Esto quiere decir que para cualquier elemento e de un nivel par se cumple abuelo ≤ e ≤ padre y para cualquier elemento e de un nivel impar padre ≤ e ≤ abuelo.
 * Implementa una operación de orden logarítmico para añadir un elemento a un montículo min-max almacenado en un vector de posiciones relativas
 */

#include "../Apo/Apo.hpp"
#include <math.h>

template<typename T>
void intercambiarPadre(const size_t& indice, const T& e, const Apo<T>& A){
    const T aux = A.nodos[A.padre(indice)];
    A.nodos[A.padre(indice)] = e;
    A.nodos[indice] = aux;
    indice = A.padre(indice);
}

template<typename T>
void intercambiarAbuelo(const size_t& indice, const T& e, const Apo<T>& A){
    const T aux = A.nodos[A.padre(A.padre(indice))];
    A.nodos[A.padre(A.padre(indice))] = e;
    A.nodos[indice] = aux;
    indice = A.padre(A.padre(indice));
}

template<typename T>
size_t insertarMinMax(const T& e, const Apo<T>& A){
    if(A.numNodos <= A.maxNodos)
    {
        size_t indice = A.numNodos;
        A.nodos[indice] = e;
        A.numNodos++;
        if(A.numNodos > 1)
        {
            unsigned int h = log2(A.numNodos);
            if(h%2 == 0) // Si el nivel es par, el padre es un min y el abuelo un max
            {
                if(e < A.nodos[A.padre(indice)]){
                    intercambiarPadre(&indice, e, A);
                    while(indice > 0 &&  e < A.nodos[indice])
                    {

                    }
                }
                else if (e > A.nodos[A.padre(A.padre(indice))])
                {
                    intercambiarAbuelo(&indice, e, A);
                    while()
                    {

                    }
                }
            }
            else
            {
                if(e > A.nodos[A.padre(indice)]){
                    intercambiarPadre(&indice, e, A);
                    {

                    }
                }
                else if (e < A.nodos[A.padre(A.padre(indice))])
                {
                    intercambiarAbuelo(&indice, e, A);
                    {

                    }
                }
            }
        }
    }
}