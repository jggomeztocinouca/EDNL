#include <grafoPMC.h>
#include <alg_grafoPMC.h>

template<typename tCoste>
GrafoP<tCoste> emasajer(const GrafoP<tCoste>& G)
{
    auto GAux = G;
    typedef typename GrafoP<tCoste>::vertice vertice;

    size_t numVert = G.numVert();
    for(vertice i = 0; i < numVert; i++)
    {
        for(vertice j = 0; j < numVert; j++)
        {
            GAux[i][j] *= -1;
        }
    }

    auto GMax = Kruskall(GAux);

    return GMax;
}