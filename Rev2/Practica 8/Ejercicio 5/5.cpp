#include <grafoPMC.h>
#include <alg_grafoPMC.h>

template<typename tCoste>
tCoste longitudMinFibra(const GrafoP<tCoste>& G)
{
    auto GMax = Kruskall(G);

    typedef typename GrafoP<tCoste>::vertice vertice;

    size_t numVert = G.numVert();
    tCoste longitud = 0;
    for(vertice i = 0; i < numVert; i++)
    {
        for(vertice j = 0; j < numVert; j++)
        {
            if(GMax[i][j] != GrafoP<tCoste>::INFINITO)
            {
                longitud += GMax[i][j];
            }
        }
    }

    return longitud;
}
