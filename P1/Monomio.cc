#include "Monomio.h"

Monomio::Monomio(float const &c, int const &g){
	coeficiente_=c;
	grado_=g;
}

Monomio::Monomio(Monomio const &m){
	coeficiente_=m.coeficiente_;
	grado_=m.grado_;
}

std::string Monomio::crearSalida() const {
	std::ostringstream salida;
	if (coeficiente_!=0){
		if (coeficiente_!=1)
			if (coeficiente_==-1)
				salida << "- ";
			else
				salida << coeficiente_;
		if (grado_!=0){
			salida << "x";
			if (grado_!=1)
				salida << "^" << grado_;
		}
	}else
		salida << "0";
	return salida.str();
}

void Monomio::leerMonomio(){
	std::cout << "Introduce el coeficiente: ";
	std::cin >> coeficiente_;
	std::cout << "Introduce el grado: ";
	std::cin >> grado_;
}

void Monomio::escribirMonomio() const {
	std::cout << crearSalida() <<"\n";
}

Monomio Monomio::operator=(Monomio const &m){
	coeficiente_=m.coeficiente_;
	grado_=m.grado_;
	return *this;
}

Monomio Monomio::operator*(Monomio const &m){
	Monomio aux;
	aux.coeficiente_ = coeficiente_ * m.coeficiente_;
	aux.grado_ = grado_ + m.grado_;
	return aux;
}

float Monomio::valor(float x) const {
	return coeficiente_*pow(x , grado_);
}

std::istream &operator>>(std::istream &stream, Monomio &m){
	std::cout << "Introduce el coeficiente: ";
	stream >> m.coeficiente_;
	std::cout << "Introduce el grado: ";
	stream >> m.grado_;
	return stream;
}

std::ostream &operator<<(std::ostream &stream, Monomio const &m){
	stream << m.crearSalida();
	return stream;
}
