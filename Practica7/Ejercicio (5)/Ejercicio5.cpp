#include <grafoPMC.h>
#include <alg_grafoPMC.h>
#include <set>

using namespace std;

enum alergeno{carretera, tren, avion};

template<typename tCoste>
vector<bool> ciudadesAlcanzables(const size_t presupuesto, const alergeno alergia, const typename GrafoP<tCoste>::vertice origen, const GrafoP<tCoste>& road, const GrafoP<tCoste>& train, const GrafoP<tCoste>& plane) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<bool> ciudades;
    auto N = road.numVert();

    const GrafoP<tCoste>* G1 = nullptr;
    const GrafoP<tCoste>* G2 = nullptr;

    switch(alergia)
    {
        case carretera:
            G1 = &road;
            G2 = &train;
            break;
        case tren:
            G1 = &train;
            G2 = &plane;
            break;
        case avion:
            G1 = &plane;
            G2 = &road;
            break;
    }

    GrafoP<tCoste> costesUnificados(N);
    for(vertice i = 0; i < N; i++)
    {
        for(vertice j = 0; j < N; j++)
        {
            costesUnificados[i][j] = min((*G1)[i][j], (*G2)[i][j]);
        }
    }

    vector<tCoste> costes = Dijkstra(costesUnificados, origen, new vector<vertice>);

    for(vertice i = 0; i < N; i++)
    {
        if(costes[i] <= presupuesto)
        {
            ciudades[i] = true;
        }
    }

    return ciudades;
}
