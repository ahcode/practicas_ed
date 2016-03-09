#ifndef MONOMIOINTERFAZ_H
#define MONOMIOINTERFAZ_H

class MonomioInterfaz{
	public:
		virtual void setCoeficiente(float const &c)=0;
		virtual void setGrado(int const &g)=0;
		virtual float getCoeficiente() const=0;
		virtual int getGrado() const=0;
};

#endif
