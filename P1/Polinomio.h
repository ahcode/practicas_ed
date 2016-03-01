#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <list>
#include "PolinomioInterfaz.h"
#include "Monomio.h"

class Polinomio: public PolinomioInterfaz{
	private:
		int grado_, nmonomios_;
		std::list<Monomio> monomios_;
		void insertarMonomio(Monomio const &m);
	public:
		Polinomio(int g=0, int const &n=0);
		Polinomio(Polinomio const &p);
		inline void setGrado(int const &g){grado_=g;};
		inline void setNMonomios(int const &n){nmonomios_=n;};
		inline void setMonomios(std::list<Monomio> const &m){monomios_=m;};
		inline int getGrado() const{return grado_;};
		inline int getNMonomios() const{return nmonomios_;};
		std::list<Monomio> getMonomios() const{return monomios_;};
		void leerPolinomio();
		//void escribirPolinomio() const;
		//float valor(float x) const;
};

#endif
