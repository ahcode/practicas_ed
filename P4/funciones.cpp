/*!
  \file   funciones.cpp
  \brief  Conjunto de funciones del algoritmo de Floyd para grafos
  \author Álvaro Herrero Pérez
  \date   18/05/2016
*/
#include "funciones.hpp"
namespace ed{
  void floyd(Grafo &gr, std::vector< std::vector<float> > &mdist, std::vector< std::vector<int> > &mint){
    mdist.clear();
    mint.clear();
    std::vector<float> vf;
    std::vector<int> vi;
    Vertice v1;
    Vertice v2;

    //Inicializar matrices
    for (int i=0; i<gr.numVertices(); i++){
      vi.clear();
      vf.clear();
      gr.goTo(i);
      v1=gr.verticeActual();
      for (int j=0; j<gr.numVertices(); j++){
        vi.push_back(-1);
        gr.goTo(j);
        v2=gr.verticeActual();
        vf.push_back(gr.getLado(v1,v2).getDato());
      }
      mdist.push_back(vf);
      mint.push_back(vi);
    }
    //Algoritmo de Floyd
    for (int k=0;k<gr.numVertices();k++){
      for (int i=0;i<gr.numVertices();i++){
        for (int j=0;j<gr.numVertices();j++){
          if (mdist[i][k]+mdist[k][j]<mdist[i][j]){
            mdist[i][j]=mdist[i][k]+mdist[k][j];
            mint[i][j]=k;
          }
        }
      }
    }
  }

  void caminoMinimo(Grafo &gr, std::vector< std::vector<int> > &mint, const Vertice &v1, const Vertice &v2, std::vector<Vertice> &camino){
    Vertice v;
    if (mint[v1.getEtiqueta()][v2.getEtiqueta()]==-1){
      camino.push_back(v2);
    }else{
      gr.goTo(mint[v1.getEtiqueta()][v2.getEtiqueta()]);
      v=gr.verticeActual();
      caminoMinimo(gr, mint, v1, v, camino);
      caminoMinimo(gr, mint, v, v2, camino);
    }
  }

  void mostrarCaminoDistancia(Grafo &gr, std::vector< std::vector<float> > &mdist, std::vector< std::vector<int> > &mint, const Vertice &v1, const Vertice &v2){
    std::vector<Vertice> camino;
    if (mdist[v1.getEtiqueta()][v2.getEtiqueta()]){
      caminoMinimo(gr, mint, v1, v2, camino);
      NEGRITA; std::cout << "El camino mínimo para ir de " << v1.getDato() << " a " << v2.getDato() << " es:\n"; NORMAL; std::cout << v1.getDato() << " ->";
      for (int i=0; i<(int)camino.size(); i++){
        if (i!=0)
          std::cout << " ->";
        std::cout << " " << camino[i].getDato();
      }
      std::cout << "\n\nY la distancia es: " << mdist[v1.getEtiqueta()][v2.getEtiqueta()] << "\n";
    }else{
      std::cout << "\n<< No existe camino para ir de " << v1.getDato() << " a " << v2.getDato() << " >>";
    }
  }
}
