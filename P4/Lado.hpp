/*!
  \file   Lado.hpp
  \brief  Especificación de la clase Lado
  \author Álvaro Herrero Pérez
  \date   18/05/2016
*/
#ifndef LADO_HPP
#define LADO_HPP
	#include <string>
	#include <cstdlib>
	#include "Vertice.hpp"
	namespace ed{
		/*!
		\brief Implementación de la clase Lado que une 2 vértices de un grafo
		*/
		class Lado{
			private:
				/*!
				\brief Dato del lado
				*/
				float dato_;
				/*!
				\brief Primer vertice del lado, si es dirigido, es el origen
				*/
				Vertice v1_;
				/*!
				\brief Segundo vertice del lado, si es dirigido, es el destino
				*/
				Vertice v2_;
			public:
				/*!
				\brief Devuelve el dato del lado
				\return float, Dato del Lado
				\sa setDato
				*/
				float getDato(){return dato_;};
				/*!
				\brief Devuelve el primer vértices
				\return Vertice, primer vértice del lado
				\sa setPrimero
				*/
				Vertice primero(){return v1_;};
				/*!
				\brief Devuelve el segundo vértices
				\return Vertice, segundo vértice del lado
				\sa setSegundo
				*/
				Vertice segundo(){return v2_;};
				/*!
				\brief Comprueba si el vértice pasado como parámetro es uno de los vértices del lado
				\return bool, true si existe y false en caso contrario
				*/
				bool existe(const Vertice &v);
				/*!
				\brief Devuelve el vértice contrario al que se pasa como parámetro
				\note Para la ejecución del programa si se le pasa un vértice que no existe, por lo que hay que comprobarlo antes con la función existe
				\param v (Vértice), de tipo Vertice
				\return Vertice, vértice contrario
				*/
				Vertice otro(const Vertice &v);
				/*!
				\brief Establece el valor del dato del lado
				\param d (dato), de tipo float
				\sa getDato
				*/
				void setDato(const float &d){dato_=d;};
				/*!
				\brief Establece el primer vértice del lado
				\param v (Vértice a establecer), de tipo Vértice
				\sa primero
				*/
				void setPrimero(const Vertice &v){v1_=v;};
				/*!
				\brief Establece el segundo vértice del lado
				\param v (Vértice a establecer), de tipo Vértice
				\sa segundo
				*/
				void setSegundo(const Vertice &v){v2_=v;};
		};
	}
#endif
