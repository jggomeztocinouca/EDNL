#ifndef AGEN_H
#define AGEN_H
#include <cassert>

template <typename T> 
class Agen 
{
    struct celda;   // declaración adelantada privada
public:
    typedef celda* nodo;
    static const nodo NODO_NULO;
    Agen();                                // constructor
    void insertarRaiz(const T& e);
    void insertarHijoIzqdo(nodo n, const T& e);
    void insertarHermDrcho(nodo n, const T& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHermDrcho(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const;
    const T& elemento(nodo n) const; // acceso a elto, lectura
    T& elemento(nodo n);       // acceso a elto, lectura/escritura
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hermDrcho(nodo n) const;
    Agen(const Agen<T>& a);                // ctor. de copia
    Agen<T>& operator =(const Agen<T>& a); // asignación de árboles
    ~Agen();                               // destructor
private:
    struct celda 
    {
        T elto;
        nodo padre, hizq, heder;
        celda(const T& e, nodo p = NODO_NULO): elto(e),padre(p), hizq(NODO_NULO), heder(NODO_NULO) {}
    };
    nodo r;   // nodo raíz del árbol
    void destruirNodos(nodo& n);
    nodo copiar(nodo n);
}; //fin de la clase


/* Definición del nodo nulo */
template <typename T> const typename Agen<T>::nodo Agen<T>::NODO_NULO(0);

template <typename T>inline Agen<T>::Agen() : r(NODO_NULO) {}

template <typename T>inline void Agen<T>::insertarRaiz(const T& e)
{
    assert(r == NODO_NULO);   // árbol vacío
    r = new celda(e);
}

template <typename T>inline void Agen<T>::insertarHijoIzqdo(Agen<T>::nodo n, const T& e)
{
    assert(n != NODO_NULO);
    nodo hizqdo = n->hizq;   // hijo izqdo actual
    n->hizq = new celda(e, n);
    n->hizq->heder = hizqdo; // El actual hijo izqdo. se convierte en// hermano drcho. del nuevo hijo
}

template <typename T>inline void Agen<T>::insertarHermDrcho(Agen<T>::nodo n, const T& e)
{
    assert(n != NODO_NULO);
    assert(n != r);   // n no es la raíz
    nodo hedrcho = n->heder;
    n->heder = new celda(e, n->padre);
    n->heder->heder = hedrcho; // El actual hermano drcho. se convierte// en hermano drcho. del nuevo
}

template <typename T>inline void Agen<T>::eliminarHijoIzqdo(Agen<T>::nodo n)
{
    nodo hizqdo;
    assert(n != NODO_NULO);
    hizqdo = n->hizq;
    assert(hizqdo != NODO_NULO);       // existe hijo izqdo.
    assert(hizqdo->hizq == NODO_NULO); // hijo izqdo. es hoja// el hermano drcho. pasa a ser el nuevo hijo izqdo.
    n->hizq = hizqdo->heder;
    delete(hizqdo);
}

template <typename T>inline void Agen<T>::eliminarHermDrcho(Agen<T>::nodo n)
{
    nodo hedrcho;
    assert(n != NODO_NULO);
    hedrcho = n->heder;
    assert(hedrcho != NODO_NULO);       // existe hermano drcho.
    assert(hedrcho->hizq == NODO_NULO); // hermano drcho. es hoja// el hermano del hermano se convierte en el// nuevo hermano drcho. de n
    n->heder = hedrcho->heder;
    delete(hedrcho);
}

#endif