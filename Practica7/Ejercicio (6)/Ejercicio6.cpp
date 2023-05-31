#include<alg_grafoPMC.h>
#include<grafoPMC.h>

using namespace std;

// ¿estos viajes como pueden hacerse? ¿solo en tren? ¿solo en autobus? ¿en ambos?
// 4 maneras:
// 1. solo en tren
// 2. solo en autobus
// 3. en tren y autobus
// 4. en bus y tren

template<typename tCoste>
matriz<tCoste> tarifaMinima(typename GrafoP<tCoste>::vertice ciudadTransbordo, const GrafoP<tCoste>& tren, const GrafoP<tCoste>& autobus)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    auto N = tren.numVert();
    auto costesTren = Floyd(tren, new matriz<vertice>);
    auto costesAutobus = Floyd(autobus, new matriz<vertice>);
    matriz<tCoste> tarifa(tren.numVert());
    for(vertice i = 0; i < N; i++)
    {
        for(vertice j = 0; j < N; j++)
        {
            auto costeDirecto = min(costesTren[i][j], costesAutobus[i][j]);
            auto costeCombinado = min(suma(costesTren[i][ciudadTransbordo],     costesAutobus[ciudadTransbordo][j]),
                                      suma(costesAutobus[i][ciudadTransbordo],  costesTren[ciudadTransbordo][j]));
            tarifa[i][j] = min(costeDirecto,costeCombinado);
        }
    }
    return tarifa;
}