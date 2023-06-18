#include <grafoPMC.h>
#include <alg_grafoPMC.h>

template<typename tCoste>
unsigned int costeMinimoDistribucion(vector<size_t>& stockDescargado,
                                     unsigned stock,
                                     vector<size_t> capacidadAlmacenes,
                                     typename GrafoP<tCoste>::vertice centroProduccion,
                                     const vector<unsigned> porcentajeSubvenciones,
                                     const GrafoP<tCoste>& G)
{
    GrafoP<tCoste> GAux = G;
    vector<size_t> capacidadRestanteAlmacenes = capacidadAlmacenes;
    unsigned stockRestante = stock;

    typedef typename GrafoP<tCoste>::vertice vertice;

    size_t nCiudades = GAux.numVert();

    for(vertice ciudadDestino = 1; ciudadDestino < nCiudades; ciudadDestino++)
    {
        GAux[centroProduccion][ciudadDestino] *= (1-(porcentajeSubvenciones[ciudadDestino]/100));
    }

    vector<vertice> caminosMinimos;
    vector<tCoste> costesMinimos = Dijkstra(GAux,centroProduccion,caminosMinimos);

    bool ciudadesDescargadas [nCiudades];
    ciudadesDescargadas[0] = true;
    for(size_t stock : stockDescargado)
    {
        stock = 0;
    }
    int nCiudadesDescargadas = 0;
    unsigned costeTotal;
    vertice ciudad;
    while(stockRestante != 0 && nCiudadesDescargadas != nCiudades)
    {
        ciudad = -1;
        int costeMinimo = GrafoP<tCoste>::INFINITO;
        for(int i = 0; i < nCiudades; i++)
        {
            if(!ciudadesDescargadas[i])
            {
                if (costesMinimos[i] < costeMinimo)
                {
                    ciudad = i;
                }
            }
        }
        if(ciudad != -1)
        {
            costeTotal += costesMinimos[ciudad];
            ciudadesDescargadas[ciudad] = true;
            nCiudades++;
            if(capacidadRestanteAlmacenes[ciudad] > stockRestante)
            {
                capacidadRestanteAlmacenes[ciudad] -= stockRestante;
                stockDescargado[ciudad] = stockRestante;
                stockRestante = 0;
            }
            else
            {
                stockDescargado[ciudad] = (stockRestante - capacidadRestanteAlmacenes[ciudad]);
                stockRestante -= capacidadRestanteAlmacenes[ciudad];
                capacidadRestanteAlmacenes[ciudad] = 0;
            }
        }
    }

    return costeTotal;
}
