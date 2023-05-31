#include <grafoPMC.h>
#include <alg_grafoPMC.h>

using namespace std;

/*template<typename tCoste>
tCoste tarifaMinima(typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino, size_t costeTaxi, const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<tCoste> costesTren, costesBus; // Matriz de costes
    matriz<vertice> PTren, PBus; // Matriz de caminos
    costesTren = Floyd(tren, PTren);
    costesBus = Floyd(bus, PBus);
    tCoste costeDirecto = min(costesTren[origen][destino], costesBus[origen][destino]);
    tCoste costeCombinado = GrafoP<tCoste>::INFINITO;
    tCoste coste1Transbordo = GrafoP<tCoste>::INFINITO;
    tCoste coste2Transbordos = GrafoP<tCoste>::INFINITO;
    size_t N = tren.numVert();
    for(vertice i = 0; i<N; i++)
    {
        if(coste1Transbordo > min(suma(costesTren[origen][i],   costesBus[i][destino])    + costeTaxi,
                                  suma(costesBus[origen][i],    costesTren[i][destino])   + costeTaxi))
        {
            coste1Transbordo = min(suma(costesTren[origen][i],  costesBus[i][destino])      + costeTaxi,
                                   suma(costesBus[origen][i],   costesTren[i][destino])     + costeTaxi);
        }
        for(vertice j = 0; j < N; j++)
        {

            if(costeCombinado > coste1Transbordo || costeCombinado > coste2Transbordos)
            {
                costeCombinado = min(coste1Transbordo, coste2Transbordos);
            }
        }
    }
    return min(costeDirecto,costeCombinado);
}*/
