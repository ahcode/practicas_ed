/*!
  \file   funciones.hpp
  \brief  Conjunto de funciones del algoritmo de Floyd para grafos
  \author Álvaro Herrero Pérez
  \date   18/05/2016
*/
#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
  #include <vector>
  #include <iostream>
  #include <cstdlib>
  #include "Grafo.hpp"
  #include "Vertice.hpp"
  #include "macros.hpp"
  namespace ed{
    /*!
    \brief Realiza el algoritmo de floyd a un grafo
    \param gr (grafo), de tipo Grafo
    \param mdist (matriz de distancias), de tipo vector<vector<float>>
    \param mint (matriz de intermedios), de tipo vector<vector<int>>
    \note Almacena el resultado en mdist y mint pasados por referencia
    */
    void floyd(Grafo &gr, std::vector< std::vector<float> > &mdist, std::vector< std::vector<int> > &mint);
    /*!
    \brief Función recursiva que almacena el camino mínimo entre 2 vértices en un vector
    \note el vértice inicial no se almacena en el vector
    \param gr (grafo), de tipo Grafo
    \param mint (matriz de intermedios), de tipo vector<vector<int>>
    \param v1 (Vértice inicial), de tipo Vertice
    \param v2 (Vértice final), de tipo Vertice
    \param camino (Camino mínimo), de tipo vector<Vertice>
    \note Almacena el resultado en camino pasado por referencia
    */
    void caminoMinimo(Grafo &gr, std::vector< std::vector<int> > &mint, const Vertice &v1, const Vertice &v2, std::vector<Vertice> &camino);
    /*!
    \brief Imprime por pantalla el camino mínimo entre 2 vértices y la distancia entre ellos
    \param gr (grafo), de tipo Grafo
    \param mdist (matriz de distancias), de tipo vector<vector<float>>
    \param mint (matriz de intermedios), de tipo vector<vector<int>>
    \param v1 (Vértice inicial), de tipo Vertice
    \param v2 (Vértice final), de tipo Vertice
    */
    void mostrarCaminoDistancia(Grafo &gr, std::vector< std::vector<float> > &mdist, std::vector< std::vector<int> > &mint, const Vertice &v1, const Vertice &v2);
  }
#endif
