#include <iostream>
#include "Donante.hpp"
//#include "macros.hpp"

using namespace ed;
using std::cout;
using std::cin;


int main(){
	Donante d1;
  cout << "PRIMER DONANTE:\n";
  cin >> d1;
  cout << d1 << "\n\n";
  cout << "SEGUDNO DONANTE:\n";
  cout << "\tCopia del primer donante (Constructor de copia)\n";
  Donante d2;
  d2=d1;
  cout << d2 << "\n\n";
  cout << "TERCER DONANTE:\n";
  cout << "\tValores por defecto\n";
  Donante d3;
  cout << d3 << "\n\n";
	return 0;
}
