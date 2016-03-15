/*!
\file Polinomio.hpp
\brief Especificación de la clase Polinomio
\author Álvaro Herrero Pérez
\date 14/03/2016
*/
#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <list>
#include <sstream>
#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"

namespace ed{
	class Polinomio: public PolinomioInterfaz{
		private:
			int grado_, nmonomios_;
			std::list<Monomio> monomios_;
			/*!
			\brief Inserta de manera ordenada un monomio en la lista de monomios
			\note Si ya existe un monomio del mismo grado, suma los coeficientes
			\note Este método actualiza el Grado del polinomio y el número de monomios si procede
			\param  m (Monomio a insertar) de tipo Monomio
			*/
			void insertarMonomio(Monomio const &m);
			/*!
			\brief Crea un string preparado para mostrar por pantalla el polinomio
			\note  Devuelve el string pero no imprime nada por pantalla
			\return string, cadena para imprimir
			\sa actualizarGrado
			*/
			std::string crearSalida() const;
			/*!
			\brief Actualiza la variable grado en función de los monomios almacenados en la lista
			*/
			void actualizarGrado();
		public:
			/*!
			\brief Constructor de la clase Polinomio a partir del grado y el número de monomios
			\note Se puede llamar sin parámetros para construir un Polinomio por defecto (Número de monomios = 0 y Grado = 0)
			\note Genera una lista de n monomios de coeficiente 1, comenzando por grado g y disminuyendo una unidad el grado en cada monomio insertado
			\param g (Grado) de tipo int, valor por defecto 0
			\param n (Número de monomos) de tipo int, valor por defecto 0
			\sa insertarMonomio
			*/
			Polinomio(int const &g=0, int const &n=0);
			/*!
			\brief Constructor de la clase Polinomio a partir de una lista de monomios
			\note Recorre la lista y inserta los elementos de uno en uno de forma ordenada
			\param m (Lista de monomios) de tipo list<Monomio>
			\sa insertarMonomio
			*/
			Polinomio(std::list<Monomio> const &m);
			/*!
			\brief Constructor de copia de la clase Polinomio
			\param p (Polinomio) de tipo Polinomio
			*/
			Polinomio(Polinomio const &p);
			/*!
			\brief Establece un valor para el grado del polinomio
			\param g (Grado) de tipo int
			*/
			inline void setGrado(int const &g){grado_=g;};
			/*!
			\brief Establece un valor para el número de monomios del polinomio
			\param n (Número de monomios) de tipo int
			*/
			inline void setNMonomios(int const &n){nmonomios_=n;};
			/*!
			\brief Establece un valor para la lista de monomios del polinomio
			\param m (Lista de monomios) de tipo list<Monomio>
			*/
			inline void setMonomios(std::list<Monomio> const &m){monomios_=m;};
			/*!
			\brief Devuelve el valor del grado del polinomio
			\return int, valor del grado
			*/
			inline int getGrado() const{return grado_;};
			/*!
			\brief Devuelve el número de monomios del polinomio
			\return int, número de monomios
			*/
			inline int getNMonomios() const{return nmonomios_;};
			/*!
			\brief Devuelve la lista de monomios del polinomio
			\return list<Monomio>, lista de monomios
			*/
			std::list<Monomio> getMonomios() const{return monomios_;};
			/*!
			\brief Devuelve verdadero si el polinomio está vacio o es nulo y falso en caso contrario
			*/
			bool vacio() const;
			/*!
			\brief Pregunta por pantalla el número de monomios que tendrá el polinomio y los va leyendo por pantalla uno a uno
			\note Elimina la lista de monomios anterior
			\sa escribirPolinomio
			*/
			void leerPolinomio();
			/*!
			\brief Muestra por pantalla un objeto Polinomio con el correspondiente formato
			\sa leerPolinomio
			*/
			void escribirPolinomio() const;
			/*!
			\brief Lee el grado y coeficiente de un monomio pidiendo los datos por pantalla
			\pre vacio()==false
			\sa escribirMonomio
			*/
			float valor(float const &x) const;
			/*!
			\brief Iguala un polinomio a otro
			\param m (Polinomio a igualar) de tipo Polinomio
			\return Polinomio
			\sa operator*, operator+
			*/
			Polinomio operator=(Polinomio const &m);
			/*!
			\brief Multiplica dos polinomios
			\param m (Polinomio a multiplicar) de tipo Polinomio
			\return Polinomio
			\sa operator=, operator+
			*/
			Polinomio operator*(Polinomio const &m);
			/*!
			\brief Suma dos polinomios
			\param m (Polinomio a sumar) de tipo Polinomio
			\return Polinomio
			\sa operator=, operator*
			*/
			Polinomio operator+(Polinomio const &m);
			/*!
			\brief Operador para asignar un valor al polinomio de la misma forma que la función leerPolinomio()
			\sa leerPolinomio, operator<<
			*/
			friend std::istream &operator>>(std::istream &stream, Polinomio &p);
			/*!
			\brief Operador para mostrar por pantalla un polinoimio de la misma forma que la función leerPolinomio()
			\sa crearSalida, escribirMonomio, operator>>
			*/
			friend std::ostream &operator<<(std::ostream &stream, Polinomio const &p);
	};
}

#endif
