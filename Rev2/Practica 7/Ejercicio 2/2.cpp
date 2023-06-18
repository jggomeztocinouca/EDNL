#include <alg_grafoPMC.h>
#include <grafoPMC.h>
#include <vector>

struct pared{
    size_t casillaFrontera1;
    size_t casillaFrontera2;
};

class casillasAdyacentes{
public:
    int casilla;
    int N;
    int arriba;
    int abajo;
    int derecha;
    int izquierda;
    casillasAdyacentes(int c, int n): casilla(c), N(n){
        arriba = casilla - N; // Si excede el borde superior, este resultado será negativo y nunca podrá ser comparable
        abajo = casilla + N;
        if(abajo >= N*N)
        {
            abajo = -1;
        }
        derecha = casilla + 1;
        if(derecha % N == 0)
        {
            derecha = -1;
        }
        izquierda = casilla - 1;
        if(izquierda % N == N-1)
        {
            izquierda = -1;
        }
    }
};

template<typename tCoste>
unsigned int caminoLaberintoOptimo(vector<typename GrafoP<tCoste>::vertice>& caminoSolucion,
                                   size_t casillaEntrada,
                                   size_t casillaSalida,
                                   vector<pared> paredes,
                                   int N)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    typedef typename GrafoP<tCoste>::INFINITO Infinito;

    GrafoP<tCoste> G(N);

    for(int i = 0; i < N; i++)
    {
        casillasAdyacentes c(i,N);
        for(int j = 0; j < N; j++)
        {
            if(j == c.arriba || j == c.abajo || j == c.derecha || j == c.izquierda)
            {
                G[i][j] = 1;
            }
            else{
                G[i][j] = GrafoP<tCoste>::INFINITO;
            }
        }
    }

    for(auto p : paredes){
        G[p.casillaFrontera1][p.casillaFrontera2] = GrafoP<tCoste>::INFINITO;
    }

    vector<vertice> caminosMinimos;
    vector<tCoste> costesMinimos = Dijkstra(G,casillaEntrada,caminosMinimos);

    caminoSolucion = camino<tCoste>(casillaEntrada,casillaSalida,caminosMinimos);

    return costesMinimos[casillaSalida];
}
