#include "Monomio.h"

Monomio::Monomio(float const &c, int const &g){
	setCoeficiente(c);
	setGrado(g);
}

Monomio::Monomio(Monomio const &m){
	setCoeficiente(m.getCoeficiente());
	setGrado(m.getGrado());
}

std::string Monomio::crearSalida() const {
	std::ostringstream salida;
	if (getCoeficiente()!=0){
		if (getCoeficiente()!=1)
			if (getCoeficiente()==-1)
				salida << "- ";
			else
				salida << getCoeficiente();
		if (getGrado()!=0){
			salida << "x";
			if (getGrado()!=1)
				salida << "^" << getGrado();
		}
	}else
		salida << "0";
	return salida.str();
}

void Monomio::leerMonomio(){
	float c;
	int g;
	std::cout << "Introduce el coeficiente: ";
	std::cin >> c;
	setCoeficiente(c);
	std::cout << "Introduce el grado: ";
	std::cin >> g;
	setGrado(g);
}

void Monomio::escribirMonomio() const {
	std::cout << crearSalida() <<"\n";
}

Monomio Monomio::operator=(Monomio const &m){
	setCoeficiente(m.getCoeficiente());
	setGrado(m.getGrado());
	return *this;
}

Monomio Monomio::operator*(Monomio const &m){
	Monomio aux;
	aux.setCoeficiente(getCoeficiente() * m.getCoeficiente());
	aux.setGrado(getGrado() + m.getGrado());
	return aux;
}

float Monomio::valor(float x) const {
	return getCoeficiente()*pow(x , getGrado());
}

std::istream &operator>>(std::istream &stream, Monomio &m){
	float c;
	int g;
	std::cout << "Introduce el coeficiente: ";
	stream >> c;
	m.setCoeficiente(c);
	std::cout << "Introduce el grado: ";
	stream >> g;
	m.setGrado(g);
	return stream;
}

std::ostream &operator<<(std::ostream &stream, Monomio const &m){
	stream << m.crearSalida();
	return stream;
}
