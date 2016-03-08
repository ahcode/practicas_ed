#ifndef POLINOMIOINTERFAZ_H
#define POLINOMIOINTERFAZ_H

#include <list>
#include "Monomio.h"

class PolinomioInterfaz{
	virtual void setGrado(int const &g)=0;
	virtual void setNMonomios(int const &n)=0;
	virtual void setMonomios(std::list<Monomio> const &m)=0;
	virtual int getGrado() const=0;
	virtual int getNMonomios() const=0;
	virtual std::list<Monomio> getMonomios() const=0;
	virtual bool vacio() const=0;
};

#endif
