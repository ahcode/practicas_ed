/*!
  \file   Vertice.hpp
  \brief  Implementación y espacificación de la clase Grafo
  \author Álvaro Herrero Pérez
  \date   18/05/2016
*/
#ifndef VERTICE_HPP
#define VERTICE_HPP
	#include <string>
	namespace ed{
		/*!
		\brief Implementación de la clase vértice
		*/
		class Vertice{
			private:
				/*!
				\brief Dato del vértice
				*/
				std::string dato_;
				/*!
				\brief Etiqueta del vértice
				*/
				int etiqueta_;
			public:
				/*!
				\brief Devuelve el dato del vértice
				\return string, Dato del vértice
				\sa setDato
				*/
				std::string getDato() const{return dato_;};
				/*!
				\brief Devuelve la etiqueta que identifica al vértice
				\return int, Etiqueta del vértice
				\sa setEtiqueta
				*/
				int getEtiqueta() const{return etiqueta_;};
				/*!
				\brief Establece el valor del dato del vértice
				\param d (dato), de tipo string
				\sa getDato
				*/
				void setDato(std::string d){dato_=d;};
				/*!
				\brief Establece el valor de la etiqueta que identifica al vértice
				\param e (etiqueta), de tipo int
				\sa getEtiqueta
				*/
				void setEtiqueta(int e){etiqueta_=e;};
		};
	}
#endif
