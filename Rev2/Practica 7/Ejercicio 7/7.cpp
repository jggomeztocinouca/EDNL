#include <grafoPMC.h>
#include <alg_grafoPMC.h>

template<typename tCoste>
tCoste viajeCombinado(vector<typename GrafoP<tCoste>::vertice>& ruta,
                      typename GrafoP<tCoste>::vertice origen,
                      typename GrafoP<tCoste>::vertice destino,
                      typename GrafoP<tCoste>::vertice cambio1,
                      typename GrafoP<tCoste>::vertice cambio2,
                      const GrafoP<tCoste>& tren,
                      const GrafoP<tCoste>& bus)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    vector<vertice> caminosMinimosTren;
    vector<tCoste> costesMinimosTren = Dijkstra(tren, origen, caminosMinimosTren);

    vector<vertice> caminosMinimosBus;
    vector<tCoste> costesMinimosBus = DijkstraInv(bus, origen, caminosMinimosBus);

    ruta.push_back(origen);
    tCoste costeTotal = costesMinimosTren[cambio1] + costesMinimosBus[cambio1];
    if(costesMinimosTren[cambio2] + costesMinimosBus[cambio2] > costeTotal)
    {
        costeTotal = costesMinimosTren[cambio2] + costesMinimosBus[cambio2];
        ruta.push_back(cambio2);
    }
    else
    {
        ruta.push_back(cambio1);
    }
    ruta.push_back(destino);
    return costeTotal;
}

