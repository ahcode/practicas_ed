#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include <vector>
#include "MonticuloDonantesInterfaz.hpp"
#include "Donante.hpp"

namespace ed{
	class MonticuloDonantes: public MonticuloDonantesInterfaz{
		private:
			std::vector<Donante> vector_(0);
		public:
			MonticuloDonantes(){};
			inline bool vacio() const{return vector_.empty();};
			Donante cima() const;
			void insertar(Donante d);
			void borrar(Donante d);
	};
}

#endif