#include <grafoPMC.h>
#include <alg_grafoPMC.h>

template<typename tCoste>
struct parte{
    unsigned cargas;
    typename GrafoP<tCoste>::vertice ciudad;
};

template<typename tCoste>
tCoste cementosZuelandia(typename GrafoP<tCoste>::vertice capitalZuelandia,
                               const vector<parte<tCoste>> partes,
                               const GrafoP<tCoste>& G)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<vertice> caminosMinimos;
    vector<tCoste> distanciasMinimas = Floyd(G,caminosMinimos);

    tCoste distanciaTotal = 0;

    for(parte<tCoste> p : partes)
    {
        tCoste distanciaIdaVuelta = G[capitalZuelandia][p.ciudad] + G[p.ciudad][capitalZuelandia];
        distanciaTotal += (p.carga * distanciaIdaVuelta);
    }

    return distanciaTotal;
}