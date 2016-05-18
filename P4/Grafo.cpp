/*!
  \file   Grafo.cpp
  \brief  Implementación de la clase Grafo
  \author Álvaro Herrero Pérez
  \date   18/05/2016
*/
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
    if (a.getEtiqueta()>(int)matriz_.size())
      throw 1;
    if (b.getEtiqueta()>(int)matriz_.size())
      throw 2;
    if(matriz_[a.getEtiqueta()][b.getEtiqueta()]<std::numeric_limits<double>::infinity() && matriz_[a.getEtiqueta()][b.getEtiqueta()]>0)
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
    std::vector<float> v;
    for (int i=0;i<(int)matriz_.size();i++)
      v.push_back(std::numeric_limits<double>::infinity());
    //Añadir la fila creada a la matriz
    matriz_.push_back(v);
    //Añadir nueva columna y asignar valir inf a todos los elementos
    for (int i=0;i<(int)matriz_.size();i++){
      (matriz_[i]).push_back(std::numeric_limits<double>::infinity());
    }
    matriz_[matriz_.size()-1][matriz_.size()-1]=0;
  }

  void Grafo::anadirLado(const Vertice &a, const Vertice &b, const float &d){
    if (a.getEtiqueta()>(int)matriz_.size())
      throw 1;
    if (b.getEtiqueta()>(int)matriz_.size())
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

  bool Grafo::goTo(const int &pos){
    if (pos<(int)vertices_.size()){
      cursor_=pos;
      return true;
    }else{
      return false;
    }
  }

  bool Grafo::finalVertices() const{
    if (cursor_>=(int)vertices_.size())
      return true;
    else
      return false;
  }

  Vertice Grafo::siguienteVertice(){
    cursor_++;
    if (finalVertices())
      cursor_=0;
    return vertices_[cursor_];
  }

  Lado Grafo::getLado(const Vertice &a, const Vertice &b) const{
    if (a.getEtiqueta()>(int)matriz_.size())
      throw 1;
    if (b.getEtiqueta()>(int)matriz_.size())
      throw 2;
    Lado lado;
    lado.setPrimero(a);
    lado.setSegundo(b);
    lado.setDato(matriz_[a.getEtiqueta()][b.getEtiqueta()]);
    return lado;
  }

  bool Grafo::cargarFichero(const std::string &nombre){
    matriz_.clear();
    vertices_.clear();
		std::ifstream f(nombre.c_str());
		std::string c;
    Vertice v1;
    Vertice v2;
    std::stringstream stream;
    int nvertices;
		if(!f.is_open())
			return false;
    //Número de vértices
    getline(f,c);
    nvertices=atoi(c.c_str());
    //Dirigido o no
    getline(f,c);
    if(c=="1")
      dirigido_=true;
    else
      dirigido_=false;
    //Vertices
		for (int i=0;i<nvertices;i++){
			getline(f,c);
      anadirVertice(c);
		}
    //Lados
    while(!f.eof()){
      getline(f,c);
      stream.clear();
      stream << c;
      getline(stream, c, ' ');
      buscarVertice(c);
      v1=verticeActual();
      getline(stream, c, ' ');
      buscarVertice(c);
      v2=verticeActual();
      getline(stream, c, ' ');
      anadirLado(v1,v2,atof(c.c_str()));
    }
		f.close();
    return true;
  }
}
