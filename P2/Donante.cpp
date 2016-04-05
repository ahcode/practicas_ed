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
		if (g=="0" || g=="cero"){
			grupo_="0";
			return true;
		}else if (g=="A" || g=="a"){
			grupo_="A";
			return true;
		}else if (g=="B" || g=="b"){
			grupo_="B";
			return true;
		}else if (g=="AB" || g=="ab"){
			grupo_="AB";
			return true;
		}else
			return false;
	}

	bool Donante::setFRH(std::string const &f){
		if (f=="positivo" || f=="+" || f=="POSITIVO" || f=="Positivo"){
			frh_="Positivo";
			return true;
		}else if(f=="negativo" || f=="-" || f=="NEGATIVO" || f=="Negativo"){
			frh_="Negativo";
			return true;
		}else
			return false;
	}

	void Donante::leerDonante(){
		std::cin >> *this;
	}

	void Donante::mostrarDonante() const{
		std::cout << *this;
	}

	void Donante::modificarDonante(){
		int op;
		bool error=false;
		std::string in;
		do {
			std::cout << "¿Que campo quieres modificar?\n";
			NEGRITA; std::cout << "\t1."; NORMAL; std::cout << " Nombre\n";
			NEGRITA; std::cout << "\t2."; NORMAL; std::cout << " Apellidos\n";
			NEGRITA; std::cout << "\t3."; NORMAL; std::cout << " Grupo Sanguíneo\n";
			NEGRITA; std::cout << "\t4."; NORMAL; std::cout << " Factor de Riesgo\n\n";
			if(error)
				std::cout << "<< La opción introducida no es válida >>";
			SUBRAYADO; std::cout << "\nOpción"; NORMAL; std::cout << " = ";
			std::cin >> op;
			std::cin.ignore(256,'\n');
			std::cout << "\n";
			BORRAR;
			error=true;
		}while(op<1 || op>4);
		switch(op){
			case 1:
				std::cout << "\n\tNuevo Nombre: ";
				std::getline(std::cin,in);
				setNombre(in);
				BORRAR;
				break;
			case 2:
				std::cout << "\n\tNuevos Apellidos: ";
				std::getline(std::cin,in);
				setApellidos(in);
				BORRAR;
				break;
			case 3:
				error=false;
				do{
					if(error)
						std::cout << "<< El grupo sanguíneo elegido no es válido >>";
					std::cout << "\n\tGrupo Sanguíneo: ";
					std::getline(std::cin,in);
					BORRAR;
					error=true;
				}while(setGrupo(in)==false);
				break;
			case 4:
				error=false;
				do{
					if(error)
						std::cout << "<< El factor de riesgo elegido no es válido >>";
					std::cout << "\n\tFactor de Riesgo: ";
					std::getline(std::cin,in);
					BORRAR;
					error=true;
				}while(setFRH(in)==false);
				break;
		}
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
		std::getline(stream,aux);
		d.setNombre(aux);
		std::cout << "Introduce los apellidos: ";
		std::getline(stream,aux);
		d.setApellidos(aux);
		do{
			std::cout << "Introduce el grupo sanguíneo: ";
			std::getline(stream,aux);
		}while(d.setGrupo(aux)!=true);
		do{
			std::cout << "Introduce el factor RH: ";
			std::getline(stream,aux);
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
