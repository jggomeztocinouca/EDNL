/*
 * - Número desconocido de islas
 * - Número desconocido de ciudades en cada isla
 * - Cada ciudad tiene un aeropuerto
 * - Número total de ciudades en el archipiélago (conjunto de todas las islas)
 * - En cada isla, hay carreteras entre las distintas ciudades [Matriz de adyacencia]
 * - Coordenadas cartesianas (x,y) para ciudad [distancia euclídea]
 * - Premisas:
 * 1. Una única línea entre cada par de islas
 * 2. Distancia de la aerolínea mínima
 * - Objetivo:
 * ENCONTRAR QUÉ LÍNEAS AÉREAS SE DEBEN IMPLANTAR
 */

#include <grafoPMC.h>
#include <grafoMA.h>
#include <alg_grafoPMC.h>
#include <cmath>

struct lineaAerea{
    typedef typename Grafo::vertice vertice;
    vertice ciudad1;
    vertice ciudad2;
};

struct coordenadas{
    int x;
    int y;
};

double distanciaEuclidea(coordenadas coordenada1, coordenadas coordenada2)
{
    return sqrt(pow(coordenada1.x - coordenada2.x, 2) +
                pow(coordenada1.y - coordenada2.y, 2));
}

template<typename tCoste>
vector<lineaAerea> aerolineasTombuctu(const vector<coordenadas>& coordenadasCiudad,
                                      const Grafo& conexionesDirectas)
{
    size_t numCiudades = conexionesDirectas.numVert();
    typedef typename Grafo::vertice vertice;

    Particion p(numCiudades);

    for(vertice i = 0; i < numCiudades; i++)
    {
        for(vertice j = 0; j < numCiudades; j++)
        {
            if(conexionesDirectas[i][j])
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


    GrafoP<tCoste> GAux(numCiudades);
    for(vertice i = 0; i < numCiudades; i++)
    {
        for(vertice j = 0; j < numCiudades; j++)
        {
            if(p.encontrar(i) != p.encontrar(j))
            {
                GAux[i][j] = distanciaEuclidea(coordenadasCiudad[i],coordenadasCiudad[j]);
            }
        }
    }



}