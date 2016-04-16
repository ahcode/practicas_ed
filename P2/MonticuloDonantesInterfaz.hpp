#ifndef MONTICULODONANTESINTERFAZ_HPP
#define MONTICULODONANTESINTERFAZ_HPP

#include "Donante.hpp"

namespace ed{
	class MonticuloDonantesInterfaz{
		public:
			virtual bool vacio() const=0;
			virtual Donante cima() const=0;
			virtual void insertar(Donante d)=0;
			virtual void borrar(Donante d)=0;
	};
}

#endif
