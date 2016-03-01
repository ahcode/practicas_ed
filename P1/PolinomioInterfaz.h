#ifndef POLINOMIOINTERFAZ_H
#define POLINOMIOINTERFAZ_H

#include <list>

class PolinomioInterfaz{
	virtual void setGrado(int const &g)=0;
	virtual void setNMonomios(int const &n)=0;
	virtual void setMonomios(std::list const &m)=0;
	virtual int getGrado() const=0;
	virtual int getNMonomios() const=0;
	virtual std::list getMonomios() const=0;
};

#endif
