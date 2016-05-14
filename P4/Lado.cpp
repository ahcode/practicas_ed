#include "Lado.hpp"

namespace ed{
	bool Lado::existe(const Vertice &v){
		if(v1_.getEtiqueta()==v.getEtiqueta() || v2_.getEtiqueta()==v.getEtiqueta())
			return true;
		else
			return false;
	}

	Vertice Lado::otro(const Vertice &v){
		if(v1_.getEtiqueta()==v.getEtiqueta())
			return v2_;
		else if(v2_.getEtiqueta()==v.getEtiqueta())
			return v1_;
		else
			abort();
	}
}
