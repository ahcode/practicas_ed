/*!
\file MonticuloDonantes.hpp
\brief Especificación de la clase MonticuloDonantes
\author Álvaro Herrero Pérez
\date 18/04/2016
*/

#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include <vector>
#include "MonticuloDonantesInterfaz.hpp"
#include "Donante.hpp"

namespace ed{
	class MonticuloDonantes: public MonticuloDonantesInterfaz{
		private:
			std::vector<Donante> vector_;
			void flotar(int const &pos);
			void hundir(int const &pos);
			int padre(int const &pos) const{return ((pos+1)/2)-1;};
			int hijoIzq(int const &pos) const{return 2*pos+1;};
			int hijoDer(int const &pos) const{return 2*pos+2;};
		public:
			MonticuloDonantes() : vector_(0){};
			inline bool vacio() const{return vector_.empty();};
			Donante cima() const;
			void insertar(Donante const &d);
			bool borrar();
	};
}

#endif
