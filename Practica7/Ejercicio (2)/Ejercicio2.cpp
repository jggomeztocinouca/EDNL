#include <cstdio>
#include <cmath>

// laberinto --> n^2 casilla1s --> grafo de n^2 nodos --> mcostes n^2 * n^2
// 1. paso --> construir matriz costes {0:Diagonal, 1:Casilla Ady, INFINITO:No Ady}
// si adyacencia(casilla) --> coste = 1
// si no adyacencia(casilla) --> coste = INFINITO mcostes[i][j]
// tipo casilla
typedef struct{
    size_t fila;
    size_t columna;
}casilla;

casilla nodoCasilla (vertice n, int N)
{
    // convertir de nodo enumerado a casilla
    casilla c;
    c.fila = n / N;
    c.columna = n % N;
    return c;
}


bool adyacencia(casilla c1, casilla c2)
{
    return abs(c1.fila - c2.fila) + abs(c1.columna - c2.columna);
}

// 3 paso --> recorrer vector paredes y modificar matriz costes

// tipo sara carbonero (pared)
typedef struct{
    casilla casilla1;
    casilla casilla2;
}pared;


vertice casillaNodo (casilla c, int N)
{
    // convertir de casilla a nodo enumerado
    return c.fila * N + c.columna;
}

// llamar a camino
// pasar camino a casilla