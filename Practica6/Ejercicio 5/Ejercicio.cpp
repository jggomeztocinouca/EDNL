#include "alg_grafoPMC.h"

template <typename tCoste>
vector<tCoste> DijkstraAdy(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice origen,
                        vector<typename GrafoP<tCoste>::vertice>& P)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice v, w;
    const size_t n = G.numVert();
    vector<bool> S(n, false);                  // Conjunto de vértices vacío.
    vector<tCoste> D;                          // Costes mínimos desde origen.

    // Iniciar D y P con caminos directos desde el vértice origen.
    D = G[origen];
    D[origen] = 0;                             // Coste origen-origen es 0.
    P = vector<vertice>(n, origen);

    // Calcular caminos de coste mínimo hasta cada vértice.
    S[origen] = true;                          // Incluir vértice origen en S.
    for (size_t i = 1; i <= n-2; i++) {
        // Seleccionar vértice w no incluido en S
        // con menor coste desde origen.
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
                tCoste Owv = suma(D[w], G[w][v]);
                if (Owv < D[v]) {
                    D[v] = Owv;
                    P[v] = w;
                }
            }
    }
    return D;
}
