#include "Donante.hpp"

namespace ed{
	Donante::Donante(std::string const &n, std::string const &a, std::string const &g, std::string const &f){
		setNombre(n);
		setApellidos(a);
		setGrupo(g);
		setFRH(f);
	}

	Donante::Donante(Donante const &d){
		*this=d;
	}

	bool Donante::setGrupo(std::string const &g){
		if (g=="0" || g=="A" || g=="B" || g=="AB"){
			grupo_=g;
			return true;
		}
		else
			return false;
	}

	bool Donante::setFRH(std::string const &f){
		if (f=="positivo" || f=="negativo"){
			frh_=f;
			return true;
		}
		else
			return false;
	}

	void Donante::leerDonante(){
		std::string aux;
		std::cout << "Introduce el nombre: ";
		std::cin >> aux;
		setNombre(aux);
		std::cout << "Introduce los apellidos: ";
		std::cin >> aux;
		setApellidos(aux);
		do{
			std::cout << "Introduce el grupo sanguíneo: ";
			std::cin >> aux;
		}while(setGrupo(aux)!=true);
		do{
			std::cout << "Introduce el factor RH: ";
			std::cin >> aux;
		}while(setFRH(aux)!=true);
	}

	void Donante::mostrarDonante(){
		std::cout << "Nombre: " << getNombre() << "\n";
		std::cout << "Apellidos: " << getApellidos() << "\n";
		std::cout << "Grupo sanguíneo: " << getGrupo() << "\n";
		std::cout << "Factor RH: " << getFRH() << "\n";
	}

	Donante Donante::operator=(Donante const &d){
		setNombre(d.getNombre());
		setApellidos(d.getApellidos());
		setGrupo(d.getGrupo());
		setFRH(d.getFRH());
		return *this;
	}

	bool Donante::operator==(Donante const &d){
		if (getNombre()==d.getNombre() && getApellidos()==d.getApellidos())
			return true;
		else
			return false;
	}

	bool Donante::operator<=(Donante const &d){
		if (getApellidos()==d.getApellidos()){
			if (getNombre()<=d.getNombre())
				return true;
			else
				return false;
		}else{
			if (getApellidos()<=d.getApellidos())
				return true;
			else
				return false;
		}
	}
}
