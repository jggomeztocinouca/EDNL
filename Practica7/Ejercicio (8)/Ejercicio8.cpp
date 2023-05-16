#include <grafoPMC.h>
#include <alg_grafoPMC.h>

using namespace std;

// djikstra bus
// djikstra tren
// dijkstrainv bus
// dijkstrainv tren

template<typename tCoste>
tCoste tarifaMinima(typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino, const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<tCoste> costesTren, costesBus; // Matriz de costes
    matriz<vertice> PTren, PBus; // Matriz de caminos
    costesTren = Floyd(tren, PTren);
    costesBus = Floyd(bus, PBus);
    tCoste costeDirecto = min(costesTren[origen][destino], costesBus[origen][destino]);
    tCoste costeCombinado = GrafoP<tCoste>::INFINITO;
    size_t N = tren.numVert();
    for(vertice i = 0; i<N; i++)
    {
        tCoste costeActual = min(suma(costesTren[origen][i] ,costesBus[i][destino]),
                                 suma(costesBus[origen][i]  ,costesTren[i][destino]));
        if(costeActual < costeCombinado)
        {
            costeCombinado = costeActual;
        }
    }
    return min(costeDirecto,costeCombinado);
}
