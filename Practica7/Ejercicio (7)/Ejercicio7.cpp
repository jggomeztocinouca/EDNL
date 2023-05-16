#include <grafoPMC.h>
#include <alg_grafoPMC.h>

template<typename tCoste>
tCoste rutaMinima(Lista<typename GrafoP<tCoste>::vertice>& ruta,
        typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
        typename GrafoP<tCoste>::vertice cambio1, typename GrafoP<tCoste>::vertice cambio2,
        const GrafoP<tCoste>& tren, const GrafoP<tCoste>& autobus)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<vertice> POrigen;
    vector<vertice> PDestino;
    auto costeOrigen = Dijkstra(tren, origen, POrigen); // 1 origen - muchos destinos
    auto costeDestino = DijkstraInv(autobus, destino, PDestino); // muchos orígenes - 1 destino
    tCoste costeMinimo;
    typename GrafoP<tCoste>::tCamino caminoOrigen;
    typename GrafoP<tCoste>::tCamino caminoDestino;
    if( suma(costeOrigen[origen][cambio1],costeDestino[cambio1][destino]) <
        suma(costeOrigen[origen][cambio2],costeDestino[cambio2][destino]))
    {
        costeMinimo = suma(costeOrigen[origen][cambio1],costeDestino[cambio1][destino]);
        caminoOrigen = camino<tCoste>(origen, cambio1, costeOrigen);
        caminoDestino = camino<tCoste>(cambio1, destino, costeDestino);
    }
    else
    {
        costeMinimo = suma(costeOrigen[origen][cambio2],costeDestino[cambio2][destino]);
        caminoOrigen = camino<tCoste>(origen, cambio2, costeOrigen);
        caminoDestino = camino<tCoste>(cambio2, destino, costeDestino);
    }
    caminoDestino.eliminar(caminoDestino.primera());
    ruta = caminoOrigen;
    ruta += caminoDestino;
    return costeMinimo;
}
