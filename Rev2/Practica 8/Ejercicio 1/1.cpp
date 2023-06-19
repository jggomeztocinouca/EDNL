#include <grafoMA.h>
#include <particion.h>
#include <vector>
#include <cmath>
#include "alg_grafoPMC.h"

/*
 * - A islas
 * - En cada isla, B ciudades
 * - En cada isla, conexión entre todas las ciudades
 *
 * Obtener:
 * - Distribución de las islas (a qué isla pertenece cada ciudad)
 * - Coste mínimo viajar entre cualquier par de ciudades de una misma isla
 */
struct coordenas{
    int x;
    int y;
};

template<typename tCoste>
matriz<tCoste> distribucionIslas(vector<unsigned>& distribucion,
                         vector<coordenas> coordenadasCiudades,
                         const Grafo& G)
{
    typedef typename Grafo::vertice vertice;
    size_t numVert = G.numVert();
    Particion p(numVert);
    for(vertice i = 0; i < numVert; i++)
    {
        for(vertice j = 0; j < numVert; j++)
        {
            if(G[i][j])
            {
                unsigned representanteI = p.encontrar(i);
                unsigned representanteJ = p.encontrar(j);
                if(representanteI != representanteJ)
                {
                    p.unir(representanteI,representanteJ);
                }
            }
        }
    }

    GrafoP<tCoste> GAux(numVert);

    for(vertice i = 0; i < numVert; i++)
    {
        for (vertice j = 0; j < numVert; j++)
        {
            if(G[i][j]){
                GAux[i][j] = sqrt(pow(coordenadasCiudades[i].x - coordenadasCiudades[j].x, 2) +
                                  pow(coordenadasCiudades[i].y - coordenadasCiudades[j].y, 2));
            }
        }

    }

    matriz<vertice> caminosMinimos;
    return Floyd(GAux,caminosMinimos);
}


