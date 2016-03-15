#ifndef DONANTE_HPP
#define DONANTE_HPP
#include <string>
#include <iostream>
#include "DonanteInterfaz.hpp"
namespace ed{
	class Donante: public DonanteInterfaz{
		private:
			std::string nombre_;
			std::string apellidos_;
			std::string grupo_;
			std::string frh_;
		public:
			Donante(std::string const &n="", std::string const &a="", std::string const &g="0", std::string const &f="positivo");
			Donante(Donante const &d);
			inline void setNombre(std::string const &n){nombre_=n;};
			inline void setApellidos(std::string const &a){apellidos_=a;};
			bool setGrupo(std::string const &g);
			bool setFRH(std::string const &f);
			inline std::string getNombre() const{return nombre_;};
			inline std::string getApellidos() const{return apellidos_;};
			inline std::string getGrupo() const{return grupo_;};
			inline std::string getFRH() const{return frh_;};
			void leerDonante();
			void mostrarDonante();
			Donante operator=(Donante const &d);
			bool operator==(Donante const &d);
			bool operator<=(Donante const &d);
	};
}
#endif
