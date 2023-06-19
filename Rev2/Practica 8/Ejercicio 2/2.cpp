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

struct lineaAerea{
    typedef typename Grafo::vertice vertice;
    vertice ciudad1;
    vertice ciudad2;
};

template<typename tCoste>
vector<lineaAerea> aerolineasTombuctu(const Grafo& conexionesDirectas)
{
    size_t numCiudades = conexionesDirectas.numVert();

}