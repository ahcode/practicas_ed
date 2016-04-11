#include "ficherosDonantes.hpp"

ed::Donantes cargarFichero(std::string const &nombreFichero){
  ed::Donantes lista;
  std::ifstream f(nombreFichero.c_str());
  std::string c;
  ed::Donante d;
  if(!f.is_open())
    throw 1;
  while (!f.eof()){
    getline(f,c);
    if(f.eof()) //Para evitar errores si hay una línea en blanco al final del fichero
      break;
    d.setNombre(c);
    getline(f,c);
    if(f.eof())
      break;
    d.setApellidos(c);
    getline(f,c);
    if(f.eof())
      break;
    if(!d.setGrupo(c))
      throw 2;
    getline(f,c);
    if(!d.setFRH(c))
      throw 3;
    lista.insertarDonante(d);
  }
  f.close();
  return lista;
}

bool grabarFichero(std::string const &nombreFichero, ed::Donantes const &lista){
  std::ofstream f(nombreFichero.c_str());
  ed::Donante d;
  if(!f.is_open())
    return false;
  for(int i=1;i<=lista.numDonantes();i++){
    d=lista.getDonante(i);
    f << d.getNombre() << "\n";
    f << d.getApellidos() << "\n";
    f << d.getGrupo() << "\n";
    f << d.getFRH() << "\n";
  }
  f.close();
  return true;
}
