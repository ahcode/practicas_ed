/*!
\file MonticuloDonantes.cpp
\brief Implementación de la clase MonticuloDonantes
\author Álvaro Herrero Pérez
\date 18/04/2016
*/

#include "MonticuloDonantes.hpp"

namespace ed{
	Donante MonticuloDonantes::cima() const{
		if (vacio())
			throw 1;
		else
			return vector_.front();
	}
	void MonticuloDonantes::flotar(int const &pos){
		Donante aux;
		int n=pos;
		while (vector_[padre(n)]<=vector_[n] && n!=0){
			aux=vector_[n];
			vector_[n]=vector_[padre(n)];
			vector_[padre(n)]=aux;
			n=padre(n);
		}
	}
	void MonticuloDonantes::hundir(int const &pos){
		int n=pos;
		if (hijoIzq(pos)<(int)vector_.size() && vector_[n]<=vector_[hijoIzq(pos)])
			n=hijoIzq(pos);
		if (hijoDer(pos)<(int)vector_.size() && vector_[n]<=vector_[hijoDer(pos)])
			n=hijoDer(pos);
		if (n!=pos){
			Donante aux;
			aux=vector_[n];
			vector_[n]=vector_[pos];
			vector_[pos]=aux;
			hundir(n);
		}
	}
	void MonticuloDonantes::insertar(Donante const &d){
		int pos = vector_.size();
		vector_.push_back(d);
		flotar(pos);
	}
	bool MonticuloDonantes::borrar(){
		if (vacio())
			return false;
		vector_[0]=vector_[vector_.size()-1];
		vector_.pop_back();
		hundir(0);
		return true;
	}
}
