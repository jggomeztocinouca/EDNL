// El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de expresión.
// Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto de los nodos los operadores.
//a) Define el tipo de los elementos del árbol para que los nodos puedan almacenar operadores y operandos.
//b) Implementa una función que tome un árbol binario de expresión (aritmética) y devuelva el resultado de la misma.
// Por simplificar el problema se puede asumir que el árbol representa una expresión correcta.
// Los operadores binarios posibles en la expresión aritmética serán suma, resta, multiplicación y división

#include "../Abin/AbinCeldasEnlazadas.h"

typedef struct { // Alternativa a "atoi"
    char operador;
    char operando;
}registro ;

template<typename T>
int evaluacionArbol_Rec(const typename Abin<T>::nodo n, const Abin<T>& A)
{
    if (A.hijoIzquierdo(n) == Abin<T>::NODO_NULO && A.hijoDerecho(n) == Abin<T>::NODO_NULO){
        // Con comprobar el izquierdo, bastaría (un nodo hoja es un nodo que no tiene NINGÚN hijo)
        return atoi(A.elemento(n)); // Nodo hoja, contiene operando
    }
    else
    {
        switch (A.elemento(n))
        {
            default:
                break;
            case '+':
                return calculo_Rec(A.hijoIzquierdo(n)) + calculo_Rec(A.hijoDerecho(n));
            case '-':
                return calculo_Rec(A.hijoIzquierdo(n)) - calculo_Rec(A.hijoDerecho(n));
            case '*':
                return calculo_Rec(A.hijoIzquierdo(n)) * calculo_Rec(A.hijoDerecho(n));
            case '/':
                return calculo_Rec(A.hijoIzquierdo(n)) / calculo_Rec(A.hijoDerecho(n));
        }
    }
}


template<typename T>
int evaluacionArbol(const Abin<T>& A)
{
    return evaluacionArbol_Rec(A.raiz(), A);
}