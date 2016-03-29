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
		std::cin >> *this;
	}

	void Donante::mostrarDonante(){
		std::cout << *this;
	}

	Donante &Donante::operator=(Donante const &d){
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

	std::istream &operator>>(std::istream &stream, Donante &d){
		std::string aux;
		std::cout << "Introduce el nombre: ";
		stream >> aux;
		d.setNombre(aux);
		std::cout << "Introduce los apellidos: ";
		stream >> aux;
		d.setApellidos(aux);
		do{
			std::cout << "Introduce el grupo sanguíneo: ";
			stream >> aux;
		}while(d.setGrupo(aux)!=true);
		do{
			std::cout << "Introduce el factor RH: ";
			stream >> aux;
		}while(d.setFRH(aux)!=true);
		return stream;
	}

	std::ostream &operator<<(std::ostream &stream, Donante const &d){
		stream << "Nombre: " << d.getNombre() << "\n";
		stream << "Apellidos: " << d.getApellidos() << "\n";
		stream << "Grupo sanguíneo: " << d.getGrupo() << "\n";
		stream << "Factor RH: " << d.getFRH() << "\n";
		return stream;
	}
}
