#include "Grafo.hpp"

namespace ed{
  int Grafo::numLados() const{
    int lados=0;
    for (int i=0;i<(int)matriz_.size();i++){
      for (int j=0;j<(int)matriz_[0].size();j++){
        if (matriz_[i][j]<std::numeric_limits<double>::infinity())
          lados++;
      }
    }
    return lados;
  }

  bool Grafo::adyacente(const Vertice &a, const Vertice &b) const{
    if (a.getEtiqueta()<(int)matriz_.size())
      throw 1;
    if (b.getEtiqueta()<(int)matriz_.size())
      throw 2;
    if (a.getEtiqueta()==b.getEtiqueta())
      throw 3;
    if(matriz_[a.getEtiqueta()][b.getEtiqueta()]<std::numeric_limits<double>::infinity())
      return true;
    else
      return false;
  }

  bool Grafo::cursorApuntaVertice() const{
    if (cursor_>=0 && cursor_<(int)vertices_.size())
      return true;
    else
      return false;
  }

  void Grafo::anadirVertice(const std::string &d){
    Vertice v;
    v.setEtiqueta((int)vertices_.size());
    v.setDato(d);
    vertices_.push_back(v);
    aumentarMatriz();
  }

  void Grafo::aumentarMatriz(){
    //Crear nueva fila y asignar valor inf a todos los elementos
    std::vector<float> v((int)matriz_.size());
    for (int i=0;i<(int)v.size();i++)
      v.push_back(std::numeric_limits<double>::infinity());
    //Añadir la fila creada a la matriz
    matriz_.push_back(v);
    //Añadir nueva columna y asignar valir inf a todos los elementos
    for (int i=0;i<(int)matriz_.size();i++){
      matriz_[i].push_back(std::numeric_limits<double>::infinity());
    }
  }

  void Grafo::anadirLado(const Vertice &a, const Vertice &b, const float &d){
    if (a.getEtiqueta()<(int)matriz_.size())
      throw 1;
    if (b.getEtiqueta()<(int)matriz_.size())
      throw 2;
    matriz_[a.getEtiqueta()][b.getEtiqueta()]=d;
    if(!dirigido_)
      matriz_[b.getEtiqueta()][a.getEtiqueta()]=d;
  }

  bool Grafo::buscarVertice(const std::string &d){
    for (int i=0;i<(int)vertices_.size();i++){
      if (vertices_[i].getDato()==d){
        cursor_=i;
        return true;
      }
    }
    return false;
  }

  bool Grafo::goTo(const Vertice &v){
    if (v.getEtiqueta()<(int)vertices_.size()){
      cursor_=v.getEtiqueta();
      return true;
    }else{
      return false;
    }
  }
}
