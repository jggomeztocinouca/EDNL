#include <alg_grafoPMC.h>
#include <grafoPMC.h>

template<typename tCoste>
unsigned int distanciaPseudocentro(const GrafoP<tCoste>& G){
    typedef typename GrafoP<tCoste>::vertice vertice;

    GrafoP<tCoste> GAux = G;

    matriz<vertice> caminosMinimos;
    matriz<tCoste> costesMinimos = Floyd(GAux,caminosMinimos);

    unsigned int distanciaTotal = GrafoP<tCoste>::INFINITO;
    unsigned int distanciaVertice1 = -GrafoP<tCoste>::INFINITO;
    unsigned int distanciaVertice2 = -GrafoP<tCoste>::INFINITO;

    for(vertice i = 0; i < G.numVert(); i++)
    {
        for(vertice j = 0; j < G.numVert(); j++)
        {
            if(costesMinimos[i][j] >= distanciaVertice1)
            {
                distanciaVertice2 = distanciaVertice1;
                distanciaVertice1 = costesMinimos[i][j];
            }
            else if (costesMinimos[i][j] >= distanciaVertice2)
            {
                distanciaVertice2 = costesMinimos[i][j];
            }
        }

        if(distanciaVertice1 + distanciaVertice2 <= distanciaTotal)
        {
            distanciaTotal = distanciaVertice1 + distanciaVertice2;
        }
    }
}
