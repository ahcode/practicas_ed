#include "Donantes.hpp"

namespace ed{

  Donante Donantes::buscarDonante(std::string const &nombre, std::string const &apellidos) const{
    int pos;
    Donante aux(nombre,apellidos);
    if((pos=lista_.findItem(aux))==-1)
      throw 1;
    else
      return lista_.item(pos);
  }

  bool Donantes::borrarDonante(Donante const &d){
    int pos;
    if((pos=lista_.findItem(d))==-1)
      return false;
    else{
      lista_.deletePosition(pos);
      return true;
    }
  }

  bool Donantes::borrarDonante(std::string const &nombre, std::string const &apellidos){
    Donante aux(nombre,apellidos);
    return borrarDonante(aux);
  }

  void Donantes::leerDonantes(){
    Donante aux;
    int n, i;
    bool error=false;
    do{
      if(error)
        std::cout << "<< El número introducido no es válido >>";
      SUBRAYADO; std::cout << "\n¿Cuantos donantes quieres crear?"; NORMAL; std::cout << " = ";
      std::cin >> n;
      std::cin.ignore(256,'\n');
      BORRAR;
      error=true;
    }while(n<0);
    borrarLista();
    for(i=0;i<n;i++){
      NEGRITA; std::cout << "Donante " << i+1 << "\n"; NORMAL;
      std::cin >> aux;
      insertarDonante(aux);
      BORRAR;
    }
  }

  void Donantes::escribirDonantes() const{
    if(!hayDonantes()){
      std::cout << "\n<< No hay donantes >>\n";
    }
    for(int pos=0;lista_.isValid(pos);pos++){
      NEGRITA; std::cout << "\nDonante " << pos+1 << "\n"; NORMAL;
      std::cout << lista_.item(pos);
    }
  }

  void Donantes::borrarLista(){
    while(lista_.deletePosition(0));
  }

  int Donantes::numDonantes() const{
    int i;
    for(i=0;lista_.isValid(i);i++);
    return i;
  }

  Donante Donantes::getDonante(int const &n) const{
    if(lista_.isValid(n-1)){
      return lista_.item(n-1);
    }else{
      throw 1;
    }
  }
}
