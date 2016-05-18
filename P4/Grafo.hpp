/*!
  \file   Grafo.hpp
  \brief  Especificación de la clase Grafo
  \author Álvaro Herrero Pérez
  \date   18/05/2016
*/
#ifndef GRAFO_HPP
#define GRAFO_HPP
	#include <vector>
	#include <limits>
	#include <string>
	#include <fstream>
	#include <sstream>
	#include <cstdlib>
	#include "Vertice.hpp"
	#include "Lado.hpp"
	namespace ed{
		/*!
		\brief Implementación de la clase Grafo
		*/
		class Grafo{
			private:
				/*!
				\brief Vector de vértices
				*/
				std::vector<Vertice> vertices_;
				/*!
				\brief Matriz de adyacencia
				*/
				std::vector< std::vector<float> > matriz_;
				/*!
				\brief Indica si el grafo es dirigido o no
				*/
				bool dirigido_;
				/*!
				\brief Cursor de vértices
				*/
				int cursor_;
				/*!
				\brief Aumenta el ancho y alto de la matriz de adyacencia en una unidad
				\note Asigna el valor infinito a los nuevos lados excepto a la última celda de la matriz que le asigna un 0
				*/
				void aumentarMatriz();
			public:
				/*!
				\brief Constructor de la clase grafo, inicia el cursor a 0 y establece si el grafo es dirigido o no
				\note Por defecto el grafo no es dirigido
				\param dirigido (Grafo dirigido o no), de tipo bool, valor por defecto false
				*/
				Grafo(bool dirigido=false){dirigido_=dirigido; cursor_=0;};
				/*!
				\brief Devuelve el número de vértices del grafo
				\return int, número de vértices
				\sa numLados
				*/
				int numVertices() const{return vertices_.size();};
				/*!
				\brief Devuelve el número de lados del grafo
				\return int, número de lados
				\sa numVertices
				*/
				int numLados() const;
				/*!
				\brief Comprueba si el grafo es dirigido o no
				\return bool, true si el grafo es dirigido y false en caso contrario
				*/
				bool esDirigido() const{return dirigido_;};
				/*!
				\brief Comprueba si el grafo está vacío o no
				\return bool, true si el grafo está vacío y false en caso contrario
				*/
				bool estaVacio() const{return vertices_.empty();};
				/*!
				\brief Comprueba si 2 vértices son adyacentes o no
				\param a (Primer vértice), de tipo vértice
				\param b (Segundo vértice), de tipo vértice
				\note Si es un grafo dirigido, a es el origen y b el destino
				\note Si el primer vértice no existe lanza una excepción con valor entero 1, y si es el segundo vértice el que no existe, valor entero 2
				\return bool, true si los vértices son adyacentes y false en caso contrario
				*/
				bool adyacente(const Vertice &a, const Vertice &b) const;
				/*!
				\brief Comprueba si el cursor del grafo apunta a un vértice o no
				\return bool, true si apunta a un vértice y false en caso contrario
				*/
				bool cursorApuntaVertice() const;
				/*!
				\brief Devuelve el vértice al que apunta el cursor
				\return Vértice, vértice en la posición del cursor
				*/
				Vertice verticeActual() const{return vertices_[cursor_];};
				/*!
				\brief Añade un vértice al grafo
				\note El nodo añadido no tendrá nodos adyacentes
				\param d (Dato del vértice), de tipo string
				\note La etiqueta será asignada automáticamente y corresponderá con la posición del vector en la que se inserta
				*/
				void anadirVertice(const std::string &d);
				/*!
				\brief Añade un lado al grafo
				\param a (Primer vértice), de tipo vértice
				\param b (Segundo vértice), de tipo vértice
				\param d (Dato del vértice), de tipo string
				\note Si el grafo es dirigido, a es el orgien y b el destino
				\note Si el primer vértice no existe lanza una excepción con valor entero 1, y si es el segundo vértice el que no existe, valor entero 2
				*/
				void anadirLado(const Vertice &a, const Vertice &b, const float &d);
				/*!
				\brief Busca un vértice cuyo dato sea igual al pasado como parámetro
				\note Si hay 2 vértices con el mismo dato devolverá el que tenga la posición anterior en el vector de vértices
				\param d (Dato del vértice), de tipo string
				*/
				bool buscarVertice(const std::string &d);
				/*!
				\brief Mueve el cursor de vértices a una determinada posición
				\param pos (Posición), de tipo int
				\note Las posiciones empiezan por 0
				*/
				bool goTo(const int &pos);
				/*!
				\brief Devuelve el primer vértice que se añadió al vector de vértices
				\return Vertice, vértice inicial
				*/
				Vertice verticeInicial(){cursor_=0; return vertices_[0];};
				/*!
				\brief Mueve el cursor una posición y devuelve el vértice de dicha posición
				\return Vertice, vértice siguiente
				\note Si no hay más vértices, vuelve al principio del vector
				*/
				Vertice siguienteVertice();
				/*!
				\brief Comprueba si el cursor está en la primera posición vacía del vector
				\return bool, true si el cursor está en la primera posición vacía del vector y false en caso contrario
				*/
				bool finalVertices() const;
				/*!
				\brief Devuelve el lado que hay entre 2 vértices pasados como parámetro
				\param a (Primer vértice), de tipo Vertice
				\param b (Segundo vértice), de tipo Vertice
				\note Si el grafo es dirigido, a es el origen y b el destino
				\return Lado, lado etre los 2 vértices
				*/
				Lado getLado(const Vertice &a, const Vertice &b) const;
				/*!
				\brief Carga un fichero que contenga la estructura de un grafo
				\param nombre (Nombre del fichero), de tipo string
				\return bool, true si la carga ha tenido éxito y false en caso contrario
				*/
				bool cargarFichero(const std::string &nombre);
		};
	}
#endif
