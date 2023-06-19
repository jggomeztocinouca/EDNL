#include <grafoPMC.h>
#include <alg_grafoPMC.h>
#include <cmath>

struct coordenadas{
    int x;
    int y;
};

struct puente{
    size_t ciudadCostera1;
    size_t ciudadCostera2;
};

double distanciaEuclidea(coordenadas c1, coordenadas c2)
{
    return sqrt(pow((abs(c1.x-c2.x)),2) +
                pow((abs(c1.y-c2.y)),2));
}

template <typename tCoste>
tCoste isadore(const vector<coordenadas>& ciudadesFobos,
               const vector<coordenadas>& ciudadesDeimos,
               const vector<coordenadas>& cCosterasFobos,
               const vector<coordenadas>& cCosterasDeimos,
               typename GrafoP<tCoste>::vertice origen,
               typename GrafoP<tCoste>::vertice destino)
{
    size_t N1 = ciudadesFobos.size();
    size_t N2 = ciudadesDeimos.size();
    size_t C1 = cCosterasFobos.size();
    size_t C2 = cCosterasDeimos.size();

    typedef typename GrafoP<tCoste>::vertice vertice;

    GrafoP<tCoste> Fobos(N1);
    GrafoP<tCoste> Deimos(N2);

    for(vertice i = 0; i < N1; i++)
    {
        for(vertice j = 0; j < N1; j++)
        {
            Fobos[i][j] = distanciaEuclidea(ciudadesFobos[i],ciudadesFobos[j]);
        }
    }

    for(vertice i = 0; i < N2; i++)
    {
        for(vertice j = 0; j < N2; j++)
        {
            Deimos[i][j] = distanciaEuclidea(ciudadesFobos[i],ciudadesFobos[j]);
        }
    }

    Fobos = Kruskall(Fobos);
    Deimos = Kruskall(Deimos);

    GrafoP<tCoste> Grecoland(N1+N2);

    for(vertice i = 0; i < N1; i++)
    {
        for(vertice j = 0; j < N1; j++)
        {
            Grecoland[i][j] = Fobos[i][j];
        }
    }

    for(vertice i = N1; i < N2; i++)
    {
        for(vertice j = N1; j < N2; j++)
        {
            Grecoland[i][j] = Deimos[i][j];
        }
    }

    tCoste distanciaMinimaPuente = GrafoP<tCoste>::INFINITO;
    puente puenteMinimo;
    for(vertice ciudadCostera1 : cCosterasFobos)
    {
        for(vertice ciudadCostera2 : cCosterasDeimos)
        {
            double distEuclidea = distanciaEuclidea(ciudadCostera1, ciudadCostera2);
            if(distEuclidea <= distanciaMinimaPuente)
            {
                distanciaMinimaPuente = distEuclidea;
                puenteMinimo.ciudadCostera1 = ciudadCostera1;
                puenteMinimo.ciudadCostera2 = ciudadCostera2;
            }
        }
    }

    Grecoland[puenteMinimo.ciudadCostera2 + N1][puenteMinimo.ciudadCostera1] = distanciaMinimaPuente;
    Grecoland[puenteMinimo.ciudadCostera1][puenteMinimo.ciudadCostera2 + N1] = distanciaMinimaPuente;

    vector<vertice> caminosMinimos;

    // Suponiendo que el vértice origen está enumerado de 0 a N1+N2.
    vector<tCoste> distanciasMinimas = Dijkstra(origen,Grecoland);

    // Suponiendo que el vértice destino está enumerado de 0 a N1+N2.
    return distanciasMinimas[destino];
}