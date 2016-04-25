/*!
\file MonticuloDonantesInterfaz.hpp
\brief Interfaz para la clase MonticuloDonantes
\author Álvaro Herrero Pérez
\date 18/04/2016
*/

#ifndef MONTICULODONANTESINTERFAZ_HPP
#define MONTICULODONANTESINTERFAZ_HPP

#include "Donante.hpp"

namespace ed{
	class MonticuloDonantesInterfaz{
		public:
			virtual bool vacio() const=0;
			virtual Donante cima() const=0;
			virtual void insertar(Donante const &d)=0;
			virtual bool borrar()=0;
	};
}

#endif
