#include "Polinomio.h"

Polinomio::Polinomio(int const &g, int const &n){
	int grado=g;
	setGrado(g);
	setNMonomios(n);
	Monomio m(1,grado);
	for (int i=0;i<n;i++){
		monomios_.push_back(m);
		m.setGrado(--grado);
	}
}

Polinomio::Polinomio(std::list<Monomio> const &m){
	setNMonomios(0);
	for(std::list<Monomio>::const_iterator i=m.begin();i!=m.end();i++){
		insertarMonomio(*i);
	}
	actualizarGrado();
}

Polinomio::Polinomio(Polinomio const &p){
	setGrado(p.getGrado());
	setNMonomios(p.getNMonomios());
	setMonomios(p.getMonomios());
}

bool Polinomio::vacio() const{
	bool vacio=true;
	for(std::list<Monomio>::const_iterator i=monomios_.begin();i!=monomios_.end();i++){
		if ((*i).getCoeficiente()!=0){
			vacio=false;
			break;
		}
	}
	return vacio;
}

void Polinomio::insertarMonomio(Monomio const &m){
	int g=m.getGrado();
	bool insertado=false;
	for(std::list<Monomio>::iterator i=monomios_.begin();i!=monomios_.end();i++){
		if ((*i).getGrado()<g){
			monomios_.insert(i,m);
			nmonomios_++;
			insertado=true;
			break;
		}
		if ((*i).getGrado()==g){
			(*i).setCoeficiente((*i).getCoeficiente()+m.getCoeficiente());
			insertado=true;
			break;
		}
	}
	if(!insertado){
		monomios_.push_back(m);
		nmonomios_++;
	}
	actualizarGrado();
}

void Polinomio::leerPolinomio(){
	int nmonomios;
	std::cout << "Número de monomios: ";
	std::cin >> nmonomios;
	Monomio m;
	monomios_.clear();
	setNMonomios(0);
	for (int i=0;i<nmonomios;i++){
		std::cout << "Monomio " << i+1 << ":\n";
		m.leerMonomio();
		insertarMonomio(m);
	}
}

std::string Polinomio::crearSalida() const{
	std::ostringstream salida;
	if (vacio())
		salida << "0";
	else
		for(std::list<Monomio>::const_iterator i=monomios_.begin();i!=monomios_.end();i++){
			if (i!=monomios_.begin() && (*i).getCoeficiente()>0)
				salida << "+ ";
			if ((*i).getCoeficiente()!=0)
				salida << (*i) << " ";
		}
	return salida.str();
}

void Polinomio::actualizarGrado(){
	setGrado(monomios_.front().getGrado());
}

void Polinomio::escribirPolinomio() const{
	std::cout << crearSalida() <<"\n";
}

float Polinomio::valor(float const &x) const{
	float valor=0;
	for(std::list<Monomio>::const_iterator i=monomios_.begin();i!=monomios_.end();i++)
		valor+=(*i).valor(x);
	return valor;
}

Polinomio Polinomio::operator=(Polinomio const &p){
	setGrado(p.getGrado());
	setNMonomios(p.getNMonomios());
	setMonomios(p.getMonomios());
	return *this;
}

Polinomio Polinomio::operator+(Polinomio const &p){
	Polinomio aux;
	bool insertado;
	for(std::list<Monomio>::iterator i=monomios_.begin();i!=monomios_.end();i++)
		aux.insertarMonomio(*i);
	for(std::list<Monomio>::const_iterator i=p.monomios_.begin();i!=p.monomios_.end();i++)
		aux.insertarMonomio(*i);
	return aux;
}

Polinomio Polinomio::operator*(Polinomio const &p){
	Polinomio aux;
	bool insertado;
	for(std::list<Monomio>::iterator i=monomios_.begin();i!=monomios_.end();i++)
		for(std::list<Monomio>::const_iterator j=p.monomios_.begin();j!=p.monomios_.end();j++)
			aux.insertarMonomio((*i)*(*j));
	return aux;
}

std::istream &operator>>(std::istream &stream, Polinomio &p){
	int nmonomios;
	std::cout << "Número de monomios: ";
	stream >> nmonomios;
	Monomio m;
	p.monomios_.clear();
	p.setNMonomios(0);
	for (int i=0;i<nmonomios;i++){
		std::cout << "Monomio " << i+1 << ":\n";
		stream >> m;
		p.insertarMonomio(m);
	}
	return stream;
}

std::ostream &operator<<(std::ostream &stream, Polinomio const &p){
	stream << p.crearSalida();
	return stream;
}
