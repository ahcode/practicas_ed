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
			\sa escribirMonomio, &operator>>
			*/
			std::string crearSalida() const;
		public:
			/*!
			\brief Constructor de la clase Monomio
			\note Se puede llamar sin parámetros para construir un Monomio por defecto
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
			\brief
			\note
			\param
			\return
			\pre
			\post
			\post
			\sa
			*/
			inline void setCoeficiente(float const &c){coeficiente_=c;};
			inline void setGrado(int const &g){grado_=g;};
			inline float getCoeficiente() const {return coeficiente_;};
			inline int getGrado() const {return grado_;};
			void leerMonomio();
			void escribirMonomio() const;
			Monomio operator=(Monomio const &m);
			Monomio operator*(Monomio const &m);
			float valor(float x) const;
			friend std::istream &operator>>(std::istream &stream, Monomio &m);
			friend std::ostream &operator<<(std::ostream &stream, Monomio const &m);
	};
}

#endif
