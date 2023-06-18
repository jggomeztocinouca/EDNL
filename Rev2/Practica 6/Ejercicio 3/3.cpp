#include <alg_grafoPMC.h>
#include <grafoPMC.h>
#include <particion.h>

template<typename tCoste>
bool esSubvencionable(const GrafoP<tCoste>& G)
{
    Particion p(G.numVert());

    typedef typename GrafoP<tCoste>::vertice vertice;

    for(vertice i = 0; i < G.numVert(); i++)
    {
        for(vertice j = 0; j < G.numVert(); j++)
        {
            if(G[i][j] != GrafoP<tCoste>::INFINITO)
            {
                unsigned int representanteI = p.encontrar(i);
                unsigned int representanteJ = p.encontrar(j);
                if(representanteI == representanteJ)
                {
                    return false;
                }
                else
                {
                    p.unir(representanteI,representanteJ);
                }
            }
        }
    }
    return true;
}
