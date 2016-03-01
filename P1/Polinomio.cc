#include <iostream>
#include <list>
#include "Polinomio.h"

Polinomio::Polinomio(int g, int const &n){
	grado_=g;
	nmonomios_=n;
	Monomio m(1,g);
	for (int i=0;i<n;i++){
		monomios_.push_back(m);
		m.setGrado(--g);
	}
}

Polinomio::Polinomio(Polinomio const &p){
	setGrado(p.getGrado());
	setNMonomios(p.getNMonomios());
	setMonomios(p.getMonomios());
}

void Polinomio::insertarMonomio(Monomio const &m){
	int g=m.getGrado();
	bool insertado=false;
	for(std::list<Monomio>::iterator i=monomios_.begin();i!=monomios_.end();i++){
		if ((*i).getGrado()<g){
			monomios_.insert(i,m);
			insertado=true;
			break;
		}
		if ((*i).getGrado()==g){
			(*i).setCoeficiente((*i).getCoeficiente()+m.getCoeficiente());
			insertado=true;
			break;
		}
	}
	if(!insertado)
		monomios_.push_back(m);
}

void Polinomio::leerPolinomio(){
	std::cout << "Número de monomios a insertar: ";
	std::cin >> nmonomios_;
	Monomio m;
	monomios_.clear();
	for (int i=0;i<nmonomios_;i++){
		std::cout << "Monomio " << i+1 << ":\n";
		m.leerMonomio();
		insertarMonomio(m);
	}
}
