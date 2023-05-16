#include <iostream>
#include <vector>
#include <listaenla.h>
#include <grafoPMC.h>

using namespace std;

// PRIMER PASO: Convierte la matriz de costes en una lista de adyacencia
// Función que convierte una matriz de costes en una lista de adyacencia
template<typename tCoste>
vector<Lista<typename GrafoP<tCoste>::vertice>> obtenerListaAdyacencia(const vector<vector<tCoste>>& matrizCoste)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    // Obtiene el número de vértices (n) del grafo
    size_t n = matrizCoste.size();

    // Crea una lista de adyacencia vacía de tamaño n
    vector<Lista<vertice>> listaAdyacencia(n);

    // Recorre cada fila de la matriz de costes
    for (size_t i = 0; i < n; i++)
    {
        // Recorre cada columna de la matriz de costes
        for(size_t j = 0; j < n; j++)
        {
            // Si hay una arista entre los vértices i y j (valor diferente de 0 y de infinito)
            if(matrizCoste[i][j] != 0 && matrizCoste[i][j] != GrafoP<tCoste>::INFINITO){
                // Añade el vértice j a la lista de vecinos del vértice i
                listaAdyacencia[i].push_back(j);
            }
        }
    }

    // Devuelve la lista de adyacencia generada
    return listaAdyacencia;
}

// SEGUNDO PASO: Recorrer la lista de adyacencia en profundidad
// Función que verifica si un grafo es acíclico a partir de su lista de adyacencia
template<typename tCoste>
bool aciclico(typename GrafoP<tCoste>::vertice vertice, typename GrafoP<tCoste>::vertice predecesor, vector<bool>& visitados, const vector<Lista<typename GrafoP<tCoste>::vertice>>& listaAdyacencia)
{
    visitados[vertice] = true;
    for(size_t vecino : listaAdyacencia[vertice])
    {
        if(!visitados[vecino])
        {
            if(!aciclico<tCoste>(vecino, vertice, visitados, listaAdyacencia))
            {
                return false;
            }
        }
        else if(vecino != predecesor)
        {
            return false;
        }
    }
    return true;
}


// TERCER PASO: Comprobar si es acíclico
// Función que determina si un grafo es acíclico a partir de su matriz de costes
template<typename tCoste>
bool derechoSubvencion(vector<vector<tCoste>>& matrizCostes)
{
    size_t n = matrizCostes.size();
    vector<bool> visitados(n, false);
    auto listaAdyacencia = obtenerListaAdyacencia(matrizCostes);
    for(size_t vertice = 0; vertice < n; vertice++)
    {
        if(!visitados[vertice] && !aciclico<tCoste>(vertice, -1, visitados, listaAdyacencia))
        {
            return false;
        }
    }
    return true;
}