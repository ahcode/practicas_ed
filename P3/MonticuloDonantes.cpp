#include "MonticuloDonantes.hpp"

namespace ed{
	Donante MonticuloDonantes::cima() const{
		if (vacio())
			throw 1;
		else
			return vector_.front();
	}
	void MonticuloDonantes::insertar(Donante d){
	}
	void MonticuloDonantes::borrar(Donante d){
	}
}
