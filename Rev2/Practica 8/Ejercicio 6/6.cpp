#include <grafoPMC.h>
#include <alg_grafoPMC.h>

template<typename tCoste>
GrafoP<tCoste> emasajer(tCoste subvencionCaudal,
                        tCoste costeKm,
                        const GrafoP<tCoste>& distancias,
                        const GrafoP<tCoste>& caudales)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    size_t numVert = distancias.numVert();
    GrafoP<tCoste> GAux (numVert);
    for(vertice i = 0; i < numVert; i++)
    {
        for(vertice j = 0; j < numVert; j++)
        {
            if(distancias[i][j] != GrafoP<tCoste>::INFINITO && caudales[i][j] != GrafoP<tCoste>::INFINITO)
            {
                GAux[i][j] = (distancias[i][j]*costeKm - caudales[i][j]*subvencionCaudal);
            }
        }
    }

    auto GMax = Kruskall(GAux);

    return GMax;
}