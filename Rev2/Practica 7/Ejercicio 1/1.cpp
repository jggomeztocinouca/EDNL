#include <alg_grafoPMC.h>
#include <grafoPMC.h>

template<typename tCoste>
tCoste viajeMillonario(typename GrafoP<tCoste>::vertice& origen,
                       typename GrafoP<tCoste>::vertice& destino,
                       const GrafoP<tCoste>& G)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    typename GrafoP<tCoste>::INFINITO Infinito;

    GrafoP<tCoste> GAux = G;

    size_t numVert = G.numVert();
    for(vertice i = 0; i < numVert; i++)
    {
        for(vertice j = 0; j < numVert; j++)
        {
            if(GAux[i][j] != Infinito)
            {
                GAux[i][j] = -GAux[i][j];
            }
        }
    }

    matriz<vertice> caminosMaximos;
    matriz<tCoste> costesMaximos = Floyd(GAux, caminosMaximos);

    tCoste costeMaximo = -Infinito;
    for(vertice i = 0; i < numVert; i++)
    {
        for(vertice j = 0; j < numVert; j++)
        {
            if(GAux[i][j] != Infinito)
            {
                GAux[i][j] = -GAux[i][j];
                if(GAux[i][j] > costeMaximo)
                {
                    costeMaximo = GAux[i][j];
                    origen = i;
                    destino = j;
                }
            }
        }
    }

    return costeMaximo;
}