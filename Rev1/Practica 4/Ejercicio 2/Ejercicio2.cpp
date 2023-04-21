#include <Abb.hpp>
#include <vector>

template<typename T>
void obtenerRecorrido(std::vector<T>& lista, Abb<T>& A)
{
    obtenerRecorrido(A.izqdo(), A);
    lista.push_back(A.elemento());
    obtenerRecorrido(A.drcho(),A);
}

template<typename T>
void insercionDicotomica(unsigned inicio, unsigned fin, Abb<T>& B, const std::vector<T>& lista){
    if(inicio==fin)
    {
        B.insertar(lista[inicio]);
    }
    else if (inicio < fin){
        unsigned mediana = fin + inicio / 2;
        B.insertar(lista[mediana]);
        insercionDicotomica(inicio, mediana-1, B, lista);
        insercionDicotomica(mediana+1, fin, B, lista);
    }
}

template<typename T>
void equilibrarAbb(Abb<T>& A)
{
    Abb<T> B;
    std::vector<T> lista;
    obtenerRecorrido(lista, A);
    insercionDicotomica(0,lista.size()-1,B,lista);
    A = B;
}
