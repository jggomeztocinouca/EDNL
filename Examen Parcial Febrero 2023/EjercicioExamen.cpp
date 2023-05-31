#include <Agen.hpp>

template<typename T>
bool similares(typename Agen<T>::nodo nA, typename Agen<T>::nodo nB, const Agen<T>& A, const Agen<T>& B)
{
    if(nA == Agen<T>::NODO_NULO && nB == Agen<T>::NODO_NULO) // Árbol vacío
    {
        return true;
    }
    else if (A.hijoIzqdo(nA) == Agen<T>::NODO_NULO && B.hijoIzqdo(nB) == Agen<T>::NODO_NULO) // Son hojas
    {
        if(A.elemento(nA) == B.elemento(nB))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        typename Agen<T>::nodo hijoA = A.hijoIzqdo(nA);
        typename Agen<T>::nodo hijoB = B.hijoIzqdo(nB);
        while(hijoA != Agen<T>::NODO_NULO && hijoB != Agen<T>::NODO_NULO)
        {
            similares(hijoA, hijoB, A, B);
            hijoA = A.hermDrcho(hijoA);
            hijoB = B.hermDrcho(hijoB);
        }
        if(hijoA == Agen<T>::NODO_NULO && hijoB == Agen<T>::NODO_NULO)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

template<typename T>
bool similares(const Agen<T>& A, const Agen<T>& B)
{
    return similares(A.raiz(), B.raiz(), A, B);
}

#include <iostream>
#include <cassert>

void test_similares() {
    // Caso 1: Ambos árboles están vacíos.
    Agen<int> A1, B1;
    assert(similares(A1, B1) == true);

    // Caso 2: Un árbol está vacío y el otro no.
    Agen<int> A2, B2;
    A2.insertarRaiz(1);
    assert(similares(A2, B2) == false);

    // Caso 3: Ambos árboles contienen solo un nodo (la raíz).
    Agen<int> A3, B3;
    A3.insertarRaiz(1);
    B3.insertarRaiz(1);
    assert(similares(A3, B3) == true);

    // Caso 4: Los árboles tienen la misma estructura pero diferentes elementos.
    Agen<int> A4, B4;
    A4.insertarRaiz(1);
    B4.insertarRaiz(2);
    assert(similares(A4, B4) == false);

    // Caso 5: Los árboles tienen la misma estructura y los mismos elementos.
    Agen<int> A5, B5;
    A5.insertarRaiz(1);
    A5.insertarHijoIzqdo(A5.raiz(), 2);
    B5.insertarRaiz(1);
    B5.insertarHijoIzqdo(B5.raiz(), 2);
    assert(similares(A5, B5) == true);

    // Caso 6: Los árboles tienen diferentes estructuras pero algunos elementos en común.
    Agen<int> A6, B6;
    A6.insertarRaiz(1);
    A6.insertarHijoIzqdo(A6.raiz(), 2);
    B6.insertarRaiz(1);
    assert(similares(A6, B6) == false);

    std::cout << "Todos los tests pasaron correctamente." << std::endl;
}

int main() {
    test_similares();
    return 0;
}

