#ifndef DONANTES_HPP
#define DONANTES_HPP

#include <string>
#include <iostream>
#include "macros.hpp"
#include "DonantesInterfaz.hpp"
#include "Donante.hpp"
#include "ListaDonantes.hpp"

namespace ed{
  class Donantes: public DonantesInterfaz{
    private:
      ListaDonantes lista_;
    public:
      Donantes(ListaDonantes const &lista){lista_=lista;};
      Donantes(){};
      bool hayDonantes() const{return !lista_.isEmpty();};
      Donante buscarDonante(std::string const &nombre, std::string const &apellidos) const;
      void insertarDonante(Donante const &d){lista_.insert(d);};
      bool borrarDonante(Donante const &d);
      bool borrarDonante(std::string const &nombre, std::string const &apellidos);
      bool borrarDonante(int const &n){return lista_.deletePosition(n-1);};
      ListaDonantes getLista() const{return lista_;};
      Donante getDonante(int const &n) const;
      void setLista(ListaDonantes const & lista){lista_=lista;};
      void leerDonantes();
      void escribirDonantes() const;
      void borrarLista();
      int numDonantes() const;
  };
}

#endif
