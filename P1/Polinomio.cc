#include "Polinomio.h"

Polinomio::Polinomio(int const &g, int const &n){
	int grado=g;
	grado_=g;
	nmonomios_=n;
	Monomio m(1,grado);
	for (int i=0;i<n;i++){
		monomios_.push_back(m);
		m.setGrado(--grado);
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

std::string Polinomio::crearSalida() const{
	std::ostringstream salida;
	for(std::list<Monomio>::const_iterator i=monomios_.begin();i!=monomios_.end();i++){
		if (i!=monomios_.begin() && (*i).getCoeficiente()>0)
			salida << " ";
		if ((*i).getCoeficiente()!=0)
			salida << (*i) << " ";
	}
	return salida.str();
}

void Polinomio::escribirPolinomio(){
	std::cout << crearSalida() <<"\n";
}

float Polinomio::valor(float const &x) const{
	float valor=0;
	for(std::list<Monomio>::const_iterator i=monomios_.begin();i!=monomios_.end();i++)
		valor+=(*i).valor(x);
	return valor;
}

std::istream &operator>>(std::istream &stream, Polinomio &p){
	std::cout << "Número de monomios a insertar: ";
	stream >> p.nmonomios_;
	Monomio m;
	p.monomios_.clear();
	for (int i=0;i<p.nmonomios_;i++){
		std::cout << "Monomio " << i+1 << ":\n";
		m.leerMonomio();
		p.insertarMonomio(m);
	}
	return stream;
}

std::ostream &operator<<(std::ostream &stream, Polinomio const &p){
	stream << p.crearSalida();
	return stream;
}
