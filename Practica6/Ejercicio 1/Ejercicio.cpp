#include <alg_grafoPMC.h>

/**
 * @brief Algoritmo de Dijkstra Inverso \n
 * Si el algoritmo de Dijkstra calcula los costes mínimos entre origen y todos los vértices,
 * el algoritmo inverso calculará los costes mínimos entre un destino común y todos los vértices.
 *
 * @tparam tCoste Tipo de dato asociado al coste de los arcos.
 * @param G Grafo ponderado. Asocia a cada vértice i del grafo una lista que almacena todos los vértices adyacentes a i.
 * @param destino Nodo destino.
 * @param P Vector de vértices tal que P[i] es el vértice anterior a i en el camino de coste mínimo desde origen hasta i.
 * @return Costes mínimos entre un destino común y todos los vértices
 */

template <typename tCoste>
vector<tCoste> DijkstraInv(const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice destino, vector<typename GrafoP<tCoste>::vertice>& P)
{
    typedef typename GrafoP<tCoste>::vertice vertice; // Para ahorrarnos escribir typename GrafoP<tCoste>::vertice cada vez que queramos usarlo.
    vertice v, w;
    const size_t n = G.numVert(); // Número de vertices en el grafo ponderado

}
