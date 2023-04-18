#include <Abin.hpp>

struct{
    float operando;
    char operador;
} registro;

template<typename T>
float evaluacionRec(const typename Abin<T>::nodo& n, const Abin<T>& A)
{
    // Bastaría comprobar sólo con un hijo ya que para que un nodo sea hoja ambos hijos deben ser nulos.
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO) // Si es nodo hoja
    {
        return atoi(A.elemento(n)); // Contiene operando, que devolvemos
    }
    else // Si no es hoja, tiene dos hijos, que pueden ser hojas (operandos) o intermedios también (operadores)
    {
        switch (A.elemento(n))
        {
            case '+':
                return evaluacionRec(A.hijoIzqdo(n), A) + evaluacionRec(A.hijoDrcho(n), A);
            case '-':
                return evaluacionRec(A.hijoIzqdo(n), A) - evaluacionRec(A.hijoDrcho(n), A);
            case 'x':
                return evaluacionRec(A.hijoIzqdo(n), A) * evaluacionRec(A.hijoDrcho(n), A);
            case '/':
                return evaluacionRec(A.hijoIzqdo(n), A) / evaluacionRec(A.hijoDrcho(n), A);
        }
    }
}

template<typename T>
float resultado(const Abin<T>& A)
{
    return evaluacionRec(A.raiz(), A);
}