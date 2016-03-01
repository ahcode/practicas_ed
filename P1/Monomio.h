#ifndef MONOMIO_H
#define MONOMIO_H

#include "MonomioInterfaz.h"
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

class Monomio: public MonomioInterfaz{
	private:
		float coeficiente_;
		int grado_;
		std::string crearSalida() const;
	public:
		Monomio(float const &c=0, int const &g=0);
		Monomio(Monomio const &m);
		inline void setCoeficiente(float const &c){coeficiente_=c;};
		inline void setGrado(int const &g){grado_=g;};
		inline float getCoeficiente() const {return coeficiente_;};
		inline int getGrado() const {return grado_;};
		void leerMonomio();
		void escribirMonomio() const;
		Monomio operator=(Monomio const &m);
		Monomio operator*(Monomio const &m);
		float valor(float x) const;
		friend std::istream &operator>>(std::istream &stream, Monomio &m);
		friend std::ostream &operator<<(std::ostream &stream, Monomio const &m);
};

#endif
