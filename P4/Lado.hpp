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
				bool existe(Vertice v);
				Vertice otro(Vertice v);
				void setDato(float d){dato_=d;};
		};
	}
#endif
