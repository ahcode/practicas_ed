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
		while (vector_[n]<=vector_[padre(n)] && n!=0){
			aux=vector_[n];
			vector_[n]=vector_[padre(n)];
			vector_[padre(n)]=aux;
			n=padre(n);
		}
	}
	void MonticuloDonantes::hundir(int const &pos){
		int n=pos;
		if (hijoIzq(pos)<(int)vector_.size() && vector_[hijoIzq(pos)]<=vector_[n])
			n=hijoIzq(pos);
		if (hijoDer(pos)<(int)vector_.size() && vector_[hijoDer(pos)]<=vector_[n])
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
		//insertar en la última hoja
		vector_.push_back(d);
		flotar(pos);
	}
	bool MonticuloDonantes::borrar(){
		if (vacio())
			return false;
		//borrar la raiz
		vector_[0]=vector_[vector_.size()-1];
		vector_.pop_back();
		hundir(0);
		return true;
	}

	bool MonticuloDonantes::donar(){
		if (vacio())
			return false;
		vector_[0].setDonaciones(vector_[0].getDonaciones()+1);
		hundir(0);
		return true;
	}

	void MonticuloDonantes::cargarFichero(std::string const &nombreFichero){
		vector_.clear();
		std::ifstream f(nombreFichero.c_str());
		std::string c;
		ed::Donante d;
		if(!f.is_open())
			throw 1;
		while (!f.eof()){
			getline(f,c);
			if(f.eof()) //Para evitar errores si hay una línea en blanco al final del fichero
				break;
			d.setNombre(c);
			getline(f,c);
			if(f.eof())
				break;
			d.setApellidos(c);
			getline(f,c);
			if(f.eof())
				break;
			if(!d.setGrupo(c))
				throw 2;
			getline(f,c);
			if(f.eof())
				break;
			if(!d.setFRH(c))
				throw 3;
			getline(f,c);
			if(f.eof())
				break;
			if(!d.setDonaciones(atoi(c.c_str())))
				throw 4;
			insertar(d);
		}
		f.close();
	}

	bool MonticuloDonantes::grabarFichero(std::string const &nombreFichero){
	  std::ofstream f(nombreFichero.c_str());
	  ed::Donante d;
	  if(!f.is_open())
		return false;
	  for(int i=0;i<(int)vector_.size();i++){
		f << vector_[i].getNombre() << "\n";
		f << vector_[i].getApellidos() << "\n";
		f << vector_[i].getGrupo() << "\n";
		f << vector_[i].getFRH() << "\n";
		f << vector_[i].getDonaciones() << "\n";
	  }
	  f.close();
	  return true;
	}
}
