#include <alg_grafoPMC.h>
#include <alg_grafoMA.h>
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
class aerolinea{
public:
    aerolinea(size_t ciudadA, size_t ciudadB, tCoste d):ciudad1(ciudadA),ciudad2(ciudadB), distancia(d){}
    int ciudad1;
    int ciudad2;
    tCoste distancia;
};

template<typename tCoste>
std::vector<aerolinea<tCoste>> aerolineasNecesarias(size_t N, const std::vector<coordenadas>& ciudades, const Grafo& carreteras)
{
    matriz<bool> caminos = Warshall(carreteras);

    typedef typename Grafo::vertice vertice;

    GrafoP<tCoste> costesEntreIslas(N);

    Particion islas(N);

    size_t numIslas = N;

    for (vertice i = 0; i < N; ++i)
    {
        for (vertice j = 0; j < N; ++j)
        {
            if(!caminos[i][j])
            {
                costesEntreIslas[i][j] = sqrt(pow(ciudades[i].x - ciudades[j].x, 2) + pow(ciudades[i].y - ciudades[j].y, 2));
            }
            else
            {
                unsigned int representanteI = islas.encontrar(i);
                unsigned int representanteJ = islas.encontrar(j);
                if(representanteI!=representanteJ)
                {
                    islas.unir(representanteI,representanteJ);
                    numIslas--;
                }
            }
        }
    }

    vector<vector<aerolinea<tCoste>>> aerolineas(numIslas);

    return aerolineas;
}
