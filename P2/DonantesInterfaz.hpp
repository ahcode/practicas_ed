#ifndef DONANTESINTERFAZ_HPP
#define DONANTESINTERFAZ_HPP

#include <string>
#include "Donante.hpp"

namespace ed{
  class DonantesInterfaz{
    public:
      virtual bool hayDonantes() const=0;
      virtual Donante buscarDonante(std::string const &nombre, std::string const &apellidos) const=0;
      virtual void insertarDonante(Donante const &d)=0;
      virtual bool borrarDonante(std::string const &nombre, std::string const &apellidos)=0;
      virtual bool borrarDonante(Donante const &d)=0;
  };
}

#endif
