#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
  #include <vector>
  #include <iostream>
  #include <cstdlib>
  #include "Grafo.hpp"
  #include "Vertice.hpp"
  #include "macros.hpp"
  namespace ed{
    void floyd(Grafo &gr, std::vector< std::vector<float> > &mdist, std::vector< std::vector<int> > &mint);
    void caminoMinimo(Grafo &gr, std::vector< std::vector<int> > &mint, const Vertice &v1, const Vertice &v2, std::vector<Vertice> &camino);
    void mostrarCaminoDistancia(Grafo &gr, std::vector< std::vector<float> > &mdist, std::vector< std::vector<int> > &mint, const Vertice &v1, const Vertice &v2);
  }
#endif
