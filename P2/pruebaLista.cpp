#include <iostream>
#include "ListaDonantes.hpp"
#include "Donante.hpp"

using namespace ed;
using namespace std;

int main(){
  ListaDonantes lista;
  Donante d, c;
  cin >> d;
  lista.insert(d);
  if (lista.isValid(0))
    cout << "\nVale\n";
  else
    cout << "\nNo vale\n";

  c=lista.item(0);
  cout << c;
  return 0;
}
