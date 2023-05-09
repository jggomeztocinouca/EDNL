#include <alg_grafoPMC.h>

template<typename tCoste>
tCoste diametroPseudocentro(const GrafoP<tCoste>& G)
{
    typedef typename GrafoP<tCoste>::vertice vertice; // Para ahorraros escribir typename GrafoP<tCoste>::vertice
    const size_t n = G.numVert(); // Número de vértices del grafo

    matriz<vertice> P(n); // Matriz vacía donde se almacenará el camino mínimo a cada vértice
    matriz<tCoste> costes = Floyd(G,P); // Matriz de costes mínimos

    tCoste diametro = GrafoP<tCoste>::INFINITO;
    tCoste diametroActual = 0;
    tCoste mayor, mayor2;

    for(size_t i = 0; i < n-1; i++)
    {
        mayor = 0;
        mayor2 = 0;
        for(size_t j = 0; j < n-1; j++)
        {
            if(costes[i][j] > mayor) // No comprobamos el caso de infinito, porque es un grafo conexo
            {
                mayor2 = mayor;
                mayor = costes[i][j];
            }
            else if(costes[i][j] > mayor2)
            {
                mayor2 = costes[i][j];
            }
        }
        diametroActual = suma(mayor, mayor2);
        if(diametro >= diametroActual)
        {
            diametro = diametroActual;
        }
    }

    return diametro;

}
