#ifndef VERTICE_HPP
#define VERTICE_HPP
	#include <string>
	namespace ed{
		class Vertice{
			private:
				std::string dato_;
				int etiqueta_;
			public:
				std::string getDato() const{return dato_;};
				int getEtiqueta() const{return etiqueta_;};
				void setDato(std::string d){dato_=d;};
				void setEtiqueta(int e){etiqueta_=e;};
		};
	}
#endif
