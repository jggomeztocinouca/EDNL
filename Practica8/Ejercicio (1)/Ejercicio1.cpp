#include <alg_grafoPMC.h>
#include <grafoMA.h>
#include <vector>
#include <particion.h>
#include <grafoPMC.h>
#include <cmath>

class coordenadas{
public:
    coordenadas(unsigned int x = 0, unsigned int y = 0):x(x),y(y){}
    unsigned int x;
    unsigned int y;
};

template<typename tCoste>
matriz<tCoste> costesMinimosEntreCiudades(size_t N,
                                          const std::vector<coordenadas>& ciudades,
                                          const Grafo& carreteras)
{
    typedef typename Grafo::vertice vertice;

    GrafoP<tCoste> costesDirectos(N);

    Particion islas(N);

    for(vertice i = 0; i < N; i++)
    {
        for(vertice j = 0; j < N; j++)
        {
            if(carreteras[i][j])
            {
                costesDirectos[i][j] = sqrt(pow(ciudades[i].x - ciudades[j].x, 2) +
                                            pow(ciudades[i].y - ciudades[j].y, 2));
            }
        }
    }

    matriz<tCoste> costesMinimos = Floyd(costesDirectos, new matriz<tCoste>);

    for(vertice i = 0; i < N; i++)
    {
        for(vertice j = 0; j < N; j++)
        {
            unsigned int representanteI = islas.encontrar(i);
            unsigned int representanteJ = islas.encontrar(j);
            if( costesMinimos[i][j] != GrafoP<tCoste>::INFINITO &&
                representanteI != representanteJ)
            {
                islas.unir(representanteI, representanteJ);
            }
        }
    }

    return costesMinimos;
}