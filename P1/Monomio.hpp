/*!
\file Monomio.hpp
\brief Especificación de la clase Monomio
\author Álvaro Herrero Pérez
\date 14/03/2016
*/
#ifndef MONOMIO_H
#define MONOMIO_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "MonomioInterfaz.hpp"

namespace ed{
	class Monomio: public MonomioInterfaz{
		private:
			float coeficiente_;
			int grado_;
			/*!
			\brief Crea un string preparado para mostrar por pantalla el monomio
			\note  Devuelve el string pero no imprime nada por pantalla
			\return string, cadena para imprimir
			\sa escribirMonomio, operator>>
			*/
			std::string crearSalida() const;
		public:
			/*!
			\brief Constructor de la clase Monomio
			\note Se puede llamar sin parámetros para construir un Monomio por defecto (Coeficiente = 0 y Grado = 0)
			\param c (Coeficiente) de tipo float, valor por defecto 0
			\param g (Grado) de tipo int, valor por defecto 0
			*/
			Monomio(float const &c=0, int const &g=0);
			/*!
			\brief Constructor de copia de la clase Monomio
			\param m (Monomio) de tipo Monomio
			*/
			Monomio(Monomio const &m);
			/*!
			\brief Establece un valor para el coeficiente del monomio
			\param c (Coeficiente) de tipo float
			*/
			inline void setCoeficiente(float const &c){coeficiente_=c;};
			/*!
			\brief Establece un valor para el grado del monomio
			\param c (Grado) de tipo int
			*/
			inline void setGrado(int const &g){grado_=g;};
			/*!
			\brief Devuelve el valor del coeficiente de un monomio
			\return float, valor del coeficiente
			*/
			inline float getCoeficiente() const {return coeficiente_;};
			/*!
			\brief Devuelve el valor del grado de un monomio
			\return int, valor del grado
			*/
			inline int getGrado() const {return grado_;};
			/*!
			\brief Lee el grado y coeficiente de un monomio pidiendo los datos por pantalla
			\sa escribirMonomio
			*/
			void leerMonomio();
			/*!
			\brief Muestra por pantalla un objeto Monomio con el correspondiente formato
			\note Si el coeficiente vale 0, no muestra la x ni el grado
			\sa leerMonomio
			*/
			void escribirMonomio() const;
			/*!
			\brief Iguala un monomio a otro
			\param m (Monomio a igualar) de tipo Monomio
			\return Monomio
			\sa operator*
			*/
			Monomio operator=(Monomio const &m);
			/*!
			\brief Multiplica dos monomios
			\param m (Monomio a multiplicar) de tipo Monomio
			\return Monomio
			\sa operator=
			*/
			Monomio operator*(Monomio const &m);
			/*!
			\brief Devuelve el valor de un monomio después de sustituir x
			\param x (Valor de la x) de tipo float
			\return float, valor del monomio una vez sustituida la x
			*/
			float valor(float x) const;
			/*!
			\brief Operador para asignar un valor al monomio de la misma forma que la función leerMonomio()
			\sa leerMonomio, operator<<
			*/
			friend std::istream &operator>>(std::istream &stream, Monomio &m);
			/*!
			\brief Operador para mostrar por pantalla un monomio de la misma forma que la función leerMonomio()
			\sa crearSalida, escribirMonomio, operator>>
			*/
			friend std::ostream &operator<<(std::ostream &stream, Monomio const &m);
	};
}

#endif
