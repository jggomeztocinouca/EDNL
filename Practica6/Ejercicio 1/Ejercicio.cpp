#include "alg_grafoPMC.h"

template <typename tCoste>
vector<tCoste> DijkstraInv(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice destino,
                        vector<typename GrafoP<tCoste>::vertice>& P)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice v, w;
    const size_t n = G.numVert();
    vector<bool> S(n, false);                  // Conjunto de vértices vacío.
    vector<tCoste> D;                          // Costes mínimos desde destino.

    // Iniciar D y P con caminos directos desde el vértice destino.
    D = G[destino]; // Distancia directa desde cualquier origen al destino (existe arco --> coste, no existe arco --> infinito)
    D[destino] = 0;                             // Coste destino-destino es 0.
    P = vector<vertice>(n, destino);

    // Calcular caminos de coste mínimo hasta cada vértice.
    S[destino] = true;                          // Incluir vértice destino en S.
    for (size_t i = 1; i <= n-2; i++) {
        // Seleccionar vértice w no incluido en S
        // con menor coste desde destino.
        tCoste costeMin = GrafoP<tCoste>::INFINITO;
        for (v = 0; v < n; v++)
            if (!S[v] && D[v] <= costeMin) {
                costeMin = D[v];
                w = v;
            }
        S[w] = true;                          // Incluir vértice w en S.
        // Recalcular coste hasta cada v no incluido en S a través de w.
        for (v = 0; v < n; v++)
            if (!S[v]) {
                tCoste Owv = suma(G[v][w], D[w]); // coste origen hasta v pasando por w
                if (Owv < D[v]) {
                    D[v] = Owv;
                    P[v] = w;
                }
            }
    }
    return D;
}