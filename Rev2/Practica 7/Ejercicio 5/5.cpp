#include <grafoPMC.h>
#include <alg_grafoPMC.h>

enum alergia{CARRETERA, TREN, AVION};

template<typename tCoste>
vector<typename GrafoP<tCoste>::vertice> viajeroAlergico(alergia alergiaViajero,
                                                         unsigned dinero,
                                                         typename GrafoP<tCoste>::vertice ciudadOrigen,
                                                         const GrafoP<tCoste>& carretera,
                                                         const GrafoP<tCoste>& tren,
                                                         const GrafoP<tCoste>& avion)
{
    size_t numVert = carretera.numVert();
    GrafoP<tCoste> transporteCombinado(numVert);
    typedef typename GrafoP<tCoste>::vertice vertice;
    for(vertice i = 0; i < numVert; i++)
    {
        for(vertice j = 0; j < numVert; j++)
        {
            transporteCombinado[i][j] = GrafoP<tCoste>::INFINITO;
            if(alergiaViajero != CARRETERA)
            {
                transporteCombinado[i][j] = carretera[i][j];
            }
            if(alergiaViajero != TREN)
            {
                transporteCombinado[i][j] = std::min(transporteCombinado[i][j], tren[i][j]);
            }
            if(alergiaViajero!=AVION)
            {
                transporteCombinado[i][j] = std::min(transporteCombinado[i][j], avion[i][j]);
            }
        }
    }

    vector<vertice> caminosMinimos;
    vector<tCoste> distanciasMinimas = Dijkstra(ciudadOrigen,caminosMinimos);

    vector<vertice> ciudadesAlcanzables;
    for(vertice i = 0; i < numVert; i++){
        if(distanciasMinimas[i] <= dinero)
        {
            ciudadesAlcanzables.push_back(i);
        }
    }

    return ciudadesAlcanzables;
}
