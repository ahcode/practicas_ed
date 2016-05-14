#ifndef LADO_HPP
#define LADO_HPP
	#include <string>
	#include <cstdlib>
	#include "Vertice.hpp"
	namespace ed{
		class Lado{
			private:
				float dato_;
				Vertice v1_, v2_;
			public:
				float getDato(){return dato_;};
				Vertice primero(){return v1_;};
				Vertice segundo(){return v2_;};
				bool existe(const Vertice &v);
				Vertice otro(const Vertice &v);
				void setDato(const float &d){dato_=d;};
				void setPrimero(const Vertice &v){v1_=v;};
				void setSegundo(const Vertice &v){v2_=v;};
		};
	}
#endif
