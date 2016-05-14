#ifndef GRAFO_HPP
#define GRAFO_HPP
	#include <vector>
	#include <limits>
	#include <string>
	#include <fstream>
	#include <sstream>
	#include <cstdlib>
	//#include <cstdio>
	#include "Vertice.hpp"
	#include "Lado.hpp"
	namespace ed{
		class Grafo{
			private:
				std::vector<Vertice> vertices_;
				std::vector< std::vector<float> > matriz_;
				bool dirigido_;
				int cursor_;
				void aumentarMatriz();
			public:
				Grafo(bool dirigido=false){dirigido_=dirigido; cursor_=0;};
				//void mostrar();
				int numVertices() const{return vertices_.size();};
				int numLados() const;
				bool esDirigido() const{return dirigido_;};
				bool estaVacio() const{return vertices_.empty();};
				bool adyacente(const Vertice &a, const Vertice &b) const;
				bool cursorApuntaVertice() const;
				Vertice verticeActual() const{return vertices_[cursor_];};
				void anadirVertice(const std::string &d);
				void anadirLado(const Vertice &a, const Vertice &b, const float &d);
				bool buscarVertice(const std::string &d);
				bool goTo(const int &pos);
				Vertice verticeInicial(){cursor_=0; return vertices_[0];};
				Vertice siguienteVertice();
				bool finalVertices() const;
				Lado getLado(const Vertice &a, const Vertice &b) const;
				bool cargarFichero(const std::string &nombre);
		};
	}
#endif
