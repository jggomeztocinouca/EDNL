#include <grafoPMC.h>
#include <alg_grafoPMC.h>

template<typename tCoste>
matriz<tCoste> tarifaMinima(typename GrafoP<tCoste>::vertice ciudadIntercambio,
                            const GrafoP<tCoste>& tren,
                            const GrafoP<tCoste>& autobus)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    matriz<vertice> caminosMinimosTren;
    matriz<tCoste> tarifasMinimasTren = Floyd(tren, caminosMinimosTren);

    matriz<vertice> caminosMinimosBus;
    matriz<tCoste> tarifasMinimasBus = Floyd(autobus, caminosMinimosBus);

    size_t numVert = tren.numVert();
    matriz<tCoste> tarifasMinimasCombinadas (numVert);
    for(vertice i = 0; i < numVert; i++)
    {
        for(vertice j = 0; j < numVert; j++)
        {
            tCoste minimoCosteDirecto = std::min(tarifasMinimasBus[i][j], tarifasMinimasTren[i][j]);
            tCoste minimoCosteCombinado = std::min(tarifasMinimasBus[i][ciudadIntercambio] + tarifasMinimasTren[ciudadIntercambio][i],
                                                  tarifasMinimasTren[i][ciudadIntercambio] + tarifasMinimasBus[ciudadIntercambio][i]);
            tarifasMinimasCombinadas[i][j] = std::min(minimoCosteDirecto,minimoCosteCombinado);
        }
    }

    return tarifasMinimasCombinadas;
}
