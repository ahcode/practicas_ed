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

Polinomio::Polinomio(std::list<Monomio> const &m){
	nmonomios_=0;
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
	actualizarGrado();
	nmonomios_++;
}

void Polinomio::leerPolinomio(){
	int nmonomios;
	std::cout << "Número de monomios: ";
	std::cin >> nmonomios;
	Monomio m;
	monomios_.clear();
	nmonomios_=0;
	for (int i=0;i<nmonomios;i++){
		std::cout << "Monomio " << i+1 << ":\n";
		m.leerMonomio();
		insertarMonomio(m);
	}
}

std::string Polinomio::crearSalida() const{
	std::ostringstream salida;
	bool vacio=true;
	for(std::list<Monomio>::const_iterator i=monomios_.begin();i!=monomios_.end();i++){
		if (i!=monomios_.begin() && (*i).getCoeficiente()>0)
			salida << "+ ";
		if ((*i).getCoeficiente()!=0){
			salida << (*i) << " ";
			vacio=false;
		}
	}
	if (vacio)
		salida << "0";
	return salida.str();
}

void Polinomio::actualizarGrado(){
	grado_=monomios_.front().getGrado();
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
	grado_=p.grado_;
	nmonomios_=p.nmonomios_;
	monomios_=p.monomios_;
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
	p.nmonomios_=0;
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
