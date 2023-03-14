#ifndef ABIN_ABINCELDASENLAZADAS_H
#define ABIN_ABINCELDASENLAZADAS_H

#include <cassert>
template <typename T> class Abin {
    struct celda; // Declaración adelantada privada
public:
    typedef celda* nodo;
    static const nodo NODO_NULO;
    Abin(); // Constructor
    void insertarRaiz(const T& elemento);
    void insertarHijoIzquierdo(nodo n, const T& elemento);
    void insertarHijoDerecho(nodo n, const T& elemento);
    void eliminarHijoIzquierdo(nodo n);
    void eliminarHijoDerecho(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const;
    const T& elemento(nodo n) const; // Lectura en Abin const
    T& elemento(nodo n); // Lectura/Escritura en Abin no-const
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzquierdo(nodo n) const;
    nodo hijoDerecho(nodo n) const;
    Abin(const Abin<T>& arbol); // Ctor. de copia
    Abin<T>& operator =(const Abin<T>& arbol); // Asignación de árboles
    ~Abin(); // Destructor

    int alturaNodo(nodo);
    int profundidadNodo(nodo);

private:
    struct celda {
        T elemento;
        nodo padre, hijoIzquierdo, hijoDerecho;
        celda(const T& elemento, nodo p = NODO_NULO): elemento(elemento),
                                               padre(p), hijoIzquierdo(NODO_NULO), hijoDerecho(NODO_NULO) {}
    };
    nodo r; // nodo raíz del árbol
    void destruirNodos(nodo& n);
    nodo copiar(nodo nodoOriginal);
};

/* Definición del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(nullptr);

/*-------------------------------------------------------- Métodos públicos --------------------------------------------------------*/
template <typename T>
inline Abin<T>::Abin() : r(NODO_NULO) {}
template <typename T>
inline void Abin<T>::insertarRaiz(const T& elemento)
{
    assert(r == NODO_NULO); // Árbol vacío
    r = new celda(elemento);
}
template <typename T>
inline void Abin<T>::insertarHijoIzquierdo(nodo n, const T& elemento){
    assert(n != NODO_NULO);
    assert(n->hijoIzquierdo == NODO_NULO); // No existe hijo izquierdo.
    n->hijoIzquierdo = new celda(elemento, n);
}

template <typename T>
inline void Abin<T>::insertarHijoDerecho(nodo n, const T& elemento){
    assert(n != NODO_NULO);
    assert(n->hijoDerecho == NODO_NULO); // No existe hijo derecho.
    n->hijoDerecho = new celda(elemento, n);
}
template <typename T>
inline void Abin<T>::eliminarHijoIzquierdo(nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hijoIzquierdo != NODO_NULO); // Existe hijo izquierdo.
    assert(n->hijoIzquierdo->hijoIzquierdo == NODO_NULO && // Hijo izquierdo.
                                         n->hijoIzquierdo->hijoDerecho == NODO_NULO); // es hoja.
    delete n->hijoIzquierdo;
    n->hijoIzquierdo = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarHijoDerecho(nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hijoDerecho != NODO_NULO); // Existe hijo derecho.
    assert(n->hijoDerecho->hijoIzquierdo == NODO_NULO && // Hijo derecho.
                                        n->hijoDerecho->hijoDerecho == NODO_NULO); // es hoja
    delete n->hijoDerecho;
    n->hijoDerecho = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarRaiz()
{
    assert(r != NODO_NULO); // Árbol no vacío.
    assert(r->hijoIzquierdo == NODO_NULO &&
           r->hijoDerecho == NODO_NULO); // La raíz es hoja.
    delete raiz;
    r = NODO_NULO;
}

template <typename T> inline bool Abin<T>::arbolVacio() const{ return (r == NODO_NULO); }
template <typename T>
inline const T& Abin<T>::elemento(nodo n) const
{
    assert(n != NODO_NULO);
    return n->elemento;
}
template <typename T>
inline T& Abin<T>::elemento(nodo n)
{
    assert(n != NODO_NULO);
    return n->elemento;
}
template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const
{ return r; }

template <typename T> inline
typename Abin<T>::nodo Abin<T>::padre(nodo n) const
{
    assert(n != NODO_NULO);
    return n->padre;
}
template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzquierdo(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hijoIzquierdo;
}
template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDerecho(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hijoDerecho;
}

template <typename T>
inline Abin<T>::Abin(const Abin<T>& arbol)
{
    r = copiar(arbol.raiz); // Copiar raíz y descendientes.
}
template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& arbol)
{
    if (this != &arbol) // Evitar autoasignación.
    {
        this->~Abin(); // Vaciar el árbol.
        r = copiar(arbol.raiz); // Copiar raíz y descendientes.
    }
    return *this;
}

template <typename T>
inline Abin<T>::~Abin()
{
    destruirNodos(r); // Vaciar el árbol.
}

/*-------------------------------------------------------- Métodos privados --------------------------------------------------------*/
// Destruye un nodo y todos sus descendientes
template <typename T>
void Abin<T>::destruirNodos(nodo& n)
{
    if (n != NODO_NULO)
    {
        destruirNodos(n->hijoIzquierdo);
        destruirNodos(n->hijoDerecho);
        delete n;
        n = NODO_NULO;
    }
}

// Devuelve una copia de un nodo y todos sus descendientes
template <typename T>
typename Abin<T>::nodo Abin<T>::copiar(nodo nodoOriginal)
{
    nodo nodoCopia = NODO_NULO;
    if (nodoOriginal != NODO_NULO) {
        nodoCopia = new celda(nodoOriginal->elemento); // Copiar n.
        nodoCopia->hijoIzquierdo = copiar(nodoOriginal->hijoIzquierdo); // Copiar subárbol izquierdo.
        if (nodoCopia->hijoIzquierdo != NODO_NULO)
            nodoCopia->hijoIzquierdo->padre = nodoCopia;
        nodoCopia->hijoDerecho = copiar(nodoOriginal->hijoDerecho); // Copiar subárbol derecho.
        if (nodoCopia->hijoDerecho != NODO_NULO)
            nodoCopia->hijoDerecho->padre = nodoCopia;
    }
    return nodoCopia;
}

#endif //ABIN_ABINCELDASENLAZADAS_H
