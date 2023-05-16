#include <grafoPMC.h>
#include <alg_grafoPMC.h>
#include <set>

using namespace std;

enum alergeno{carretera, tren, avion};

template<typename tCoste>
set<typename GrafoP<tCoste>::vertice> ciudadesAlcanzables(const size_t presupuesto, const alergeno alergia, const typename GrafoP<tCoste>::vertice origen, const GrafoP<tCoste>& road, const GrafoP<tCoste>& train, const GrafoP<tCoste>& plane) {
    set<typename GrafoP<tCoste>::vertice> ciudades;
    auto nodos = road.numVert();

    if(alergia != carretera)
    {
        auto ciudadesCarretera = Dijkstra(road, origen, new vector<typename GrafoP<tCoste>::vertice>);
        for(size_t i = 0; i < nodos; i++)
        {
            if(ciudadesCarretera[i] <= presupuesto && i != origen)
                ciudades.insert(i);
        }

    }
    if(alergia != tren)
    {
        auto ciudadesTren = Dijkstra(train, origen, new vector<typename GrafoP<tCoste>::vertice>);
        for(size_t i = 0; i < nodos; i++)
        {
            if(ciudadesTren[i] <= presupuesto && i != origen)
                ciudades.insert(i);
        }
    }
    if(alergia != avion)
    {
        auto ciudadesAvion = Dijkstra(plane, origen, new vector<typename GrafoP<tCoste>::vertice>);
        for(size_t i = 0; i < nodos; i++)
        {
            if(ciudadesAvion[i] <= presupuesto && i != origen)
                ciudades.insert(i);
        }
    }
    return ciudades;
}
